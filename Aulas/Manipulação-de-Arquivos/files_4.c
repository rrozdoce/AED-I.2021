#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file;                                       // ponteiro file
    file = fopen("D:\\Aplicativos\\string.txt", "a"); // diretório do arquivo,  'a' append para colocar mais coisa no arquivo

    if (file == NULL) // controle de erro
    {
        printf("Arquivo nao pode ser aberto");
        getchar();
        exit(1);
    }

    fprintf(file, "Primeira linha\n"); // adicionou mais uma linha

    char frase[] = "Segunda linha\n"; //  passar um vetor de caracteres
    fputs(frase, file);               // anexa / escreve informação

    char caractere = '3';
    fputc(caractere, file); // anexa somente um caractere

    fclose(file); // fechar o arquivo

    return 0;
}