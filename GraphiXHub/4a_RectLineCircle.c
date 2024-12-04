//Write a C program to print rectangle, line and circle as: 
   

 
#include<conio.h> 
#include<stdio.h> 
#include<graphics.h> 
 
void main() 
{ 
 int gd = DETECT, gm; 
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
 rectangle(100, 10, 400, 150); // rectangle(left, top, right, bottom) 
 line(100, 250, 400, 250); // line(x1, y1, x2, y2) 
 circle(250, 350, 50); //circle(x, y, r) 
 getch(); 
 closegraph(); 
} 