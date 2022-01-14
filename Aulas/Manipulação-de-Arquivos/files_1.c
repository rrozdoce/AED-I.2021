#include <stdio.h>

int main(void)
{
    FILE *file;
    file = fopen("D:\\Aplicativos\\teste.txt", "w"); // 'r' para ler e 'w' para escrever e 'a' para alterar
    fprintf(file, "hauahahah");
    fclose(file);
    return 0;
}