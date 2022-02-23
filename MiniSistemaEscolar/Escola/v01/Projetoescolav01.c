#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5

//Declaração de funções do menu de cadastro
void Cadastrar();
void CadastrarAluno();
void CadastrarProfessor();
void CadastrarDisciplina();

//Declaração de funções do menu de Inserção
void Inserir();
void InserirAluno();
void InserirProfessor();

//Declaração de funções do menu de listagem
void Listar();
void ListarAluno();
void ListarProfessor();
void ListarDisciplina();

//Declaração de funções do menu de exclusão 
void Excluir();
void ExcluirAluno();
void ExcluirProfessor();
void ExcluirAlunoDisc();
void ExcluirProfDisc();
void ExcluirDisciplina();

//Declaração de funções para atualização de cadastro
void Atualizar();
void AtualizarProfessor();
void AtualizarAluno();
void AtualizarDisciplina();

//Struct para cadastrar data de nascimento
struct CadastroNascimento
{
    int Dia;
    int Mes;
    int Ano;
};

//Struct para cadastro de alunos
struct CadastroAluno
{
    char Nome[30], Matricula[10], Cpf[20], Disciplina[30], Codigo[10];
    int Sexo, Semestre;
    int Flag1, Flag2;
    struct CadastroNascimento Nascimento;
    
}Aluno[MAX];

//Struct para cadastro de professores
struct CadastroProfessor
{
    char Nome [30], Matricula[10], Cpf[20], Disciplina[30], Codigo[10];
    int Sexo, Semestre;
    int Flag1, Flag2;
    struct CadastroNascimento Nascimento;

}Professor[MAX];

//Struct para cadastro de disciplina
struct CadastroDisciplina
{
    char Nome [30], Codigo[10];
    int Semestre;
    int Flag1, Flag2;

}Disciplina[MAX];



//BlOCO MAIN (Menu Principal)
int main(void)
{

    int opcao;

    do
    {
        system("Cls");

        printf("\n -----Bem Vindo Ao Projeto Escola-----\n");
        printf("\n Digite 1 Para Cadastrar:\n");
        printf("\n Digite 2 Para Inserir:\n");
        printf("\n Digite 3 Para Listar:\n");
        printf("\n Digite 4 Para Atualizar:\n");
        printf("\n Digite 5 Para Excluir:\n");
        printf("\n Digite 0 Para Encerrar:\n");

        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            
            case 1:
            Cadastrar();
            break;

            case 2:
            Inserir();
            break;

            case 3:
            //Listar();
            break;

            case 4:
            //Atualizar();
            break;

            case 5:
            //Excluir();
            break;

        }
        getchar();

    }while(opcao != 0);
    
    return 0;
}


//Função Cadastro
void Cadastrar(){

     int opcao;

        do
        {
            system("Cls");

            printf("\n -----Bem Vindo Ao Sistema De Cadastramento-----\n");
            printf("\n Digite 1 Para Cadastrar Aluno:\n");
            printf("\n Digite 2 Para Cadastrar Professor:\n");
            printf("\n Digite 3 Para Cadastrar Disciplina:\n");
            printf("\n Digite 0 Para Encerrar:\n");

            scanf("%d", &opcao);
            getchar();

            switch(opcao){
            
            case 1:
            CadastrarAluno();
            break;

            case 2:
            CadastrarProfessor();
            break;

            case 3:
            CadastrarDisciplina();
            break;

            }
            getchar();

        }while(opcao != 0);
}//FIM DO BLOCO PRINCIPAL DE CADASTRO GERAL


