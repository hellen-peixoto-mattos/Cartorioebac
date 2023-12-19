#include <stdio.h> //biblioteca de comunicação com o usuário
#include <locale.h> //biblioteca de alocação de texto por região
#include <stdlib.h> //biblioteca de olocação de espaço em memória 
#include <string.h> //biblioteca responsável por cuidar das string
 
 
int registro() //Função responsavel por registrar os usuários no sistema
{
	//inicio criação de variaveis/string
	char cpf[40];
	char nome[40];
	char cargo[40];
	char arquivo[40];	
	char sobrenome[40];
	//final da criação de variaveis/string
	
	printf("Informe o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //%s referece a string /armazenar string
	
	strcpy(arquivo , cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria um arquivo
	file = fopen(arquivo, "w"); //cria um arquivo e o "w" significa escrever
	fprintf(file,cpf); //fprintf salva o arquivo/salvar arquivo na variavel cpf
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //acessar e incluir mais informações
	fprintf(file,","); //salvar no arquivo "file"
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //incluir arquivo
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");

}

int consulta() //função responável por consultar usúario no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
   
    printf("Digite o cpf a ser consultado: ");
    scanf("%s",cpf); //Armazenando a variavel "cpf" utilizando a função string "%s"
    
    FILE *file; //consultar arquivo(abrir)
    file = fopen(cpf,"r"); //Abre o arquivo CPF e "R" de Read para "ler" a informação
    
    if(file == NULL) //Se a informação não existir traz a seguinte mensagem
    {
    	printf("\nNão foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //(while) enquanto tiver informaão, armazene a informação em conteudo se for diferente de NULL (nulo)
	{
 		printf("\nEssas são as informações do usuário: \n");//informação que vai aparecer antes dos dados
 		printf("%s", conteudo);
 		printf("\n\n"); //Comando utilizado para quebra de linha
    }

	system("pause");

    }  
	
int deletar() //função responsável por deletar usúario do sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
		
	FILE *file; //acessar arquivo
	file = fopen(cpf, "r"); //ler o cpf
	
	if(file == NULL) //caso o arquivo não for encontrado mostrar a seguinte informação para o usuário
	{
		printf("\nUsuário não encontrado no sistema!.\n\n");
		system("pause");
	}
	
	remove(cpf); //remover arquivo
	
	if(file != NULL) //cpf encontrado e deletado com sucesso (!=) diferente de "não encontrado"
	{
		printf("\nUsuário deletado com sucesso! \n\n");
		system("pause");
	}

}

int main() //Função principal do menu
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //criando laço de repetição 
	{
	   system("cls"); //limpa a tela
	   
	   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	   printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	   printf("Escolha a opção desejada do menu:\n\n");
       printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n");
	   printf("\t4 - Sair do sitema\n\n");
	   printf("Opção: "); //fim do menu
	
	   scanf("%d" , &opcao); //armezando a escolha do usuário
	
	   system("cls");
	   
	switch(opcao) //(switch)escolha
	   {
	   	    case 1:
	   		registro(); //chamada da função
	        break;
	        
			case 2: 
			consulta(); //chamda da função consulta
	        break;
	        
	        case 3:
	        deletar(); //chamada da função deletar
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema!\n");
		    return 0;
		    break;
		    	
		    default:
		    printf("Essa opcao não está disponivel!\n"); 
		    system("pause"); 
			break; 
		    //fim da seleção	
	   }
    }
}

