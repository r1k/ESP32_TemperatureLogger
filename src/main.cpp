#include <r1k_Display.h>
#include <r1k_Bme280Sensor.h>
#include <r1k_Wifi.h>


r1k_Display oled;
r1k_Bme280Sensor sensor(oled);

r1k_Wifi wifi(oled);

const char *ssid = "SSID";
const char *ap_pass = "AP_PASSWORD";

void setup() 
{
    pinMode(LED, OUTPUT);
	digitalWrite(LED, HIGH);

    oled.init();
    oled.PrintMessage("Starting up ...", "- and initializing.");
    delay(500);

    sensor.init();

    wifi.ConnectToAccessPoint(ssid, ap_pass, true);
}

void Sensor() 
{
    sensor.TakeMeasurement();

    oled.ClearDisplay();

    // Print temperature
    oled.SetMenuItem(0, "Temp.", String(sensor.Temperature()) + " °C");

    // Print humidity
    oled.SetMenuItem(1, "Humidity", String(sensor.Humidity()) + " %");

    // Print pressure
    oled.SetMenuItem(2, "Pressure", String(sensor.Pressure()) + " hPa");

    auto networkConnected = wifi.Connected();
    if (!networkConnected)
    {
        networkConnected = wifi.ConnectToAccessPoint(ssid, ap_pass, false);
    }

    if (networkConnected)
    {
        // Print altitude
        oled.SetMenuItem(3, "Altitude", String(sensor.Altitude()) + " m ASL");

        // Send sensor information to server
    }
    else
    {
        oled.SetMenuItem(2, "Network", "Fail");
    }
    

    oled.UpdateDisplay();

    delay(5000);
}

int count = 0;
void loop() 
{
    count++;

    if (count % 3 == 0)
    {
        Sensor();
    }

    delay(1000);
}