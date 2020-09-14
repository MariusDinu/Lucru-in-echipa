/*
Problema in sine:
Primim doua vectori de cate 5 numere si dorim sa adunam fiecare cu fiecare 
Daca primesc:
2 5 10 0 2 
8 9 1 4 2
Vreau sa obtin:
10 14 11 4 4; 
*/
module suma(Clk,start,n,s,ack); //prima data declari modulul, punand ca argumente ce vine din afara + SI CE IESE
//aici Clk e perioada de ceas(o pui mereu la module)
//start e bitul care zice "pentru sincronizare"; cand start e 0 circuitul se afla intr-o bucla infinita, nefacand nimic; cand start devine 1, incepe treaba
//n este numarul primit la intrare; nu putem citi tablouri, in schimb fiecare numar din ele este primit intr-o perioada; aici vom citi fix 10
//s este numarul de iesire; vom returna 5 numere, aceasta fiind suma lui n0 cu n5, n1 cu n6 ... n4 cu n9 (cifra de dupa n e ordinea a ceea ce primim la intrare)
//ack este bitul suplimentar de iesire. Il folosim ca sa ii spunem sa nu inceapa sa scoata s-uri pana cand nu am facut calculul;
input Clk,start; //deja descrisi, Clk si start mereu sunt input
input [7:0]n; // aici primim numarul: [7:0] inseamna ca este un numar pe 8 biti (+1 fata de primul numar); (daca nu pui nimic de genul asta vei avea numar doar pe un bit, cum sunt cele anterioare)
output reg [7:0]s; // asta este numarul pe care il scoatem din circuit; practic vom asigna la el pe rand valorile din sume;
output reg ack; //am zis deja ce face ack; il declari mereu ca output reg
reg [7:0]sume[0:4]; //asa se declara un array; prima [] e cat de mari sunt numerele in termen de biti (tot 8), al doilea [] specifica dimensiunea array-ului (daca vrem 5 punem 4)
//pe asta il declaram ca reg simplu pentru ca nu o sa il trimitem pe el in sine, ci s care va primi pe rand valorile sale
reg [1:0]stare; // a zis sa fie automat cu stari; declaram pe 2 biti pentru a avea 4 stari posibile
reg [3:0]counter; //ia valori de la 0 la 15 (4 biti); il folosim ca sa vedem cate numere am citit pana acum;
always @(posedge Clk) //la fiecare bataie de ceas... mereu o sa ai linia asta
    if(stare==0) //S0 e starea initiala/latenta; de mentionat ca folosesti begin/end in loc de {} la if-uri
        if(start==0)//daca start e 0, atunci continuam sa nu facem nimic
            begin 
                ack<=0;//si mentinem ack si starea pe 0; a se vedea recapitularea
                stare<=0;//asignarile se fac cu <= (ca in pseudocod), nu cu egal in verilog
            end
        else 
            begin//daca start e 1, incepem sa preluam numere
                sume[counter]<=n; //stocam numarul primit la intrare in sume, prima casuta aici
                counter<=counter+1; //pentru fiecare numar citit incrementam
                stare<=1; //si trecem in starea 1
            end
    else if(stare==1)//starea citirii primelor 5 numerele (fara primul, oarecum)
            begin 
                sume[counter]<=n; //aceleasi chestii ca in else-ul de mai sus
                counter<=counter+1;
                if(counter==5) //daca dupa incrementare am ajuns la 5, inseamna vom trece la citirea ultimelor 5 numere
                    begin
                        counter<=0; //resetam counter-ul pentru celalalt array de 5 numere
                        stare<=2;//trecem in starea 2
                    end
                else
                    begin
                        stare<=1;//altfel ramanem in starea curenta
                    end
                ack<=0; //bune practici
            end
    else if(stare==2)//aici citim ultimele 5 numere; si calculam sumele totodata
            begin
                sume[counter]<=sume[counter]+n; //facem suma intre primul si al saselea, intre 2-lea si 7-lea etc...
                counter<=counter+1;
                if(counter==5)//pana cand ajungem la al 10, cand vom termina
                    begin
                        counter<=0;
                        stare<=3; // trecem in starea finala, in care trimitem numerele
                    end
                else
                    begin
                        stare<=2; //altfel ramanem in starea asta, continuand sa citim numerele
                    end
                ack<=0;//nu suntem inca gata sa trimitem raspunsul
            end
    else if(stare==3)//aici trimitem numerele catre iesire
            begin
                s<=sume[counter]; //punem in registrul de iesire raspunsul
                ack<=1;//acum suntem gata sa trimitem numerele
                counter<=counter+1;
                if(counter==5)//am terminat de dat toate numerele
                    begin //punem aici ce aveam in initial
                        stare<=0; 
                        ack<=0; 
                        counter<=0;
                        //eventual poti sa-i mai spui ca resetam si vectorul sume, care s-ar face ceva in genul..
                        //sume[0]<=0; sume[1]<=0; sume[2]<=0; sume[3]<=0; sume[4]<=0;
                        //s nu e neaparat necesar de resetat, fiindca el mereu va primi o valoare proaspata inainte sa fie folosit
                    end
                else
                    begin
                        stare<=3; //daca nu am ajuns la 5, mai avem de trimis, caz in care ramanem in starea 3
                    end
            end
initial //aici scrii cum vrei sa fie chestiile initial; o sa vrei sa incepi cam cu toate chestiile care sunt reg pe 0;
    stare<=0; //dupa cum am zis, starea 0 e starea initiala; sa asignezi imputuri aici, doar reg;
    ack<=0; //e destul de clar ca nu avem nimic de trimis mai departe; (in starea initiala)
    counter<=0; //similar
    //s nu e neaparat necesar de setat, fiindca el mereu va primi o valoare proaspata inainte sa fie folosit
    //eventual poti sa-i mai spui ca resetam si vectorul sume, care s-ar face ceva in genul..
    //sume[0]<=0; sume[1]<=0; sume[2]<=0; sume[3]<=0; sume[4]<=0;
endmodule

Module(Clck,start,n,s,ack);
input start,clck;
input [0:7]n;
output reg [0:7]s;
output reg ack; 
reg[0:7] reg [255:0];
reg[1:0]stare;
initial begin
stare<=0;
ack<=0;
counter<=0;
i<=0;
end
always @(posedge Clk)
if(stare==0)
   if(stare==0)
    begin
     ack<=0;
     stare<=0;
    end
   else//daca start e 1 incepem sa prelom datele
    begin 
     stare<=1;
    end
   else if(stare==1) 
    begin
     n<=X;
     stare<=2;
    end
   else if(stare==2)
    begin
     if(i<n)
      V[i]=V[i-1]*(2*(i+1));
      i=i-1;
      stare<=2;
    end
   else begin
     i<=0;
     ack<=1;
     stare<=3;
    end   
   else if(stare==3)begin     
        if(ack==1)begin
           ack<=0;
        end
        if(i<n)begin
        R = v[i];
        i=i+1;
        stare <=3;
        end
        else begin  
          stare<=0;
        end
   end
endmodule





