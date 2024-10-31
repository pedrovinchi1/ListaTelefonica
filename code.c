//Trabalho de Laboratorio de Informatica
//Alunos
//Juliana Yukari Hukushima
//Lucas Carvalho Silva
//Pedro Henrique Ferreira Vinchi
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include<windows.h>

#define VALOR 100

/*Estruturas de Dados*/
struct Endereco{//Estrutura de Endere�o
    char rua[VALOR];
    char num_rua[VALOR];
    char complemento[VALOR];
    char bairro[VALOR];
    char cep[VALOR];
    char cidade[VALOR];
    char estado[VALOR];
    char pais[VALOR];
};


struct Datanasc{//Estrutura para Data de Nascimento
    int dia;
    int mes;
    int ano;
};

struct Agenda{//Estrutura geral da Agenda
    char nome[VALOR];
    char email[VALOR];
    char tel[VALOR];
    struct Endereco end;
    struct Datanasc data;
    char obs[VALOR];
};

/*Declara��o de Fun��es*/
void mostra_dadoNome(struct Agenda *a);//Fun��o para pesquisa por nome
void mostra_dadoMes(struct Agenda *a);//Fun��o para pesquisa por mes
void mostra_dadoTel(struct Agenda *a);//Fun��o para pesquisa por telefone
void ordena_nomes(struct Agenda *a, int x);//Fun��o para listagem por nome
int exclui_dado(struct Agenda *a, int x);//Fun��o para excluir cadastro
void tipos_consulta(struct Agenda *a, int x);//Fun��o para imprimir dados
void gotoxy(int x, int y); //definir posi�ao das frases

int ValidaEmail(struct Agenda *a, int cadastro);//Fun��o para valida��o do email
int ValidaCEP(struct Agenda *a,int cadastro);//Fun��o para valida��o do CEP
int ValidaESTADO(struct Agenda *a,int cadastro);//Fun��o para valida��o do Estado
int ValidaTELEFONE(struct Agenda *a,int cadastro);//Fun��o para valida��o do telefone
int ValidaDATA(struct Agenda * a,int cadastro);//Fun��o para valida��o da data

