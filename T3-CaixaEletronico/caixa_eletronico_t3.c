/*
Trabalho 3 AEDI-I

Alunos:

Henrique Gettner de Oliveira RGM: 45767
Henrique Apolinário Iwamizu Tada RGM: 43927
Leandro Madeira de Oliveira RGM: 45280
Guilherme Garcia Gloor RGM: 45535
Felipe Echeverria Vilhalva RGM: 45611
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int opc_principal, opc_cliente, opc_relatorios;                                                                              // Controle das opcões dos menus
int cedulas[8] = {100, 200, 400, 800, 1600, 3200, 6400, 12800};                                                              // Quantidade de cada cedula
int cedulas_total = 100 + 200 + 400 + 800 + 1600 + 3200 + 6400 + 12800;                                                      // Total de cedulas
int valor_caixa = (500 * 100) + (150 * 200) + (50 * 400) + (20 * 800) + (10 * 1600) + (5 * 3200) + (2 * 6400) + (1 * 12800); // Valor total no caixa
int saque_total = 0;                                                                                                         // Valor total sacado no caixa
int cadastros = 0;                                                                                                           // Controle das contas no caixa
int saques_realizados[50][999];
char cedulas_escrita[8][17] = {"R$ 500,00 reais", "R$ 150,00 reais", "R$ 50,00 reais", "R$ 20,00 reais", "R$ 10,00 reais", "R$ 5,00 reais", "R$ 2,00 reais", "R$ 1,00 real"};
char clientes_cpf[50][15], clientes_conta[50][10]; // CPF e Conta corrente para 50 clientes

// objetivo:escolhe dentre as letras do alfabeto ('a'..'z') uma letra aleatoriamente
// parametros: nenhum
// retorno:a letra do alfabeto
char geraAlfabeto()
{
    int i;
    char letras[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    i = rand() % 26;
    return (letras[i] - 32);
}

// objetivo:escolhe dentre os numeros ('0'..'9') uma numero aleatoriamente
// parametros: nenhum
// retorno:o numero
char geraNumero()
{
    int i;
    char numeros[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    i = rand() % 9;
    return (numeros[i]);
}

// objetivo:gera aleatoriamente um numero de conta corrente no formato 999.999-X
// parametros: c onde armazera a conta gerada
// retorno:nenhum
void geraContaCorrente(char c[])
{
    char conta_corrente[10];
    int i;

    for (i = 0; i < 9; i++)
    {
        if (i < 3 || i > 3)
            conta_corrente[i] = geraNumero();
        if (i == 3)
            conta_corrente[i] = '.';
        if (i == 7)
            conta_corrente[i] = '-';
    }
    conta_corrente[8] = geraAlfabeto();
    conta_corrente[9] = '\0';

    for (i = 0; i < 11; i++)
        c[i] = conta_corrente[i];

    printf("\n\tConta Corrente: %s", conta_corrente);
}

// objetivo: verificar se a conta corrente está de acordo com o formato (999.999-X)
// parametros: conta corrente a ser verificada de acordo com o foramto (999.999-X)
// retorno: 1 se o formato for correto ou 0 se o formato for incorreto
int verifica_conta_corrente(char conta[])
{
    int i, valida = 1;

    for (i = 0; i < 9; i++)
    {
        if (i == 3)
        {
            if (conta[i] != '.')
                valida = 0;
        }
        if (i == 7)
        {
            if (conta[i] != '-')
                valida = 0;
        }
    }

    return (valida);
}

// objetivo: Remover a pontução do cpf para verificar se é válido
// parametros: (cpf_com_pontucao) recebe o cpf pontuado e copia em (cpf_sem_pontuacao) o cpf sem pontuação
// retorno: (cpf_sem_pontuacao) cpf sem a pontuação
void remove_pontucao_cpf(char cpf_com_pontucao[], char cpf_sem_pontuacao[])
{
    char cpf[12];
    int i, ii = 0;

    for (i = 0; i < 14; i++)
    {
        if (ii == 3)
            ii = 4;
        if (ii == 7)
            ii = 8;
        if (ii == 11)
            ii = 12;
        cpf[i] = cpf_com_pontucao[ii];
        ii++;
    }

    for (i = 0; i < 11; i++)
        cpf_sem_pontuacao[i] = cpf[i];
}

// objetivo:verifica se um cpf no formato 999.999.999-99 e valido
// parametros: cpf a ser verificado
// retorno: 1 se cpf e valido ou 0 se cpf nao e valido
int verifica_cpf_valido(char cpf[])
{
    int valido = 1;
    char cpf_sem_pontucao[11];
    int dig[11], sequencia[11];
    int verifica, cont, i, ii, total = 0, digito_1 = 0, digito_2 = 0;
    long long int cpf_verifica, casas = 10000000000;

    remove_pontucao_cpf(cpf, cpf_sem_pontucao);
    cpf_verifica = atoll(cpf_sem_pontucao);

    for (i = 0; i <= 10; i++)
    {
        if (i < 10)
        {
            dig[i] = (cpf_verifica / casas) % 10;
            casas = casas / 10;
        }
        else
            dig[i] = (cpf_verifica % 10);
    }

    verifica = dig[0];
    cont = 0;

    for (i = 0; i < sizeof(cpf_sem_pontucao); i++)
        sequencia[i] = verifica * 1;

    for (i = 0; i < sizeof(cpf_sem_pontucao); i++)
    {
        if (dig[i] == sequencia[i])
            cont++;
    }

    if (cont == sizeof(cpf_sem_pontucao))
        valido = 0;
    else
    {
        for (i = 0, ii = 10; i < 9; i++, ii--)
            total += dig[i] * ii;

        digito_1 = 11 - (total % 11);

        if (digito_1 > 9)
            digito_1 = 0;

        if (dig[9] == digito_1)
        {
            total = 0;

            for (i = 0, ii = 11; i < 10; i++, ii--)
                total += dig[i] * ii;

            digito_2 = 11 - (total % 11);

            if (digito_2 > 9)
                digito_2 = 0;

            if (dig[10] != digito_2)
                valido = 0;
        }
        else
            valido = 0;
    }
    return (valido);
}

// objetivo:insere pontuacoes '.' e '- ' em um cpf
// parametros: cpf_origem o cpf recebido no format 99999999999
// retorno: cpf_destino o cpf com as pontuacoes inseridas no formato 999.999.999-99
void insere_pontuacao_cpf(char cpf_origem[], char cpf_destino[])
{
    char cpf[14];
    int i, ii = 0;

    for (i = 0; i < 14; i++)
    {
        if ((i < 3) || (i > 3 && i < 7) || (i > 7 && i < 11) || (i > 11))
        {
            cpf[i] = cpf_origem[ii];
            ii++;
        }
        if (i == 3 || i == 7)
            cpf[i] = '.';
        if (i == 11)
            cpf[i] = '-';
    }

    for (i = 0; i < 14; i++)
        cpf_destino[i] = cpf[i];
}

// objetivo:calcula o primeiro digito verificador de um cpf no formato 999999999
// parametros: cpf o cpf sem os digitos verificadores
// retorno: o calculo do primeiro digito verificador
int obtem_primeiro_digito_verificador(char cpf[])
{
    int digito = 0;
    int dig[9], total = 0, i, ii;
    long int cpf_verifica, casas = 100000000;
    cpf_verifica = atol(cpf);

    for (i = 0; i <= 8; i++)
    {
        if (i < 8)
        {
            dig[i] = (cpf_verifica / casas) % 10;
            casas = casas / 10;
        }
        else
            dig[i] = (cpf_verifica % 10);
    }

    for (i = 0, ii = 10; i < 9; i++, ii--)
        total += dig[i] * ii;

    digito = 11 - (total % 11);

    if (digito > 9)
        digito = 0;

    return (digito);
}

// objetivo:calcula o segundo digito verificador de um cpf no formato 999999999
// parametros: cpf sem os digitos verificadores
// retorno: o calculo do segundo digito verificador
int obtem_segundo_digito_verificador(char cpf[])
{
    int digito = 0;
    int dig[10], total = 0, i, ii;
    long long int cpf_verifica;
    long int casas = 100000000;
    cpf_verifica = atoll(cpf);

    for (i = 0; i <= 9; i++)
    {
        if (i < 9)
        {
            dig[i] = (cpf_verifica / casas) % 10;
            casas = casas / 10;
        }
    }

    for (i = 0, ii = 11; i < 10; i++, ii--)
        total += dig[i] * ii;

    digito = 11 - (total % 11);

    if (digito > 9)
        digito = 0;

    return (digito);
}

// objetivo:gera aleatoriamente um cpf valido no formato 999.999.999-99
// parametros: cpf onde sera armazenado o cpf valido
// retorno: nenhum
void gera_cpf_valido(char cpf[])
{
    char novo_cpf[15], cpf_sem_pontucao[11];
    char digitos[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int i, digito_1, digito_2;
    do
    {
        for (i = 0; i < 10; i++)
            cpf_sem_pontucao[i] = '\0';

        for (i = 0; i < 9; i++)
            cpf_sem_pontucao[i] = geraNumero();

        digito_1 = obtem_primeiro_digito_verificador(cpf_sem_pontucao);
        cpf_sem_pontucao[9] = digitos[digito_1];

        digito_2 = obtem_segundo_digito_verificador(cpf_sem_pontucao);
        cpf_sem_pontucao[10] = digitos[digito_2];

        insere_pontuacao_cpf(cpf_sem_pontucao, novo_cpf);

        novo_cpf[14] = '\0';

    } while (verifica_cpf_valido(novo_cpf) != 1);

    for (i = 0; i < 14; i++)
        cpf[i] = novo_cpf[i];

    printf("\n\tCPF: %s\n", novo_cpf);
}

// objetivo: incluir um cadastro por vez
// parametros: nenhum
// retorno: nenhum
void incluir()
{
    if (cadastros < 50)
    {
        printf("\nCliente %d:\n", cadastros + 1);
        geraContaCorrente(clientes_conta[cadastros]);
        gera_cpf_valido(clientes_cpf[cadastros]);
        printf("\n\tIncluindo clinte...\n");
        cadastros++;
    }
    else
        printf("\nNumero maximo de clientes cadastrados atingido!");
}

// objetivo: mostrar os cadastros inclusos
// parametros: nenhum
// retorno: nenhum
void mostrar()
{
    if (cadastros > 0)
    {
        printf("----------------------------------------------------------------------------------------------------------------------------");
        for (int i = 0; i < cadastros; i++)
        {
            if (clientes_conta[i] != '\0' || clientes_cpf[i] != '\0')
            {
                printf("\nCliente %d:", i + 1);
                printf("\n\tCPF: %s", clientes_cpf[i]);
                printf("\n\tCONTA CORRENTE: %s\n", clientes_conta[i]);
                printf("----------------------------------------------------------------------------------------------------------------------------");
            }
        }
        printf("\nCadastros restantes: %d", (cadastros - 50) * -1);
    }
    else
        printf("\n\nNENHUM CADASTRO INDENTIFICADO!\n");
}

// objetivo: alterar o cpf ou conta corrente do cliente que nao realizou um saque
// parametros: nenhum
// retorno: nenhum
void alterar()
{
    int i = 0, ii, opcao, indice_cliente, finaliza = 0;
    int veri_exist, veri_exist_2, veri_cpf, veri_conta, valida_cpf, valida_conta;
    int teste = 0;
    char conta[10];
    char novo_cpf[14];
    char nova_conta[9];

    if (cadastros > 0)
    {
        do
        {
            system("cls");
            printf("\nInforme sua conta corrente no formato (999.999-X) ou (s) para voltar.\n---> ");
            scanf("%s", conta);

            if (conta[0] == 's')
            {
                printf("\nVoltando . . .\n\n");
                system("pause");
                finaliza = 1;
            }
            else
            {
                do
                {
                    veri_exist = strcmp(conta, clientes_conta[i]);
                    if (veri_exist == 0)
                        indice_cliente = i;
                    i++;
                } while ((veri_exist != 0) && (i < cadastros));

                if ((veri_exist != 0) && (i == cadastros))
                {
                    printf("\nConta corrente inexistente ou formato errado!\nTente novamente mais tarde.\n\n");
                    system("pause");
                }
                if ((veri_exist == 0) && (saques_realizados[indice_cliente][0] == 0))
                {

                    do
                    {
                        system("cls");
                        printf("\nInforme 1 para alterar o CPF.\nInforme 2 para alterar a conta corrente.\nInforme 3 caso queira voltar.\n\nOpcao: ");
                        scanf("%d", &opcao);

                        if (opcao == 1)
                        {
                            do
                            {
                                system("cls");
                                printf("\nInforme o novo CPF no formato (999.999.999-99)\n---> ");
                                scanf("%s", &novo_cpf);

                                i = 0;
                                do
                                {
                                    veri_exist_2 = strcmp(novo_cpf, clientes_cpf[i]);
                                    if (veri_exist_2 == 0 && veri_exist_2 != indice_cliente)
                                    {
                                        printf("\nEste CPF ja esta registrado em outro cadastrado!\n\n");
                                        system("pause");
                                        finaliza = 1;
                                    }
                                    i++;
                                } while ((veri_exist_2 != 0) && (i < cadastros) && (finaliza != 1));

                                veri_cpf = strcmp(novo_cpf, clientes_cpf[indice_cliente]);

                                if ((veri_exist_2 != 0) && (veri_cpf != 0))
                                {
                                    if (verifica_cpf_valido(novo_cpf) == 1)
                                    {
                                        for (ii = 0; ii < 14; ii++)
                                            clientes_cpf[indice_cliente][ii] = novo_cpf[ii];

                                        clientes_cpf[indice_cliente][14] = '\0';

                                        printf("\nCPF alterado com sucesso!\n\n");
                                        system("pause");
                                        finaliza = 1;
                                    }
                                    else
                                    {
                                        printf("\nCPF INVALIDO!\nTente novamente!\n\n");
                                        system("pause");
                                    }
                                }
                                else if (veri_cpf == 0)
                                {
                                    printf("\nEste CPF ja esta registrado no seu cadastro!\n\n");
                                    system("pause");
                                    finaliza = 1;
                                }

                            } while (finaliza != 1);
                        }
                        else if (opcao == 2)
                        {
                            do
                            {
                                system("cls");
                                printf("\nInforme a nova conta corrente no formato (999.999-X)\n---> ");
                                scanf("%s", &nova_conta);

                                i = 0;
                                do
                                {
                                    veri_exist_2 = strcmp(nova_conta, clientes_conta[i]);
                                    if (veri_exist_2 == 0 && veri_exist_2 != indice_cliente)
                                    {
                                        printf("\nEsta conta corrente esta registrada em outro cadastrado!\n\n");
                                        system("pause");
                                        finaliza = 1;
                                    }
                                    i++;
                                } while ((veri_exist_2 != 0) && (i < cadastros) && (finaliza != 1));

                                veri_conta = strcmp(nova_conta, clientes_conta[indice_cliente]);

                                if ((veri_conta != 0) && (veri_exist_2 != 0))
                                {
                                    if (verifica_conta_corrente(nova_conta) == 1)
                                    {
                                        for (ii = 0; ii < 9; ii++)
                                            clientes_conta[indice_cliente][ii] = nova_conta[ii];

                                        clientes_conta[indice_cliente][9] = '\0';

                                        printf("\nConta corrente alterada com sucesso!\n\n");
                                        system("pause");
                                        finaliza = 1;
                                    }
                                    else
                                    {
                                        printf("\nCONTA CORRENTE INVALIDA!\nTente novamente!\n\n");
                                        system("pause");
                                    }
                                }
                                else if (veri_conta == 0)
                                {
                                    printf("\nEsta conta corrente esta registrado no seu cadastro!\n\n");
                                    system("pause");
                                    finaliza = 1;
                                }
                            } while (finaliza != 1);
                        }
                        else if (opcao == 3)
                        {
                            printf("\nOPERACAO FINALIZADA COM SUCESSO!\n\n");
                            system("pause");
                        }
                        else
                        {
                            printf("\nNUMERO DE OPCAO INVALIDA!\nTENTE NOVAMENTE.\n\n");
                            system("pause");
                        }
                    } while (opcao != 3 && finaliza != 1);
                }
                else if ((veri_exist == 0) && (saques_realizados[indice_cliente][0] > 0))
                {
                    printf("\nNao sera possivel alterar o seu cadastro!\nVerificamos um saque registrado em sua conta corrente.\n\n");
                    system("pause");
                }
            }

        } while (conta[0] == 's' && finaliza != 1);
    }
    else
    {
        printf("\n\nNENHUM CADASTRO INDENTIFICADO!\n\n");
        system("pause");
    }
}

// objetivo: zerar as posições do cpf e conta corrente do cadastro para excluir
// parametros: indice que indica qual cadastro deve ser zerado
// retorno: nenhum
void zera_indice(int indice)
{
    for (int i = indice; i < cadastros; i++)
    {
        strcpy(clientes_conta[i], clientes_conta[i + 1]);

        strcpy(clientes_cpf[i], clientes_cpf[i + 1]);
    }
}

// objetivo: excluir o cadastro que não realizou nenhum saque
// parametros: nenhum
// retorno: nenhum
void excluir()
{
    int i = 0, finaliza = 0, indice_cliente, verifica_conta;
    char conta[10];

    if (cadastros > 0)
    {
        do
        {
            system("cls");
            printf("\nInforme sua conta corrente no formato (999.999-X) ou (s) para voltar.\n---> ");
            scanf("%s", conta);
            if (conta[0] == 's')
            {
                printf("\nVoltando . . .\n\n");
                system("pause");
                finaliza = 1;
            }
            else
            {
                i = 0;
                do
                {
                    verifica_conta = strcmp(conta, clientes_conta[i]);
                    if (verifica_conta == 0)
                        indice_cliente = i;
                    i++;
                } while ((verifica_conta != 0) && (i < cadastros));

                if (verifica_conta == 0)
                {
                    if (saques_realizados[indice_cliente][0] == 0 && i <= cadastros)
                    {
                        zera_indice(indice_cliente);
                        cadastros -= 1;
                        printf("\nConta excluida com sucesso!\n\n");
                        system("pause");
                        finaliza = 1;
                    }
                    else
                    {
                        printf("\nNao sera possivel excluir o seu cadastro!\nVerificamos um saque registrado em sua conta corrente.\n\n");
                        system("pause");
                        finaliza = 1;
                    }
                }
                else if (verifica_conta != 0)
                {
                    printf("\nConta corrente inexistente ou formato errado!\nTente novamente.\n\n");
                    system("pause");
                }
            }

        } while (finaliza != 1);
    }
    else
        printf("\n\nNENHUM CADASTRO INDENTIFICADO!\n");
}

// objetivo: escrever um valor numérico por extenso
// parametros: valor para realizar a escrita e opcao que define se será em real ou cédulas
// retorno: nenhum
void escrita_extenso(int valor, int opcao)
{
    char unidades[10][8] = {" ", "um ", "dois ", "tres ", "quatro ", "cinco ", "seis ", "sete ", "oito ", "nove "};
    char unidades_cedulas[10][8] = {" ", "uma ", "duas ", "tres ", "quatro ", "cinco ", "seis ", "sete ", "oito ", "nove "};
    char entre_dez_e_vinte[10][11] = {" ", "onze ", "doze ", "treze ", "quatorze ", "quinze ", "dezesseis ", "dezessete ", "dezoito ", "dezenove "};
    char dezenas[10][11] = {" ", "dez ", "vinte ", "trinta ", "quarenta ", "cinquenta ", "sessenta ", "setenta ", "oitenta ", "noventa "};
    char dezenas_com_e[10][13] = {" ", " ", "vinte e ", "trinta e ", "quarenta e ", "cinquenta e ", "sessenta e ", "setenta e ", "oitenta e ", "noventa e "};
    char centenas[10][14] = {" ", "cem ", "duzentos ", "trezentos ", "quatrocentos ", "quinhentos ", "seiscentos ", "setecentos ", "oitocentos ", "novecentos "};
    char centenas_cedulas[10][14] = {" ", "cem ", "duzentas ", "trezentas ", "quatrocentas ", "quinhentas ", "seiscentas ", "setecentas ", "oitocentas ", "novecentas "};
    char centenas_com_e[10][16] = {" ", "cento e ", "duzentos e ", "trezentos e ", "quatrocentos e ", "quinhentos e ", "seiscentos e ", "setecentos e ", "oitocentos e ", "novecentos e "};
    int d1, d2, d3, d4, d5, d6;

    d1 = d2 = d3 = d4 = d5 = d6 = 0;
    d1 = (valor % 10);          // Unidade
    d2 = (valor / 10) % 10;     // Dezena
    d3 = (valor / 100) % 10;    // Centena
    d4 = (valor / 1000) % 10;   // Milhar
    d5 = (valor / 10000) % 10;  // Dezena de milhar
    d6 = (valor / 100000) % 10; // Centena de milhar

    if (valor > 0)
    {
        if (d6 > 0)
        {
            if ((d5 == 0) && (d4 == 0))
                printf("%s", centenas[1]);
            else
                printf("%s", centenas_com_e[1]);
        }

        if (d5 > 0)
        {
            if (d4 > 0)
            {
                if (d5 == 1)
                    printf("%s", entre_dez_e_vinte[d4]);
                else
                    printf("%s", dezenas_com_e[d5]);
            }
            else
                printf("%s", dezenas[d5]);
        }

        if ((d4 > 0) && (d5 != 1))
            printf("%s", unidades[d4]);

        if (((d1 == 0) && (d2 == 0)) && ((d3 == 0) && (d6 > 0)) || ((d5 > 0) || (d4 > 0)))
            printf("mil ");

        if (((d6 > 0) || (d5 > 0) || (d4 > 0)) && ((d3 > 0) || (d2 > 0) || (d1 > 0)))
            printf("e ");

        if (d3 > 0)
        {
            if ((d2 > 0) || (d1 > 0))
                printf("%s", centenas_com_e[d3]);
            else
            {
                if (opcao == 1)
                    printf("%s", centenas[d3]);
                else if (opcao == 2)
                    printf("%s", centenas_cedulas[d3]);
            }
        }

        if (d2 > 0)
        {
            if (d1 > 0)
            {
                if (d2 == 1)
                    printf("%s", entre_dez_e_vinte[d1]);
                else
                    printf("%s", dezenas_com_e[d2]);
            }
            else
                printf("%s", dezenas[d2]);
        }

        if ((d1 > 0) && (d2 != 1))
        {
            if (opcao == 1)
                printf("%s", unidades[d1]);
            else if (opcao == 2)
                printf("%s", unidades_cedulas[d1]);
        }
    }
    else
        printf("zero ");

    if (opcao == 1)
    {
        if (valor > 1) // Plural
            printf("reais");
        else if ((valor == 1) || (valor == 0)) // Singular
            printf("real");
    }
    else if (opcao == 2)
    {
        if (valor > 1) // Plural
            printf("cedulas");
        else if ((valor == 1) || (valor == 0)) // Singular
            printf("cedula");
    }
}

// objetivo: distribuir a menor quantidade de cédulas possíveis para o saque
// parametros: valor_saque para realizar a distribuição
// retorno: nenhum
void distribuicao_cedulas(int valor_saque)
{
    int verifica_saque = valor_saque;
    int cedulas_usadas[8];
    int valor_cedulas[8] = {500, 150, 50, 20, 10, 5, 2, 1};

    for (int i = 0; i < 8; i++)
        cedulas_usadas[i] = 0;

    for (int ii = 0; ii < 8; ii++)
    {
        while ((cedulas[ii] > 0) && (verifica_saque >= valor_cedulas[ii]))
        {
            cedulas[ii] -= 1;
            saque_total += valor_cedulas[ii];
            cedulas_total -= 1;
            verifica_saque -= valor_cedulas[ii];
            valor_caixa -= valor_cedulas[ii];
            cedulas_usadas[ii] += 1;
        }
    }

    printf("\nCedulas utilizadas:\n");

    for (int j = 0; j < 8; j++)
    {
        if (cedulas_usadas[j] > 1)
            printf("\n%d cedulas de %s", cedulas_usadas[j], cedulas_escrita[j]);
        else if (cedulas_usadas[j] == 1)
            printf("\n%d cedula de %s", cedulas_usadas[j], cedulas_escrita[j]);
    }
}

// objetivo: realizar o saque informando a conta corrente
// parametros: nenhum
// retorno: nenhum
void saque()
{
    char conta[10];
    int i = 0, verifica, saque_cliente, valor_saque, finaliza = 0;
    int controle;

    do
    {
        do
        {
            system("cls");
            printf("\nInforme a sua conta corrente no formato (999.999-X) ou (s) para voltar\n---> ");
            scanf("%s", &conta);

            if (conta[0] == 's')
            {
                printf("\nVoltando . . .");
                finaliza = 1;
            }
            else
            {
                do
                {
                    verifica = strcmp(conta, clientes_conta[i]);

                    if (verifica == 0)
                        saque_cliente = i;
                    i++;

                } while (verifica != 0 && i < cadastros);

                if (verifica < 0 || verifica > 0)
                {
                    printf("\nConta corrente inexistente ou formato errado!\nTente novamente.\n\n");
                    system("pause");
                    i = 0;
                }
            }

        } while (verifica != 0 && conta[0] != 's');

        if (verifica == 0)
        {
            system("cls");
            printf("\nInforme o valor do saque: ");
            scanf("%d", &valor_saque);

            while (valor_saque < 1)
            {
                system("cls");
                printf("\nO valor de saque nao pode ser menor que R$ 1,00 real!\n\nInforme novamente o valor de saque: ");
                scanf("%d", &valor_saque);
            }

            if (valor_saque <= valor_caixa)
            {
                controle = 1;
                for (i = 0; i < 999; i++)
                {
                    if (!saques_realizados[saque_cliente][i] > 0)
                    {
                        if (controle)
                        {
                            saques_realizados[saque_cliente][i] = valor_saque;
                            controle = 0;
                        }
                    }
                }
                distribuicao_cedulas(valor_saque);
                printf("\n\nSaque realizado no valor de ");
                escrita_extenso(valor_saque, 1);
                finaliza = 1;
            }
            else
            {
                printf("\nATENCAO\n\nValor de R$ %d,00 reais nao disponivel para saque!", valor_saque);
                if (valor_caixa > 0)
                {
                    printf("\nSaque maximo: R$ %d,00\n\n", valor_caixa);
                    system("pause");
                }
                else
                {
                    printf("\nCaixa sem cedulas!\n", valor_caixa);
                    finaliza = 1;
                }
            }
        }

    } while (finaliza != 1);
}

// objetivo: informar os valores sacados por cada cadastro
// parametros: nenhum
// retorno: nenhum
void valores_sacados()
{
    int m, n, total = 0;

    printf("----------------------------------------------------------------------------------------------------------------------------");
    printf("\nRelatorio 'valores sacados'\n");
    printf("----------------------------------------------------------------------------------------------------------------------------\n");
    if (cadastros > 0)
    {
        for (m = 0; m < cadastros; m++)
        {
            total = 0;
            printf("\n%s %s", clientes_conta[m], clientes_cpf[m]);
            for (n = 0; n < 999; n++)
            {
                if (saques_realizados[m][n] != 0)
                {
                    if (n == 0)
                    {
                        printf("\tR$ %d,00 \n", saques_realizados[m][n]);
                        total = total + saques_realizados[m][n];
                    }
                    else
                    {
                        printf("\t\t\t\tR$ %d,00 \n", saques_realizados[m][n]);
                        total = total + saques_realizados[m][n];
                    }
                }
            }
            printf("\t\t\t\t\t R$ %d,00 \n", total);
        }
    }
    else
        printf("\nNENHUM CADASTRO INDENTIFICADO!\n");
    printf("\n----------------------------------------------------------------------------------------------------------------------------");
    printf("\nR$ %d,00 (", saque_total);
    escrita_extenso(saque_total, 1);
    printf(")\n----------------------------------------------------------------------------------------------------------------------------");
}

// objetivo: informar o saldo existente no caixa
// parametros: nenhum
// retorno: nenhum
void saldo_existente()
{
    printf("----------------------------------------------------------------------------------------------------------------------------");
    printf("\nRelatorio 'Valor do saldo existente'\n");
    printf("----------------------------------------------------------------------------------------------------------------------------");
    printf("\nR$ %d,00 (", valor_caixa);
    escrita_extenso(valor_caixa, 1);
    printf(")\n----------------------------------------------------------------------------------------------------------------------------");
}

// objetivo: informar a quantidade de cada cédula no caixa e o total
// parametros: nenhum
// retorno: nenhum
void cedulas_existentes()
{
    char escrita_notas[8][28] = {" de quinhentos reais", " de cento e cinquenta reais", " de cinquenta reais", " de vinte reais", " de dez reais", " de cinco reais", " de dois reais", " de um real"};
    printf("----------------------------------------------------------------------------------------------------------------------------");
    printf("\nRelatorio 'Quantidade de cedulas existentes'\n");
    printf("----------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < 8; i++)
    {
        printf("Cedula de %s: %d (", cedulas_escrita[i], cedulas[i]);
        escrita_extenso(cedulas[i], 2);
        printf("%s)\n", escrita_notas[i]);
    }
    printf("----------------------------------------------------------------------------------------------------------------------------");
    printf("\n%d (", cedulas_total);
    escrita_extenso(cedulas_total, 2);
    printf(")\n----------------------------------------------------------------------------------------------------------------------------");
}

void menu_cliente()
{
    do
    {
        system("cls");
        printf("\nMENU CLIENTE\n\n1 - Incluir.\n2 - Mostrar.\n3 - Alterar.\n4 - Excluir.\n5 - Voltar.\n\nInforme a sua opcao: ");
        scanf("%d", &opc_cliente);

        switch (opc_cliente)
        {

        case 1:
            system("cls");
            printf("\nOPCAO: INCLUIR CLIENTE\n");
            incluir();
            printf("\n\n");
            system("pause");
            break;

        case 2:
            system("cls");
            printf("\nOPCAO: MOSTRAR CLIENTE\n");
            mostrar();
            printf("\n\n");
            system("pause");
            break;

        case 3:
            system("cls");
            printf("\nOPCAO: ALTERAR CLIENTE\n");
            alterar();
            break;

        case 4:
            system("cls");
            printf("\nOPCAO: EXCLUIR CLIENTE\n");
            excluir();
            printf("\n\n");
            break;

        case 5:
            printf("\nOPERACAO FINALIZADA COM SUCESSO!\n\n");
            system("pause");
            break;

        default:
            printf("\nNUMERO DE OPCAO INVALIDA!\nTENTE NOVAMENTE.\n\n");
            system("pause");
            break;
        }

    } while (opc_cliente != 5);
}

void menu_relatorios()
{
    do
    {
        system("cls");
        printf("\nMENU RELATORIOS\n\n1 - Valores sacados.\n2 - Valor do saldo existente.\n3 - Quantidade de cedulas existentes.\n4 - Voltar ao menu principal.\n\nInforme a sua opcao: ");
        scanf("%d", &opc_relatorios);

        switch (opc_relatorios)
        {

        case 1:
            system("cls");
            valores_sacados();
            printf("\n\n");
            system("pause");
            break;

        case 2:
            system("cls");
            saldo_existente();
            printf("\n\n");
            system("pause");
            break;

        case 3:
            system("cls");
            cedulas_existentes();
            printf("\n\n");
            system("pause");
            break;

        case 4:
            printf("\nOPERACAO FINALIZADA COM SUCESSO!\n\n");
            system("pause");
            break;

        default:
            printf("\nNUMERO DE OPCAO INVALIDA!\nTENTE NOVAMENTE.\n\n");
            system("pause");
            break;
        }

    } while (opc_relatorios != 4);
}

void menu_principal()
{
    do
    {
        system("cls");
        printf("\nMENU PRINCIPAL\n\n1 - Cliente.\n2 - Saque.\n3 - Relatorios.\n4 - Finalizar.\n\nInforme a sua opcao: ");
        scanf("%d", &opc_principal);

        switch (opc_principal)
        {

        case 1:
            system("cls");
            menu_cliente();
            break;

        case 2:
            system("cls");
            printf("\nOPCAO: SAQUE\n");
            saque();
            printf("\n\n");
            system("pause");
            break;

        case 3:
            system("cls");
            menu_relatorios();
            break;

        case 4:
            printf("\nOPERACAO FINALIZADA COM SUCESSO!\n\n");
            system("pause");
            break;

        default:
            printf("\nNUMERO DE OPCAO INVALIDA!\nTENTE NOVAMENTE.\n\n");
            system("pause");
            break;
        }

    } while (opc_principal != 4);
}

int main()
{
    srand(time(NULL));

    // Inicia a matriz que armazena os valores sacados de cada cliente
    for (int m = 0; m < 50; m++)
    {
        for (int n = 0; n < 999; n++)
            saques_realizados[m][n] = 0;
    }

    menu_principal();

    return 0;
}