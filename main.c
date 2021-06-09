#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <windows.h>

int  num, quant, resul, soma=0,somaRM=0,contas, loop=1,media,mediaTT, ano = 0, mes =1;
float quantS=0,quantA=0,quantB=0,quantC=0,quantD=0,quantE=0,quantF=0,somaRank=0;
float porS=0,porA=0,porB=0,porC=0,porD=0,porE=0,porF=0,porsomaRank=0;
float ecoNivel=1,mult;
char nivel, comand;
double dinheiro =  0, 
	sal = 1,                                                    // 1000 = 1 lata
	lata = 1,                                                   // 1000 = 1 ferro
	ferro = 1,                                                  // 1000 = 1 prata
	prata = 1,                                                  // 1000 = 1 ouro
	ouro = 1,                                                   // 1000 = 1 platina
	platina = 1,                                                // 1000 = 1 cristal
	diamante = 1,                                               // 1000 = 10 credito
	credito = 1,                                                // 1000 = 1 quantum
	quantum = 1,
	//multiplicadores
	multsal = 1,
	multlata = 2,
	multferro = 3,
	multprata = 4,
	multouro = 5,
	multplatina = 6,
	multdiamante = 7,
	multcredito = 8,
	multquantum = 9;
char tendencia[100];


void era(){
	if(mes>=12){
		ano = ano +1;
		mes = 0;
	}
	mes = mes + 1;
	switch(mes){
		case 1:
			strcpy(tendencia,"Sal     ");
			multsal = multsal + 1;
			multquantum = multquantum - 1;
			break;
		case 2:
			strcpy(tendencia,"Sal     ");
			multsal = multsal + 1;
			multsal = multsal - 1;
			break;
		case 3:
			strcpy(tendencia,"Sal     ");
			multsal = multsal + 1;
			multsal = multsal - 1;
			break;
		case 4:
			strcpy(tendencia,"Lata    ");
			multlata = multlata + 1;
			multsal = multsal - 1;
			break;
		case 5:
			strcpy(tendencia,"Lata    ");
			multlata = multlata + 1;
			multlata = multlata - 1;
			break;
		case 6:
			strcpy(tendencia,"Ferro   ");
			multferro = multferro + 1;
			multlata = multlata - 1;
			break;
		case 7:
			strcpy(tendencia,"Prata   ");
			multprata = multprata + 1;
			multferro = multferro - 1;
			break;
		case 8:
			strcpy(tendencia,"Ouro    ");
			multouro = multouro + 1;
			multprata = multprata - 1;
			break;
		case 9:
			strcpy(tendencia,"Platina ");
			multplatina = multplatina + 1;
			multouro = multouro - 1;
			break;
		case 10:
			strcpy(tendencia,"Diamante");
			multdiamante = multdiamante + 1;
			multplatina = multplatina - 1;
			break;
		case 11:
			strcpy(tendencia,"Credito ");
			multcredito = multcredito + 1;
			multdiamante = multdiamante - 1;
			break;
		case 12:
			strcpy(tendencia,"Quantum ");
			multquantum = multquantum + 1;
			multcredito = multcredito - 1;
			break;
	}
	_sleep(50);
}

void moedas(){
	//SAL
	sal = sal + (ecoNivel/quantum*multsal);
	//LATA
	lata = lata + (ecoNivel/credito*multlata);
	//FERRO
	ferro = ferro + (ecoNivel/diamante*multferro);
	//PRATA
	prata = prata + (ecoNivel/platina*multprata);
	//OURO
	ouro = ouro + (ecoNivel/ouro*multouro);
	//PLATINA
	platina = platina + (ecoNivel/prata*multplatina);
	//DIAMANTE
	diamante = diamante + (ecoNivel/ferro*multdiamante);
	//CREDITO
	credito = credito + (ecoNivel/lata*multcredito);
	//QUANTUM
	quantum = quantum + (ecoNivel/sal*multquantum);
	//VALOR TOTAL MERCADO
	dinheiro = sal + lata + ferro + prata + ouro + platina + diamante + credito + quantum;
}

//MUDA A POSIÇÃO DO CURSOR DO CONSOLE
void gotoxy(int x,int y){
	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}