//Função CadastrarAluno - Sub bloco da função Cadastrar
void CadastrarAluno()
{
    int opcao, i, cont;

    do
    {
        system("Cls");

        for(i=0; i<MAX; i++)
        {
            if(Aluno[i].Flag1 == 0)
            {

                printf("\nNome: ");
		        fgets(Aluno[i].Nome, sizeof(Aluno[i].Nome), stdin); 
                printf("\nMatricula: ");
		        fgets(Aluno[i].Matricula, sizeof(Aluno[i].Matricula), stdin);
                fflush(stdin);
                printf("\nCPF: ");
		        fgets(Aluno[i].Cpf, sizeof(Aluno[i].Cpf), stdin);
                
                //VALIDAÇÃO DO CPF
                cont=0;
                while(Aluno[i].Cpf[cont] != '\n'){
                cont++;
                }

                if(cont>11)
                {
                printf("\n CPF INVALIDO\n");

                    do{
                        printf("\nCPF: ");
		                fgets(Aluno[i].Cpf, sizeof(Aluno[i].Cpf), stdin);
                        fflush(stdin);
                        cont=0;   
                        while(Aluno[i].Cpf[cont] != '\n'){
                        cont++;
                        }
                        if(cont>11){
                        printf("\n CPF INVALIDO\n");
                        } 
                    }while(cont>11);
                }
                
                printf("\nSexo:\n \n1-Masculino\n \n2-Feminino\n \n3-Outros\n\n");
                scanf("%d", &Aluno[i].Sexo);
                fflush(stdin);//FIM DA VALIDAÇÃO DO CPF


                //VALIDAÇÃO DO SEXO
                while((Aluno[i].Sexo < 1) || (Aluno[i].Sexo > 3)){
                    printf("\nOpcao invalida\n");
                    printf("\nSexo:\n \n1-Masculino\n \n2-Feminino\n \n3-Outros\n\n");
                    scanf("%d", &Aluno[i].Sexo);
                    fflush(stdin);
                }//FIM DA VALIDAÇÃO DO SEXO
                


                //VALIDAÇÃO DE DATA DE NASCIMENTO COM ANO BISSEXTO
                do
                {
                system("cls");
                printf("\nData de nascimento\n");
                printf("\nDia: ");
                scanf("%d", &Aluno[i].Nascimento.Dia);
                fflush(stdin);
                printf("\nMes: ");
                scanf("%d", &Aluno[i].Nascimento.Mes);
                fflush(stdin);
                printf("\nAno: ");
                scanf("%d", &Aluno[i].Nascimento.Ano);
                fflush(stdin);

                cont=0;

                    if(Aluno[i].Nascimento.Ano >= 1900 && Aluno[i].Nascimento.Ano <= 9999){

                        if(Aluno[i].Nascimento.Mes >= 1 && Aluno[i].Nascimento.Mes <= 12){

                            if((Aluno[i].Nascimento.Dia >= 1 && Aluno[i].Nascimento.Dia <= 31) && (Aluno[i].Nascimento.Mes == 1 || Aluno[i].Nascimento.Mes == 3 || Aluno[i].Nascimento.Mes == 5 || Aluno[i].Nascimento.Mes == 7 || Aluno[i].Nascimento.Mes == 8 || Aluno[i].Nascimento.Mes == 10 || Aluno[i].Nascimento.Mes == 12)){
                            cont++;
                            }
                            else if((Aluno[i].Nascimento.Dia >= 1 && Aluno[i].Nascimento.Dia <= 30) && (Aluno[i].Nascimento.Mes == 4 || Aluno[i].Nascimento.Mes == 6 || Aluno[i].Nascimento.Mes == 9 || Aluno[i].Nascimento.Mes == 11)){
                            cont++;
                            }
                            else if((Aluno[i].Nascimento.Dia >= 1 && Aluno[i].Nascimento.Dia <= 28) && (Aluno[i].Nascimento.Mes == 2)){
                            cont++;
                            }
                            else if(Aluno[i].Nascimento.Dia == 29 && Aluno[i].Nascimento.Mes == 2 && (Aluno[i].Nascimento.Ano % 400 == 0 || (Aluno[i].Nascimento.Ano % 4 == 0 && Aluno[i].Nascimento.Ano % 100 != 0))){
                            cont++;
                            }
                            else
                            {
                            printf("\nO formato da data de nascimento esta invalida.\n");
                            }
                        }
                        else
                        {
                        printf("\nO formato da data de nascimento esta invalida.\n");
                        }    
                    }
                    else
                    {
                    printf("\nO formato da data de nascimento esta invalida.\n");
                    }    

                }while(cont != 1); //FIM DA VALIDAÇÃO DA DATA DE NASCIMENTO
            
                Aluno[i].Flag1 = 1;  //INSERINDO O CADASTRO NA STRUCT ATRAVÉS DA FLAG  
                break;
            } 
        }

        printf("\n1 - Continuar cadastrando\n0 - Sair\n");
		scanf("%d", &opcao);
        fflush(stdin);
        getchar();

    }while(opcao != 0);
}//FIM DA FUNÇÃO DE CADASTRAR ALUNO



