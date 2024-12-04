// Write a C program to print the word “Google” with its default colour. 
 
 
#include<conio.h> 
#include<stdio.h> 
#include<graphics.h> 
 
void main() 
{ 
 int gd=DETECT, gm; 
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
 settextstyle(1, 0, 4); 
 setcolor(9);//blue 
 outtext("G"); 
 setcolor(12);//red 
 outtext("o"); 
 setcolor(14);//yellow 
 outtext("o"); 
 setcolor(9);//blue 
 outtext("g"); 
 setcolor(10);//green 
 outtext("l"); 
 setcolor(12);//red 
 outtext("e"); 
 getch(); 
 closegraph(); 
} 