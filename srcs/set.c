#include "mboi.h"

void set_item_menu(){
	color p_a=active;
	color p_i=inactive;
	showCursor(0);
	item car_cimp[4];
	car_cimp[0].cor.X=5;  car_cimp[0].cor.Y=7;  car_cimp[0].s=(char*)malloc(25); car_cimp[0].s="       set text color\0"; 
	car_cimp[1].cor.X=5;  car_cimp[1].cor.Y=9;  car_cimp[1].s=(char*)malloc(25); car_cimp[1].s=" set background color\0"; 
	car_cimp[2].cor.X=50; car_cimp[2].cor.Y=7;  car_cimp[2].s=(char*)malloc(25); car_cimp[2].s="       set text color\0"; 
	car_cimp[3].cor.X=50; car_cimp[3].cor.Y=9;  car_cimp[3].s=(char*)malloc(25); car_cimp[3].s=" set background color\0"; 
	SetColor(15,0);
	GotoXY(car_cimp[0].cor.X-5,car_cimp[0].cor.Y-2);printf("set active item menu color:");
	GotoXY(car_cimp[2].cor.X-7,car_cimp[2].cor.Y-2);printf("set inactive item menu color:");
	SetColor(15,0); GotoXY(car_cimp[0].cor.X,car_cimp[0].cor.Y); printf(car_cimp[0].s); puts(":"); GotoXY(car_cimp[0].cor.X+27,car_cimp[0].cor.Y); SetColor(0,active.text);   	   printf("  "); 
	SetColor(15,0); GotoXY(car_cimp[1].cor.X,car_cimp[1].cor.Y); printf(car_cimp[1].s); puts(":"); GotoXY(car_cimp[1].cor.X+27,car_cimp[1].cor.Y); SetColor(0,active.background);   printf("  "); 
	SetColor(15,0); GotoXY(car_cimp[2].cor.X,car_cimp[2].cor.Y); printf(car_cimp[2].s); puts(":"); GotoXY(car_cimp[2].cor.X+27,car_cimp[2].cor.Y); SetColor(0,inactive.text); 	   printf("  "); 
	SetColor(15,0); GotoXY(car_cimp[3].cor.X,car_cimp[3].cor.Y); printf(car_cimp[3].s); puts(":"); GotoXY(car_cimp[3].cor.X+27,car_cimp[3].cor.Y); SetColor(0,inactive.background); printf("  "); 
	GotoXY(car_cimp[1].cor.X+5,car_cimp[1].cor.Y+2);SetColor(active.text,active.background);	printf("exemple");
	GotoXY(car_cimp[3].cor.X+5,car_cimp[3].cor.Y+2);SetColor(inactive.text,inactive.background);printf("exemple");
	SetColor(0,15);GotoXY(car_cimp[0].cor.X+24,car_cimp[0].cor.Y);printf(" ");
	BYTE alg,prm=0;
	do{
		alg=_getch();
		switch(alg){
			case 13:
				return;
			case 27: 
				active=p_a;
				SetColor(15,active.text);
				SetColor(15,active.background);
				inactive=p_i;
				SetColor(15,inactive.text);
				SetColor(15,inactive.background);
				return;
			case 72:
				if(prm!=0){
					SetColor(15,0);GotoXY(car_cimp[prm].cor.X+24,car_cimp[prm].cor.Y);printf(" ");
					prm--;
					SetColor(0,15);GotoXY(car_cimp[prm].cor.X+24,car_cimp[prm].cor.Y);printf(" ");
				} 
				break;
			case 80:
				if(prm!=3){
					SetColor(15,0);GotoXY(car_cimp[prm].cor.X+24,car_cimp[prm].cor.Y);printf(" ");
					prm++;
					SetColor(0,15);GotoXY(car_cimp[prm].cor.X+24,car_cimp[prm].cor.Y);printf(" ");
				} 
				break;
			case 77:
				switch(prm){
					case 0:
						if(active.text!=15){
							active.text++;
							GotoXY(car_cimp[prm].cor.X+27,car_cimp[prm].cor.Y);SetColor(15,active.text);printf("  ");
							GotoXY(car_cimp[1].cor.X+5,car_cimp[1].cor.Y+2);SetColor(active.text,active.background);	printf("exemple");
						}
						break;
					case 1:
						if(active.background!=15){
							active.background++;
							GotoXY(car_cimp[prm].cor.X+27,car_cimp[prm].cor.Y);SetColor(15,active.background);printf("  ");
							GotoXY(car_cimp[1].cor.X+5,car_cimp[1].cor.Y+2);SetColor(active.text,active.background);	printf("exemple");
						}
						break;
					case 2:
						if(inactive.text!=15){
							inactive.text++;
							GotoXY(car_cimp[prm].cor.X+27,car_cimp[prm].cor.Y);SetColor(15,inactive.text);printf("  ");
							GotoXY(car_cimp[3].cor.X+5,car_cimp[3].cor.Y+2);SetColor(inactive.text,inactive.background);printf("exemple");
						}
						break;
					case 3:
						if(inactive.background!=15){
							inactive.background++;
							GotoXY(car_cimp[prm].cor.X+27,car_cimp[prm].cor.Y);SetColor(15,inactive.background);printf("  ");
							GotoXY(car_cimp[3].cor.X+5,car_cimp[3].cor.Y+2);SetColor(inactive.text,inactive.background);printf("exemple");
						}
						break;
				}
				break;
			case 75:
				switch(prm){
					case 0:
						if(active.text!=0){
							active.text--;
							GotoXY(car_cimp[prm].cor.X+27,car_cimp[prm].cor.Y);SetColor(15,active.text);printf("  ");		
							GotoXY(car_cimp[1].cor.X+5,car_cimp[1].cor.Y+2);SetColor(active.text,active.background);	printf("exemple");
						}
						break;
					case 1:
						if(active.background!=0){
							active.background--;
							GotoXY(car_cimp[prm].cor.X+27,car_cimp[prm].cor.Y);SetColor(15,active.background);printf("  ");	
							GotoXY(car_cimp[1].cor.X+5,car_cimp[1].cor.Y+2);SetColor(active.text,active.background);	printf("exemple");
						}
						break;
					case 2:
						if(inactive.text!=0){
							inactive.text--;
							GotoXY(car_cimp[prm].cor.X+27,car_cimp[prm].cor.Y);SetColor(15,inactive.text);printf("  ");
							GotoXY(car_cimp[3].cor.X+5,car_cimp[3].cor.Y+2);SetColor(inactive.text,inactive.background);printf("exemple");
						}
						break;
					case 3:
						if(inactive.background!=0){
							inactive.background--;
							GotoXY(car_cimp[prm].cor.X+27,car_cimp[prm].cor.Y);SetColor(15,inactive.background);printf("  ");
							GotoXY(car_cimp[3].cor.X+5,car_cimp[3].cor.Y+2);SetColor(inactive.text,inactive.background);printf("exemple");
						}
						break;
				} 
				break;
		}
	}while(1);
}

