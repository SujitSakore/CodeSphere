// Write a C program to perform line clipping using Cohen-Sutherland Algorithm. 
 
#include<conio.h> 
#include<stdio.h> 
#include<stdlib.h> 
#include<graphics.h> 
 
#define MAX 20 
 
enum 
{ 
 TOP = 0x1, BOTTOM = 0x2, RIGHT = 0x4, LEFT = 0x8 
}; 
 
enum 
{ 
 TRUE, FALSE 
}; 
 
typedef unsigned int outcode; 
 
outcode compute_outcode(int x, int y, int xmin, int ymin, int xmax, int ymax) 
{ 
 outcode oc = 0; 
 if(y > ymax) 
 oc |= TOP; 
 else if(y < ymin) 
 oc |= BOTTOM; 
 if(x > xmax) 
 oc |= RIGHT; 
 else if(x < xmin) 
 oc |= LEFT; 
 return oc; 
} 
 
void cohenSutherland(double x1, double y1, double x2, double y2, double xmin, double ymin, double xmax, double 
ymax) 
{ 
 int accept, done; 
 outcode oc1, oc2; 
 done = FALSE; 
 accept = FALSE; 
 oc1 = compute_outcode(x1, y1, xmin, ymin, xmax, ymax); 
 oc2 = compute_outcode(x2, y2, xmin, ymin, xmax, ymax); 
 do 
 { 
  if(oc1 == 0 && oc2 == 0) 
  { 
   accept = TRUE; 
   done = TRUE; 
  } 
  else if(oc1 & oc2) 
   done = TRUE; 
  else 
  { 
   double x, y; 
   int oc_ex = oc1?oc1:oc2; 
   if(oc_ex & TOP) 
   { 
    x = x1 + (x2-x1)*(ymax-y1)/(y2-y1); 
    y = ymax; 
   } 
   else if(oc_ex & BOTTOM) 
   { 
    x = x1 + (x2-x1)*(ymin-y1)/(y2-y1); 
    y = ymin; 
   } 
   else if(oc_ex & LEFT) 
   { 
    y = y1 + (y2-y1)*(xmin-x1)/(x2-x1); 
    x = xmin; 
   } 
   else 
   { 
    y = y1 + (y2-y1)*(xmax-x1)/(x2-x1); 
    x = xmax; 
   } 
   if(oc_ex == oc1) 
   { 
    x1 = x; 
    y1 = y; 
    oc1 = compute_outcode(x1, y1, xmin, ymin, xmax, ymax); 
   } 
   else 
   { 
    x2 = x; 
    y2 = y; 
    oc2 = compute_outcode(x2, y2, xmin, ymin, xmax, ymax); 
   } 
  } 
 }while(done==FALSE); 
 if(accept==TRUE) 
 line(x1,y1,x2,y2); 
} 
 
void main() 
{ 
 int n, i, j, ln[MAX][4], clip[4], gd=DETECT, gm; 
 printf("Enter the number of lines to be clipped: "); 
 scanf("%d",&n); 
 printf("enter the endpoints of the lines: "); 
 for(i = 0; i < n; i++) 
 { 
  printf("Line %d: ",(i+1)); 
  for(j = 0; j < 4; j++) 
  scanf("%d",&ln[i][j]); 
 } 
 printf("Enter the left top and right bottom coordinates of the clip window:"); 
 scanf("%d%d%d%d",&clip[0],&clip[1],&clip[2],&clip[3]); 
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
 printf("Original position of window and line(s): "); 
 rectangle(clip[0],clip[1],clip[2],clip[3]); 
 for(i = 0; i < n; i++) 
 line(ln[i][0],ln[i][1],ln[i][2],ln[i][3]); 
 getch(); 
 clrscr(); 
 cleardevice(); 
 printf("After clipping:"); 
 rectangle(clip[0], clip[1], clip[2], clip[3]); 
 for(i = 0; i < n; i++) 
 cohenSutherland(ln[i][0],ln[i][1],ln[i][2],ln[i][3],clip[0],clip[1],clip[2],clip[3]); 
 getch(); 
 closegraph(); 
}