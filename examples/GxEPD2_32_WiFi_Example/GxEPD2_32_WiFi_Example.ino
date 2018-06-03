// GxEPD2_32_WiFi_Example : Display Library example for SPI e-paper panels from Dalian Good Display and boards from Waveshare.
// Requires HW SPI and Adafruit_GFX. Caution: these e-papers require 3.3V supply AND data lines!
//
// Display Library based on Demo Example from Good Display: http://www.good-display.com/download_list/downloadcategoryid=34&isMode=false.html
//
// Author: Jean-Marc Zingg
//
// Version: see library.properties
//
// Library: https://github.com/ZinggJM/GxEPD2_32

// Supporting Arduino Forum Topics:
// Waveshare e-paper displays with SPI: http://forum.arduino.cc/index.php?topic=487007.0
// Good Dispay ePaper for Arduino : https://forum.arduino.cc/index.php?topic=436411.0

// mapping suggestion from Waveshare SPI e-Paper to Wemos D1 mini
// BUSY -> D2, RST -> D4, DC -> D3, CS -> D8, CLK -> D5, DIN -> D7, GND -> GND, 3.3V -> 3.3V

// mapping suggestion from Waveshare SPI e-Paper to generic ESP8266
// BUSY -> GPIO4, RST -> GPIO2, DC -> GPIO0, CS -> GPIO15, CLK -> GPIO14, DIN -> GPIO13, GND -> GND, 3.3V -> 3.3V

// mapping of Waveshare e-Paper ESP8266 Driver Board
// BUSY -> GPIO16, RST -> GPIO5, DC -> GPIO4, CS -> GPIO15, CLK -> GPIO14, DIN -> GPIO13, GND -> GND, 3.3V -> 3.3V

// mapping suggestion for ESP32, e.g. LOLIN32, see .../variants/.../pins_arduino.h for your board
// NOTE: there are variants with different pins for SPI ! CHECK SPI PINS OF YOUR BOARD
// BUSY -> 4, RST -> 16, DC -> 17, CS -> SS(5), CLK -> SCK(18), DIN -> MOSI(23), GND -> GND, 3.3V -> 3.3V

// new mapping suggestion for STM32F1, e.g. STM32F103C8T6 "BluePill"
// BUSY -> A1, RST -> A2, DC -> A3, CS-> A4, CLK -> A5, DIN -> A7

// mapping suggestion for AVR, UNO, NANO etc.
// BUSY -> 7, RST -> 9, DC -> 8, CS-> 10, CLK -> 13, DIN -> 11
//

#include <GxEPD2_32_BW.h>
#include <GxEPD2_32_3C.h>

#if defined (ESP8266)
// select one and adapt to your mapping
//GxEPD2_32_BW display(GxEPD2::GDEP015OC1, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
//GxEPD2_32_BW display(GxEPD2::GDE0213B1, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
//GxEPD2_32_BW display(GxEPD2::GDEH029A1, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
//GxEPD2_32_BW display(GxEPD2::GDEW027W3, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
//GxEPD2_32_BW display(GxEPD2::GDEW042T2, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
//GxEPD2_32_BW display(GxEPD2::GDEW075T8,  /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
// 3-color e-papers
//GxEPD2_32_3C display(GxEPD2::GDEW0154Z04,  /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
//GxEPD2_32_3C display(GxEPD2::GDEW0213Z16,  /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
//GxEPD2_32_3C display(GxEPD2::GDEW029Z10,  /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
//GxEPD2_32_3C display(GxEPD2::GDEW027C44,  /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
//GxEPD2_32_3C display(GxEPD2::GDEW042Z15,  /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
//GxEPD2_32_3C display(GxEPD2::GDEW075Z09,  /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
#endif

