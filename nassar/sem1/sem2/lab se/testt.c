#include <8051.h>
short time;
short aux;
int main(){
    time=0;
    P3_0=0;
    P3_1=1;
    while(1){ 
        if(P3_5==0){
            time=time+1;
            aux=time;
            P1=aux;
        }
    }
    return 0;
}
