// Write a C program to make line reflection in x-axis and y-axis. 
 
#include<conio.h> 
#include<stdio.h> 
#include<graphics.h> 
 
void main() 
{ 
 int gd = DETECT, gm, x1=50, y1=50, x2=100, y2=100; 
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
 printf("Reflection in x and y axis of the white line:"); 
 line(0, getmaxy()/2, getmaxx(), getmaxy()/2); 
 line(getmaxx()/2, 0, getmaxx()/2, getmaxy()); 
 line(x1, y1, x2, y2); 
 setcolor(14); 
 line(x1, getmaxy()-y1, x2, getmaxy()-y2); 
 line(getmaxx()-x1, y1, getmaxx()-x2, y2); 
 getch(); 
 closegraph(); 
}