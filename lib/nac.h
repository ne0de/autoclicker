#include <iostream>
#include <windows.h>

// numpad: 1, 2, 3, 4
#define KEY_START 0x61
#define KEY_STOP 0x62
#define KEY_SAVE 0x63
#define KEY_CONS 0x64
#define KEY_EXIT 0x1B
#define KEY_DELAY 300

namespace nac
{

    class HNAC
    {
    private:
        int x;
        int y;
        int click_delay;
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
        //~HNAC();
    };
}
