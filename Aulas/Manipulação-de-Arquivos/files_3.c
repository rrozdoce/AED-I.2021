#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    FILE *file;
    file = fopen("D:\\Aplicativos\\string.txt", "r"); // diretório do arquivo

    if (file == NULL) // controle de erro
    {
        printf("Nao foi possivel abrir o arquivo");
        getchar();
        exit(0); // fecha o programa
    }

    char frase[1000];

    // fscanf() vai tratar de entrada de dados formatadas perfeitamente

    while (fgets(frase, 100, file) != NULL) // file get string
    {
        printf("%s\n", frase);
    }

    fclose(file); // fechar o arquivo

    system("pause");
    return 0;
}