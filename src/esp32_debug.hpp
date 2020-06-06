#pragma once

#include <Arduino.h>
#include "esp32_config.hpp"
#include <WiFi.h>
#include <WiFiClient.h>


class esp32_debug
{
private:
    struct debugConfig
    {
        //Setup debug configuration
        debugConfig()
            : Debug_IPs("192.168.0.112") //IP adress of proxy server - Lorris
            , Debug_port(12345)          //Debug port of proxy server
            , Data_port(12346) {         //Data port of proxy server
        }
        String Debug_IPs;    //IP adress of proxy server - Lorris
        int Debug_port;      //Debug port of proxy server
        int Data_port;       //Data port of proxy server
    };

    debugConfig debugCfg;
    IPAddress Debug_IP;

    
public:
	WiFiClient Debug;
    WiFiClient Data;
    void init(esp32Config config);
	
};















