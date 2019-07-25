#pragma once

#include <SSD1306.h>

class r1k_Display
{
private:
    static constexpr int ROW_HEIGHT{15};
    static constexpr int PIN_SDA{4};
    static constexpr int PIN_SCL{15};

    enum side_e {
        left = 0,
        right = 55
    };

public:
    r1k_Display() :
        display(0x3C, PIN_SDA, PIN_SCL)
    { }

    virtual ~r1k_Display() {}

    r1k_Display(const r1k_Display &) = delete;
    r1k_Display &operator=(const r1k_Display &) = delete;
    r1k_Display(const r1k_Display &&) = delete;
    r1k_Display &operator=(const r1k_Display &&) = delete;
    
    void init();

    void PrintMessage(const char *msg);
    void PrintMessage(const char *msg1, const char *msg2);

    void SetMenuItem(int row, const String &key, const String &value);

    void ClearDisplay();
    void UpdateDisplay();

private:
    SSD1306Wire display;
};