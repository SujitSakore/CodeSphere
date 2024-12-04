//Write a C program to draw a square using dda. 
 
#include<conio.h> 
#include<stdio.h> 
#include<graphics.h> 
#include<math.h> 
 
void dda(int x1, int y1, int x2, int y2) 
{ 
 int dx, dy, steps, i; 
 float xinc, yinc, x, y; 
 dx = x2-x1; 
 dy = y2-y1; 
 steps = (abs(dx)>abs(dy))?abs(dx):abs(dy); 
 xinc = dx/(steps*1.0); 
 yinc = dy/(steps*1.0); 
 x = x1; 
 y = y1; 
 for(i = 0; i < steps; i++) 
 { 
  putpixel((int)x, (int)y, WHITE); 
  x+=xinc; 
  y+=yinc; 
 } 
} 
 
void main() 
{ 
 int gd = DETECT, gm; 
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
 dda(100, 100, 200, 100); 
 dda(200, 100, 200, 200); 
 dda(200, 200, 100, 200); 
 dda(100, 200, 100, 100); 
 getch(); 
 closegraph(); 
}