#if defined(ESP32)
// select one and adapt to your mapping
//GxEPD2_32_BW display(GxEPD2::GDEP015OC1, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16, /*BUSY=*/ 4);
//GxEPD2_32_BW display(GxEPD2::GDE0213B1, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16, /*BUSY=*/ 4);
//GxEPD2_32_BW display(GxEPD2::GDEH029A1, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16, /*BUSY=*/ 4);
//GxEPD2_32_BW display(GxEPD2::GDEW027W3, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16, /*BUSY=*/ 4);
//GxEPD2_32_BW display(GxEPD2::GDEW042T2, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16, /*BUSY=*/ 4);
//GxEPD2_32_BW display(GxEPD2::GDEW075T8, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16, /*BUSY=*/ 4);
// 3-color e-papers
//GxEPD2_32_3C display(GxEPD2::GDEW0154Z04, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16, /*BUSY=*/ 4);
//GxEPD2_32_3C display(GxEPD2::GDEW0213Z16, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16, /*BUSY=*/ 4);
//GxEPD2_32_3C display(GxEPD2::GDEW029Z10,  /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16, /*BUSY=*/ 4);
//GxEPD2_32_3C display(GxEPD2::GDEW027C44,  /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16, /*BUSY=*/ 4);
//GxEPD2_32_3C display(GxEPD2::GDEW042Z15,  /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16, /*BUSY=*/ 4);
//GxEPD2_32_3C display(GxEPD2::GDEW075Z09,  /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16, /*BUSY=*/ 4);
#endif

#if defined(_BOARD_GENERIC_STM32F103C_H_)
// select one and adapt to your mapping
//GxEPD2_32_BW display(GxEPD2::GDEP015OC1, /*CS=4*/ SS, /*DC=*/ 3, /*RST=*/ 2, /*BUSY=*/ 1);
//GxEPD2_32_BW display(GxEPD2::GDE0213B1, /*CS=4*/ SS, /*DC=*/ 3, /*RST=*/ 2, /*BUSY=*/ 1);
//GxEPD2_32_BW display(GxEPD2::GDEH029A1, /*CS=4*/ SS, /*DC=*/ 3, /*RST=*/ 2, /*BUSY=*/ 1);
//GxEPD2_32_BW display(GxEPD2::GDEW027W3, /*CS=4*/ SS, /*DC=*/ 3, /*RST=*/ 2, /*BUSY=*/ 1);
//GxEPD2_32_BW display(GxEPD2::GDEW042T2, /*CS=4*/ SS, /*DC=*/ 3, /*RST=*/ 2, /*BUSY=*/ 1);
//GxEPD2_32_BW display(GxEPD2::GDEW075T8, /*CS=4*/ SS, /*DC=*/ 3, /*RST=*/ 2, /*BUSY=*/ 1);
// 3-color e-papers
//GxEPD2_32_3C display(GxEPD2::GDEW0154Z04, /*CS=4*/ SS, /*DC=*/ 3, /*RST=*/ 2, /*BUSY=*/ 1);
//GxEPD2_32_3C display(GxEPD2::GDEW0213Z16, /*CS=4*/ SS, /*DC=*/ 3, /*RST=*/ 2, /*BUSY=*/ 1);
//GxEPD2_32_3C display(GxEPD2::GDEW029Z10,  /*CS=4*/ SS, /*DC=*/ 3, /*RST=*/ 2, /*BUSY=*/ 1);
//GxEPD2_32_3C display(GxEPD2::GDEW027C44,  /*CS=4*/ SS, /*DC=*/ 3, /*RST=*/ 2, /*BUSY=*/ 1);
//GxEPD2_32_3C display(GxEPD2::GDEW042Z15,  /*CS=4*/ SS, /*DC=*/ 3, /*RST=*/ 2, /*BUSY=*/ 1);
//GxEPD2_32_3C display(GxEPD2::GDEW075Z09,  /*CS=4*/ SS, /*DC=*/ 3, /*RST=*/ 2, /*BUSY=*/ 1);
#endif

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>

const char* ssid     = "........";
const char* password = "........";
const int httpPort  = 80;
const int httpsPort = 443;
const char* fp_api_github_com = "35 85 74 EF 67 35 A7 CE 40 69 50 F3 C0 F6 80 CF 80 3B 2E 19";
const char* fp_github_com     = "ca 06 f5 6b 25 8b 7a 0d 4f 2b 05 47 09 39 47 86 51 15 19 84";
const char* fp_rawcontent     = "cc aa 48 48 66 46 0e 91 53 2c 9c 7c 23 2a b1 74 4d 29 9d 33";
const char* host_rawcontent   = "raw.githubusercontent.com";
const char* path_rawcontent   = "/ZinggJM/GxEPD2/master/extras/bitmaps/";

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("GxEPD2_32_WiFi_Example");

  display.init();

