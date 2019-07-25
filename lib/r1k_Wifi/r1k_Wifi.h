#pragma once


class r1k_Display;

class r1k_Wifi
{
public:
    explicit r1k_Wifi(r1k_Display &display);
    virtual ~r1k_Wifi();

    r1k_Wifi(const r1k_Wifi&) = delete;
    r1k_Wifi &operator=(const r1k_Wifi&) = delete;
    r1k_Wifi(const r1k_Wifi&&) = delete;
    r1k_Wifi &operator=(const r1k_Wifi&&) = delete;

    bool ConnectToAccessPoint(const char *ssid, const char * password, bool displayDiagnostics=false);

    bool Connected();


private:

    r1k_Display &disp;
};