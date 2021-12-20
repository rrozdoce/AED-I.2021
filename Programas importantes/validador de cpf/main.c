#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char cpf[15];
    int i;
    int dig;
    
    srand(time(NULL));
    
    for(i = 0; i < 11; i++){
        cpf[i] = (rand() % 10) + '0';
    }
    cpf[3] = '.';
    cpf[7] = '.';
    cpf[11] = '-';
    dig = ((((cpf[0] - '0') * 10) + ((cpf[1] - '0') * 9) + ((cpf[2] - '0') * 8) + ((cpf[4] - '0') * 7) + ((cpf[5] - '0') * 6) + ((cpf[6] - '0') * 5) + ((cpf[8] - '0') * 4) + ((cpf[9] - '0') * 3) + ((cpf[10] - '0') * 2)) % 11);
    if(dig == 0 || dig == 1){
        cpf[12] = '0';
    }
    else{
        cpf[12] = (11 - dig) + '0';
    }
    dig = ((((cpf[0] - '0') * 11) + ((cpf[1] - '0') * 10) + ((cpf[2] - '0') * 9) + ((cpf[4] - '0') * 8) + ((cpf[5] - '0') * 7) + ((cpf[6] - '0') * 6) + ((cpf[8] - '0') * 5) + ((cpf[9] - '0') * 4) + ((cpf[10] - '0') * 3) + ((cpf[12] - '0') * 2)) % 11);
    if(dig == 0 || dig == 1){
        cpf[13] = '0';
    }
    else{
        cpf[13] = (11 - dig) + '0';
    }
    cpf[15] = '\0';
    
    printf("%s \n", cpf);
}