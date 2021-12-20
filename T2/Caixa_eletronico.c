/*
Trabalho 2 - Caixa Eletrônico
Alunos:
Henrique Gettner de Oliveira RGM: 45767
Henrique Apolinário Iwamizu Tada RGM: 43927
Leandro Madeira de Oliveira RGM: 45280
Guilherme Garcia Gloor RGM: 45535
Felipe Echeverria Vilhalva RGM: 45611
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nota_500 = 0, nota_150 = 0, nota_50 = 0, nota_20 = 0, nota_10 = 0, nota_5 = 0, nota_2 = 0, nota_1 = 0;
    int qnt_500, qnt_150, qnt_50, qnt_20, qnt_10, qnt_5, qnt_2, qnt_1;
    int opc = 0, opc_ger = 0, opc_abs = 0, opc_menu = 0;
    int valor_saque = 0, total_existente = 0, total_sacado = 0, total_cedulas = 0, cedulas_abs = 0, verifica_saque = 0, verifica_abs = 0;
    int digito_1, digito_2, total, verifica, valida_verifica;
    int c1, c2, c3, c4, c5, c6;
    long long cpf_user, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;

    opc = -1;
    opc_ger = -1;

    nota_500 = 100;
    nota_150 = 200;
    nota_50 = 400;
    nota_20 = 800;
    nota_10 = 1600;
    nota_5 = 3200;
    nota_2 = 6400;
    nota_1 = 12800;

    // 173600 - total_existente.
    total_existente = (500 * nota_500) + (150 * nota_150) + (50 * nota_50) + (20 * nota_20) + (10 * nota_10) + (5 * nota_5) + (2 * nota_2) + (1 * nota_1);

    // 25500 - total_cedulas
    total_cedulas = (nota_500 + nota_150 + nota_50 + nota_20 + nota_10 + nota_5 + nota_2 + nota_1);

    do
    {
        system("cls");
        printf("\n\n---Bem vindo ao caixa eletronico!--\n\n");
        printf("---Menu principal---\n");
        printf("1 - Saque\n");
        printf("2 - Gerente\n");
        printf("3 - Finalizar\n");
        printf("\nDigite o numero da opcao desejada: ");
        scanf("%d", &opc);

        if (opc < 1 || opc > 3)
        {
            printf("\nOpcao inexistente, digite uma opcao valida.\n\n");
            system("pause");
            opc = -1; // Retorna ao menu principal
        }

        switch (opc) // Switch da opção solicitada no menu principal
        {
        case 1: // Saque
            cpf_user = d1 = d2 = d3 = d4 = d5 = d6 = d7 = d8 = d9 = d10 = d11 = 0;
            digito_1 = digito_2 = total = verifica = valida_verifica = 0;
            system("cls");
            printf("\nOPCAO ESCOLHIDA: SAQUE\n");
            printf("\nINFORME SEU CPF: ");
            scanf("%lld", &cpf_user);

            //VALIDAÇÃO DO CPF
            d11 = cpf_user % 10;
            d10 = (cpf_user / 10) % 10;
            d9 = (cpf_user / 100) % 10;
            d8 = (cpf_user / 1000) % 10;
            d7 = (cpf_user / 10000) % 10;
            d6 = (cpf_user / 100000) % 10;
            d5 = (cpf_user / 1000000) % 10;
            d4 = (cpf_user / 10000000) % 10;
            d3 = (cpf_user / 100000000) % 10;
            d2 = (cpf_user / 1000000000) % 10;
            d1 = cpf_user / 10000000000;
            // Verificação de sequencia
            if ((cpf_user == 0) || (cpf_user == -0) || (cpf_user == 11111111111) || (cpf_user == 22222222222) || (cpf_user == 33333333333) || (cpf_user == 44444444444) || (cpf_user == 55555555555) || (cpf_user == 66666666666) || (cpf_user == 77777777777) || (cpf_user == 88888888888) || (cpf_user == 99999999999))
            {
                printf("\nCPF Invalido, tente novamente!\n\n");
                system("pause");
                opc = -1; // Retorna ao menu principal
                break;
            }
            else
            {
                // Cálculo do dígito 1
                total += ((d1 * 10) + (d2 * 9) + (d3 * 8) + (d4 * 7) + (d5 * 6) + (d6 * 5) + (d7 * 4) + (d8 * 3) + (d9 * 2));
                digito_1 = 11 - (total % 11);
                if (digito_1 > 9)
                {
                    digito_1 = 0;
                }

                // Cálculo do dígito 2
                total = 0;
                total += ((d1 * 11) + (d2 * 10) + (d3 * 9) + (d4 * 8) + (d5 * 7) + (d6 * 6) + (d7 * 5) + (d8 * 4) + (d9 * 3) + (digito_1 * 2));
                digito_2 = 11 - (total % 11);
                if (digito_2 > 9)
                {
                    digito_2 = 0;
                }

                // Cálculos para a validação
                verifica = (d10 * 10) + d11;
                valida_verifica = (10 * digito_1) + digito_2;

                // Verifica se o CPF é inválido
                if (verifica != valida_verifica)
                {
                    printf("\nCPF Invalido, tente novamente!\n\n");
                    system("pause");
                    opc = -1; // Retorna ao menu principal
                    break;
                }
                else // Se o CPF for válido
                {
                    printf("\nOla, cliente.\n");
                    printf("\nInsira o valor do saque desejado: ");
                    scanf("%d", &valor_saque);

                    // Validação de entrada
                    if (valor_saque <= 0)
                    {
                        do
                        {
                            printf("\nValor invalido, o valor do saque deve ser maior ou igual a 1 real.\n");
                            printf("\nInsira novamente o valor desejado: ");
                            scanf("%d", &valor_saque);
                            system("cls");
                        } while (valor_saque <= 0);
                    }

                    // Verificar o valor do saque
                    verifica_saque = valor_saque;
                    // Quantidade de cada cédula
                    qnt_500 = qnt_150 = qnt_50 = qnt_20 = qnt_10 = qnt_5 = qnt_2 = qnt_1 = 0;
                    // Melhor distribuição de cédulas
                    while ((nota_500 > 0) && (verifica_saque >= 500))
                    {
                        nota_500 -= 1;
                        total_sacado += 500;
                        total_cedulas -= 1;
                        verifica_saque -= 500;
                        total_existente -= 500;
                        qnt_500 += 1;
                    }
                    while ((nota_150 > 0) && (verifica_saque >= 150))
                    {
                        nota_150 -= 1;
                        total_sacado += 150;
                        total_cedulas -= 1;
                        verifica_saque -= 150;
                        total_existente -= 150;
                        qnt_150 += 1;
                    }
                    while ((nota_50 > 0) && (verifica_saque >= 50))
                    {
                        nota_50 -= 1;
                        total_sacado += 50;
                        total_cedulas -= 1;
                        verifica_saque -= 50;
                        total_existente -= 50;
                        qnt_50 += 1;
                    }
                    while ((nota_20 > 0) && (verifica_saque >= 20))
                    {
                        nota_20 -= 1;
                        total_sacado += 20;
                        total_cedulas -= 1;
                        verifica_saque -= 20;
                        total_existente -= 20;
                        qnt_20 += 1;
                    }
                    while ((nota_10 > 0) && (verifica_saque >= 10))
                    {
                        nota_10 -= 1;
                        total_sacado += 10;
                        total_cedulas -= 1;
                        verifica_saque -= 10;
                        total_existente -= 10;
                        qnt_10 += 1;
                    }
                    while ((nota_5 > 0) && (verifica_saque >= 5))
                    {
                        nota_5 -= 1;
                        total_sacado += 5;
                        total_cedulas -= 1;
                        verifica_saque -= 5;
                        total_existente -= 5;
                        qnt_5 += 1;
                    }
                    while ((nota_2 > 0) && (verifica_saque >= 2))
                    {
                        nota_2 -= 1;
                        total_sacado += 2;
                        total_cedulas -= 1;
                        verifica_saque -= 2;
                        total_existente -= 2;
                        qnt_2 += 1;
                    }
                    while ((nota_1 > 0) && (verifica_saque >= 1))
                    {
                        nota_1 -= 1;
                        total_sacado += 1;
                        total_cedulas -= 1;
                        verifica_saque -= 1;
                        total_existente -= 1;
                        qnt_1 += 1;
                    }

                    // Verificação da existência do valor solicitado no caixa
                    if (verifica_saque > 0)
                    {
                        valor_saque = valor_saque - verifica_saque;
                        system("cls");
                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                        printf("\nATENCAO\n");
                        printf("\nValor de R$ %d,00 reais nao disponivel para saque.", verifica_saque);
                        printf("\nVerifique o abastecimento do caixa com o gerente!\n\n");
                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                        system("pause");
                        system("cls");
                    }
                    system("cls");
                    if ((verifica_saque == 0) && (valor_saque > 0))
                    {
                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                        printf("\nOperacao realizada com sucesso!\n");
                    }
                    else if ((verifica_saque > 0) && (valor_saque > 0))
                    {
                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                        printf("\nOperacao realizada!\n");
                    }

                    if ((total_cedulas > 0) || (valor_saque > 0)) // Só vai executar se tiver cédulas no caixa
                    {
                        // Cédulas utilizadas para realizar o saque
                        printf("\nCEDULAS UTILIZADAS:\n\n");
                        if (qnt_500 > 1) // Plural
                        {
                            printf("%d cedulas de quinhentos reais.\n", qnt_500);
                        }
                        else if (qnt_500 == 1) // Singular
                        {
                            printf("%d cedula de quinhentos reais.\n", qnt_500);
                        }
                        if (qnt_150 > 1) // Plural
                        {
                            printf("%d cedulas de cento e cinquenta reais.\n", qnt_150);
                        }
                        else if (qnt_150 == 1) // Singular
                        {
                            printf("%d cedula de cento e cinquenta reais.\n", qnt_150);
                        }
                        if (qnt_50 > 1) // Plural
                        {
                            printf("%d cedulas de cinquenta reais.\n", qnt_50);
                        }
                        else if (qnt_50 == 1) // Singular
                        {
                            printf("%d cedula de cinquenta reais.\n", qnt_50);
                        }
                        if (qnt_20 > 1) // Plural
                        {
                            printf("%d cedulas de vinte reais.\n", qnt_20);
                        }
                        else if (qnt_20 == 1) // Singular
                        {
                            printf("%d cedula de vinte reais.\n", qnt_20);
                        }
                        if (qnt_10 > 1) // Plural
                        {
                            printf("%d cedulas de dez reais.\n", qnt_10);
                        }
                        else if (qnt_10 == 1) // Singular
                        {
                            printf("%d cedula de dez reais.\n", qnt_10);
                        }
                        if (qnt_5 > 1) // Plural
                        {
                            printf("%d cedulas de cinco reais.\n", qnt_5);
                        }
                        else if (qnt_5 == 1) // Singular
                        {
                            printf("%d cedula de cinco reais.\n", qnt_5);
                        }
                        if (qnt_2 > 1) // Plural
                        {
                            printf("%d cedulas de dois reais.\n", qnt_2);
                        }
                        else if (qnt_2 == 1) // Singular
                        {
                            printf("%d cedula de dois reais.\n", qnt_2);
                        }
                        if (qnt_1 > 1) // Plural
                        {
                            printf("%d cedulas de um real.\n", qnt_1);
                        }
                        else if (qnt_1 == 1) // Singular
                        {
                            printf("%d cedula de um real.\n", qnt_1);
                        }

                        // Separação dos digitos do valor de saque solicitado para informá-lo por extenso
                        c1 = c2 = c3 = c4 = c5 = c6 = 0;
                        c1 = (valor_saque % 10);          // Unidade
                        c2 = (valor_saque / 10) % 10;     // Dezena
                        c3 = (valor_saque / 100) % 10;    // Centena
                        c4 = (valor_saque / 1000) % 10;   // Milhar
                        c5 = (valor_saque / 10000) % 10;  // Dezena de milhar
                        c6 = (valor_saque / 100000) % 10; // Centena de milhar

                        if (valor_saque > 0)
                        {
                            printf("\nSaque realizado no valor de ");
                        }
                        // Centena de milhar
                        if (c6 > 0)
                        {
                            if ((c5 == 0) && (c4 == 0))
                            {
                                printf("cem ");
                            }
                            else
                            {
                                printf("cento e ");
                            }
                        }
                        // Dezena de milhar
                        if (c5 > 0)
                        { // Parte do milhar
                            if (c4 > 0)
                            {
                                switch (c5)
                                {
                                case 1:
                                    if (c4 == 1)
                                    {
                                        printf("onze ");
                                    }
                                    else if (c4 == 2)
                                    {
                                        printf("doze ");
                                    }
                                    else if (c4 == 3)
                                    {
                                        printf("treze ");
                                    }
                                    else if (c4 == 4)
                                    {
                                        printf("quatorze ");
                                    }
                                    else if (c4 == 5)
                                    {
                                        printf("quinze ");
                                    }
                                    else
                                    {
                                        printf("dez");
                                    }
                                    break;
                                case 2:
                                    printf("vinte e ");
                                    break;
                                case 3:
                                    printf("trinta e ");
                                    break;
                                case 4:
                                    printf("quarenta e ");
                                    break;
                                case 5:
                                    printf("cinquenta e ");
                                    break;
                                case 6:
                                    printf("sessenta e ");
                                    break;
                                case 7:
                                    printf("setenta e ");
                                    break;
                                case 8:
                                    printf("oitenta e ");
                                    break;
                                case 9:
                                    printf("noventa e ");
                                }
                            }
                            else
                            {
                                switch (c5)
                                {
                                case 1:
                                    printf("dez ");
                                    break;
                                case 2:
                                    printf("vinte ");
                                    break;
                                case 3:
                                    printf("trinta ");
                                    break;
                                case 4:
                                    printf("quarenta ");
                                    break;
                                case 5:
                                    printf("cinquenta ");
                                    break;
                                case 6:
                                    printf("sessenta ");
                                    break;
                                case 7:
                                    printf("setenta ");
                                    break;
                                case 8:
                                    printf("oitenta ");
                                    break;
                                case 9:
                                    printf("noventa ");
                                    break;
                                }
                            }
                        }
                        // Milhar
                        if (c4 > 0)
                        {
                            if (c5 == 1)
                            {
                                switch (c4)
                                {
                                case 6:
                                    printf("esseis ");
                                    break;
                                case 7:
                                    printf("essete ");
                                    break;
                                case 8:
                                    printf("oito ");
                                    break;
                                case 9:
                                    printf("enove ");
                                    break;
                                }
                            }
                            else if (c5 != 1)
                            {
                                switch (c4)
                                {
                                case 1:
                                    printf("um ");
                                    break;
                                case 2:
                                    printf("dois ");
                                    break;
                                case 3:
                                    printf("tres ");
                                    break;
                                case 4:
                                    printf("quatro ");
                                    break;
                                case 5:
                                    printf("cinco ");
                                    break;
                                case 6:
                                    printf("seis ");
                                    break;
                                case 7:
                                    printf("sete ");
                                    break;
                                case 8:
                                    printf("oito ");
                                    break;
                                case 9:
                                    printf("nove ");
                                    break;
                                }
                            }
                        }
                        // Para finalizar o milhar e caso o cliente queira sacar um valor inexistente no caixa.
                        if (((c1 == 0) && (c2 == 0)) && ((c3 == 0) && (c6 > 0)) || ((c5 > 0) || (c4 > 0)))
                        {
                            printf("mil ");
                        }
                        if (((c6 > 0) || (c5 > 0) || (c4 > 0)) && ((c3 > 0) || (c2 > 0) || (c1 > 0)))
                        {
                            printf("e ");
                        }
                        // Centena
                        if (c3 > 0)
                        {
                            if ((c2 > 0) || (c1 > 0))
                            {
                                switch (c3)
                                {
                                case 1:
                                    printf("cento e ");
                                    break;
                                case 2:
                                    printf("duzentos e ");
                                    break;
                                case 3:
                                    printf("trezentos e ");
                                    break;
                                case 4:
                                    printf("quatrocentos e ");
                                    break;
                                case 5:
                                    printf("quinhentos e ");
                                    break;
                                case 6:
                                    printf("seiscentos e ");
                                    break;
                                case 7:
                                    printf("setecentos e ");
                                    break;
                                case 8:
                                    printf("oitocentos e ");
                                    break;
                                case 9:
                                    printf("novecentos e ");
                                    break;
                                }
                            }
                            else
                            {
                                switch (c3)
                                {
                                case 1:
                                    printf("cem ");
                                    break;
                                case 2:
                                    printf("duzentos ");
                                    break;
                                case 3:
                                    printf("trezentos ");
                                    break;
                                case 4:
                                    printf("quatrocentos ");
                                    break;
                                case 5:
                                    printf("quinhentos ");
                                    break;
                                case 6:
                                    printf("seiscentos ");
                                    break;
                                case 7:
                                    printf("setecentos ");
                                    break;
                                case 8:
                                    printf("oitocentos ");
                                    break;
                                case 9:
                                    printf("novecentos ");
                                    break;
                                }
                            }
                        }
                        // Dezena
                        if (c2 > 0)
                        {
                            if (c1 > 0)
                            {
                                switch (c2)
                                {
                                case 1:
                                    if (c1 == 1)
                                    {
                                        printf("onze ");
                                    }
                                    else if (c1 == 2)
                                    {
                                        printf("doze ");
                                    }
                                    else if (c1 == 3)
                                    {
                                        printf("treze ");
                                    }
                                    else if (c1 == 4)
                                    {
                                        printf("quatorze ");
                                    }
                                    else if (c1 == 5)
                                    {
                                        printf("quinze ");
                                    }
                                    else
                                    {
                                        printf("dez");
                                    }
                                    break;
                                case 2:
                                    printf("vinte e ");
                                    break;
                                case 3:
                                    printf("trinta e ");
                                    break;
                                case 4:
                                    printf("quarenta e ");
                                    break;
                                case 5:
                                    printf("cinquenta e ");
                                    break;
                                case 6:
                                    printf("sessenta e ");
                                    break;
                                case 7:
                                    printf("setenta e ");
                                    break;
                                case 8:
                                    printf("oitenta e ");
                                    break;
                                case 9:
                                    printf("noventa e ");
                                    break;
                                }
                            }
                            else
                            {
                                switch (c2)
                                {
                                case 1:
                                    printf("dez ");
                                    break;
                                case 2:
                                    printf("vinte ");
                                    break;
                                case 3:
                                    printf("trinta ");
                                    break;
                                case 4:
                                    printf("quarenta ");
                                    break;
                                case 5:
                                    printf("cinquenta ");
                                    break;
                                case 6:
                                    printf("sessenta ");
                                    break;
                                case 7:
                                    printf("setenta ");
                                    break;
                                case 8:
                                    printf("oitenta ");
                                    break;
                                case 9:
                                    printf("noventa ");
                                    break;
                                }
                            }
                        }
                        // Unidade
                        if (c1 > 0)
                        {
                            if (c2 == 1)
                            {
                                switch (c1)
                                {
                                case 6:
                                    printf("esseis ");
                                    break;
                                case 7:
                                    printf("essete ");
                                    break;
                                case 8:
                                    printf("oito ");
                                    break;
                                case 9:
                                    printf("enove ");
                                    break;
                                }
                            }
                            else if (c2 != 1)
                            {
                                switch (c1)
                                {
                                case 1:
                                    printf("um ");
                                    break;
                                case 2:
                                    printf("dois ");
                                    break;
                                case 3:
                                    printf("tres ");
                                    break;
                                case 4:
                                    printf("quatro ");
                                    break;
                                case 5:
                                    printf("cinco ");
                                    break;
                                case 6:
                                    printf("seis ");
                                    break;
                                case 7:
                                    printf("sete ");
                                    break;
                                case 8:
                                    printf("oito ");
                                    break;
                                case 9:
                                    printf("nove ");
                                    break;
                                }
                            }
                        }
                        if (valor_saque > 1) // Plural
                        {
                            printf("reais.\n");
                        }
                        else if (valor_saque == 1) // Singular
                        {
                            printf("real.\n");
                        }
                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                        printf("\n");
                        system("pause");
                        opc = -1; // Retorna ao menu principal
                        break;
                    }    // Fim da verificação da existência de cédulas para o saque
                    else // Se não tiver cédulas, retornará ao menu principal
                    {
                        opc = -1; // Retorna ao menu principal
                        break;
                    }
                } // Fim do else do CPF válido
            }     // Fim do else pós verificação da sequência
        case 2:
            do
            {
                system("cls");
                printf("\n---Menu Gerente--\n");
                printf("1 - Valor total sacado\n");
                printf("2 - Valor do saldo existente\n");
                printf("3 - Quantidade de cedulas existentes\n");
                printf("4 - Abastecer o caixa eletronico\n");
                printf("5 - Voltar ao menu principal\n");
                printf("\nDigite o numero da opcao desejada: ");
                scanf("%d", &opc_ger);

                if ((opc_ger < 1) || (opc_ger > 5))
                {
                    printf("\nOpcao inexistente, digite uma opcao valida.\n\n");
                    system("pause");
                }

                switch (opc_ger) // Switch da opção do gerente
                {
                case 1: // Valor total sacado
                    system("cls");

                    // Separação dos digitos do valor total sacado para informá-lo por extenso
                    c1 = c2 = c3 = c4 = c5 = c6 = 0;
                    c1 = (total_sacado % 10);          // Unidade
                    c2 = (total_sacado / 10) % 10;     // Dezena
                    c3 = (total_sacado / 100) % 10;    // Centena
                    c4 = (total_sacado / 1000) % 10;   // Milhar
                    c5 = (total_sacado / 10000) % 10;  // Dezena de milhar
                    c6 = (total_sacado / 100000) % 10; // Centena de milhar

                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");

                    if (total_sacado > 1) // Plural
                    {
                        printf("\nValor total sacado: R$ %d,00 reais, '", total_sacado);
                    }
                    else if ((total_sacado == 0) || (total_sacado == 1)) // Singular
                    {
                        printf("\nValor total sacado: R$ %d,00 real, '", total_sacado);
                    }

                    if ((c6 == 0) && (c5 == 0) && (c4 == 0) && (c3 == 0) && (c2 == 0) && (c1 == 0))
                    {
                        printf("zero ");
                    }
                    // Centena de milhar
                    if (c6 > 0)
                    {
                        if ((c5 == 0) && (c4 == 0))
                        {
                            printf("cem ");
                        }
                        else
                        {
                            printf("cento e ");
                        }
                    }
                    // Dezena de milhar
                    if (c5 > 0)
                    { // Parte do milhar
                        if (c4 > 0)
                        {
                            switch (c5)
                            {
                            case 1:
                                if (c4 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c4 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c4 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c4 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c4 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                            }
                        }
                        else
                        {
                            switch (c5)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Milhar
                    if (c4 > 0)
                    {
                        if (c5 == 1)
                        {
                            switch (c4)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c5 != 1)
                        {
                            switch (c4)
                            {
                            case 1:
                                printf("um ");
                                break;
                            case 2:
                                printf("dois ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    // Para finalizar o milhar e caso o cliente queira sacar um valor inexistente no caixa.
                    if (((c1 == 0) && (c2 == 0)) && ((c3 == 0) && (c6 > 0)) || ((c5 > 0) || (c4 > 0)))
                    {
                        printf("mil ");
                    }
                    if (((c6 > 0) || (c5 > 0) || (c4 > 0)) && ((c3 > 0) || (c2 > 0) || (c1 > 0)))
                    {
                        printf("e ");
                    }
                    // Centena
                    if (c3 > 0)
                    {
                        if ((c2 > 0) || (c1 > 0))
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cento e ");
                                break;
                            case 2:
                                printf("duzentos e ");
                                break;
                            case 3:
                                printf("trezentos e ");
                                break;
                            case 4:
                                printf("quatrocentos e ");
                                break;
                            case 5:
                                printf("quinhentos e ");
                                break;
                            case 6:
                                printf("seiscentos e ");
                                break;
                            case 7:
                                printf("setecentos e ");
                                break;
                            case 8:
                                printf("oitocentos e ");
                                break;
                            case 9:
                                printf("novecentos e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cem ");
                                break;
                            case 2:
                                printf("duzentos ");
                                break;
                            case 3:
                                printf("trezentos ");
                                break;
                            case 4:
                                printf("quatrocentos ");
                                break;
                            case 5:
                                printf("quinhentos ");
                                break;
                            case 6:
                                printf("seiscentos ");
                                break;
                            case 7:
                                printf("setecentos ");
                                break;
                            case 8:
                                printf("oitocentos ");
                                break;
                            case 9:
                                printf("novecentos ");
                                break;
                            }
                        }
                    }
                    // Dezena
                    if (c2 > 0)
                    {
                        if (c1 > 0)
                        {
                            switch (c2)
                            {
                            case 1:
                                if (c1 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c1 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c1 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c1 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c1 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c2)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Unidade
                    if (c1 > 0)
                    {
                        if (c2 == 1)
                        {
                            switch (c1)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c2 != 1)
                        {
                            switch (c1)
                            {
                            case 1:
                                printf("um ");
                                break;
                            case 2:
                                printf("dois ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    if (total_sacado > 1) // Plural
                    {
                        printf("reais'.\n");
                    }
                    else if ((total_sacado == 1) || (total_sacado == 0)) // Singular
                    {
                        printf("real'.\n");
                    }
                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                    system("pause");
                    opc_ger = -1; // Retorna ao menu do gerente
                    break;
                case 2: // Saldo existente
                    system("cls");

                    // Separação dos digitos do valor do saldo existente para informá-lo por extenso
                    c1 = c2 = c3 = c4 = c5 = c6 = 0;
                    c1 = (total_existente % 10);          // Unidade
                    c2 = (total_existente / 10) % 10;     // Dezena
                    c3 = (total_existente / 100) % 10;    // Centena
                    c4 = (total_existente / 1000) % 10;   // Milhar
                    c5 = (total_existente / 10000) % 10;  // Dezena de milhar
                    c6 = (total_existente / 100000) % 10; // Centena de milhar

                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");

                    if (total_existente > 1) // Plural
                    {
                        printf("\nValor do saldo existente no caixa: R$ %d,00 reais, '", total_existente);
                    }
                    else if ((total_existente == 0) || (total_existente == 1)) // Singular
                    {
                        printf("\nValor do saldo existente no caixa: R$ %d,00 real, '", total_existente);
                    }

                    if ((c6 == 0) && (c5 == 0) && (c4 == 0) && (c3 == 0) && (c2 == 0) && (c1 == 0))
                    {
                        printf("zero ");
                    }
                    // Centena de milhar
                    if (c6 > 0)
                    {
                        if ((c5 == 0) && (c4 == 0))
                        {
                            printf("cem ");
                        }
                        else
                        {
                            printf("cento e ");
                        }
                    }
                    // Dezena de milhar
                    if (c5 > 0)
                    { // Parte do milhar
                        if (c4 > 0)
                        {
                            switch (c5)
                            {
                            case 1:
                                if (c4 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c4 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c4 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c4 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c4 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                            }
                        }
                        else
                        {
                            switch (c5)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Milhar
                    if (c4 > 0)
                    {
                        if (c5 == 1)
                        {
                            switch (c4)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c5 != 1)
                        {
                            switch (c4)
                            {
                            case 1:
                                printf("um ");
                                break;
                            case 2:
                                printf("dois ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    // Para finalizar o milhar e caso o cliente queira sacar um valor inexistente no caixa.
                    if (((c1 == 0) && (c2 == 0)) && ((c3 == 0) && (c6 > 0)) || ((c5 > 0) || (c4 > 0)))
                    {
                        printf("mil ");
                    }
                    if (((c6 > 0) || (c5 > 0) || (c4 > 0)) && ((c3 > 0) || (c2 > 0) || (c1 > 0)))
                    {
                        printf("e ");
                    }
                    // Centena
                    if (c3 > 0)
                    {
                        if ((c2 > 0) || (c1 > 0))
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cento e ");
                                break;
                            case 2:
                                printf("duzentos e ");
                                break;
                            case 3:
                                printf("trezentos e ");
                                break;
                            case 4:
                                printf("quatrocentos e ");
                                break;
                            case 5:
                                printf("quinhentos e ");
                                break;
                            case 6:
                                printf("seiscentos e ");
                                break;
                            case 7:
                                printf("setecentos e ");
                                break;
                            case 8:
                                printf("oitocentos e ");
                                break;
                            case 9:
                                printf("novecentos e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cem ");
                                break;
                            case 2:
                                printf("duzentos ");
                                break;
                            case 3:
                                printf("trezentos ");
                                break;
                            case 4:
                                printf("quatrocentos ");
                                break;
                            case 5:
                                printf("quinhentos ");
                                break;
                            case 6:
                                printf("seiscentos ");
                                break;
                            case 7:
                                printf("setecentos ");
                                break;
                            case 8:
                                printf("oitocentos ");
                                break;
                            case 9:
                                printf("novecentos ");
                                break;
                            }
                        }
                    }
                    // Dezena
                    if (c2 > 0)
                    {
                        if (c1 > 0)
                        {
                            switch (c2)
                            {
                            case 1:
                                if (c1 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c1 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c1 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c1 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c1 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c2)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Unidade
                    if (c1 > 0)
                    {
                        if (c2 == 1)
                        {
                            switch (c1)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c2 != 1)
                        {
                            switch (c1)
                            {
                            case 1:
                                printf("um ");
                                break;
                            case 2:
                                printf("dois ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    if (total_existente > 1) // Plural
                    {
                        printf("reais'.\n");
                    }
                    else if ((total_existente == 1) || (total_existente == 0)) // Singular
                    {
                        printf("real'.\n");
                    }
                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                    system("pause");
                    opc_ger = -1; // Retorna ao menu do gerente
                    break;
                case 3: // Quantidade de cada cédula
                    system("cls");
                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                    printf("\nQUANTIDADE DE CADA CEDULA:\n");

                    // Cédulas de 1 real
                    if (nota_1 > 1) // Plural
                    {
                        printf("\n  Cedulas de 1 real: %d cedulas, '", nota_1);
                    }
                    else if ((nota_1 == 0) || (nota_1 == 1)) // Singular
                    {
                        printf("\n  Cedulas de 1 real: %d cedula, '", nota_1);
                    }

                    // Separação dos dígitos para informar o valor por extenso
                    c1 = c2 = c3 = c4 = c5 = c6 = 0;
                    c1 = (nota_1 % 10);          // Unidade
                    c2 = (nota_1 / 10) % 10;     // Dezena
                    c3 = (nota_1 / 100) % 10;    // Centena
                    c4 = (nota_1 / 1000) % 10;   // Milhar
                    c5 = (nota_1 / 10000) % 10;  // Dezena de milhar
                    c6 = (nota_1 / 100000) % 10; // Centena de milhar

                    if ((c6 == 0) && (c5 == 0) && (c4 == 0) && (c3 == 0) && (c2 == 0) && (c1 == 0))
                    {
                        printf("zero ");
                    }
                    // Centena de milhar
                    if (c6 > 0)
                    {
                        if ((c5 == 0) && (c4 == 0))
                        {
                            printf("cem ");
                        }
                        else
                        {
                            printf("cento e ");
                        }
                    }
                    // Dezena de milhar
                    if (c5 > 0)
                    { // Parte do milhar
                        if (c4 > 0)
                        {
                            switch (c5)
                            {
                            case 1:
                                if (c4 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c4 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c4 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c4 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c4 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                            }
                        }
                        else
                        {
                            switch (c5)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Milhar
                    if (c4 > 0)
                    {
                        if (c5 == 1)
                        {
                            switch (c4)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c5 != 1)
                        {
                            switch (c4)
                            {
                            case 1:
                                printf("um ");
                                break;
                            case 2:
                                printf("dois ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    // Para finalizar o milhar e caso o cliente queira sacar um valor inexistente no caixa.
                    if (((c1 == 0) && (c2 == 0)) && ((c3 == 0) && (c6 > 0)) || ((c5 > 0) || (c4 > 0)))
                    {
                        printf("mil ");
                    }
                    if (((c6 > 0) || (c5 > 0) || (c4 > 0)) && ((c3 > 0) || (c2 > 0) || (c1 > 0)))
                    {
                        printf("e ");
                    }
                    // Centena
                    if (c3 > 0)
                    {
                        if ((c2 > 0) || (c1 > 0))
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cento e ");
                                break;
                            case 2:
                                printf("duzentos e ");
                                break;
                            case 3:
                                printf("trezentos e ");
                                break;
                            case 4:
                                printf("quatrocentos e ");
                                break;
                            case 5:
                                printf("quinhentos e ");
                                break;
                            case 6:
                                printf("seiscentos e ");
                                break;
                            case 7:
                                printf("setecentos e ");
                                break;
                            case 8:
                                printf("oitocentos e ");
                                break;
                            case 9:
                                printf("novecentos e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cem ");
                                break;
                            case 2:
                                printf("duzentas ");
                                break;
                            case 3:
                                printf("trezentas ");
                                break;
                            case 4:
                                printf("quatrocentas ");
                                break;
                            case 5:
                                printf("quinhentas ");
                                break;
                            case 6:
                                printf("seiscentas ");
                                break;
                            case 7:
                                printf("setecentas ");
                                break;
                            case 8:
                                printf("oitocentas ");
                                break;
                            case 9:
                                printf("novecentas ");
                                break;
                            }
                        }
                    }
                    // Dezena
                    if (c2 > 0)
                    {
                        if (c1 > 0)
                        {
                            switch (c2)
                            {
                            case 1:
                                if (c1 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c1 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c1 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c1 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c1 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c2)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Unidade
                    if (c1 > 0)
                    {
                        if (c2 == 1)
                        {
                            switch (c1)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c2 != 1)
                        {
                            switch (c1)
                            {
                            case 1:
                                printf("uma ");
                                break;
                            case 2:
                                printf("duas ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    if (nota_1 > 1) // Plural
                    {
                        printf("cedulas de um real'.\n");
                    }
                    else if ((nota_1 == 1) || (nota_1 == 0)) // Singular
                    {
                        printf("cedula de um real'.\n");
                    }

                    // Cédulas de 2 reais
                    if (nota_2 > 1) // Plural
                    {
                        printf("\n  Cedulas de 2 reais: %d cedulas, '", nota_2);
                    }
                    else if ((nota_2 == 0) || (nota_2 == 1)) // Singular
                    {
                        printf("\n  Cedulas de 2 reais: %d cedula, '", nota_2);
                    }

                    // Separação dos dígitos para informar o valor por extenso
                    c1 = c2 = c3 = c4 = c5 = c6 = 0;
                    c1 = (nota_2 % 10);          // Unidade
                    c2 = (nota_2 / 10) % 10;     // Dezena
                    c3 = (nota_2 / 100) % 10;    // Centena
                    c4 = (nota_2 / 1000) % 10;   // Milhar
                    c5 = (nota_2 / 10000) % 10;  // Dezena de milhar
                    c6 = (nota_2 / 100000) % 10; // Centena de milhar

                    if ((c6 == 0) && (c5 == 0) && (c4 == 0) && (c3 == 0) && (c2 == 0) && (c1 == 0))
                    {
                        printf("zero ");
                    }
                    // Centena de milhar
                    if (c6 > 0)
                    {
                        if ((c5 == 0) && (c4 == 0))
                        {
                            printf("cem ");
                        }
                        else
                        {
                            printf("cento e ");
                        }
                    }
                    // Dezena de milhar
                    if (c5 > 0)
                    { // Parte do milhar
                        if (c4 > 0)
                        {
                            switch (c5)
                            {
                            case 1:
                                if (c4 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c4 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c4 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c4 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c4 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                            }
                        }
                        else
                        {
                            switch (c5)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Milhar
                    if (c4 > 0)
                    {
                        if (c5 == 1)
                        {
                            switch (c4)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c5 != 1)
                        {
                            switch (c4)
                            {
                            case 1:
                                printf("um ");
                                break;
                            case 2:
                                printf("dois ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    // Para finalizar o milhar e caso o cliente queira sacar um valor inexistente no caixa.
                    if (((c1 == 0) && (c2 == 0)) && ((c3 == 0) && (c6 > 0)) || ((c5 > 0) || (c4 > 0)))
                    {
                        printf("mil ");
                    }
                    if (((c6 > 0) || (c5 > 0) || (c4 > 0)) && ((c3 > 0) || (c2 > 0) || (c1 > 0)))
                    {
                        printf("e ");
                    }
                    // Centena
                    if (c3 > 0)
                    {
                        if ((c2 > 0) || (c1 > 0))
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cento e ");
                                break;
                            case 2:
                                printf("duzentos e ");
                                break;
                            case 3:
                                printf("trezentos e ");
                                break;
                            case 4:
                                printf("quatrocentos e ");
                                break;
                            case 5:
                                printf("quinhentos e ");
                                break;
                            case 6:
                                printf("seiscentos e ");
                                break;
                            case 7:
                                printf("setecentos e ");
                                break;
                            case 8:
                                printf("oitocentos e ");
                                break;
                            case 9:
                                printf("novecentos e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cem ");
                                break;
                            case 2:
                                printf("duzentas ");
                                break;
                            case 3:
                                printf("trezentas ");
                                break;
                            case 4:
                                printf("quatrocentas ");
                                break;
                            case 5:
                                printf("quinhentas ");
                                break;
                            case 6:
                                printf("seiscentas ");
                                break;
                            case 7:
                                printf("setecentas ");
                                break;
                            case 8:
                                printf("oitocentas ");
                                break;
                            case 9:
                                printf("novecentas ");
                                break;
                            }
                        }
                    }
                    // Dezena
                    if (c2 > 0)
                    {
                        if (c1 > 0)
                        {
                            switch (c2)
                            {
                            case 1:
                                if (c1 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c1 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c1 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c1 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c1 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c2)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Unidade
                    if (c1 > 0)
                    {
                        if (c2 == 1)
                        {
                            switch (c1)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c2 != 1)
                        {
                            switch (c1)
                            {
                            case 1:
                                printf("uma ");
                                break;
                            case 2:
                                printf("duas ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    if (nota_2 > 1) // Plural
                    {
                        printf("cedulas de dois reais'.\n");
                    }
                    else if ((nota_2 == 1) || (nota_2 == 0)) // Singular
                    {
                        printf("cedula de dois reais'.\n");
                    }

                    // Cédulas de 5 reais
                    if (nota_5 > 1) // Plural
                    {
                        printf("\n  Cedulas de 5 reais: %d cedulas, '", nota_5);
                    }
                    else if ((nota_5 == 0) || (nota_5 == 1)) // Singular
                    {
                        printf("\n  Cedulas de 5 reais: %d cedula, '", nota_5);
                    }

                    // Separação dos dígitos para informar o valor por extenso
                    c1 = c2 = c3 = c4 = c5 = c6 = 0;
                    c1 = (nota_5 % 10);          // Unidade
                    c2 = (nota_5 / 10) % 10;     // Dezena
                    c3 = (nota_5 / 100) % 10;    // Centena
                    c4 = (nota_5 / 1000) % 10;   // Milhar
                    c5 = (nota_5 / 10000) % 10;  // Dezena de milhar
                    c6 = (nota_5 / 100000) % 10; // Centena de milhar

                    if ((c6 == 0) && (c5 == 0) && (c4 == 0) && (c3 == 0) && (c2 == 0) && (c1 == 0))
                    {
                        printf("zero ");
                    }
                    // Centena de milhar
                    if (c6 > 0)
                    {
                        if ((c5 == 0) && (c4 == 0))
                        {
                            printf("cem ");
                        }
                        else
                        {
                            printf("cento e ");
                        }
                    }
                    // Dezena de milhar
                    if (c5 > 0)
                    { // Parte do milhar
                        if (c4 > 0)
                        {
                            switch (c5)
                            {
                            case 1:
                                if (c4 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c4 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c4 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c4 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c4 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                            }
                        }
                        else
                        {
                            switch (c5)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Milhar
                    if (c4 > 0)
                    {
                        if (c5 == 1)
                        {
                            switch (c4)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c5 != 1)
                        {
                            switch (c4)
                            {
                            case 1:
                                printf("um ");
                                break;
                            case 2:
                                printf("dois ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    // Para finalizar o milhar e caso o cliente queira sacar um valor inexistente no caixa.
                    if (((c1 == 0) && (c2 == 0)) && ((c3 == 0) && (c6 > 0)) || ((c5 > 0) || (c4 > 0)))
                    {
                        printf("mil ");
                    }
                    if (((c6 > 0) || (c5 > 0) || (c4 > 0)) && ((c3 > 0) || (c2 > 0) || (c1 > 0)))
                    {
                        printf("e ");
                    }
                    // Centena
                    if (c3 > 0)
                    {
                        if ((c2 > 0) || (c1 > 0))
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cento e ");
                                break;
                            case 2:
                                printf("duzentos e ");
                                break;
                            case 3:
                                printf("trezentos e ");
                                break;
                            case 4:
                                printf("quatrocentos e ");
                                break;
                            case 5:
                                printf("quinhentos e ");
                                break;
                            case 6:
                                printf("seiscentos e ");
                                break;
                            case 7:
                                printf("setecentos e ");
                                break;
                            case 8:
                                printf("oitocentos e ");
                                break;
                            case 9:
                                printf("novecentos e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cem ");
                                break;
                            case 2:
                                printf("duzentas ");
                                break;
                            case 3:
                                printf("trezentas ");
                                break;
                            case 4:
                                printf("quatrocentas ");
                                break;
                            case 5:
                                printf("quinhentas ");
                                break;
                            case 6:
                                printf("seiscentas ");
                                break;
                            case 7:
                                printf("setecentas ");
                                break;
                            case 8:
                                printf("oitocentas ");
                                break;
                            case 9:
                                printf("novecentas ");
                                break;
                            }
                        }
                    }
                    // Dezena
                    if (c2 > 0)
                    {
                        if (c1 > 0)
                        {
                            switch (c2)
                            {
                            case 1:
                                if (c1 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c1 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c1 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c1 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c1 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c2)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Unidade
                    if (c1 > 0)
                    {
                        if (c2 == 1)
                        {
                            switch (c1)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c2 != 1)
                        {
                            switch (c1)
                            {
                            case 1:
                                printf("uma ");
                                break;
                            case 2:
                                printf("duas ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    if (nota_5 > 1) // Plural
                    {
                        printf("cedulas de cinco reais'.\n");
                    }
                    else if ((nota_5 == 1) || (nota_5 == 0)) // Singular
                    {
                        printf("cedula de cinco reais'.\n");
                    }

                    // Cédulas de 10 reais
                    if (nota_10 > 1) // Plural
                    {
                        printf("\n  Cedulas de 10 reais: %d cedulas, '", nota_10);
                    }
                    else if ((nota_10 == 0) || (nota_10 == 1)) // Singular
                    {
                        printf("\n  Cedulas de 10 reais: %d cedula, '", nota_10);
                    }

                    // Separação dos dígitos para informar o valor por extenso
                    c1 = c2 = c3 = c4 = c5 = c6 = 0;
                    c1 = (nota_10 % 10);          // Unidade
                    c2 = (nota_10 / 10) % 10;     // Dezena
                    c3 = (nota_10 / 100) % 10;    // Centena
                    c4 = (nota_10 / 1000) % 10;   // Milhar
                    c5 = (nota_10 / 10000) % 10;  // Dezena de milhar
                    c6 = (nota_10 / 100000) % 10; // Centena de milhar

                    if ((c6 == 0) && (c5 == 0) && (c4 == 0) && (c3 == 0) && (c2 == 0) && (c1 == 0))
                    {
                        printf("zero ");
                    }
                    // Centena de milhar
                    if (c6 > 0)
                    {
                        if ((c5 == 0) && (c4 == 0))
                        {
                            printf("cem ");
                        }
                        else
                        {
                            printf("cento e ");
                        }
                    }
                    // Dezena de milhar
                    if (c5 > 0)
                    { // Parte do milhar
                        if (c4 > 0)
                        {
                            switch (c5)
                            {
                            case 1:
                                if (c4 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c4 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c4 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c4 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c4 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                            }
                        }
                        else
                        {
                            switch (c5)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Milhar
                    if (c4 > 0)
                    {
                        if (c5 == 1)
                        {
                            switch (c4)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c5 != 1)
                        {
                            switch (c4)
                            {
                            case 1:
                                printf("um ");
                                break;
                            case 2:
                                printf("dois ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    // Para finalizar o milhar e caso o cliente queira sacar um valor inexistente no caixa.
                    if (((c1 == 0) && (c2 == 0)) && ((c3 == 0) && (c6 > 0)) || ((c5 > 0) || (c4 > 0)))
                    {
                        printf("mil ");
                    }
                    if (((c6 > 0) || (c5 > 0) || (c4 > 0)) && ((c3 > 0) || (c2 > 0) || (c1 > 0)))
                    {
                        printf("e ");
                    }
                    // Centena
                    if (c3 > 0)
                    {
                        if ((c2 > 0) || (c1 > 0))
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cento e ");
                                break;
                            case 2:
                                printf("duzentos e ");
                                break;
                            case 3:
                                printf("trezentos e ");
                                break;
                            case 4:
                                printf("quatrocentos e ");
                                break;
                            case 5:
                                printf("quinhentos e ");
                                break;
                            case 6:
                                printf("seiscentos e ");
                                break;
                            case 7:
                                printf("setecentos e ");
                                break;
                            case 8:
                                printf("oitocentos e ");
                                break;
                            case 9:
                                printf("novecentos e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cem ");
                                break;
                            case 2:
                                printf("duzentas ");
                                break;
                            case 3:
                                printf("trezentas ");
                                break;
                            case 4:
                                printf("quatrocentas ");
                                break;
                            case 5:
                                printf("quinhentas ");
                                break;
                            case 6:
                                printf("seiscentas ");
                                break;
                            case 7:
                                printf("setecentas ");
                                break;
                            case 8:
                                printf("oitocentas ");
                                break;
                            case 9:
                                printf("novecentas ");
                                break;
                            }
                        }
                    }
                    // Dezena
                    if (c2 > 0)
                    {
                        if (c1 > 0)
                        {
                            switch (c2)
                            {
                            case 1:
                                if (c1 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c1 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c1 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c1 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c1 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c2)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Unidade
                    if (c1 > 0)
                    {
                        if (c2 == 1)
                        {
                            switch (c1)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c2 != 1)
                        {
                            switch (c1)
                            {
                            case 1:
                                printf("uma ");
                                break;
                            case 2:
                                printf("duas ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    if (nota_10 > 1) // Plural
                    {
                        printf("cedulas de dez reais'.\n");
                    }
                    else if ((nota_10 == 1) || (nota_10 == 0)) // Singular
                    {
                        printf("cedula de dez reais'.\n");
                    }

                    // Cédulas de 20 reais
                    if (nota_20 > 1) // Plural
                    {
                        printf("\n  Cedulas de 20 reais: %d cedulas, '", nota_20);
                    }
                    else if ((nota_20 == 0) || (nota_20 == 1)) // Singular
                    {
                        printf("\n  Cedulas de 20 reais: %d cedula, '", nota_20);
                    }

                    // Separação dos dígitos para informar o valor por extenso
                    c1 = c2 = c3 = c4 = c5 = c6 = 0;
                    c1 = (nota_20 % 10);          // Unidade
                    c2 = (nota_20 / 10) % 10;     // Dezena
                    c3 = (nota_20 / 100) % 10;    // Centena
                    c4 = (nota_20 / 1000) % 10;   // Milhar
                    c5 = (nota_20 / 10000) % 10;  // Dezena de milhar
                    c6 = (nota_20 / 100000) % 10; // Centena de milhar

                    if ((c6 == 0) && (c5 == 0) && (c4 == 0) && (c3 == 0) && (c2 == 0) && (c1 == 0))
                    {
                        printf("zero ");
                    }
                    // Centena de milhar
                    if (c6 > 0)
                    {
                        if ((c5 == 0) && (c4 == 0))
                        {
                            printf("cem ");
                        }
                        else
                        {
                            printf("cento e ");
                        }
                    }
                    // Dezena de milhar
                    if (c5 > 0)
                    { // Parte do milhar
                        if (c4 > 0)
                        {
                            switch (c5)
                            {
                            case 1:
                                if (c4 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c4 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c4 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c4 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c4 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                            }
                        }
                        else
                        {
                            switch (c5)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Milhar
                    if (c4 > 0)
                    {
                        if (c5 == 1)
                        {
                            switch (c4)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c5 != 1)
                        {
                            switch (c4)
                            {
                            case 1:
                                printf("um ");
                                break;
                            case 2:
                                printf("dois ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    // Para finalizar o milhar e caso o cliente queira sacar um valor inexistente no caixa.
                    if (((c1 == 0) && (c2 == 0)) && ((c3 == 0) && (c6 > 0)) || ((c5 > 0) || (c4 > 0)))
                    {
                        printf("mil ");
                    }
                    if (((c6 > 0) || (c5 > 0) || (c4 > 0)) && ((c3 > 0) || (c2 > 0) || (c1 > 0)))
                    {
                        printf("e ");
                    }
                    // Centena
                    if (c3 > 0)
                    {
                        if ((c2 > 0) || (c1 > 0))
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cento e ");
                                break;
                            case 2:
                                printf("duzentos e ");
                                break;
                            case 3:
                                printf("trezentos e ");
                                break;
                            case 4:
                                printf("quatrocentos e ");
                                break;
                            case 5:
                                printf("quinhentos e ");
                                break;
                            case 6:
                                printf("seiscentos e ");
                                break;
                            case 7:
                                printf("setecentos e ");
                                break;
                            case 8:
                                printf("oitocentos e ");
                                break;
                            case 9:
                                printf("novecentos e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cem ");
                                break;
                            case 2:
                                printf("duzentas ");
                                break;
                            case 3:
                                printf("trezentas ");
                                break;
                            case 4:
                                printf("quatrocentas ");
                                break;
                            case 5:
                                printf("quinhentas ");
                                break;
                            case 6:
                                printf("seiscentas ");
                                break;
                            case 7:
                                printf("setecentas ");
                                break;
                            case 8:
                                printf("oitocentas ");
                                break;
                            case 9:
                                printf("novecentas ");
                                break;
                            }
                        }
                    }
                    // Dezena
                    if (c2 > 0)
                    {
                        if (c1 > 0)
                        {
                            switch (c2)
                            {
                            case 1:
                                if (c1 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c1 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c1 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c1 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c1 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c2)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Unidade
                    if (c1 > 0)
                    {
                        if (c2 == 1)
                        {
                            switch (c1)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c2 != 1)
                        {
                            switch (c1)
                            {
                            case 1:
                                printf("uma ");
                                break;
                            case 2:
                                printf("duas ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    if (nota_20 > 1) // Plural
                    {
                        printf("cedulas de vinte reais'.\n");
                    }
                    else if ((nota_20 == 1) || (nota_20 == 0)) // Singular
                    {
                        printf("cedula de vinte reais'.\n");
                    }

                    // Cédulas de 50 reais
                    if (nota_50 > 1) // Plural
                    {
                        printf("\n  Cedulas de 50 reais: %d cedulas, '", nota_50);
                    }
                    else if ((nota_50 == 0) || (nota_50 == 1)) // Singular
                    {
                        printf("\n  Cedulas de 50 reais: %d cedula, '", nota_50);
                    }

                    // Separação dos dígitos para informar o valor por extenso
                    c1 = c2 = c3 = c4 = c5 = c6 = 0;
                    c1 = (nota_50 % 10);          // Unidade
                    c2 = (nota_50 / 10) % 10;     // Dezena
                    c3 = (nota_50 / 100) % 10;    // Centena
                    c4 = (nota_50 / 1000) % 10;   // Milhar
                    c5 = (nota_50 / 10000) % 10;  // Dezena de milhar
                    c6 = (nota_50 / 100000) % 10; // Centena de milhar

                    if ((c6 == 0) && (c5 == 0) && (c4 == 0) && (c3 == 0) && (c2 == 0) && (c1 == 0))
                    {
                        printf("zero ");
                    }
                    // Centena de milhar
                    if (c6 > 0)
                    {
                        if ((c5 == 0) && (c4 == 0))
                        {
                            printf("cem ");
                        }
                        else
                        {
                            printf("cento e ");
                        }
                    }
                    // Dezena de milhar
                    if (c5 > 0)
                    { // Parte do milhar
                        if (c4 > 0)
                        {
                            switch (c5)
                            {
                            case 1:
                                if (c4 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c4 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c4 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c4 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c4 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                            }
                        }
                        else
                        {
                            switch (c5)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Milhar
                    if (c4 > 0)
                    {
                        if (c5 == 1)
                        {
                            switch (c4)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c5 != 1)
                        {
                            switch (c4)
                            {
                            case 1:
                                printf("um ");
                                break;
                            case 2:
                                printf("dois ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    // Para finalizar o milhar e caso o cliente queira sacar um valor inexistente no caixa.
                    if (((c1 == 0) && (c2 == 0)) && ((c3 == 0) && (c6 > 0)) || ((c5 > 0) || (c4 > 0)))
                    {
                        printf("mil ");
                    }
                    if (((c6 > 0) || (c5 > 0) || (c4 > 0)) && ((c3 > 0) || (c2 > 0) || (c1 > 0)))
                    {
                        printf("e ");
                    }
                    // Centena
                    if (c3 > 0)
                    {
                        if ((c2 > 0) || (c1 > 0))
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cento e ");
                                break;
                            case 2:
                                printf("duzentos e ");
                                break;
                            case 3:
                                printf("trezentos e ");
                                break;
                            case 4:
                                printf("quatrocentos e ");
                                break;
                            case 5:
                                printf("quinhentos e ");
                                break;
                            case 6:
                                printf("seiscentos e ");
                                break;
                            case 7:
                                printf("setecentos e ");
                                break;
                            case 8:
                                printf("oitocentos e ");
                                break;
                            case 9:
                                printf("novecentos e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cem ");
                                break;
                            case 2:
                                printf("duzentas ");
                                break;
                            case 3:
                                printf("trezentas ");
                                break;
                            case 4:
                                printf("quatrocentas ");
                                break;
                            case 5:
                                printf("quinhentas ");
                                break;
                            case 6:
                                printf("seiscentas ");
                                break;
                            case 7:
                                printf("setecentas ");
                                break;
                            case 8:
                                printf("oitocentas ");
                                break;
                            case 9:
                                printf("novecentas ");
                                break;
                            }
                        }
                    }
                    // Dezena
                    if (c2 > 0)
                    {
                        if (c1 > 0)
                        {
                            switch (c2)
                            {
                            case 1:
                                if (c1 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c1 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c1 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c1 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c1 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c2)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Unidade
                    if (c1 > 0)
                    {
                        if (c2 == 1)
                        {
                            switch (c1)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c2 != 1)
                        {
                            switch (c1)
                            {
                            case 1:
                                printf("uma ");
                                break;
                            case 2:
                                printf("duas ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    if (nota_50 > 1) // Plural
                    {
                        printf("cedulas de cinquenta reais'.\n");
                    }
                    else if ((nota_50 == 1) || (nota_50 == 0)) // Singular
                    {
                        printf("cedula de cinquenta reais'.\n");
                    }

                    // Cédulas de 150 reais
                    if (nota_150 > 1) // Plural
                    {
                        printf("\n  Cedulas de 150 reais: %d cedulas, '", nota_150);
                    }
                    else if ((nota_150 == 0) || (nota_150 == 1)) // Singular
                    {
                        printf("\n  Cedulas de 150 reais: %d cedula, '", nota_150);
                    }

                    // Separação dos dígitos para informar o valor por extenso
                    c1 = c2 = c3 = c4 = c5 = c6 = 0;
                    c1 = (nota_150 % 10);          // Unidade
                    c2 = (nota_150 / 10) % 10;     // Dezena
                    c3 = (nota_150 / 100) % 10;    // Centena
                    c4 = (nota_150 / 1000) % 10;   // Milhar
                    c5 = (nota_150 / 10000) % 10;  // Dezena de milhar
                    c6 = (nota_150 / 100000) % 10; // Centena de milhar

                    if ((c6 == 0) && (c5 == 0) && (c4 == 0) && (c3 == 0) && (c2 == 0) && (c1 == 0))
                    {
                        printf("zero ");
                    }
                    // Centena de milhar
                    if (c6 > 0)
                    {
                        if ((c5 == 0) && (c4 == 0))
                        {
                            printf("cem ");
                        }
                        else
                        {
                            printf("cento e ");
                        }
                    }
                    // Dezena de milhar
                    if (c5 > 0)
                    { // Parte do milhar
                        if (c4 > 0)
                        {
                            switch (c5)
                            {
                            case 1:
                                if (c4 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c4 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c4 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c4 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c4 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                            }
                        }
                        else
                        {
                            switch (c5)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Milhar
                    if (c4 > 0)
                    {
                        if (c5 == 1)
                        {
                            switch (c4)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c5 != 1)
                        {
                            switch (c4)
                            {
                            case 1:
                                printf("um ");
                                break;
                            case 2:
                                printf("dois ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    // Para finalizar o milhar e caso o cliente queira sacar um valor inexistente no caixa.
                    if (((c1 == 0) && (c2 == 0)) && ((c3 == 0) && (c6 > 0)) || ((c5 > 0) || (c4 > 0)))
                    {
                        printf("mil ");
                    }
                    if (((c6 > 0) || (c5 > 0) || (c4 > 0)) && ((c3 > 0) || (c2 > 0) || (c1 > 0)))
                    {
                        printf("e ");
                    }
                    // Centena
                    if (c3 > 0)
                    {
                        if ((c2 > 0) || (c1 > 0))
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cento e ");
                                break;
                            case 2:
                                printf("duzentos e ");
                                break;
                            case 3:
                                printf("trezentos e ");
                                break;
                            case 4:
                                printf("quatrocentos e ");
                                break;
                            case 5:
                                printf("quinhentos e ");
                                break;
                            case 6:
                                printf("seiscentos e ");
                                break;
                            case 7:
                                printf("setecentos e ");
                                break;
                            case 8:
                                printf("oitocentos e ");
                                break;
                            case 9:
                                printf("novecentos e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cem ");
                                break;
                            case 2:
                                printf("duzentas ");
                                break;
                            case 3:
                                printf("trezentas ");
                                break;
                            case 4:
                                printf("quatrocentas ");
                                break;
                            case 5:
                                printf("quinhentas ");
                                break;
                            case 6:
                                printf("seiscentas ");
                                break;
                            case 7:
                                printf("setecentas ");
                                break;
                            case 8:
                                printf("oitocentas ");
                                break;
                            case 9:
                                printf("novecentas ");
                                break;
                            }
                        }
                    }
                    // Dezena
                    if (c2 > 0)
                    {
                        if (c1 > 0)
                        {
                            switch (c2)
                            {
                            case 1:
                                if (c1 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c1 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c1 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c1 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c1 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c2)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Unidade
                    if (c1 > 0)
                    {
                        if (c2 == 1)
                        {
                            switch (c1)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c2 != 1)
                        {
                            switch (c1)
                            {
                            case 1:
                                printf("uma ");
                                break;
                            case 2:
                                printf("duas ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    if (nota_150 > 1) // Plural
                    {
                        printf("cedulas de cento e cinquenta reais'.\n");
                    }
                    else if ((nota_150 == 1) || (nota_150 == 0)) // Singular
                    {
                        printf("cedula de cento e cinquenta reais'.\n");
                    }

                    // Cédulas de 500 reais
                    if (nota_500 > 1) // Plural
                    {
                        printf("\n  Cedulas de 500 reais: %d cedulas, '", nota_500);
                    }
                    else if ((nota_500 == 0) || (nota_500 == 1)) // Singular
                    {
                        printf("\n  Cedulas de 500 reais: %d cedula, '", nota_500);
                    }

                    // Separação dos dígitos para informar o valor por extenso
                    c1 = c2 = c3 = c4 = c5 = c6 = 0;
                    c1 = (nota_500 % 10);          // Unidade
                    c2 = (nota_500 / 10) % 10;     // Dezena
                    c3 = (nota_500 / 100) % 10;    // Centena
                    c4 = (nota_500 / 1000) % 10;   // Milhar
                    c5 = (nota_500 / 10000) % 10;  // Dezena de milhar
                    c6 = (nota_500 / 100000) % 10; // Centena de milhar

                    if ((c6 == 0) && (c5 == 0) && (c4 == 0) && (c3 == 0) && (c2 == 0) && (c1 == 0))
                    {
                        printf("zero ");
                    }
                    // Centena de milhar
                    if (c6 > 0)
                    {
                        if ((c5 == 0) && (c4 == 0))
                        {
                            printf("cem ");
                        }
                        else
                        {
                            printf("cento e ");
                        }
                    }
                    // Dezena de milhar
                    if (c5 > 0)
                    { // Parte do milhar
                        if (c4 > 0)
                        {
                            switch (c5)
                            {
                            case 1:
                                if (c4 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c4 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c4 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c4 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c4 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                            }
                        }
                        else
                        {
                            switch (c5)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Milhar
                    if (c4 > 0)
                    {
                        if (c5 == 1)
                        {
                            switch (c4)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c5 != 1)
                        {
                            switch (c4)
                            {
                            case 1:
                                printf("um ");
                                break;
                            case 2:
                                printf("dois ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    // Para finalizar o milhar e caso o cliente queira sacar um valor inexistente no caixa.
                    if (((c1 == 0) && (c2 == 0)) && ((c3 == 0) && (c6 > 0)) || ((c5 > 0) || (c4 > 0)))
                    {
                        printf("mil ");
                    }
                    if (((c6 > 0) || (c5 > 0) || (c4 > 0)) && ((c3 > 0) || (c2 > 0) || (c1 > 0)))
                    {
                        printf("e ");
                    }
                    // Centena
                    if (c3 > 0)
                    {
                        if ((c2 > 0) || (c1 > 0))
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cento e ");
                                break;
                            case 2:
                                printf("duzentos e ");
                                break;
                            case 3:
                                printf("trezentos e ");
                                break;
                            case 4:
                                printf("quatrocentos e ");
                                break;
                            case 5:
                                printf("quinhentos e ");
                                break;
                            case 6:
                                printf("seiscentos e ");
                                break;
                            case 7:
                                printf("setecentos e ");
                                break;
                            case 8:
                                printf("oitocentos e ");
                                break;
                            case 9:
                                printf("novecentos e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cem ");
                                break;
                            case 2:
                                printf("duzentas ");
                                break;
                            case 3:
                                printf("trezentas ");
                                break;
                            case 4:
                                printf("quatrocentas ");
                                break;
                            case 5:
                                printf("quinhentas ");
                                break;
                            case 6:
                                printf("seiscentas ");
                                break;
                            case 7:
                                printf("setecentas ");
                                break;
                            case 8:
                                printf("oitocentas ");
                                break;
                            case 9:
                                printf("novecentas ");
                                break;
                            }
                        }
                    }
                    // Dezena
                    if (c2 > 0)
                    {
                        if (c1 > 0)
                        {
                            switch (c2)
                            {
                            case 1:
                                if (c1 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c1 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c1 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c1 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c1 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c2)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Unidade
                    if (c1 > 0)
                    {
                        if (c2 == 1)
                        {
                            switch (c1)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c2 != 1)
                        {
                            switch (c1)
                            {
                            case 1:
                                printf("uma ");
                                break;
                            case 2:
                                printf("duas ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    if (nota_500 > 1) // Plural
                    {
                        printf("cedulas de quinhentos reais'.\n");
                    }
                    else if ((nota_500 == 1) || (nota_500 == 0)) // Singular
                    {
                        printf("cedula de quinhentos reais'.\n");
                    }

                    // Total de cédulas
                    printf("\nTOTAL DE CEDULAS:\n");
                    if (total_cedulas > 1) // Plural
                    {
                        printf("\n  Total de cedulas existentes no caixa: %d cedulas, '", total_cedulas);
                    }
                    else if ((total_cedulas == 0) || (total_cedulas == 1)) // Singular
                    {
                        printf("\n  Total de cedulas existentes no caixa: %d cedula, '", total_cedulas);
                    }

                    // Separação dos dígitos para informar o valor por extenso
                    c1 = c2 = c3 = c4 = c5 = c6 = 0;
                    c1 = (total_cedulas % 10);          // Unidade
                    c2 = (total_cedulas / 10) % 10;     // Dezena
                    c3 = (total_cedulas / 100) % 10;    // Centena
                    c4 = (total_cedulas / 1000) % 10;   // Milhar
                    c5 = (total_cedulas / 10000) % 10;  // Dezena de milhar
                    c6 = (total_cedulas / 100000) % 10; // Centena de milhar

                    if ((c6 == 0) && (c5 == 0) && (c4 == 0) && (c3 == 0) && (c2 == 0) && (c1 == 0))
                    {
                        printf("zero ");
                    }
                    // Centena de milhar
                    if (c6 > 0)
                    {
                        if ((c5 == 0) && (c4 == 0))
                        {
                            printf("cem ");
                        }
                        else
                        {
                            printf("cento e ");
                        }
                    }
                    // Dezena de milhar
                    if (c5 > 0)
                    { // Parte do milhar
                        if (c4 > 0)
                        {
                            switch (c5)
                            {
                            case 1:
                                if (c4 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c4 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c4 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c4 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c4 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                            }
                        }
                        else
                        {
                            switch (c5)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Milhar
                    if (c4 > 0)
                    {
                        if (c5 == 1)
                        {
                            switch (c4)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c5 != 1)
                        {
                            switch (c4)
                            {
                            case 1:
                                printf("um ");
                                break;
                            case 2:
                                printf("dois ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    // Para finalizar o milhar e caso o cliente queira sacar um valor inexistente no caixa.
                    if (((c1 == 0) && (c2 == 0)) && ((c3 == 0) && (c6 > 0)) || ((c5 > 0) || (c4 > 0)))
                    {
                        printf("mil ");
                    }
                    if (((c6 > 0) || (c5 > 0) || (c4 > 0)) && ((c3 > 0) || (c2 > 0) || (c1 > 0)))
                    {
                        printf("e ");
                    }
                    // Centena
                    if (c3 > 0)
                    {
                        if ((c2 > 0) || (c1 > 0))
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cento e ");
                                break;
                            case 2:
                                printf("duzentos e ");
                                break;
                            case 3:
                                printf("trezentos e ");
                                break;
                            case 4:
                                printf("quatrocentos e ");
                                break;
                            case 5:
                                printf("quinhentos e ");
                                break;
                            case 6:
                                printf("seiscentos e ");
                                break;
                            case 7:
                                printf("setecentos e ");
                                break;
                            case 8:
                                printf("oitocentos e ");
                                break;
                            case 9:
                                printf("novecentos e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c3)
                            {
                            case 1:
                                printf("cem ");
                                break;
                            case 2:
                                printf("duzentas ");
                                break;
                            case 3:
                                printf("trezentas ");
                                break;
                            case 4:
                                printf("quatrocentas ");
                                break;
                            case 5:
                                printf("quinhentas ");
                                break;
                            case 6:
                                printf("seiscentas ");
                                break;
                            case 7:
                                printf("setecentas ");
                                break;
                            case 8:
                                printf("oitocentas ");
                                break;
                            case 9:
                                printf("novecentas ");
                                break;
                            }
                        }
                    }
                    // Dezena
                    if (c2 > 0)
                    {
                        if (c1 > 0)
                        {
                            switch (c2)
                            {
                            case 1:
                                if (c1 == 1)
                                {
                                    printf("onze ");
                                }
                                else if (c1 == 2)
                                {
                                    printf("doze ");
                                }
                                else if (c1 == 3)
                                {
                                    printf("treze ");
                                }
                                else if (c1 == 4)
                                {
                                    printf("quatorze ");
                                }
                                else if (c1 == 5)
                                {
                                    printf("quinze ");
                                }
                                else
                                {
                                    printf("dez");
                                }
                                break;
                            case 2:
                                printf("vinte e ");
                                break;
                            case 3:
                                printf("trinta e ");
                                break;
                            case 4:
                                printf("quarenta e ");
                                break;
                            case 5:
                                printf("cinquenta e ");
                                break;
                            case 6:
                                printf("sessenta e ");
                                break;
                            case 7:
                                printf("setenta e ");
                                break;
                            case 8:
                                printf("oitenta e ");
                                break;
                            case 9:
                                printf("noventa e ");
                                break;
                            }
                        }
                        else
                        {
                            switch (c2)
                            {
                            case 1:
                                printf("dez ");
                                break;
                            case 2:
                                printf("vinte ");
                                break;
                            case 3:
                                printf("trinta ");
                                break;
                            case 4:
                                printf("quarenta ");
                                break;
                            case 5:
                                printf("cinquenta ");
                                break;
                            case 6:
                                printf("sessenta ");
                                break;
                            case 7:
                                printf("setenta ");
                                break;
                            case 8:
                                printf("oitenta ");
                                break;
                            case 9:
                                printf("noventa ");
                                break;
                            }
                        }
                    }
                    // Unidade
                    if (c1 > 0)
                    {
                        if (c2 == 1)
                        {
                            switch (c1)
                            {
                            case 6:
                                printf("esseis ");
                                break;
                            case 7:
                                printf("essete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("enove ");
                                break;
                            }
                        }
                        else if (c2 != 1)
                        {
                            switch (c1)
                            {
                            case 1:
                                printf("uma ");
                                break;
                            case 2:
                                printf("duas ");
                                break;
                            case 3:
                                printf("tres ");
                                break;
                            case 4:
                                printf("quatro ");
                                break;
                            case 5:
                                printf("cinco ");
                                break;
                            case 6:
                                printf("seis ");
                                break;
                            case 7:
                                printf("sete ");
                                break;
                            case 8:
                                printf("oito ");
                                break;
                            case 9:
                                printf("nove ");
                                break;
                            }
                        }
                    }
                    if (total_cedulas > 1) // Plural
                    {
                        printf("cedulas'.");
                    }
                    else if ((total_cedulas == 1) || (total_cedulas == 0)) // Singular
                    {
                        printf("cedula'.");
                    }
                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                    system("pause");
                    opc_ger = -1; // Retorna ao menu do gerente
                    break;
                case 4: // Menu de abastecimento do caixa
                    do
                    {
                        system("cls");
                        printf("\n--Abastecimento do caixa eletronico--\n\n");
                        printf("Digite:\n");
                        printf("\n500 - Cedulas de 500");
                        printf("\n150 - Cedulas de 150");
                        printf("\n50 - Cedulas de 50");
                        printf("\n20 - Cedulas de 20");
                        printf("\n10 - Cedulas de 10");
                        printf("\n5 - Cedulas de 5");
                        printf("\n2 - Cedulas de 2");
                        printf("\n1 - Cedulas de 1");
                        printf("\n0 - Voltar ao menu gerente\n");
                        printf("\nInforme a opcao desejada: ");
                        scanf("%d", &opc_abs);
                        cedulas_abs = verifica_saque = 0;

                        switch (opc_abs) // Switch da opção do menu de abastecimento
                        {
                        case 0:
                            printf("\nOperacao finalizada com sucesso!\n\n");
                            system("pause");
                            opc_menu = 1; // Retorna ao menu do gerente
                            break;
                        case 1:                  // Abastecimento das cédulas de 1
                            if (nota_1 == 12800) // Caso o caixa já tenha a quantidade correta de cédulas
                            {
                                system("cls");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                printf("\nO caixa ja esta abastecido!\n");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                system("pause");
                                opc_menu = -1; // Retorna ao menu do abastecimento
                                break;
                            }
                            else if (nota_1 < 12800)
                            {
                                system("cls");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                printf("\nOpcao escolhida: Abastecer cedulas de 1 real.\n");
                                printf("\nQuantidade de cedulas:");
                                scanf("%d", &cedulas_abs);
                                if (cedulas_abs <= 0)
                                {
                                    do
                                    {
                                        system("cls");
                                        printf("\nQuantidade de cedulas invalida!\n\n");
                                        system("pause");
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nOpcao escolhida: Abastecer cedulas de 1 real.\n");
                                        printf("\nInforme novamente a quantidade de cedulas: ");
                                        scanf("%d", &cedulas_abs);
                                    } while (cedulas_abs <= 0);
                                }
                                nota_1 += cedulas_abs;
                                if (nota_1 > 12800)
                                {
                                    nota_1 = nota_1 - cedulas_abs;
                                    verifica_abs = 12800 - nota_1;
                                    if (verifica_abs == 1) // Cédulas em singular
                                    {
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nQuantidade maxima de cedulas ultrapassada!");
                                        printf("\nTente novamente informando uma quantidade de %d cedula.\n", verifica_abs);
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        system("pause");
                                        opc_menu = -1; // Retorna ao menu do abastecimento
                                        break;
                                    }
                                    else // Cédulas em plural
                                    {
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nQuantidade maxima de cedulas ultrapassada!");
                                        printf("\nTente novamente informando uma quantidade dentro de %d cedulas.\n", verifica_abs);
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        system("pause");
                                        opc_menu = -1; // Retorna ao menu do abastecimento
                                        break;
                                    }
                                }
                                total_existente += (1 * cedulas_abs);
                                total_cedulas += cedulas_abs;
                                if (cedulas_abs == 1) // Cédulas em singular
                                {
                                    printf("\nCaixa abastecido com %d cedula.", cedulas_abs);
                                    printf("\nQuantidade de cedulas de R$ 1,00: %d cedulas.\n", nota_1);
                                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                    system("pause");
                                    opc_menu = -1; // Retorna ao menu do abastecimento
                                    break;
                                }
                                else // Cédulas em plural
                                {
                                    printf("\nCaixa abastecido com %d cedulas.", cedulas_abs);
                                    printf("\nQuantidade de cedulas de R$ 1,00: %d cedulas.\n", nota_1);
                                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                    system("pause");
                                    opc_menu = -1; // Retorna ao menu do abastecimento
                                    break;
                                }
                            }
                        case 2:                 // Abastecimento das cédulas de 2
                            if (nota_2 == 6400) // Caso o caixa já tenha a quantidade correta de cédulas
                            {
                                system("cls");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                printf("\nO caixa ja esta abastecido!\n");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                system("pause");
                                opc_menu = -1; // Retorna ao menu do abastecimento
                                break;
                            }
                            else if (nota_2 < 6400)
                            {
                                system("cls");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                printf("\nOpcao escolhida: Abastecer cedulas de 2 reais.\n");
                                printf("\nQuantidade de cedulas:");
                                scanf("%d", &cedulas_abs);
                                if (cedulas_abs <= 0)
                                {
                                    do
                                    {
                                        system("cls");
                                        printf("\nQuantidade de cedulas invalida!\n\n");
                                        system("pause");
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nOpcao escolhida: Abastecer cedulas de 2 reais.\n");
                                        printf("\nInforme novamente a quantidade de cedulas: ");
                                        scanf("%d", &cedulas_abs);
                                    } while (cedulas_abs <= 0);
                                }
                                nota_2 += cedulas_abs;
                                if (nota_2 > 6400)
                                {
                                    nota_2 = nota_2 - cedulas_abs;
                                    verifica_abs = 6400 - nota_2;
                                    if (verifica_abs == 1) // Cédulas em singular
                                    {
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nQuantidade maxima de cedulas ultrapassada!");
                                        printf("\nTente novamente informando uma quantidade de %d cedula.\n", verifica_abs);
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        system("pause");
                                        opc_menu = -1; // Retorna ao menu do abastecimento
                                        break;
                                    }
                                    else // Cédulas em plural
                                    {
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nQuantidade maxima de cedulas ultrapassada!");
                                        printf("\nTente novamente informando uma quantidade dentro de %d cedulas.\n", verifica_abs);
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        system("pause");
                                        opc_menu = -1; // Retorna ao menu do abastecimento
                                        break;
                                    }
                                }
                                total_existente += (2 * cedulas_abs);
                                total_cedulas += cedulas_abs;
                                if (cedulas_abs == 1) // Cédulas em singular
                                {
                                    printf("\nCaixa abastecido com %d cedula.", cedulas_abs);
                                    printf("\nQuantidade de cedulas de R$ 2,00: %d cedula.\n", nota_2);
                                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                    system("pause");
                                    opc_menu = -1; // Retorna ao menu do abastecimento
                                    break;
                                }
                                else // Cédulas em plural
                                {
                                    printf("\nCaixa abastecido com %d cedulas.", cedulas_abs);
                                    printf("\nQuantidade de cedulas de R$ 2,00: %d cedulas.\n", nota_2);
                                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                    system("pause");
                                    opc_menu = -1; // Retorna ao menu do abastecimento
                                    break;
                                }
                            }
                        case 5:                 // Abastecimento das cédulas de 5
                            if (nota_5 == 3200) // Caso o caixa já tenha a quantidade correta de cédulas
                            {
                                system("cls");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                printf("\nO caixa ja esta abastecido!\n");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                system("pause");
                                opc_menu = -1; // Retorna ao menu do abastecimento
                                break;
                            }
                            else if (nota_5 < 3200)
                            {
                                system("cls");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                printf("\nOpcao escolhida: Abastecer cedulas de 5 reais.\n");
                                printf("\nQuantidade de cedulas:");
                                scanf("%d", &cedulas_abs);
                                if (cedulas_abs <= 0)
                                {
                                    do
                                    {
                                        system("cls");
                                        printf("\nQuantidade de cedulas invalida!\n\n");
                                        system("pause");
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nOpcao escolhida: Abastecer cedulas de 5 reais.\n");
                                        printf("\nInforme novamente a quantidade de cedulas: ");
                                        scanf("%d", &cedulas_abs);
                                    } while (cedulas_abs <= 0);
                                }
                                nota_5 += cedulas_abs;
                                if (nota_5 > 3200)
                                {
                                    nota_5 = nota_5 - cedulas_abs;
                                    verifica_abs = 3200 - nota_5;
                                    if (verifica_abs == 1) // Cédulas em singular
                                    {
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nQuantidade maxima de cedulas ultrapassada!");
                                        printf("\nTente novamente informando uma quantidade de %d cedula.\n", verifica_abs);
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        system("pause");
                                        opc_menu = -1; // Retorna ao menu do abastecimento
                                        break;
                                    }
                                    else // Cédulas em plural
                                    {
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nQuantidade maxima de cedulas ultrapassada!");
                                        printf("\nTente novamente informando uma quantidade dentro de %d cedulas.\n", verifica_abs);
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        system("pause");
                                        opc_menu = -1; // Retorna ao menu do abastecimento
                                        break;
                                    }
                                }
                                total_existente += (5 * cedulas_abs);
                                total_cedulas += cedulas_abs;
                                if (cedulas_abs == 1) // Cédulas em singular
                                {
                                    printf("\nCaixa abastecido com %d cedula.", cedulas_abs);
                                    printf("\nQuantidade de cedulas de R$ 5,00: %d cedulas.\n", nota_5);
                                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                    system("pause");
                                    opc_menu = -1; // Retorna ao menu do abastecimento
                                    break;
                                }
                                else // Cédulas em plural
                                {
                                    printf("\nCaixa abastecido com %d cedulas.", cedulas_abs);
                                    printf("\nQuantidade de cedulas de R$ 5,00: %d cedulas.\n", nota_5);
                                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                    system("pause");
                                    opc_menu = -1; // Retorna ao menu do abastecimento
                                    break;
                                }
                            }
                        case 10:                 // Abastecimento das cédulas de 10
                            if (nota_10 == 1600) // Caso o caixa já tenha a quantidade correta de cédulas
                            {
                                system("cls");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                printf("\nO caixa ja esta abastecido!\n");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                system("pause");
                                opc_menu = -1; // Retorna ao menu do abastecimento
                                break;
                            }
                            else if (nota_10 < 1600)
                            {
                                system("cls");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                printf("\nOpcao escolhida: Abastecer cedulas de 10 reais.\n");
                                printf("\nQuantidade de cedulas:");
                                scanf("%d", &cedulas_abs);
                                if (cedulas_abs <= 0)
                                {
                                    do
                                    {
                                        system("cls");
                                        printf("\nQuantidade de cedulas invalida!\n\n");
                                        system("pause");
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nOpcao escolhida: Abastecer cedulas de 10 reais.\n");
                                        printf("\nInforme novamente a quantidade de cedulas: ");
                                        scanf("%d", &cedulas_abs);
                                    } while (cedulas_abs <= 0);
                                }
                                nota_10 += cedulas_abs;
                                if (nota_10 > 1600)
                                {
                                    nota_10 = nota_10 - cedulas_abs;
                                    verifica_abs = 1600 - nota_10;
                                    if (verifica_abs == 1) // Cédulas em singular
                                    {
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nQuantidade maxima de cedulas ultrapassada!");
                                        printf("\nTente novamente informando uma quantidade de %d cedula.\n", verifica_abs);
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        system("pause");
                                        opc_menu = -1; // Retorna ao menu do abastecimento
                                        break;
                                    }
                                    else // Cédulas em plural
                                    {
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nQuantidade maxima de cedulas ultrapassada!");
                                        printf("\nTente novamente informando uma quantidade dentro de %d cedulas.\n", verifica_abs);
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        system("pause");
                                        opc_menu = -1; // Retorna ao menu do abastecimento
                                        break;
                                    }
                                }
                                total_existente += (10 * cedulas_abs);
                                total_cedulas += cedulas_abs;
                                if (cedulas_abs == 1) // Cédulas em singular
                                {
                                    printf("\nCaixa abastecido com %d cedula.", cedulas_abs);
                                    printf("\nQuantidade de cedulas de R$ 10,00: %d cedulas.\n", nota_10);
                                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                    system("pause");
                                    opc_menu = -1; // Retorna ao menu do abastecimento
                                    break;
                                }
                                else // Cédulas em plural
                                {
                                    printf("\nCaixa abastecido com %d cedulas.", cedulas_abs);
                                    printf("\nQuantidade de cedulas de R$ 10,00: %d cedulas.\n", nota_10);
                                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                    system("pause");
                                    opc_menu = -1; // Retorna ao menu do abastecimento
                                    break;
                                }
                            }
                        case 20:                // Abastecimento das cédulas de 20
                            if (nota_20 == 800) // Caso o caixa já tenha a quantidade correta de cédulas
                            {
                                system("cls");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                printf("\nO caixa ja esta abastecido!\n");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                system("pause");
                                opc_menu = -1; // Retorna ao menu do abastecimento
                                break;
                            }
                            else if (nota_20 < 800)
                            {
                                system("cls");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                printf("\nOpcao escolhida: Abastecer cedulas de 20 reais.\n");
                                printf("\nQuantidade de cedulas:");
                                scanf("%d", &cedulas_abs);
                                if (cedulas_abs <= 0)
                                {
                                    do
                                    {
                                        system("cls");
                                        printf("\nQuantidade de cedulas invalida!\n\n");
                                        system("pause");
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nOpcao escolhida: Abastecer cedulas de 20 reais.\n");
                                        printf("\nInforme novamente a quantidade de cedulas: ");
                                        scanf("%d", &cedulas_abs);
                                    } while (cedulas_abs <= 0);
                                }
                                nota_20 += cedulas_abs;
                                if (nota_20 > 800)
                                {
                                    nota_20 = nota_20 - cedulas_abs;
                                    verifica_abs = 800 - nota_20;
                                    if (verifica_abs == 1) // Cédulas em singular
                                    {
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nQuantidade maxima de cedulas ultrapassada!");
                                        printf("\nTente novamente informando uma quantidade de %d cedula.\n", verifica_abs);
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        system("pause");
                                        opc_menu = -1; // Retorna ao menu do abastecimento
                                        break;
                                    }
                                    else // Cédulas em plural
                                    {
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nQuantidade maxima de cedulas ultrapassada!");
                                        printf("\nTente novamente informando uma quantidade dentro de %d cedulas.\n", verifica_abs);
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        system("pause");
                                        opc_menu = -1; // Retorna ao menu do abastecimento
                                        break;
                                    }
                                }
                                total_existente += (20 * cedulas_abs);
                                total_cedulas += cedulas_abs;
                                if (cedulas_abs == 1) // Cédulas em singular
                                {
                                    printf("\nCaixa abastecido com %d cedula.", cedulas_abs);
                                    printf("\nQuantidade de cedulas de R$ 20,00: %d cedulas.\n", nota_20);
                                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                    system("pause");
                                    opc_menu = -1; // Retorna ao menu do abastecimento
                                    break;
                                }
                                else // Cédulas em plural
                                {
                                    printf("\nCaixa abastecido com %d cedulas.", cedulas_abs);
                                    printf("\nQuantidade de cedulas de R$ 20,00: %d cedulas.\n", nota_20);
                                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                    system("pause");
                                    opc_menu = -1; // Retorna ao menu do abastecimento
                                    break;
                                }
                            }
                        case 50:                // Abastecimento das cédulas de 50
                            if (nota_50 == 400) // Caso o caixa já tenha a quantidade correta de cédulas
                            {
                                system("cls");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                printf("\nO caixa ja esta abastecido!\n");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                system("pause");
                                opc_menu = -1; // Retorna ao menu do abastecimento
                                break;
                            }
                            else if (nota_50 < 400)
                            {
                                system("cls");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                printf("\nOpcao escolhida: Abastecer cedulas de 50 reais.\n");
                                printf("\nQuantidade de cedulas:");
                                scanf("%d", &cedulas_abs);
                                if (cedulas_abs <= 0)
                                {
                                    do
                                    {
                                        system("cls");
                                        printf("\nQuantidade de cedulas invalida!\n\n");
                                        system("pause");
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nOpcao escolhida: Abastecer cedulas de 50 reais.\n");
                                        printf("\nInforme novamente a quantidade de cedulas: ");
                                        scanf("%d", &cedulas_abs);
                                    } while (cedulas_abs <= 0);
                                }
                                nota_50 += cedulas_abs;
                                if (nota_50 > 400)
                                {
                                    nota_50 = nota_50 - cedulas_abs;
                                    verifica_abs = 400 - nota_50;
                                    if (verifica_abs == 1) // Cédulas em singular
                                    {
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nQuantidade maxima de cedulas ultrapassada!");
                                        printf("\nTente novamente informando uma quantidade de %d cedula.\n", verifica_abs);
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        system("pause");
                                        opc_menu = -1; // Retorna ao menu do abastecimento
                                        break;
                                    }
                                    else // Cédulas em plural
                                    {
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nQuantidade maxima de cedulas ultrapassada!");
                                        printf("\nTente novamente informando uma quantidade dentro de %d cedulas.\n", verifica_abs);
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        system("pause");
                                        opc_menu = -1; // Retorna ao menu do abastecimento
                                        break;
                                    }
                                }
                                total_existente += (50 * cedulas_abs);
                                total_cedulas += cedulas_abs;
                                if (cedulas_abs == 1) // Cédulas em singular
                                {
                                    printf("\nCaixa abastecido com %d cedula.", cedulas_abs);
                                    printf("\nQuantidade de cedulas de R$ 50,00: %d cedulas.\n", nota_50);
                                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                    system("pause");
                                    opc_menu = -1; // Retorna ao menu do abastecimento
                                    break;
                                }
                                else // Cédulas em plural
                                {
                                    printf("\nCaixa abastecido com %d cedulas.", cedulas_abs);
                                    printf("\nQuantidade de cedulas de R$ 50,00: %d cedulas.\n", nota_50);
                                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                    system("pause");
                                    opc_menu = -1; // Retorna ao menu do abastecimento
                                    break;
                                }
                            }
                        case 150:                // Abastecimento das cédulas de 150
                            if (nota_150 == 200) // Caso o caixa já tenha a quantidade correta de cédulas
                            {
                                system("cls");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                printf("\nO caixa ja esta abastecido!\n");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                system("pause");
                                opc_menu = -1; // Retorna ao menu do abastecimento
                                break;
                            }
                            else if (nota_150 < 200)
                            {
                                system("cls");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                printf("\nOpcao escolhida: Abastecer cedulas de 150 reais.\n");
                                printf("\nQuantidade de cedulas:");
                                scanf("%d", &cedulas_abs);
                                if (cedulas_abs <= 0)
                                {
                                    do
                                    {
                                        system("cls");
                                        printf("\nQuantidade de cedulas invalida!\n\n");
                                        system("pause");
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nOpcao escolhida: Abastecer cedulas de 150 reais.\n");
                                        printf("\nInforme novamente a quantidade de cedulas: ");
                                        scanf("%d", &cedulas_abs);
                                    } while (cedulas_abs <= 0);
                                }
                                nota_150 += cedulas_abs;
                                if (nota_150 > 200)
                                {
                                    nota_150 = nota_150 - cedulas_abs;
                                    verifica_abs = 200 - nota_150;
                                    if (verifica_abs == 1) // Cédulas em singular
                                    {
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nQuantidade maxima de cedulas ultrapassada!");
                                        printf("\nTente novamente informando uma quantidade de %d cedula.\n", verifica_abs);
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        system("pause");
                                        opc_menu = -1; // Retorna ao menu do abastecimento
                                        break;
                                    }
                                    else // Cédulas em plural
                                    {
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nQuantidade maxima de cedulas ultrapassada!");
                                        printf("\nTente novamente informando uma quantidade dentro de %d cedulas.\n", verifica_abs);
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        system("pause");
                                        opc_menu = -1; // Retorna ao menu do abastecimento
                                        break;
                                    }
                                }
                                total_existente += (150 * cedulas_abs);
                                total_cedulas += cedulas_abs;
                                if (cedulas_abs == 1) // Cédulas em singular
                                {
                                    printf("\nCaixa abastecido com %d cedula.", cedulas_abs);
                                    printf("\nQuantidade de cedulas de R$ 150,00: %d cedulas.\n", nota_150);
                                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                    system("pause");
                                    opc_menu = -1; // Retorna ao menu do abastecimento
                                    break;
                                }
                                else // Cédulas em plural
                                {
                                    printf("\nCaixa abastecido com %d cedulas.", cedulas_abs);
                                    printf("\nQuantidade de cedulas de R$ 150,00: %d cedulas.\n", nota_150);
                                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                    system("pause");
                                    opc_menu = -1; // Retorna ao menu do abastecimento
                                    break;
                                }
                            }
                        case 500:                // Abastecimento das cédulas de 500
                            if (nota_500 == 100) // Caso o caixa já tenha a quantidade correta de cédulas
                            {
                                system("cls");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                printf("\nO caixa ja esta abastecido!\n");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                system("pause");
                                opc_menu = -1; // Retorna ao menu do abastecimento
                                break;
                            }
                            else if (nota_500 < 100)
                            {
                                system("cls");
                                printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                printf("\nOpcao escolhida: Abastecer cedulas de 500 reais.\n");
                                printf("\nQuantidade de cedulas:");
                                scanf("%d", &cedulas_abs);
                                if (cedulas_abs <= 0)
                                {
                                    do
                                    {
                                        system("cls");
                                        printf("\nQuantidade de cedulas invalida!\n\n");
                                        system("pause");
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nOpcao escolhida: Abastecer cedulas de 500 reais.\n");
                                        printf("\nInforme novamente a quantidade de cedulas: ");
                                        scanf("%d", &cedulas_abs);
                                    } while (cedulas_abs <= 0);
                                }
                                nota_500 += cedulas_abs;
                                if (nota_500 > 100)
                                {
                                    nota_500 = nota_500 - cedulas_abs;
                                    verifica_abs = 100 - nota_500;
                                    if (verifica_abs == 1) // Cédulas em singular
                                    {
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nQuantidade maxima de cedulas ultrapassada!");
                                        printf("\nTente novamente informando uma quantidade de %d cedula.\n", verifica_abs);
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        system("pause");
                                        opc_menu = -1; // Retorna ao menu do abastecimento
                                        break;
                                    }
                                    else // Cédulas em plural
                                    {
                                        system("cls");
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        printf("\nQuantidade maxima de cedulas ultrapassada!");
                                        printf("\nTente novamente informando uma quantidade dentro de %d cedulas.\n", verifica_abs);
                                        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                        system("pause");
                                        opc_menu = -1; // Retorna ao menu do abastecimento
                                        break;
                                    }
                                }
                                total_existente += (500 * cedulas_abs);
                                total_cedulas += cedulas_abs;
                                if (cedulas_abs == 1) // Cédulas em singular
                                {
                                    printf("\nCaixa abastecido com %d cedula.", cedulas_abs);
                                    printf("\nQuantidade de cedulas de R$ 500,00: %d cedulas.\n", nota_500);
                                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                    system("pause");
                                    opc_menu = -1; // Retorna ao menu do abastecimento
                                    break;
                                }
                                else // Cédulas em plural
                                {
                                    printf("\nCaixa abastecido com %d cedulas.", cedulas_abs);
                                    printf("\nQuantidade de cedulas de R$ 500,00: %d cedulas.\n", nota_500);
                                    printf("\n\n----------------------------------------------------------------------------------------------------------------------------------\n\n");
                                    system("pause");
                                    opc_menu = -1; // Retorna ao menu do abastecimento
                                    break;
                                }
                            }
                        default:
                            printf("\nOpcao invalida!\n\n");
                            system("pause");
                            system("cls");
                            opc_menu = -1; // Retorna ao menu do abastecimento
                            break;
                        }
                    } while (opc_menu < 1); // Fim do laço Do While do menu de abastecimento
                    opc_ger = -1;           // Retorna ao menu do gerente
                }
                if (opc_ger == 5) // Sair do menu do gerente
                {
                    printf("\nOperacao finalizada com sucesso!\n\n");
                    system("pause");
                    opc = -1; // Retorna ao menu principal
                }
            } while (opc_ger < 1 || opc_ger > 5); // Fim do laço Do While do menu do gerente.
        }
        if (opc == 3) // Finalizar o programa
        {
            printf("\nOperacao finalizada com sucesso!\n\n");
            system("pause");
        }
    } while (opc < 1 || opc > 3); // Fim do laço Do While do início.
    return 0;
}