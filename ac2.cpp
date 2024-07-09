//Autores: Cainã RA:210626, Leandro RA:203399, Nelson RA:211916 e waldir RA:145102
//data:30/05/2022

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<ctype.h>

char sair,op, aux;
int opcalc;
int tm;
void menu1();
void menu2();
void calculoEscada();
void espacamentoUniforme();
void quantidadeTijolos();
void recorte();
void agradecimento();
void saircalc();


int main() {
	// mensagem inicial
	printf("\n\t\tOla! Bem vindo a calculadora beta para construcao!\n");
	printf("\n\n\t\tPressione qualquer tecla para continuar!");
	getch();
	system("cls");
	do{
		menu1();
		
		do{ //menu
			menu2();
			
			switch(opcalc){
				case 49: //calculo de escada
					system("cls");
					calculoEscada();
					break;
				
				case 50: // espacamento uniforme
					system("cls");
					espacamentoUniforme();
					break;
				
				case 51:// quantidade de tijolos
					system("cls");
					quantidadeTijolos();
					break;

				case 52://Otimização
					system("cls");
					recorte();
					break;
				
				case 53://sair
					system("cls");
					agradecimento();
					getch();
					exit(0);
					break;
					
				default:
					printf("\n\n\t----------------------------------------- \n");
					printf("\t      Opcao invalida!Digite novamente.\n");
					printf("\t----------------------------------------- \n\n");
					
			}
			
		}while(opcalc < 49 || opcalc > 53);
	
		//sair do programa
		
		saircalc();
		
	}while(sair != 'n');
	system("cls");
	agradecimento();
	getch();
	 
	return(0);
}

void menu1(){
	printf("\t----------------------------------------- \n");
	printf("\t|\t\t Menu\t\t\t|\n");
	printf("\t|---------------------------------------| \n");
	printf("\t|\t[1]-Calculo de escada.\t\t|\n\t|\t[2]-Espacamento Uniforme.\t|\n\t|\t[3]-Quantidade de Tijolos.\t|\n\t|\t[4]-Recorte.\t\t\t|\n\t|\t[5]-Sair.\t\t\t|\n");
	printf("\t|---------------------------------------| \n");

}

void menu2(){

	printf("\t\tDigite a opcao desejada:");
	scanf(" %c",&aux);
	opcalc = (int)aux;
}

//1
void calculoEscada(){
	float matriz[2][3];
	do{
		//inicio da parte 1
		printf("\t\t\tCalculo da Escada\n");
		printf("\t----------------------------------------------------- \n");
		printf("\n\t  Digite o tamanho do degrau (cm): ");
		scanf("%f",&matriz[0][0]);//td
		printf("\n\t  Digite a altura de um pavimento ao outro (cm): ");
		scanf("%f",&matriz[0][1]); //h
		
		//e = (64-td)/2;
		matriz[1][0] = (64 - matriz[0][0])/2;
		
		//ne = h/e;
		matriz[1][1] = matriz[0][1]/matriz[1][0];
		
		//np = ne -1;
		matriz[1][2] = matriz[1][1] - 1;
		
		printf("\n\t----------------------------------------------------- \n");
		printf("\t\t\t    Resultado.\n");
		printf("\n\t  Tamanho do Espelho: %.2f cm\t\t\t",matriz[1][0]); //e
		printf("\n\t  Numero de Espelhos: %.2f ",matriz[1][1]); //ne
		printf("\n\t  Numero de Pisos: %.2f \n\n",matriz[1][2]); //np
		printf("\t----------------------------------------------------- \n");
		//fim parte 1
		
		do{
		
			printf("\t\t   Deseja calcular novamente? s/n\n\t\t   ");
			scanf(" %c",&op);
			if(op != 's' && op != 'n'){
				printf("\n\t----------------------------------------------------- ");
				printf("\n\t\tOpcao invalida! Digite novamente.\n\n");
				printf("\t----------------------------------------------------- \n\n");
			}
		}while(op != 's' && op != 'n');
		if(op != 'n'){
			system("cls");
		}
		system("cls");
		}while(op != 'n');
	
}

