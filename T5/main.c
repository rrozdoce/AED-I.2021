/*
Trabalho 5 AEDI-I

Alunos:

Henrique Gettner de Oliveira RGM: 45767
Henrique Apolinário Iwamizu Tada RGM: 43927
Leandro Madeira de Oliveira RGM: 45280
Guilherme Garcia Gloor RGM: 45535
Felipe Echeverria Vilhalva RGM: 45611
*/

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 50

#define ERRO_OPCAO printf("\nOPCAO INVALIDA!\nTENTE NOVAMENTE . . .\n\n")
#define ERRO_VENDA printf("\nNENHUMA VENDA FOI CADASTRADA AINDA!")
#define ERRO_CLIENTE printf("\nNAO EXISTE NENHUM CLIENTE CADASTRADO AINDA!")
#define ERRO_CARRO printf("\nNAO EXISTE NENHUM CARRO CADASTRADO AINDA!")
#define ERRO_DISPONIBILIDADE_CARRO printf("\nNENHUM CARRO ESTA DISPONIVEL PARA VENDA!")
#define ERRO_LIMITE printf("\nLIMITE DE CADASTROS ATINGIDO!")
#define RETORNA printf("\nRETORNANDO . . .")

char opcionais[][TAM] = {{"4.portas"}, {"cambio.automatico"}, {"vidros.eletricos"}, {"abs"}, {"air.bag"}, {"ar.condicionado"}, {"banco.couro"}, {"sensor.estacionamento"}};

char estados[][3] = {{"AC"}, {"AL"}, {"AP"}, {"AM"}, {"BA"}, {"CE"}, {"DF"}, {"ES"}, {"GO"}, {"MA"}, {"MT"}, {"MS"}, {"MG"}, {"PA"}, {"PB"}, {"PR"}, {"PE"}, {"PI"}, {"RJ"}, {"RN"}, {"RS"}, {"RO"}, {"RR"}, {"SC"}, {"SP"}, {"SE"}, {"TO"}};

char cidades[][TAM] = {{"Rio Branco"}, {"Maceio"}, {"Macapa"}, {"Manaus"}, {"Salvador"}, {"Fortaleza"}, {"Brasilia"}, {"Vitoria"}, {"Goiania"}, {"Sao Luis"}, {"Cuiaba"}, {"Campo Grande"}, {"Belo Horizonte"}, {"Belem"}, {"Joao Pessoa"}, {"Curitiba"}, {"Recife"}, {"Teresina"}, {"Rio de Janeiro"}, {"Natal"}, {"Porto Alegre"}, {"Porto Velho"}, {"Boa Vista"}, {"Florianopolis"}, {"Sao Paulo"}, {"Aracaju"}, {"Palmas"}};

char nomes[][TAM] = {{"Maria"}, {"Jose"}, {"Antonio"}, {"Joao"}, {"Francisco"}, {"Ana"}, {"Luiz"}, {"Paulo"}, {"Adriana"}, {"Marcia"}, {"Vera"}, {"Sandra"}, {"Edson"}, {"Roberto"}, {"Rita"}};

char sobrenomes[][TAM] = {{"Silva"}, {"Santos"}, {"Oliveira"}, {"Souza"}, {"Lima"}, {"Pereira"}, {"Ferreira"}, {"Costa"}, {"Rodrigues"}, {"Almeida"}, {"Nascimento"}, {"Alves"}, {"Carvalho"}, {"Araujo"}, {"Ribeiro"}};

char modelos[][15] = {{"Astra"}, {"Corsa"}, {"Cruze"}, {"Opala"}, {"Prisma"}, {"Palio"}, {"Siena"}, {"Uno"}, {"Punto"}, {"Linea"}, {"Taro"}, {"Fox"}, {"Gol"}, {"Voyage"}, {"Polo"}};

struct CARRO
{
    char placa[9];         // AAA-1234
    char modelo[TAM];      // gol, celta, palio, ...
    char fabricante[TAM];  // chevrolet, fiat, ...
    int ano_fabricacao;    // 1980 à 2016
    int ano_modelo;        // 1980 à 2017
    char combustivel[TAM]; // alcool, gasolina, flex, diesel
    char cor[TAM];         // branca, prata, preta
    int opcional[8];       // ver matriz opcionais
    float preco_compra;
};

struct ENDERECO
{
    char rua[TAM];
    int numero;
    char bairro[TAM];
    char cidade[TAM];
    char estado[3];
    char cep[11]; // 99.999-999
};

struct TELEFONE
{
    char telefone[14]; // 99 99999-9999
};

struct CLIENTE
{
    int cod_cli;
    char nome[TAM];
    struct ENDERECO endereco;
    struct TELEFONE residencial;
    struct TELEFONE celular[5];
    float renda_mensal;
};

struct DATA
{
    int dia, mes, ano;
};

struct VENDA_CARRO
{
    char placa[9]; // AAA-1234
    int cod_cli;
    float preco_venda;
    struct DATA data_venda;
};

struct CADASTROS_VENDAS
{
    struct CLIENTE cliente;
    struct CARRO carro;
    struct VENDA_CARRO venda_carro;
};

struct CLIENTE cadastro_clientes[TAM];
struct CARRO cadastro_carros[TAM];
struct CARRO carros_disponiveis[TAM];

struct VENDA_CARRO cadastro_vendas[TAM];
struct CADASTROS_VENDAS dados_vendas[TAM];

int qnt_clientes = 0, qnt_carros = 0, qnt_carros_disponiveis = 0, qnt_vendas = 0;

