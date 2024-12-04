// Write a C program to print a triangle with predefined vertices using Breshenhams Line Algorithm. 
 
#include<conio.h> 
#include<stdio.h> 
#include<graphics.h> 
 
void plotLineHigh(int x1, int y1, int x2, int y2) 
{ 
 int dx, dy, xi, D, x, y; 
 dx = x2-x1; 
 dy = y2-y1; 
 xi = 1; 
 if(dx < 0) 
 { 
  xi = -1; 
  dx = -dx; 
 } 
 D = (2*dx) - dy; 
 x = x1; 
 y = y1; 
 while(y <= y2) 
 { 
  putpixel(x, y, WHITE); 
  if(D > 0) 
  { 
   D += 2*(dx-dy); 
   x += xi; 
  } 
  else 
   D += (2*dx); 
  y++; 
 } 
} 
 
void plotLineLow(int x1, int y1, int x2, int y2) 
{ 
 int dx, dy, x, y, yi, D; 
 dx = x2-x1; 
 dy = y2-y1; 
 yi = 1; 
 if(dy < 0) 
 { 
  dy = -dy; 
  yi = -1; 
 } 
 D = 2*dy - dx; 
 x = x1; 
 y = y1; 
 while(x <= x2) 
 { 
  putpixel(x, y, WHITE); 
  if(D > 0) 
  { 
   D += 2*(dy-dx); 
   y += yi; 
  } 
  else 
   D += 2*dy; 
  x++; 
 } 
} 
 
void plotLine(int x1, int y1, int x2, int y2) 
{ 
 if(abs(y2-y1) < abs(x2-x1)) 
 { 
  if(x1 < x2) 
  plotLineLow(x1, y1, x2, y2); 
  else 
  plotLineLow(x2, y2, x1, y1); 
 } 
 else if(y1 > y2) 
  plotLineHigh(x2, y2, x1, y1); 
 else 
  plotLineHigh(x1, y1, x2, y2); 
} 
 
void main() 
{ 
    int gd = DETECT, gm; 
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
    plotLine(100, 100, 20, 180); 
    plotLine(20, 180, 180, 180); 
    plotLine(180, 180, 100, 100); 
    getch(); 
    closegraph(); 
}