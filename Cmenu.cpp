#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
/*STRUCT de cadastro*/
typedef struct cadastro
{
	char nome[40], telefone[14], email[25];
    int idade;
    
}cadastro;
/* VARIAVEIS GLOBAIS */
	cadastro agenda[4];
	int opc, i=0, tamanho, aux=0, contador=0;
	char sair, voltar, busca[40];
/*CADASTRAR PESSOAS*/
int cadastrar_pessoa()
{
	for(i=aux;i<4;i++)
	{
		tamanho = (strlen(agenda[i].nome));
		if((tamanho == 0) && (agenda[i].nome != '\0') && (contador != 4))
		{
			printf("Informe o nome: ");
			scanf("%s",agenda[i].nome);
			printf("Informe o telefone: ");
			scanf("%s",agenda[i].telefone); 
			printf("Informe o email: ");
			scanf("%s",agenda[i].email); 
			printf("Informe a idade: ");
			scanf("%d",&agenda[i].idade);
			contador = contador + 1;
			printf("Deseja voltar ao menu principal? (S/N): ");
			fflush(stdin);
			scanf("%c",&voltar);
				if(voltar =='s')
				{
					aux = i+1;
					system("cls");
					break;
				}
				
					if((voltar == 'n') && (*agenda[3].nome != 0))
					{
						while(voltar =='n')
						{
							system("cls");
							printf("A agenda est� cheia, digite (S) para voltar ao menu ");
							fflush(stdin);
							scanf("%c",&voltar);
							system("cls");
						}
					}
		}
		else if (contador == 4)
		{
			printf("O cadastro est� cheio!\n");
			break;
		}
	}	
}
/*PESQUISAR PELO NOME (exibir todas informa��es do usu�rio)*/
int pesquisar_pessoa(){
	int teste = 0;
	
	printf("Digite o nome de quem deseja procurar: ");
	scanf("%s",busca);
		for (i=0;i<4;i++)
		{
			if(strcmp(busca,agenda[i].nome) ==0)
			{
				printf("Informa��es buscadas: \n");
				printf("Nome: %s\n", agenda[i].nome);
				printf("Telefone: %s\n", agenda[i].telefone);
				printf("Email: %s\n", agenda[i].email);
				printf("Idade: %d\n", agenda[i].idade);	
				teste = 1;
				printf("Deseja voltar ao menu principal? (S/N): ");
				fflush(stdin);
				scanf("%c",&voltar);
				if(voltar == 'n')
				{
					system("cls");
					pesquisar_pessoa();
				}
				else
				{
					system("cls");
				}
			}
			teste = teste + 1;
			if(teste == 4 )
			{
				printf("Essa pessoa n�o existe!\n");
				printf("Deseja voltar ao menu principal? (S/N): ");
				fflush(stdin);
				scanf("%c",&voltar);
					if(voltar == 'n')
					{
						system("cls");
						pesquisar_pessoa();
					}
					else
					{
						system("cls");
					}
			}
		}
}
/*EXIBIR TODAS INFORMA��ES DOS CADASTRADOS NA AGENDA*/
int exibir_pessoa()
{
	for(i=0;i<aux;i++)
	{
		printf("Nome: %s\n Telefone: %s\n Email: %s\n Idade: %d\n", agenda[i].nome, agenda[i].telefone, agenda[i].email, agenda[i].idade);
	}
}

/*PROGRAMA PRINCIPAL*/
int main()
{
	setlocale(LC_ALL, "Portuguese");
	voltar = 's';
while(voltar == 's')
{
	printf("=======================\n");
	printf("AGENDA ELETR�NICA\n");
	printf("=======================\n");
	
	printf("1. ADICIONAR\n");
	printf("2. PESQUISAR\n");
	printf("3. EXIBIR\n");
	printf("4. SAIR\n");
	printf("\nAcesso: ");
	scanf("%d",&opc);
	switch(opc)
        {
            case 1:
            	system("cls");
                	cadastrar_pessoa();
                break;
            case 2:
                system("cls");
                printf("Bem vindo ao menu de pesquisar um aluno! \n\n");
                pesquisar_pessoa();
                break;
            case 3:
                system("cls");
                printf("Bem vindo ao menu de exibir um aluno! \n\n");
                exibir_pessoa();
                break;
            case 4:
                system("cls");
                printf("\nDeseja mesmo sair do programa? (s/n)");
                fflush(stdin);
                scanf("%c",&sair);
                if(sair == 's')
                {
                    printf("Pressione qualquer tecla para sair.\n");
                    exit(0);
                }
                break;
            default:
                system("cls");
                printf("Digite um comando valido!\n\n");
    	}
}
return 0;
}
