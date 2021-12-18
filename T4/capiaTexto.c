#include <string.h>
#include <stdio.h>

void copia_t(char t_cpy[], char t_mod[])
{
    for (int i = 0; i < 9999; i++)
    {
        t_cpy[i] = '\0';
        t_cpy[i] = t_mod[i];
        t_mod[i] = '\0';
    }
}

int main()
{
    char str[] = "William Henry Gates III KBE GCIH (Seattle, 28 de outubro de 1955) mais conhecido como Bill Gates, \
 e um magnata, empresario, diretor executivo, investidor, filantropo e autor americano, que ficou conhecido por \
 fundar junto com Paul Allen a Microsoft a maior e mais conhecida empresa de software do mundo em termos de valor \
 de mercado. Gates ocupa atualmente o cargo de presidente nao-executivo da Microsoft alem de ser classificado \
 regularmente como a pessoa mais rica do mundo, posicao ocupada por ele de 1995 a 2007, 2009, e de 2014 a 2017. E \
 um dos pioneiros na revolucao do computador pessoal. Gates nasceu em uma familia de classe media de Seattle. Seu \
 pai, William H. Gates, era advogado de grandes empresas, e sua mae, Mary Maxwell Gates, foi professora da \
 Universidade de Washington e diretora de bancos. Bill Gates e as suas duas irmas, Kristanne e Libby, \
 frequentaram as melhores escolas particulares de sua cidade natal, e Bill tambem participou do \
 Movimento Escoteiro ainda quando jovem. Bill Gates, foi admitido na prestigiosa Universidade \
 Harvard, (conseguindo 1590 SATs dos 1600 possiveis) mas abandonou os cursos de Matematica e \
 Direito no terceiro ano para dedicar-se a Microsoft. Trabalhou na Taito com o desenvolvimento de \
 software basico para maquinas de jogos eletronicos (fliperamas) ate seus 16 anos. Tambem \
 trabalhou como pesquisador visitante na University of Massachusetts at Amherst, UMASS, Estados Unidos, quando \
 com 17 anos, desenvolveu junto com Paul Allen um software para leitura de fitas magneticas, com informacoes \
 de trafego de veiculos, em um chip Intel 8008. Com esse produto, Gates e Allen criaram uma empresa, \
 a Traf-o-Data, porem os clientes desistiram do negocio quando descobriram a idade dos donos. Enquanto \
 estudavam em Harvard, os jovens desenvolveram um interpretador da linguagem BASIC para um dos primeiros \
 computadores pessoais a serem lancado nos Estados Unidos - o Altair 8800. Apos um modesto sucesso na \
 comercializacao deste produto, Gates e Allen fundaram a Microsoft, uma das primeiras empresas no mundo \
 focadas exclusivamente no mercado de programas para computadores pessoais ou PCs. Gates adquiriu ao \
 longo dos anos uma fama de visionario (apostou no mercado de software na epoca em que o hardware era \
 considerado muito mais valioso) e de negociador agressivo, chegando muitas vezes a ser acusado por \
 concorrentes da Microsoft de utilizar praticas comerciais desleais. Nos anos 1980, a IBM, lider \
 no mercado de grandes computadores, resolveu entrar no mercado da microinformatica com o PC, \
 porem faltava o Sistema Operacional. Para isso, fechou contrato com a recem-criada Microsoft. Todavia, \
 a Microsoft nao possuia o software ainda. O jovem Bill Gates foi a uma pequena empresa que havia \
 desenvolvido o sistema para o processador da Intel e decidiu compra-lo, pagou cerca de US$ 50 mil, personalizou \
 o programa e vendeu-o por US$ 8 milhoes, mantendo a licenca do produto. Este viria a ser o MS-DOS. \
 Fonte: https://pt.wikipedia.org/wiki/Bill_Gates";

    const char sp[2] = " ";
    const char vi[2] = ",";
    const char po[2] = ".";
    const char pa_1[2] = "(";
    const char pa_2[2] = ")";
    const char dp[2] = ":";
    const char ba[2] = "/";
    const char un[2] = "_";
    char t_novo[9999];
    char t_aux[9999];
    char *token, *aux_vi, *aux_pa_1, *aux_pa_2, *aux_ba, *aux_dp, *aux_un, *aux_po;
    int cont;
    strcpy(t_aux, str);

    // Virgula
    aux_vi = strtok(t_aux, vi);

    cont = 1;
    while (aux_vi != NULL)
    {
        strcat(t_novo, aux_vi);
        strcat(t_novo, sp);
        if (cont < 43)
            strcat(t_novo, vi);
        strcat(t_novo, sp);

        cont++;
        aux_vi = strtok(NULL, vi);
    }

    // Parenteses (
    copia_t(t_aux, t_novo);
    aux_pa_1 = strtok(t_aux, pa_1);

    cont = 1;
    while (aux_pa_1 != NULL)
    {
        strcat(t_novo, aux_pa_1);
        strcat(t_novo, sp);
        if (cont < 5)
            strcat(t_novo, pa_1);
        strcat(t_novo, sp);

        cont++;
        aux_pa_1 = strtok(NULL, pa_1);
    }

    // Parenteses )
    copia_t(t_aux, t_novo);
    aux_pa_2 = strtok(t_aux, pa_2);

    cont = 1;
    while (aux_pa_2 != NULL)
    {
        strcat(t_novo, aux_pa_2);
        strcat(t_novo, sp);
        if (cont < 5)
            strcat(t_novo, pa_2);
        strcat(t_novo, sp);

        cont++;
        aux_pa_2 = strtok(NULL, pa_2);
    }

    // Barra
    copia_t(t_aux, t_novo);
    aux_ba = strtok(t_aux, ba);

    cont = 1;
    while (aux_ba != NULL)
    {
        strcat(t_novo, aux_ba);
        strcat(t_novo, sp);
        if (cont == 1)
        {
            strcat(t_novo, ba);
            strcat(t_novo, ba);
        }
        else if (cont < 4)
            strcat(t_novo, ba);

        strcat(t_novo, sp);

        cont++;
        aux_ba = strtok(NULL, ba);
    }

    // Dois pontos
    copia_t(t_aux, t_novo);
    aux_dp = strtok(t_aux, dp);

    cont = 1;
    while (aux_dp != NULL)
    {
        strcat(t_novo, aux_dp);
        strcat(t_novo, sp);
        if (cont < 3)
            strcat(t_novo, dp);

        cont++;
        aux_dp = strtok(NULL, dp);
    }

    // Underline
    copia_t(t_aux, t_novo);
    aux_un = strtok(t_aux, un);

    cont = 1;
    while (aux_un != NULL)
    {
        strcat(t_novo, aux_un);
        strcat(t_novo, sp);
        if (cont == 1)
        {
            strcat(t_novo, un);
            strcat(t_novo, sp);
        }

        cont++;
        aux_un = strtok(NULL, un);
    }

    // Ponto
    copia_t(t_aux, t_novo);
    aux_po = strtok(t_aux, po);
    cont = 1;
    while (aux_po != NULL)
    {
        strcat(t_novo, aux_po);
        strcat(t_novo, sp);
        if (cont < 22)
            strcat(t_novo, po);
        strcat(t_novo, sp);

        cont++;
        aux_po = strtok(NULL, po);
    }

    // Retira os espaços
    token = strtok(t_novo, sp);

    while (token != NULL)
    {

        printf("%s\n", token);

        token = strtok(NULL, sp);
    }

    // printf("%s", t_novo);

    return (0);
}