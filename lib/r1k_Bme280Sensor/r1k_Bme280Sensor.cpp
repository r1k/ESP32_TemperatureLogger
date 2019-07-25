#include <Wire.h>
#include <r1k_Display.h>
#include "r1k_Bme280Sensor.h"

#define SEALEVELPRESSURE_HPA (1019) //Check Internet for MSL pressure at our place to calc your elevation mASL

void r1k_Bme280Sensor::init()
{
    bool wireStatus = Wire1.begin(21, 22);
    if (!wireStatus)
    {
        output.PrintMessage("I2C failed to init");
        delay(3000);
    }

    bool bme_status = bme.begin(0x76, &Wire1);  //address either 0x76 or 0x77
    if (!bme_status) 
    {
        output.PrintMessage("No valid BME280 found", "Please check wiring!");
        delay(3000);
    }
  
    bme.setSampling(Adafruit_BME280::MODE_FORCED,
                    Adafruit_BME280::SAMPLING_X16,  // temperature
                    Adafruit_BME280::SAMPLING_X1,   // pressure
                    Adafruit_BME280::SAMPLING_X1,   // humidity
                    Adafruit_BME280::FILTER_X16,
                    Adafruit_BME280::STANDBY_MS_0_5 );
}

void r1k_Bme280Sensor::TakeMeasurement()
{
    bme.takeForcedMeasurement();
}

float r1k_Bme280Sensor::Temperature()
{
    return bme.readTemperature();
}

float r1k_Bme280Sensor::Humidity()
{
    return bme.readHumidity();
}

float r1k_Bme280Sensor::Pressure()
{
    return bme.readPressure() / 100.0F;
}

float r1k_Bme280Sensor::Altitude()
{
    return bme.readAltitude(seaLevelPressure);
}