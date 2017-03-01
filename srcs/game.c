#include "mboi.h"

BYTE Set_col_dep(BYTE a, BYTE prm, color cl[2], BYTE i, cimp_efc cp){
	switch(a){
		case 0: return cl[i%2].background;break;
		case 1:
    		if(prm) return cp.col3.background;
			else    return cl[i%2].background;
			break;
		case 2: return cp.col4.background;break;
		case 3: return cp.col5.background;break;
		case 4: return cp.col6.background;break;
	}
}

void afisare(BYTE x, BYTE y, car_patr patr, cimp_efc cp, cimp **A, BOOL tip){
	init_cimp(x,y,patr.dim,cp.col1.background,cp.col2.background,patr.m_patr,cp.rama);
    for(BYTE i=1;i<patr.dim+1;i++){
		for(BYTE j=1;j<patr.dim+1;j++){
			switch(A[i][j].a){
				case 1: if(tip)col_cel((j-1)*2*patr.m_patr+x+2,(i-1)*patr.m_patr+y+2,patr.m_patr,cp.col3.background);break;
				case 2: col_cel((j-1)*2*patr.m_patr+x+2,(i-1)*patr.m_patr+y+2,patr.m_patr,cp.col4.background); break;
				case 3: col_cel((j-1)*2*patr.m_patr+x+2,(i-1)*patr.m_patr+y+2,patr.m_patr,cp.col5.background); break;
				case 4: col_cel((j-1)*2*patr.m_patr+x+2,(i-1)*patr.m_patr+y+2,patr.m_patr,cp.col6.background); break;
			}   
		}
	}
}

