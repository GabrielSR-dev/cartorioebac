#include<stdio.h>  //biblioteca de comunica��o com o usu�rio
#include<stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include<locale.h> //biblioteca de aloca��es de texto por regi�o 
#include<string.h> //biblioteca respons�vel por cuidar das strings
int registro() //fun��o respos�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/strings
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de vari�veis/strings
    
    printf("digite o cpf a ser cadastrado:"); //coletando informa��es dos usu�rios
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); // respos�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" atualiza
	fprintf(file, ","); //adiciona "," ap�s cada vari�vel/dado apresentado
	fclose(file);//fecha o arquivo
	 
	 printf("digite o nome a ser cadastrado:");//coletando informa��es dos usu�rios
	 scanf("%s", nome); //%s refere-se a string
	 
	 file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza
	 fprintf(file,nome); //salva o valor da vari�vel
	 fclose(file);//fecha o arquivo
	 
	 file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza
     fprintf(file, ",");//adiciona "," ap�s cada vari�vel apresentada
	 fclose(file);//fecha o arquivo
	 
	 printf("digite o sobrenome a ser cadastrado:");//coletando informa��es dos usu�rios
	 scanf("%s", sobrenome);//%s refere-se a string
	 
	 file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza
	 fprintf(file,sobrenome); //salva o valor da vari�vel
	 fclose(file);//fecha o arquivo
	 
	 file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza
	 fprintf(file, ",");//adiciona "," ap�s cada vari�vel apresentada
	 fclose(file);//fecha o arquivo
	 
	 printf("digite o cargo a ser cadastrado:");//coletando informa��es dos usu�rios
	 scanf("%s", cargo);//%s refere-se a string
	 
	 file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza
	 fprintf(file,cargo); //salva o valor da vari�vel
	 fclose(file);//fecha o arquivo
	 
	 system("pause");//pausa a a��o para que o usu�rio tenha tempo para ler e decidir
	
	
	


}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("n�o foi poss�vel abrir o arquivo, n�o localizado \n");
	}	
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nessas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");//pausa a a��o para que o usu�rio tenha tempo para ler e decidir
}

int deletar()
{
	char cpf[40];
	
	printf("digite o cpf do usu�rio a ser deletado:");
	scanf("%s", cpf);
	
	remove (cpf);
	
	FILE *file;
	file = fopen (cpf,"r");
	
	if(file == NULL);
	{
		printf("o usu�rio n�o se encontra no sistema! \n");
		system("pause");//pausa a a��o para que o usu�rio tenha tempo para ler e decidir
		
	}
	
	
}


int main()
{
    	int opcao=0; //definindo vari�veis
    	int laco=1;
    	for(laco=1;laco=1;)
	{

        system("cls"); //respons�vel por limpar a tela
		
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem

       	printf("##### CART�RIO DA EBAC #####\n\n"); //in�cio do menu 
	    printf("escolha a op��o desejada no menu:\n\n");
     	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
    	printf("\t4 - sair do sistema \n\n");
    	printf("op��o: "); //fim do menu
	
      	scanf("%d", &opcao); // armazenando a escolha do usu�rio
	
    	system("cls");//respons�vel por limpar a tela
    	
    	switch(opcao) //in�cio da sele��o
    	{
    		case 1:
    	    registro(); //chamada de fun��es
    	    break;
    	
    	    case 2:
        	consulta(); //chamada de fun��es
		   break;
 
 	       case 3:
		   	deletar(); //chamada de fun��es
		   break;
		   
	       case 4:
	       	printf("obrigado por utilizar o sistema ");
	       	return 0;
	       	break;
	    
	   
	       default:
		printf("essa op��o n�o est� dispon�vel!\n");
		system("pause");//pausa a a��o para que o usu�rio tenha tempo para ler e decidir
		break;
		//fim da sele��o
	      	
		}	
	}
		
} 