//ESCONDER CURSOR DO CONSOLE
void HideCursor(){
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

int dados(int num, int quant){
	srand(time(NULL));
	soma = 0;
	somaRM = 0;
	mediaTT = 0;
	for(int i=1;i<=quant;i++){
		resul = rand() % num+1;
		media = 0;
		//resul = 7; // para teste 100% rank S
		if(resul==0){
			resul=1;
		}
		if(soma>=0){
			nivel='F';
		}
		if(soma>=2){
			nivel='E';
		}
		if(soma>=3){
			nivel='D';
		}
		if(resul>=4){
			nivel='C';
		}
		if(resul>=5){
			nivel='B';
		}
		if(resul>=6){
			nivel='A';
		}
		if(resul==7){
			nivel='S';
		}
		switch(nivel){
			case 'F':
				somaRM = somaRM - 3;
				media = -3;
				break;
			case 'E':
				somaRM = somaRM - 2;
				media = -2;
				break;
			case 'D':
				somaRM = somaRM - 1;
				media = -1;
				break;
			case 'C':
				somaRM = somaRM + 0;
				media = 0;
				break;
			case 'B':
				somaRM = somaRM + 1;
				media = 1;
				break;
			case 'A':
				somaRM = somaRM + 2;
				media = 2;
				break;
			case 'S':
				somaRM = somaRM + 3;
				media = 3;
				break;
		}
		mediaTT = mediaTT + media;
		printf("dado - %d : %d - Rank:%c (%d)  \n",i,resul,nivel,media);
		soma = soma + resul;
		_sleep(10);
	}
	somaRM = somaRM/quant;
	switch(somaRM){
		case -3:
			nivel='F';
			break;
		case -2:
			nivel='E';
			break;
		case -1:
			nivel='D';
			break;
		case 0:
			nivel='C';
			break;
		case 1:
			nivel='B';
			break;
		case 2:
			nivel='A';
			break;
		case 3:
			nivel='S';
			break;
	}
	printf("\nsoma dos dados : %d/%d - Rank:%c(%d) | (Soma:%d)  \n\n",soma,num*quant,nivel,somaRM,mediaTT);
	era();
	switch(nivel){
		case 'F':
			mult = -3;
			ecoNivel = ecoNivel-3;
			quantF++;
			break;
		case 'E':
			mult = -2;
			ecoNivel = ecoNivel-2;
			quantE++;
			break;
		case 'D':
			mult = -1;
			ecoNivel = ecoNivel-1;
			quantD++;
			break;
		case 'C':
			mult = 0;
			ecoNivel = ecoNivel/1.25;
			quantC++;
			break;
		case 'B':
			mult = 1;
			ecoNivel = ecoNivel+1;
			quantB++;
			break;
		case 'A':
			mult = 2;
			ecoNivel = ecoNivel+2;
			quantA++;
			break;
		case 'S':
			mult = 3;
			ecoNivel = ecoNivel+3;
			quantS++;
			break;
	}
	somaRank=quantS+quantA+quantB+quantC+quantD+quantE+quantF;
	porsomaRank=porS+porA+porB+porC+porD+porE+porF;
	porF=(quantF/somaRank)*100;
	porE=(quantE/somaRank)*100;
	porD=(quantD/somaRank)*100;
	porC=(quantC/somaRank)*100;
	porB=(quantB/somaRank)*100;
	porA=(quantA/somaRank)*100;
	porS=(quantS/somaRank)*100;
	_sleep(5);
	return soma;
}

int main(){
	system("color a");
	system("Title Sistema de Economia BETA v0.01");
	while(loop=1){
		/*if(kbhit()){
		}*/
		//while(!kbhit()){}
		gotoxy(60,0);
		printf("Data atual: 30 / %d / %d | Tendencia: %s    ",mes,ano,tendencia);
		gotoxy(60,1);
		printf("----------------------------------------");
		gotoxy(60,2);
		printf("multiplicador:%.0f | Ultimo rank: %c ",mult, nivel);
		gotoxy(60,3);
		printf("Fluxo: %.10f                       ",ecoNivel);
		gotoxy(60,4);
		printf(" UBM: $%.2f                        ",dinheiro);
		gotoxy(60,5);
		printf("----------------------------------------");
		gotoxy(60,6);
		printf("S : %.0f (%.2f%%)      ",quantS,porS);
		gotoxy(60,7);
		printf("A : %.0f (%.2f%%)      ",quantA,porA);
		gotoxy(60,8);
		printf("B : %.0f (%.2f%%)      ",quantB,porB);
		gotoxy(60,9);
		printf("C : %.0f (%.2f%%)      ",quantC,porC);
		gotoxy(60,10);
		printf("D : %.0f (%.2f%%)      ",quantD,porD);
		gotoxy(60,11);
		printf("E : %.0f (%.2f%%)      ",quantE,porE);
		gotoxy(60,12);
		printf("F : %.0f (%.2f%%)      ",quantF,porF);
		gotoxy(60,13);
		printf("T : %.0f (%.2f%%)     ",somaRank,porsomaRank);
		gotoxy(60,14);
		printf("----------------------------------------");
		gotoxy(60,15);
		printf("Sal:       $ %.2f             ",sal);
		gotoxy(60,16);
		printf("Lata:      $ %.2f             ",lata);
		gotoxy(60,17);
		printf("Ferro:     $ %.2f             ",ferro);
		gotoxy(60,18);
		printf("Prata:     $ %.2f             ",prata);
		gotoxy(60,19);
		printf("Ouro:      $ %.2f             ",ouro);
		gotoxy(60,20);
		printf("Platina:   $ %.2f             ",platina);
		gotoxy(60,21);
		printf("Diamante:  $ %.2f             ",diamante);
		gotoxy(60,22);
		printf("Credito:   $ %.2f             ",credito);
		gotoxy(60,23);
		printf("Quantum:   $ %.2f            ",quantum);
		gotoxy(60,24);
		printf("----------------------------------------");
		gotoxy(0,0);
		dados(7,7);
		moedas();
	}
}
