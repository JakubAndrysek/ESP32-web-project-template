#include <Arduino.h>
#include "esp32.hpp"
#include "BasicOTA.hpp"

void mainPrograme()
{
	//Main setup

	BasicOTA ota;
	esp32Config config;
	delay(2000);

	Serial.println("Start");
	config.sensorName = "TestESP";
	config.sensorNumber = 1;
	config.wifiName = "WLOffice";
	config.wifiPassword = "$BlueC6r&R06D";
	config.apName = "esp32-ESP";
	config.apPassword = "esp32Plete";
	config.wifiDefaulAp = false;
	config.remoteDataOn = true;
	config.remoteDebugOn = true;
	config.serialDebugOn = true;
	
	myESP.config(config);
	ota.begin();
	
	myESP.println("println");
	myESP.debugln("debugln");

	//Main loop
	while (true)
	{
		ota.handle();
	}
	
}

void setup() {
	mainPrograme();
}
































void loop() {}