char gera_alfabeto()
{
    int i;
    char letras[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    i = rand() % 26;
    return (letras[i]);
}

char gera_numero()
{
    int i;
    char numeros[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    i = rand() % 9;
    return (numeros[i]);
}

int gera_codigo()
{
    int i = 0, verifica, num;

    if (qnt_clientes > 0)
    {
        do
        {
            num = rand() % 1000;

            if (num == cadastro_clientes[i].cod_cli)
                verifica = 0;
            else
                verifica = 1;

            i++;
        } while (verifica != 1 && i < qnt_clientes);
    }
    else
        num = rand() % 1000;

    return (num);
}

void gera_nome(char *nome)
{
    char nome_completo[TAM];
    int n, s;

    n = rand() % 15;
    s = rand() % 15;

    strcpy(nome_completo, nomes[n]);
    strcat(nome_completo, " ");
    strcat(nome_completo, sobrenomes[s]);

    strcpy(nome, nome_completo);
}

void gera_rua(char *rua)
{
    char rua_auxiliar[15];
    char identificacao[3];

    identificacao[0] = gera_numero();
    identificacao[1] = gera_numero();
    identificacao[2] = '\0';

    strcpy(rua_auxiliar, "Rua ");
    strcat(rua_auxiliar, identificacao);
    strcpy(rua, rua_auxiliar);
}

void gera_bairro(char *bairro)
{
    char bairro_auxiliar[15];
    char identificacao[2];

    identificacao[0] = gera_alfabeto();
    identificacao[1] = '\0';

    strcpy(bairro_auxiliar, "Bairro ");
    strcat(bairro_auxiliar, identificacao);
    strcpy(bairro, bairro_auxiliar);
}

void gera_estado(char *sigla)
{
    int i;

    i = rand() % 26;

    strcpy(sigla, estados[i]);
}

void gera_cidade(char *cidade, char *sigla)
{
    int verifica, indentificador, i = 0;

    do
    {
        verifica = strcmp(sigla, estados[i]);

        if (verifica == 0)
            indentificador = i;

        i++;
    } while (verifica != 0 && i != 26);

    strcpy(cidade, cidades[indentificador]);
}

void gera_cep(char *cep)
{
    char cep_auxiliar[11];
    int i;

    for (i = 0; i < 10; i++)
    {
        if (i == 2)
            cep_auxiliar[i] = '.';
        else if (i == 6)
            cep_auxiliar[i] = '-';
        else
            cep_auxiliar[i] = gera_numero();
    }

    cep_auxiliar[10] = '\0';

    strcpy(cep, cep_auxiliar);
}

void gera_telefone(char *telefone)
{
    char telefone_auxiliar[14];
    int i;

    for (i = 0; i < 13; i++)
    {
        if (i == 2)
            telefone_auxiliar[i] = ' ';
        else if (i == 8)
            telefone_auxiliar[i] = '-';
        else
            telefone_auxiliar[i] = gera_numero();
    }

    telefone_auxiliar[13] = '\0';

    strcpy(telefone, telefone_auxiliar);
}

void mostra_cliente(struct CLIENTE cliente)
{
    int i;
    printf("\n\tCODIGO: %d", cliente.cod_cli);
    printf("\n\tNOME: %s", cliente.nome);
    printf("\n\tCEP: %s", cliente.endereco.cep);
    printf("\n\tBAIRRO: %s", cliente.endereco.bairro);
    printf("\n\tRUA: %s", cliente.endereco.rua);
    printf("\n\tNUMERO: %d", cliente.endereco.numero);
    printf("\n\tCIDADE: %s", cliente.endereco.cidade);
    printf("\n\tESTADO: %s", cliente.endereco.estado);
    printf("\n\tTELEFONE: %s", cliente.residencial.telefone);

    for (i = 0; i < 5; i++)
        printf("\n\tCELULAR %d: %s", i + 1, cliente.celular[i].telefone);

    printf("\n\tRENDA MENSAL: R$ %.2f", cliente.renda_mensal);
}

void gera_cliente()
{
    struct CLIENTE cliente;
    struct TELEFONE telefone;
    struct ENDERECO endereco;
    int i, opc = 0;

    if (qnt_clientes < TAM)
    {
        do
        {
            system("cls");
            cliente.cod_cli = gera_codigo();
            gera_nome(cliente.nome);
            gera_rua(cliente.endereco.rua);
            cliente.endereco.numero = rand() % 3999 + 1;
            gera_bairro(cliente.endereco.bairro);
            gera_estado(cliente.endereco.estado);
            gera_cidade(cliente.endereco.cidade, cliente.endereco.estado);
            gera_cep(cliente.endereco.cep);
            gera_telefone(cliente.residencial.telefone);
            for (i = 0; i < 5; i++)
                gera_telefone(cliente.celular[i].telefone);
            cliente.renda_mensal = rand() % 90000 + 900;

            printf("INFORMACOES DO CLIENTE:\n");
            mostra_cliente(cliente);

            printf("\n\nINFORME: (1 - SIM) OU (2 - NAO)\nDESEJA INCLUIR ESTE CLIENTE? ");
            scanf("%d", &opc);

            if (opc != 1 && opc != 2)
            {
                do
                {
                    system("cls");
                    printf("INFORMACOES DO CLIENTE:\n");
                    mostra_cliente(cliente);
                    printf("\n\nATENCAO!! INFORME: (1 - SIM) OU (2 - NAO)\nDESEJA INCLUIR ESTE CLIENTE? ");
                    scanf("%d", &opc);
                } while (opc != 1 && opc != 2);
            }

        } while (opc != 1);

        printf("\nINCLUINDO . . .");
        memcpy(&cadastro_clientes[qnt_clientes], &cliente, sizeof(cadastro_clientes[qnt_clientes]));
        qnt_clientes++;
    }
    else
        ERRO_LIMITE;
}

void copia_cadastros_cliente(struct CLIENTE vetor_clientes[])
{
    int i;
    for (i = 0; i < qnt_clientes; i++)
        memcpy(&vetor_clientes[i], &cadastro_clientes[i], sizeof(vetor_clientes[i]));
}

void ordena_nomes_clientes(struct CLIENTE vetor_clientes[], int tamanho)
{
    struct CLIENTE vetor_aux[TAM];
    int i, j, verifica;

    for (i = 0; i < tamanho; i++)
    {
        for (j = i; j < tamanho; j++)
        {
            verifica = strcmp(vetor_clientes[i].nome, vetor_clientes[j].nome);

            if (verifica > 0)
            {
                memcpy(&vetor_aux[0], &vetor_clientes[i], sizeof(vetor_aux[0]));
                memcpy(&vetor_clientes[i], &vetor_clientes[j], sizeof(vetor_clientes[i]));
                memcpy(&vetor_clientes[j], &vetor_aux[0], sizeof(vetor_clientes[j]));
            }
        }
    }
}

void listar_clientes(struct CLIENTE vetor_clientes[], int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        printf("INFORMACOES DO CLIENTE:\n");
        mostra_cliente(vetor_clientes[i]);
        printf("\n\n-----------------------------------------------------------\n\n");
    }
}

void lista_clientes_nome()
{
    struct CLIENTE vetor_clientes[TAM];

    if (qnt_clientes > 0)
    {
        system("cls");
        printf("\nOPCAO: LISTAR OS CLIENTES NO CADASTRO ORDENADOS CRESCENTEMENTE PELO NOME\n\n");
        copia_cadastros_cliente(vetor_clientes);
        ordena_nomes_clientes(vetor_clientes, qnt_clientes);
        listar_clientes(vetor_clientes, qnt_clientes);
    }
    else
        ERRO_CLIENTE;
}

void lista_clientes_selecao_salario()
{
    int opc = 0, i, j;
    float max = 0, min = 0;
    struct CLIENTE vetor_clientes[TAM];

    if (qnt_clientes > 0)
    {
        do
        {
            system("cls");
            printf("\nOPCAO: LISTAR OS CLIENTES NO CADASTRO ORDENADOS CRESCENTEMENTE PELO NOME POR SELECAO DE FAIXA DE RENDA SALARIAL MENSAL\n\n");
            printf("| 1 - DE R$ 900,00    ATE R$ 10.000,00 |\n| 2 - DE R$ 10.000,00 ATE R$ 20.000,00 |\n");
            printf("| 3 - DE R$ 20.000,00 ATE R$ 30.000,00 |\n| 4 - DE R$ 30.000,00 ATE R$ 40.000,00 |\n");
            printf("| 5 - DE R$ 40.000,00 ATE R$ 50.000,00 |\n| 6 - DE R$ 50.000,00 ATE R$ 60.000,00 |\n");
            printf("| 7 - DE R$ 60.000,00 ATE R$ 70.000,00 |\n| 8 - DE R$ 70.000,00 ATE R$ 80.000,00 |\n");
            printf("| 9 - DE R$ 80.000,00 ATE R$ 90.900,00 |\n");

            printf("\nDE ACORDO COM A TABELA ACIMA SELECIONE UMA FAIXA SALARIAL MENSAL: ");
            scanf("%d", &opc);

            if (opc < 1 || opc > 9)
            {
                ERRO_OPCAO;
                system("pause");
            }
        } while (opc < 1 || opc > 9);

        if (opc == 1)
        {
            min = 899.0;
            max = 10000.0;
        }
        else if (opc == 2)
        {
            min = 10000.0;
            max = 20000.0;
        }
        else if (opc == 3)
        {
            min = 20000.0;
            max = 30000.0;
        }
        else if (opc == 4)
        {
            min = 30000.0;
            max = 40000.0;
        }
        else if (opc == 5)
        {
            min = 40000.0;
            max = 50000.0;
        }
        else if (opc == 6)
        {
            min = 50000.0;
            max = 60000.0;
        }
        else if (opc == 7)
        {
            min = 60000.0;
            max = 70000.0;
        }
        else if (opc == 8)
        {
            min = 70000.0;
            max = 80000.0;
        }
        else if (opc == 9)
        {
            min = 80000.0;
            max = 90900.0;
        }

        i = 0;
        j = 0;
        do
        {
            if (cadastro_clientes[i].renda_mensal > min && cadastro_clientes[i].renda_mensal <= max)
            {
                memcpy(&vetor_clientes[j], &cadastro_clientes[i], sizeof(vetor_clientes[j]));
                j++;
            }

            i++;
        } while (i < qnt_clientes);

        if (j > 0)
        {
            if (min == 899.0)
                min = 900.0;
            system("cls");
            printf("\nFAIXA SALARIAL MENSAL SELECIONADA: DE R$ %.2f ATE R$ %.2f\n\n", min, max);
            ordena_nomes_clientes(vetor_clientes, j);
            listar_clientes(vetor_clientes, j);
        }
        else
            printf("\nNAO EXISTEM CLINTES CADASTRADOS COM ESTA FAIXA SALARIAL!");
    }
    else
        ERRO_CLIENTE;
}

void organiza_cadastros_clientes(int indice)
{
    int i;
    for (i = indice; i < qnt_clientes; i++)
        memcpy(&cadastro_clientes[i], &cadastro_clientes[i + 1], sizeof(cadastro_clientes[i]));
}

void excluir_cliente()
{
    int codigo, verifica, verifica_venda, identificador = 0, finaliza = 0, i = 0;

    if (qnt_clientes > 0)
    {
        do
        {
            system("cls");
            printf("\nOPCAO: INSERIR UM CLIENTE NO CADASTRO\n\n");
            printf("INFORME O CODIGO DO CLIENTE QUE DESEJA EXCLUIR OU (-1) PARA RETORNAR: ");
            scanf("%d", &codigo);

            if (codigo == -1)
            {
                RETORNA;
                finaliza = 1;
            }
            else
            {
                i = 0;
                verifica_venda = 1;
                do
                {
                    if (dados_vendas[i].cliente.cod_cli == codigo)
                        verifica_venda = 0;

                    i++;
                } while ((verifica_venda != 0) && (i < qnt_vendas));

                if (verifica_venda == 0)
                {
                    printf("\nVERIFICAMOS UMA VENDA REGISTRADA NESTE CLIENTE\nNAO SERA POSSIVEL EXCLUIR O CADASTRO!\n\n");
                    system("pause");
                    finaliza = 1;
                }
                else
                {
                    i = 0;
                    verifica = 1;
                    do
                    {
                        if (cadastro_clientes[i].cod_cli == codigo)
                        {
                            identificador = i;
                            verifica = 0;
                        }
                        i++;
                    } while ((verifica != 0) && (i < qnt_clientes));

                    if (verifica == 0)
                    {
                        organiza_cadastros_clientes(identificador);
                        qnt_clientes -= 1;
                        printf("\nCLIENTE EXCLUIDO COM SUCESSO!");
                        finaliza = 1;
                    }
                    else
                    {
                        printf("\nCODIGO INVALIDO!\nNAO FOI ENCONTRADO NENHUM CADASTRO.\n\n");
                        system("pause");
                    }
                }
            }

        } while (finaliza != 1);
    }
    else
        ERRO_CLIENTE;
}

void aux_gera_placa(char vetor_placa[])
{
    int i;
    vetor_placa[0] = '\0';
    for (i = 0; i < 8; i++)
    {
        if (i < 3)
            vetor_placa[i] = gera_alfabeto();
        if (i == 3)
            vetor_placa[i] = '-';
        if (i > 3)
            vetor_placa[i] = gera_numero();
    }

    vetor_placa[8] = '\0';
}

void gera_placa(char *placa)
{
    char placa_auxiliar[9];
    int i, j = 0, verifica;

    if (qnt_carros > 0)
    {
        do
        {
            aux_gera_placa(placa_auxiliar);
            verifica = strcmp(cadastro_carros[j].placa, placa_auxiliar);

            j++;
        } while (verifica != 0 && j < qnt_carros);
    }
    else
        aux_gera_placa(placa_auxiliar);

    strcpy(placa, placa_auxiliar);
}

void gera_modelo(char *modelo)
{
    int i = rand() % 15;
    strcpy(modelo, modelos[i]);
}

void gera_fabricante(char *fabricante, char *modelo)
{
    char marcas[][15] = {{"Fiat"}, {"Chevrolet"}, {"Volkswagen"}};
    char modelos_fiat[][10] = {{"Palio"}, {"Siena"}, {"Uno"}, {"Punto"}, {"Linea"}};
    char modelos_chevrolet[][10] = {{"Astra"}, {"Corsa"}, {"Cruze"}, {"Opala"}, {"Prisma"}};
    char modelos_volkswagen[][10] = {{"Taro"}, {"Fox"}, {"Gol"}, {"Voyage"}, {"Polo"}};
    int i = 0, verifica;

    do
    {
        verifica = strcmp(modelo, modelos_fiat[i]);

        if (verifica == 0)
            strcpy(fabricante, marcas[0]);

        i++;
    } while (verifica != 0 && i != 5);

    if (i == 5 && verifica != 0)
    {
        i = 0;
        do
        {
            verifica = strcmp(modelo, modelos_chevrolet[i]);

            if (verifica == 0)
                strcpy(fabricante, marcas[1]);

            i++;
        } while (verifica != 0 && i != 5);
    }
    if (i == 5 && verifica != 0)
    {
        i = 0;
        do
        {
            verifica = strcmp(modelo, modelos_volkswagen[i]);

            if (verifica == 0)
                strcpy(fabricante, marcas[2]);

            i++;
        } while (verifica != 0 && i != 5);
    }
}

int gera_ano_fabricacao()
{
    int ano = rand() % 36 + 1980;
    return (ano);
}

int gera_ano_modelo(int ano_fabricacao)
{
    int anos_modelo[2], i;

    anos_modelo[0] = ano_fabricacao;
    if (ano_fabricacao < 2015)
        anos_modelo[1] = ano_fabricacao + (rand() % 2 + 1);
    else
        anos_modelo[1] = ano_fabricacao + 1;

    i = rand() % 2;
    return (anos_modelo[i]);
}

void gera_combustivel(char *combustivel)
{
    int i;
    char tipos[][10] = {{"Alcool"}, {"Gasolina"}, {"Flex"}, {"Diesel"}};

    i = rand() % 4;
    strcpy(combustivel, tipos[i]);
}

void gera_cor(char *cor)
{
    int i;
    char cores[][10] = {{"Branco"}, {"Prata"}, {"Preto"}};

    i = rand() % 3;
    strcpy(cor, cores[i]);
}

void mostra_carro(struct CARRO carro)
{
    int i;
    printf("\n\tPLACA: %s", carro.placa);
    printf("\n\tMODELO: %s", carro.modelo);
    printf("\n\tFABRICANTE: %s", carro.fabricante);
    printf("\n\tANO DE FABRICACAO: %d", carro.ano_fabricacao);
    printf("\n\tANO DO MODELO: %d", carro.ano_modelo);
    printf("\n\tCOMBUSTIVEL: %s", carro.combustivel);
    printf("\n\tCOR: %s", carro.cor);
    printf("\n\tOPCIONAIS:\n");
    for (i = 0; i < 8; i++)
    {
        if (carro.opcional[i] == 1)
            printf("\t\t  %s\n", opcionais[i]);
    }
    printf("\tPRECO DE COMPRA: R$ %.2f", carro.preco_compra);
}

void gera_carro()
{
    struct CARRO carro;
    int i, opc = 0;

    if (cadastro_carros < TAM)
    {
        do
        {
            system("cls");
            gera_placa(carro.placa);
            gera_modelo(carro.modelo);
            gera_fabricante(carro.fabricante, carro.modelo);
            carro.ano_fabricacao = gera_ano_fabricacao();
            carro.ano_modelo = gera_ano_modelo(carro.ano_fabricacao);
            gera_combustivel(carro.combustivel);
            gera_cor(carro.cor);
            for (i = 0; i < 8; i++)
                carro.opcional[i] = rand() % 2;
            carro.preco_compra = rand() % 90000 + 17000;

            printf("INFORMACOES DO CARRO:\n");
            mostra_carro(carro);

            printf("\n\nINFORME: (1 - SIM) OU (2 - NAO)\nDESEJA INCLUIR ESTE CARRO? ");
            scanf("%d", &opc);

            if (opc != 1 && opc != 2)
            {
                do
                {
                    system("cls");
                    printf("INFORMACOES DO CARRO:\n");
                    mostra_carro(carro);
                    printf("\n\nATENCAO!! INFORME: (1 - SIM) OU (2 - NAO)\nDESEJA INCLUIR ESTE CARRO? ");
                    scanf("%d", &opc);
                } while (opc != 1 && opc != 2);
            }

        } while (opc != 1);

        printf("\nINCLUINDO . . .");
        memcpy(&cadastro_carros[qnt_carros], &carro, sizeof(cadastro_carros[qnt_carros]));
        memcpy(&carros_disponiveis[qnt_carros_disponiveis], &carro, sizeof(carros_disponiveis[qnt_carros_disponiveis]));
        qnt_carros++;
        qnt_carros_disponiveis++;
    }
    else
        ERRO_LIMITE;
}

void copia_cadastros_carros(struct CARRO vetor_carros[])
{
    int i;
    for (i = 0; i < qnt_carros_disponiveis; i++)
        memcpy(&vetor_carros[i], &carros_disponiveis[i], sizeof(vetor_carros[i]));
}

void ordena_fabricante_modelo_carros(struct CARRO vetor_carros[])
{
    struct CARRO vetor_aux[TAM];
    int i, j, verifica_modelo, verifica_fabricante;
    copia_cadastros_carros(vetor_carros);

    for (i = 0; i < qnt_carros_disponiveis; i++)
    {
        for (j = i + 1; j < qnt_carros_disponiveis; j++)
        {
            verifica_modelo = strcmp(vetor_carros[i].modelo, vetor_carros[j].modelo);
            verifica_fabricante = strcmp(vetor_carros[i].fabricante, vetor_carros[j].fabricante);

            if (verifica_fabricante > 0)
            {
                memcpy(&vetor_aux[0], &vetor_carros[i], sizeof(vetor_aux[0]));
                memcpy(&vetor_carros[i], &vetor_carros[j], sizeof(vetor_carros[i]));
                memcpy(&vetor_carros[j], &vetor_aux[0], sizeof(vetor_carros[j]));
            }
            if (verifica_fabricante == 0 && verifica_modelo > 0)
            {
                memcpy(&vetor_aux[0], &vetor_carros[i], sizeof(vetor_aux[0]));
                memcpy(&vetor_carros[i], &vetor_carros[j], sizeof(vetor_carros[i]));
                memcpy(&vetor_carros[j], &vetor_aux[0], sizeof(vetor_carros[j]));
            }
        }
    }
}

void listar_carros(struct CARRO vetor_carro[], int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        printf("INFORMACOES DO CARRO:\n");
        mostra_carro(vetor_carro[i]);
        printf("\n\n-----------------------------------------------------------\n\n");
    }
}