/*Programa*/
int main (){
    struct Agenda a[VALOR];
    int i = 0,//variavel padrao para la�o de repeti��o for
        menu = 0,//variavel para acesso ao menu do programa, por switch case
        valid = 1,//variavel auxiliar para as valida��es
        cadastro = 0;//variavel auxiliar para controle de cadastros

    do {//meno
        system("cls");
        gotoxy(15,2);printf("TRABALHO DE LABORATORIO");//mensagem padr�o nome do programa
        gotoxy(15,5);printf("1- Cadastro de pessoas ");//indica��o para sele��o de cadastro de pessoas
        gotoxy(15,6);printf("2- Consulta por nome ");//indica��o para consulta por nome
        gotoxy(15,7);printf("3- Busca pro mes ");//indica��o para busca por nome
        gotoxy(15,8);printf("4- Consultar por numero de telefone ");//indica��o para consulta de pessoas por numero de telefone
        gotoxy(15,9);printf("5- Listagem de pessoas em ordem alfabetica ");//Indica��o para listar o nome de todas as pessoas cadastradas
        gotoxy(15,10);printf("6- Excluir Cadastro ");//indica��o para exclusao de cadastro
        gotoxy(15,11);printf("7- Opcoes para listagem de dados ");//indica��o para listagem de alguns dados de cada cadastro em ordem alfabetica
        gotoxy(15,12);printf("0- Encerrar o programa ");//para finalizar o programa
        gotoxy(15,13);printf("Digite a sua resposta: ");//mensagem de solicita��o de entrada
        scanf("%d",&menu);//entrada de um valor para o menu
        fflush(stdin);//limpeza

        switch(menu){//menu
            case 1://Cadastrar
/*VERIFICA��O SE � POSSIVEL REALIZAR MAIS UM CADASTRO*/
                 system("cls");
                 if(cadastro >= 100){//verifica��o de quantidade de cadastro
                    printf("\nExcesso de cadastro, caso deseje inserir mais um cadastro favor excluir um cadastro ja existente");//mensagem avisando que ja esta no limite maximo de cadastros aceitos
                    break;//encerra a fun��o de cadastro sem mesmo inicia-la
                }//fim if

/*LEITURA DE DADOS*/
                do{//la�o de repeti��o para limite de cadastro

/*LEITURA DO NOME*/
                    gotoxy(15,2);printf("Cadasto de pessoas");
                    gotoxy(15,5);printf("Nome: ");//mensagem de solicita��o de dado
                    gets(a[cadastro].nome);//solicita��o de nome
                    fflush(stdin);//limpeza

/*LEITURA E VALIDA��O DE EMAIL*/
                    do{//la�o de repeti��o para leitura e valida��o de email
                        gotoxy(15,6);printf("Email: ");//mensagem de solicita��o de dado
                        gets(a[cadastro].email);//solicita��o do email
                        fflush(stdin);//limpeza
                        ValidaEmail(a, cadastro);//valida��o do email pela fun��o
                        valid=ValidaEmail(a, cadastro);//retorno de verifica��o de validade
                        if(valid==1){//verifica��o se o email n�o � valido
                            gotoxy(15,7);printf("Erro no email");//mensagem para avisar que o email n�o �  valido
                        }//fim if
                        else{
                            gotoxy(15,7);printf("                        ");
                        }
                    }while(valid==1);//verifica��o para repeti��o, se o email nao for valido o la�o ira repetir ate que o email seja valido

/*LEITURA ENDERE�O*/

/*LEITURA RUA*/
                    gotoxy(15,7);printf("Rua: ");//mensagem de solicita��o de dado
                    gets(a[cadastro].end.rua);//solicita��o de dado de rua
                    fflush(stdin);//limpeza

/*LEITURA NUMERO*/
                    gotoxy(15,8);printf("Numero da Residencia: ");//mensagem de solicita��o de dado
                    gets(a[cadastro].end.num_rua);//solicita��o de entrada de numero de residencia
                    fflush(stdin);//limpeza

/*LEITURA COMPLEMENTO*/
                    gotoxy(15,9);printf("Complemento: ");//mensagem de solicita��o de dado
                    gets(a[cadastro].end.complemento);//solicita��o de entrada de complemento
                    fflush(stdin);//limpeza

/*LEITURA BAIRRO*/
                    gotoxy(15,10);printf("Bairro: ");//mensagem de solicita��o de dado
                    gets(a[cadastro].end.bairro);//solicita��o de entrada de bairro
                    fflush(stdin);//limpeza

/*LEITURA E VALIDA��O CEP*/
                    do{//la�o de repeti��o para leitura e valida��o do cep
                        gotoxy(15,11);printf("CEP: ");//mensagem de solicita��o de dado
                        gets(a[cadastro].end.cep);//solicita��o de entrada do CEP
                        ValidaCEP(a,cadastro);//declara��o de fun��o para valida��o do cep
                        valid=ValidaCEP(a,cadastro);//retorno da fun��o de valida��o

                        if(valid == 1){//verifica��o de CEP nao valido
                            gotoxy(15,12);printf("Favor digitar um cep valido!");//mensagem de erro
                        }//fim if
                        else{
                            gotoxy(15,12);printf("                               ");
                        }
                    }while(valid == 1);//fim DO, variavel de valida��o se diferente de 1 sai do lop

/*LEITURA CIDADE*/
                    gotoxy(15,12);printf("Cidade: ");//mensagem de solicita��o de dado
                    gets(a[cadastro].end.cidade);//solicita��o de entrada da cidade
                    fflush(stdin);//limpeza

/*LEITURA E VALIDA��O ESTADO*/
                    do{//la�o de repeti��o para leitura e valida��o do estado
                        gotoxy(15,13);printf("Estado (ex:PR): ");//mensagem de solicita��o de dado
                        gets(a[cadastro].end.estado);//solicita��o de entrada do estado
                        fflush(stdin);//limpeza
                        ValidaESTADO(a,cadastro);//declara��o de fun��o para valida��o do estado
                        valid = ValidaESTADO(a,cadastro);//retorno da fun��o de valida��o

                        if(valid == 1){//verifica��o de estado nao valido
                            gotoxy(15,14);printf("Favor digitar um Estado valido!");//mensagem de erro
                        }//fim if
                        else{
                            gotoxy(15,14);printf("                                    ");
                        }
                    }while(valid == 1);//fim DO, variavel de valida��o diferente de 1 sai do lop

/*LEITURA PAIS*/
                    gotoxy(15,14);printf("Pais: ");//mensagem de solicita��o de dado
                    gets(a[cadastro].end.pais);//solicita��o de entrada do pais
                    fflush(stdin);//limpeza

/*LEITURA E VALIDA��O TELEFONE*/
                    do{//la�o de repeti��o para leitura e valida��o do telefone
                        gotoxy(15,15);printf("Telefone:");//mensagem de solicita��o de dado
                        gotoxy(15,16);printf("Obs.: Digite (XX)XXXX-XXXX ou (XX)XXXXX-XXXX: ");//mensagem especificando a estada de dado
                        gets(a[cadastro].tel);//solicita��o de entrada de numero de telefone
                        fflush(stdin);//limpeza
                        ValidaTELEFONE(a,cadastro);//declara��o da fun��o para valida��o do numero de telefone
                        valid = ValidaTELEFONE(a,cadastro);////retorno da fun��o de valida��o

                        if(valid == 1){//verifica��o de telefone n�o valido
                            gotoxy(15,17);printf("Favor digitar um numero de telefone valido!");//mensagem de erro
                        }//fim if
                        else{
                            gotoxy(15,17); printf("                                           ");
                        }

                    }while(valid == 1);//fim DO, variavel de valida��o doferente de 1 sai do lop

/*LEITURA E VALIDA��O DATA DE NASCIMENTO*/
                    do{//la�o para leitura e valida��o da data de nascimento
                        gotoxy(15,17);printf("Data de nascimento(dd/mm/aaaa): ");//mensagem de solicita��o de dado
                        scanf("%d/%d/%d",&a[cadastro].data.dia,&a[cadastro].data.mes,&a[cadastro].data.ano);//solicita��o da entrada de data de nascimento
                        fflush(stdin);//limpeza
                        ValidaDATA(a,cadastro);//declara��o de fun��o para valida��o da data
                        valid=ValidaDATA(a,cadastro);//retorno da fun��o

                        if(valid == 1){//verfica��o de data invalida
                            gotoxy(15,18);printf("Favor digitar uma data valida!");//mensagem de erro
                        }//fim if
                        else{
                            gotoxy(15,18); printf("                                ");
                        }

                    }while(valid == 1);//fim DO, se variavel de valida��o diferente de 1 sai do lopo

/*LEITURA OBSERVA��ES*/
                    gotoxy(15,18);printf("Observacoes: ");//mensagem de solicita��o de dado
                    gets(a[cadastro].obs);//solicita��o de entrada de valida��o
                    fflush(stdin);//limpeza


/*FIM DE CADASTRO, ACRESCIMO NO CONTADOR*/

                    cadastro++;//acrescimo do contador
                    break;//encerramento do cadastro

                }while(cadastro < 100);//teste de verifica��o do la�o de repiti��o, se ja existirem 100 cadastros, n�o sera possivel realizar um novo.

                break;//fim case 1

            case 2://Consulta por nome
                mostra_dadoNome(a);//declara��o de fun��o para consulta por nome
                break;//fim case 2

            case 3://listagem por aniversariantes do mes especifico
                mostra_dadoMes(a);//declara��o de variavel
                break;//fim case 3

            case 4://Consulta por telefone
                mostra_dadoTel(a);//chamada da fun��o que realiza pesquisa por telefone
                break;//fim case 4

            case 5://Listagem de pessoas cadastradas em ordem alfabetica
                ordena_nomes(a,cadastro);//chamada da fun��o que ordena os nomes em ordem alfabetica
                break;//fim case 5

            case 6://Excluir cadastros
                exclui_dado(a,cadastro);
                cadastro = exclui_dado(a,cadastro);
                break;

            case 7://Listagem de nome, telefone e email dos cadastros em ordem alfabetica
                tipos_consulta(a,cadastro);//chamada da fun��o com op��es de imprimir dado com 3 maneiras diferentes
                break;//fim case 7

            case 0://encerrar o programa
                return 0;//retorno, para encerrar o programa
                break;//fim case 0

            default://se acontecer do usuario digitar um valor errado
                printf("\nOpcao invalida.\nPor favor! Digite uma opcao valida.\n");//aviso de erro

        }//fim do switch

    }while(1);//fim DO, la�o de repeti��o infinito,

return 0;//fim do programa
}//fim do programa

