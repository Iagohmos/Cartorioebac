#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aaloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usuarios no sitema
{
	//Inicio da cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//Coletando inform��o do usuario
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Abre o arquivo, "w" signifa escrever
	fprintf(file,cpf); //Salva o valor da string
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo j� salvo para atualizar
	fprintf(file, ","); //Acrescenta a v�rgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //Abre o arquivo j� salvo para atualizar
	fprintf(file,nome); //Salva o valor da string
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo j� salvo para atualizar
	fprintf(file, ","); //Acrescenta a v�rgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //Abre o arquivo j� salvo para atualizar
	fprintf(file, sobrenome); //Salva o valor da string
	fclose(file); //Fecha o aarquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo j� salvo para atualizar
	fprintf(file, ","); //Acrescenta a v�rgula
	fclose(file); //Fecha o arquivo
		
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //Abre o arquivo j� salvo atualizar
	fprintf(file,cargo); //Salva o valor da string
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa o programa e aguarda o usu�rio apertar qualquer tecla para continuar
	
	
}

int consulta() //Fun��o responsavel por consultar os usu�rios
{
 	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
 	
	char cpf[40];
 	char conteudo[200]; 
 	
 	printf("Digite o CPF a ser consultado: ");
 	scanf("%s",cpf);
 	
 	FILE *file; //Cria o arquivo
 	file = fopen(cpf,"r"); //Abre o arquivo, "r" � ler o que tem no arquivo 
 	
 	if(file == NULL) //Analisa o que tem dentro do parantesis e executa o que tem dentro
 	{
 		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
 	
 	while(fgets(conteudo, 200, file) != NULL) //Estrutura de repeti��es
 	{
 		printf("\nEssas s�o as informa��es do usu�rio: ");
 		printf("%s", conteudo);
 		printf("\n\n");
	}
 	
 	system("pause"); //Pausa o programa e aguarda o usu�rio apertar qualquer tecla para continuar
}

int deletar() //Fun��o responsavel por deletar o usu�rio 
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Abre o arquivo "r" significa remove
	
	if(file == NULL) //Analisa o que tem dentro do parantesis e executa o que tem dentro
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause"); //Pausa o programa e aguarda o usu�rio apertar qualquer tecla para continuar
	}

	
}

int main() //Fun��o principal
    {
	int opcao=0; //Definindo variaveis 
	int laco=1; //Contador da Estrutura de repeti��es
	
	for(laco=1;laco=1;) //Estrutura de repeti��es
	{
		
		system("cls"); //Responsavel por limpar a tela

	    setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n"); 
	    printf("Op��o:  "); //Final do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usuario
	
	    system("cls"); //Respondavel por limpar a tela
	    
	    
	    switch(opcao) //Inicio da sele��o do menu
	    {
	    	case 1:
	    	registro(); //Chamada de fun��es
			break; //Encerra a execu��o do loop
			
			case 2:
			consulta(); //Chamada de fun��es
			break; //Encerra a execu��o do loop
			
			case 3:
			deletar(); //Chamada de fun��es
			break; //Encerra a execu��o do loop
			
			case 4:
			printf("Obrigado por ultilizar nosso sistema!\n");	
			return 0;
			break;
			
			default: 
			printf("Essa op��o n�o est� disponivel, por favor tente novamente!\n");
		    system("pause"); //Pausa o programa e aguarda o usu�rio apertar qualquer tecla para continuar
			break; //Encerra a execu��o do loop
		}
	
	    
}	
}
