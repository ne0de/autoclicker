#include "nac.h"

using namespace nac;

HNAC::HNAC(void)
{
    x = 0;
    y = 0;
    running = false;
    clicking = false;
    click_delay = DEFAULT_SPEED;
}

void HNAC::ShowMenu(void)
{
    puts("ne0de's autoclicker\n\
    > C: comenzar autoclicker\n\
    > P: parar autoclicker\n\
    > G: guardar posicion del mouse\n\
    > V: establecer velocidad del autoclicker");
    std::cout << "> Posicion actual: " << x << " " << y << std::endl;
    std::cout << "> Velocidad actual: " << click_delay << " cps" << std::endl;
}

void HNAC::SetConsoleTitleN(void)
{
    char tmp[] = "title NAC ";
    strcat(tmp, VERSION);
    system(tmp);
}

void HNAC::ClearScreen(void)
{
    HANDLE hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = {0, 0};

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE)
        return;

    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi))
        return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    if (!FillConsoleOutputCharacter(
            hStdOut,
            (TCHAR)' ',
            cellCount,
            homeCoords,
            &count))
        return;

    if (!FillConsoleOutputAttribute(
            hStdOut,
            csbi.wAttributes,
            cellCount,
            homeCoords,
            &count))
        return;

    SetConsoleCursorPosition(hStdOut, homeCoords);
}

void HNAC::SetCoordinates(int x_, int y_)
{
    x = x_;
    y = y_;
}

void HNAC::Click(void)
{
    Sleep(click_delay);
    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
}

void HNAC::SaveMousePosition(void)
{
    Sleep(KEY_DELAY);
    POINT CursorPosition;
    GetCursorPos(&CursorPosition);
    SetCoordinates(CursorPosition.x, CursorPosition.y);
    ClearScreen();
    ShowMenu();
    puts("> Posicion del mouse guardada");
}

void HNAC::SetClickSpeed(void)
{
    float tmp;
    std::cout << "> Introduce la velocidad (ejemplo: 50,5): ";
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
