#pragma once
#include <iostream>
#include <string.h>
#include <windows.h>

// numpad: 1, 2, 3, 4
#define KEY_START 0x43
#define KEY_STOP 0x50
#define KEY_SAVE 0x47
#define KEY_CONS 0x56
#define KEY_EXIT 0x74
#define KEY_DELAY 300

#define VERSION "v0.0.3a"

namespace nac
{

    class HNAC
    {
    private:
        int x;
        int y;
        float click_delay;
        bool running;
        bool clicking;

    public:
        HNAC();
        void Click(void);
        void ShowMenu(void);
        void Initialize(void);
        void SetClickSpeed(void);
        void SaveMousePosition(void);
        void SetCoordinates(int x_, int y_);
        void SetConsoleTitleN(void);
        //~HNAC();
    };
}