/*Fun��es Sem Retorno*/

/*PESQUISA POR NOME*/
void mostra_dadoNome(struct Agenda *a){//Pesquisa por nome
    char nome[VALOR];
    int i,
        j=0;
    system("cls");//limpar a tela do programa
    gotoxy(15,2);printf("PESQUISA POR NOME");//mensagem inicial
    gotoxy(15,3);printf("Digite o nome a ser pesquisado: ");//mensagem de solicita��o de dado
    gets(nome);//solicita��o de entrada do nome
    system("cls");//limpar a tela do programa
    for(i=0;i<VALOR;i++){//la�o de repeti��o por pesquisa
        if(strcmp(a[i].nome, nome) == 0){//confere se o nome bate
            gotoxy(15,2);printf("Nome: %s ",a[i].nome);//escreve o nome da pessoa
            gotoxy(15,3);printf("Email: %s " ,a[i].email);//escreve o email da pessoa
            gotoxy(15,4);printf("Rua: %s " ,a[i].end.rua);//escreve o nome da rua da pessoa
            gotoxy(15,5);printf("Numero da residencia: %s " ,a[i].end.num_rua);//escreve o numero da casa da pessoa
            gotoxy(15,6);printf("Complemento: %s \n" ,a[i].end.complemento);//escreve o complento de endere�o da pessoa
            gotoxy(15,7);printf("Bairro: %s " ,a[i].end.bairro);//escreve o bairro da pessoa
            gotoxy(15,8);printf("CEP: %s " ,a[i].end.cep);//escreve o cep da pessoa
            gotoxy(15,9);printf("Cidade: %s " ,a[i].end.cidade);//escreve a cidade da pessoa
            gotoxy(15,10);printf("Estado: %s " ,a[i].end.estado);//escreve o estado da pessoa
            gotoxy(15,11);printf("Pais: %s " ,a[i].end.pais);//escreve o pais da pessoa
            gotoxy(15,12);printf("Telefone: %s " ,a[i].tel);//escreve o telefone da pessoa
            gotoxy(15,13);printf("Data de nascimento: %d/%d/%d " ,a[i].data.dia,a[i].data.mes,a[i].data.ano);//escreve a data de nascimento da pessoa
            gotoxy(15,14);printf("Observacoes: %s " ,a[i].obs);//escreve as observa��es feitas sobre as pessoas
            getch();//espera um caracter para mostrar a proxima pessoa se tiver, ou voltar ao menu caso nao tenha uma proxima pessoa
            system("cls");//limpar a tela
        }//fim if
    }//fim do la�o de repeti��o
}//fim da fun��o