void listar_carros_fabricante_modelo()
{
    struct CARRO vetor_carros[TAM];

    if (qnt_carros > 0 && qnt_carros_disponiveis == 0)
        ERRO_DISPONIBILIDADE_CARRO;
    else if (qnt_carros > 0 && qnt_carros_disponiveis > 0)
    {
        system("cls");
        printf("\nOPCAO: LISTAR OS CARROS DISPONIVEIS PARA A VENDA ORDENADOS CESCENTEMENTE POR FABRICANTES E MODELO\n\n");
        ordena_fabricante_modelo_carros(vetor_carros);
        listar_carros(vetor_carros, qnt_carros_disponiveis);
    }
    else if (qnt_carros == 0)
        ERRO_CARRO;
}

void listar_carros_selecao_opcionais()
{
    struct CARRO vetor_carros[TAM];
    int i, ii, j, qnt, contador_opcionais = 0;

    if (qnt_carros > 0 && qnt_carros_disponiveis == 0)
        ERRO_DISPONIBILIDADE_CARRO;
    else if (qnt_carros > 0 && qnt_carros_disponiveis > 0)
    {
        do
        {
            system("cls");
            printf("\nOPCAO: LISTAR OS CARROS DISPONIVEIS PARA A VENDA POR SELECAO DE UM OU MAIS OPICIONAIS\n\n");
            printf("OPCIONAIS:\n");
            for (i = 0; i < 8; i++)
                printf("\t- %s\n", opcionais[i]);
            printf("\nINFORME A QUANTIDADE DE OPCIONAIS: ");
            scanf("%d", &qnt);

            if (qnt < 1 || qnt > 8)
            {
                ERRO_OPCAO;
                system("pause");
            }
        } while (qnt < 1 || qnt > 8);

        i = 0;
        j = 0;
        do
        {
            contador_opcionais = 0;

            for (ii = 0; ii < 8; ii++)
            {
                if (carros_disponiveis[i].opcional[ii] == 1)
                    contador_opcionais++;
            }

            if (contador_opcionais == qnt)
            {
                memcpy(&vetor_carros[j], &carros_disponiveis[i], sizeof(vetor_carros[j]));
                j++;
            }
            i++;
        } while (i < qnt_carros_disponiveis);

        if (j > 0)
        {
            system("cls");
            printf("\nCARROS DISPONIVEIS PARA VENDA COM %d OPCIONAIS:\n\n", qnt);
            listar_carros(vetor_carros, j);
        }
        else
            printf("\nNAO FOI ENCONTRADO NENHUM CARRO COM ESSA QUANTIDADE DE OPCIONAIS!");
    }
    else if (qnt_carros == 0)
        ERRO_CARRO;
}

