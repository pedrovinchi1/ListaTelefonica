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
struct Endereco{//Estrutura de Endereço
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

/*Declaração de Funções*/
void mostra_dadoNome(struct Agenda *a);//Função para pesquisa por nome
void mostra_dadoMes(struct Agenda *a);//Função para pesquisa por mes
void mostra_dadoTel(struct Agenda *a);//Função para pesquisa por telefone
void ordena_nomes(struct Agenda *a, int x);//Função para listagem por nome
int exclui_dado(struct Agenda *a, int x);//Função para excluir cadastro
void tipos_consulta(struct Agenda *a, int x);//Função para imprimir dados
void gotoxy(int x, int y); //definir posiçao das frases

int ValidaEmail(struct Agenda *a, int cadastro);//Função para validação do email
int ValidaCEP(struct Agenda *a,int cadastro);//Função para validação do CEP
int ValidaESTADO(struct Agenda *a,int cadastro);//Função para validação do Estado
int ValidaTELEFONE(struct Agenda *a,int cadastro);//Função para validação do telefone
int ValidaDATA(struct Agenda * a,int cadastro);//Função para validação da data

/*Programa*/
int main (){
    struct Agenda a[VALOR];
    int i = 0,//variavel padrao para laço de repetição for
        menu = 0,//variavel para acesso ao menu do programa, por switch case
        valid = 1,//variavel auxiliar para as validações
        cadastro = 0;//variavel auxiliar para controle de cadastros

    do {//meno
        system("cls");
        gotoxy(15,2);printf("TRABALHO DE LABORATORIO");//mensagem padrão nome do programa
        gotoxy(15,5);printf("1- Cadastro de pessoas ");//indicação para seleção de cadastro de pessoas
        gotoxy(15,6);printf("2- Consulta por nome ");//indicação para consulta por nome
        gotoxy(15,7);printf("3- Busca pro mes ");//indicação para busca por nome
        gotoxy(15,8);printf("4- Consultar por numero de telefone ");//indicação para consulta de pessoas por numero de telefone
        gotoxy(15,9);printf("5- Listagem de pessoas em ordem alfabetica ");//Indicação para listar o nome de todas as pessoas cadastradas
        gotoxy(15,10);printf("6- Excluir Cadastro ");//indicação para exclusao de cadastro
        gotoxy(15,11);printf("7- Opcoes para listagem de dados ");//indicação para listagem de alguns dados de cada cadastro em ordem alfabetica
        gotoxy(15,12);printf("0- Encerrar o programa ");//para finalizar o programa
        gotoxy(15,13);printf("Digite a sua resposta: ");//mensagem de solicitação de entrada
        scanf("%d",&menu);//entrada de um valor para o menu
        fflush(stdin);//limpeza

        switch(menu){//menu
            case 1://Cadastrar
/*VERIFICAÇÃO SE É POSSIVEL REALIZAR MAIS UM CADASTRO*/
                 system("cls");
                 if(cadastro >= 100){//verificação de quantidade de cadastro
                    printf("\nExcesso de cadastro, caso deseje inserir mais um cadastro favor excluir um cadastro ja existente");//mensagem avisando que ja esta no limite maximo de cadastros aceitos
                    break;//encerra a função de cadastro sem mesmo inicia-la
                }//fim if

/*LEITURA DE DADOS*/
                do{//laço de repetição para limite de cadastro

/*LEITURA DO NOME*/
                    gotoxy(15,2);printf("Cadasto de pessoas");
                    gotoxy(15,5);printf("Nome: ");//mensagem de solicitação de dado
                    gets(a[cadastro].nome);//solicitação de nome
                    fflush(stdin);//limpeza

/*LEITURA E VALIDAÇÂO DE EMAIL*/
                    do{//laço de repetição para leitura e validação de email
                        gotoxy(15,6);printf("Email: ");//mensagem de solicitação de dado
                        gets(a[cadastro].email);//solicitação do email
                        fflush(stdin);//limpeza
                        ValidaEmail(a, cadastro);//validação do email pela função
                        valid=ValidaEmail(a, cadastro);//retorno de verificação de validade
                        if(valid==1){//verificação se o email não é valido
                            gotoxy(15,7);printf("Erro no email");//mensagem para avisar que o email não é  valido
                        }//fim if
                        else{
                            gotoxy(15,7);printf("                        ");
                        }
                    }while(valid==1);//verificação para repetição, se o email nao for valido o laço ira repetir ate que o email seja valido

/*LEITURA ENDEREÇO*/

/*LEITURA RUA*/
                    gotoxy(15,7);printf("Rua: ");//mensagem de solicitação de dado
                    gets(a[cadastro].end.rua);//solicitação de dado de rua
                    fflush(stdin);//limpeza

/*LEITURA NUMERO*/
                    gotoxy(15,8);printf("Numero da Residencia: ");//mensagem de solicitação de dado
                    gets(a[cadastro].end.num_rua);//solicitação de entrada de numero de residencia
                    fflush(stdin);//limpeza

/*LEITURA COMPLEMENTO*/
                    gotoxy(15,9);printf("Complemento: ");//mensagem de solicitação de dado
                    gets(a[cadastro].end.complemento);//solicitação de entrada de complemento
                    fflush(stdin);//limpeza

/*LEITURA BAIRRO*/
                    gotoxy(15,10);printf("Bairro: ");//mensagem de solicitação de dado
                    gets(a[cadastro].end.bairro);//solicitação de entrada de bairro
                    fflush(stdin);//limpeza

/*LEITURA E VALIDAÇÂO CEP*/
                    do{//laço de repetição para leitura e validação do cep
                        gotoxy(15,11);printf("CEP: ");//mensagem de solicitação de dado
                        gets(a[cadastro].end.cep);//solicitação de entrada do CEP
                        ValidaCEP(a,cadastro);//declaração de função para validação do cep
                        valid=ValidaCEP(a,cadastro);//retorno da função de validação

                        if(valid == 1){//verificação de CEP nao valido
                            gotoxy(15,12);printf("Favor digitar um cep valido!");//mensagem de erro
                        }//fim if
                        else{
                            gotoxy(15,12);printf("                               ");
                        }
                    }while(valid == 1);//fim DO, variavel de validação se diferente de 1 sai do lop

/*LEITURA CIDADE*/
                    gotoxy(15,12);printf("Cidade: ");//mensagem de solicitação de dado
                    gets(a[cadastro].end.cidade);//solicitação de entrada da cidade
                    fflush(stdin);//limpeza

/*LEITURA E VALIDAÇÂO ESTADO*/
                    do{//laço de repetição para leitura e validação do estado
                        gotoxy(15,13);printf("Estado (ex:PR): ");//mensagem de solicitação de dado
                        gets(a[cadastro].end.estado);//solicitação de entrada do estado
                        fflush(stdin);//limpeza
                        ValidaESTADO(a,cadastro);//declaração de função para validação do estado
                        valid = ValidaESTADO(a,cadastro);//retorno da função de validação

                        if(valid == 1){//verificação de estado nao valido
                            gotoxy(15,14);printf("Favor digitar um Estado valido!");//mensagem de erro
                        }//fim if
                        else{
                            gotoxy(15,14);printf("                                    ");
                        }
                    }while(valid == 1);//fim DO, variavel de validação diferente de 1 sai do lop

/*LEITURA PAIS*/
                    gotoxy(15,14);printf("Pais: ");//mensagem de solicitação de dado
                    gets(a[cadastro].end.pais);//solicitação de entrada do pais
                    fflush(stdin);//limpeza

/*LEITURA E VALIDAÇÂO TELEFONE*/
                    do{//laço de repetição para leitura e validação do telefone
                        gotoxy(15,15);printf("Telefone:");//mensagem de solicitação de dado
                        gotoxy(15,16);printf("Obs.: Digite (XX)XXXX-XXXX ou (XX)XXXXX-XXXX: ");//mensagem especificando a estada de dado
                        gets(a[cadastro].tel);//solicitação de entrada de numero de telefone
                        fflush(stdin);//limpeza
                        ValidaTELEFONE(a,cadastro);//declaração da função para validação do numero de telefone
                        valid = ValidaTELEFONE(a,cadastro);////retorno da função de validação

                        if(valid == 1){//verificação de telefone não valido
                            gotoxy(15,17);printf("Favor digitar um numero de telefone valido!");//mensagem de erro
                        }//fim if
                        else{
                            gotoxy(15,17); printf("                                           ");
                        }

                    }while(valid == 1);//fim DO, variavel de validação doferente de 1 sai do lop

/*LEITURA E VALIDAÇÂO DATA DE NASCIMENTO*/
                    do{//laço para leitura e validação da data de nascimento
                        gotoxy(15,17);printf("Data de nascimento(dd/mm/aaaa): ");//mensagem de solicitação de dado
                        scanf("%d/%d/%d",&a[cadastro].data.dia,&a[cadastro].data.mes,&a[cadastro].data.ano);//solicitação da entrada de data de nascimento
                        fflush(stdin);//limpeza
                        ValidaDATA(a,cadastro);//declaração de função para validação da data
                        valid=ValidaDATA(a,cadastro);//retorno da função

                        if(valid == 1){//verficação de data invalida
                            gotoxy(15,18);printf("Favor digitar uma data valida!");//mensagem de erro
                        }//fim if
                        else{
                            gotoxy(15,18); printf("                                ");
                        }

                    }while(valid == 1);//fim DO, se variavel de validação diferente de 1 sai do lopo

/*LEITURA OBSERVAÇÔES*/
                    gotoxy(15,18);printf("Observacoes: ");//mensagem de solicitação de dado
                    gets(a[cadastro].obs);//solicitação de entrada de validação
                    fflush(stdin);//limpeza


/*FIM DE CADASTRO, ACRESCIMO NO CONTADOR*/

                    cadastro++;//acrescimo do contador
                    break;//encerramento do cadastro

                }while(cadastro < 100);//teste de verificação do laço de repitição, se ja existirem 100 cadastros, não sera possivel realizar um novo.

                break;//fim case 1

            case 2://Consulta por nome
                mostra_dadoNome(a);//declaração de função para consulta por nome
                break;//fim case 2

            case 3://listagem por aniversariantes do mes especifico
                mostra_dadoMes(a);//declaração de variavel
                break;//fim case 3

            case 4://Consulta por telefone
                mostra_dadoTel(a);//chamada da função que realiza pesquisa por telefone
                break;//fim case 4

            case 5://Listagem de pessoas cadastradas em ordem alfabetica
                ordena_nomes(a,cadastro);//chamada da função que ordena os nomes em ordem alfabetica
                break;//fim case 5

            case 6://Excluir cadastros
                exclui_dado(a,cadastro);
                cadastro = exclui_dado(a,cadastro);
                break;

            case 7://Listagem de nome, telefone e email dos cadastros em ordem alfabetica
                tipos_consulta(a,cadastro);//chamada da função com opções de imprimir dado com 3 maneiras diferentes
                break;//fim case 7

            case 0://encerrar o programa
                return 0;//retorno, para encerrar o programa
                break;//fim case 0

            default://se acontecer do usuario digitar um valor errado
                printf("\nOpcao invalida.\nPor favor! Digite uma opcao valida.\n");//aviso de erro

        }//fim do switch

    }while(1);//fim DO, laço de repetição infinito,

return 0;//fim do programa
}//fim do programa

/*Funções Sem Retorno*/

/*PESQUISA POR NOME*/
void mostra_dadoNome(struct Agenda *a){//Pesquisa por nome
    char nome[VALOR];
    int i,
        j=0;
    system("cls");//limpar a tela do programa
    gotoxy(15,2);printf("PESQUISA POR NOME");//mensagem inicial
    gotoxy(15,3);printf("Digite o nome a ser pesquisado: ");//mensagem de solicitação de dado
    gets(nome);//solicitação de entrada do nome
    system("cls");//limpar a tela do programa
    for(i=0;i<VALOR;i++){//laço de repetição por pesquisa
        if(strcmp(a[i].nome, nome) == 0){//confere se o nome bate
            gotoxy(15,2);printf("Nome: %s ",a[i].nome);//escreve o nome da pessoa
            gotoxy(15,3);printf("Email: %s " ,a[i].email);//escreve o email da pessoa
            gotoxy(15,4);printf("Rua: %s " ,a[i].end.rua);//escreve o nome da rua da pessoa
            gotoxy(15,5);printf("Numero da residencia: %s " ,a[i].end.num_rua);//escreve o numero da casa da pessoa
            gotoxy(15,6);printf("Complemento: %s \n" ,a[i].end.complemento);//escreve o complento de endereço da pessoa
            gotoxy(15,7);printf("Bairro: %s " ,a[i].end.bairro);//escreve o bairro da pessoa
            gotoxy(15,8);printf("CEP: %s " ,a[i].end.cep);//escreve o cep da pessoa
            gotoxy(15,9);printf("Cidade: %s " ,a[i].end.cidade);//escreve a cidade da pessoa
            gotoxy(15,10);printf("Estado: %s " ,a[i].end.estado);//escreve o estado da pessoa
            gotoxy(15,11);printf("Pais: %s " ,a[i].end.pais);//escreve o pais da pessoa
            gotoxy(15,12);printf("Telefone: %s " ,a[i].tel);//escreve o telefone da pessoa
            gotoxy(15,13);printf("Data de nascimento: %d/%d/%d " ,a[i].data.dia,a[i].data.mes,a[i].data.ano);//escreve a data de nascimento da pessoa
            gotoxy(15,14);printf("Observacoes: %s " ,a[i].obs);//escreve as observações feitas sobre as pessoas
            getch();//espera um caracter para mostrar a proxima pessoa se tiver, ou voltar ao menu caso nao tenha uma proxima pessoa
            system("cls");//limpar a tela
        }//fim if
    }//fim do laço de repetição
}//fim da função

/*PESQUISA POR MES*/
void mostra_dadoMes(struct Agenda *a){//pesquisa por mes
    int mes;
    int i,
        j=0;
    system("cls");//limpar a tela do programa
    gotoxy(15,2);printf("PESQUISA POR MES ");//mensagem inicial
    gotoxy(15,3);printf("Digite o mes a ser pesquisado: ");//mensagem de solicitação de dado
    scanf("%d",&mes);//solicitação de entrada do mes
    system("cls");//limpar a tela do programa
    for(i=0;i<VALOR;i++){//laço de repetição por pesquisa
        if(a[i].data.mes == mes){//confere se o mes bate
            gotoxy(15,2);printf("Nome: %s ",a[i].nome);//escreve o nome da pessoa
            gotoxy(15,3);printf("Email: %s " ,a[i].email);//escreve o email da pessoa
            gotoxy(15,4);printf("Rua: %s " ,a[i].end.rua);//escreve o nome da rua da pessoa
            gotoxy(15,5);printf("Numero da residencia: %s " ,a[i].end.num_rua);//escreve o numero da casa da pessoa
            gotoxy(15,6);printf("Complemento: %s " ,a[i].end.complemento);//escreve o complento de endereço da pessoa
            gotoxy(15,7);printf("Bairro: %s " ,a[i].end.bairro);//escreve o bairro da pessoa
            gotoxy(15,8);printf("CEP: %s " ,a[i].end.cep);//escreve o cep da pessoa
            gotoxy(15,9);printf("Cidade: %s " ,a[i].end.cidade);//escreve a cidade da pessoa
            gotoxy(15,10);printf("Estado: %s " ,a[i].end.estado);//escreve o estado da pessoa
            gotoxy(15,11);printf("Pais: %s " ,a[i].end.pais);//escreve o pais da pessoa
            gotoxy(15,12);printf("Telefone: %s " ,a[i].tel);//escreve o telefone da pessoa
            gotoxy(15,13);printf("Data de nascimento: %d/%d/%d " ,a[i].data.dia,a[i].data.mes,a[i].data.ano);//escreve a data de nascimento da pessoa
            gotoxy(15,14);printf("Observacoes: %s " ,a[i].obs);//escreve as observações feitas sobre as pessoas
            getch();//espera um caracter para mostrar a proxima pessoa se tiver, ou voltar ao menu caso nao tenha uma proxima pessoa
            system("cls");//limpar a tela
        }//fim if
    }//fim do laço de repetição
}//fim da função

/*FUMÇÃO PARA PESQUISAR POR TELEFONE*/
void mostra_dadoTel(struct Agenda *a){
    char tel[VALOR];
    int i,
        j=0,
        cont=0;
    system("cls");//limpa a tela
    gotoxy(15,2);printf("PESQUISA POR TELEFONE");//mensagem inicial
    gotoxy(15,3);printf("Digite o telefone a ser pesquisado: ");//mensagem solicitando entrada de dado
    gets(tel);//solicitação de entrada de dado

    system("cls");//limpa a tela
    for(i=0;i<VALOR;i++){//laço para verificação
        if(strcmp(a[i].tel, tel) == 0){//confere so os dados batem
            gotoxy(15,2);printf("Nome: %s ",a[i].nome);//escreve o nome da pessoa
            gotoxy(15,3);printf("Email: %s " ,a[i].email);//escreve o email da pessoa
            gotoxy(15,4);printf("Rua: %s " ,a[i].end.rua);//escreve o nome da rua da pessoa
            gotoxy(15,5);printf("Numero da residencia: %s " ,a[i].end.num_rua);//escreve o numero da casa da pessoa
            gotoxy(15,6);printf("Complemento: %s " ,a[i].end.complemento);//escreve o complento de endereço da pessoa
            gotoxy(15,7);printf("Bairro: %s " ,a[i].end.bairro);//escreve o bairro da pessoa
            gotoxy(15,8);printf("CEP: %s " ,a[i].end.cep);//escreve o cep da pessoa
            gotoxy(15,9);printf("Cidade: %s " ,a[i].end.cidade);//escreve a cidade da pessoa
            gotoxy(15,10);printf("Estado: %s " ,a[i].end.estado);//escreve o estado da pessoa
            gotoxy(15,11);printf("Pais: %s " ,a[i].end.pais);//escreve o pais da pessoa
            gotoxy(15,12);printf("Telefone: %s " ,a[i].tel);//escreve o telefone da pessoa
            gotoxy(15,13);printf("Data de nascimento: %d/%d/%d " ,a[i].data.dia,a[i].data.mes,a[i].data.ano);//escreve a data de nascimento da pessoa
            gotoxy(15,14);printf("Observacoes: %s " ,a[i].obs);//escreve as observações feitas sobre as pessoas
            getch();//espera um caracter para mostrar a proxima pessoa se tiver, ou voltar ao menu caso nao tenha uma proxima pessoa
            system("cls");//limpar a tela
        }//fim if
    }//fim for
}//fim da função

/*FUNÇÃO PARA ORDERNAR POR NOME*/
void ordena_nomes(struct Agenda *a, int x){//FUNÇÃO PARA ORDENAÇÃO UTILIZANDO O METODO BUBBLESORT
    struct Agenda b;
    char aux[VALOR];
    int i,
        j;
    for(i = 0; i < x-1 ; i++){//laço para ordenação
        for(j = i + 1;j < x; j++){//segundo laço para ordenação
            if(strcmp(a[i].nome,a[j].nome)> 0){//verificação de qual nome vem antes
                b = a[i];//caso o segundo nome venha antes o primeiro nome vai pra uma variavel auxiliar
                a[i] = a[j];//o segundo toma o lugar do primeiro
                a[j] = b;//o primeiro vai que esta em uma variavel auxiliar vai pro lugar do segundo
            }
        }
    }

    for(i=0;i<x;i++){//laço de repetição para imprimir
        system("cls");//limpar a tela do programa
        printf("Nomes em ordem alfabetica");//mensagem inicial
        printf("Nome: %s \n",a[i].nome);//escreve o nome da pessoa
        getch();//espera um caracter para mostrar a proxima pessoa se tiver, ou voltar ao menu caso nao tenha uma proxima pessoa
        system("cls");//limpar a tela
    }
}

/*FUNÇÃO PARA EXCLUIR UM CONTATO*/
int exclui_dado(struct Agenda *a, int x){//função para excluir cadastros
    char nome[VALOR],
        email[VALOR];
    int i,
        j,
        contador = 0;
    system("cls");//limpa a tela
    gotoxy(15,2);printf("EXCLUSAO DE DADOS");//mensagem inicial
    gotoxy(15,3);printf("Digite o nome do contato: ");//mensagem solicitando um dado
    gets(nome);//solitação de entrada de dado


    for(i=0;i<x;i++){//laço de repetição para analise de nomes repetidos
        if((strcmp(a[i].nome,nome) == 0)){//verificação de compatibilidade do nome
            contador ++;//caso encontre o nome a variavel acrescenta 1
        }//fim if
    }//fim for

    if(contador > 1){//se tiver nomes repetidos
        gotoxy(15,4);printf("Existe mais de um cadastro com esse nome, por favor digite o email da pessoa para seja excuido o cadastro correto: ");//mensagem para solicitar mais uma informação para analise
        gets(email);//solicitação de entrada de dado
        for(i=0;i<x;i++){//laço para analise de dados
            if((strcmp(a[i].nome,nome) == 0) &&(strcmp(a[i].email,email)==0)){//se encontrar um nome e email compativel
                for(j=i; j<x-1; j++){//laço para exclusao
                    a[j] = a[j+1];//excuil os dados passando substituindo ele pelo subsequente
                }// fim for
            x--;// contador de cadastro decresce 1
            return x;//retorna a quantidade de cadastros ainda existentes
            }//fim for
        }//fim for

        }else if (contador == 0){//se nao ouver 1 pessoa sequer cadastrada com o nome
            gotoxy(15,4);printf("Pessoa nao cadastrada");//avisa que a pessoa não esta cadastrada
            return x;//e retorna o mesmo valor antigo de cadastro existentes

        }else{//se ouver apenas uma pessoa cadastrada nao precisa de mais nenhuma informação
            for(i=0;i<x;i++){//laço para procura da pessoa
                if((strcmp(a[i].nome,nome) == 0)){//analise de compatibilidade
                    for(j=i; j<x-1; j++){//laço para exclusao
                        a[j] = a[j+1];//substitiu um valor pelo antigo
                    }//fim if
                }//fim for
            x--;//quantidade de pessoas cadastradas decai 1
            return x;//retorna
            }
        }
        return x;
}

/*FUNÇÂO PARA IMPRESSÂO*/
void tipos_consulta(struct Agenda *a, int x){
    struct Agenda b;
    int i,
        j,
        resp;
    system("cls");
    gotoxy(15,2);printf("OPCOES DE CONSULTA DE DADOS");
    gotoxy(15,5);printf("1- Imprime nome, telefone e e-mail (ordem alfabetica de nome) ");//opção de listagem 1
    gotoxy(15,6);printf("2- Imprime nome, telefone e e-mail (separado por localidade) ");//opção de listagem 2
    gotoxy(15,7);printf("3- Imprime todos os dados (ordem alfabetica de nome) ");//opção  de listagem 3
    gotoxy(15,8);printf("Digite qual opcao de consulta voce deseja?:");//mensagem solicitando dado
    scanf("%d", &resp);//solicitação de entrada de dado
    fflush(stdin);

    switch(resp){//sub menu
        case 1://ordena em ordem alfabetica mostrando menos detalhes
             for(i = 0; i < x-1 ; i++){//laço para ordenação
                for(j = i + 1;j < x; j++){//segundo laço para ordenação
                    if(strcmp(a[i].nome,a[j].nome)> 0){//verificação de qual nome vem antes
                        b = a[i];//caso o segundo nome venha antes o primeiro nome vai pra uma variavel auxiliar
                        a[i] = a[j];//o segundo toma o lugar do primeiro
                        a[j] = b;//o primeiro vai que esta em uma variavel auxiliar vai pro lugar do segundo
                    }//fim if
                }//fim for
            }//fim for

            for(i=0;i<x;i++){//laço para impressão
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
                for(i = 0; i < x-1 ; i++){//laço para ordenação
                for(j = i + 1;j < x; j++){//segundo laço para ordenação
                    if(strcmp(a[i].nome,a[j].nome)> 0){//verificação de qual nome vem antes
                        b = a[i];//caso o segundo nome venha antes o primeiro nome vai pra uma variavel auxiliar
                        a[i] = a[j];//o segundo toma o lugar do primeiro
                        a[j] = b;//o primeiro vai que esta em uma variavel auxiliar vai pro lugar do segundo
                    }//fim if
                }//fim for
            }//fim for

            for(i=0;i<x;i++){//laço para impressao
                system("cls");//limpar a tela do programa
                gotoxy(15,2);printf("Nomes em ordem alfabetica de estados");//mensagem inicial
                gotoxy(15,5);printf("Nome: %s \n",a[i].nome);//escreve o nome da pessoa
                gotoxy(15,6);printf("Email: %s \n" ,a[i].email);//escreve o email da pessoa
                gotoxy(15,7);printf("Telefone: %s \n" ,a[i].tel);//escreve o telefone da pessoa
                getch();//espera um caracter para mostrar a proxima pessoa se tiver, ou voltar ao menu caso nao tenha uma proxima pessoa
                system("cls");//limpar a tela
            }//fim for

        case 3://ordena em ordem alfabetica imprimindo mais dados
            for(i = 0; i < x-1 ; i++){//laço para ordenação
                for(j = i + 1;j < x; j++){//segundo laço para ordenação
                    if(strcmp(a[i].nome,a[j].nome)> 0){//verificação de qual nome vem antes
                        b = a[i];//caso o segundo nome venha antes o primeiro nome vai pra uma variavel auxiliar
                        a[i] = a[j];//o segundo toma o lugar do primeiro
                        a[j] = b;//o primeiro vai que esta em uma variavel auxiliar vai pro lugar do segundo
                    }//fim if
                }//fim for
            }//fim for

            for(i=0;i<x;i++){//laço para impressão
                system("cls");//limpar a tela do programa
                gotoxy(15,2);printf("Nomes em ordem alfabetica");//mensagem inicial
                gotoxy(15,5);printf("Nome: %s ",a[i].nome);//escreve o nome da pessoa
                gotoxy(15,6);printf("Email: %s " ,a[i].email);//escreve o email da pessoa
                gotoxy(15,7);printf("Rua: %s " ,a[i].end.rua);//escreve o nome da rua da pessoa
                gotoxy(15,8);printf("Numero da residencia: %s " ,a[i].end.num_rua);//escreve o numero da casa da pessoa
                gotoxy(15,9);printf("Complemento: %s " ,a[i].end.complemento);//escreve o complento de endereço da pessoa
                gotoxy(15,10);printf("Bairro: %s " ,a[i].end.bairro);//escreve o bairro da pessoa
                gotoxy(15,11);printf("CEP: %s " ,a[i].end.cep);//escreve o cep da pessoa
                gotoxy(15,12);printf("Cidade: %s " ,a[i].end.cidade);//escreve a cidade da pessoa
                gotoxy(15,13);printf("Estado: %s " ,a[i].end.estado);//escreve o estado da pessoa
                gotoxy(15,14);printf("Pais: %s " ,a[i].end.pais);//escreve o pais da pessoa
                gotoxy(15,15);printf("Telefone: %s " ,a[i].tel);//escreve o telefone da pessoa
                gotoxy(15,16);printf("Data de nascimento: %d/%d/%d " ,a[i].data.dia,a[i].data.mes,a[i].data.ano);//escreve a data de nascimento da pessoa
                gotoxy(15,17);printf("Observacoes: %s " ,a[i].obs);//escreve as observações feitas sobre as pessoas
                getch();//espera um caracter para mostrar a proxima pessoa se tiver, ou voltar ao menu caso nao tenha uma proxima pessoa
                system("cls");//limpar a tela
            }//fim for
        break;//fim case 3

        default://para quando o usuario digitar uma opção invalida
            printf("opção invalida");//caso o usuario digite um valor invalidado
    }//fim switch case
}//fim da função

/*Funções com Retorno*/

/*VAILDAÇÃO DO EMAIL*/
int ValidaEmail(struct Agenda *a, int cadastro){//função para validar o email
	int i=0,
	mail = 0,
    mail2 = 0;

    for(i = 0;i < VALOR;i++){//laço para procurar o @
        if(a[cadastro].email[i]=='@'){//analise de caracter para ver se é o @
            mail = i;//caso seja a variavel vai receber sua posição
        }//fim if
    }//fim for

    if(mail < 2){//verificação da posição do @
		return 1;//retorna o valor 1 para o programa se manter no laço de repetição e o usuario digitar um novo email
    }//fim if

    for(i = mail; i < VALOR;i++){//laço para verificar a posição do primeiro ponto final, apos o caracter @
        if(a[cadastro].email[i]=='.'){//se encontrar o ponto final
            mail2 = i;//a variavel de validação recebe a posição dele
        }//fim if
    }//fim for

    if(mail2 == 0){//se nao existir o ponto final, o email nao e valido
        return 1;//retorna o valor 1 para o programa se manter no laço de repetição e o usuario digitar um novo email
    }//fim if

    else if((mail2 - mail) <= 3){//verificação de quantos caracters existem entre o caracter arroba e o caracter .
        // caso entre no if a distancia sera menor ou igaul a dois, e portanto o email nao sera valido
        return 1;//retorna o valor 1 para o programa se manter no laço de repetição e o usuario digitar um novo email
    }//fim if

    mail2++;//a variavel com a possição do ponto final recebe um acrescimo para verficação do final 'com' do email
    if(a[cadastro].email[mail2]!= 'c'){//analisa a letra apos o '.' nao for 'c' o email nao sera valido
        return 1;//retorna o valor 1 para o programa se manter no laço de repetição e o usuario digitar um novo email
    }//fim if

    mail2++;//a variavel com a possição do ponto final recebe um acrescimo para verficação do final 'com' do email
    if(a[cadastro].email[mail2]!= 'o'){//analisa a letra apos o 'c' nao for 'o' o email nao sera valido
        return 1;//retorna o valor 1 para o programa se manter no laço de repetição e o usuario digitar um novo email
    }//fim if

    mail2++;//a variavel com a possição do ponto final recebe um acrescimo para verficação do final 'com' do email
    if(a[cadastro].email[mail2] != 'm'){//analisa a letrar apos o 'o' nao for 'm' o email nao sera valido
        return 1;//retorna o valor 1 para o programa se manter no laço de repetição e o usuario digitar um novo email
    }//fim if

    mail2++;//a variavel que testou o final 'com' recebe um acrescimo para verificar se o email terminou corretamente
    if(a[cadastro].email[mail2] != '\0'){//analisa se o email terminou com 'com'
        return 1;//retorna o valor 1 para o programa se manter no laço de repetição e o usuario digitar um novo email
    }//fim if

    return 0;//retorna 0 para que o programa saia do laço de repetição com o email valido
}//fim da função

/*VALIDAÇÃO DO CEP*/
int ValidaCEP(struct Agenda *a,int cadastro){//função para validar o CEP
    int i = 0;

    if(strlen(a[cadastro].end.cep)==9){//verifica se o tamanho do CEP é de 9 digitos, caso nao seja o cep nao é valido
        if(a[cadastro].end.cep[5]=='-'){//verifica se o sexto caracter é '-', caso nao seja o CEP nao é valido
            for(i = 0; i < 5; i++){//laço de repetição para analisar os cinco primeiros caracters
                if(a[cadastro].end.cep[i] >= 48 && a[cadastro].end.cep[i] <= 57){//verfica se os caracters são numeros, caso nao seja o CEP nao é valido
                }else{//caso nao sejam numeros
                    return 1;//retorna 1 para o programa se manter no laço de repetição e o usuario digitar um novo CEP
                }//fim if else
            }//fim for

            for(i = 6; i < 9; i++){//laço de repetição para analisar os ultimos tres caracters
                if(a[cadastro].end.cep[i] >= 48 && a[cadastro].end.cep[i] <= 57){//verfica se os caracters são numeros, caso nao seja o CEP nao é valido
                }else{//se nao forem
                    return 1;//retorna 1 para o programa se manter no laço de repetição e o usuario digitar um novo CEP
                }//fim if else
            }//fim for

            return 0;//retorna 0 para que o programa saia do laço de repetição
        }else{//se o sexto caracter nao for '-'
            return 1;//retorna 1 para o programa se manter no laço de repetição e o usuario digitar um novo CEP
        }//fim if else
    }else{//se o CEP nao possuir 9 caracters
        return 1;//retorna 1 para o programa se manter no laço de repetição e o usuario digitar um novo CEP
    }//fim if else
    return 0;//retorna 0 para que o programa saia do laço de repetição
}//fim da função

/*VALIDAÇÃO DO ESTADO*/
int ValidaESTADO(struct Agenda *a,int cadastro){//função para validação do estado
    if(strcmp(a[cadastro].end.estado,"AC")==0){//analisa se o usuario digitou a sigla do estado acre
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"AL")==0){//analisa se o usuario digitou a sigla do estado alagoas
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"AP")==0){//analisa se o usuario digitou a sigla do estado amapa
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"AM")==0){//analisa se o usuario digitou a sigla do estado amazonas
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"BA")==0){//analisa se o usuario digitou a sigla do estado bahia
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"CE")==0){//analisa se o usuario digitou a sigla do estado ceara
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"DF")==0){//analisa se o usuario digitou a sigla do distrito federal
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"ES")==0){//analisa se o usuario digitou a sigla do estado espirito santo
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"GO")==0){//analisa se o usuario digitou a sigla do estado goias
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"MA")==0){//analisa se o usuario digitou a sigla do estado maranhao
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"MT")==0){//analisa se o usuario digitou a sigla do estado mato grosso
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"MS")==0){//analisa se o usuario digitou a sigla do estado mato grosso do sul
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"MG")==0){//analisa se o usuario digitou a sigla do estado minas gerais
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"PA")==0){//analisa se o usuario digitou a sigla do estado para
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"PB")==0){//analisa se o usuario digitou a sigla do estado paraiba
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"PR")==0){//analisa se o usuario digitou a sigla do estado parana
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"PE")==0){//analisa se o usuario digitou a sigla do estado pernambuco
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"PI")==0){//analisa se o usuario digitou a sigla do estado piaui
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"RJ")==0){//analisa se o usuario digitou a sigla do estado rio de janeiro
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"RN")==0){//analisa se o usuario digitou a sigla do estado rio grande do norte
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"RS")==0){//analisa se o usuario digitou a sigla do estado rio grande do sul
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"RO")==0){//analisa se o usuario digitou a sigla do estado rondonia
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"RR")==0){//analisa se o usuario digitou a sigla do estado roraima
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"SC")==0){//analisa se o usuario digitou a sigla do estado santa catarina
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"SP")==0){//analisa se o usuario digitou a sigla do estado sao paulo
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"SE")==0){//analisa se o usuario digitou a sigla do estado sergipe
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else if (strcmp(a[cadastro].end.estado,"TO")==0){//analisa se o usuario digitou a sigla do estado tocantins
        return 0;//caso seja a função retorna 0 para o programa sair do laço de repetição
    }else{//se nao for nenhuma sigla de estado
        return 1;//a função ira retornar 1 e manter o programa no laço de repetição para que o usuario digite um novo estado
    }//fim dos ifs
}//fim da função

