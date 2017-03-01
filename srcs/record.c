#include "mboi.h"

void sort_players(char *s) {
	int step,i,j,k,n=0,var;
	FILE *pf;
	player p[2];
	pf=fopen(s,"r+");
	if(pf==NULL) return;
	for(step=n/2;step>0;step/=2)
		for(i=step;i<n;i++){
			fseek(pf,(i-step)*sizeof(p[0]),SEEK_SET);
			fread(&p[0],sizeof(p[0]),1,pf);
			fseek(pf,i*sizeof(p[1]),SEEK_SET);
			fread(&p[1],sizeof(p[1]),1,pf);
			for(k=i-step;k>=0&&p[0].punctaj<p[1].punctaj;k-=step){
				fseek(pf,k*sizeof(p[1]),SEEK_SET);
				fwrite(&p[1],sizeof(p[1]),1,pf);
				fseek(pf,(k+step)*sizeof(p[0]),SEEK_SET);
				fwrite(&p[0],sizeof(p[0]),1,pf);
				if((k-step)>=0){
					fseek(pf,(k-step)*sizeof(p[0]),SEEK_SET);
					fread(&p[0],sizeof(p[0]),1,pf);
					fseek(pf,k*sizeof(p[1]),SEEK_SET);
					fread(&p[1],sizeof(p[1]),1,pf);
				}
			}
		}
	fclose(pf);
}

void read_player(){
	FILE *pf;
	player p;
	int i;
	_cls(0,1,200,70,0);
	GotoXY(20,12);SetColor(15,0);
	printf("Dati dimensiunea cimpului:");
	char s[15],dim[10];
	gets(dim);strcat(dim,".dat\0");strcpy(s,"txt/recorduri\0");strcat(s,dim);
	_cls(0,1,200,70,0);
	pf=fopen(s,"r");
	if(pf==NULL){
		puts(" Nu exista inregistrari pentru astfel de dimensiuni ale cimpului!");
		_getch(); 
		return;
	}
	printf("\n\n\t\t\t\t\t\t\t    Persoanele care au obtinut cel mai inalt punctaj sunt:\n");
	printf("\n\t\t\t\t\t\t\t%c",201);
	for(i=0;i<22;i++) printf("%c",205); printf("%c",203); 
	for(i=0;i<9;i++) printf("%c",205); printf("%c\n",187);
	
	printf("\t\t\t\t\t\t\t%c         Nume         %c Punctaj %c\n\t\t\t\t\t\t\t%c",186,186,186,204);
    for(i=0;i<22;i++) printf("%c",205); printf("%c",206); 
    for(i=0;i<9;i++) printf("%c",205); printf("%c",185);
	
    fread(&p,sizeof(player),1,pf);
	while(!feof(pf)){
	    printf("\n\t\t\t\t\t\t\t%c %-20s %c %-7d ",186,p.NP,186,p.punctaj);
	    CONSOLE_SCREEN_BUFFER_INFO coninfo;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hConsole, &coninfo);
		coninfo.dwCursorPosition.Y -= 1;    // move up one line
		coninfo.dwCursorPosition.X += 115;  // move to the right the length of the word
		SetConsoleCursorPosition(hConsole, coninfo.dwCursorPosition);
		printf("%c\n\t\t\t\t\t\t\t%c",186,204);
		for(i=0;i<22;i++) printf("%c",205); printf("%c",206); 
		for(i=0;i<9;i++) printf("%c",205);printf("%c",185);
		fread(&p,sizeof(player),1,pf);
	}
	printf("\b%c",188);
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &coninfo);
	coninfo.dwCursorPosition.X -= 11;
	SetConsoleCursorPosition(hConsole, coninfo.dwCursorPosition);
	printf("%c",202);
	coninfo.dwCursorPosition.X -= 23;
	SetConsoleCursorPosition(hConsole, coninfo.dwCursorPosition);
	printf("%c",200);
	fclose(pf);
	_getch();
}

void write_player(BYTE pt, BYTE dim){
	_cls(0,1,200,70,0);
	BYTE alg,prm=0;
	item opt[3];
	opt[0].cor.X=55; opt[0].cor.Y=13; opt[0].s=(char*)malloc(4); opt[0].s="DA\0";
	opt[1].cor.X=60; opt[1].cor.Y=13; opt[1].s=(char*)malloc(4); opt[1].s="NU\0";
	opt[2].cor.X=45; opt[2].cor.Y=11; opt[2].s=(char*)malloc(35);opt[2].s="Doriti inregistarea recorduilor?\0";
	SetColor(inactive.text,inactive.background);
	for(int i=0;i<2;i++){
		GotoXY(opt[i].cor.X,opt[i].cor.Y);printf(opt[i].s);
	}
	SetColor(15,0); GotoXY(opt[2].cor.X,opt[2].cor.Y);printf(opt[2].s);SetColor(active.text,active.background);
	GotoXY(opt[prm].cor.X,opt[prm].cor.Y);printf(opt[prm].s);
	do{
		alg=_getch();
		switch(alg){
			case 13:
				switch(prm){
					case 0:
						_cls(45,11,200,70,0);SetColor(15,0);showCursor(1);
						char *s=(char*)malloc(20);
						BYTE k=0;
						FILE *pf;
						player p;
						sprintf(s,"%s%d%s","txt/recorduri",dim,".dat");
						pf=fopen(s,"a");
						fflush(stdin);
						printf("\n\n\n\tIntroduceti numele d-voastra:");
						gets(p.NP);
						p.punctaj=pt;
						fwrite(&p,sizeof(player),1,pf);
						fclose(pf);
						sort_players(s);
						showCursor(0);
						break;
					case 1:
						return;
				}
				return;
			case 27:
				return;
			case 77://dreapta
				if(prm!=1){
					GotoXY(opt[prm].cor.X,opt[prm].cor.Y);SetColor(inactive.text,inactive.background);printf(opt[prm].s);
					prm++;
					GotoXY(opt[prm].cor.X,opt[prm].cor.Y);SetColor(active.text,active.background);printf(opt[prm].s);
				}
				break;
			case 75://stinga
				if(prm!=0){
					GotoXY(opt[prm].cor.X,opt[prm].cor.Y);SetColor(inactive.text,inactive.background);printf(opt[prm].s);
					prm--;
					GotoXY(opt[prm].cor.X,opt[prm].cor.Y);SetColor(active.text,active.background);printf(opt[prm].s);
				}
				break;	
		}
	}while(1);
}