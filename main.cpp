#include"snake.h"
#include<graphics.h>
#include<conio.h>
#include<string>
#include <iostream>

using namespace std;




int main()
{
     int gd=DETECT, gm,flag=0;

     initgraph(&gd,&gm,"d:\\tc\\bgi");

     frame();
     snake(flag);
     getch();

    return 0;
}
