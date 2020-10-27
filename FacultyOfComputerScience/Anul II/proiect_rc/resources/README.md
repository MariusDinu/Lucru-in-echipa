Pheasant (C)
Sa se realizeze o aplicatie ce va implementa jocul fazan, ce permite existenta mai multor sesiuni paralele. 
Intr-un fisier de configurare se va specifica numarul de jucatori. Va exista un fisier de tip dictionar, ce va fi folosit pentru validarea cuvintelor. 
Utilizatorii vor fi pusi intr-o ordine in care va functiona jocul. Primul jucator alege o litera, dupa care alege un cuvant ce incepe cu litera respectiva. 
Urmatorul utilizator va trebui sa trimita un cuvant ce va incepe cu ultimele doua litere din cuvantul jucatorului precedent.
Cand cuvantul trimis de un utilizator nu face parte din dictionar, jucatorul a pierdut si va fi deconectat. 
Utilizatorul care ramane la sfarsit castiga jocul.

Compilare:
g++ mainServer.cpp -o server.out
g++ mainClient.cpp -o client.out

Rulare:
./server.out
./client.out

Cum sa rulezi:
rulezi 3 clienti in paralel, la fiecare pui nume diferite, si acelasi nume la camera de joc, la fiecare pe rand
apoi iti va aparea acum e randul tau la unul din clienti
atunci scrii un cuvant(prima data se doar prima litera chiar daca nu te lasa sa scrii mai putin de un caracter)
urmatorul jucator trebuie sa scrie un cuvant din dictionar (cand ii apare ca e randul lui) care sa inceapa cu prima litera primita de la cel anterior
acum incepe jocul obisnuit de faza...cu ultimele 2 cu primele 2
fiecare jucator spune cate un cuvand doar cand apare ca e randul lui

Protocol:
Orice comanda/mesaj este precedat(a) de lungimea ei.

Serverul la inceput va citi configuratiile din fisier, si apoi va citi dictionarul de cuvinte.
Serverul asteapta sa se conecteze clientii: 
	- asteapta sa trimita clientii numele lor prin comanda : login <nume>  (id = 1)
	- asteapta ca clientii sa intri in grupurile de jocuri:  join  <nume>  (id = 2)
	- pentru a porni jocul un jucator dupa ce a dat join trebuie sa foloseasca comanda: start(id=3)
	- sa trimita cuvantul ales (id = 0)
     Comenzile prepocesate de client si in forma finala primite in server vor arata <lungime_comanda:int><id:char><date...> datele sunt trimise doar daca e cazul

sizeof(int)=4;
sizeof(char)1=;
Raspunsuri server: <lungime_mesaj:int> <id_raspuns:char> <mesaj> 
ID-uri raspuns: -  0: doar afiseaza mesajul utilizatorul, nu faci nimic mai mult
		-  2: clientul a castigat si s-a terminat jocul (este dat afara)
		-  1: afiseaza mesajul si ateapta raspunsul utilizatorul pentru a-l trimite inapoi
		- -1: clientul a piedut si s-a terminat jocul (este dat afara) (trimis ca "2" -> afiseaza mesajul si deconecteaza utilizatorul)
		

  