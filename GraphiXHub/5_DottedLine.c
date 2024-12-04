//Write a C program to print a dotted line. 
 
#include<conio.h> 
#include<stdio.h> 
#include<graphics.h> 
 
void main() 
{ 
 int gd = DETECT, gm; 
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
 setlinestyle(1, 1, 3); 
 line(0, getmaxy()/2, getmaxx(), getmaxy()/2); 
 getch(); 
 closegraph(); 
} 