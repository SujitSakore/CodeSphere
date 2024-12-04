//Write a C program to draw a circle using Mid-Point algorithm. 
 
#include<stdio.h> 
#include<conio.h> 
#include<graphics.h> 
 
void drawCircle(int x0, int y0, int r) 
{ 
 int x, y, err; 
 x = r; 
 y = 0; 
 while(x >= y) 
 { 
  putpixel(x0+x, y0+y, WHITE); 
  putpixel(x0+x, y0-y, WHITE); 
  putpixel(x0-x, y0+y, WHITE); 
  putpixel(x0-x, y0-y, WHITE); 
  putpixel(x0+y, y0+x, WHITE); 
  putpixel(x0+y, y0-x, WHITE); 
  putpixel(x0-y, y0+x, WHITE); 
  putpixel(x0-y, y0-x, WHITE); 
  if(err <= 0) 
  { 
   y++; 
   err += 2*y + 1; 
  } 
  if(err > 0) 
  { 
   x--; 
   err -= 2*x + 1; 
  } 
 } 
} 
 
void main() 
{ 
 int gd = DETECT, gm, x, y, r; 
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
 printf("Enter the coordinate of the center: "); 
 scanf("%d%d",&x,&y); 
 printf("Enter the radius of the circle: "); 
 scanf("%d",&r); 
 drawCircle(x, y, r); 
 getch(); 
 closegraph(); 
}