#include "esp32.hpp"

esp32::esp32()
{
    Serial.begin(115200);
}

esp32::~esp32()
{
}

void esp32::config(const esp32Config config)
{
    cfg = config;
    Serial.begin(115200);
    Serial.println("Sensor "+cfg.sensorName+ " is configuring");
    pWifi.init(config);
    pDebug.init(config);    
}

void esp32::debug(String message)
{
	if(cfg.remoteDebugOn)
	{
		pDebug.Debug.print(message);
	}

	if(cfg.serialDebugOn)
	{
		Serial.print(message);
	}
	
}


void esp32::debugln(String message)
{
	if(cfg.remoteDebugOn)
	{
		pDebug.Debug.println(message);
	}

	if(cfg.serialDebugOn)
	{
		Serial.println(message);
	}
}

void esp32::print(String message)
{
	if(cfg.remoteDataOn)
	{
		pDebug.Data.print(message);
	}

	if(cfg.serialDebugOn)
	{
		Serial.print(message);
	}
	
}


void esp32::println(String message)
{
	if(cfg.remoteDataOn)
	{
		pDebug.Data.println(message);
	}

	Serial.println(message);
}


esp32 myESP;