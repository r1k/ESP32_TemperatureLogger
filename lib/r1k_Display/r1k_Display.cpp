#include "r1k_Display.h"

void r1k_Display::init()
{
    pinMode(16,OUTPUT);
    digitalWrite(16, LOW); // set GPIO16 low to reset OLED
    delay(50);
    digitalWrite(16, HIGH);
    delay(50);
    display.init();
    display.setFont(ArialMT_Plain_10);
    delay(50);
    PrintMessage("Starting up", "  and initializing.");
    UpdateDisplay();
    delay(500);
}

void r1k_Display::PrintMessage(const char *msg)
{
    ClearDisplay();
    display.drawString( 0, 20, msg);
    UpdateDisplay();
}

void r1k_Display::PrintMessage(const char *msg1, const char *msg2)
{
    ClearDisplay();
    display.drawString( 0, 15, msg1);
    display.drawString( 0, 30, msg2);
    UpdateDisplay();
}

void r1k_Display::SetMenuItem(int row, const String &key, const String &value)
{
    auto Write = [&] (const String &msg, int row, enum side_e side) {
        display.drawString(side, row * ROW_HEIGHT, msg);
    };

    Write(key, row, left);
    Write(value, row, right);
}

void r1k_Display::ClearDisplay()
{
    display.clear();
}

void r1k_Display::UpdateDisplay()
{
    display.display(); // print display buffer
}