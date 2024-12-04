//Write a C program to print a rectangle with its diagonals. 
 
#include<conio.h> 
#include<stdio.h> 
#include<graphics.h> 
 
void main() 
{ 
 int gd = DETECT, gm; 
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
 rectangle(100, 10, 400, 150); 
 line(100, 10, 400, 150); 
 line(400, 10, 100, 150); 
 getch(); 
 closegraph(); 
}