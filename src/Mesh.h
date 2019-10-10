#pragma once

extern "C" {
  #include "user_interface.h"
}

void promisc_cb(uint8_t *buf, uint16_t len) {
    // TODO
}

void init_mesh(uint8_t channel) {
    // Note: This works only in station mode. wifi_station_disconnect should be called in advance.
    // http://www.liot.io/media/liot_esp8266_env/documents/esp8266_non_os_sdk_api_reference.pdf
    // https://carvesystems.com/news/writing-a-simple-esp8266-based-sniffer/

    wifi_set_opmode(STATION_MODE);
    wifi_promiscuous_enable(0);
    wifi_station_disconnect();

    wifi_set_channel(channel);
    wifi_promiscuous_enable(0);
    wifi_set_promiscuous_rx_cb(promisc_cb);
    wifi_promiscuous_enable(1);
}

void send_packet(char* data, uint8_t data_size) {
    // wifi_send_pkt_freed(uint8 *buf, int len, bool sys_seq);
}