void listar_carros_selecao_ano_fabricacao()
{
    int opc, i, j, ii, max, min;
    struct CARRO vetor_carros[TAM];

    if (qnt_carros > 0 && qnt_carros_disponiveis == 0)
        ERRO_DISPONIBILIDADE_CARRO;
    else if (qnt_carros > 0 && qnt_carros_disponiveis > 0)
    {

        do
        {
            system("cls");
            printf("\nOPCAO: LISTAR OS CARROS DISPONIVEIS PARA A VENDA POR SELECAO DA FAIXA DE ANO ADE FABRICACAO\n\n");
            printf(" 1 - DE 1980 ATE 1990\n 2 - DE 1990 ATE 2000\n 3 - DE 2000 ATE 2010\n 4 - DE 2010 ATE 2016\n");
            printf("\nDE ACORDO COM A TABELA ACIMA INFORME A FAIXA DE ANO DE FABRICACAO: ");
            scanf("%d", &opc);

            if (opc < 1 || opc > 4)
            {
                ERRO_OPCAO;
                system("pause");
            }
        } while (opc < 1 || opc > 4);

        if (opc == 1)
        {
            min = 1979;
            max = 1990;
        }
        else if (opc == 2)
        {
            min = 1990;
            max = 2000;
        }
        else if (opc == 3)
        {
            min = 2000;
            max = 2010;
        }
        else if (opc == 4)
        {
            min = 2010;
            max = 2016;
        }

        i = 0;
        j = 0;
        do
        {
            if (carros_disponiveis[i].ano_fabricacao > min && carros_disponiveis[i].ano_fabricacao <= max)
            {
                memcpy(&vetor_carros[j], &carros_disponiveis[i], sizeof(vetor_carros[j]));
                j++;
            }
            i++;
        } while (i < qnt_carros_disponiveis);

        if (j > 0)
        {
            if (opc == 1)
                min = 1980;
            system("cls");
            printf("\nFAIXA DE ANO DE FABRICACAO SELECIONADA: DE %d ATE %d\n\n", min, max);
            listar_carros(vetor_carros, j);
        }
        else
            printf("\nNAO EXISTE NENHUM CARRO DISPONIVEL NESTA FAIXA DE ANO DE FABRICACAO!");
    }
    else if (qnt_carros == 0)
        ERRO_CARRO;
}

