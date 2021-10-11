#include "nac.h"

using namespace nac;

HNAC::HNAC(void)
{
    x = 0;
    y = 0;
    running = false;
    clicking = false;
    click_delay = 300;
}

void HNAC::SetCoordinates(int x_, int y_)
{
    x = x_;
    y = y_;
}

void HNAC::ShowMenu(void)
{
    puts("\
    > Numpad1: comenzar autoclicker\n\
    > Numpad2: parar autoclicker\n\
    > Numpad3: guardar posicion del mouse\n\
    > Numpad4: establecer velocidad del autoclicker");
}

void HNAC::Click(void)
{
    Sleep(click_delay);
    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
}

void HNAC::SetConsoleTitleN(void)
{
    char tmp[] = "title NAC ";
    strcat(tmp, VERSION);
    system(tmp);
}

void HNAC::SaveMousePosition(void)
{
    Sleep(KEY_DELAY);
    POINT CursorPosition;
    GetCursorPos(&CursorPosition);
    SetCoordinates(CursorPosition.x, CursorPosition.y);
    puts("> Posicion del mouse guardada");
}

void HNAC::SetClickSpeed(void)
{
    int tmp;
    std::cout << "> Introduce la velocidad (100, 200..): ";
    std::cin >> tmp;
    click_delay = tmp;
    std::cout << "> Nueva velocidad establecida: " << click_delay
              << std::endl;
}

void HNAC::Initialize(void)
{
    if (running)
    {
        puts("ne0de's autoclicker ya esta en ejecucion");
        return;
    }

    running = true;
    puts("ne0de's autoclicker iniciado correctamente");
    SetConsoleTitleN();
    ShowMenu();

    while (running)
    {
        if (clicking)
            Click();

        if (GetAsyncKeyState(KEY_SAVE))
            SaveMousePosition();

        if (GetAsyncKeyState(KEY_CONS) && !clicking)
            SetClickSpeed();

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
            puts("ne0de's autoclicker cerrado correctamente");
        }
    }
}
