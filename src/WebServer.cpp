#include "NoWiFi.h"

char buffer[4096];

WebServer::WebServer(NetworkSettings* networkSettings, Logger* logger, SystemCheck* systemCheck)
    :WebServerBase(networkSettings, logger, systemCheck) {
}

void WebServer::registerHandlers() {
    server->on("/", std::bind(&WebServer::handle_root, this));
    server->on("/settings", std::bind(&WebServer::handle_settings, this));
}

void WebServer::handle_root() {
    systemCheck->registerWebCall();
    server->sendHeader("Location","/settings");
    server->send(303);
}

void WebServer::handle_settings() {
    systemCheck->registerWebCall();

    bool save = false;

    wifi.parse_config_params(this, save);

    if (save) {
        settings.save();
    }

    char network_settings[strlen_P(NETWORK_CONFIG_PAGE) + 32];
    wifi.get_config_page(network_settings);


    sprintf_P(
        buffer,
        CONFIG_PAGE,
        network_settings);
    server->send(200, "text/html", buffer);
}