//Função CadastrarProfessor - Sub bloco da função Cadastrar
void CadastrarProfessor()
{
    int opcao, i, cont;

    do
    {
        system("Cls");

        for(i=0; i<MAX; i++)
        {
            if(Professor[i].Flag1 == 0)
            {

                printf("\nNome: ");
		        fgets(Professor[i].Nome, sizeof(Professor[i].Nome), stdin); 
                printf("\nMatricula: ");
		        fgets(Professor[i].Matricula, sizeof(Professor[i].Matricula), stdin);
                fflush(stdin);
                printf("\nCPF: ");
		        fgets(Professor[i].Cpf, sizeof(Professor[i].Cpf), stdin);
                
                //VALIDAÇÃO DO CPF
                cont=0;
                while(Professor[i].Cpf[cont] != '\n'){
                cont++;
                }

                if(cont>11)
                {
                printf("\n CPF INVALIDO\n");

                    do{
                        printf("\nCPF: ");
		                fgets(Professor[i].Cpf, sizeof(Professor[i].Cpf), stdin);
                        fflush(stdin);
                        cont=0;   
                        while(Professor[i].Cpf[cont] != '\n'){
                        cont++;
                        }
                        if(cont>11){
                        printf("\n CPF INVALIDO\n");
                        } 
                    }while(cont>11);
                }
                
                printf("\nSexo:\n \n1-Masculino\n \n2-Feminino\n \n3-Outros\n\n");
                scanf("%d", &Professor[i].Sexo);
                fflush(stdin);//FIM DA VALIDAÇÃO DO CPF


                //VALIDAÇÃO DO SEXO
                while((Professor[i].Sexo < 1) || (Professor[i].Sexo > 3)){
                    printf("\nOpcao invalida\n");
                    printf("\nSexo:\n \n1-Masculino\n \n2-Feminino\n \n3-Outros\n\n");
                    scanf("%d", &Professor[i].Sexo);
                    fflush(stdin);
                }//FIM DA VALIDAÇÃO DO SEXO
                


                //VALIDAÇÃO DE DATA DE NASCIMENTO COM ANO BISSEXTO
                do
                {
                system("cls");
                printf("\nData de nascimento\n");
                printf("\nDia: ");
                scanf("%d", &Professor[i].Nascimento.Dia);
                fflush(stdin);
                printf("\nMes: ");
                scanf("%d", &Professor[i].Nascimento.Mes);
                fflush(stdin);
                printf("\nAno: ");
                scanf("%d", &Professor[i].Nascimento.Ano);
                fflush(stdin);

                cont=0;

                    if(Professor[i].Nascimento.Ano >= 1900 && Professor[i].Nascimento.Ano <= 9999){

                        if(Professor[i].Nascimento.Mes >= 1 && Professor[i].Nascimento.Mes <= 12){

                            if((Professor[i].Nascimento.Dia >= 1 && Professor[i].Nascimento.Dia <= 31) && (Professor[i].Nascimento.Mes == 1 || Professor[i].Nascimento.Mes == 3 || Professor[i].Nascimento.Mes == 5 || Professor[i].Nascimento.Mes == 7 || Professor[i].Nascimento.Mes == 8 || Professor[i].Nascimento.Mes == 10 || Professor[i].Nascimento.Mes == 12)){
                            cont++;
                            }
                            else if((Professor[i].Nascimento.Dia >= 1 && Professor[i].Nascimento.Dia <= 30) && (Professor[i].Nascimento.Mes == 4 || Professor[i].Nascimento.Mes == 6 || Professor[i].Nascimento.Mes == 9 || Professor[i].Nascimento.Mes == 11)){
                            cont++;
                            }
                            else if((Professor[i].Nascimento.Dia >= 1 && Professor[i].Nascimento.Dia <= 28) && (Professor[i].Nascimento.Mes == 2)){
                            cont++;
                            }
                            else if(Professor[i].Nascimento.Dia == 29 && Professor[i].Nascimento.Mes == 2 && (Professor[i].Nascimento.Ano % 400 == 0 || (Professor[i].Nascimento.Ano % 4 == 0 && Professor[i].Nascimento.Ano % 100 != 0))){
                            cont++;
                            }
                            else
                            {
                            printf("\nO formato da data de nascimento esta invalida.\n");
                            }
                        }
                        else
                        {
                        printf("\nO formato da data de nascimento esta invalida.\n");
                        }    
                    }
                    else
                    {
                    printf("\nO formato da data de nascimento esta invalida.\n");
                    }    

                }while(cont != 1); //FIM DA VALIDAÇÃO DA DATA DE NASCIMENTO
            
                Professor[i].Flag1 = 1;  //INSERINDO O CADASTRO NA STRUCT ATRAVÉS DA FLAG  
                break;
            } 
        }

        printf("\n1 - Continuar cadastrando\n0 - Sair\n");
		scanf("%d", &opcao);
        fflush(stdin);
        getchar();

    }while(opcao != 0);
}//FIM DA FUNÇÃO CADASTRAR PROFESSOR



