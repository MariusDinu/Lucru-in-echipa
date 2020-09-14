#include <8051.h>

volatile char counter;
void f(void)__interrupt 1{
    TH0=4;
    TL0=0;
    counter++;
    P1=~counter;
}
int main()
{
    counter=0;
    TMOD=1;
    IE=130;
    TR0=1;

    while(1){
    }
    return 0;
}