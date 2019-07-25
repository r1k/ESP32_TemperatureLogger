#pragma once

#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1019) //Check Internet for MSL pressure at our place to calc your elevation mASL

class r1k_Display;

class r1k_Bme280Sensor
{
private:
public:
    explicit r1k_Bme280Sensor(r1k_Display &disp) : 
        seaLevelPressure{SEALEVELPRESSURE_HPA},
        output{disp},
        bme{}
    {}

    virtual ~r1k_Bme280Sensor() {}

    r1k_Bme280Sensor(const r1k_Bme280Sensor&) = delete;
    r1k_Bme280Sensor &operator=(const r1k_Bme280Sensor&) = delete;

    r1k_Bme280Sensor(const r1k_Bme280Sensor&&) = delete;
    r1k_Bme280Sensor &operator=(const r1k_Bme280Sensor&&) = delete;

    void init();

    void TakeMeasurement();

    float Temperature();
    float Humidity();
    float Pressure();
    float Altitude();

private:
    float seaLevelPressure;
    r1k_Display &output;
    Adafruit_BME280 bme;
};