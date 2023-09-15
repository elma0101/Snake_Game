#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED


struct point {
 int x,y;
} ;

void frame();
void create_fruit();
void snake(int flag);
int collision(int x,int y,int rand_x,int rand_y);
void gameover();

#endif // SNAKE_H_INCLUDED
