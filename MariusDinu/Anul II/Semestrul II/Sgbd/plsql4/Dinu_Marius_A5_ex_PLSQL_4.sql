set serveroutput on;
CREATE OR REPLACE TYPE lista_medii is TABLE of NUMBER; --am rulat prima data asta ca sa se faca tipul lista_medii de tip number 
alter table studenti add medii lista_medii nested table medii store as nume; --adaugam coloana medii la tabelul studenti 

ALTER SESSION SET NLS_NUMERIC_CHARACTERS = '. '; --aici am schimbat virgula care aparea la 7,25 de exemplu cu punct pentru a arata mai ok lista

DECLARE
medii_materii lista_medii;--declaram medii materii de tip lista_medii creat mai sus
nr_studenti NUMBER; --aici vom stoca numatul de studenti 
BEGIN
  DBMS_OUTPUT.PUT_LINE('Inserarea mediilor a 1025 studenti...');
 SElECT COUNT(*) INTO nr_studenti FROM studenti; --stocam numarul de studenti in nr_studenti
  FOR value_i IN 1..nr_studenti LOOP --vom lua fiecare student in parte pentru a realiza 2 comenzi 
     --comanda 1
     SELECT avg(n.valoare) BULK COLLECT INTO medii_materii     --folosim functia avg pentru a calcula mediile la fiecare materie apoi vom salva mediile obtinute pe care fiecare semestru in parte la fiecare student in medii_materii in functie de anul de studiu 
     FROM studenti s JOIN note n ON s.id = n.id_student JOIN cursuri c ON c.id=n.id_curs WHERE s.id=value_i GROUP BY s.id,c.an,c.semestru ORDER BY s.id; --grupam dupa an si semestru pentru a calcula mediile  
     --comanda 2
     UPDATE studenti SET medii = medii_materii WHERE id=value_i; --si vom face update in tabelul studenti pe coloana medii la fiecare student in parte
END LOOP;
DBMS_OUTPUT.PUT_LINE('S-au inserat mediile!');
END;



select * from studenti;
select * from note group by id_curs;
select medii from studenti;
select REPLACE(CAST(avg(bursa) as decimal(29,2)), ',', '.')  as Listenpreis from studenti;
select avg(bursa) from studenti;
select medii from studenti where id=1;

