//Write a C program to perform line clipping using Liang-Barsky Algo. 
 
#include<graphics.h> 
#include<stdio.h> 
#include<conio.h> 
 
double max(double a, double b) { 
    return (a > b) ? a : b; 
} 
 
double min(double a, double b) { 
    return (a < b) ? a : b; 
} 
 
void main() 
{ 
 int i,dx,dy,gd=DETECT, gm, xwmin, ywmin, xwmax, ywmax, x1,x2,y1,y2; 
 int p[4], q[4]; 
 double t1,t2; 
 printf("Enter window:"); 
 scanf("%d%d%d%d",&xwmin,&ywmin,&xwmax,&ywmax); 
 printf("Enter endpoints:"); 
 scanf("%d%d%d%d",&x1,&y1,&x2,&y2); 
 clrscr(); 
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI"); 
 rectangle(xwmin,ywmin,xwmax,ywmax); 
 line(x1,y1,x2,y2); 
 getch(); 
 dx=x2-x1; 
 dy=y2-y1; 
 p[0]=-dx; 
 p[1]=dx; 
 p[2]=-dy; 
 p[3]=dy; 
 q[0]=x1-xwmin; 
 q[1]=xwmax-x1; 
 q[2]=y1-ywmin; 
 q[3]=ywmax-y1; 
 t1=0; 
 t2=1; 
 for(i=0;i<4;i++) 
 { 
  if(p[i]==0&&q[i]<0) 
  { 
   printf("Line iss completely outside"); 
   getch(); 
   closegraph(); 
   return; 
  } 
  if(p[i]<0) 
  t1=max(t1, q[i]/(p[i]*1.0)); 
  else if(p[i]>0) 
  t2=min(t2, q[i]/(p[i]*1.0)); 
 } 
 if(t1>t2) 
 { 
  printf("Line is outside."); 
  getch(); 
  closegraph(); 
  return; 
 } 
 x2=x1+(int)(t1*dx); 
 y2=y1+(int)(t1*dy); 
 x1=x1+(int)(t2*dx); 
 y1=y1+(int)(t2*dy); 
 setcolor(3); 
 line(x1,y1,x2,y2); 
 getch(); 
 closegraph(); 
}