BOOL deplasare(COORD cori, COORD *cor, car_patr patr, cimp_efc cp, cimp **A, BYTE tip_cor, BOOL *orn, BOOL prm){
    BYTE alg;
    color cl[2];
    if(patr.dim%2==1){
        if(((cor->Y-1)*patr.dim+cor->X)%2==1){cl[0]=cp.col1;cl[1]=cp.col2;}
        else{cl[0]=cp.col2;cl[1]=cp.col1; }
    }
    else{
        if(cor->Y%2==1){
            if(cor->X%2==1){
                cl[1]=cp.col2;cl[0]=cp.col1;
            }
            else{
                cl[1]=cp.col1;cl[0]=cp.col2;
            }
        }
        else{
            if(cor->X%2==1){
                cl[1]=cp.col1;cl[0]=cp.col2;
            }
            else{
                cl[1]=cp.col2;cl[0]=cp.col1;
            }
        }
    }
    color aux;
    if(*orn)
        for(int i=0;i<tip_cor;i++) 
        col_cel((cor->X-1)*2*patr.m_patr+cori.X,(cor->Y-1)*patr.m_patr+cori.Y+i*patr.m_patr,patr.m_patr,cp.col3.background);
    else
        for(int i=0;i<tip_cor;i++)
            col_cel((cor->X-1)*2*patr.m_patr+cori.X+i*patr.m_patr*2,(cor->Y-1)*patr.m_patr+cori.Y,patr.m_patr,cp.col3.background);
    do{
        alg=_getch();
        switch(alg){
            case 27:
                if(*orn)
                    for(int i=0;i<tip_cor;i++)
                        col_cel((cor->X-1)*2*patr.m_patr+cori.X,(cor->Y-1)*patr.m_patr+cori.Y+i*patr.m_patr,patr.m_patr,Set_col_dep(A[cor->Y+i][cor->X].a,prm,cl,i,cp));   
                else
                    for(int i=0;i<tip_cor;i++)
                        col_cel((cor->X-1)*2*patr.m_patr+cori.X+i*patr.m_patr*2,(cor->Y-1)*patr.m_patr+cori.Y,patr.m_patr,Set_col_dep(A[cor->Y][cor->X+i].a,prm,cl,i,cp));
                return 0;
            case 13:
                if(*orn)
                    for(int i=0;i<tip_cor;i++)
                        col_cel((cor->X-1)*2*patr.m_patr+cori.X,(cor->Y-1)*patr.m_patr+cori.Y+i*patr.m_patr,patr.m_patr,Set_col_dep(A[cor->Y+i][cor->X].a,prm,cl,i,cp));   
                else
                    for(int i=0;i<tip_cor;i++)
                        col_cel((cor->X-1)*2*patr.m_patr+cori.X+i*patr.m_patr*2,(cor->Y-1)*patr.m_patr+cori.Y,patr.m_patr,Set_col_dep(A[cor->Y][cor->X+i].a,prm,cl,i,cp));
                return 1;
            case 32:
                if(*orn){
                    if(cor->X+tip_cor-1<=patr.dim){
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X,(cor->Y-1)*patr.m_patr+cori.Y+i*patr.m_patr,patr.m_patr,Set_col_dep(A[cor->Y+i][cor->X].a,prm,cl,i,cp));
                        *orn-=1;
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X+i*patr.m_patr*2,(cor->Y-1)*patr.m_patr+cori.Y,patr.m_patr,cp.col3.background);
                    }
                }
                else{
                    if(cor->Y+tip_cor-1<=patr.dim){
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X+i*patr.m_patr*2,(cor->Y-1)*patr.m_patr+cori.Y,patr.m_patr,Set_col_dep(A[cor->Y][cor->X+i].a,prm,cl,i,cp));
                        *orn+=1;
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X,(cor->Y-1)*patr.m_patr+cori.Y+i*patr.m_patr,patr.m_patr,cp.col3.background);
                    }
                }
                break;
            case 72://sus
                if(cor->Y!=1){
                    if(*orn){
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X,(cor->Y-1)*patr.m_patr+cori.Y+i*patr.m_patr,patr.m_patr,Set_col_dep(A[cor->Y+i][cor->X].a,prm,cl,i,cp));
                        cor->Y--;
                        aux=cl[0];cl[0]=cl[1];cl[1]=aux;
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X,(cor->Y-1)*patr.m_patr+cori.Y+i*patr.m_patr,patr.m_patr,cp.col3.background);
                    }
                    else{
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X+i*patr.m_patr*2,(cor->Y-1)*patr.m_patr+cori.Y,patr.m_patr,Set_col_dep(A[cor->Y][cor->X+i].a,prm,cl,i,cp));   
                        cor->Y--;
                        aux=cl[0];cl[0]=cl[1];cl[1]=aux;
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X+i*patr.m_patr*2,(cor->Y-1)*patr.m_patr+cori.Y,patr.m_patr,cp.col3.background);
                    }   
                }
                break;
            case 80://jos
                if(*orn){
                    if(cor->Y+tip_cor-1!=patr.dim){
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X,(cor->Y-1)*patr.m_patr+cori.Y+i*patr.m_patr,patr.m_patr,Set_col_dep(A[cor->Y+i][cor->X].a,prm,cl,i,cp));
                        cor->Y++;
                        aux=cl[0];cl[0]=cl[1];cl[1]=aux;
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X,(cor->Y-1)*patr.m_patr+cori.Y+i*patr.m_patr,patr.m_patr,cp.col3.background);
                    }
                }
                else{
                    if(cor->Y!=patr.dim){
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X+i*patr.m_patr*2,(cor->Y-1)*patr.m_patr+cori.Y,patr.m_patr,Set_col_dep(A[cor->Y][cor->X+i].a,prm,cl,i,cp));
                        cor->Y++;
                        aux=cl[0];cl[0]=cl[1];cl[1]=aux;
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X+i*patr.m_patr*2,(cor->Y-1)*patr.m_patr+cori.Y,patr.m_patr,cp.col3.background);
                    }
                }
                break;
            case 77://dreapta
                if(*orn){
                    if(cor->X!=patr.dim){
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X,(cor->Y-1)*patr.m_patr+cori.Y+i*patr.m_patr,patr.m_patr,Set_col_dep(A[cor->Y+i][cor->X].a,prm,cl,i,cp));
                        cor->X++;
                        aux=cl[0];cl[0]=cl[1];cl[1]=aux;
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X,(cor->Y-1)*patr.m_patr+cori.Y+i*patr.m_patr,patr.m_patr,cp.col3.background);
                    }
                }
                else{
                    if(cor->X+tip_cor-1!=patr.dim){
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X+i*patr.m_patr*2,(cor->Y-1)*patr.m_patr+cori.Y,patr.m_patr,Set_col_dep(A[cor->Y][cor->X+i].a,prm,cl,i,cp));
                        cor->X++;patr;
                        aux=cl[0];cl[0]=cl[1];cl[1]=aux;
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X+i*patr.m_patr*2,(cor->Y-1)*patr.m_patr+cori.Y,patr.m_patr,cp.col3.background);
                    }
                }
                break;
            case 75://stinga
                if(cor->X!=1){
                    if(*orn){
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X,(cor->Y-1)*patr.m_patr+cori.Y+i*patr.m_patr,patr.m_patr,Set_col_dep(A[cor->Y+i][cor->X].a,prm,cl,i,cp));
                        cor->X--;
                        aux=cl[0];cl[0]=cl[1];cl[1]=aux;
                        SetColor(cp.col3.text,cp.col3.background);
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X,(cor->Y-1)*patr.m_patr+cori.Y+i*patr.m_patr,patr.m_patr,cp.col3.background);
                    }
                    else{
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X+i*patr.m_patr*2,(cor->Y-1)*patr.m_patr+cori.Y,patr.m_patr,Set_col_dep(A[cor->Y][cor->X+i].a,prm,cl,i,cp));   
                        cor->X--;
                        aux=cl[0];cl[0]=cl[1];cl[1]=aux;
                        for(int i=0;i<tip_cor;i++)
                            col_cel((cor->X-1)*2*patr.m_patr+cori.X+i*patr.m_patr*2,(cor->Y-1)*patr.m_patr+cori.Y,patr.m_patr,cp.col3.background);
                    }       
                }
                break;
        }
    }while(1);
}

