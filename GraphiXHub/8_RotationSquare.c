// Write a C program to perform the rotation of a square with predefined vertex 
 
#include<conio.h> 
#include<stdio.h> 
#include<graphics.h> 
#include<math.h> 
 
double points[8]; 
 
void rotateRectangle(int cx, int cy, int w, int h, int angle) 
{ 
 int i; 
 double theta, dx, dy; 
 theta = (angle%180)*M_PI/180.0; 
 dx = w/2.0; 
 dy = h/2.0; 
 points[0] = -dx * cos(theta) - dy * sin(theta) + cx; 
 points[1] = -dx * sin(theta) + dy * cos(theta) + cy; 
 points[2] = dx * cos(theta) - dy * sin(theta) + cx; 
 points[3] = dx * sin(theta) + dy * cos(theta) + cy; 
 points[4] = dx * cos(theta) + dy * sin(theta) + cx; 
 points[5] = dx * sin(theta) - dy * cos(theta) + cy; 
 points[6] = -dx * cos(theta) + dy * sin(theta) + cx; 
 points[7] = -dx * sin(theta) - dy * cos(theta) + cy; 
 for(i=0;i<8;i+=2) 
  line(points[i], points[i+1], points[(i+2)%8], points[(i+3)%8]); 
} 
 
void main() 
{ 
 int gd = DETECT, gm, angle, x1, y1, x2, y2; 
 x1=250; 
 y1=250; 
 x2=300; 
 y2=300; 
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
 printf("Initial square:"); 
 rotateRectangle(x1, y1, x2, y2, 0); 
 getch(); 
 cleardevice(); 
 rotateRectangle(x1, y1, x2, y2, 0); 
 printf("Enter angle to rotate the square: "); 
 scanf("%d",&angle); 
 setcolor(YELLOW); 
 rotateRectangle(x1, y1, x2, y2, angle); 
 getch(); 
 closegraph(); 
}