/*PESQUISA POR MES*/
void mostra_dadoMes(struct Agenda *a){//pesquisa por mes
    int mes;
    int i,
        j=0;
    system("cls");//limpar a tela do programa
    gotoxy(15,2);printf("PESQUISA POR MES ");//mensagem inicial
    gotoxy(15,3);printf("Digite o mes a ser pesquisado: ");//mensagem de solicita��o de dado
    scanf("%d",&mes);//solicita��o de entrada do mes
    system("cls");//limpar a tela do programa
    for(i=0;i<VALOR;i++){//la�o de repeti��o por pesquisa
        if(a[i].data.mes == mes){//confere se o mes bate
            gotoxy(15,2);printf("Nome: %s ",a[i].nome);//escreve o nome da pessoa
            gotoxy(15,3);printf("Email: %s " ,a[i].email);//escreve o email da pessoa
            gotoxy(15,4);printf("Rua: %s " ,a[i].end.rua);//escreve o nome da rua da pessoa
            gotoxy(15,5);printf("Numero da residencia: %s " ,a[i].end.num_rua);//escreve o numero da casa da pessoa
            gotoxy(15,6);printf("Complemento: %s " ,a[i].end.complemento);//escreve o complento de endere�o da pessoa
            gotoxy(15,7);printf("Bairro: %s " ,a[i].end.bairro);//escreve o bairro da pessoa
            gotoxy(15,8);printf("CEP: %s " ,a[i].end.cep);//escreve o cep da pessoa
            gotoxy(15,9);printf("Cidade: %s " ,a[i].end.cidade);//escreve a cidade da pessoa
            gotoxy(15,10);printf("Estado: %s " ,a[i].end.estado);//escreve o estado da pessoa
            gotoxy(15,11);printf("Pais: %s " ,a[i].end.pais);//escreve o pais da pessoa
            gotoxy(15,12);printf("Telefone: %s " ,a[i].tel);//escreve o telefone da pessoa
            gotoxy(15,13);printf("Data de nascimento: %d/%d/%d " ,a[i].data.dia,a[i].data.mes,a[i].data.ano);//escreve a data de nascimento da pessoa
            gotoxy(15,14);printf("Observacoes: %s " ,a[i].obs);//escreve as observa��es feitas sobre as pessoas
            getch();//espera um caracter para mostrar a proxima pessoa se tiver, ou voltar ao menu caso nao tenha uma proxima pessoa
            system("cls");//limpar a tela
        }//fim if
    }//fim do la�o de repeti��o
}//fim da fun��o

/*FUM��O PARA PESQUISAR POR TELEFONE*/
void mostra_dadoTel(struct Agenda *a){
    char tel[VALOR];
    int i,
        j=0,
        cont=0;
    system("cls");//limpa a tela
    gotoxy(15,2);printf("PESQUISA POR TELEFONE");//mensagem inicial
    gotoxy(15,3);printf("Digite o telefone a ser pesquisado: ");//mensagem solicitando entrada de dado
    gets(tel);//solicita��o de entrada de dado

    system("cls");//limpa a tela
    for(i=0;i<VALOR;i++){//la�o para verifica��o
        if(strcmp(a[i].tel, tel) == 0){//confere so os dados batem
            gotoxy(15,2);printf("Nome: %s ",a[i].nome);//escreve o nome da pessoa
            gotoxy(15,3);printf("Email: %s " ,a[i].email);//escreve o email da pessoa
            gotoxy(15,4);printf("Rua: %s " ,a[i].end.rua);//escreve o nome da rua da pessoa
            gotoxy(15,5);printf("Numero da residencia: %s " ,a[i].end.num_rua);//escreve o numero da casa da pessoa
            gotoxy(15,6);printf("Complemento: %s " ,a[i].end.complemento);//escreve o complento de endere�o da pessoa
            gotoxy(15,7);printf("Bairro: %s " ,a[i].end.bairro);//escreve o bairro da pessoa
            gotoxy(15,8);printf("CEP: %s " ,a[i].end.cep);//escreve o cep da pessoa
            gotoxy(15,9);printf("Cidade: %s " ,a[i].end.cidade);//escreve a cidade da pessoa
            gotoxy(15,10);printf("Estado: %s " ,a[i].end.estado);//escreve o estado da pessoa
            gotoxy(15,11);printf("Pais: %s " ,a[i].end.pais);//escreve o pais da pessoa
            gotoxy(15,12);printf("Telefone: %s " ,a[i].tel);//escreve o telefone da pessoa
            gotoxy(15,13);printf("Data de nascimento: %d/%d/%d " ,a[i].data.dia,a[i].data.mes,a[i].data.ano);//escreve a data de nascimento da pessoa
            gotoxy(15,14);printf("Observacoes: %s " ,a[i].obs);//escreve as observa��es feitas sobre as pessoas
            getch();//espera um caracter para mostrar a proxima pessoa se tiver, ou voltar ao menu caso nao tenha uma proxima pessoa
            system("cls");//limpar a tela
        }//fim if
    }//fim for
}//fim da fun��o

/*FUN��O PARA ORDERNAR POR NOME*/
void ordena_nomes(struct Agenda *a, int x){//FUN��O PARA ORDENA��O UTILIZANDO O METODO BUBBLESORT
    struct Agenda b;
    char aux[VALOR];
    int i,
        j;
    for(i = 0; i < x-1 ; i++){//la�o para ordena��o
        for(j = i + 1;j < x; j++){//segundo la�o para ordena��o
            if(strcmp(a[i].nome,a[j].nome)> 0){//verifica��o de qual nome vem antes
                b = a[i];//caso o segundo nome venha antes o primeiro nome vai pra uma variavel auxiliar
                a[i] = a[j];//o segundo toma o lugar do primeiro
                a[j] = b;//o primeiro vai que esta em uma variavel auxiliar vai pro lugar do segundo
            }
        }
    }

    for(i=0;i<x;i++){//la�o de repeti��o para imprimir
        system("cls");//limpar a tela do programa
        printf("Nomes em ordem alfabetica");//mensagem inicial
        printf("Nome: %s \n",a[i].nome);//escreve o nome da pessoa
        getch();//espera um caracter para mostrar a proxima pessoa se tiver, ou voltar ao menu caso nao tenha uma proxima pessoa
        system("cls");//limpar a tela
    }
}

