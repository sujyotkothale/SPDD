#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main(void)
{
    int choice = 1;
    int x, y; 
    union REGS regs;
    int row, col;
    clrscr();
        printf("\nEnter 1 for Setting cursor size :");
        printf("\nEnter 2 to Scroll the window down :");
        printf("\nEnter 3 for Positioning the cursor :");
        printf("\nEnter 4 for Reading the cursor position :");
        printf("\nEnter 0 to exit :");

        scanf("%d", &choice);

        // Switch on the user's choice
        switch (choice)
        {
        case 1:
            // Set the cursor size
            printf("  Enter the starting line of the cursor(0-4) : ");
            scanf("%d", &x);
            printf("  Enter the ending line of the cursor : ");
            scanf("%d", &y);
            regs.h.ah = 1;
            regs.h.ch = x;
            regs.h.cl = y;
            int86(0x10, &regs, &regs);
            break;
        case 2:
            // Scroll the window down
            printf("  Enter the no of lines : ");
            scanf("%d", &x);
            regs.h.ah = 07;
            regs.h.al = x;
            regs.h.bh = 8;
            regs.h.ch = 0;
            regs.h.cl = 0;
            regs.h.dh = 50;
            regs.h.dl = 50;
            int86(0x10, &regs, &regs);
            break;
        case 3:
            // Position the cursor
            printf("Enter the row and column: ");
            scanf("%d %d", &row, &col);
            regs.h.ah = 02;
            regs.h.bh = 00;
            regs.h.dh = row;
            regs.h.dl = col;
            int86(0x10, &regs, &regs);
            break;
        case 4:
            // Read the cursor position
            regs.h.ah = 03;
            regs.h.bh = 00;
            int86(0x10, &regs, &regs);
            printf("The cursor position is (%d, %d)\n", regs.h.dh, regs.h.dl);
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
