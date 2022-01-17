#include <stdio.h>

//Funções freopen e fgets / stdin

int main(void)
{
    char x[100];

    FILE *file = fopen("C:\\Users\\XSpat\\OneDrive\\Área de Trabalho\\Arquivo1.txt", "r"); // le o arquivo

    fgets(x, 100, file);
    printf("%s\n", x);

    freopen("C:\\Users\\XSpat\\OneDrive\\Área de Trabalho\\Arquivo2.txt", "r", file); // muda onde que 'file' apontava para outro local
    fgets(x, 100, file);
    printf("%s\n", x);

    return 0;
}
