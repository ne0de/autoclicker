#pragma once

#ifndef NAC_H
#define NAC_H

#include <iostream>
#include <string.h>
#include <windows.h>

#define KEY_START 0x43
#define KEY_STOP 0x50
#define KEY_SAVE 0x47
#define KEY_CONS 0x56
#define KEY_EXIT 0x74

#define DEFAULT_SPEED 300.0
#define KEY_DELAY 300

#define VERSION "v0.0.5a"

namespace nac
{
    class HNAC
    {

    protected:
        int x, y;
        float click_delay;
        bool running, clicking;

    public:
        HNAC();
        void Click(void);
        void ShowMenu(void);
        void Initialize(void);
        void ClearScreen(void);
        void SetClickSpeed(void);
        void SaveMousePosition(void);
        void SetCoordinates(int, int);
        void SetConsoleTitleN(void);
        //~HNAC();
    };
}

#endif
