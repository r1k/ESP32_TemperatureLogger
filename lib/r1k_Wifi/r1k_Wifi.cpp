#include <Wifi.h>

#include <r1k_Display.h>

#include "r1k_Wifi.h"


r1k_Wifi::r1k_Wifi(r1k_Display &display) :
    disp{display}
{
    WiFi.disconnect(true);
    delay(1000);
    WiFi.mode(WIFI_STA);
	WiFi.setAutoConnect(true);
}

r1k_Wifi::~r1k_Wifi()
{
    WiFi.disconnect(true);
}

bool r1k_Wifi::ConnectToAccessPoint(const char *ssid, const char * password, bool displayDiagnostics)
{
    WiFi.begin(ssid, password);
    int count{10};
    while (!Connected() && count > 0)
    {
        count--;
        if (displayDiagnostics)
        {
            disp.PrintMessage("Connecting...");
        }
        delay(500);
    }

    if (!count)
    {
        if (displayDiagnostics)
        {
            disp.PrintMessage("Unable to connect to WiFi");
            delay(3000);
        }
        return false;
    }
    else
    {
        if (displayDiagnostics)
        {
            disp.PrintMessage("Connected.");
            delay(2000);
        }
        return true;
    }
}

bool r1k_Wifi::Connected()
{
    return WiFi.status() == WL_CONNECTED;
}