void organiza_cadastros_carros(int indice)
{
    int i;
    for (i = indice; i < qnt_carros; i++)
        memcpy(&cadastro_carros[i], &cadastro_carros[i + 1], sizeof(cadastro_carros[i]));
}

void excluir_carro()
{
    int verifica, verifica_venda, identificador = 0, finaliza = 0, i = 0;
    char placa[9];

    if (qnt_carros > 0 && qnt_carros_disponiveis == 0)
        printf("\nTODOS OS CARROS CADASTRADOS ESTAO VENDIDOS!\nNAO SERA POSSIVEL EXCUIR QUALQUER CARRO!");
    else if (qnt_carros > 0 && qnt_carros_disponiveis > 0)
    {
        do
        {
            system("cls");
            printf("\nOPCAO: EXCLUIR UM CARRO DO CADASTRO\n\n");
            printf("INFORME A PLACA DO CARRO QUE DESEJA EXCLUIR NO FORMATO (AAA-1234) OU (-1) PARA RETORNAR: ");
            scanf("%s", &placa);

            if (placa[0] == '-' && placa[1] == '1')
            {
                RETORNA;
                finaliza = 1;
            }
            else
            {
                i = 0;
                do
                {
                    verifica_venda = strcmp(dados_vendas[i].carro.placa, placa);

                    i++;
                } while ((verifica != 0) && (i < qnt_vendas));

                if (verifica_venda == 0)
                {
                    printf("\nVERIFICAMOS QUE ESTE VEICULO JA FOI VENDIDO\nNAO SERA POSSIVEL EXCLUIR O CADASTRO!\n\n");
                    system("pause");
                    finaliza = 1;
                }
                else
                {
                    i = 0;
                    do
                    {
                        verifica = strcmp(cadastro_carros[i].placa, placa);

                        if (verifica == 0)
                            identificador = i;

                        i++;
                    } while ((verifica != 0) && (i < qnt_carros));

                    if (verifica == 0)
                    {
                        organiza_cadastros_carros(identificador);
                        qnt_carros -= 1;
                        printf("\nCARRO EXCLUIDO COM SUCESSO!");
                        finaliza = 1;
                    }
                    else
                    {
                        printf("\nPLACA INVALIDA!\nNAO FOI ENCONTRADO NENHUM CADASTRO.\n\n");
                        system("pause");
                    }
                }
            }

        } while (finaliza != 1);
    }
    else
        ERRO_CARRO;
}

void mostra_venda(struct VENDA_CARRO venda)
{
    printf("\n\tPLACA DO CARRO: %s", venda.placa);
    printf("\n\tCODIGO DO CLIENTE: %d", venda.cod_cli);
    printf("\n\tPRECO DA VENDA: R$ %.2f", venda.preco_venda);
    printf("\n\tDATA: %d/%d/%d", venda.data_venda.dia, venda.data_venda.mes, venda.data_venda.ano);
}

