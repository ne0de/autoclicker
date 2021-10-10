#include "nac.h"

using namespace nac;

HNAC::HNAC()
{
    x = 0;
    y = 0;
    running = false;
    clicking = false;
}

void HNAC::SetCoordinates(int x_, int y_)
{
    x = x_;
    y = y_;
}

void HNAC::Initialize()
{
    if (running)
    {
        puts("NAC ya esta en ejecucion");
        return;
    }

    running = true;
    puts("ne0de's autoclicker iniciado correctamente");

    while (running)
    {
        if (clicking)
        {
            Sleep(CLICK_DELAY);
            SetCursorPos(x, y);
            mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
        }

        if (GetAsyncKeyState(VK_NUMPAD3))
        {
            Sleep(KEY_DELAY);
            POINT CursorPosition;
            GetCursorPos(&CursorPosition);
            SetCoordinates(CursorPosition.x, CursorPosition.y);
            puts("> Posicion del mouse guardada");
        }

        if (GetAsyncKeyState(KEY_START) && !clicking)
        {
            clicking = true;
            puts("> Autoclick iniciado");
        }

        if (GetAsyncKeyState(KEY_STOP) && clicking)
        {
            clicking = false;
            puts("> Autoclick apagado");
        }

        if (GetAsyncKeyState(VK_ESCAPE))
        {
            running = false;
            puts("NAC cerrado correctamente");
        }
    }
}

int HNAC::GetXCoord()
{
    return x;
}

int HNAC::GetYCoord()
{
    return y;
}