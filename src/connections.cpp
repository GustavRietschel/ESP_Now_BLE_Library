#include "esp_netif.h"
#include "esp_wifi.h"
#include "connections.h"

void ESP_NOW::wifiInit() 
{
    esp_netif_init();
    esp_event_loop_create_default();
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);
    esp_wifi_set_storage(WIFI_STORAGE_RAM);
    esp_wifi_set_mode(WIFI_MODE_STA);
    esp_wifi_start();
    esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);
}


void ESP_NOW::start(onDataSend sendCb, onDataReceive receiveCb) {
   wifiInit();
   esp_now_init();
   esp_now_register_send_cb(sendCb);
   esp_now_register_recv_cb(receiveCb);
};

void ESP_NOW::addNewESP(uint8_t macAddr[6]) 
{
    esp_now_peer_info peer_info = {0};
    peer_info.channel = 1;
    peer_info.encrypt = false;
    memcpy(peer_info.peer_addr, macAddr, 6);
    esp_now_add_peer(&peer_info);
}

void ESP_NOW::sendData(uint8_t macAddr[6], const void* data, size_t len)
{
    esp_now_send(macAddr, reinterpret_cast<const uint8_t*>(data), len);
}