void inserir_venda()
{
    int i, verifica_venda, verifica_placa, verifica_codigo, identificador_placa, identificador_codigo, finaliza = 0, codigo, verifica_ano, verifica_valor;
    char placa[9];
    int data[3];
    float valor_venda;

    if (qnt_carros > 0 && qnt_clientes > 0 && qnt_carros_disponiveis == 0)
        ERRO_DISPONIBILIDADE_CARRO;
    else if (qnt_carros > 0 && qnt_clientes > 0 && qnt_carros_disponiveis > 0)
    {
        do
        {
            system("cls");
            printf("\nOPCAO: INSERIR UMA VENDA\n\n");
            printf("INFORME A PLACA DO VEICULO NO FORMATO (AAA-1234) OU (-1) PARA RETORNAR: ");
            scanf("%s", &placa);

            if (placa[0] == '-' && placa[1] == '1')
            {
                RETORNA;
                finaliza = 1;
            }
            else
            {
                i = 0;
                do
                {
                    verifica_venda = strcmp(dados_vendas[i].carro.placa, placa);
                    i++;
                } while ((verifica_venda != 0) && (i < qnt_vendas));

                if (verifica_venda != 0)
                {
                    i = 0;
                    do
                    {
                        verifica_placa = strcmp(cadastro_carros[i].placa, placa);

                        if (verifica_placa == 0)
                            identificador_placa = i;

                        i++;
                    } while ((verifica_placa != 0) && (i < qnt_carros));

                    if (verifica_placa == 0)
                    {
                        do
                        {
                            system("cls");
                            printf("INFORME O CODIGO DO CLIENTE OU (-1) PARA RETORNAR: ");
                            scanf("%d", &codigo);

                            if (codigo == -1)
                            {
                                RETORNA;
                                finaliza = 1;
                            }
                            else
                            {
                                i = 0;
                                verifica_codigo = 1;
                                do
                                {
                                    if (cadastro_clientes[i].cod_cli == codigo)
                                    {
                                        identificador_codigo = i;
                                        verifica_codigo = 0;
                                    }
                                    i++;
                                } while ((verifica_codigo != 0) && (i < qnt_clientes));

                                if (verifica_codigo == 0)
                                {
                                    do
                                    {
                                        system("cls");
                                        printf("DADOS DO VEICULO:\n");
                                        mostra_carro(cadastro_carros[identificador_placa]);
                                        printf("\nDADOS DO CLIENTE:\n");
                                        mostra_cliente(cadastro_clientes[identificador_codigo]);
                                        printf("\n\nINFORME O VALOR DA VENDA OU (-1) PARA CANCELAR: ");
                                        scanf("%f", &valor_venda);

                                        if (valor_venda == -1)
                                        {
                                            printf("\nVENDA CANCELADA!\nRETORNANDO . . .");
                                            finaliza = 1;
                                        }
                                        else
                                        {
                                            verifica_valor = cadastro_carros[identificador_placa].preco_compra;
                                            if (valor_venda >= verifica_valor)
                                            {
                                                // NOTA : VERIFICAR O TOTAL DE DIAS DE CADA MES
                                                verifica_ano = cadastro_carros[identificador_placa].ano_modelo;
                                                printf("\nINFORME A DATA NO FORMATO NUMERICO:\n");
                                                do
                                                {
                                                    printf("\nDIA: ");
                                                    scanf("%d", &data[0]);

                                                    if (data[0] > 31 || data[0] < 1)
                                                        printf("\nDIA INVALIDO!\n");

                                                } while (data[0] > 31 || data[0] < 1);
                                                do
                                                {
                                                    printf("\nMES: ");
                                                    scanf("%d", &data[1]);

                                                    if (data[1] > 12 || data[1] < 1)
                                                        printf("\nMES INVALIDO!\n");

                                                } while (data[1] > 12 || data[1] < 1);
                                                do
                                                {
                                                    printf("\nANO: ");
                                                    scanf("%d", &data[2]);

                                                    if (data[2] < verifica_ano || data[2] > 2021)
                                                        printf("\nANO INVALIDO!\n");

                                                } while (data[2] < verifica_ano || data[2] > 2021);

                                                cadastro_vendas[qnt_vendas].cod_cli = cadastro_clientes[identificador_codigo].cod_cli;
                                                strcpy(cadastro_vendas[qnt_vendas].placa, cadastro_carros[identificador_placa].placa);
                                                cadastro_vendas[qnt_vendas].data_venda.dia = data[0];
                                                cadastro_vendas[qnt_vendas].data_venda.mes = data[1];
                                                cadastro_vendas[qnt_vendas].data_venda.ano = data[2];
                                                cadastro_vendas[qnt_vendas].preco_venda = valor_venda;

                                                for (i = identificador_placa; i < qnt_carros; i++)
                                                    memcpy(&carros_disponiveis[i], &carros_disponiveis[i + 1], sizeof(carros_disponiveis[i]));

                                                qnt_carros_disponiveis -= 1;

                                                memcpy(&dados_vendas[qnt_vendas].cliente, &cadastro_clientes[identificador_codigo], sizeof(dados_vendas[qnt_vendas].cliente));
                                                memcpy(&dados_vendas[qnt_vendas].carro, &cadastro_carros[identificador_placa], sizeof(dados_vendas[qnt_vendas].carro));
                                                memcpy(&dados_vendas[qnt_vendas].venda_carro, &cadastro_vendas[qnt_vendas], sizeof(dados_vendas[qnt_vendas].venda_carro));

                                                printf("\nVENDA REGISTRADA COM SUCESSO!\nDETALHES DA VENDA:\n");
                                                mostra_venda(cadastro_vendas[qnt_vendas]);
                                                qnt_vendas++;
                                                finaliza = 1;
                                            }
                                            else
                                            {
                                                printf("\nO VEICULO NAO PODE SER VENDIDO POR UM VALOR INFERIOR DO SEU PRECO DE COMPRA!\n\n");
                                                system("pause");
                                            }
                                        }

                                    } while (valor_venda < verifica_valor && finaliza != 1);
                                }
                                else
                                {
                                    printf("\nCODIGO INVALIDO!\nNAO FOI ENCONTRADO NENHUM CADASTRO.\n\n");
                                    system("pause");
                                }
                            }

                        } while (verifica_codigo != 0 && finaliza != 1);
                    }
                    else
                    {
                        printf("\nPLACA INVALIDA!\nNAO FOI ENCONTRADO NENHUM CADASTRO.\n\n");
                        system("pause");
                    }
                }
                else
                {
                    printf("ESTE VEICULO JA FOI VENDIDO!");
                    system("pause");
                }
            }

        } while (finaliza != 1);
    }
    if (qnt_carros == 0)
        ERRO_CARRO;
    if (qnt_carros == 0)
        ERRO_CLIENTE;
}

void organiza_vendas(int indice)
{
    int i;
    for (i = indice; i < qnt_vendas; i++)
    {
        memcpy(&cadastro_vendas[i], &cadastro_vendas[i + 1], sizeof(cadastro_vendas[i]));
        memcpy(&dados_vendas[i], &dados_vendas[i + 1], sizeof(dados_vendas[i]));
    }
}

