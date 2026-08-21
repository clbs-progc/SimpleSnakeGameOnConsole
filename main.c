#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include "fff.h"

typedef struct player Player;
struct player
{
    int X;
    int Y;
};



//dd = 3650
int nScreenHeight = 61, nScreenWidth = 61, playerSize = 3;
unsigned long long int cont = 1;
time_t t;

int rng(int seed, int range)
{
    srand(cont);
    int g = rand();
    srand(time(&t));
    int g2 = rand();
    g = g+g2;
    srand(g);
    int RandomGen1 = rand() % range;
    cont++;
    switch(cont)
    {
        case 4000000000:
            cont = 1;
        break;
    }
    srand(seed);
    int RandomGen2 = rand() % range;
    RandomGen1 = RandomGen1 + RandomGen2;
    RandomGen1 = RandomGen1/2;
    return RandomGen1;
}

int main()
{
    int playerPosY = 30, playerPosX = 30;
    //declaring const
    int test = 0;
    int info = 0, dd = 10, incrementX = 0, incrementY = -1, movepoints = 0, ETorF = 0, point = 0, gameover = 0, contpoints = 0, raa = rand();
    int nScreenHeightREAL = nScreenHeight-2, nScreenWidthREAL = nScreenWidth-2, raa2, ElapsedTime = 0, pause = 0;
    int sizeincrease = 1;
    clock_t start, end, start2;
    int tickrateDes = 12;
    unsigned int SleepTime = 1000000/tickrateDes;
    unsigned long long int ulliTick = 0;
    int tickrate = 1000000/SleepTime;

    //creating the screen
    SetConsoleTitle(" ");
    COORD coord = {0,0};
    COORD erromsg = {25,15};
    char **falsescreen = (char**) malloc(nScreenHeight*sizeof(char*));
    for(int y = 0; y<nScreenHeight; y++)
    {
        falsescreen[y] = (char*) malloc(nScreenWidth*sizeof(char));
    }
    char *screen = (char*) malloc(((nScreenHeight*nScreenWidth)+1)*sizeof(char));
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;
	raa2 = rand();
    Player *p = (Player*) malloc(10*sizeof(Player)); //creating player
    if(p == NULL)
    {
        sprintf(screen, "ERROR 1");
        gameover = 1;
        point = 1;
        WriteConsoleOutputCharacter(hConsole, screen, nScreenHeight*nScreenWidth, erromsg, &dwBytesWritten);
        Sleep(5000);
    }
    else
    {
        for(int x = 0; x < playerSize; x++)
        {
            p[x].X = playerPosX;
            p[x].Y = playerPosY + x;
        }
    }
	//generating the first random position
    int randomX = rng(raa, nScreenHeightREAL), randomY = rng(raa2, nScreenWidthREAL), ErandomX, ErandomY, Econt, hX, hY;
    switch(randomX)
    {
        case 0:
            randomX++;
        break;
    }
    switch(randomY)
    {
        case 0:
            randomY++;
        break;
    }
    start = clock();
    start2 = clock();
    //game starts
    while(gameover == 0)
    {
        switch(ETorF)
        {
            case 1:
            break;

            default:
                Econt = rng(ulliTick, 100);
                //Econt = 50;
                switch(Econt)
                {
                    case 50:
                        ErandomX = rng(raa, nScreenWidthREAL);
                        SwitchCaseRngIsZero(1);
                        ErandomY = rng(cont, nScreenWidthREAL);
                        SwitchCaseRngIsZero(ErandomY);
                        raa = rand();
                        if(ErandomY == randomY && ErandomX == randomX)
                        {
                            ErandomX = rng(raa, nScreenWidthREAL);
                            SwitchCaseRngIsZero(ErandomX);
                            ErandomY = rng(cont, nScreenWidthREAL);
                            SwitchCaseRngIsZero(ErandomY);
                            raa = rand();
                        }
                        ETorF = 1;
                    break;
                }
        }
        while(point == 0)
        {
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                point = 1;
                gameover = 1;
            }

            if(GetAsyncKeyState('P'))
            {
                info = 1;
            }

            if(GetAsyncKeyState('O'))
            {
                info = 0;
            }

            //CONTROLS
            //mov(incrementY, incrementX, movepoints, playerPosY, playerPosX);
            if(GetAsyncKeyState('W')) //'W' VK_UP
            {
                switch(movepoints)
                {
                    case 0:

                        switch(incrementY)
                        {
                            case 1:
                                incrementY = 1;
                                //incrementX = 0;
                            break;

                            default:
                                incrementY = -1;
                                incrementX = 0;
                                movepoints = 1;
                                playerPosY = playerPosY + incrementY;
                        }
                    break;
                }
            }
            if(GetAsyncKeyState('S')) //'S' VK_DOWN
            {
                switch(movepoints)
                {
                    case 0:
                        switch(incrementY)
                        {
                            case -1:
                                incrementY = -1;
                                //incrementX = 0;
                            break;

                            default:
                                incrementY = 1;
                                incrementX = 0;
                                movepoints = 1;
                                playerPosY = playerPosY + incrementY;
                        }
                    break;
                }
            }
            if(GetAsyncKeyState('A')) //'A' VK_LEFT
            {
                switch(movepoints)
                {
                    case 0:
                        switch(incrementX)
                        {
                            case 1:
                                //incrementY = 0;
                                incrementX = 1;
                            break;

                            default:
                                incrementY = 0;
                                incrementX = -1;
                                movepoints = 1;
                                playerPosX = playerPosX + incrementX;
                        }
                    break;
                }
            }
            if(GetAsyncKeyState('D')) //'D' VK_RIGHT
            {
                switch(movepoints)
                {
                    case 0:
                        switch(incrementX)
                        {
                            case -1:
                                //incrementY = 0;
                                incrementX = -1;
                            break;

                            default:
                                incrementY = 0;
                                incrementX = 1;
                                movepoints = 1;
                                playerPosX = playerPosX + incrementX;
                        }
                    break;
                }
            }
            if(GetAsyncKeyState('G'))
            {
                switch(tickrateDes)
                {
                    case 2:
                        tickrateDes = 2;
                        break;

                    default:
                        tickrateDes--;
                }
            }
            if(GetAsyncKeyState('H'))
            {
                tickrateDes++;
            }
            if(GetAsyncKeyState('K'))
            {
                    pause = 1;
                    movepoints = 1;

            }
            if(GetAsyncKeyState('L'))
            {
                switch(pause)
                {
                    case 1:
                        pause = 0;
                        movepoints = 0;
                    break;

                    default:
                        break;
                }

            }
            switch(movepoints)
            {
                case 0:
                    if(pause == 0)
                    {
                        playerPosX = playerPosX + incrementX;
                        playerPosY = playerPosY + incrementY;
                    }
                break;
            }
            playerPosX = TeleportingPlayerCaseWall(playerPosX, nScreenWidth);
            playerPosY = TeleportingPlayerCaseWall(playerPosY, nScreenHeight);
            for(int x = playerSize; x > 0 ; x--)
            {
                p[x].X = p[x-1].X;
                p[x].Y = p[x-1].Y;
            }

            p[0].X = playerPosX;
            p[0].Y = playerPosY;
            //END OF CONTROLS

            //DRAWING
            falsescreen[0][0] = '#';
            for(int y = 1; y<nScreenHeight; y++)
            {
                for(int x = 1; x<nScreenWidth; x++)
                {
                    falsescreen[y][x] = ' ';
                    falsescreen[0][x] = '#';
                    falsescreen[nScreenHeight-1][x] = '#';
                }
                falsescreen[y][0] = '#';
                falsescreen[y][nScreenWidth-1] = '#';
            }
            falsescreen[playerPosY][playerPosX] = 'O';
            //player moves here
            for(int x = 1; x < playerSize; x++)
            {
                hX = p[x].X;
                hY = p[x].Y;
                falsescreen[hY][hX] = 'o';
                if(pause == 0)
                {
                    if(playerPosY == p[x].Y && playerPosX == p[x].X)
                    {
                        point = 1;
                        gameover = 1;
                    }
                }

                if(randomY == p[x].Y && randomX == p[x].X)
                {
                    randomY = rng(raa, nScreenWidthREAL);
                    SwitchCaseRngIsZero(randomY);
                    randomX = rng(raa2, nScreenWidthREAL);
                    SwitchCaseRngIsZero(randomX);
                }
                switch(ETorF)
                {
                    case 1:
                        if(ErandomY == p[x].Y && ErandomX == p[x].X)
                        {
                            ErandomY = rng(raa, nScreenWidthREAL);
                            SwitchCaseRngIsZero(ErandomY);
                            ErandomX = rng(raa2, nScreenWidthREAL);
                            SwitchCaseRngIsZero(ErandomX);
                        }
                    break;
                }
            }
            if(test == 1){
                playerSize = playerSize + sizeincrease;
                test = 0;
            }
            falsescreen[randomY][randomX] = '*';
            switch(ETorF)
            {
                case 1:
                    falsescreen[ErandomY][ErandomX] = 'X';
                break;
            }
            //if point++ -> player data increases
            if(playerPosY == randomY && playerPosX == randomX)
            {
                playerSize++;
                dd = dd + 3;
                p = (Player*) realloc(p, dd*sizeof(Player));
                if(p == NULL)
                {
                    for(int x = 0; x < nScreenHeight*nScreenWidth; x++)
                    {
                        screen[x] = ' ';
                    }
                    sprintf(screen, "ERROR 2");
                    gameover = 1;
                    point = 1;
                    WriteConsoleOutputCharacter(hConsole, screen, nScreenHeight*nScreenWidth, erromsg, &dwBytesWritten);
                    Sleep(5000);
                }
                point = 1;
            }
            if(playerPosY == ErandomY && playerPosX == ErandomX)
            {
                sizeincrease = 2;
                contpoints = contpoints + 2;
                playerSize = playerSize + 2;
            //changing from false screen to real screen
            int f=0;
            for(int y = 0; y<nScreenHeight; y++)
            {
                for(int x = 0; x<nScreenWidth; x++)
                {
                    screen[f] = falsescreen[y][x];
                    f++;
                }
            }
            ulliTick++;
            switch(info)
            {
                case 1:
                    sprintf(screen, "X:%i | Y:%i TIME = %f s  TICKRATE = %i  ECONT = %i", playerPosX, playerPosY, ((float) (end-start)/CLOCKS_PER_SEC), tickrateDes, Econt);
                break;
            }
            screen[nScreenHeight*nScreenWidth] = '\0';
            WriteConsoleOutputCharacter(hConsole, screen, nScreenHeight*nScreenWidth, coord, &dwBytesWritten);
            raa = rand();
            if(pause == 0){movepoints = 0;}
            end = clock();
            ElapsedTime = ((end-start2)/CLOCKS_PER_SEC)*1000;
            SleepTime = (1000000/tickrateDes - (ElapsedTime));
            usleep(SleepTime);
            start2 = clock();
            raa2 = rand();
        }
        contpoints++;
        point = 0;
        raa2 = rand();
        randomX = rng(raa, nScreenHeightREAL);
        randomX = SwitchCaseRngIsZero(randomX);
        randomY = rng(raa2, nScreenWidthREAL);
        randomY = SwitchCaseRngIsZero(randomY);
        switch(ETorF)
        {
            case 1:
            break;

            default:
                Econt = rng(ulliTick, 100);
                //Econt = 50;
                switch(Econt)
                {
                    case 50:
                        ErandomX = rng(raa, nScreenWidthREAL);
                        SwitchCaseRngIsZero(ErandomX);
                        ErandomY = rng(cont, nScreenWidthREAL);
                        SwitchCaseRngIsZero(ErandomY);
                        raa = rand();
                        if(ErandomY == randomY && ErandomX == randomX)
                        {
                            ErandomX = rng(raa, nScreenWidthREAL);
                            SwitchCaseRngIsZero(ErandomX);
                            ErandomY = rng(cont, nScreenWidthREAL);
                            SwitchCaseRngIsZero(ErandomY);
                            raa = rand();
                        }
                        ETorF = 1;
                    break;
                }
        }
    }
    for(int y = 0; y<nScreenHeight; y++)
    {
        free(falsescreen[y]);
    }
    free(falsescreen);
    free(p);
    free(screen);
    return 1;
}
