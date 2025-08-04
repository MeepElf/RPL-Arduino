#include "FS.h"
#include "SD_MMC.h"
#include "esp_camera.h"
#include <EEPROM.h>            // read and write from flash memory

#define CAMERA_MODEL_AI_THINKER
#include "camera_pins.h"

#define EEPROM_SIZE 1
int pictureNumber = 0;

static esp_err_t get_image(fs::FS &fs, const char * path) {
    camera_fb_t * fb = NULL;
    int64_t fr_start = esp_timer_get_time();

    fb = esp_camera_fb_get();
    if (!fb) {
        Serial.println("Camera capture failed");
        return ESP_FAIL;
    }

    size_t fb_len = fb->len;
    File file = fs.open(path, FILE_WRITE);
    if(!file){
      Serial.println("Failed to open file in writing mode");
    } else {
      file.write(fb->buf, fb->len);
      Serial.printf("Saved file to path: %s\n", path);
    }
    file.close();

    esp_camera_fb_return(fb);
    int64_t fr_end = esp_timer_get_time();
    Serial.printf("JPG: %uB %ums\n", (uint32_t)(fb_len), (uint32_t)((fr_end - fr_start)/1000));
    return ESP_OK;
}

void setup() {
  Serial.begin(115200);
  Serial.println();

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;

  if(psramFound()){
    config.frame_size = FRAMESIZE_UXGA;
    config.jpeg_quality = 10;
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_SVGA;
    config.jpeg_quality = 12;
    config.fb_count = 1;
  }

  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

  Serial.println("Camera initialized!");

  if(!SD_MMC.begin()){
    Serial.println("Card Mount Failed");
    return;
  }
  uint8_t cardType = SD_MMC.cardType();
  if(cardType == CARD_NONE){
    Serial.println("No SD_MMC card attached");
    return;
  }
  Serial.println("SD Card Initialized");

  EEPROM.begin(EEPROM_SIZE);
  pictureNumber = EEPROM.read(0) + 1;
}

void loop() {
  String path = "/picture" + String(pictureNumber) + ".jpg";
  if(get_image(SD_MMC, path.c_str()) != ESP_OK ) {
    Serial.println("Failed to capture picture");
  } else {
    Serial.println("Captured picture");
    EEPROM.write(0, pictureNumber);
    EEPROM.commit();
    pictureNumber++;
  }
  delay(5000); // Wait 5 seconds before taking another picture
}