#ifdef RE_INIT_NEEDED
  WiFi.persistent(true);
  WiFi.mode(WIFI_STA); // switch off AP
  WiFi.setAutoConnect(true);
  WiFi.setAutoReconnect(true);
  WiFi.disconnect();
#endif

  if (!WiFi.getAutoConnect() || ( WiFi.getMode() != WIFI_STA) || ((WiFi.SSID() != ssid) && String(ssid) != "........"))
  {
    Serial.println();
    Serial.print("WiFi.getAutoConnect()=");
    Serial.println(WiFi.getAutoConnect());
    Serial.print("WiFi.SSID()=");
    Serial.println(WiFi.SSID());
    WiFi.mode(WIFI_STA); // switch off AP
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
  }
  int ConnectTimeout = 30; // 15 seconds
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    Serial.print(WiFi.status());
    if (--ConnectTimeout <= 0)
    {
      Serial.println();
      Serial.println("WiFi connect timeout");
      return;
    }
  }
  Serial.println();
  Serial.println("WiFi connected");

  // Print the IP address
  Serial.println(WiFi.localIP());

  showBitmapsFromWiFi();
}

void loop(void)
{
}

void showBitmapsFromWiFi()
{
  showBitmapFrom_HTTP("www.squix.org", "/blog/wunderground/", "chanceflurries.bmp", 0, 0);
  delay(2000);
  //return;
  showBitmapFrom_HTTPS(host_rawcontent, path_rawcontent, "logo200x200.bmp", fp_rawcontent, 0, 0);
  delay(2000);
  //return;
  showBitmapFrom_HTTPS(host_rawcontent, path_rawcontent, "first200x200.bmp", fp_rawcontent, 0, 0);
  delay(2000);
  showBitmapFrom_HTTPS(host_rawcontent, path_rawcontent, "second200x200.bmp", fp_rawcontent, 0, 0);
  delay(2000);
  showBitmapFrom_HTTPS(host_rawcontent, path_rawcontent, "third200x200.bmp", fp_rawcontent, 0, 0);
  delay(2000);
  showBitmapFrom_HTTPS(host_rawcontent, path_rawcontent, "fourth200x200.bmp", fp_rawcontent, 0, 0);
  delay(2000);
  showBitmapFrom_HTTPS(host_rawcontent, path_rawcontent, "fifth200x200.bmp", fp_rawcontent, 0, 0);
  delay(2000);
  showBitmapFrom_HTTPS(host_rawcontent, path_rawcontent, "sixth200x200.bmp", fp_rawcontent, 0, 0);
  delay(2000);
  showBitmapFrom_HTTPS(host_rawcontent, path_rawcontent, "seventh200x200.bmp", fp_rawcontent, 0, 0);
  delay(2000);
  showBitmapFrom_HTTPS(host_rawcontent, path_rawcontent, "eighth200x200.bmp", fp_rawcontent, 0, 0);
  delay(2000);
}

