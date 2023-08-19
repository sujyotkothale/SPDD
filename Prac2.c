/*
// display different window combinations
// CreateWindow(window_name, window_text, window_style, x, y, width, height, parent, menu, hInstance, lparam);
#include<stdio.h>
#include<windows.h>
int _stdcall WinMain(HINSTANCE thisins,HINSTANCE previns,LPSTR lpstr,int cmdshow){
    HWND h[5];
    h[0] = CreateWindow("BUTTON","HSCROLL",WS_HSCROLL,0,0,300,300,0,0,thisins,0);
    ShowWindow(h[0],cmdshow);
    h[1] = CreateWindow("BUTTON","MINIMIZED Window",WS_OVERLAPPEDWINDOW|WS_MINIMIZEBOX,100,100,300,400,0,0,thisins,0);
    ShowWindow(h[1],cmdshow);
    h[2] = CreateWindow("BUTTON","VSCROLL",WS_VSCROLL,100,100,300,300,0,0,thisins,0);
    ShowWindow(h[2],cmdshow);
    h[3] = CreateWindow("BUTTON","MAXIMIZED WINDOW",WS_OVERLAPPEDWINDOW|WS_MAXIMIZEBOX,200,300,300,300,0,0,thisins,0);
    ShowWindow(h[3],cmdshow);
    h[4] = CreateWindow("BUTTON","SYSMENU",WS_SYSMENU,300,400,300,300,0,0,thisins,0);
    ShowWindow(h[4],cmdshow);
    MessageBox(0,"Press OK to Exit","BLOCKER",MB_OK);
}
*/

/*
// Write a program, which receives an integer as a command line argument, creates an edit window,
//and based on the value of the integer displays a button window as maximized/minimized / normal
#include<stdio.h>
#include<windows.h>
int _stdcall WinMain(HINSTANCE thisins,HINSTANCE previns,LPSTR lpstr,int cmdshow){
    HWND h;
    h = CreateWindow("BUTTON","HITME",WS_SYSMENU,0,0,300,400,0,0,thisins,0);
    int x = atoi(lpstr);
    switch(x){
        case 1:
            ShowWindow(h,SW_MAXIMIZE);
            break;
        case 2:
            ShowWindow(h,SW_MINIMIZE);
            break;
        case 3:
            ShowWindow(h,SW_NORMAL);
            break;
        default:
            ShowWindow(h,SW_SHOW);
    }
    char str[30];
    sprintf(str,"Input = %d",x);
    MessageBox(0,str,"BLOCKER",MB_OK);
}
*/

/*
//Write a program to create a simple window. Add the Menu bar, Menu item & Submenus to the
//created Window application and write a program to add some functionalities to the created menu items like save or open, etc.
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
WNDCLASS wc;
#define ID_FILE_NEW 1
#define ID_FILE_OPEN 2
#define ID_FILE_EXIT 3
void addMenu(HWND h);
long _stdcall myfunc(HWND w,UINT x,UINT y,long z){
    switch(x){
        case WM_DESTROY:
        PostQuitMessage(0);
        printf("Executed Successfully");
        break;

        case WM_CREATE:
        addMenu(w);
        break;

        case WM_COMMAND:
        switch(y){
            case ID_FILE_NEW:
            MessageBox(0,"New button clicked","File",MB_OK);
            break;

            case ID_FILE_OPEN:
            MessageBox(0,"Open button clicked","File",MB_OK);
            break;

            case ID_FILE_EXIT:
            MessageBox(0,"Exit button clicked","File",MB_OK);
            break;
        }
        default:
            return DefWindowProc(w,x,y,z);
    }
    return 0;
}
void addMenu(HWND h){
    HMENU hMenubar;
    HMENU hMenu,hMenu1;

    hMenubar = CreateMenu();
    hMenu = CreateMenu();

   // hMenubar1 = CreateMenu();
    hMenu1 = CreateMenu();
   HMENU hSubMenu = CreatePopupMenu();

    AppendMenuW(hMenu, MF_STRING | MF_POPUP, (UINT_PTR) hSubMenu, L"&New");
    AppendMenuW(hSubMenu, MF_STRING, ID_FILE_NEW, L"Empty &File");
    AppendMenuW(hSubMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuW(hSubMenu, MF_STRING, ID_FILE_NEW, L"Class..");
    AppendMenuW(hMenu, MF_STRING, ID_FILE_OPEN, L"&Open");

    AppendMenuW(hMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuW(hMenu, MF_STRING, ID_FILE_EXIT, L"&Quit");
    AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu, L"&File");
    AppendMenuW(hMenu1, MF_STRING, ID_FILE_EXIT, L"&Undo");
    AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu1, L"&Edit");
    SetMenu(h, hMenubar);
}
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpszCmdline, int nCmdShow){
    HINSTANCE hinst;
    HWND hwndMain;
    MSG msg;
    wc.lpfnWndProc = myfunc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "Main Class";
    wc.lpszMenuName = "First Menue";
    RegisterClass(&wc);
    hwndMain = CreateWindow("Main Class","Test- Sujyot",WS_OVERLAPPEDWINDOW,0,0,300,300,0,0,hInstance,0);
    ShowWindow(hwndMain,SW_NORMAL);
    while(GetMessage(&msg,0,0,0)){
        DispatchMessage(&msg);
    }
    return 0;
}
*/
