#include <8051.h>
 unsigned char aux;
int main(){
    aux=1;
    while(1) {
        if(aux==128)
            aux=1;
        else
            aux=aux<<1;
        P1=255^aux;
    }
    return 0;
}