void showBitmapFrom_HTTP(const char* host, const char* path, const char* filename, uint8_t x, uint8_t y)
{
  WiFiClient client;
  uint8_t buffer[512]; // buffer for at least one row
  bool valid = false; // valid format to be handled
  bool flip = true; // bitmap is stored bottom-to-top
  uint32_t startTime = millis();
  if ((x >= display.width()) || (y >= display.height())) return;
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpPort))
  {
    Serial.println("connection failed");
    return;
  }
  Serial.print("requesting URL: ");
  Serial.println(String("http://") + host + path + filename);
  client.print(String("GET ") + path + filename + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: GxEPD2_Spiffs_Loader\r\n" +
               "Connection: close\r\n\r\n");
  Serial.println("request sent");
  bool ok = false;
  while (client.connected())
  {
    String line = client.readStringUntil('\n');
    if (!ok)
    {
      ok = line.startsWith("HTTP/1.1 200 OK");
      if (ok) Serial.println(line);
      //if (!ok) Serial.println(line);
    }
    if (!ok) Serial.println(line);
    //Serial.println(line);
    if (line == "\r")
    {
      Serial.println("headers received");
      break;
    }
  }
  if (!ok) return;
  // Parse BMP header
  if (read16(client) == 0x4D42) // BMP signature
  {
    uint32_t fileSize = read32(client);
    uint32_t creatorBytes = read32(client);
    uint32_t imageOffset = read32(client); // Start of image data
    uint32_t headerSize = read32(client);
    uint32_t width  = read32(client);
    uint32_t height = read32(client);
    uint16_t planes = read16(client);
    uint16_t depth = read16(client); // bits per pixel
    uint32_t format = read32(client);
    uint32_t bytes_read = 7 * 4 + 3 * 2; // read so far
    if ((planes == 1) && (format == 0)) // uncompressed is handled
    {
      Serial.print("File size: "); Serial.println(fileSize);
      Serial.print("Image Offset: "); Serial.println(imageOffset);
      Serial.print("Header size: "); Serial.println(headerSize);
      Serial.print("Bit Depth: "); Serial.println(depth);
      Serial.print("Image size: ");
      Serial.print(width);
      Serial.print('x');
      Serial.println(height);
      // BMP rows are padded (if needed) to 4-byte boundary
      uint32_t rowSize = (width * depth / 8 + 3) & ~3;
      if (height < 0)
      {
        height = -height;
        flip = false;
      }
      uint16_t w = width;
      uint16_t h = height;
      if ((x + w - 1) >= display.width())  w = display.width()  - x;
      if ((y + h - 1) >= display.height()) h = display.height() - y;
      uint32_t skip = (flip ? (imageOffset + (height - h) * rowSize) : imageOffset) - bytes_read;
      if (skip > 0) bytes_read += client.read(buffer, skip);
      //Serial.print("skip "); Serial.println(skip);
      if (((depth == 1) || (depth == 24)) && (rowSize < sizeof(buffer))) // handle with direct drawing
      {
        valid = true;
        display.writeScreenBuffer();
        for (uint16_t row = 0; row < h; row++) // for each line
        {
          delay(1); // yield() to avoid WDT
          uint32_t got = client.read(buffer, rowSize);
          while ((got < rowSize) && client.connected())
          {
            delay(1); // yield() to avoid WDT
            got += client.read(buffer + got, rowSize - got);
          }
          bytes_read += got;
          if (depth == 24)
          {
            uint8_t out_byte = 0;
            uint32_t out_idx = 0;
            uint32_t in_idx = 0;
            for (uint16_t col = 0; col < w; col++)
            {
              uint16_t b = buffer[in_idx++];
              uint16_t g = buffer[in_idx++];
              uint16_t r = buffer[in_idx++];
              if ((r + g + b) / 3 > 0xFF  / 2)
              {
                out_byte |= 0x80 >> col % 8;
              }
              if (7 == col % 8)
              {
                buffer[out_idx++] = out_byte;
                out_byte = 0;
              }
            }
          }
          uint16_t y = flip ? h - row - 1 : row;
          display.writeImage(buffer, 0, y, w, 1);
        }
        display.refresh();
      }
    }
    Serial.print("bytes read "); Serial.println(bytes_read);
    //Serial.print("available  "); Serial.println(client.available());
  }
  if (valid)
  {
    Serial.print("loaded in ");
    Serial.print(millis() - startTime);
    Serial.println(" ms");
  }
  else
  {
    Serial.println("bitmap format not handled.");
  }
}

