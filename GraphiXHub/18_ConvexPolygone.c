Write a C program to draw a convex polygon. 
 
 
 
 
#include<conio.h> 
#include<stdio.h> 
#include<graphics.h> 
#include<math.h> 
 
#define v 4 
 
void dda(int x0, int y0, int x1, int y1) 
{ 
 int i,dx,dy,steps; 
 float x,y,xinc,yinc; 
 dx=x1-x0; 
 dy=y1-y0; 
 steps=(abs(dx)>abs(dy))?abs(dx):abs(dy); 
 xinc=dx/(steps*1.0); 
 yinc=dy/(steps*1.0); 
 x=x0; 
 y=y0; 
 for(i=0;i<=steps;i++) 
 { 
  putpixel(x,y,WHITE); 
  x+=xinc; 
  y+=yinc; 
 } 
} 
 
void main() 
{ 
 int p[v][2], gd=DETECT, gm, i; 
 /* 
 printf("Enter the points:"); 
 for(i=0;i<v;i++) 
 scanf("%d%d",&p[i][0], &p[i][1]); 
 */ 
 p[0][0]=100; 
 p[0][1]=100; 
 p[1][0]=170; 
 p[1][1]=100; 
 p[2][0]=200; 
 p[2][1]=200; 
 p[3][0]=70; 
 p[3][1]=200; 
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI"); 
 for(i=0;i<v;i++) 
 line(p[i][0],p[i][1],p[(i+1)%v][0], p[(i+1)%v][1]); 
 getch(); 
 closegraph(); 
}