void excluir_venda()
{
    int verifica_venda, verifica_carro, identificador = 0, identificador_carro = 0, finaliza = 0, i = 0;
    char placa[9];

    if (qnt_vendas > 0)
    {
        do
        {
            system("cls");
            printf("\nOPCAO: EXCLUIR UMA VENDA\n\n");
            printf("INFORME A PLACA DO CARRO REGISTRADO NA VENDA NO FORMATO (AAA-1234) OU (-1) PARA RETORNAR: ");
            scanf("%s", &placa);

            if (placa[0] == '-' && placa[1] == '1')
            {
                RETORNA;
                finaliza = 1;
            }
            else
            {
                i = 0;
                do
                {
                    verifica_venda = strcmp(dados_vendas[i].carro.placa, placa);

                    if (verifica_venda == 0)
                        identificador = i;

                    i++;
                } while ((verifica_venda != 0) && (i < qnt_vendas));

                if (verifica_venda == 0)
                {
                    i = 0;
                    do
                    {
                        verifica_carro = strcmp(cadastro_carros[i].placa, placa);

                        if (verifica_carro == 0)
                            identificador_carro = i;

                        i++;
                    } while ((verifica_carro != 0) && (i < qnt_carros));

                    memcpy(&carros_disponiveis[qnt_carros_disponiveis], &cadastro_carros[identificador_carro], sizeof(carros_disponiveis[qnt_carros_disponiveis]));
                    qnt_carros_disponiveis++;

                    organiza_vendas(identificador);
                    qnt_vendas -= 1;
                    printf("\nVENDA EXCLUIDA COM SUCESSO!");
                    finaliza = 1;
                }
                else
                {
                    printf("\nPLACA INVALIDA!\nNAO FOI ENCONTRADA NENHUMA CADASTRADA.\n\n");
                    system("pause");
                    finaliza = 1;
                }
            }

        } while (finaliza != 1);
    }
    else
        ERRO_VENDA;
}

void ordena_modelo_carros(struct CADASTROS_VENDAS dados[], int tamanho)
{
    struct CADASTROS_VENDAS vetor_aux[TAM];
    int i, j, verifica_modelo;

    for (i = 0; i < tamanho; i++)
    {
        for (j = i + 1; j < tamanho; j++)
        {
            verifica_modelo = strcmp(dados[i].carro.modelo, dados[j].carro.modelo);

            if (verifica_modelo > 0)
            {
                memcpy(&vetor_aux[0], &dados[i], sizeof(vetor_aux[0]));
                memcpy(&dados[i], &dados[j], sizeof(dados[i]));
                memcpy(&dados[j], &vetor_aux[0], sizeof(dados[j]));
            }
        }
    }
}

void ordena_ano_fabricacao(struct CADASTROS_VENDAS dados[], int tamanho)
{
    struct CADASTROS_VENDAS vetor_aux[TAM];
    int i, j;

    for (i = 0; i < tamanho; i++)
    {
        for (j = i + 1; j < tamanho; j++)
        {
            if (dados[i].carro.ano_fabricacao > dados[j].carro.ano_fabricacao)
            {
                memcpy(&vetor_aux[0], &dados[i], sizeof(vetor_aux[0]));
                memcpy(&dados[i], &dados[j], sizeof(dados[i]));
                memcpy(&dados[j], &vetor_aux[0], sizeof(dados[j]));
            }
        }
    }
}

void mostra_venda_listagem(struct CADASTROS_VENDAS cadastro, int opc)
{
    if (opc == 1)
    {
        printf("\n\tMODELO DO CARRO: %s", cadastro.carro.modelo);
        printf("\n\tPLACA DO CARRO: %s", cadastro.carro.placa);
        printf("\n\tANO DE FABRICACAO: %d", cadastro.carro.ano_fabricacao);
        printf("\n\tNOME DO CLIENTE: %s", cadastro.cliente.nome);
    }
    else if (opc == 2)
    {
        printf("\n\tANO DE FABRICACAO: %d", cadastro.carro.ano_fabricacao);
        printf("\n\tPLACA DO CARRO: %s", cadastro.carro.placa);
        printf("\n\tNOME DO CLIENTE: %s", cadastro.cliente.nome);
    }
}

void listar_vendas(struct CADASTROS_VENDAS cadastro[], int opc, int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        printf("INFORMACOES DA VENDA:\n");
        mostra_venda_listagem(cadastro[i], opc);
        printf("\n\n-----------------------------------------------------------\n\n");
    }
}

void listar_vendas_por_fabricante()
{
    int opc, i, j, ii, verifica_placa, verifica_fabricante, verifica_codigo;
    char fabricante[15];
    struct CADASTROS_VENDAS copia_dados[TAM];

    if (qnt_vendas > 0)
    {
        do
        {
            system("cls");
            printf("\nOPCAO: LISTAR OS CARROS VENDIDOS DE UM DETERMINADO FABRICANTE, ORDENADOS CRESCENTEMENTE PELO MODELO\n\n");
            printf("FABRICANTES:\n\t1 - Chevrolet\n\t2 - Fiat\n\t3 - Volkswagen\n\nOPCAO: ");
            scanf("%d", &opc);

            if (opc < 1 || opc > 3)
            {
                ERRO_OPCAO;
                system("pause");
            }
        } while (opc < 1 || opc > 3);

        if (opc == 1)
            strcpy(fabricante, "Chevrolet");
        else if (opc == 2)
            strcpy(fabricante, "Fiat");
        else
            strcpy(fabricante, "Volkswagen");

        i = 0;
        j = 0;
        do
        {
            verifica_fabricante = strcmp(dados_vendas[i].carro.fabricante, fabricante);

            if (verifica_fabricante == 0)
            {
                memcpy(&copia_dados[j].carro, &dados_vendas[i].carro, sizeof(copia_dados[j].carro));
                memcpy(&copia_dados[j].cliente, &dados_vendas[i].cliente, sizeof(copia_dados[j].cliente));
                j++;
            }

            i++;
        } while (i < qnt_vendas);

        if (j > 0)
        {
            system("cls");
            printf("\nTODOS AS VENDAS CORRESPONDENTE AO FABRICANTE %s:\n", fabricante);
            ordena_modelo_carros(copia_dados, j);
            listar_vendas(copia_dados, 1, j);
        }
        else
            printf("\nAINDA NAO FOI REGISTRADA NENHUMA VENDA DESTE FABRICANTE!");
    }
    else
        ERRO_VENDA;
}

void listar_vendas_por_modelo()
{
    int i, ii = 1, j, opc, verifica_modelo;
    struct CADASTROS_VENDAS copia_dados[TAM];

    if (qnt_vendas > 0)
    {
        do
        {
            system("cls");
            printf("\nOPCAO: LISTAR OS CARROS VENDIDOS DE UM DETERMINADO MODELO, ORDENADOS CRESCENTEMENTE PELO ANO DE FABRICACAO\n\n");
            for (i = 0; i < 15; i++)
            {
                printf(" | %d - %s", i + 1, modelos[i]);
                if (ii == 5)
                {
                    printf(" |\n");
                    ii = 0;
                }
                ii++;
            }
            printf("\nINFORME O MODELO DE ACORDO COM A TABELA ACIMA: ");
            scanf("%d", &opc);

            if (opc < 1 || opc > 15)
            {
                ERRO_OPCAO;
                system("pause");
            }
        } while (opc < 1 || opc > 15);

        i = 0;
        j = 0;
        opc = opc - 1;
        do
        {
            verifica_modelo = strcmp(dados_vendas[i].carro.modelo, modelos[opc]);

            if (verifica_modelo == 0)
            {
                memcpy(&copia_dados[j].carro, &dados_vendas[i].carro, sizeof(copia_dados[j].carro));
                memcpy(&copia_dados[j].cliente, &dados_vendas[i].cliente, sizeof(copia_dados[j].cliente));
                j++;
            }
            i++;
        } while (i < qnt_vendas);

        if (j > 0)
        {
            system("cls");
            printf("\nTODOS AS VENDAS CORRESPONDENTE AO MODELO %s:\n", modelos[opc]);
            ordena_ano_fabricacao(copia_dados, j);
            listar_vendas(copia_dados, 2, j);
        }
        else
            printf("\nAINDA NAO FOI REGISTRADA NENHUMA VENDA DESTE MODELO!");
    }
    else
        ERRO_VENDA;
}