void showBitmapFrom_HTTPS(const char* host, const char* path, const char* filename, const char* fingerprint, uint8_t x, uint8_t y)
{
  // Use WiFiClientSecure class to create TLS connection
  WiFiClientSecure client;
  uint8_t buffer[512]; // buffer for at least one row
  bool valid = false; // valid format to be handled
  bool flip = true; // bitmap is stored bottom-to-top
  uint32_t startTime = millis();
  if ((x >= display.width()) || (y >= display.height())) return;
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort))
  {
    Serial.println("connection failed");
    return;
  }
  if (fingerprint)
  {
    if (client.verify(fingerprint, host))
    {
      Serial.println("certificate matches");
    }
    else
    {
      Serial.println("certificate doesn't match");
      return;
    }
  }
  Serial.print("requesting URL: ");
  Serial.println(String("https://") + host + path + filename);
  client.print(String("GET ") + path + filename + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: GxEPD2_Spiffs_Loader\r\n" +
               "Connection: close\r\n\r\n");
  Serial.println("request sent");
  bool ok = false;
  while (client.connected())
  {
    String line = client.readStringUntil('\n');
    if (!ok)
    {
      ok = line.startsWith("HTTP/1.1 200 OK");
      if (ok) Serial.println(line);
      //if (!ok) Serial.println(line);
    }
    if (!ok) Serial.println(line);
    //Serial.println(line);
    if (line == "\r")
    {
      Serial.println("headers received");
      break;
    }
  }
  if (!ok) return;
  // Parse BMP header
  if (read16(client) == 0x4D42) // BMP signature
  {
    uint32_t fileSize = read32(client);
    uint32_t creatorBytes = read32(client);
    uint32_t imageOffset = read32(client); // Start of image data
    uint32_t headerSize = read32(client);
    uint32_t width  = read32(client);
    uint32_t height = read32(client);
    uint16_t planes = read16(client);
    uint16_t depth = read16(client); // bits per pixel
    uint32_t format = read32(client);
    uint32_t bytes_read = 7 * 4 + 3 * 2; // read so far
    if ((planes == 1) && (format == 0)) // uncompressed is handled
    {
      Serial.print("File size: "); Serial.println(fileSize);
      Serial.print("Image Offset: "); Serial.println(imageOffset);
      Serial.print("Header size: "); Serial.println(headerSize);
      Serial.print("Bit Depth: "); Serial.println(depth);
      Serial.print("Image size: ");
      Serial.print(width);
      Serial.print('x');
      Serial.println(height);
      // BMP rows are padded (if needed) to 4-byte boundary
      uint32_t rowSize = (width * depth / 8 + 3) & ~3;
      if (height < 0)
      {
        height = -height;
        flip = false;
      }
      uint16_t w = width;
      uint16_t h = height;
      if ((x + w - 1) >= display.width())  w = display.width()  - x;
      if ((y + h - 1) >= display.height()) h = display.height() - y;
      uint32_t skip = (flip ? (imageOffset + (height - h) * rowSize) : imageOffset) - bytes_read;
      if (skip > 0) bytes_read += client.read(buffer, skip);
      //Serial.print("skip "); Serial.println(skip);
      if (((depth == 1) || (depth == 24)) && (rowSize < sizeof(buffer))) // handle with direct drawing
      {
        valid = true;
        display.writeScreenBuffer();
        for (uint16_t row = 0; row < h; row++) // for each line
        {
          delay(1); // yield() to avoid WDT
          uint32_t got = client.read(buffer, rowSize);
          while ((got < rowSize) && client.connected())
          {
            delay(1); // yield() to avoid WDT
            got += client.read(buffer + got, rowSize - got);
          }
          bytes_read += got;
          if (depth == 24)
          {
            uint8_t out_byte = 0;
            uint32_t out_idx = 0;
            uint32_t in_idx = 0;
            for (uint16_t col = 0; col < w; col++)
            {
              uint16_t b = buffer[in_idx++];
              uint16_t g = buffer[in_idx++];
              uint16_t r = buffer[in_idx++];
              if ((r + g + b) / 3 > 0xFF  / 2)
              {
                out_byte |= 0x80 >> col % 8;
              }
              if (7 == col % 8)
              {
                buffer[out_idx++] = out_byte;
                out_byte = 0;
              }
            }
          }
          uint16_t y = flip ? h - row - 1 : row;
          display.writeImage(buffer, 0, y, w, 1);
        }
        display.refresh();
      }
    }
    Serial.print("bytes read "); Serial.println(bytes_read);
    //Serial.print("available  "); Serial.println(client.available());
  }
  if (valid)
  {
    Serial.print("loaded in ");
    Serial.print(millis() - startTime);
    Serial.println(" ms");
  }
  else
  {
    Serial.println("bitmap format not handled.");
  }
}

uint16_t read16(WiFiClient& client)
{
  // BMP data is stored little-endian, same as Arduino.
  uint16_t result;
  ((uint8_t *)&result)[0] = client.read(); // LSB
  ((uint8_t *)&result)[1] = client.read(); // MSB
  return result;
}

uint32_t read32(WiFiClient& client)
{
  // BMP data is stored little-endian, same as Arduino.
  uint32_t result;
  ((uint8_t *)&result)[0] = client.read(); // LSB
  ((uint8_t *)&result)[1] = client.read();
  ((uint8_t *)&result)[2] = client.read();
  ((uint8_t *)&result)[3] = client.read(); // MSB
  return result;
}

