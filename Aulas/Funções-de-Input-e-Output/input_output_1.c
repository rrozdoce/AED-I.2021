#include <stdio.h>
#include <stdlib.h>

// Funções contidas na stdio.h
// Funções freopen e fgets

int main(void)
{

    char x[100];

    fgets(x, 100, stdin); // esse valor inteiro delimita quantos caracteres a sua função pode ler, aqui 99 caracteres

    // stdin(standard-input), ler os dados do teclado, mas nao necessariamente

    printf("%s", x);

    freopen("C:\\Users\\XSpat\\OneDrive\\Área de Trabalho\\Arquivo1.txt", "r", stdin); // permite redirecionar a file inserida

    fgets(x, 10, stdin);

    printf("%s", x);

    system("pause");
    return 0;
}
