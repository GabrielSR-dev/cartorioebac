#include<stdio.h>  //biblioteca de comunicação com o usuário
#include<stdlib.h> //biblioteca de alocação de espaço de memória
#include<locale.h> //biblioteca de alocações de texto por região 
#include<string.h> //biblioteca responsável por cuidar das strings
int registro() //função resposável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/strings
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variáveis/strings
    
    printf("digite o cpf a ser cadastrado:"); //coletando informações dos usuários
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); // resposável por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); //salva o valor da variável
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" atualiza
	fprintf(file, ","); //adiciona "," após cada variável/dado apresentado
	fclose(file);//fecha o arquivo
	 
	 printf("digite o nome a ser cadastrado:");//coletando informações dos usuários
	 scanf("%s", nome); //%s refere-se a string
	 
	 file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza
	 fprintf(file,nome); //salva o valor da variável
	 fclose(file);//fecha o arquivo
	 
	 file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza
     fprintf(file, ",");//adiciona "," após cada variável apresentada
	 fclose(file);//fecha o arquivo
	 
	 printf("digite o sobrenome a ser cadastrado:");//coletando informações dos usuários
	 scanf("%s", sobrenome);//%s refere-se a string
	 
	 file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza
	 fprintf(file,sobrenome); //salva o valor da variável
	 fclose(file);//fecha o arquivo
	 
	 file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza
	 fprintf(file, ",");//adiciona "," após cada variável apresentada
	 fclose(file);//fecha o arquivo
	 
	 printf("digite o cargo a ser cadastrado:");//coletando informações dos usuários
	 scanf("%s", cargo);//%s refere-se a string
	 
	 file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza
	 fprintf(file,cargo); //salva o valor da variável
	 fclose(file);//fecha o arquivo
	 
	 system("pause");//pausa a ação para que o usuário tenha tempo para ler e decidir
	
	
	


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
		printf("não foi possível abrir o arquivo, não localizado \n");
	}	
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nessas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");//pausa a ação para que o usuário tenha tempo para ler e decidir
}

int deletar()
{
	char cpf[40];
	
	printf("digite o cpf do usuário a ser deletado:");
	scanf("%s", cpf);
	
	remove (cpf);
	
	FILE *file;
	file = fopen (cpf,"r");
	
	if(file == NULL);
	{
		printf("o usuário não se encontra no sistema! \n");
		system("pause");//pausa a ação para que o usuário tenha tempo para ler e decidir
		
	}
	
	
}


int main()
{
    	int opcao=0; //definindo variáveis
    	int laco=1;
    	for(laco=1;laco=1;)
	{

        system("cls"); //responsável por limpar a tela
		
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem

       	printf("##### CARTÓRIO DA EBAC #####\n\n"); //início do menu 
	    printf("escolha a opção desejada no menu:\n\n");
     	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
    	printf("\t4 - sair do sistema \n\n");
    	printf("opção: "); //fim do menu
	
      	scanf("%d", &opcao); // armazenando a escolha do usuário
	
    	system("cls");//responsável por limpar a tela
    	
    	switch(opcao) //início da seleção
    	{
    		case 1:
    	    registro(); //chamada de funções
    	    break;
    	
    	    case 2:
        	consulta(); //chamada de funções
		   break;
 
 	       case 3:
		   	deletar(); //chamada de funções
		   break;
		   
	       case 4:
	       	printf("obrigado por utilizar o sistema ");
	       	return 0;
	       	break;
	    
	   
	       default:
		printf("essa opção não está disponível!\n");
		system("pause");//pausa a ação para que o usuário tenha tempo para ler e decidir
		break;
		//fim da seleção
	      	
		}	
	}
		
} 
