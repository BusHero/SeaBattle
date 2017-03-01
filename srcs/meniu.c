#include "mboi.h"

int main(){
	srand(time(NULL));
	HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    keybd_event(VK_MENU,0x38,0,0); //press ALT
	keybd_event(VK_RETURN,0x1c,0,0); //press ENTER
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0); //release ENTER
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0); //release ALT
	SetColor(15,0);system("cls");

	cimp_efc *cp=(cimp_efc*)malloc(sizeof(cimp_efc));
	cp->col1.text=0;  cp->col1.background=0;
	cp->col2.text=15; cp->col2.background=15;
	cp->col3.text=3;  cp->col3.background=3;
	cp->col4.text=4;  cp->col4.background=4;
	cp->col5.text=5;  cp->col5.background=5;
	cp->col6.text=6;  cp->col6.background=6;
	cp->rama=1;
	active.text=15;active.background=1;
	inactive.text=1;inactive.background=8;
	car_patr patr1;
	patr1.dim=10;patr1.m_patr=2;patr1.nr_cor=10;
	patr1.cor=(car_cor*)malloc(4*sizeof(car_cor));
	patr1.cor[0].nr_patr=1;patr1.cor[0].nr_cor=4;
	patr1.cor[1].nr_patr=2;patr1.cor[1].nr_cor=3;
	patr1.cor[2].nr_patr=3;patr1.cor[2].nr_cor=2;
	patr1.cor[3].nr_patr=4;patr1.cor[3].nr_cor=1;
	showCursor(0);
	item optM[5];
	optM[0].cor.X=0;  optM[0].cor.Y=0; optM[0].s=(char*)malloc(15); optM[0].s="          start\0";
	optM[1].cor.X=15; optM[1].cor.Y=0; optM[1].s=(char*)malloc(15); optM[1].s="         setari\0";
	optM[2].cor.X=30; optM[2].cor.Y=0; optM[2].s=(char*)malloc(15); optM[2].s="      recorduri\0";
	optM[3].cor.X=45; optM[3].cor.Y=0; optM[3].s=(char*)malloc(15); optM[3].s="       regulile\0";
	optM[4].cor.X=60; optM[4].cor.Y=0; optM[4].s=(char*)malloc(15); optM[4].s="         iesire\0";
	item optS[3];
	optS[0].cor.X=15; optS[0].cor.Y=1; optS[0].s=(char*)malloc(15); optS[0].s="     item meniu\0";
	optS[1].cor.X=15; optS[1].cor.Y=2; optS[1].s=(char*)malloc(15); optS[1].s="           cimp\0";
	optS[2].cor.X=15; optS[2].cor.Y=3; optS[2].s=(char*)malloc(15); optS[2].s="    culori cimp\0";
	SetColor(inactive.text,inactive.background);
	for(int i=0;i<5;i++){
		GotoXY(optM[i].cor.X,optM[i].cor.Y);printf(optM[i].s);
	}
	SetColor(active.text,active.background);
	GotoXY(optM[0].cor.X,optM[0].cor.Y);printf(optM[0].s);
	char alg;
	int x; BYTE prm=0;
	do{
		alg=_getch();
		switch(alg){	
			case 13:
				switch(prm){
					case 0:
						GotoXY(optM[prm].cor.X,optM[prm].cor.Y);SetColor(inactive.text,inactive.background);printf(optM[prm].s);
						game(patr1,*cp);
						_cls(0,1,200,40,0);
						GotoXY(optM[prm].cor.X,optM[prm].cor.Y);SetColor(active.text,active.background);printf(optM[prm].s);
						break;
					case 1:
						GotoXY(optM[prm].cor.X,optM[prm].cor.Y);SetColor(inactive.text,inactive.background);printf(optM[prm].s);
						SetColor(inactive.text,inactive.background);
						for(int i=0;i<5;i++){
							GotoXY(optS[i].cor.X,optS[i].cor.Y);printf(optS[i].s);
						}
						SetColor(active.text,active.background);
						GotoXY(optS[0].cor.X,optS[0].cor.Y);printf(optS[0].s);
						prm=0;
						do{
							alg=_getch();
							switch(alg){
								case 13:
									switch(prm){
										case 0:
											_cls(0,1,30,40,0);
											set_item_menu();
											_cls(0,1,0,40,0);
											SetColor(inactive.text,inactive.background);
											for(int i=0;i<5;i++){
												GotoXY(optM[i].cor.X,optM[i].cor.Y);printf(optM[i].s);
											}
											break;
										case 1:
											_cls(0,1,30,40,0);
											set_cimp_menu(&patr1,cp->col1,cp->col2,cp->col3,cp->rama);
											break;
										case 2:
											_cls(0,1,30,40,0);
											set_intr_cimp_menu(cp);
											break;
									}
								case 27:
									goto et1;
								case 72://sus
									if(prm!=0){
										GotoXY(optS[prm].cor.X,optS[prm].cor.Y);SetColor(inactive.text,inactive.background);printf(optS[prm].s);
										prm--;
										GotoXY(optS[prm].cor.X,optS[prm].cor.Y);SetColor(active.text,active.background);printf(optS[prm].s);
									}
									break;
								case 80://jos
									if(prm!=2){
										GotoXY(optS[prm].cor.X,optS[prm].cor.Y);SetColor(inactive.text,inactive.background);printf(optS[prm].s);
										prm++;
										GotoXY(optS[prm].cor.X,optS[prm].cor.Y);SetColor(active.text,active.background);printf(optS[prm].s);
									}
									break;
							}
						}while(1);
						et1:
						prm=1;
						_cls(0,1,200,40,0);
						GotoXY(optM[prm].cor.X,optM[prm].cor.Y);SetColor(active.text,active.background);printf(optM[prm].s);
						break;
					case 2:
						GotoXY(optM[prm].cor.X,optM[prm].cor.Y);SetColor(inactive.text,inactive.background);printf(optM[prm].s);
						read_player();
						_cls(0,1,200,40,0);
						GotoXY(optM[prm].cor.X,optM[prm].cor.Y);SetColor(active.text,active.background);printf(optM[prm].s);
						break;
					case 3:
						GotoXY(optM[prm].cor.X,optM[prm].cor.Y);SetColor(inactive.text,inactive.background);printf(optM[prm].s);
						reguli(*cp);
						_cls(0,1,200,40,0);
						GotoXY(optM[prm].cor.X,optM[prm].cor.Y);SetColor(active.text,active.background);printf(optM[prm].s);
						break;
					case 4:
						return 1;
				}
				break;
			case 27:
				SetStdHandle(STD_OUTPUT_HANDLE,hStdOut);
				free(cp);free(patr1.cor);
				return 1;
			case 77://dreapta
				if(prm!=4){
					GotoXY(optM[prm].cor.X,optM[prm].cor.Y);SetColor(inactive.text,inactive.background);printf(optM[prm].s);
					prm++;
					GotoXY(optM[prm].cor.X,optM[prm].cor.Y);SetColor(active.text,active.background);printf(optM[prm].s);
				}
				break;
			case 75://stinga
				if(prm!=0){
					GotoXY(optM[prm].cor.X,optM[prm].cor.Y);SetColor(inactive.text,inactive.background);printf(optM[prm].s);
					prm--;
					GotoXY(optM[prm].cor.X,optM[prm].cor.Y);SetColor(active.text,active.background);printf(optM[prm].s);
				}
				break;
		}
	}while(1);
}