#include "esp32_wifi.hpp"

esp32_wifi::esp32_wifi()
{
 
}

esp32_wifi::~esp32_wifi()
{
}

void esp32_wifi::init(esp32Config config)
{
    wifiCfg.wifiName = config.wifiName;
    wifiCfg.wifiPassword = config.wifiPassword;
    wifiCfg.wifiChanel = config.wifiChenel;
    wifiCfg.wifiDefaulAp = config.wifiDefaulAp;
    wifiCfg.apName = config.apName;
    wifiCfg.apPassword = config.apPassword;

    configConnection();
}

void esp32_wifi::configConnection()
{
    if(wifiCfg.wifiDefaulAp)
    {
        startAP();
    }
    else
    {
        connectWifi();
    }
    
}


void esp32_wifi::connectWifi()
{
    Serial.println("Connecting to " + wifiCfg.wifiName);
    WiFi.begin(wifiCfg.wifiName.c_str(), wifiCfg.wifiPassword.c_str());
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.print("\nWiFi connected -> IP address: ");
    Serial.println(WiFi.localIP());
}

void esp32_wifi::startAP()
{
    Serial.println("Starting **" + wifiCfg.apName + "** AP");
    WiFi.softAP(wifiCfg.apName.c_str(), wifiCfg.apPassword.c_str(), wifiCfg.apChanel );
}