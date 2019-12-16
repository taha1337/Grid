#include <ncurses.h>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

char grid[10][15];
void init();
void print();
void moveLeft();
void moveRight();
void moveDown();
void moveUp();
//void move();
int posx = 0, posy = 0;
int oldx = 0, oldy = 0;

int main()
{
    init();    
    print();
    //BufferToggle bt;
    //bt.off();
    while(true){
            
       char inp = cin.get();//getch();
      switch(inp){
        case 'A': case 'a':
          moveLeft();
          //print();
          break;
        case 'S': case 's':
          moveDown();
          //print();
          break;
        case 'D': case 'd':
          moveRight();
          //print();
          break;
        case 'W': case 'w':
          moveUp();
          //print();
          break;
        default:
          //print();
          break;
      }
      system("clear");        
      print();
    }

    return 0;
}


void init(){
    for(int i = 0; i <= 9; i++){
        for(int k = 0; k <= 14; k++){
         grid[i][k] = 'X';
        }
    }
    posx = 0;
    posy = 0;
}

void moveUp() {
    oldx = posx;
    oldy = posy;
    posy--;
    if(posy < 0){
        posy++; // do nothing
    }
    /*else if(posy >= 5){
        //init();
        posy = 0;
    }*/
    grid[oldy][oldx] = 'X';
    grid[posy][posx] = ' ';
}
void moveDown() {
    oldx = posx;
    oldy = posy;
    posy++;
    if(posy > 9){
        posy--; // do nothing
    }
    /*else if(posy >= 5){
        //init();
        posy = 0;
    }*/
    grid[oldy][oldx] = 'X';
    grid[posy][posx] = ' ';
}

void moveRight() {
    oldx = posx;
    oldy = posy;
    posx++;
    if(posx > 14){
        posx--; // do nothing
    }
    /*else if(posy >= 5){
        //init();
        posy = 0;
    }*/
    grid[oldy][oldx] = 'X';
    grid[posy][posx] = ' ';
}

void moveLeft() {
    oldx = posx;
    oldy = posy;
    posx--;
    if(posx < 0){
        posx++; // do nothing
    }
    /*else if(posy >= 5){
        //init();
        posy = 0;
    }*/
    grid[oldy][oldx] = 'X';
    grid[posy][posx] = ' ';
}

void print() {
    for(int i = 0; i <= 9; i++){
        for(int k = 0; k <= 14; k++){
          //if
          cout << grid[i][k] << " ";
        }
        cout << endl;
    }
}
