#include <8051.h>

char nr;
char counter=0;
int main(){
    char x[]={0b11000000,0b11111001,0b10110000,0b10110000};
    char numbers[4];
    nr=123;
    numbers[0]=nr%10;
    numbers[1]=nr/10%10;
    numbers[2]=nr/100%10;
    numbers[3]=nr/1000%10;
    P0_7=1;
    while(1){
        P1=255;
        P3=counter<<3;
        P1=x[numbers[counter]];
        counter=counter+1;
        counter=counter%4;
    }
}