//2
void espacamentoUniforme(){
	
	float matriz[3][3];
	do{
		//inicio da parte 2
		printf("\t\t\t\t    Espacamento Uniforme!");
		printf("\n\t------------------------------------------------------------------------------ \n");
		printf("\n\t\tDigite a Largura media dos Componentes (cm):");
		scanf(" %f",&matriz[0][0]); //w
		printf("\n\t\tDigite o Numero de Componentes (unidades):");
		scanf(" %f",&matriz[0][1]); //n
		printf("\n\t\tDigite o Comprimento total da Instalacao (cm):");
		scanf(" %f",&matriz[0][2]); //ti
		
		//at = w * n
		matriz[1][0] = matriz[0][0] * matriz[0][1];
		
		//ta = ti - at
		matriz[1][1] = matriz[0][2] - matriz[1][0];
		
		//ws = ta/(n-1)
		matriz[1][2] = matriz[1][1]/(matriz[0][1] - 1);
		
		//fe = ws + (w/2)
		matriz[2][0] = matriz[1][2] + (matriz[0][0] / 2);
		
		printf("\n\t------------------------------------------------------------------------------ \n");
		printf("\t\t\t\t\t  Resultado.\n");
		printf("\n\t\tEspessura Total dos Componentes: %.3f cm",matriz[1][0]); //at
		printf("\n\t\tEspaço vazio total entre todos os Componentes: %.3f cm",matriz[1][1]); //ta
		printf("\n\t\tLargura de cada espaco entre os Componentes: %.3f cm",matriz[1][2]); //ws
		printf("\n\t\tDistância da primeira borda ao centro do primeiro Componente: %.3f cm",matriz[2][0]); //fe
		printf("\n\t\tCentro a centro de cada Componentes: %.3f cm\n\n",matriz[2][0]); //fe
		printf("\n\t------------------------------------------------------------------------------ \n");
	
		//fim parte 2
		
		do{
			printf("\t\t\t\t Deseja calcular novamente? s/n\n");
			scanf(" %c",&op);
			if(op != 's' && op != 'n'){
				printf("\n\t------------------------------------------------------------------------------ ");
				printf("\n\t\t\t\tOpcao invalida! Digite novamente.\n");
				printf("\t------------------------------------------------------------------------------ \n\n");
			}
		}while(op != 's' && op != 'n');
		if(op != 'n'){
			system("cls");
		}
		system("cls");
	}while(op != 'n');

}

//3
void quantidadeTijolos(){
		float matriz[3][6];
	do{
		//inicio da parte 3
		printf("\t\t    Quantidade de Tijolos.\n\n");
		printf("\t-------------------------------------------------- \n");
		printf("\n\t  Digite o comprimento do muro em (m):");
		scanf(" %f",&matriz[0][0]); //c
		printf("\n\t  Digite a altura (pe direito) do muro em (m):");
		scanf(" %f",&matriz[0][1]); //al
		printf("\n\t  Digite a quantidade de janelas(un):");
		scanf(" %f",&matriz[0][2]); //nj
		printf("\n\t  Digite a altura das janelas (m):");
		scanf(" %f",&matriz[0][3]); //alj
		printf("\n\t  Digite a comprimento das janelas (m):");
		scanf(" %f",&matriz[0][4]); //cj
		printf("\n\t  Digite a quantidade de portas(un):");
		scanf(" %f",&matriz[0][5]); //np
		printf("\n\t  Digite a altura das portas (m):");
		scanf(" %f",&matriz[1][0]); //alp
		printf("\n\t  Digite a comprimento das portas (m):");
		scanf(" %f",&matriz[1][1]); //cp
		printf("\n\t  Digite a altura do tijolo (m):");
		scanf(" %f",&matriz[1][2]); //alt
		printf("\n\t  Digite a comprimento do tijolo (m):");
		scanf(" %f",&matriz[1][3]); //ct
		
		//apb = c * al;
		matriz[2][0] = matriz[0][0] * matriz[0][1];
		
		//aj = nj * (alj*cj);
		matriz[2][1] = matriz[0][2] * (matriz[0][3] * matriz[0][4]);
		
		//ap = np * (alp*cp);
		matriz[2][2] = matriz[0][5] * (matriz[1][0] * matriz[1][1]);
		
		//apl = apb - (aj+ap);
		matriz[2][3] = matriz[2][0] - (matriz[2][1] + matriz[2][2]);
		
		//ata = (ct + 0.01) * (alt + 0.01);
		matriz[2][4] = (matriz[1][3] + 0.01) * (matriz[1][2] + 0.01);
		
		//qt = apl / ata;
		matriz[2][5] = matriz[2][3] / matriz[2][4];
		
		printf("\t-------------------------------------------------- \n");
		printf("\t\t\tResultado.\n");
		printf("\n\t  Area bruta da Parede: %.3f m(quadrados)",matriz[2][0]); 	 //apb
		printf("\n\t  Area de Janelas: %.3f m(quadrados)",matriz[2][1]); 		 //aj
		printf("\n\t  Area de Portas: %.3f m(quadrados)",matriz[2][2]); 			 //ap
		printf("\n\t  Area Liquida da Parede: %.3f m(quadrados)",matriz[2][3]); 	 //apl
		printf("\n\t  Area do tijolo com argamassa: %.3f m(quadrados)",matriz[2][4]);	 //ata
		printf("\n\t  Quantidade de tijolos: %.3f (un)\n\n",matriz[2][5]); 	 //qt
		printf("\t-------------------------------------------------- \n");
		
			//fim parte 3
		do{
			printf("\t\tDeseja calcular novamente? s/n\n");
			scanf(" %c",&op);
			if(op != 's' && op != 'n'){
				printf("\n\t-------------------------------------------------- ");
				printf("\n\t\tOpcao invalida! Digite novamente.\n");
				printf("\t-------------------------------------------------- \n\n");
			}
		}while(op != 's' && op != 'n');
		if(op != 'n'){
			system("cls");
		}
		system("cls");
	}while(op != 'n');

}

