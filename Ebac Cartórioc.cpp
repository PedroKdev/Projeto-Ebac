#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //para poder colocar o outro comando de baixo de assentos e @ e afins
#include <locale.h> //aloca��o de texto por regi�o
#include <string.h> //biblioteca das strings

int registro ()
{
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf ("Digite o cpf a ser cadastrado: ");
	scanf ("%s", cpf);
	
	strcpy (arquivo, cpf); //strcpy copia os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados, na pasta do projeto
	file = fopen(arquivo, "w"); //"w" pq � para criar
	fprintf (file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen (arquivo, "a"); //"a" � para acessar o arquivo
	fprintf (file, ","); //criamos uma virgula no arquivo, ap�s o cpf
	fclose (file);
	
	printf ("Digite o Nome a ser cadastrado: ");
	scanf ("%s",nome);
	
	file = fopen (arquivo,"a");
	fprintf (file,nome);
	fclose (file);
	
	file = fopen (arquivo,"a"); //"a" � para acessar o arquivo
	fprintf (file, ","); //criamos uma virgula no arquivo, ap�s o cpf
	fclose (file);
	
	printf ("Digite o Sobrenome a ser cadastrado: ");
	scanf ("%s",sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf (file,sobrenome);
	fclose (file);
	
	file = fopen (arquivo, "a"); //"a" � para acessar o arquivo
	fprintf (file, ","); //criamos uma virgula no arquivo, ap�s o cpf
	fclose (file);
	
	printf ("Digite o Cargo a ser cadastrado: ");
	scanf ("%s",cargo);
	
	file = fopen (arquivo,"a");
	fprintf (file, cargo);
	fclose (file);
	
	system ("pause");
}

int consulta ()

{
	;setlocale (LC_ALL, "portuguese");
	
	char cpf [40];
	char conteudo[200];
	
	printf ("Digite o CPF a ser consultado: ");
	scanf ("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf ("N�o foi poss�vel abrir o arqu�vo, N�o localizado!\n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system ("pause");
	
}

int deletar ()
{
	char cpf [40];
	
	printf ("Digite o CPF a ser deletado: ");
	scanf ("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	
	if (file == NULL)
	{
		printf ("O usu�rio foi deletado e n�o se encontra mais no sistema!\n");
		system ("pause");
	}
}

int main ()
{
	;int opcao=0 //defini��o de variavel
	;int laco=1;
	for (laco=1;laco=1;)
	{
		
	system ("cls");
	
    ;setlocale (LC_ALL, "portuguese");  //definindo um padr�o de linguagem
    
    
    printf ("       ### Cart�rio da Ebac ### \n\n" );
    printf ("   Escolha a op��o desejada no menu: \n\n");
    printf ("\t1 - Registrar Nomes\n");
    printf ("\t2 - Consultar Nomes\n");
    printf ("\t3 - Deletar Nomes\n\n");
    printf ("Op��o:")
    
   ;scanf("%d", &opcao) //guardando a informa��o do usu�rio
   
   ;system ("cls") //limpando a tela
   
   
   ;switch (opcao)
   {
   		case 1:
   		registro (); //chamando as fun��es fora da main
   		break;;
   		
   		case 2:
   		consulta (); //chamando
		break;
		
		case 3:
		deletar (); //chamando
   		break;
   		
   		default:
   		printf ("Esta op��o n�o est� dispon�vel! \n");
   		system ("pause");
   		break;
   	}
    }
}
