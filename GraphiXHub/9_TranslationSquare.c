//Write a C program to perform translation of a square with predefined vertices. 
 
#include<conio.h> 
#include<stdio.h> 
#include<graphics.h> 
 
void main() 
{ 
 int gd = DETECT, gm, tx, ty; 
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
 rectangle(50, 50, 300, 300); 
 setcolor(14); 
 printf("Enter the translation distance for x: "); 
 scanf("%d",&tx); 
 printf("Enter the translation distance for y: "); 
 scanf("%d",&ty); 
 rectangle(50+tx, 50+ty, 300+tx, 300+ty); 
 getch(); 
 closegraph(); 
}