//Função de Cadastrar Disciplina - Sub Bloco da Função Cadastrar
void CadastrarDisciplina()
{
    int opcao, i, cont;

    do
    {
        system("Cls");

        for(i=0; i<MAX; i++)
        {
            if(Disciplina[i].Flag1 == 0)
            {

                printf("\nNome: ");
		        fgets(Disciplina[i].Nome, sizeof(Disciplina[i].Nome), stdin); 
                printf("\nCodigo: ");
		        fgets(Disciplina[i].Codigo, sizeof(Disciplina[i].Codigo), stdin);
                fflush(stdin);
                
                //INSERÇÃO E VALIDAÇÃO DO SEMESTRE
                cont=0;
                while(cont != 1){

                    printf("\nSemestre Da Disciplina: ");
		            scanf("%d", &Disciplina[i].Semestre);
                    fflush(stdin);

                    if(Disciplina[i].Semestre >= 1 && Disciplina[i].Semestre <=12)
                        cont=1;
                    else
                    printf("\nSemestre Invalido\n");
                }

                Disciplina[i].Flag1 = 1;  //INSERINDO O CADASTRO NA STRUCT ATRAVÉS DA FLAG  
                break;
            } 
        }

        printf("\n1 - Continuar cadastrando\n0 - Sair\n");
		scanf("%d", &opcao);
        fflush(stdin);
        getchar();

    }while(opcao != 0);
}//FIM DA FUNÇÃO CADASTRAR DISCIPLINA

 

//MENU DE INSERÇÃO
void Inserir(){

	int opcao;

	do{

		system("cls");
		fflush(stdin);
		printf("\nDigite 1 para Inserir Aluno em disciplina\n");
		printf("\nDigite 2 para Inserir Professor em disciplina\n");
		printf("\nDigite 0 - Sair\n");
		scanf("%d", &opcao);
        fflush(stdin);

		switch(opcao){
			case 1:
				InserirAluno();
			break;
			case 2:
				InserirProfessor();
			break;
		}
	}while(opcao!=0);
}//FIM DO BLOCO PRINCIPAL DE INSERÇÃO


//Função de Inserir Aluno em Disciplina - Sub Bloco da função Inserir
void InserirAluno(){

    int opcao,i;
	char Matricula[10], Codigo[10];

	do{
		system("cls");
		fflush(stdin);
		printf("\nDigite a Matricula do aluno: \n");
		fgets(Matricula, sizeof(Matricula), stdin);
		for(i=0;i<MAX;i++){
			if(strstr(Aluno[i].Matricula, Matricula)!=NULL){
				printf("Pois bem %s\n", Aluno[i].Nome);
			}
		}
		printf("\nDigite o codigo da disciplina: \n");
		fgets(Codigo, sizeof(Codigo), stdin);
		for(i=0;i<MAX;i++){
			if(strstr(Aluno[i].Matricula, Matricula)!=NULL){
				if(strstr(Disciplina[i].Codigo, Codigo)!=NULL){
					if(Aluno[i].Flag2==0){
						strcpy(Aluno[i].Disciplina, Disciplina[i].Nome);
						strcpy(Aluno[i].Codigo, Disciplina[i].Codigo);
						Aluno[i].Semestre=Disciplina[i].Semestre;
						Aluno[i].Flag2=1;
						printf("\nDisciplina Inserida\n");
						break;	
					}
				}
			}
		}
		printf("\n1 - Inserir outra\n0 - Sair\n");
		scanf("%d", &opcao);
        fflush(stdin);
	}while(opcao!=0);
}//FIM DA FUNÇÃO INSERIR ALUNO EM UMA DISCIPLINA


//Função de Inserir Professor em uma Disciplina - Sub Bloco da função Inserir
void InserirProfessor(){

    int opcao,i;
	char Matricula[10], Codigo[10];

	do{
		system("cls");
		fflush(stdin);
		printf("\nDigite a Matricula do Professor: \n");
		fgets(Matricula, sizeof(Matricula), stdin);
		for(i=0;i<MAX;i++){
			if(strstr(Professor[i].Matricula, Matricula)!=NULL){
				printf("Pois bem professor %s\n", Professor[i].Nome);
			}
		}
		printf("\nDigite o codigo da disciplina: \n");
		fgets(Codigo, sizeof(Codigo), stdin);
		for(i=0;i<MAX;i++){
			if(strstr(Professor[i].Matricula, Matricula)!=NULL){
				if(strstr(Disciplina[i].Codigo, Codigo)!=NULL){
					if(Aluno[i].Flag2==0){
						strcpy(Professor[i].Disciplina, Disciplina[i].Nome);
						strcpy(Professor[i].Codigo, Disciplina[i].Codigo);
						Professor[i].Semestre=Disciplina[i].Semestre;
						Professor[i].Flag2=1;
						printf("\nDisciplina Inserida\n");
						break;	
					}
				}
			}
		}
		printf("\n1 - Inserir outra\n0 - Sair\n");
		scanf("%d", &opcao);
        fflush(stdin);
	}while(opcao!=0);
}//FIM DA FUNÇÃO INSERIR PROFESSOR EM UMA DISCIPLINA 