void quantidade_vendas()
{
    int i = 0;
    float total = 0, valores[TAM];

    if (qnt_vendas > 0)
    {
        system("cls");
        printf("\nOPCAO: INFORMAR A QUANTIDADE DE CARROS VENDIDOS COM O VALOR TOTALIZADO DOS PRECOS VENDIDOS\n\n");
        printf("\nQUANTIDADE DE CARROS VENDIDOS: %d", qnt_vendas);

        for (i = 0; i < qnt_vendas; i++)
        {
            valores[i] = dados_vendas[i].venda_carro.preco_venda;
            total += valores[i];
        }
        printf("\nVALOR TOTAL DAS VENDAS: R$ %.2f", total);
    }
    else
        ERRO_VENDA;
}

void lucro_total_vendas()
{
    int i = 0;
    float total = 0, valores_vendas[TAM], valores_carros[TAM];

    if (qnt_vendas > 0)
    {
        for (i = 0; i < qnt_vendas; i++)
        {
            valores_vendas[i] = dados_vendas[i].venda_carro.preco_venda;
            valores_carros[i] = dados_vendas[i].carro.preco_compra;
            total += (valores_vendas[i] - valores_carros[i]);
        }
        system("cls");
        printf("\nOPCAO: INFORMAR O LUCRO TOTAL DAS VENDAS\n\n");
        printf("\nLUCRO TOTAL DAS VENDAS: R$ %.2f", total);
    }
    else
        ERRO_VENDA;
}

void menu_carro()
{
    int opc;
    do
    {
        system("cls");
        printf("OPCOES:\n\n0 - RETORNAR AO MENU PRINCIPAL\n1 - INSERIR UM CARRO NO CADASTRO\n2 - EXCLUIR UM CARRO DO CADASTRO");
        printf("\n3 - LISTAR OS CARROS DISPONIVEIS PARA A VENDA ORDENADOS CESCENTEMENTE POR FABRICANTES E MODELO");
        printf("\n4 - LISTAR OS CARROS DISPONIVEIS PARA A VENDA POR SELECAO DE UM OU MAIS OPICIONAIS");
        printf("\n5 - LISTAR OS CARROS DISPONIVEIS PARA A VENDA POR SELECAO DA FAIXA DE ANO ADE FABRICACAO\n\nINFORME A SUA OPCAO: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 0:
            RETORNA;
            printf("\n\n");
            system("pause");
            break;
        case 1:
            gera_carro();
            printf("\n\n");
            system("pause");
            break;
        case 2:
            excluir_carro();
            printf("\n\n");
            system("pause");
            break;
        case 3:
            listar_carros_fabricante_modelo();
            printf("\n\n");
            system("pause");
            break;
        case 4:
            listar_carros_selecao_opcionais();
            printf("\n\n");
            system("pause");
            break;
        case 5:
            listar_carros_selecao_ano_fabricacao();
            printf("\n\n");
            system("pause");
            break;

        default:
            ERRO_OPCAO;
            system("pause");
            break;
        }
    } while (opc != 0);
}

void menu_cliente()
{
    int opc;
    do
    {
        system("cls");
        printf("OPCOES:\n\n0 - RETORNAR AO MENU PRINCIPAL\n1 - INSERIR UM CLIENTE NO CADASTRO\n2 - EXCLUIR UM CLIENTE DO CADASTRO");
        printf("\n3 - LISTAR OS CLIENTES NO CADASTRO ORDENADOS CRESCENTEMENTE PELO NOME");
        printf("\n4 - LISTAR OS CLIENTES NO CADASTRO ORDENADOS CRESCENTEMENTE PELO NOME POR SELECAO DE FAIXA DE RENDA SALARIAL MENSAL");
        printf("\n\nINFORME A SUA OPCAO: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 0:
            RETORNA;
            printf("\n\n");
            system("pause");
            break;
        case 1:
            gera_cliente();
            printf("\n\n");
            system("pause");
            break;
        case 2:
            excluir_cliente();
            printf("\n\n");
            system("pause");
            break;
        case 3:
            lista_clientes_nome();
            printf("\n\n");
            system("pause");
            break;
        case 4:
            lista_clientes_selecao_salario();
            printf("\n\n");
            system("pause");
            break;

        default:
            ERRO_OPCAO;
            system("pause");
            break;
        }
    } while (opc != 0);
}

void menu_venda()
{
    int opc;
    do
    {
        system("cls");
        printf("OPCOES:\n\n0 - RETORNAR AO MENU PRINCIPAL\n1 - INSERIR UMA VENDA\n2 - EXCLUIR UMA VENDA");
        printf("\n3 - LISTAR OS CARROS VENDIDOS DE UM DETERMINADO FABRICANTE, ORDENADOS CRESCENTEMENTE PELO MODELO");
        printf("\n4 - LISTAR OS CARROS VENDIDOS DE UM DETERMINADO MODELO, ORDENADOS CRESCENTEMENTE PELO ANO DE FABRICACAO");
        printf("\n5 - INFORMAR A QUANTIDADE DE CARROS VENDIDOS COM O VALOR TOTALIZADO DOS PRECOS VENDIDOS");
        printf("\n6 - INFORMAR O LUCRO TOTAL DAS VENDAS\n\nINFORME A SUA OPCAO: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 0:
            RETORNA;
            printf("\n\n");
            system("pause");
            break;
        case 1:
            inserir_venda();
            printf("\n\n");
            system("pause");
            break;
        case 2:
            excluir_venda();
            printf("\n\n");
            system("pause");
            break;
        case 3:
            listar_vendas_por_fabricante();
            printf("\n\n");
            system("pause");
            break;
        case 4:
            listar_vendas_por_modelo();
            printf("\n\n");
            system("pause");
            break;
        case 5:
            quantidade_vendas();
            printf("\n\n");
            system("pause");
            break;
        case 6:
            lucro_total_vendas();
            printf("\n\n");
            system("pause");
            break;

        default:
            ERRO_OPCAO;
            system("pause");
            break;
        }
    } while (opc != 0);
}

void menu_principal()
{
    int opc;
    do
    {
        system("cls");
        printf("OPCOES:\n\n1 - CARRO\n2 - CLIENTE\n3 - VENDA\n4 - SAIR DO PROGRAMA\n\nINFORME SUA OPCAO: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            system("cls");
            menu_carro();
            break;
        case 2:
            system("cls");
            menu_cliente();
            break;
        case 3:
            system("cls");
            menu_venda();
            break;
        case 4:
            printf("\nOPERACAO FINALIZADA COM SUCESSO!\n\n");
            system("pause");
            break;

        default:
            ERRO_OPCAO;
            system("pause");
            break;
        }
    } while (opc != 4);
}

int main()
{
    srand(time(NULL));

    menu_principal();

    return 0;
}