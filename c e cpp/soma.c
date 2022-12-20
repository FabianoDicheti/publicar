#include <stdio.h>
#include <stdlib.h>


int main(){
    int m,n,soma = 0;
    int aux;

    while(1){
        
        scanf("%d %d", &m, &n);
        if(m<=0 || n<=0)
            break;
        else{
            soma=0;
            if(m<n){
                for(aux=m; aux<=n; aux++){
                    printf("%d ",aux);
                    soma= soma + aux;
                }

                printf("Sum=%d\n",soma);
            }

            else if(m>n){
                for(aux=n; aux<=m; aux++){
                    printf("%d ",aux);
                    soma = soma + aux;

                }

                printf("Sum=%d\n",soma);

            }

        }

    }

    return 0;
}

