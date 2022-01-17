#include <stdio.h>
#include <stdlib.h>

//  Funções fgetc e getc

int main(void)
{

    char x[100];

    FILE *file = fopen("C:\\Users\\XSpat\\OneDrive\\Área de Trabalho\\Arquivo1.txt", "r");

    int i = 0;
    while ((x[i] = fgetc(file)) != EOF) // EOF == end of file
    {
        i++; // fgetc == getc
    }

    x[i] = '\0'; // colocar x[i] ao invez de [++i], pois da lixo

    printf("%s", x);

    return 0;
}
