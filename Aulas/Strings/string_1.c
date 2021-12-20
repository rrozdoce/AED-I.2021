#include <stdio.h>
#include <stdlib.h>

// Introdução a strings

int main(int argc, char const *argv[])
{

    char teste[] = {'b', 'r', 'a', 's', 'i', 'L'};

    for (int i = 0; i < 6; ++i)
    {
        printf("%c", teste[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}