/*FUN��O PARA EXCLUIR UM CONTATO*/
int exclui_dado(struct Agenda *a, int x){//fun��o para excluir cadastros
    char nome[VALOR],
        email[VALOR];
    int i,
        j,
        contador = 0;
    system("cls");//limpa a tela
    gotoxy(15,2);printf("EXCLUSAO DE DADOS");//mensagem inicial
    gotoxy(15,3);printf("Digite o nome do contato: ");//mensagem solicitando um dado
    gets(nome);//solita��o de entrada de dado


    for(i=0;i<x;i++){//la�o de repeti��o para analise de nomes repetidos
        if((strcmp(a[i].nome,nome) == 0)){//verifica��o de compatibilidade do nome
            contador ++;//caso encontre o nome a variavel acrescenta 1
        }//fim if
    }//fim for

    if(contador > 1){//se tiver nomes repetidos
        gotoxy(15,4);printf("Existe mais de um cadastro com esse nome, por favor digite o email da pessoa para seja excuido o cadastro correto: ");//mensagem para solicitar mais uma informa��o para analise
        gets(email);//solicita��o de entrada de dado
        for(i=0;i<x;i++){//la�o para analise de dados
            if((strcmp(a[i].nome,nome) == 0) &&(strcmp(a[i].email,email)==0)){//se encontrar um nome e email compativel
                for(j=i; j<x-1; j++){//la�o para exclusao
                    a[j] = a[j+1];//excuil os dados passando substituindo ele pelo subsequente
                }// fim for
            x--;// contador de cadastro decresce 1
            return x;//retorna a quantidade de cadastros ainda existentes
            }//fim for
        }//fim for

        }else if (contador == 0){//se nao ouver 1 pessoa sequer cadastrada com o nome
            gotoxy(15,4);printf("Pessoa nao cadastrada");//avisa que a pessoa n�o esta cadastrada
            return x;//e retorna o mesmo valor antigo de cadastro existentes

        }else{//se ouver apenas uma pessoa cadastrada nao precisa de mais nenhuma informa��o
            for(i=0;i<x;i++){//la�o para procura da pessoa
                if((strcmp(a[i].nome,nome) == 0)){//analise de compatibilidade
                    for(j=i; j<x-1; j++){//la�o para exclusao
                        a[j] = a[j+1];//substitiu um valor pelo antigo
                    }//fim if
                }//fim for
            x--;//quantidade de pessoas cadastradas decai 1
            return x;//retorna
            }
        }
        return x;
}

