#include <stdio.h>
#include <stdlib.h>

// declarar e inicializar strings

int main(int argc, char const *argv[])
{
    char palavra[6] = {'B', 'r', 'a', 's', 'i', 'l'}; // nao tem \0
    char palavra[] = {'B', 'r', 'a', 's', 'i', 'l'};  // nao tem \0
    char palavra[7] = {"Brasil"};
    char palavra[] = {"Brasil"};
    char palavra[] = "Brasil"; // maneira mais simples

    //char palavra[] = {"Brasil\0"}; <-- oque o compilador ve
    // \0 --> apenas um caractere
    // char palavra[] = {'B', 'r', 'a', 's', 'i', 'l'}; ===  char palavra[7] = {"Brasil"};

    system("pause");
    return 0;
}
