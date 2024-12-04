//Write a C program to perform scaling on a square with predefined vertices. 
 
#include<stdio.h> 
#include<conio.h> 
#include<graphics.h> 
 
void main() 
{ 
 int gd = DETECT, gm, sx, sy; 
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
 rectangle(50, 50, 100, 100); 
 setcolor(14); 
 printf("Enter the scaling factor for x: "); 
 scanf("%d",&sx); 
 printf("Enter the scaling factor for y: "); 
 scanf("%d",&sy); 
 rectangle(50*sx, 50*sy, 100*sx, 100*sy); 
 getch(); 
 closegraph(); 
} 