/*FUN��O PARA IMPRESS�O*/
void tipos_consulta(struct Agenda *a, int x){
    struct Agenda b;
    int i,
        j,
        resp;
    system("cls");
    gotoxy(15,2);printf("OPCOES DE CONSULTA DE DADOS");
    gotoxy(15,5);printf("1- Imprime nome, telefone e e-mail (ordem alfabetica de nome) ");//op��o de listagem 1
    gotoxy(15,6);printf("2- Imprime nome, telefone e e-mail (separado por localidade) ");//op��o de listagem 2
    gotoxy(15,7);printf("3- Imprime todos os dados (ordem alfabetica de nome) ");//op��o  de listagem 3
    gotoxy(15,8);printf("Digite qual opcao de consulta voce deseja?:");//mensagem solicitando dado
    scanf("%d", &resp);//solicita��o de entrada de dado
    fflush(stdin);

    switch(resp){//sub menu
        case 1://ordena em ordem alfabetica mostrando menos detalhes
             for(i = 0; i < x-1 ; i++){//la�o para ordena��o
                for(j = i + 1;j < x; j++){//segundo la�o para ordena��o
                    if(strcmp(a[i].nome,a[j].nome)> 0){//verifica��o de qual nome vem antes
                        b = a[i];//caso o segundo nome venha antes o primeiro nome vai pra uma variavel auxiliar
                        a[i] = a[j];//o segundo toma o lugar do primeiro
                        a[j] = b;//o primeiro vai que esta em uma variavel auxiliar vai pro lugar do segundo
                    }//fim if
                }//fim for
            }//fim for

            for(i=0;i<x;i++){//la�o para impress�o
                system("cls");//limpar a tela do programa
                gotoxy(15,2);printf("Nomes em ordem alfabetica");//mensagem inicial
                gotoxy(15,5);printf("Nome: %s ",a[i].nome);//escreve o nome da pessoa
                gotoxy(15,6);printf("Email: %s " ,a[i].email);//escreve o email da pessoa
                gotoxy(15,7);printf("Telefone: %s " ,a[i].tel);//escreve o telefone da pessoa
                getch();//espera um caracter para mostrar a proxima pessoa se tiver, ou voltar ao menu caso nao tenha uma proxima pessoa
                system("cls");//limpar a tela
            }//fim for

            break;//fim case 1

        case 2://ordena por localidade
                for(i = 0; i < x-1 ; i++){//la�o para ordena��o
                for(j = i + 1;j < x; j++){//segundo la�o para ordena��o
                    if(strcmp(a[i].nome,a[j].nome)> 0){//verifica��o de qual nome vem antes
                        b = a[i];//caso o segundo nome venha antes o primeiro nome vai pra uma variavel auxiliar
                        a[i] = a[j];//o segundo toma o lugar do primeiro
                        a[j] = b;//o primeiro vai que esta em uma variavel auxiliar vai pro lugar do segundo
                    }//fim if
                }//fim for
            }//fim for

            for(i=0;i<x;i++){//la�o para impressao
                system("cls");//limpar a tela do programa
                gotoxy(15,2);printf("Nomes em ordem alfabetica de estados");//mensagem inicial
                gotoxy(15,5);printf("Nome: %s \n",a[i].nome);//escreve o nome da pessoa
                gotoxy(15,6);printf("Email: %s \n" ,a[i].email);//escreve o email da pessoa
                gotoxy(15,7);printf("Telefone: %s \n" ,a[i].tel);//escreve o telefone da pessoa
                getch();//espera um caracter para mostrar a proxima pessoa se tiver, ou voltar ao menu caso nao tenha uma proxima pessoa
                system("cls");//limpar a tela
            }//fim for

        case 3://ordena em ordem alfabetica imprimindo mais dados
            for(i = 0; i < x-1 ; i++){//la�o para ordena��o
                for(j = i + 1;j < x; j++){//segundo la�o para ordena��o
                    if(strcmp(a[i].nome,a[j].nome)> 0){//verifica��o de qual nome vem antes
                        b = a[i];//caso o segundo nome venha antes o primeiro nome vai pra uma variavel auxiliar
                        a[i] = a[j];//o segundo toma o lugar do primeiro
                        a[j] = b;//o primeiro vai que esta em uma variavel auxiliar vai pro lugar do segundo
                    }//fim if
                }//fim for
            }//fim for

            for(i=0;i<x;i++){//la�o para impress�o
                system("cls");//limpar a tela do programa
                gotoxy(15,2);printf("Nomes em ordem alfabetica");//mensagem inicial
                gotoxy(15,5);printf("Nome: %s ",a[i].nome);//escreve o nome da pessoa
                gotoxy(15,6);printf("Email: %s " ,a[i].email);//escreve o email da pessoa
                gotoxy(15,7);printf("Rua: %s " ,a[i].end.rua);//escreve o nome da rua da pessoa
                gotoxy(15,8);printf("Numero da residencia: %s " ,a[i].end.num_rua);//escreve o numero da casa da pessoa
                gotoxy(15,9);printf("Complemento: %s " ,a[i].end.complemento);//escreve o complento de endere�o da pessoa
                gotoxy(15,10);printf("Bairro: %s " ,a[i].end.bairro);//escreve o bairro da pessoa
                gotoxy(15,11);printf("CEP: %s " ,a[i].end.cep);//escreve o cep da pessoa
                gotoxy(15,12);printf("Cidade: %s " ,a[i].end.cidade);//escreve a cidade da pessoa
                gotoxy(15,13);printf("Estado: %s " ,a[i].end.estado);//escreve o estado da pessoa
                gotoxy(15,14);printf("Pais: %s " ,a[i].end.pais);//escreve o pais da pessoa
                gotoxy(15,15);printf("Telefone: %s " ,a[i].tel);//escreve o telefone da pessoa
                gotoxy(15,16);printf("Data de nascimento: %d/%d/%d " ,a[i].data.dia,a[i].data.mes,a[i].data.ano);//escreve a data de nascimento da pessoa
                gotoxy(15,17);printf("Observacoes: %s " ,a[i].obs);//escreve as observa��es feitas sobre as pessoas
                getch();//espera um caracter para mostrar a proxima pessoa se tiver, ou voltar ao menu caso nao tenha uma proxima pessoa
                system("cls");//limpar a tela
            }//fim for
        break;//fim case 3

        default://para quando o usuario digitar uma op��o invalida
            printf("op��o invalida");//caso o usuario digite um valor invalidado
    }//fim switch case
}//fim da fun��o

/*Fun��es com Retorno*/

