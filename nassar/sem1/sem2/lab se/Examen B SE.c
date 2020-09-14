//la punctul B e foarte usor daca intelegi rationamentul (care e putin dubios)
//asta e B-ul de la subiectul tau de la sesiune
/*
Care e ideea de baza:
    
"Intrarea X a circuitului este conectata la P1":
X era intrarea pe care intra numerele. O sa vrem in programul nostru
sa facem P1=numere[i], unde numere contine cele 10 numerele
Ideea e mereu o sa scriem in P1, dar nicioadata nu o sa citim din el
(adica facem P1=n, dar nu n=P1)

"Iesirea R a circuitului este conectata la P2":
R este iesirea pentru numere. De aceea o sa vrem sa citim din el (atunci cand si e 1)

"Intrarea si iesirea sunt la bitii 3 si 4 din P0":
Intrarea e startul, iesirea e ack din Verilog.
O sa vrem sa facem P0_2=1 atunci cand avem un numar de trimis, altfel il facem 0
In schimb din P0_3 o sa citim valorile returnate de Verilog.
Daca P0_3 e 1, atunci avem un numar in P2 pe care vrem sa-l luam
Daca P0_3 e 0, atunci nu facem nimic

Cerinta ne cere sa afisam cel mai mare coeficient care nu e 0
Pentru ca noi primim de la cel mai mare la cel mai mic, ne vom opri la primul diferit de 0
Led-urile se aprind cu 0 si se sting cu 1 pe pozitia respectiva
Cod:
*/
#include <8051.h>
int numere[10];
int suma[5];
int i;       //pentru trimitere
int counter; //pentru raspuns
int patterns[5];
int main()
{
    numere[0] = 0;
    numere[1] = 3;
    numere[2] = 0;
    numere[3] = 1;
    numere[4] = 0;
    numere[5] = 0;
    numere[6] = 0;
    numere[7] = 5;
    numere[8] = 10;
    numere[9] = 2;
    //declararea numerelor constante: pot fi oricat
    i = 0;
    counter = 0;
    patterns[0] = 0b11101111; //explicat la final
    patterns[1] = 0b11110111;
    patterns[2] = 0b11111011;
    patterns[3] = 0b11111101;
    patterns[4] = 0b11111110;
    while (1)
    {
        P3 = 0b11111111; //P3 controleaza ledurile; 
        //asa ii spunem sa fie toate stinse; poti face si 0xFF sau 255
        //0b11111111; inseamna numar in binar cu fiecare bit egal cu 1
        if (i < 10) //se poate cu for dar prefer asa pentru ca e asem. cu Verilog
        {
            P1 = numare[i]; //P1 e intrarea in Verilog
            i++;
            P0_2 = 1; //facem startul 1, fiindca avem de trimis
        }
        else //aici e partea care vine dupa ce am trimis toate numerele
        {
            P0_2 = 0;        //am terminat de trimis, facem startul 0
            if (counter < 5) //daca c<5, inseamna ca mai avem de citit
            {
                if (P0_3 == 1) //daca ack=1, inseamna ca putem lua, altfel nu facem nimic
                {
                    suma[counter] = P2; //numarul va fi in P2
                    counter++;
                }
            }
            else //inseamna ca am terminat de citit tot, putem afisa
            {
                for (i = 0; i < 5; i++)
                    if (suma[i] != 0)
                    {
                        P3=patterns[i];
                        break;
                    }
            }
        }
        return 0;
    }
    /*else-ul de la final functioneaza in felul urmator
Noi o sa avem in suma un vector de 5 numere de genul cum e in exemplu(sa zicem 0,6.-25,0,17)

Pentru ca deja citim de la cel mai mic la cel mai mare coeficient (adica suma[0]=0, suma[1]=6 ... suma[4]=17 in cazul asta)
o sa ne oprim cand ajugem la primul diferit de 0 (de aceea break-ul din if);

Acum partea de shiftare/pattern;
P3 controleaza led-urile, deci lui trebuie sa-i dam valoarea;
Am declarat pattern-urile de la p[0] la p[4];
Dupa cum se vede, ele sunt formate din 1-uri cu cate un 0;
0-ul ala va fi pozitia singurului LED aprins
In exemplu, prima suma[i]!=0 este suma[1];
i-ul va deveni 1 si patterns[1] este  = 0b11110111, care aprinde led-ul de pe pozitia 3 (dinspre dreapta spre stanga) (pozitia 0 e cea mai din dreapta)
Daca nu e gasit niciunul(adica toate sumele sunt 0), P3 va ramane 0b11111111(declarat la inceputul lui while(1)), care nu aprinde nimic;





