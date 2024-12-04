 //Write a C program to print the word “TEXT” such that: 
  //T comes from left 
  //E comes from right 
  //X comes from top 
  //T comes from bottom 
 
#include<conio.h> 
#include<stdio.h> 
#include<graphics.h> 
 
void main() 
{ 
 int i, gd = DETECT, gm; 
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
 settextstyle(DEFAULT_FONT, 0, 2);//instead of 0, we can also use HORIZ_DIR 
 for(i = 0; i <= getmaxx()/2; i++) 
 { 
  outtextxy(i, getmaxy()/2, "T"); 
  delay(10); 
  cleardevice(); 
 } 
 for(i = getmaxx(); i >= getmaxx()/2 + 15; i--)//+15 to avoid overlap 
 { 
  outtextxy(getmaxx()/2, getmaxy()/2, "T"); 
  outtextxy(i, getmaxy()/2, "E"); 
  delay(10); 
  cleardevice(); 
 } 
 for(i = 0; i <= getmaxy()/2; i++) 
 { 
  outtextxy(getmaxx()/2, getmaxy()/2, "T"); 
  outtextxy(getmaxx()/2 + 15, getmaxy()/2, "E"); 
  outtextxy(getmaxx()/2 + 30, i, "X"); 
  delay(10); 
  cleardevice(); 
 } 
 for(i = getmaxy(); i >= getmaxy()/2; i--) 
 { 
  outtextxy(getmaxx()/2, getmaxy()/2, "T"); 
  outtextxy(getmaxx()/2 + 15, getmaxy()/2, "E"); 
  outtextxy(getmaxx()/2 + 30, getmaxy()/2, "X"); 
  outtextxy(getmaxx()/2 + 45, i, "T"); 
  delay(10); 
  cleardevice(); 
 } 
 outtextxy(getmaxx()/2, getmaxy()/2, "T"); 
 outtextxy(getmaxx()/2 + 15, getmaxy()/2, "E"); 
 outtextxy(getmaxx()/2 + 30, getmaxy()/2, "X"); 
 outtextxy(getmaxx()/2 + 45, getmaxy()/2, "T"); 
 getch(); 
 closegraph(); 
} 
 