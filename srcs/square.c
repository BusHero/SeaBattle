#include "mboi.h"

void col_cel(BYTE X, BYTE Y, BYTE m_patr, BYTE col){
    SetColor(15,col);
    for(BYTE j=0;j<m_patr;j++){
        GotoXY(X,Y+j);
        for(BYTE q=0;q<m_patr*2;q++)printf(" ");
    }
}

void intr_cord(int xi, int yi, int n, int m, BYTE m_patr){
    for(BYTE i=1;i<=m;i++){
        GotoXY(xi+2*m_patr*i,yi);printf("%c",64+i);
    }
    yi++;
    for(BYTE i=1;i<=n;i++){
        GotoXY(xi-1,yi+m_patr*i);printf("%2d",i);
    }   
}

void rama(int xi, int yi, int n, int m, BYTE prm){
    SetColor(15,0);
    switch(prm){
        case 1://rama simpla
            GotoXY(xi,yi+0);printf("\xda");for(BYTE i=1;i<m;i++)printf("\xc4");printf("\xbf");
            for(BYTE i=1;i<n;i++){
                GotoXY(xi,yi+i);printf("\xb3"); for(BYTE j=1;j<m;j++)printf(" ");printf("\xb3");
            }
            GotoXY(xi,yi+n);printf("\xc0");for(BYTE i=1;i<m;i++)printf("\xc4");printf("\xd9");
            break;
        case 2://linii orizontale duble
            GotoXY(xi,yi+0);printf("\xd5");for(BYTE i=1;i<m;i++)printf("\xcd");printf("\xb8");
            for(BYTE i=1;i<n;i++){
                GotoXY(xi,yi+i);printf("\xb3"); for(BYTE j=1;j<m;j++)printf(" ");printf("\xb3");
            }
            GotoXY(xi,yi+n);printf("\xd4");for(BYTE i=1;i<m;i++)printf("\xcd");printf("\xbe");
            break;
        case 3://linii verticale duble
            GotoXY(xi,yi+0);printf("\xd6");for(BYTE i=1;i<m;i++)printf("\xc4");printf("\xb7");
            for(BYTE i=1;i<n;i++){
                GotoXY(xi,yi+i);printf("\xba"); for(BYTE j=1;j<m;j++)printf(" ");printf("\xba");
            }
            GotoXY(xi,yi+n);printf("\xd3");for(BYTE i=1;i<m;i++)printf("\xc4");printf("\xbd");
            break;
        case 4://rama dubla
            GotoXY(xi,yi+0);printf("\xc9");for(BYTE i=1;i<m;i++)printf("\xcd");printf("\xbb");
            for(BYTE i=1;i<n;i++){
                GotoXY(xi,yi+i);printf("\xba"); for(BYTE j=1;j<m;j++)printf(" ");printf("\xba");
            }
            GotoXY(xi,yi+n);printf("\xc8");for(BYTE i=1;i<m;i++)printf("\xcd");printf("\xbc");
            break;
    }
}

void col_init(int xi, int yi, int n, int m, BYTE col1, BYTE col2,BYTE m_patr){
    BYTE i,j,x,y;
    for (i=0,x=xi;i<n;i++,x+=2*m_patr){
        for (j=0,y=yi;j<m;j++,y+=m_patr){
            if((j+i)%2!=0) col_cel(x,y,m_patr,col2);
            else           col_cel(x,y,m_patr,col1);
        }
    }
    SetColor(15,0);
}

void init_cimp(int xi, int yi, int dim, BYTE col1, BYTE col2, BYTE m_patr, BYTE ptr){
    SetColor(15,0);
    intr_cord(xi,yi,dim,dim,m_patr);
    rama(xi+1,yi+1,m_patr*dim+1,2*m_patr*dim+1,ptr);
    col_init(xi+2,yi+2,dim,dim,col1,col2,m_patr);
    SetColor(15,0);
}