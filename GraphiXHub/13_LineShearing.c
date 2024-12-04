// Write a C program to perform line shearing about x and y axis. 
 
#include<conio.h> 
#include<stdio.h> 
#include<graphics.h> 
 
void main() 
{ 
 int gd = DETECT, gm, x1, x2, y1, y2, shx, shy; 
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
 printf("Enter the endpoints of the line: "); 
 scanf("%d%d%d%d",&x1,&y1,&x2,&y2); 
 printf("Enter the shearin parameter along x-axis: "); 
 scanf("%d",&shx); 
 cleardevice(); 
 outtextxy(0,0,"WHITE = Before Shearing"); 
 line(x1, y1, x2, y2); 
 outtextxy(0, 15, "RED = After Shearing along x-axis"); 
 setcolor(RED); 
 line(x1 + shx*y1, y1, x2 + shx*y2, y2); 
 getch(); 
 cleardevice(); 
 printf("Enter the shearing factor along y-axis: "); 
 scanf("%d",&shy); 
 cleardevice(); 
 setcolor(WHITE); 
 outtextxy(0, 0, "WHITE = Before shearing"); 
 line(x1, y1, x2, y2); 
 outtextxy(0, 15, "RED = After shearing along y-axis"); 
 setcolor(RED); 
 line(x1, y1 + shy*x1, x2, y2 + shy*x2); 
 getch(); 
 closegraph(); 
}