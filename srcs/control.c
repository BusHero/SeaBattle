#include "mboi.h"

void GotoXY( WORD X, WORD Y){
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
} 

void showCursor(BOOL visible){
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ccInfo;
    ccInfo.bVisible = visible;
    ccInfo.dwSize = 20;
    SetConsoleCursorInfo(hStdOut, &ccInfo);
}

color GetConsoleColor(BYTE col){
    color cl;
    for(BYTE i=-0;i<16;i++){
        if((col-i)%16==0){
            cl.background=i;
            break;
        }
    }
    for(BYTE i=0;i<16;i++){
        if(cl.background+16*i==col){
            cl.text=i;
        }
    }
    return cl;
}

void SetColor(BYTE text, BYTE background){
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void _cls(BYTE xi, BYTE yi, BYTE xf, BYTE yf, BYTE col){
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CHAR_INFO consBuffer[((xf-xi)+1)*((yf-yi)+1)];
    for (int i = 0; i<((xf-xi)+1)*((yf-yi)+1); ++i) {
        consBuffer[i].Char.UnicodeChar = ' ';
        consBuffer[i].Attributes = (WORD)((col << 4) | 15);
    }
    COORD charPosition={0,0};
    SMALL_RECT writeArea={xi,yi,xf,yf};
    COORD bufferSize = {(xf-xi)+1,(yf-yi)+1};
    WriteConsoleOutput(hStdOut, consBuffer, bufferSize,charPosition, &writeArea);
}

char *bfr(BYTE xi, BYTE yi, BYTE xf, BYTE yf){
    char *s=(char*)  malloc(((xf-xi)+1)*((yf-yi)+1)); 
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CHAR_INFO consBuffer[((xf-xi)+1)*((yf-yi)+1)];
    COORD charPosition={0,0};
    SMALL_RECT writeArea={xi,yi,xf,yf};
    COORD bufferSize = {(xf-xi)+1,(yf-yi)+1};
    ReadConsoleOutput(hStdOut,consBuffer,bufferSize,charPosition,&writeArea);
    for(int i=0; i<((xf-xi)+1)*((yf-yi)+1); i++)
    {
        s[i]=consBuffer[i].Char.UnicodeChar;
    }
    return s;
}