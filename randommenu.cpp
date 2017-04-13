#include "graphics.hpp"
#include <vector>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace genv;
using namespace std;

int SZEL = 1280;
int MAG = 720;
int BOX = 10;

event ev;


void ClearScreen()
{
    gout << move_to(0,0) << color (0,0,0) << box(SZEL,MAG) << color (255,255,255);
}

void QuitGame()
{
    cout << "-------------------------" << endl;
    cout << "|                       |" << endl;
    cout << "|                       |" << endl;
    cout << "|                       |" << endl;
    cout << "|                       |" << endl;
    cout << "|  Thanks for playing!  |" << endl;
    cout << "|                       |" << endl;
    cout << "|                       |" << endl;
    cout << "|                       |" << endl;
    cout << "|                       |" << endl;
    cout << "-------------------------" << endl;
    exit(0);
}

void ScreenSaver()
{
    ClearScreen();

    gout << refresh;
    int x = rand() % 1119+80;
    int y = rand() % 495+80;
    int xnovel = 1;
    int ynovel = 1;
    int r = 255;
    int g = 255;
    int b = 255;
    gin.timer(1);
    gout << move_to (x, y);
    while(gin >> ev && ev.keycode != key_enter)
    {
        if (ev.time > 0)
        {
            if (ev.keycode == key_escape)
            {
                QuitGame();
            }
            x=x+xnovel;
            y= y+ynovel;
            gout << move_to(SZEL/2-90,MAG/2);
            gout << text("PRESS ENTER TO RETURN");
            gout << move_to (x, y);
            gout << box(80,80) << refresh;
            gout << move_to(0,0) << color (0,0,0) << box(SZEL,MAG) << color (r,g,b);


            // Y Tengely

            if (y < 6 && ynovel < 0)
            {
                ynovel = -1;
            }

            if (y < 6 && ynovel > 0)
            {
                ynovel = (rand()%5+1);
            }

            if (y > 633 && ynovel < 0)
            {
                ynovel = (rand()%5+1)*-1;
            }

            if (y > 633 && ynovel > 0)
            {
                ynovel = 1;
            }

            if (y ==639)
            {
                ynovel = -ynovel;
                r = rand() % 256;
                g = rand() % 256;
                b = rand() % 256;
            }
            if (y == 0 )
            {
                ynovel = -ynovel;
                r = rand() % 256;
                g = rand() % 256;
                b = rand() % 256;
            }

            // X Tengely

            if (x < 6 && xnovel < 0)
            {
                xnovel = -1;
            }

            if (x < 6 && xnovel > 0)
            {
                xnovel = (rand()%5+1);
            }

            if (x > 1193 && xnovel < 0)
            {
                xnovel = (rand()%5+1)*-1;
            }

            if (x > 1193 && xnovel > 0)
            {
                xnovel = 1;
            }

            if (x == 1199 )
            {
                xnovel = -xnovel;
                r = rand() % 256;
                g = rand() % 256;
                b = rand() % 256;
            }
            if (x == 0 )
            {
                xnovel = -xnovel;
                r = rand() % 256;
                g = rand() % 256;
                b = rand() % 256;
            }

        }
    }
}

void LetsPlay()
{
    ClearScreen();
    while(gin >> ev && ev.keycode != key_enter)
    {

        if (ev.keycode == key_escape)
        {
            QuitGame();
        }
        gout << move_to(SZEL/2-36,MAG/3-25);
        gout << text("ITT LENNE A SNAKE :D");
        gout << move_to(SZEL/2-36,MAG/3-85);
        gout << text("ENTER ÉS VISSZALÉPSZ A FÕMENÜBE");
        gout << refresh;
    }
}