BOOL ver_intr_cor(cimp **A, COORD cor, BYTE l, BOOL orn){
	COORD cori,corf;
	if(orn){
		if(cor.Y+l-1>10) return 0;
		else{
			cori.X=cor.X-1;cori.Y=cor.Y-1;
			corf.X=cor.X+1;corf.Y=cor.Y+l;
		}
	}
	else{
		if(cor.X+l-1>10) return 0;
		else{
			cori.X=cor.X-1;cori.Y=cor.Y-1;
			corf.X=cor.X+l;corf.Y=cor.Y+1;
		}
	}
	for(int i=cori.Y;i<=corf.Y;i++){
		for(int j=cori.X;j<=corf.X;j++){
			if(A[i][j].a==1){
				return 0;
			}
		}	
	}
	BYTE *link=(BYTE*)malloc(sizeof(BYTE));
	*link=l;
	for(int i=cori.Y+1;i<corf.Y;i++){
		for(int j=cori.X+1;j<corf.X;j++){
			A[i][j].a=1;
			A[i][j].link=link;
		}
	}
	return 1;
}

BOOL intr_man(cimp **A, car_patr patr, cimp_efc cp){
	BOOL orn=1;
	for(BYTE i=0;i<patr.dim+2;i++)
		for(BYTE j=0;j<patr.dim+2;j++){
			A[i][j].a=0;
			A[i][j].link=NULL;
		}
	afisare(1,4,patr,cp,A,1);
	car_cor aux;
	car_cor *cor_aux=(car_cor*)malloc(_msize(patr.cor));
	for(int i=0;i<_msize(cor_aux)/sizeof(cor_aux[0]);i++){
		cor_aux[i].nr_patr=patr.cor[i].nr_patr;
		cor_aux[i].nr_cor=patr.cor[i].nr_cor;
	}

	item *car_cor=(item*)malloc(sizeof(item)*_msize(patr.cor)/sizeof(patr.cor[0]));
	for(int i=0;i<_msize(patr.cor)/sizeof(patr.cor[0]);i++){
		car_cor[i].cor.X=50; car_cor[i].cor.Y=5+2*i;  	
	}
	SetColor(15,0); GotoXY(50,3); printf("n_c");GotoXY(56,3); printf("n_p");
	for(int i=0;i<_msize(cor_aux)/sizeof(cor_aux[0]);i++){ 
		GotoXY(car_cor[i].cor.X,car_cor[i].cor.Y);   printf("%3d",cor_aux[i].nr_cor);
		GotoXY(car_cor[i].cor.X+6,car_cor[i].cor.Y); printf("%2d",cor_aux[i].nr_patr);  
		GotoXY(car_cor[i].cor.X+12,car_cor[i].cor.Y);SetColor(cp.col3.text+1,cp.col3.background);for(int j=0;j<cor_aux[i].nr_patr;j++)printf("  ");  	
		SetColor(15,0);
	}
	char alg,prm=0;
	COORD cori={3,6};
	COORD cor={1,1};
	SetColor(0,15);GotoXY(car_cor[prm].cor.X-2,car_cor[prm].cor.Y);printf(" ");
	do{
		alg=_getch();
		switch(alg){
			case 13://enter
				SetColor(15,0);GotoXY(car_cor[prm].cor.X-2,car_cor[prm].cor.Y);printf(" ");
				do{
					if(deplasare(cori,&cor,patr,cp,A,cor_aux[prm].nr_patr,&orn,1)==1){//a fost tastat enter
						GotoXY(0,40);SetColor(15,0);//("dep=0");
						if(ver_intr_cor(A,cor,cor_aux[prm].nr_patr,orn)){//corabia a fost introdusa pe aceste coordonate
							if(orn){
								for(BYTE i=0;i<cor_aux[prm].nr_patr;i++){
									col_cel((cor.X-1)*2*patr.m_patr+cori.X,(cor.Y-1)*patr.m_patr+cori.Y+i*patr.m_patr,patr.m_patr,cp.col3.background);
						        }
							}
							else{
								for(BYTE i=0;i<cor_aux[prm].nr_patr;i++){
									col_cel((cor.X-1)*2*patr.m_patr+cori.X+i*patr.m_patr*2,(cor.Y-1)*patr.m_patr+cori.Y,patr.m_patr,cp.col3.background);
					            }
							}
							cor.X=1; cor.Y=1;
							if(--cor_aux[prm].nr_cor==0){//sau finisat toate corabiile de un anumit tip
								for(int i=prm+1;i<_msize(cor_aux)/sizeof(cor_aux[0]);i++){
									aux=cor_aux[i];cor_aux[i]=cor_aux[i-1];cor_aux[i-1]=aux;
								}
								if(_msize(cor_aux)/sizeof(cor_aux[0])-1!=0){// mai sunt corabii care trebuiesc introduse 
									cor_aux=realloc(cor_aux,_msize(cor_aux)-sizeof(cor_aux[0]));
									_cls(50,4,224,50,0);
									for(int i=0;i<_msize(cor_aux)/sizeof(cor_aux[0]);i++){ 
										SetColor(15,0);
										GotoXY(car_cor[i].cor.X,car_cor[i].cor.Y);   printf("%3d",cor_aux[i].nr_cor);
										GotoXY(car_cor[i].cor.X+6,car_cor[i].cor.Y); printf("%2d",cor_aux[i].nr_patr);  
										GotoXY(car_cor[i].cor.X+12,car_cor[i].cor.Y);SetColor(cp.col3.text+1,cp.col3.background); for(int j=0;j<cor_aux[i].nr_patr;j++)printf("  ");  											
									}
								}
								else{// corabiile sau finisat
									goto iesire;
								}
							}
							else{//mai sunt corabii care trebuiesc introduse
								SetColor(15,0); GotoXY(car_cor[prm].cor.X,car_cor[prm].cor.Y);printf("%3d",cor_aux[prm].nr_cor);	
							}
							goto et1;
						} 
					}
					else{//a fost tastat esc
						cor.X=1; cor.Y=1; goto et1;	
					}
				}while(1);
				et1:
				prm=0;SetColor(0,15);GotoXY(car_cor[prm].cor.X-2,car_cor[prm].cor.Y);printf(" ");
				break;
			case 27://esc
				goto iesire;
			case 72://sus
				if(prm!=0){
					SetColor(15,0);GotoXY(car_cor[prm].cor.X-2,car_cor[prm].cor.Y);printf(" ");
					prm--;
					SetColor(0,15);GotoXY(car_cor[prm].cor.X-2,car_cor[prm].cor.Y);printf(" ");
				}
				break;
			case 80://jos
				if(prm!=_msize(cor_aux)/sizeof(cor_aux[0])-1){
					SetColor(15,0);GotoXY(car_cor[prm].cor.X-2,car_cor[prm].cor.Y);printf(" ");
					prm++;
					SetColor(0,15);GotoXY(car_cor[prm].cor.X-2,car_cor[prm].cor.Y);printf(" ");
				}
				break;	
		}
	}while(1);
	iesire:
	free(car_cor);free(cor_aux);
}

