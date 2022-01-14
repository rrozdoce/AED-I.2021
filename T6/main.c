/*
Trabalho 6 AEDI-I

Alunos:

Henrique Gettner de Oliveira RGM: 45767
Henrique Apolinário Iwamizu Tada RGM: 43927
Leandro Madeira de Oliveira RGM: 45280
Guilherme Garcia Gloor RGM: 45535
Felipe Echeverria Vilhalva RGM: 45611
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERRO_ENCONTRAR_ARQUIVO(arqv) printf("\nO ARQUIVO '%s' NAO FOI ENCONTRADO!\n", arqv)

#define SUGESTAO_ERRO(arqv) printf("VERIFIQUE SE O ARQUIVO '%s' ESTA NA MESMA PASTA OU LOCAL QUE ESTA O ARQUIVO '.c'.\n\n", arqv);

#define INFORMA_ERRO(arqv, complemento) printf("O ARQUIVO '%s' AINDA NAO %s!\n\n", arqv, complemento)

#define MAX_LINHA 800
#define MAX_CHAR_LINHA 200
#define MAX_CHAR_PALAVRA 100

char *fileCode = "readme.code.txt";
char *fileDecifra = "readme.decifra.txt";
char *fileNlines = "readme.nlines.txt";

// Limpez do buffer
void flush_in()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}

// Mostrar as linhas do texto armazenadas na matriz
void mostraLinhas(char matrizLinhas[MAX_LINHA][MAX_CHAR_LINHA], int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
        printf("%s", matrizLinhas[i]);
}

// Zerar os indices do vetor
void zeraIndiceVetor(char vetor[], int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
        vetor[i] = 0;
}

// Zerar os indices da matriz
void zeraIndiceMatriz(char matriz[MAX_LINHA][MAX_CHAR_LINHA])
{
    int i;
    for (i = 0; i < MAX_LINHA; i++)
        matriz[i][0] = '\0';
}

// Decifra o arquivo readme.code.txt e armazena no arquivo readme.decifra.txt
void decifraArquivo(char *caminhoArquivoCodificado)
{
    FILE *arquivoCodificado, *arquivoDecifrado;

    int digito = 0, transformaInt;
    char caractere, numeroCode[4], transformaAscii;

    arquivoCodificado = fopen(caminhoArquivoCodificado, "r+");
    arquivoDecifrado = fopen(fileDecifra, "w");
    numeroCode[3] = '\0';

    zeraIndiceVetor(numeroCode, 4);

    do
    {
        fread(&caractere, 1, 1, arquivoCodificado);

        if (caractere != '[' && caractere != ']')
        {
            numeroCode[digito] = caractere;
            digito++;
        }
        else if (caractere == ']')
        {
            transformaInt = atoi(numeroCode);      // Transforma para um inteiro
            transformaAscii = (char)transformaInt; // Converte em caracter na tabela Ascii

            fprintf(arquivoDecifrado, "%c", transformaAscii); // Adciona o caracter no arquivo readme.decifra.txt

            zeraIndiceVetor(numeroCode, 4);
            digito = 0;
        }

    } while (!feof(arquivoCodificado)); // Enquanto não for o fim do arquivo

    printf("\nARQUIVO DECIFRADO!\n\n");

    fclose(arquivoCodificado);
    fclose(arquivoDecifrado);
}

// Grava as linhas do texto decifrado e armazena no arquivo readme.nlines.txt
void gravaLinhaArquivo()
{
    FILE *arquivoDecifrado, *arquivoNlinhas;

    int contadorLinha = 1;
    char linha[MAX_CHAR_LINHA], linhaEnumerada[MAX_CHAR_LINHA];

    arquivoDecifrado = fopen(fileDecifra, "r+");

    if (arquivoDecifrado == NULL)
    {
        ERRO_ENCONTRAR_ARQUIVO(fileDecifra);
        INFORMA_ERRO(fileCode, "FOI DECIFRADO");
    }
    else
    {
        arquivoNlinhas = fopen(fileNlines, "w");

        do
        {
            fgets(linha, MAX_CHAR_LINHA, arquivoDecifrado);
            sprintf(linhaEnumerada, "[linha:%d]%s", contadorLinha, linha);
            fprintf(arquivoNlinhas, "%s", linhaEnumerada);

            contadorLinha++;
        } while (!feof(arquivoDecifrado));

        printf("\nLINHAS ENUMERADAS!\n\n");

        fclose(arquivoNlinhas);
    }
    fclose(arquivoDecifrado);
}

// Informa a quantidade de linhas do arquivo readme.decifra.txt
void quantidadeLinhaArquivo()
{
    FILE *arquivoDecifrado;

    int contadorLinhas = 0;
    char linha[MAX_CHAR_LINHA];

    arquivoDecifrado = fopen(fileDecifra, "r");

    if (arquivoDecifrado == NULL)
    {
        ERRO_ENCONTRAR_ARQUIVO(fileDecifra);
        INFORMA_ERRO(fileCode, "FOI DECIFRADO");
    }
    else
    {
        do
        {
            if (fgets(linha, MAX_CHAR_LINHA, arquivoDecifrado))
                contadorLinhas++;

        } while (!feof(arquivoDecifrado));

        printf("\nO ARQUIVO %s TEM (%d) LINHAS.\n\n", fileDecifra, contadorLinhas);
    }
    fclose(arquivoDecifrado);
}

// Informa a maior linha do arquivo readme.decifra.txt
void maiorLinha()
{
    FILE *arquivoDecifrado;

    int maiorLinha = 0, quantidadeCaracteres = 0, verificaTamanho = 0, identificacaoLinha = 0;
    char caractere;

    arquivoDecifrado = fopen(fileDecifra, "r+");

    if (arquivoDecifrado == NULL)
    {
        ERRO_ENCONTRAR_ARQUIVO(fileDecifra);
        INFORMA_ERRO(fileCode, "FOI DECIFRADO");
    }
    else
    {
        while (fscanf(arquivoDecifrado, "%c", &caractere) != EOF)
        {
            verificaTamanho++;

            if (caractere == '\n')
            {
                identificacaoLinha++;

                if (verificaTamanho > quantidadeCaracteres)
                {
                    quantidadeCaracteres = verificaTamanho;
                    maiorLinha = identificacaoLinha;
                }

                verificaTamanho = 0;
            }
        }
        printf("\nA LINHA [%d] E A MAIOR COM (%d) CARACTERES.\n\n", maiorLinha, quantidadeCaracteres);
    }
    fclose(arquivoDecifrado);
}

// Pesquisar uma palavra no texto
void pesquisarPalavra()
{
    FILE *arquivoNlinhas, *arquivoDecifrado;

    int i = 0, totalOcorrencias = 0, ocorrenciaLinha = 0, indices = 0;
    char palavra[MAX_CHAR_PALAVRA], linhaAux[MAX_CHAR_LINHA], linhaOriginal[MAX_CHAR_LINHA];
    char linhasOcorrencias[MAX_LINHA][MAX_CHAR_LINHA];
    const char espaco[] = " ";
    char *token;

    zeraIndiceMatriz(linhasOcorrencias);

    arquivoNlinhas = fopen(fileNlines, "r");
    arquivoDecifrado = fopen(fileDecifra, "r");

    if (arquivoDecifrado == NULL)
    {
        ERRO_ENCONTRAR_ARQUIVO(fileDecifra);
        INFORMA_ERRO(fileCode, "FOI DECIFRADO");
    }
    else if (arquivoNlinhas == NULL)
    {
        ERRO_ENCONTRAR_ARQUIVO(fileNlines);
        INFORMA_ERRO(fileDecifra, "TEVE SUAS LINHAS ENUMERADAS");
    }
    else
    {
        printf("\nQUAL PALAVRA PESQUISAR: ");
        flush_in();
        fgets(palavra, MAX_CHAR_PALAVRA, stdin);

        palavra[strlen(palavra) - 1] = 0; // NULO

        while (!feof(arquivoNlinhas))
        {
            if (fgets(linhaOriginal, MAX_CHAR_LINHA, arquivoNlinhas) != NULL)
            {
                strcpy(linhaAux, linhaOriginal);
                token = strtok(linhaAux, espaco);

                while (token != NULL)
                {
                    if (strstr(token, palavra) != NULL)
                    {
                        ocorrenciaLinha++;
                        if (ocorrenciaLinha == 1)
                        {
                            strcpy(linhasOcorrencias[indices], linhaOriginal);
                            indices++;
                        }
                    }

                    token = strtok(NULL, espaco);
                }
                totalOcorrencias += ocorrenciaLinha;
                ocorrenciaLinha = 0;
            }
        }
        if (totalOcorrencias != 0)
        {
            printf("\nAS LINHAS EM QUE A PALAVRA '%s' OCORRE:\n\n", palavra);
            mostraLinhas(linhasOcorrencias, indices);
            printf("\nE TEM %d OCORRENCIAS.\n\n", totalOcorrencias);
        }
        else
            printf("\nA PALAVRA '%s' NAO FOI ENCONTRADA!\n\n", palavra);
    }
}

void menuPrincipal(char *caminhoArquivoCodificado)
{
    int opc;
    do
    {
        system("cls");
        printf("1 - DECIFRA ARQUIVO\n2 - GRAVA NUMERO LINHA EM ARQUIVO\n3 - QUANTAS LINHAS O ARQUIVO TEM\n4 - QUAL A MAIOR LINHA\n");
        printf("5 - PESQUISAR UMA PALAVRA\n0 - ENCERRAR\n\nQUAL OPCAO: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            decifraArquivo(caminhoArquivoCodificado);
            system("pause");
            break;
        case 2:
            gravaLinhaArquivo();
            system("pause");
            break;
        case 3:
            quantidadeLinhaArquivo();
            system("pause");
            break;
        case 4:
            maiorLinha();
            system("pause");
            break;
        case 5:
            pesquisarPalavra();
            system("pause");
            break;
        case 0:
            printf("\nOPERACAO FIANLIZADA COM SUCESSO!\n\n");
            system("pause");
            break;

        default:
            printf("\nOPCAO INVALIDA!\nTENTE NOVAMENTE . . .\n\n");
            system("pause");
            break;
        }

    } while (opc != 0);
}

int main(int argc, char *argv[])
{
    FILE *arquivoCodificado;

    if ((arquivoCodificado = fopen(fileCode, "r")) == NULL)
    {
        ERRO_ENCONTRAR_ARQUIVO(fileCode);
        SUGESTAO_ERRO(fileCode);
        system("pause");
    }
    else
        menuPrincipal(fileCode);

    fclose(arquivoCodificado);
    return 0;
}