void set_cimp_menu(car_patr *patr, color col1, color col2, color col3, BYTE rama){
	car_patr patr1=*patr;
	item car_cimp[3];
	car_cimp[0].cor.X=0;car_cimp[0].cor.Y=3;car_cimp[0].s=(char*)malloc(25); car_cimp[0].s="          dimensiunea\0"; 
	car_cimp[1].cor.X=0;car_cimp[1].cor.Y=5;car_cimp[1].s=(char*)malloc(25); car_cimp[1].s=" marimea patratelului\0";
	car_cimp[2].cor.X=0;car_cimp[2].cor.Y=7;car_cimp[2].s=(char*)malloc(25); car_cimp[2].s="        Nr de corabii\0";
	SetColor(15,0); GotoXY(car_cimp[0].cor.X,car_cimp[0].cor.Y); printf(car_cimp[0].s); puts(":"); GotoXY(car_cimp[0].cor.X+25,car_cimp[0].cor.Y); printf("%3d",patr->dim); 
	SetColor(15,0); GotoXY(car_cimp[1].cor.X,car_cimp[1].cor.Y); printf(car_cimp[1].s); puts(":"); GotoXY(car_cimp[1].cor.X+25,car_cimp[1].cor.Y); printf("%3d",patr->m_patr);
	SetColor(15,0); GotoXY(car_cimp[2].cor.X,car_cimp[2].cor.Y); printf(car_cimp[2].s); puts(":"); GotoXY(car_cimp[2].cor.X+25,car_cimp[2].cor.Y); printf("%3d",patr->nr_cor); 
	item *car_cor=(item*)malloc(sizeof(item)*_msize(patr->cor)/sizeof(patr->cor[0]));
	for(int i=0;i<_msize(patr->cor)/sizeof(patr->cor[0]);i++){
		car_cor[i].cor.X=85; car_cor[i].cor.Y=5+2*i;  
	}
	SetColor(15,0); GotoXY(85,3); printf("n_c");GotoXY(91,3); printf("n_p");
	SetColor(15,0); 
	GotoXY(car_cor[0].cor.X,car_cor[0].cor.Y); printf("%3d",patr1.cor[0].nr_cor);
	GotoXY(car_cor[0].cor.X+6,car_cor[0].cor.Y); printf("%2d",patr1.cor[0].nr_patr);  
	GotoXY(car_cor[0].cor.X+12,car_cor[0].cor.Y);SetColor(col3.text,col3.background);for(int i=0;i<patr1.cor[0].nr_patr;i++) printf("  ");
	SetColor(15,0); 
	GotoXY(car_cor[1].cor.X,car_cor[1].cor.Y); printf("%3d",patr1.cor[1].nr_cor);
	GotoXY(car_cor[1].cor.X+6,car_cor[1].cor.Y); printf("%2d",patr1.cor[1].nr_patr);  
	GotoXY(car_cor[1].cor.X+12,car_cor[1].cor.Y);SetColor(col3.text,col3.background);for(int i=0;i<patr1.cor[1].nr_patr;i++) printf("  ");
	SetColor(15,0); 
	GotoXY(car_cor[2].cor.X,car_cor[2].cor.Y); printf("%3d",patr1.cor[2].nr_cor);
	GotoXY(car_cor[2].cor.X+6,car_cor[2].cor.Y); printf("%2d",patr1.cor[2].nr_patr);  
	GotoXY(car_cor[2].cor.X+12,car_cor[2].cor.Y);SetColor(col3.text,col3.background);for(int i=0;i<patr1.cor[2].nr_patr;i++) printf("  ");
	SetColor(15,0); 
	GotoXY(car_cor[3].cor.X,car_cor[3].cor.Y); printf("%3d",patr1.cor[3].nr_cor);
	GotoXY(car_cor[3].cor.X+6,car_cor[3].cor.Y); printf("%2d",patr1.cor[3].nr_patr);  
	GotoXY(car_cor[3].cor.X+12,car_cor[3].cor.Y);SetColor(col3.text,col3.background);for(int i=0;i<patr1.cor[3].nr_patr;i++) printf("  ");
	init_cimp(car_cimp[0].cor.X+35,car_cimp[0].cor.Y,patr->dim,col1.background,col2.background,patr->m_patr,rama);
	char alg,prm=0;
	BYTE nr_cor_max=(patr->dim+patr->dim%2)*(patr->dim+patr->dim%2)/4;
	for(int i=0;i<sizeof(patr->cor);i++){nr_cor_max-=(patr->cor[i].nr_patr-1)*patr->cor[i].nr_cor;}
	SetColor(0,15);GotoXY(car_cimp[0].cor.X+23,car_cimp[0].cor.Y);printf(" ");SetColor(15,0);
	do{
		alg=_getch();
		switch(alg){
			case 27:
				*patr=patr1;free(car_cor);
				return;
			case 13:
				return;
			case 80:
				if(prm!=1){
					if(prm>1){SetColor(15,0);GotoXY(car_cor[prm-2].cor.X-3,car_cor[prm-2].cor.Y);printf(" ");}
					else{SetColor(15,0);GotoXY(car_cimp[prm].cor.X+23,car_cimp[prm].cor.Y);printf(" ");}
					prm++;
					if(prm>1){SetColor(0,15);GotoXY(car_cor[prm-2].cor.X-3,car_cor[prm-2].cor.Y);printf(" ");}
					else{SetColor(0,15);GotoXY(car_cimp[prm].cor.X+23,car_cimp[prm].cor.Y);printf(" ");}
				}
				break;
			case 72:
				if(prm!=0){

					if(prm>1){SetColor(15,0);GotoXY(car_cor[prm-2].cor.X-3,car_cor[prm-2].cor.Y);printf(" ");}
					else{SetColor(15,0);GotoXY(car_cimp[prm].cor.X+23,car_cimp[prm].cor.Y);printf(" ");}
					prm--;
					if(prm>1){SetColor(0,15);GotoXY(car_cor[prm-2].cor.X-3,car_cor[prm-2].cor.Y);printf(" ");}
					else{SetColor(0,15);GotoXY(car_cimp[prm].cor.X+23,car_cimp[prm].cor.Y);printf(" ");}		
				}
				break;
			case 77:
				switch(prm){
					case 0:
						if(patr->dim!=20){
							patr->dim++;
							nr_cor_max=(patr->dim+patr->dim%2)*(patr->dim+patr->dim%2)/4;
							for(int i=0;i<sizeof(patr->cor);i++){nr_cor_max-=(patr->cor[i].nr_patr-1)*patr->cor[i].nr_cor;}
							SetColor(15,0); GotoXY(car_cimp[0].cor.X+25,car_cimp[0].cor.Y); printf("%3d",patr->dim);
							if((patr->dim==11)&&(patr->m_patr==2)){
								patr->m_patr--;
								SetColor(15,0); GotoXY(car_cimp[1].cor.X+25,car_cimp[1].cor.Y); printf("%3d",patr->m_patr);
							}
							_cls(car_cimp[0].cor.X+34,car_cimp[0].cor.Y,80,30,0);
							init_cimp(car_cimp[0].cor.X+35,car_cimp[0].cor.Y,patr->dim,col1.background,col2.background,patr->m_patr,rama);
						}
						break;
					case 1:
						if((patr->m_patr!=2)&&(patr->dim<=10)){
							patr->m_patr++;
							SetColor(15,0);GotoXY(car_cimp[1].cor.X+25,car_cimp[1].cor.Y); printf("%3d",patr->m_patr);
							_cls(car_cimp[0].cor.X+34,car_cimp[0].cor.Y,80,30,0);
							init_cimp(car_cimp[0].cor.X+35,car_cimp[0].cor.Y,patr->dim,col1.background,col2.background,patr->m_patr,rama);
						}
						break;
				}
				break;
			case 75:
				switch(prm){
					case 0:
						if(patr->dim!=5){
							patr->dim--;
							nr_cor_max=(patr->dim+patr->dim%2)*(patr->dim+patr->dim%2)/4;
							for(int i=0;i<sizeof(patr->cor);i++){nr_cor_max-=(patr->cor[i].nr_patr-1)*patr->cor[i].nr_cor;}
							if(patr->nr_cor>=nr_cor_max){
								patr->nr_cor=(patr->dim+patr->dim%2)*(patr->dim+patr->dim%2)/4;
								SetColor(15,0);GotoXY(car_cimp[2].cor.X+25,car_cimp[2].cor.Y); printf("%3d",patr->nr_cor);
							}
							SetColor(15,0); GotoXY(car_cimp[0].cor.X+25,car_cimp[0].cor.Y); printf("%3d",patr->dim);
							_cls(car_cimp[0].cor.X+34,car_cimp[0].cor.Y,80,30,0);
							init_cimp(car_cimp[0].cor.X+35,car_cimp[0].cor.Y,patr->dim,col1.background,col2.background,patr->m_patr,rama);
						}
						break;
					case 1:
						if(patr->m_patr!=1){
							patr->m_patr--;
							SetColor(15,0);GotoXY(car_cimp[1].cor.X+25,car_cimp[1].cor.Y); printf("%3d",patr->m_patr);
							_cls(car_cimp[0].cor.X+34,car_cimp[0].cor.Y,80,30,0);
							init_cimp(car_cimp[0].cor.X+35,car_cimp[0].cor.Y,patr->dim,col1.background,col2.background,patr->m_patr,rama);
						}
						break;
				}
				break;
		}
	}while(1);
}