void intr_ran(cimp **A, car_patr patr, cimp_efc cp){
	BYTE x,y;
	BOOL orn;
	COORD cor;
	for(BYTE i=0;i<patr.dim+2;i++)
		for(BYTE j=0;j<patr.dim+2;j++){
			A[i][j].a=0;
			A[i][j].link=NULL;
		}
	for(int i=_msize(patr.cor)/sizeof(patr.cor[0])-1;i>=0;i--){
		for(int j=0;j<patr.cor[i].nr_cor;j++){
			do{
				cor.Y=rand()%patr.dim+1;cor.X=rand()%patr.dim+1;
				orn=rand()%2;
				if(ver_intr_cor(A,cor,patr.cor[i].nr_patr,orn))goto et1;
				else
					if(ver_intr_cor(A,cor,patr.cor[i].nr_patr,!orn))goto et1;
			}while(1);
			et1:;
		}
	}
}

BOOL intr_cor(cimp **A,car_patr patr,cimp_efc cp){
	item opt[2];
	rama(48,10,5,20,4);
	opt[0].cor.X=50; opt[0].cor.Y=12; opt[0].s=(char*)malloc(8); opt[0].s="manual\0";
	opt[1].cor.X=60; opt[1].cor.Y=12; opt[1].s=(char*)malloc(8); opt[1].s="random\0";
	BYTE alg,alg1,prm=0;	
	item opts[2];
	opts[0].cor.X=54; opts[0].cor.Y=13; opts[0].s=(char*)malloc(4); opts[0].s="DA\0";
	opts[1].cor.X=59; opts[1].cor.Y=13; opts[1].s=(char*)malloc(4); opts[1].s="NU\0";
	SetColor(inactive.text,inactive.background);
	for(int i=0;i<2;i++){
		GotoXY(opt[i].cor.X,opt[i].cor.Y);printf(opt[i].s);
	}
	SetColor(active.text,active.background);
	GotoXY(opt[prm].cor.X,opt[prm].cor.Y);printf(opt[prm].s);
	do{
		alg=_getch();
		switch(alg){
			case 13:
				switch(prm){
					case 0:
						_cls(48,10,68,15,0);
						intr_man(A,patr,cp);
						break;
					case 1:
						_cls(50,12,65,12,0);
						prm=0;
						GotoXY(55,11);SetColor(15,0); puts("merge?");
						SetColor(inactive.text,inactive.background);
						for(int i=0;i<2;i++){
							GotoXY(opts[i].cor.X,opts[i].cor.Y);printf(opts[i].s);
						}
						SetColor(active.text,active.background);
						GotoXY(opts[prm].cor.X,opts[prm].cor.Y);printf(opts[prm].s);
						do{
							intr_ran(A,patr,cp);
							afisare(1,4,patr,cp,A,1);
							do{
								alg=_getch();
								switch(alg){
									case 13:
										if(!prm) {
											for(int i=0;i<2;i++){free(opt[i].s);free(opts[i].s);}
											return 0;
										}
										else goto et2;
									case 27:
										for(int i=0;i<2;i++){free(opt[i].s);free(opts[i].s);}
										return 1;
									case 77://dreapta
										if(prm!=1){
											GotoXY(opts[prm].cor.X,opts[prm].cor.Y);SetColor(inactive.text,inactive.background);printf(opts[prm].s);
											prm++;
											GotoXY(opts[prm].cor.X,opts[prm].cor.Y);SetColor(active.text,active.background);printf(opts[prm].s);
										}
										break;
									case 75://stinga
										if(prm!=0){
											GotoXY(opts[prm].cor.X,opts[prm].cor.Y);SetColor(inactive.text,inactive.background);printf(opts[prm].s);
											prm--;
											GotoXY(opts[prm].cor.X,opts[prm].cor.Y);SetColor(active.text,active.background);printf(opts[prm].s);
										}
										break;
								}	
							}while(1);
							et2:;	
						}while(1);
						for(int i=0;i<2;i++){free(opt[i].s);free(opts[i].s);}
						return 1;
				}
				return 0;
			case 27:
				return 1;
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

void zona(cimp **A, BYTE x, BYTE y){
	A[y][x].a=4;
	if(A[y+1][x+1].a==0)A[y+1][x+1].a=5;
	if(A[y-1][x+1].a==0)A[y-1][x+1].a=5;
	if(A[y+1][x-1].a==0)A[y+1][x-1].a=5;
	if(A[y-1][x-1].a==0)A[y-1][x-1].a=5;
	switch(A[y][x+1].a){
		case 0: A[y][x+1].a=5; break;
		case 2: zona(A,x+1,y);
	}
	switch(A[y][x-1].a){
		case 0: A[y][x-1].a=5; break;
		case 2: zona(A,x-1,y);
	}
	switch(A[y+1][x].a){
		case 0: A[y+1][x].a=5; break;
		case 2: zona(A,x,y+1);
	}
	switch(A[y-1][x].a){
		case 0: A[y-1][x].a=5; break;
		case 2: zona(A,x,y-1);
	}
	A[y][x].a=2;
}

void zona2(cimp **A, COORD cori, BYTE x, BYTE y, BYTE m_patr, color col){
	A[y][x].a=3;
	col_cel((x-1)*2*m_patr+cori.X,(y-1)*m_patr+cori.Y,m_patr,col.background);
	if(A[y][x+1].a==2)zona2(A,cori,x+1,y,m_patr,col);
	if(A[y][x-1].a==2)zona2(A,cori,x-1,y,m_patr,col);
	if(A[y+1][x].a==2)zona2(A,cori,x,y+1,m_patr,col);
	if(A[y-1][x].a==2)zona2(A,cori,x,y-1,m_patr,col);
}

BYTE gcu(cimp **A, COORD *cor, car_patr patr, cimp_efc cp){
	COORD cori={3,6};//,cor={1,1};
	BOOL orn=1;
	do{
		switch(deplasare(cori,cor,patr,cp,A,1,&orn,0)){
			case 0: return 27;
			case 1:
				if(A[cor->Y][cor->X].a==1){
					*(A[cor->Y][cor->X].link)-=1;
					if(*A[cor->Y][cor->X].link==0){
						_cls(52,12,89,18,0);SetColor(15,0); GotoXY(65,13); printf(" corabie distrusa");
						A[cor->Y][cor->X].a=3;
						zona2(A,cori,cor->X,cor->Y,patr.m_patr,cp.col5);
						return 3;
					}
					else{
						_cls(52,12,89,18,0);SetColor(15,0); GotoXY(65,13); printf(" corabie ranita");
						A[cor->Y][cor->X].a=2;
						col_cel((cor->X-1)*2*patr.m_patr+cori.X,(cor->Y-1)*patr.m_patr+cori.Y,patr.m_patr,cp.col4.background);
						return 2;
					}
				}
				else{
					_cls(52,12,89,18,0);SetColor(15,0); GotoXY(65,13); printf("nu ai nimerit");
					if(A[cor->Y][cor->X].a==0){
						A[cor->Y][cor->X].a=4;
						col_cel((cor->X-1)*2*patr.m_patr+cori.X,(cor->Y-1)*patr.m_patr+cori.Y,patr.m_patr,cp.col6.background);
					}
					return 0;
				}
		}
	}while(1);
}

BYTE cercetare(cimp **A, COORD *cor, BYTE dim){
	do{
		cor->X=rand()%dim+1;
		cor->Y=rand()%dim+1;
		switch(A[cor->Y][cor->X].a){
			case 0: 
				A[cor->Y][cor->X].a=4;
				return 0;
			case 1:
				*(A[cor->Y][cor->X].link)-=1;
				if(*A[cor->Y][cor->X].link==0){
					A[cor->Y][cor->X].a=3;
					zona(A,cor->X,cor->Y);
					return 3;
				}
				else{
					A[cor->Y][cor->X].a=2;
					return 2;
				}
		}
	}while(1);
}
void comp(cimp **A, COORD **var_cor, BYTE dim){
	COORD *cor;
	BYTE x,y,nr=0;
	x=(*var_cor)->X;y=(*var_cor)->Y;
	cor=*var_cor;free(*var_cor);
	cor=malloc(4*sizeof(COORD));	
	cor[nr].X=x-1;cor[nr].Y=y;
	if(cor[nr].X<1)goto esst;
	if((A[cor[nr].Y][cor[nr].X].a==4)||(A[cor[nr].Y][cor[nr].X].a==5))goto esst;
	nr++;
	esst:
	cor[nr].X=x+1;cor[nr].Y=y;
	if(cor[nr].X>dim)goto esdr;
	if((A[cor[nr].Y][cor[nr].X].a==4)||(A[cor[nr].Y][cor[nr].X].a==5))goto esdr;
	nr++;
	esdr:
	cor[nr].X=x;cor[nr].Y=y-1;
	if(cor[nr].Y<1)goto essus;
	if((A[cor[nr].Y][cor[nr].X].a==4)||(A[cor[nr].Y][cor[nr].X].a==5))goto essus;
	nr++;
	essus:
	cor[nr].X=x;cor[nr].Y=y+1;
	if(cor[nr].Y>dim)goto esjos;
	if((A[cor[nr].Y][cor[nr].X].a==4)||(A[cor[nr].Y][cor[nr].X].a==5))goto esjos;
	nr++;
	esjos:
	nr--;
	cor=(COORD*)realloc(cor,(nr+1)*sizeof(COORD));
	*var_cor=cor;
	return;
}

void el_var(cimp **A, COORD **cor, BYTE prm, BYTE dim){
	COORD *temp,*aux;
	BYTE dir=0;
	temp=*cor;
	BYTE nr=0;
	aux=(COORD*)malloc(4*sizeof(COORD));
	if((temp[prm].Y!=dim)&&(A[temp[prm].Y-1][temp[prm].X].a==2)){dir=1; goto et1;}
	if((temp[prm].Y!=1)  &&(A[temp[prm].Y+1][temp[prm].X].a==2)){dir=2; goto et1;}
	if((temp[prm].X!=dim)&&(A[temp[prm].Y][temp[prm].X-1].a==2)){dir=3; goto et1;}
	if((temp[prm].X!=1)  &&(A[temp[prm].Y][temp[prm].X+1].a==2)){dir=4; goto et1;}
	et1:
	for(int i=0;i<(_msize(*cor)/sizeof(temp[0]));i++){
		if(((temp[prm].X==temp[i].X)||(temp[prm].Y==temp[i].Y))){
			aux[nr].X=temp[i].X;
			aux[nr].Y=temp[i].Y;
			nr++;
		}	
	}
	aux=(COORD*)realloc(aux,nr*sizeof(COORD));
	for(int i=0;i<_msize(aux)/sizeof(aux[0]);i++){
		if((aux[i].X==temp[prm].X)&&(aux[i].Y==temp[prm].Y)){
			free(temp);
			switch(dir){
				case 1:aux[i].Y+=1; *cor=aux;return;	
				case 2:aux[i].Y-=1; *cor=aux;return;
				case 3:aux[i].X+=1; *cor=aux;return;
				case 4:aux[i].X-=1; *cor=aux;return;
			}
		}
	}
	*cor=aux; 
	return;
}

BYTE gcc(cimp **A, car_patr patr, cimp_efc cp, COORD **cor, BOOL *et){
	COORD *temp;
	COORD cori={102,6};
	BYTE prm;
	if(*et){
		temp=*cor;
		prm=rand()%(_msize(*cor)/sizeof(temp[0]));
		switch(A[temp[prm].Y][temp[prm].X].a){
			case 0:		
				_cls(52,12,89,18,0);SetColor(15,0); GotoXY(65,13);puts("nu ma nimerit");
				col_cel((temp[prm].X-1)*2*patr.m_patr+cori.X,(temp[prm].Y-1)*patr.m_patr+cori.Y,patr.m_patr,cp.col6.background);
		    	for(int i=prm+1;i<_msize(*cor)/sizeof(temp[0]);i++){
					temp[i-1].X=temp[i].X;
		    		temp[i-1].Y=temp[i].Y;
		    	}
		    	temp=realloc(temp,_msize(*cor)-sizeof(temp[0]));
		    	*cor=temp;   
		    	return 0;
			case 1:
				*(A[temp[prm].Y][temp[prm].X].link)-=1;
				if(*A[temp[prm].Y][temp[prm].X].link==0){
					_cls(52,12,89,18,0);SetColor(15,0);  GotoXY(65,13);puts("am distrus corabia");
					A[temp[prm].Y][temp[prm].X].a=3;
					zona(A,temp[prm].X,temp[prm].Y);
					zona2(A,cori,temp[prm].X,temp[prm].Y,patr.m_patr,cp.col5);
					free(temp); *cor=(COORD*)malloc(sizeof(COORD)); *et=0;
					return 3;
				}
				else{
					_cls(52,12,89,18,0);SetColor(15,0);  GotoXY(65,13);puts(" am ranit corabia");
					A[temp[prm].Y][temp[prm].X].a=2;
					col_cel((temp[prm].X-1)*2*patr.m_patr+cori.X,(temp[prm].Y-1)*patr.m_patr+cori.Y,patr.m_patr,cp.col4.background);
					el_var(A,cor,prm,patr.dim);
                    return 2;
				}
		}
	}
	else{
		switch(cercetare(A,*cor,patr.dim)){
			case 0:
				_cls(52,12,89,18,0);SetColor(15,0); GotoXY(65,13); printf(" nu am nimerit");
				col_cel(((*cor)->X-1)*2*patr.m_patr+cori.X,((*cor)->Y-1)*patr.m_patr+cori.Y,patr.m_patr,cp.col6.background);
				return 0;
			case 2:
				_cls(52,12,89,18,0);SetColor(15,0); GotoXY(65,13); printf(" am ranit corabia");
				col_cel(((*cor)->X-1)*2*patr.m_patr+cori.X,((*cor)->Y-1)*patr.m_patr+cori.Y,patr.m_patr,cp.col4.background);
				comp(A,cor,patr.dim);*et=1;
				return 2;
			case 3:
				_cls(52,12,89,18,0);SetColor(15,0); GotoXY(65,13); printf(" am distrus corabia");
				col_cel(((*cor)->X-1)*2*patr.m_patr+cori.X,((*cor)->Y-1)*patr.m_patr+cori.Y,patr.m_patr,cp.col5.background);
				return 3;
		}	
	}
}

void game(car_patr patr,cimp_efc cp){
	cimp** A,**B;
	BOOL et=0; 
	BYTE nr_corU=0, nr_corC=0;
	COORD **var_pos,cor={1,1};
	var_pos=(COORD**)malloc(sizeof(COORD*));
	*var_pos=(COORD*)malloc(sizeof(COORD));
	BYTE nr_misc=0;
	BYTE nr_var;
	A=(cimp**)malloc((patr.dim+2)*sizeof(cimp*));
	for(int i=0;i<patr.dim+2;i++)A[i]=(cimp*)malloc((patr.dim+2)*sizeof(cimp));
	B=(cimp**)malloc((patr.dim+2)*sizeof(cimp*));
	for(int i=0;i<patr.dim+2;i++)B[i]=(cimp*)malloc((patr.dim+2)*sizeof(cimp));
	for(int i=0;i<_msize(patr.cor)/sizeof(patr.cor[0]);i++){
		nr_corU+=patr.cor[i].nr_cor;  	
	}
	nr_corC=nr_corU;
	if(intr_cor(A,patr,cp)==1) goto iesire;
	intr_ran(B,patr,cp);
	_cls(0,1,200,100,0);
	afisare(1,4,patr,cp,B,0);
	afisare(100,4,patr,cp,A,1);
	rama(50,10,10,40,4);
	FILE *fp=fopen("file.txt","w");fclose(fp);	
	do{
		GotoXY(51,11);SetColor(15,0); puts("mersul    jucatorului");
		do{
			nr_misc++;
			switch(gcu(B,&cor,patr,cp)){
				case 3: 
 					if(--nr_corC==0){
						_cls(52,12,89,18,0);GotoXY(51,13);SetColor(15,0); puts("Felicitari, Ati cisitgat");_getch();Sleep(1000);
						write_player(nr_misc,patr.dim);
						goto iesire;
					}
					break;
				case 0: goto do1;
				case 27: goto iesire;
			}
		}while(1);
		do1:;
		GotoXY(51,11);SetColor(15,0); puts("mersul computatorului");
		Sleep(200);
		do{
			switch(gcc(A,patr,cp,var_pos,&et)){
				case 3: 
					if(--nr_corU==0){
						_cls(52,12,89,18,0);GotoXY(51,13);SetColor(15,0); puts("Din pacate ati pierdut");_getch();
						goto iesire;
					}
					break;
				case 0: goto do2;
			}
			Sleep(200);
		}while(1);
		do2:;
	}while(1);
	iesire:
	free(*var_pos);free(var_pos);
	for(int i=0;i<patr.dim+2;i++){
		free(A[i]);
	}
	free(A);A=NULL;
	et=1;
	for(int i=0;i<patr.dim+2;i++){
		free(B[i]);
	}
	free(B);B=NULL;
}