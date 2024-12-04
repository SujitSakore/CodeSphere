//Write a C program to print the word “Graphics” in 10 different fonts and colours. 
 
#include<conio.h> 
#include<graphics.h> 
#include<stdio.h> 
 
void main() 
{ 
 int gd=DETECT, gm, i; 
 initgraph(&gd, &gm,  "C:\\TURBOC3\\BGI"); 
 for(i = 0; i < 10; i++) 
 { 
  setcolor(i+1); 
  settextstyle(i,0,1); 
  //settextstyle(font, vertical(0)/horizontal(1), size) 
  outtextxy(40, i*30+20, "Graphics"); 
 } 
 getch(); 
 closegraph();//to deallocate the memory 
}