#include"snake.h"
#include<graphics.h>
#include <iostream>
#include<conio.h>
#include<string>
#include <time.h>

using namespace std;


void frame()
{
    int points1[]= {50,50,50,400,600,400,600,50,50,50},points2[]= {50,410,50,475,600,475,600,410,50,410},i;


    setfillstyle(SOLID_FILL, BLACK);
    for(i=55; i<600; i+=5)
    {
        fillellipse(i, 55, 10, 5);
    }
    for(i=55; i<380; i+=4)
    {
        fillellipse(600, i, 10, 5);
    }

    for(i=55; i<380; i+=4)
    {
        fillellipse(55, i, 10, 5);
    }
    for(i=55; i<600; i+=5)
    {
        fillellipse(i, 380, 10, 5);
    }

    drawpoly(5,points2);
    settextstyle(2,HORIZ_DIR,7);
    outtextxy(240,20,"*** SNAKE GAME *** ");
    settextstyle(8,HORIZ_DIR,1);
    outtextxy(70,420,"p:pause/start                       score: ");
    outtextxy(70,440,"ESC:Quit ");


}

void create_fruit(int *rand_x,int *rand_y)
{
    int x_prev=0,y_prev=0;

    srand(time(NULL));

    do
    {
        *rand_x= rand() %500 +1;
        *rand_y =rand() %300;

    }
    while(*rand_x<60 || *rand_y<55 );

    setcolor(RED);
    settextstyle(2,HORIZ_DIR,5);
    outtextxy(*rand_x,*rand_y,"@");

}

int collision(int x,int y,int rand_x,int rand_y)
{

    if((x>(rand_x-5) && x<(rand_x+20)) && (y>(rand_y-5)&& y<(rand_y+15)))
    {
        setcolor(BLACK);
        settextstyle(2,HORIZ_DIR,5);
        outtextxy(rand_x,rand_y,"@");
        return TRUE;
    }

    return FALSE;

}

void gameover(point *tab,int Size)
{
    int i,flag=0;

    if(tab[0].x<=74 || tab[0].x>=580 || tab[0].y<=71 || tab[0].y>=365 )flag=1;

    for(i=1;i<Size;i++)
     {
       if(tab[0].x==tab[i].x && tab[0].y==tab[i].y)
            flag=1;
     }

    if(flag==1)
    {
        cleardevice();
        settextstyle(2, HORIZ_DIR, 8);
        outtextxy(240,210,"GAME OVER !");
    }

}

void snake(int flag)
{
    struct point *tab=(point*)malloc(sizeof(point));

    int n=580,x=78,y=119,rand_x=100,rand_y=100,i=0,j,x_prev,y_prev,speed=3,score=0;
    char kb,kb2;


    //INITIAL PARAMETERS
    setcolor(RED);
    settextstyle(6,HORIZ_DIR,2);

    create_fruit(&rand_x,&rand_y);


    tab[0].x=78;
    tab[0].y=119;
    while(1)
    {
        std::string numberString = std::to_string(score);
        if(kbhit())
            kb2=kb;

        if(collision(tab[0].x,tab[0].y,rand_x,rand_y))
        {
            create_fruit(&rand_x,&rand_y);
            i++;
            score+=100;
            tab=(point*)realloc(tab,i*sizeof(point));

        }
        //CONTROL THE SPEED

        if(i>10 && i<20)speed=5;
        else if(i>20 )speed=7;

        //SET COLOR
        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);

        //GET VALUE
        if(kbhit())
            kb=getch();

        //CONTROL MOVEMENTS

        for(j=i-1; j>0; j--)
        {

            tab[j].x=tab[j-1].x;
            tab[j].y=tab[j-1].y;
            fillellipse(tab[j].x,tab[j].y, 5, 3);


        }

        if(kb=='d' && kb2!='q')
        {
            tab[0].x+=speed;
            fillellipse(tab[0].x,tab[0].y, 5, 3);
        }
        else if(kb=='q' && kb2!='d')
        {
            tab[0].x-=speed;
            fillellipse(tab[0].x,tab[0].y, 5, 3);

        }
        else if(kb=='z' && kb2!='s')
        {
            tab[0].y-=speed;
            fillellipse(tab[0].x,tab[0].y, 5, 3);
        }
        else if(kb=='s' && kb2!='z')
        {
            tab[0].y+=speed;
            fillellipse(tab[0].x,tab[0].y, 5, 3);
        }
        else if(int(kb)==27)
            break;

        else
        {
            if(kb2=='d')  fillellipse(tab[0].x,tab[0].y, 5, 3);
            else if(kb2=='q') fillellipse(tab[0].x,tab[0].y, 5, 3);
            else if(kb2=='z') fillellipse(tab[0].x,tab[0].y, 5, 3);
            else if(kb2=='s') fillellipse(tab[0].x,tab[0].y, 5, 3);

        }

        //CONVERSION FROM INTEGER TO A STRING

        char charArray[100];
        strcpy(charArray, numberString.c_str());
        settextstyle(8,HORIZ_DIR,1);
        outtextxy(530, 420,charArray);

        if(tab[0].x<75)tab[0].x=75;
        else if(tab[0].x>579)tab[0].x=579;
        else if(tab[0].y<72)tab[0].y=72;
        else if(tab[0].y>365)tab[0].y=365;
        //gameover(tab,i);
        delay(5);
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, BLACK);

        fillellipse(tab[0].x,tab[0].y, 5, 3);

        for(j=i-1; j>0; j--)
        {

            fillellipse(tab[j].x,tab[j].y, 5, 3);
        }

    }


}