//4
void recorte(){
	float al1, com1, al2, com2, a1, a2, af, sobra;
	int op, opM, opR;

	do{
		printf("\t\t    Formato do material que ira utilizar.\n");
		printf("\t--------------------------------------------------------- \n");
		printf("\t|\t\t[1]-Quadrado ou Retangulo.\t\t|\n\t|\t\t[2]-Triangulo.\t\t\t\t|\n\t|\t\t[3]-Circulo.\t\t\t\t|\n");
		printf("\t--------------------------------------------------------- \n");
		do{

			printf("\n\t   Digite o formato do material que ira utilizar:");
			scanf(" %c",&aux);
			
			opM = (int)aux;
			
			switch(opM){
				 case 49: //tipo quadrado ou retangulo
					printf("\n\t--------------------------------------------------------- \n");
					printf("\n\t\tQual a altura do material utilizado(m):");
					scanf(" %f",&al1);
					printf("\n\t\tQual o comprimento do material utilizado(m):");
					scanf(" %f",&com1);
					
					a1 = al1 * com1;
					break;
					
				case 50: //triangulo
					printf("\n\t--------------------------------------------------------- \n");
					printf("\n\t\tQual a altura do material utilizado(m):");
					scanf(" %f",&al1);
					printf("\n\t\tQual o comprimento do material utilizado(m):");
					scanf(" %f",&com1);
					
					a1 = (al1 * com1 )/ 2;
					break;
					
				case 51: //circulo
					printf("\n\t--------------------------------------------------------- \n");
					printf("\n\t\tQual o diametro do material utilizado(m):");
					scanf(" %f",&al1);
			 	 
					
					a1 = 3.14 *(pow((al1/2),2));
					
					break;
					
				default:
					printf("\n\t--------------------------------------------------------- ");
			    	printf("\n\t\tOpcao invalida!Digite novamente.");
			    	printf("\n\t--------------------------------------------------------- \n");
			}
		}while(opM < 49 || opM > 51);
		 	
		system("cls");
		printf("\n\t\t\tFormato que ira recortar\n");
		printf("\t------------------------------------------------------------------------- \n");
		printf("\t|\t\t\t[1]-Quadradro ou Retangulo.\t\t\t|\n\t|\t\t\t[2]-Triangulo.\t\t\t\t\t|\n\t|\t\t\t[3]-Circulo.\t\t\t\t\t|\n");
		printf("\t------------------------------------------------------------------------- \n");
		
		do{		
			printf("\n\t   Digite o formato do material que deseja recortar:");
			scanf(" %c",&aux);
			opR = (int)aux;
				
			
			switch(opR){
						
				case 49: //quadrado ou retangulo
					do{
						printf("\t------------------------------------------------------------------------- \n");
						printf("\n\t  Qual a altura que deseja para esse material de recorte(m):");
						scanf(" %f",&al2);
						printf("\n\t  Qual o comprimento que deseja do material para recorte(m):");
						scanf(" %f",&com2);
						
						a2 = al2 * com2;
		
						if(a2 > a1){
							printf("\t------------------------------------------------------------------------- \n");
							printf("\n\t\t\t\tImpossivel calcular!\n\t  Area do material para recorte maior que a do material utilizado!!");
							printf("\n\t\t\t\tDigite novamente.\n\n");
						}
						else{
							
							af = floor(a1 / a2);
							sobra = fmod(a1,a2);
							
							printf("\n\t------------------------------------------------------------------------- \n");
							printf("\n\t\tQuantidade de pecas recortadas: %.3f(un)",af);
							printf("\n\t\tSobra do material de recorte: %.3f",sobra);
							printf("\n\n\t------------------------------------------------------------------------- \n\n");
				    	}
					}while(a2 > a1);
					break;
				
				case 50: //triangulo
					do{
						printf("\t------------------------------------------------------------------------- \n");
						printf("\n\t  Qual a altura que deseja para esse material de recorte(m):");
						scanf(" %f",&al2);
						printf("\n\t  Qual o comprimento que deseja do material para recorte(m):");
						scanf(" %f",&com2);
			
						a2 = (al2 * com2)/2;
	
						if(a2 > a1){
							printf("\t------------------------------------------------------------------------- \n");
							printf("\n\t\t\t\tImpossivel calcular!\n\t  Area do material para recorte maior que a do material utilizado!!");
							printf("\n\t\t\tDigite novamente.\n");
						}
						
						else{
							af = floor(a1 / a2);
							sobra = fmod(a1,a2);
				
							printf("\n\t------------------------------------------------------------------------- \n");
							printf("\n\t\tQuantidade de pecas recortadas: %.3f(un)",af);
							printf("\n\t\tSobra do material de recorte: %.3f",sobra);
							printf("\n\n\t------------------------------------------------------------------------- \n\n");
		    			}
					}while(a2 > a1);
					break;
				case 51: //circulo
					do{
						printf("\t------------------------------------------------------------------------- \n");
						printf("\n\t  Qual o diametro que deseja para esse material de recorte(m):");
						scanf(" %f",&al2);
						
					
						a2 = 3.14 * (pow((al2/2),2));
	
						if(a2 > a1){
							printf("\t------------------------------------------------------------------------- \n");
							printf("\n\t\t\t\tImpossivel calcular!\n\t  Area do material para recorte maior que a do material utilizado!!");
							printf("\n\t\t\tDigite novamente.\n");
						}
						else{
							af = floor(a1 / a2);
							sobra = fmod(a1,a2);
							
							printf("\n\t------------------------------------------------------------------------- \n");
							printf("\n\t   O raio do circulo e: %f (m)", al2/2);
							printf("\n\t   Quantidade de pecas recortadas: %.3f (un)",af);
							printf("\n\t   Sobra do material de recorte: %.3f",sobra);
							printf("\n\n\t------------------------------------------------------------------------- \n\n");
					    	}
					}while(a2 > a1);
					break;
				default:
					printf("\t------------------------------------------------------------------------- \n");
			    	printf("\n\t\tOpcao invalida!Digite novamente.");
			    	printf("\t------------------------------------------------------------------------- \n");
			}
							
		}while(opR < 49 || opR > 51);
		
		do{
			printf("\n\t\tDeseja calcular novamente? s/n\n");
			scanf(" %c",&op);
			if(op != 's' && op != 'n'){
				printf("\n\t--------------------------------------------------------- ");
				printf("\n\t\tOpcao invalida! Digite novamente.\n");
				printf("\t--------------------------------------------------------- \n");
			}
		}while(op != 's' && op != 'n');
		if(op != 'n'){
			system("cls");
		}
		system("cls");
	}while(op != 'n');
}
	
	
void saircalc(){
	do{
		printf("\t\t\tDeseja continuar usando a calculadora? s/n\n\t\t");
		scanf(" %c",&sair);
		if(sair != 's' && sair != 'n'){
			printf("\t------------------------------------------------------------------------------ \n");
			printf("\t\t\tOpcao invalida! Digite novamente.\n");
			printf("\t------------------------------------------------------------------------------ \n\n");
		}
	}while(sair != 's' && sair != 'n');
		
	if(sair == 's'){
		system("cls");
	}
}


void agradecimento(){
	printf("\n\n\t\tObrigado por usar a calculadora beta de construcao!!\n\n");
	printf("\t\tPressione qualquer tecla para finalizar!");
}





