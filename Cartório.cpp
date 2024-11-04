#include <stdio.h> //biblioteca de comunicaçâo com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() // Função responsável por cadastrar usuários no sistema
{
	//início da criação de variáveis//string
	char arquivo[40]; 
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação das variáveis 

    printf("Digite o CPF a ser cadastrado: "); //coletando informaçôes
    scanf("%s" , cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //responsável por copiar os valores das strings
     
    FILE *file; //Cria o arwuivo no banco de dados 
    file = fopen(arquivo, "w"); //Cria o arquivo
    fprintf(file,cpf); //salvo o valor da variável
    fclose(file); //fecho o arquivo
    
    file = fopen(arquivo,"a"); //Comando de abertura de dados
    fprintf(file, ","); //Comando de vírgula no sitema 
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s" ,nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo,"a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s" ,sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo,"a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado:");
    scanf("%s" ,cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
}

int consulta() // Início das consultas de usuários 
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	
    char cpf[40]; // CPF a ser consultado
    char conteudo[200]; // Conteúdo a ser consultado 
    
    printf(" Digite o CPF a ser consultado "); //local para inserir usuário a ser consultado 
    scanf("%s" , cpf); 
    
    FILE *file;
    file = fopen(cpf, "r"); //Revisão de CPF do usuário
    
    if(file== NULL)
    {
    	printf("Não foi possível abrir o arquivo, não localizado! \n"); //Informção de erro na localização do usuário 
	}

    while(fgets(conteudo, 200, file) != NULL)
    { 
       printf("\nEssas são as informações do usuário ");
       printf("%s" , conteudo);
       printf("\n\n" );
	}
	
	
    system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado ");
	scanf("%s" ,cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
	   printf("O usuário não se encontra no sistema ! \n");
	   system("pause");
	}
	
}

int main()
   {
	int opcao=0; //Definindo Variáveis
	int laco=1;
	
	for(laco=1;laco=1; )
	{
		
		system("cls");

	    setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
		
	    printf("###Cartório da EBAC### \n\n"); //Início do menu 
	    printf("Escolha as opção desejada do menu: \n\n");
	    printf("\t1 - Registrar nomes \n");
        printf("\t2 - Consultar nomes \n");
        printf("\t3 - Deletar nomes \n\n"); 
        printf("\t4 - Sair do Sistema \n\n");
		 //Fim do meu programa
    
    scanf("%d" , &opcao); // Armazenando escolha do usuário
    
    system("cls");
    
    
    switch(opcao) //início da seleção
    {
    	case 1:
        registro();
    	break;
    	
    	case 2:
    	consulta();
    	break;
    	
    	case 3:
        deletar();
     	break;
     	
     	default:
     	printf("Essa opção não está disponível\n");
        system("pause");
        break;
        
        case 4:
        printf("Obrigado por utilizar nosso sistema_\n");
        return 0;
        break;
        system("pause");
       
        
	} // Fim de seleção 
   
    
}		  
}
 
    