void menu()
{
    gin.timer(0);
    if (ev.keycode == key_escape)
    {
        QuitGame();
    }

    gout << move_to(SZEL/2-36,MAG/3-25);
    gout << color (0,0,120) << box(100,40) << color (255,255,255);
    gout << move_to(SZEL/2,MAG/3);
    gout << text("PLAY");

    gout << move_to(SZEL/2-36,MAG/3+30);
    gout << color (0,0,120) << box(100,40) << color (255,255,255);
    gout << move_to(SZEL/2,MAG/3+55);
    gout << text("QUIT");

    gout << move_to(SZEL/2-36,MAG/3+85);
    gout << color (0,0,120) << box(100,40) << color (255,255,255);
    gout << move_to(SZEL/2-33,MAG/3+110);
    gout << text("Screen Saver");

    gout << refresh;


    //--PLAY--///////////////////////////////////////////////////////////////////////////////

    if (ev.pos_x >SZEL/2-36 && ev.pos_y > MAG/3-25 && ev.pos_x < SZEL/2-36+100 && ev.pos_y < MAG/3-25+40)
    {
        if (ev.button == btn_left)
        {
            LetsPlay();
        }

        gout << move_to(SZEL/2-41,MAG/3-30);
        gout << color (255,255,255) << box(110,50);

        gout << move_to(SZEL/2-36,MAG/3-25);
        gout << color (0,0,120) << box(100,40) << color (255,255,255);
        gout << move_to(SZEL/2,MAG/3);
        gout << text("PLAY") << refresh;
    }


    //--QUIT--///////////////////////////////////////////////////////////////////////////////

    if (ev.pos_x > SZEL/2-36 && ev.pos_y > MAG/3+30 && ev.pos_x < SZEL/2-36+100 && ev.pos_y < MAG/3+30+40)
    {
        if (ev.button == btn_left)
        {
            QuitGame();
        }
        gout << move_to(SZEL/2-41,MAG/3+25);
        gout << color (255,255,255) << box(110,50);

        gout << move_to(SZEL/2-36,MAG/3+30);
        gout << color (0,0,120) << box(100,40) << color (255,255,255);
        gout << move_to(SZEL/2,MAG/3+55);
        gout << text("QUIT") << refresh;
    }

    //--SCREENSAVER--////////////////////////////////////////////////////////////////////////

    if (ev.pos_x > SZEL/2-36 && ev.pos_y > MAG/3+85 && ev.pos_x < SZEL/2-36+100 && ev.pos_y < MAG/3+85+40)
    {
        if (ev.button == btn_left)
        {
            ScreenSaver();
        }
        gout << move_to(SZEL/2-41,MAG/3+80);
        gout << color (255,255,255) << box(110,50);

        gout << move_to(SZEL/2-36,MAG/3+85);
        gout << color (0,0,120) << box(100,40) << color (255,255,255);
        gout << move_to(SZEL/2-33,MAG/3+110);
        gout << text("Screen Saver") << refresh;
    }

    //--NOBORDER--///////////////////////////////////////////////////////////////////////////

    if (ev.pos_x < SZEL/2-36 || ev.pos_y < MAG/3-25 || ev.pos_x > SZEL/2-36+100 || ev.pos_y > MAG/3+85+40 || (ev.pos_y > MAG/3+15 && ev.pos_y < MAG/3+30) || (ev.pos_y > MAG/3+70 && ev.pos_y < MAG/3+85 ))
    {
        ClearScreen();

        gout << move_to(SZEL/2-36,MAG/3-25);
        gout << color (0,0,120) << box(100,40) << color (255,255,255);
        gout << move_to(SZEL/2,MAG/3);
        gout << text("PLAY");

        gout << move_to(SZEL/2-36,MAG/3+30);
        gout << color (0,0,120) << box(100,40) << color (255,255,255);
        gout << move_to(SZEL/2,MAG/3+55);
        gout << text("QUIT");

        gout << move_to(SZEL/2-36,MAG/3+85);
        gout << color (0,0,120) << box(100,40) << color (255,255,255);
        gout << move_to(SZEL/2-33,MAG/3+110);
        gout << text("Screen Saver");

        gout << refresh;
    }

}



int main()
{
    srand(time(0));
    gout.open(SZEL,MAG);
    while(gin >> ev)
    {
            menu();

    }
    return 0;
}
