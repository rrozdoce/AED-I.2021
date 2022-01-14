#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    FILE *file;
    file = fopen("D:\\Aplicativos\\numero.txt", "r"); // diretório do arquivo

    if (file == NULL) // controle de erro
    {
        printf("Arquivo nao pode ser aberto\n");
        system("pause");
        return 0;
    }

    int x, y, z;

    fscanf(file, "%i %i %i", &x, &y, &z); // scanf no arquivo file(ponteiro)

    printf("%i %i %i\n", x, y, z);

    fclose(file); // fechar o arquivo

    system("pause");
    return 0;
}