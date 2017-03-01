#include "mboi.h"

void reguli(cimp_efc cp){
	cimp **A;
	A=(cimp**)malloc((10+2)*sizeof(cimp*));
	for(int i=0;i<10+2;i++)
		A[i]=(cimp*)malloc((10+2)*sizeof(cimp));
	for(int i=0;i<12;i++) 
		for(int j=0;j<12;j++) 
			A[i][j].a=0;
	A[2][2].a=A[3][2].a=A[4][2].a=A[7][2].a=A[8][2].a=A[9][2].a=A[2][5].a=A[3][5].a=A[4][5].a=A[5][5].a=
	A[7][5].a=A[8][5].a=A[2][8].a=A[3][8].a=A[6][8].a=A[7][8].a=A[9][8].a=A[1][10].a=A[4][10].a=A[7][10].a=1;
	SetColor(15,0);
	GotoXY(50,2);puts("Regulile Jocului \"Batalia Navala\"\n\n");
	puts("\t* In acest joc participa 2 adversari");
	puts("\t* Fiecare adversar are la dispozitie un cimp de dimensiunea NxN");
	puts("\n\t\tIn regulile clasice ale jocului N=10\n");
	puts("\t* Advesrarii se inteleg inaintea jocului asupra sistemului de coordanate ce va fi utilizat in joc");
	puts("\n\t\tIn aceasta versiune Jocului de coordonate este urmatorul:");
	puts("\t\t\tX={A..J}\n\t\t\tY={10..1}\n");
	init_cimp(120,10,10,0,15,1,4);SetColor(15,0);
	puts("\n\t* Ulterior fiecare adversar isi pregateste cimpul pozitionindcorabiile sale pe cimp");
	puts("\n\t* O corabie nu trebuie sa se atinga de alta corabie pe muchii sau pe colturi");
	puts("\n\t\tNumarul de corabii care necesita sa fie puse pe cimp depinde de dimesiunea cimpul N");
	puts("\n\t\tIn regulile clasice ale jocului, pentru un cimp de dimesiunea N=10, numarul de corabii este egal 10");
	puts("\n\t\tIn regulile clasice ale jocului, pentru un cimp de dimesiunea N=10, adversarii au urmatoarele tipuri de corabii:");
	printf("\n\t\t\tnr. de cor=4  dimesiunea=1  "); SetColor(0,15);puts("  ");SetColor(15,0);
	printf("\n\t\t\tnr. de cor=3  dimesiunea=2  "); SetColor(0,15);puts("    ");SetColor(15,0);
	printf("\n\t\t\tnr. de cor=2  dimesiunea=3  "); SetColor(0,15);puts("      ");SetColor(15,0);
	printf("\n\t\t\tnr. de cor=1  dimesiunea=4  "); SetColor(0,15);puts("        ");SetColor(15,0);
	init_cimp(120,31,10,0,15,1,4);SetColor(15,0);
	for(BYTE i=1;i<11;i++){
		for(BYTE j=1;j<11;j++){
			if(A[i][j].a==1) col_cel(j*2+120,i+32,1,3);
		}   
	}
	GotoXY(0,44);SetColor(15,0);
	puts("\n\t* Sarcina jocului consta in distugerea corabiilor adversarului");
	puts("\t* Dupa ce corabiile au fost pozitionate jucatorii pe rind fac <<impuscaturi>> in cimpul adversarului numind pe rind coordonatele patratelulu: A1, C5, J4...");
	puts("\t* Daca aceasta patratica contine o corabie sau o parte din corabia a adversarului, patratica se marcheaza, \n\t  adversarul fiind obligat sa spuna <<ranit>> sau <distrus>>, jucatorul continuind sa faca impuscaturi in cimpul advers");
	puts("\t* Daca aceasta patratica este goala, ea obtine un marcaj special. Dreptul de a ochi trece la urmatorul jucator");
	puts("\t* Jocul se va finisa cind toate corabiile unui jucator vor fi scufundate");
	_getch(); _cls(0,1,200,70,0);
}