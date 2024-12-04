//Write a C program to print the figure: 


#include<conio.h> 
#include<stdio.h> 
#include<graphics.h> 
 
void main() 
{ 
 int gd = DETECT, gm; 
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
 rectangle(200, 200, 300, 300); 
 line(120, 250, 200, 200); 
 line(200, 200, 250, 120); 
 line(250, 120, 300, 200); 
 line(300, 200, 380, 250); 
 line(380, 250, 300, 300); 
 line(300, 300, 250, 380); 
 line(250, 380, 200, 300); 
 line(200, 300, 120, 250); 
 getch(); 
 closegraph(); 
}