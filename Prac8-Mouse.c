#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
void main(void)
{
    int choice = 1;
    int ex;
    int x, y;
    union REGS regs;
    int  MouseBtn;
    int gd = DETECT, gm;
    clrscr();
    printf("\nEnter 1 Check if mouse support is available or not :");
    printf("\nEnter 2 Display mouse pointer in graphics mode :");
    printf("\nEnter 3 Determine which mouse button is clicked :");
    printf("\nEnter 4 Current position of mouse pointer :");
    printf("\nEnter 0 to exit :");

    scanf("%d", &choice);

    // Switch on the user's choice
    switch (choice)
    {
    case 1:
    // Check if mouse support is available or not
        regs.x.ax = 00;
        int86(0x33, &regs, &regs);
        if (regs.x.ax == 0){
            printf("Mouse support not available.\n");
        }
        else{
            // Mouse support is available.
            printf("Mouse support available.\n");
        }
        break;
    case 2:
    // Display mouse pointer in graphics mode
        regs.x.ax = 00;
        int86(0x33, &regs, &regs);
        initgraph(&gd, &gm, "c://turboc3//bgi");
        printf("Displaying pointer :");
        regs.x.ax = 01;
        int86(0x33, &regs, &regs);
        scanf("%d", ex);
        regs.x.ax = 3;
        int86(0x33, &regs, &regs);

        break;
    case 3:
    // Determine which button is clicked
        regs.x.ax = 00;
        int86(0x33, &regs, &regs);
        initgraph(&gd, &gm, "c://turboc3//bgi");
        regs.x.ax = 01;
        int86(0x33, &regs, &regs);
        scanf("%d", ex);
        regs.x.ax = 3;
        int86(0x33, &regs, &regs);
        MouseBtn = regs.x.bx;
        clrscr();
        printf("Button Pressed : %d", MouseBtn);
        switch (MouseBtn)
        {
        case 0:
            printf("(Button not pressed)");
            break;
        case 1:
            printf("(Left button pressed)");
            break;
        case 2:
            printf("(Right button pressed)");
            break;
        case 4:
            printf("(Middle button pressed)");
            break;
        }

        break;
    case 4:
    // Print current Position of cursor
        regs.x.ax = 00;
        int86(0x33, &regs, &regs);
        initgraph(&gd, &gm, "c://turboc3//bgi");
        regs.x.ax = 01;
        int86(0x33, &regs, &regs);
        regs.x.ax = 3;
        int86(0x33, &regs, &regs);
        printf("The cursor position is (%d, %d)\n", regs.x.cx, regs.x.dx);
        break;
    case 5:
        // Exit
        break;
    default:
        printf("Invalid choice\n");
        break;
    }

    getch();
}
