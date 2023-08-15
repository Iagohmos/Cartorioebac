#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de aalocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuarios no sitema
{
	//Inicio da criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//Coletando informção do usuario
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Abre o arquivo, "w" signifa escrever
	fprintf(file,cpf); //Salva o valor da string
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo já salvo para atualizar
	fprintf(file, ","); //Acrescenta a vírgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //Abre o arquivo já salvo para atualizar
	fprintf(file,nome); //Salva o valor da string
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo já salvo para atualizar
	fprintf(file, ","); //Acrescenta a vírgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //Abre o arquivo já salvo para atualizar
	fprintf(file, sobrenome); //Salva o valor da string
	fclose(file); //Fecha o aarquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo já salvo para atualizar
	fprintf(file, ","); //Acrescenta a vírgula
	fclose(file); //Fecha o arquivo
		
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //Abre o arquivo já salvo atualizar
	fprintf(file,cargo); //Salva o valor da string
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa o programa e aguarda o usuário apertar qualquer tecla para continuar
	
	
}

int consulta() //Função responsavel por consultar os usuários
{
 	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
 	
	char cpf[40];
 	char conteudo[200]; 
 	
 	printf("Digite o CPF a ser consultado: ");
 	scanf("%s",cpf);
 	
 	FILE *file; //Cria o arquivo
 	file = fopen(cpf,"r"); //Abre o arquivo, "r" é ler o que tem no arquivo 
 	
 	if(file == NULL) //Analisa o que tem dentro do parantesis e executa o que tem dentro
 	{
 		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
 	
 	while(fgets(conteudo, 200, file) != NULL) //Estrutura de repetições
 	{
 		printf("\nEssas são as informações do usuário: ");
 		printf("%s", conteudo);
 		printf("\n\n");
	}
 	
 	system("pause"); //Pausa o programa e aguarda o usuário apertar qualquer tecla para continuar
}

int deletar() //Função responsavel por deletar o usuário 
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Abre o arquivo "r" significa remove
	
	if(file == NULL) //Analisa o que tem dentro do parantesis e executa o que tem dentro
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause"); //Pausa o programa e aguarda o usuário apertar qualquer tecla para continuar
	}

	
}

int main() //Função principal
    {
	int opcao=0; //Definindo variaveis 
	int laco=1; //Contador da Estrutura de repetições
	
	for(laco=1;laco=1;) //Estrutura de repetições
	{
		
		system("cls"); //Responsavel por limpar a tela

	    setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	    printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n"); 
	    printf("Opção:  "); //Final do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usuario
	
	    system("cls"); //Respondavel por limpar a tela
	    
	    
	    switch(opcao) //Inicio da seleção do menu
	    {
	    	case 1:
	    	registro(); //Chamada de funções
			break; //Encerra a execução do loop
			
			case 2:
			consulta(); //Chamada de funções
			break; //Encerra a execução do loop
			
			case 3:
			deletar(); //Chamada de funções
			break; //Encerra a execução do loop
			
			case 4:
			printf("Obrigado por ultilizar nosso sistema!\n");	
			return 0;
			break;
			
			default: 
			printf("Essa opção não está disponivel, por favor tente novamente!\n");
		    system("pause"); //Pausa o programa e aguarda o usuário apertar qualquer tecla para continuar
			break; //Encerra a execução do loop
		}
	
	    
}	
}
