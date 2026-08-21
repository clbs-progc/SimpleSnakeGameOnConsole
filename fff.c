#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "fff.h"

int SwitchCaseRngIsZero(int x)
{
    switch(x)
    {
        case 0:
            x = x+1;
            return x;
        break;
    }
    return x;
}

int TeleportingPlayerCaseWall(int POS, int WALL)
{
    WALL--;

    if(POS > WALL-1)
    {
        POS = 1;
    }
    if(POS < 1)
    {
        POS = WALL-1;
    }
    return POS;
}


