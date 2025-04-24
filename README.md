# ESP_Now_BLE_Library

Easy to use Library for ESP NOW. Enable ESP NOW two way communication in ESP IDF in a very easy to use way. 

## Features

- Simple API for device-to-device communication
- Support for both ESP-NOW protocols
- Efficient data transmission
- Easy integration with ESP-IDF framework

## Installation

### Using PlatformIO

1. Open your PlatformIO project
2. Add the following to your `platformio.ini`:
```ini
lib_deps =
    https://github.com/GustavRietschel/ESP_Now_BLE_Library.git
```

### Manual Installation

1. Clone this repository into your project's libraries folder:
```bash
git clone https://github.com/GustavRietschel/ESP_Now_BLE_Library.git
```

## Usage

Include the library in your project:
```cpp
#include "connections.h"
```

Store the macadress of the peer esp32. 
```cpp
// Change with your mac adress
uint8_t macAddr[6] = {0x34, 0x5f, 0x45, 0xa7, 0x8a, 0xa4};
```

Create a callback function for sending and receiving data. 
```cpp
// Example Callback functions
void onDataSend(const uint8_t *macAddr, esp_now_send_status_t status) 
{
    if (status != 0) {
        printf("Error while sending!");
    }
};


void onDataReceived(const esp_now_recv_info_t *esp_now_info, const uint8_t *data, int len) {
    memcpy(&carData, data, sizeof(CarData));
    newData = true;
};
```

Basic usage example:
```cpp
// Initialize the connection
ESP_NOW esp_now;

// Setup the connection
esp_now.init();

// Add peer ESP32
esp_now.add(macAddr);

// Send data
esp_now.sendData("Hello, ESP32!");
```

## Requirements

- ESP-IDF framework
- ESP32 platform
- PlatformIO (recommended)


## Author

Gustav Rietschel

## Version

Current version: 0.9.0