/*VALIDAÇÃO DO TELEFONE*/
int ValidaTELEFONE(struct Agenda *a,int cadastro){//função para validação do telefone
    int i = 0,
        tel = 0;

    if(strlen(a[cadastro].tel)==13||strlen(a[cadastro].tel)==14){//analise da quantia de caracters do telefone, caso possua 13 caracters verificar se bate com um telefone fixo, caso possua 14 verificar se bate com um celular
        if(a[cadastro].tel[0]=='('&&a[cadastro].tel[3]==')'){//verficação se o dd esta entre parenteses

            if(((strlen(a[cadastro].tel)==13)&&(a[cadastro].tel[8]=='-'))||((strlen(a[cadastro].tel)==14)&&(a[cadastro].tel[9]=='-'))){//analise do caracter '-' separando parte do numero telefonico
                for(i = 0; i < strlen(a[cadastro].tel);i++){//analise de quantos caracters nao sao numeros
                    if(a[cadastro].tel[i]>=48&&a[cadastro].tel[i]<=57){//se forem numeros
                    }else{//se nao forem numeros
                        tel++;//a variavel auxiliar vai receber um acrescimo de mais 1
                    }//fim if else
                }//fim for

                if (tel == 3){//se o valor digitado possuir 3 caracters que nao sejam numeros e todos os outros sejam, esta OK
                }else{//caso contrario
                    return 1;//a função ira retornar 1 e manter o programa no laço de repetição para que o usuario digite um numero de telefone
                }//fim if

            }else{//caso o caracter '-' estiver na posição errada
                return 1;//a função ira retornar 1 e manter o programa no laço de repetição para que o usuario digite um numero de telefone
            }//fim if else
        }//fim if
    }else{//caso a quantidade de caracters esteja errada
        return 1;//a função ira retornar 1 e manter o programa no laço de repetição para que o usuario digite um numero de telefone
    }//fim if else

    return 0;//retorna 0 para que o programa saia do laço de repetição
}//fim da função

