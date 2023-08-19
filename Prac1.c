/*
print hello
#include<stdio.h>
#include<windows.h>
int _stdcall WinMain(HINSTANCE thisinstance, HINSTANCE previnstance,LPSTR lpstr,int cmdshow){
    char str[100];
    sprintf(str,"Hello %d",10);
    MessageBox(0,str,"TITLE",0);
}
*/

/*
print factorial
#include<stdio.h>
#include<windows.h>
int _stdcall WinMain(HINSTANCE thisins,HINSTANCE previns,LPSTR lpstr,int cmdshow){
    char str[100];
    int x = atoi(lpstr);
    int f=1;
    for(int i=1;i<=x;i++){
        f=f*i;
    }
    sprintf(str,"Factorial : %d",f);
    MessageBox(0,str,"Factorial",0);
}
*/

/*
#include<stdio.h>
#include<windows.h>
int _stdcall WinMain(HINSTANCE currins,HINSTANCE previns,LPSTR lpstr,int cmdshow){
    char str[100];
    sprintf(str,"%s",lpstr);
    int count = 0;
    for(int x=0;str[x]!='\0';x++){
        if(str[x] == ' '){
            count++;
        }
    }
    sprintf(str,"Number of words = %d",count+1);
    MessageBox(0,str,"Count",0);
}
*/
