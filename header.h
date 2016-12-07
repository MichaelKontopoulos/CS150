#include <iostream>
#include <string>
#include <strings.h>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <cstring>
using namespace std;


char Canvas[50][50];
int CanvWIDTH=50;
int CanvHEIGHT=50;
int R[50][50];
int G[50][50];
int B[50][50];
class shape *head=NULL;
class shape *last=NULL; 
struct VectorNode *head1=NULL;
struct VectorNode *last1=NULL;


class shape{
public:
    
    
    string Shape;
    string full;
    int x;
    int y;
    int r;
    int g;
    int b;
    shape *next;
    
    
};
   

class rectangle : public shape{
public:
    int width;
    int height;
public:
    void makerectangle(string mode,int x,int y,int width,int height,int r,int g,int b);
    inline rectangle(){
    }
    inline ~rectangle(){
    }   
};

class square : public shape{
public:
    int side;
public:
    
    void makesquare(string mode,int x,int y,int side,int r,int g,int b);
    inline square(){
    }
    inline ~square(){
    }
};

class circle : public shape{
public:
    int radius;
public:
    void makecircle(string mode,int x,int y,int radius,int r,int g,int b);
    inline circle(){
    }
    inline ~circle(){
    }
};

    