/*VALIDAR DATA DE NASCIMENTO*/
int ValidaDATA(struct Agenda * a,int cadastro){//função para validação da data de nascimento
    if(a[cadastro].data.dia<1||a[cadastro].data.dia>30){//verificação do valor do dia, se ele for menor que 1 ou maior que 30 a data esta invalida
        return 1;//a função ira retornar 1 e manter o programa no laço de repetição para que o usuario digite uma nova data
    }else if(a[cadastro].data.mes<1||a[cadastro].data.mes>12){//verificação do valor do mes, se ele for menor que 1 ou maior que 12 a data esta invalida
        return 1;//a função ira retornar 1 e manter o programa no laço de repetição para que o usuario digite uma nova data
    }else if(a[cadastro].data.ano<1900||a[cadastro].data.ano>2017){//verificação do valor do ano, se ele for menor que 1900 ou maior que 2017 a data esta invalida
        return 1;//a função ira retornar 1 e manter o programa no laço de repetição para que o usuario digite uma nova data
    }else if(a[cadastro].data.ano==2017){//verificação se é o ano de 2017
        if(a[cadastro].data.mes==12){//se for 2017 e estiver em dezembro, e hoje sendo o ultimo dia de novembro, nao tem como a pessoa ter nascido, portando a data esta invalida
            return 1;//a função ira retornar 1 e manter o programa no laço de repetição para que o usuario digite uma nova data
        }//fim if else
    }//fim if else
    return 0;//retorna 0 para que o programa saia do laço de repetição
}//fim da função

//Gotoxy para ajustar onde ficaram as letras
void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}
