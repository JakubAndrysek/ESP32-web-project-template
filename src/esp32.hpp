# pragma once

#include <Arduino.h>

#include "esp32_config.hpp"
#include "esp32_wifi.hpp"
#include "esp32_debug.hpp"

class esp32
{
private:
	esp32Config cfg;
	esp32_wifi pWifi;
	esp32_debug pDebug;
	



public:
	esp32();
	~esp32();
	void config(const esp32Config config);
	void debug(String message);
	void debugln(String message);
	void print(String message);
	void println(String message);
	
};

extern esp32 myESP;




