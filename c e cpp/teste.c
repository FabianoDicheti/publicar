#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define PI 3.14

int* alocaVmemoria(int tamanho){
    //ponteiro auxiliar
    int *auxiliar;
    // alocacao dinamica de memoria memory allocation
    // ponteiro auxiliar = (ponteiro inteiro) memoryallocation(tamanho do vetor * tamanhode(inteiro em bytes))
    auxiliar = (int*) malloc(tamanho * sizeof(int));
    // retornar o ponteiro que aponta para a primeira posicao de memoria do vetor alocado
    return auxiliar;

}

int** alocaMmemoria(int linhas, int colunas){
    int **matriz;

    //alocando as linhas
    matriz = (int **) malloc(linhas * sizeof(int *));
    // alocando para as colunas de cada linha
    int i;
    for(i = 0; i<linhas; i++){
        matriz[i] = (int *) malloc(colunas * sizeof(int));

    }
    return matriz;

}


int main(void) {
    printf("teste da batata\n");
    

    int batata = 123;
    printf("%d\n", batata);

    printf("batata %d eh\n", batata);

    int valor;
    printf("valor para batata: \n");

    scanf("%d", &valor);
    
    printf("\nsoma de %d   e %d igual a %d :",batata, valor, batata + valor );

    char fritas[10];
    fflush(stdin);
    printf("\ndigite um vegetal:");
    scanf("%s", &fritas);

    printf("fritando : %s", fritas);

    printf("\no resto da divisao de %d por %d eh %d:", batata, valor, batata % valor);

    printf("\n o valor absoluto de -5 eh = %d", abs(-5));

    float nota1, nota2;

    printf("\nnota1 :");
    fflush(stdin);
    scanf("%f", &nota1);

    printf("\nnota2 :");
    fflush(stdin);
    scanf("%f", &nota2);

    float med;

    med = (nota1 + nota2) / 2;

    printf("\n a media da nota 1 de %f e da nota 2 %f eh igual a:  %f ", nota1, nota2, med);

    float dif = abs(nota1 - nota2);

    printf("\n o valor absoluto da diferenca entre as notas eh: %f", dif);

    float a, b, c;
    printf(" \n 3 valores :");
    fflush(stdin);
    scanf("%f %f %f", &a, &b, &c);
    float res = (a * b *c);
    printf(" \nmultiplos = %f", res);

    int j = (int)a;

    if(j % 2 == 1){
        printf("\n o primeiro valor: %f eh impar", a);
    }else{
        printf("\n o primeiro valor: %f eh par", a);
    }

    int k = (int)b;
    if(k % 2 == 1){
        printf("\n o segundo valor: %f eh impar", b);
    }else{
        printf("\n o segundo valor: %f eh par", b);
    }

    int l = (int)c;
    if(l % 2 == 1){
        printf("\no terceiro valor %f eh impar", c);
    }else{
        printf("\no terceiro valor %f eh par", c);
    }

    // condicional com valores booleanos

    bool abobora = true, biscoito = false;

    if(abobora){
        printf("\na abobora eh real");
    }else{
        printf("\n a abobora eh imaginaria");
    }
    // exclamacao significa "NAO" IF !X = SE NAO X
    if(!biscoito){
        printf("\n o biscoito eh imaginario" );
    }


    // consultar o codigo ASCII das letras

    char letra = 'J';
    printf(" \n o codigo da letra %c eh %d", letra, letra);

    char novaletra;
    fflush(stdin);
    printf("\n digite uma letra: ");
    scanf("%c", &novaletra);
    printf("\n o codigo da letra %c eh %d", novaletra, novaletra);


    // "and" escreve &&

    if(a < b && b < c){
        printf("\na eh maior que b AND b eh naior que c");
    }else{
        printf("\ninsira valores em ordem crescente para funcionar");
    }

    // "or" escreve || (dois pipe)

    if (a > b || b > c){
        printf("\na eh maior que b OR b eh maior que c");
    }else{
        printf(" \ntenta colocar uma sequencia crescente");
    }


    float ladoa, ladob, ladoc;

    printf("\n lado a: ");
    scanf("%f", &ladoa);

    printf("\nlado b: ");
    scanf("%f", &ladob);

    printf("\nlado c: ");
    scanf("%f", &ladoc);

    if( ladoa == ladob && ladob == ladoc){
        printf(" \no triangulo eh equilatero");
    }else{
        if(ladoa > ladob){
            printf(" \no lado a eh maior");
        }
        if(ladob > ladoc){
            printf("\n o lado b eh maior");
        }
        if(ladoc > ladoa){
            printf("\n o lado c eh o maior");
        }
    }

    // escolha caso SWITCH IN CASE

    int opcao;

    printf("\n escolha uma opcao 1,2,3\n");
    fflush(stdin);
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            printf("\nopcao 1");
            break;
        case 2:
            printf("\nopcao 2");
            break;
        case 3:
            printf("\nopcao 3");
            break;
        default:
            printf(" \nopcao invalida");
            break;
    }


    int primeiro, segundo;
    printf("\n digite dois numeros\n");
    fflush(stdin);
    scanf("%d %d", &primeiro, &segundo);
    printf("\nescolha uma opcao\n (1) somar \n (2) subtrair \n (3) multiplicar \n (4) dividir \n");
    fflush(stdin);
    int option;
    scanf("%d", &option);

    switch(option){
        case 1:
            printf("\n a soma de %d e %d eh: %d", primeiro, segundo, (primeiro + segundo));
            break;
        case 2:
            printf("\n a subtracao de %d em %d eh: %d", segundo, primeiro, (primeiro - segundo));
            break;
        case 3:
            printf("\n a multiplicacao entre %d e %d eh %d", primeiro, segundo, (primeiro * segundo));
            break;
        case 4:
            printf("\n a divisao de %d por %d eh %d", primeiro, segundo, (primeiro / segundo));
            break;
        default:
            printf("\n opcao invalida");
            break;
    }

    // ######################################
    // PARA DEFINIR O NUMERO DE CASAS DECIMAIS  %.2F para duas casas decimais, %.4f para 4 casas, etc...
    // #####################################



    // gerar numero aleatorio

    srand((unsigned) time(NULL));

    int aleatorio = rand();
    printf("\n numero aleatorio %d", aleatorio);

    int aleatorio0a3 = rand() %3;
    printf("\n numero aleatorio entre 0 e 3: %d", aleatorio0a3);

    int aleatorio1a4 = (rand() %3) +1;
    printf("\n numero aleatorio entre 1 e 4: %d", aleatorio1a4);


    // while

    int qq = 1, oqq = 20;

    while(qq <= 7){
        printf("\n %d", qq);
        qq++;
        //qq ++ =  qq = qq+1
    }

    while(oqq >= qq){
        printf("\n %d", oqq);

        oqq--; // oqq-- = oqq=oqq-1 se for de 2 em 2 ai usar oqq = oqq -2
    }
     
    // do while faz uma vez antes de comparar 

    do{
        printf("\noqq %d", oqq);

        oqq = oqq + 2;
    }while(oqq <= 20);


    // FOR para:    PARA(VARIAVEL=VALOR; VARIAVEL<CONDICAO; VARIAVEL = VARIAVEL+OPERACAO){ ATIVIDADE }

    int outro;

    for(outro = 1; outro <=10; outro++){
        printf("\n 3 vezes %d = %d", outro, outro*3);
    }


    char escolha;
    while(!(escolha == 'a' || escolha == 'b' || escolha == 'c')){

        fflush(stdin);
        printf("\n escolha uma opcao \n (a) \n (b) \n (c)\n");
        scanf("%c", &escolha);

        switch(escolha){
            case 'a':
                printf(" \nopcao a escolhida ASCII %d", escolha);
                break;
            case 'b':
                printf("\nopcao b escolhida ASCII %d", escolha);
                break;
            case 'c':
                printf("\n opcao c escolhida ASCII %d", escolha);
                break;
        }



    }

    int primo;
    int p;
    int zeros = 0;

    printf("\n digite um numero para verificar se eh primo\n");
    fflush(stdin);
    scanf("%d", &primo);

    for(p = 1; p <= primo; p++){
        if(primo % p == 0){
            zeros++;
        }  
    }

    if(zeros == 2){
        printf("\n o numero %d eh primo", primo);
    }else{
        printf("\n o numero possui %d divisores, portanto nao eh primo", zeros);
    }

    // ##############################################
    // ########## V E T O R E S ######################
    // ##############################################

    int vetor[3];
    float vetor2[3];

    vetor[0] = 10, vetor[1] = 100, vetor[2] = 27;
    vetor2[0] = 1.4, vetor2[1] = 34.7, vetor2[2] = 111.9;

    int i;
    for(i = 0; i <3; i++){
        printf("\n vetor int posicao %d valor eh %d", i, vetor[i]);
        printf("\n vetor float posicao %d valor eh %.4f", i, vetor2[i]);
        printf("\n --//--//-- ");
    }

    float vetor3[3];
    int w;
    for(w = 0; w < 3; w++){
        vetor3[w] = vetor[w]*vetor2[w];
        printf("\n na posicao %d o valor ficou %.2f", w, vetor3[w]);
    }

    int size;
    printf("\n digite um tamanho para o vetor: \n");
    fflush(stdin);
    scanf("%d", &size);
    
    float vetor4[size];
    int y = 0;
    float mediaa = 0.0;

    for(y=0; y<size; y++){
        printf("\n digite um valor para o indice[%d]", y);
        fflush(stdin);
        scanf("%f", &vetor4[y]);
        mediaa = mediaa + (vetor4[y]/size);

    }

    int o = 0;
    for(o=0; o<size; o++){
        printf("\n na posicao[%d] do vetor 4 o valor eh: %.3f", o, vetor4[o]);
    }
    printf("\n em media os valores do vetor 4 foram de %.4f", mediaa);

    // EH POSSIVEL CRIAR VETORES COM CHAVES
    int vetorc[4] = {3, 5, 6, 9};
    

   
    // nao esquecer #include <string.h>

    char palavra[20];
    printf("\ndigite uma palavra\n");
    // limpar o espaco dos caracteres "buffer"
    setbuf(stdin, 0);
    // ler palavra: (nome da variavel, tamanho, fonte)
    fgets(palavra, 20, stdin);
    // limpar espaco nao utilizado tamanho da variavel (len) - tamanho utilizado
    palavra[strlen(palavra)-1] = '\0';

    printf(" a palavra %s, possui %lu caracteres", palavra, strlen(palavra));


    system("clear");


    int matriz[3][3], f, e;

    matriz[0][0] = 10;
    matriz[0][1] = 12;
    matriz[0][2] = 13;
    matriz[1][0] = 20;
    matriz[1][1] = 22;
    matriz[1][2] = 23;
    matriz[2][0] = 30;
    matriz[2][1] = 32;
    matriz[2][2] = 33;

    printf("\n matriz \n");

    for(f=0; f<3; f++){
        for(e=0; e<3; e++){
            printf("%d   ", matriz[f][e]);
        }
        printf("\n");
    }

    printf("\n digite os valores \n");
    float matriz2[2][2];
    int r, t;

    for(r=0; r<2; r++){
        for(t=0; t<2; t++){
            printf("valor [%d][%d] : ", r,t);
            scanf("%f", &matriz2[r][t]);
        }
    }

    printf("\n matriz2: \n ");
    int u, g;
    for(u=0; u<2; u++){
        for(g=0; g<2; g++){
            printf("%.2f   ", matriz2[u][g]);
        }
        printf("\n");
    }

    int q, s;
    printf("\n matriz invertida \n");
    for(q=1; q>-1; q--){
        for(s=0; s<2; s++){
            printf("%.2f  ", matriz2[q][s]);
        }
        printf("\n");
    }