/*VAILDA��O DO EMAIL*/
int ValidaEmail(struct Agenda *a, int cadastro){//fun��o para validar o email
	int i=0,
	mail = 0,
    mail2 = 0;

    for(i = 0;i < VALOR;i++){//la�o para procurar o @
        if(a[cadastro].email[i]=='@'){//analise de caracter para ver se � o @
            mail = i;//caso seja a variavel vai receber sua posi��o
        }//fim if
    }//fim for

    if(mail < 2){//verifica��o da posi��o do @
		return 1;//retorna o valor 1 para o programa se manter no la�o de repeti��o e o usuario digitar um novo email
    }//fim if

    for(i = mail; i < VALOR;i++){//la�o para verificar a posi��o do primeiro ponto final, apos o caracter @
        if(a[cadastro].email[i]=='.'){//se encontrar o ponto final
            mail2 = i;//a variavel de valida��o recebe a posi��o dele
        }//fim if
    }//fim for

    if(mail2 == 0){//se nao existir o ponto final, o email nao e valido
        return 1;//retorna o valor 1 para o programa se manter no la�o de repeti��o e o usuario digitar um novo email
    }//fim if

    else if((mail2 - mail) <= 3){//verifica��o de quantos caracters existem entre o caracter arroba e o caracter .
        // caso entre no if a distancia sera menor ou igaul a dois, e portanto o email nao sera valido
        return 1;//retorna o valor 1 para o programa se manter no la�o de repeti��o e o usuario digitar um novo email
    }//fim if

    mail2++;//a variavel com a possi��o do ponto final recebe um acrescimo para verfica��o do final 'com' do email
    if(a[cadastro].email[mail2]!= 'c'){//analisa a letra apos o '.' nao for 'c' o email nao sera valido
        return 1;//retorna o valor 1 para o programa se manter no la�o de repeti��o e o usuario digitar um novo email
    }//fim if

    mail2++;//a variavel com a possi��o do ponto final recebe um acrescimo para verfica��o do final 'com' do email
    if(a[cadastro].email[mail2]!= 'o'){//analisa a letra apos o 'c' nao for 'o' o email nao sera valido
        return 1;//retorna o valor 1 para o programa se manter no la�o de repeti��o e o usuario digitar um novo email
    }//fim if

    mail2++;//a variavel com a possi��o do ponto final recebe um acrescimo para verfica��o do final 'com' do email
    if(a[cadastro].email[mail2] != 'm'){//analisa a letrar apos o 'o' nao for 'm' o email nao sera valido
        return 1;//retorna o valor 1 para o programa se manter no la�o de repeti��o e o usuario digitar um novo email
    }//fim if

    mail2++;//a variavel que testou o final 'com' recebe um acrescimo para verificar se o email terminou corretamente
    if(a[cadastro].email[mail2] != '\0'){//analisa se o email terminou com 'com'
        return 1;//retorna o valor 1 para o programa se manter no la�o de repeti��o e o usuario digitar um novo email
    }//fim if

    return 0;//retorna 0 para que o programa saia do la�o de repeti��o com o email valido
}//fim da fun��o

/*VALIDA��O DO CEP*/
int ValidaCEP(struct Agenda *a,int cadastro){//fun��o para validar o CEP
    int i = 0;

    if(strlen(a[cadastro].end.cep)==9){//verifica se o tamanho do CEP � de 9 digitos, caso nao seja o cep nao � valido
        if(a[cadastro].end.cep[5]=='-'){//verifica se o sexto caracter � '-', caso nao seja o CEP nao � valido
            for(i = 0; i < 5; i++){//la�o de repeti��o para analisar os cinco primeiros caracters
                if(a[cadastro].end.cep[i] >= 48 && a[cadastro].end.cep[i] <= 57){//verfica se os caracters s�o numeros, caso nao seja o CEP nao � valido
                }else{//caso nao sejam numeros
                    return 1;//retorna 1 para o programa se manter no la�o de repeti��o e o usuario digitar um novo CEP
                }//fim if else
            }//fim for

            for(i = 6; i < 9; i++){//la�o de repeti��o para analisar os ultimos tres caracters
                if(a[cadastro].end.cep[i] >= 48 && a[cadastro].end.cep[i] <= 57){//verfica se os caracters s�o numeros, caso nao seja o CEP nao � valido
                }else{//se nao forem
                    return 1;//retorna 1 para o programa se manter no la�o de repeti��o e o usuario digitar um novo CEP
                }//fim if else
            }//fim for

            return 0;//retorna 0 para que o programa saia do la�o de repeti��o
        }else{//se o sexto caracter nao for '-'
            return 1;//retorna 1 para o programa se manter no la�o de repeti��o e o usuario digitar um novo CEP
        }//fim if else
    }else{//se o CEP nao possuir 9 caracters
        return 1;//retorna 1 para o programa se manter no la�o de repeti��o e o usuario digitar um novo CEP
    }//fim if else
    return 0;//retorna 0 para que o programa saia do la�o de repeti��o
}//fim da fun��o