void col_cimp(BYTE x, BYTE y, cimp_efc cp){
	init_cimp(x+35,y,10,cp.col1.background,cp.col2.background,2,cp.rama);
	SetColor(cp.col3.text,cp.col3.background);
	for(int i=0;i<2;i++){GotoXY(x+37,2+y+i);printf("    ");}
	for(int i=0;i<2;i++){GotoXY(x+49,2+y+i);printf("    ");}
	SetColor(cp.col4.text,cp.col4.background);
	for(int i=0;i<2;i++){GotoXY(x+53,2+y+i);printf("    ");}
	SetColor(cp.col5.text,cp.col5.background);
	for(int i=0;i<2;i++){GotoXY(x+65,2+y+i);printf("    ");printf("    ");printf("    ");}
	SetColor(cp.col6.text,cp.col6.background);
	for(int i=0;i<2;i++){GotoXY(x+41,2+y+i);printf("    ");printf("    ");}
	for(int i=0;i<2;i++){GotoXY(x+57,2+y+i);printf("    ");printf("    ");}
	for(int i=0;i<2;i++){GotoXY(x+37,4+y+i);for(int j=0;j<10;j++)printf("    ");}
}

void set_intr_cimp_menu(cimp_efc *cp){
	item car_cimp[7];
	cimp_efc cp1=*cp;
	car_cimp[0].cor.X=0; car_cimp[0].cor.Y=3;  car_cimp[0].s=(char*)malloc(25); car_cimp[0].s="          culoarea cimp 1\0"; 
	car_cimp[1].cor.X=0; car_cimp[1].cor.Y=5;  car_cimp[1].s=(char*)malloc(25); car_cimp[1].s="          culoarea cimp 2\0"; 
	car_cimp[2].cor.X=0; car_cimp[2].cor.Y=7;  car_cimp[2].s=(char*)malloc(25); car_cimp[2].s="culoarea corabie intreaga\0"; 
	car_cimp[3].cor.X=0; car_cimp[3].cor.Y=9;  car_cimp[3].s=(char*)malloc(25); car_cimp[3].s="  culoarea corabie ranita\0"; 
	car_cimp[4].cor.X=0; car_cimp[4].cor.Y=11; car_cimp[4].s=(char*)malloc(25); car_cimp[4].s="culoarea corabie distrusa\0"; 
	car_cimp[5].cor.X=0; car_cimp[5].cor.Y=13; car_cimp[5].s=(char*)malloc(25); car_cimp[5].s="        culoarea cimp gol\0"; 
	car_cimp[6].cor.X=0; car_cimp[6].cor.Y=15; car_cimp[6].s=(char*)malloc(25); car_cimp[6].s="                     rama\0"; 
	SetColor(15,0); GotoXY(car_cimp[0].cor.X,car_cimp[0].cor.Y); printf(car_cimp[0].s); puts(":"); GotoXY(car_cimp[0].cor.X+30,car_cimp[0].cor.Y); SetColor(cp->col1.text,cp->col1.background); printf("  "); 
	SetColor(15,0); GotoXY(car_cimp[1].cor.X,car_cimp[1].cor.Y); printf(car_cimp[1].s); puts(":"); GotoXY(car_cimp[1].cor.X+30,car_cimp[1].cor.Y); SetColor(cp->col2.text,cp->col2.background); printf("  "); 
	SetColor(15,0); GotoXY(car_cimp[2].cor.X,car_cimp[2].cor.Y); printf(car_cimp[2].s); puts(":"); GotoXY(car_cimp[2].cor.X+30,car_cimp[2].cor.Y); SetColor(cp->col3.text,cp->col3.background); printf("  "); 
	SetColor(15,0); GotoXY(car_cimp[3].cor.X,car_cimp[3].cor.Y); printf(car_cimp[3].s); puts(":"); GotoXY(car_cimp[3].cor.X+30,car_cimp[3].cor.Y); SetColor(cp->col4.text,cp->col4.background); printf("  "); 
	SetColor(15,0); GotoXY(car_cimp[4].cor.X,car_cimp[4].cor.Y); printf(car_cimp[4].s); puts(":"); GotoXY(car_cimp[4].cor.X+30,car_cimp[4].cor.Y); SetColor(cp->col5.text,cp->col5.background); printf("  "); 
	SetColor(15,0); GotoXY(car_cimp[5].cor.X,car_cimp[5].cor.Y); printf(car_cimp[5].s); puts(":"); GotoXY(car_cimp[5].cor.X+30,car_cimp[5].cor.Y); SetColor(cp->col6.text,cp->col6.background); printf("  "); 
	SetColor(15,0); GotoXY(car_cimp[6].cor.X,car_cimp[6].cor.Y); printf(car_cimp[6].s); puts(":"); GotoXY(car_cimp[6].cor.X+30,car_cimp[6].cor.Y); printf("%2d",cp->rama); 
	col_cimp(car_cimp[0].cor.X,car_cimp[0].cor.Y,*cp);	
	char alg,prm=0;
	SetColor(0,15);GotoXY(car_cimp[0].cor.X+27,car_cimp[0].cor.Y);printf(" ");SetColor(15,0);
	do{
		alg=_getch();
		switch(alg){
			case 27:
				*cp=cp1;
				return;
			case 13:
				return;
			case 80:
				if(prm!=6){
					SetColor(15,0);GotoXY(car_cimp[prm].cor.X+27,car_cimp[prm].cor.Y);printf(" ");
					prm++;
					SetColor(0,15);GotoXY(car_cimp[prm].cor.X+27,car_cimp[prm].cor.Y);printf(" ");
				}
				break;
			case 72:
				if(prm!=0){
					SetColor(15,0);GotoXY(car_cimp[prm].cor.X+27,car_cimp[prm].cor.Y);printf(" ");
					prm--;
					SetColor(0,15);GotoXY(car_cimp[prm].cor.X+27,car_cimp[prm].cor.Y);printf(" ");		
				}
				break;
			case 77:
				switch(prm){
					case 0:
						if(cp->col1.background!=15){
							cp->col1.background++;
							GotoXY(car_cimp[0].cor.X+30,car_cimp[0].cor.Y); SetColor(cp->col1.text,cp->col1.background); printf("  ");
							col_cimp(car_cimp[0].cor.X,car_cimp[0].cor.Y,*cp);
						}
						break;
					case 1:
						if(cp->col2.background!=15){
							cp->col2.background++;
							GotoXY(car_cimp[1].cor.X+30,car_cimp[1].cor.Y); SetColor(cp->col2.text,cp->col2.background); printf("  ");
							col_cimp(car_cimp[0].cor.X,car_cimp[0].cor.Y,*cp);
						}
						break;
					case 2:
						if(cp->col3.background!=15){
							cp->col3.background++;
							GotoXY(car_cimp[2].cor.X+30,car_cimp[2].cor.Y); SetColor(cp->col3.text,cp->col3.background); printf("  ");
							SetColor(cp->col3.text,cp->col3.background);
							for(int i=0;i<2;i++){GotoXY(car_cimp[0].cor.X+37,2+car_cimp[0].cor.Y+i);printf("    ");}
							for(int i=0;i<2;i++){GotoXY(car_cimp[0].cor.X+49,2+car_cimp[0].cor.Y+i);printf("    ");}
						}
						break;
					case 3:
						if(cp->col4.background!=15){
							cp->col4.background++;
							GotoXY(car_cimp[3].cor.X+30,car_cimp[3].cor.Y); SetColor(cp->col4.text,cp->col4.background); printf("  ");
							SetColor(cp->col4.text,cp->col4.background);
							for(int i=0;i<2;i++){GotoXY(car_cimp[0].cor.X+53,2+car_cimp[0].cor.Y+i);printf("    ");}
						}
						break;
					case 4:
						if(cp->col5.background!=15){
							cp->col5.background++;
							GotoXY(car_cimp[4].cor.X+30,car_cimp[4].cor.Y); SetColor(cp->col5.text,cp->col5.background); printf("  ");
							SetColor(cp->col5.text,cp->col5.background);
							for(int i=0;i<2;i++){GotoXY(car_cimp[0].cor.X+65,2+car_cimp[0].cor.Y+i);printf("    ");printf("    ");printf("    ");}
						}
						break;
					case 5:
						if(cp->col6.background!=15){
							cp->col6.background++;
							GotoXY(car_cimp[5].cor.X+30,car_cimp[5].cor.Y); SetColor(cp->col6.text,cp->col6.background); printf("  ");
							SetColor(cp->col6.text,cp->col6.background);
							for(int i=0;i<2;i++){GotoXY(car_cimp[0].cor.X+41,2+car_cimp[0].cor.Y+i);printf("    ");printf("    ");}
							for(int i=0;i<2;i++){GotoXY(car_cimp[0].cor.X+57,2+car_cimp[0].cor.Y+i);printf("    ");printf("    ");}
							for(int i=0;i<2;i++){GotoXY(car_cimp[0].cor.X+37,4+car_cimp[0].cor.Y+i);for(int j=0;j<10;j++)printf("    ");}
						}
						break;
					case 6:
						if(cp->rama!=4){
							cp->rama++;
							SetColor(15,0);GotoXY(car_cimp[6].cor.X+30,car_cimp[6].cor.Y); printf("%2d",cp->rama);
							_cls(car_cimp[0].cor.X+35,2,127,47,0);
							col_cimp(car_cimp[0].cor.X,car_cimp[0].cor.Y,*cp);

						}
						break;
				}
				break;
			case 75:
				switch(prm){
					case 0:
						if(cp->col1.background!=0){
							cp->col1.background--;
							GotoXY(car_cimp[0].cor.X+30,car_cimp[0].cor.Y); SetColor(cp->col1.text,cp->col1.background); printf("  ");
							col_cimp(car_cimp[0].cor.X,car_cimp[0].cor.Y,*cp);
						}
						break;
					case 1:
						if(cp->col2.background!=0){
							cp->col2.background--;
							GotoXY(car_cimp[1].cor.X+30,car_cimp[1].cor.Y); SetColor(cp->col2.text,cp->col2.background); printf("  ");
							col_cimp(car_cimp[0].cor.X,car_cimp[0].cor.Y,*cp);
						}
						break;
					case 2:
						if(cp->col3.background!=0){
							cp->col3.background--;
							SetColor(cp->col3.text,cp->col3.background);
							GotoXY(car_cimp[2].cor.X+30,car_cimp[2].cor.Y); SetColor(cp->col3.text,cp->col3.background); printf("  ");
							for(int i=0;i<2;i++){GotoXY(car_cimp[0].cor.X+37,2+car_cimp[0].cor.Y+i);printf("    ");}
							for(int i=0;i<2;i++){GotoXY(car_cimp[0].cor.X+49,2+car_cimp[0].cor.Y+i);printf("    ");}
						}
						break;
					case 3:
						if(cp->col4.background!=0){
							cp->col4.background--;
							GotoXY(car_cimp[3].cor.X+30,car_cimp[3].cor.Y); SetColor(cp->col4.text,cp->col4.background); printf("  ");
							SetColor(cp->col4.text,cp->col4.background);
							for(int i=0;i<2;i++){GotoXY(car_cimp[0].cor.X+53,2+car_cimp[0].cor.Y+i);printf("    ");}
						}
						break;
					case 4:
						if(cp->col5.background!=0){
							cp->col5.background--;
							GotoXY(car_cimp[4].cor.X+30,car_cimp[4].cor.Y); SetColor(cp->col5.text,cp->col5.background); printf("  ");
							SetColor(cp->col5.text,cp->col5.background);
							for(int i=0;i<2;i++){GotoXY(car_cimp[0].cor.X+65,2+car_cimp[0].cor.Y+i);printf("    ");printf("    ");printf("    ");}
						}
						break;
					case 5:
						if(cp->col6.background!=0){
							cp->col6.background--;
							GotoXY(car_cimp[5].cor.X+30,car_cimp[5].cor.Y); SetColor(cp->col6.text,cp->col6.background); printf("  ");
							SetColor(cp->col6.text,cp->col6.background);
							for(int i=0;i<2;i++){GotoXY(car_cimp[0].cor.X+41,2+car_cimp[0].cor.Y+i);printf("    ");printf("    ");}
							for(int i=0;i<2;i++){GotoXY(car_cimp[0].cor.X+57,2+car_cimp[0].cor.Y+i);printf("    ");printf("    ");}
							for(int i=0;i<2;i++){GotoXY(car_cimp[0].cor.X+37,4+car_cimp[0].cor.Y+i);for(int j=0;j<10;j++)printf("    ");}
						}
						break;
					case 6:
						if(cp->rama!=1){
							cp->rama--;
							SetColor(15,0);GotoXY(car_cimp[6].cor.X+30,car_cimp[6].cor.Y); printf("%2d",cp->rama);
							_cls(car_cimp[0].cor.X+35,2,127,47,0);
							col_cimp(car_cimp[0].cor.X,car_cimp[0].cor.Y,*cp);	

						}
						break;
				}
				break;
		}
	}while(1);
}