// EH POSSIVEL CRIAR MATRIZES E VETORES COM CHAVES

    float matrizF[3][3] = {12,1,3,4,5,33,4,77,9};
    


    // ######## A L O C A C A O  D I N A M I C A   D E   M E M O R I A

    printf("\n ALOCACAO DINAMICA DE MEMORIA \n ________");
    //define as variaveis um ponteiro e um tamanho
    int *vetorDin, tamanhodin;
    // carregar um tamanho qualquer
    printf("\nQual o tamanho para o vetor?\n");
    scanf("%d", &tamanhodin);

    //ponteiro definido dinamicamente pela funcao alocaVmemoria
    vetorDin = alocaVmemoria(tamanhodin);

    //preencher os valores do vetor
    int is;
    for(is=0; is<tamanhodin; is++){
        printf("Qaual o valor para a posicao [%d]: ", is);
        fflush(stdin);
        scanf("%d", &vetorDin[is]);
    }

    int th;
    for(th=0; th<tamanhodin; th++){
        printf("\n Vetor[%d]: = %d", th, vetorDin[th]);
    }
    //libera a memoria
    free(vetorDin);


    printf("\n alocacao dinamica para matriz");
    int largura, altura;
    printf("\n numero de colunas para a matriz: \n");
    fflush(stdin);
    scanf("%d", &largura);
    printf("\n numero de linhas para a matriz: \n");
    fflush(stdin);
    scanf("%d", &altura);

    int **matrizdin;
    matrizdin = alocaMmemoria(largura, altura);

    int li, co;
    for(li = 0; li < altura; li++){
        for(co = 0; co < largura; co++){
            printf("\n valor para[%d][%d]", li, co);
            fflush(stdin);
            scanf("%d", &matrizdin[li][co]);
        }
    }

    printf("\n matriz dinamica \n");

    int pl, pc;
    for(pl = 0; pl < altura; pl++){
        for(pc = 0; pc < largura; pc++){
            printf("%d  ", matrizdin[pl][pc]);
        }
    printf("\n");
    }

    free(matrizdin);





    printf("\n");
    return 0;
}