#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <esp_now.h>


#ifdef __cplusplus
}
#endif

class ESP_NOW
{
public:
    // type definitions for callback functions that are created by the user
    typedef void (*onDataReceive)(const esp_now_recv_info_t* esp_now_info,
                                  const uint8_t* data, int len);
    typedef void (*onDataSend)(const uint8_t* macAddr,
                               esp_now_send_status_t status);

    // initialize esp now to use it
    void start(onDataSend sendCb, onDataReceive receiveCb);

    void addNewESP(uint8_t macAddr[6]);
    void sendData(uint8_t macAddr[6], const void* data, size_t len);

private:
    // Init Wifi functions because ESP NOW is based on WIFI protocol
    void wifiInit();
};

#endif