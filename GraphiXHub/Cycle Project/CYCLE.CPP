#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int circle1x = 100, circle2x = 250;
    int poly_upline = 150, poly_lowerline = 100, poly_leftline = 100, poly_rightline = 225;
    int handle_1 = 250, handle_2 = 225, handle_3 = 200;
    int sheet_1 = 150, sheet_2 = 145;
    int speed = 5;
    int Cycle_Color = WHITE;

    char s[30] = "Loading...";

    // Loading Screen
    setcolor(WHITE);
    rectangle(200, 200, 400, 220);
    for (int i = 0; i < 200; i++) {
	setcolor(GREEN);
	line(201 + i, 201, 201 + i, 219);
	delay(10);
    }
    setcolor(WHITE);
    outtextxy(220, 230, s);
    delay(1000);

    while (1) {
	cleardevice();
	setcolor(WHITE);

	// Draw the ground line
	line(0, 400, 640, 400);
	line(0,401,641,401);

	// Draw Sun
	setcolor(YELLOW);
	circle(405, 80, 28);
	floodfill(405, 80, YELLOW);

	// Draw Hills
	setcolor(GREEN);
	line(0, 160, 100, 70);
	line(100, 70, 200, 160);
	line(200, 160, 300, 70);
	line(300, 70, 400, 160);
	line(400, 160, 500, 70);
	line(500, 70, 600, 160);
	line(600, 160, 700, 70);

	// Cycle tires
	setcolor(Cycle_Color);
	circle(circle1x, 350, 50);
	circle(circle2x, 350, 50);

	// Cycle frame
	line(poly_lowerline, 350, poly_lowerline + 75, 350);
	line(poly_leftline, 350, poly_leftline + 50, 290);
	line(poly_upline, 290, poly_upline + 75, 290);
	line(poly_rightline, 290, poly_rightline - 50, 350);

	// Cycle handle
	line(handle_1, 350, handle_1 - 25, 290);
	line(handle_2, 290, handle_2 - 25, 240);
	line(handle_3, 240, handle_3 - 20, 240);

	// Cycle seat
	line(sheet_1, 290, sheet_1, 280);
	line(sheet_2, 280, sheet_2 + 10, 280);

	// Draw Man
	setcolor(BROWN);

	// Head
	circle(handle_3 - 50, 230, 15);
	floodfill(handle_3 - 50, 230, BROWN);

	// Body
	line(handle_3 - 50, 245, handle_3 - 50, 280);

	// Arms
	line(handle_3 - 50, 250, handle_3 - 90, 230);
	line(handle_3 - 50, 250, handle_3 - 10, 230);

	// Legs
	line(handle_3 - 50, 279, handle_3 - 55, 300);
	line(handle_3 - 50, 279, handle_3 - 35, 295);

	// Check for keyboard input
	if (kbhit()) {
	    char ch = getch();
	    if (ch == 0) ch = getch();

	    // Move cycle left and right with arrow keys
	    if (ch == 75) { // Left arrow
		circle1x -= speed;
		circle2x -= speed;
		poly_upline -= speed;
		poly_lowerline -= speed;
		poly_leftline -= speed;
		poly_rightline -= speed;
		handle_1 -= speed;
		handle_2 -= speed;
		handle_3 -= speed;
		sheet_1 -= speed;
		sheet_2 -= speed;
	    }
	    else if (ch == 77) { // Right arrow
		circle1x += speed;
		circle2x += speed;
		poly_upline += speed;
		poly_lowerline += speed;
		poly_leftline += speed;
		poly_rightline += speed;
		handle_1 += speed;
		handle_2 += speed;
		handle_3 += speed;
		sheet_1 += speed;
		sheet_2 += speed;
	    }

	    // Change color with function keys F1 - F9
	    switch (ch) {
		case 59: Cycle_Color = WHITE; break;
		case 60: Cycle_Color = YELLOW; break;
		case 61: Cycle_Color = LIGHTMAGENTA; break;
		case 62: Cycle_Color = LIGHTCYAN; break;
		case 63: Cycle_Color = LIGHTBLUE; break;
		case 64: Cycle_Color = LIGHTGREEN; break;
		case 65: Cycle_Color = LIGHTRED; break;
		case 66: Cycle_Color = BLUE; break;
		case 67: Cycle_Color = RED; break;
	    }

	    // Exit the program with the ESC key
	    if (ch == 27) {
		break;
	    }
	}

	delay(50);
    }

    closegraph();
    return 0;
}