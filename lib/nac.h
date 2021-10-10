#include <iostream>
#include <windows.h>

// numpad: 1, 2, 3
#define KEY_START 0x61
#define KEY_STOP 0x62
#define KEY_SAVE 0x63s
#define KEY_EXIT 0x1B

#define KEY_DELAY 300
#define CLICK_DELAY 100

namespace nac
{

    class HNAC
    {
    private:
        int x;
        int y;
        bool running;
        bool clicking;

    public:
        HNAC();
        int GetXCoord();
        int GetYCoord();
        void Initialize();
        void SetCoordinates(int x_, int y_);
        //~HNAC();
    };
}