#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() // Fun��o respons�vel por cadastrar usu�rios no sistema
{
	//in�cio da cria��o de vari�veis//string
	char arquivo[40]; 
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o das vari�veis 

    printf("Digite o CPF a ser cadastrado: "); //coletando informa��es
    scanf("%s" , cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
     
    FILE *file; //Cria o arwuivo no banco de dados 
    file = fopen(arquivo, "w"); //Cria o arquivo
    fprintf(file,cpf); //salvo o valor da vari�vel
    fclose(file); //fecho o arquivo
    
    file = fopen(arquivo,"a"); //Comando de abertura de dados
    fprintf(file, ","); //Comando de v�rgula no sitema 
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

int consulta() // In�cio das consultas de usu�rios 
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	
    char cpf[40]; // CPF a ser consultado
    char conteudo[200]; // Conte�do a ser consultado 
    
    printf(" Digite o CPF a ser consultado "); //local para inserir usu�rio a ser consultado 
    scanf("%s" , cpf); 
    
    FILE *file;
    file = fopen(cpf, "r"); //Revis�o de CPF do usu�rio
    
    if(file== NULL)
    {
    	printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n"); //Inform��o de erro na localiza��o do usu�rio 
	}

    while(fgets(conteudo, 200, file) != NULL)
    { 
       printf("\nEssas s�o as informa��es do usu�rio ");
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
	   printf("O usu�rio n�o se encontra no sistema ! \n");
	   system("pause");
	}
	
}

int main()
   {
	int opcao=0; //Definindo Vari�veis
	int laco=1;
	
	for(laco=1;laco=1; )
	{
		
		system("cls");

	    setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
		
	    printf("###Cart�rio da EBAC### \n\n"); //In�cio do menu 
	    printf("Escolha as op��o desejada do menu: \n\n");
	    printf("\t1 - Registrar nomes \n");
        printf("\t2 - Consultar nomes \n");
        printf("\t3 - Deletar nomes \n\n"); 
        printf("\t4 - Sair do Sistema \n\n");
		 //Fim do meu programa
    
    scanf("%d" , &opcao); // Armazenando escolha do usu�rio
    
    system("cls");
    
    
    switch(opcao) //in�cio da sele��o
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
     	printf("Essa op��o n�o est� dispon�vel\n");
        system("pause");
        break;
        
        case 4:
        printf("Obrigado por utilizar nosso sistema_\n");
        return 0;
        break;
        system("pause");
       
        
	} // Fim de sele��o 
   
    
}		  
}
 
    