//Função do menu de Listagem
void Listar(){

    int opcao;

    do{

		system("cls");

		fflush(stdin);
        printf("\n1 - Listar Alunos\n");
        printf("\n2 - Listar Professores\n");
        printf("\n3 - Listar Disciplinas\n");
        printf("\n0 - Sair\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                ListarAluno();
            break;
            case 2:
                ListarProfessor();
            break;
            case 3:
                ListarDisciplina();
            break;
        }
    }while(opcao!=0);
}//FIM DO MENU PRINCIPAL DE LISTAGEM


//Função para listar alunos e suas respectivas disciplinas - Sub bloco da função listar
void ListarAluno(){

    int i,opcao;

	system("cls");

	fflush(stdin);
	printf("\n_____LISTA DE ALUNOS_____\n");
	for(i=0;i<MAX;i++){
		if(Aluno[i].Flag1==1){
			printf("Nome: %s\n", Aluno[i].Nome);
			printf("Matricula: %s\n", Aluno[i].Matricula);
			printf("CPF: %s\n", Aluno[i].Cpf);
			printf("Sexo: %s\n", Aluno[i].Sexo);
            printf("Nascimento:%d/%d/%d\n", Aluno[i].Dia, Aluno[i].Mes, Aluno[i].Ano);
			if(Aluno[i].Flag2==1){
				printf("\nMatriculado: %s \n", Aluno[i].Disciplina);
				printf("codigo: %s \n", Aluno[i].Codigo);
				printf("Semestre: %d \n", Aluno[i].Semestre);
				printf("\n----------------\n");
			}
		}
	}
    while(opcao!=0){

        printf("\n0 - Sair\n");
	    scanf("%d", &opcao);

        if(opcao==0)
		    Listar();
	    else
		printf("\n Opcao Invalida");
    }
}//FIM DA FUNÇÃO DE LISTAR ALUNOS



//Função para lista professores e suas respectivas disciplinas - Sub bloco da função listar
void ListarProfessor(){

    int i,opcao;

	system("cls");

	fflush(stdin);
	printf("\n_____LISTA DE PROFESSORES_____\n");
	for(i = 0; i < MAX; i++){
		if(Professor[i].Flag1==1){
			printf("Nome: %s\n", Professor[i].Nome);
			printf("Matricula: %s\n", Professor[i].Matricula);
			printf("CPF: %s\n", Professor[i].Cpf);
			printf("Sexo: %s\n", Professor[i].Sexo);
            printf("Nascimento:%d/%d/%d\n", Professor[i].Dia, Professor[i].Mes, Professor[i].Ano);
			if(Professor[i].Flag2==1){
				printf("\nLeciona: %s \n", Professor[i].Disciplina);
				printf("codigo: %s \n", Professor[i].Codigo);
				printf("Semestre: %d \n", Professor[i].Semestre);
			}
			printf("\n----------------\n");
		}
	}
    while(opcao!=0){

        printf("\n0 - Sair\n");
	    scanf("%d", &opcao);

        if(opcao==0)
		    Listar();
	    else
		printf("\n Opcao Invalida");
    }
}//FIM DA FUNÇÃO DE LISTAR PROFESSOR



//Função de listar as disciplinas cadastradas no sistema - Sub bloco da função listar
void ListarDisciplina(){

    int i,opcao;

	system("cls");

	fflush(stdin);
	printf("\n_____LISTA DE DISCIPLINAS_____\n");
	for(i=0;i<MAX;i++){
		if(Disciplina[i].Flag1==1){
			printf("Disciplina: %s\n", Disciplina[i].Nome);
			printf("codigo: %s\n", Disciplina[i].Codigo);
            printf("Semestre: %d\n", Disciplina[i].Semestre);
			printf("\n----------------\n");
		}
	}
    while(opcao!=0){

        printf("\n0 - Sair\n");
	    scanf("%d", &opcao);

        if(opcao==0)
		    Listar();
	    else
		printf("\n Opcao Invalida");
    }
}//FIM DA FUNÇÃO DE LISTAR DISCIPLINAS