/*VALIDA��O DO ESTADO*/
int ValidaESTADO(struct Agenda *a,int cadastro){//fun��o para valida��o do estado
    if(strcmp(a[cadastro].end.estado,"AC")==0){//analisa se o usuario digitou a sigla do estado acre
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"AL")==0){//analisa se o usuario digitou a sigla do estado alagoas
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"AP")==0){//analisa se o usuario digitou a sigla do estado amapa
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"AM")==0){//analisa se o usuario digitou a sigla do estado amazonas
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"BA")==0){//analisa se o usuario digitou a sigla do estado bahia
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"CE")==0){//analisa se o usuario digitou a sigla do estado ceara
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"DF")==0){//analisa se o usuario digitou a sigla do distrito federal
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"ES")==0){//analisa se o usuario digitou a sigla do estado espirito santo
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"GO")==0){//analisa se o usuario digitou a sigla do estado goias
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"MA")==0){//analisa se o usuario digitou a sigla do estado maranhao
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"MT")==0){//analisa se o usuario digitou a sigla do estado mato grosso
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"MS")==0){//analisa se o usuario digitou a sigla do estado mato grosso do sul
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"MG")==0){//analisa se o usuario digitou a sigla do estado minas gerais
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"PA")==0){//analisa se o usuario digitou a sigla do estado para
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"PB")==0){//analisa se o usuario digitou a sigla do estado paraiba
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"PR")==0){//analisa se o usuario digitou a sigla do estado parana
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"PE")==0){//analisa se o usuario digitou a sigla do estado pernambuco
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"PI")==0){//analisa se o usuario digitou a sigla do estado piaui
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"RJ")==0){//analisa se o usuario digitou a sigla do estado rio de janeiro
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"RN")==0){//analisa se o usuario digitou a sigla do estado rio grande do norte
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"RS")==0){//analisa se o usuario digitou a sigla do estado rio grande do sul
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"RO")==0){//analisa se o usuario digitou a sigla do estado rondonia
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"RR")==0){//analisa se o usuario digitou a sigla do estado roraima
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"SC")==0){//analisa se o usuario digitou a sigla do estado santa catarina
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"SP")==0){//analisa se o usuario digitou a sigla do estado sao paulo
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"SE")==0){//analisa se o usuario digitou a sigla do estado sergipe
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else if (strcmp(a[cadastro].end.estado,"TO")==0){//analisa se o usuario digitou a sigla do estado tocantins
        return 0;//caso seja a fun��o retorna 0 para o programa sair do la�o de repeti��o
    }else{//se nao for nenhuma sigla de estado
        return 1;//a fun��o ira retornar 1 e manter o programa no la�o de repeti��o para que o usuario digite um novo estado
    }//fim dos ifs
}//fim da fun��o

/*VALIDA��O DO TELEFONE*/
int ValidaTELEFONE(struct Agenda *a,int cadastro){//fun��o para valida��o do telefone
    int i = 0,
        tel = 0;

    if(strlen(a[cadastro].tel)==13||strlen(a[cadastro].tel)==14){//analise da quantia de caracters do telefone, caso possua 13 caracters verificar se bate com um telefone fixo, caso possua 14 verificar se bate com um celular
        if(a[cadastro].tel[0]=='('&&a[cadastro].tel[3]==')'){//verfica��o se o dd esta entre parenteses

            if(((strlen(a[cadastro].tel)==13)&&(a[cadastro].tel[8]=='-'))||((strlen(a[cadastro].tel)==14)&&(a[cadastro].tel[9]=='-'))){//analise do caracter '-' separando parte do numero telefonico
                for(i = 0; i < strlen(a[cadastro].tel);i++){//analise de quantos caracters nao sao numeros
                    if(a[cadastro].tel[i]>=48&&a[cadastro].tel[i]<=57){//se forem numeros
                    }else{//se nao forem numeros
                        tel++;//a variavel auxiliar vai receber um acrescimo de mais 1
                    }//fim if else
                }//fim for

                if (tel == 3){//se o valor digitado possuir 3 caracters que nao sejam numeros e todos os outros sejam, esta OK
                }else{//caso contrario
                    return 1;//a fun��o ira retornar 1 e manter o programa no la�o de repeti��o para que o usuario digite um numero de telefone
                }//fim if

            }else{//caso o caracter '-' estiver na posi��o errada
                return 1;//a fun��o ira retornar 1 e manter o programa no la�o de repeti��o para que o usuario digite um numero de telefone
            }//fim if else
        }//fim if
    }else{//caso a quantidade de caracters esteja errada
        return 1;//a fun��o ira retornar 1 e manter o programa no la�o de repeti��o para que o usuario digite um numero de telefone
    }//fim if else

    return 0;//retorna 0 para que o programa saia do la�o de repeti��o
}//fim da fun��o

/*VALIDAR DATA DE NASCIMENTO*/
int ValidaDATA(struct Agenda * a,int cadastro){//fun��o para valida��o da data de nascimento
    if(a[cadastro].data.dia<1||a[cadastro].data.dia>30){//verifica��o do valor do dia, se ele for menor que 1 ou maior que 30 a data esta invalida
        return 1;//a fun��o ira retornar 1 e manter o programa no la�o de repeti��o para que o usuario digite uma nova data
    }else if(a[cadastro].data.mes<1||a[cadastro].data.mes>12){//verifica��o do valor do mes, se ele for menor que 1 ou maior que 12 a data esta invalida
        return 1;//a fun��o ira retornar 1 e manter o programa no la�o de repeti��o para que o usuario digite uma nova data
    }else if(a[cadastro].data.ano<1900||a[cadastro].data.ano>2017){//verifica��o do valor do ano, se ele for menor que 1900 ou maior que 2017 a data esta invalida
        return 1;//a fun��o ira retornar 1 e manter o programa no la�o de repeti��o para que o usuario digite uma nova data
    }else if(a[cadastro].data.ano==2017){//verifica��o se � o ano de 2017
        if(a[cadastro].data.mes==12){//se for 2017 e estiver em dezembro, e hoje sendo o ultimo dia de novembro, nao tem como a pessoa ter nascido, portando a data esta invalida
            return 1;//a fun��o ira retornar 1 e manter o programa no la�o de repeti��o para que o usuario digite uma nova data
        }//fim if else
    }//fim if else
    return 0;//retorna 0 para que o programa saia do la�o de repeti��o
}//fim da fun��o

//Gotoxy para ajustar onde ficaram as letras
void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}
