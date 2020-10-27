--Dinu Marius, grupa A5, anul II 
SET SERVEROUTPUT ON;
--am creat un view care sa contina coloanele datele in select 
  CREATE OR REPLACE FORCE VIEW catalog AS 
select s.id as student_id,s.nume as nume_student,s.prenume as prenume_student,n.id_curs as id_curs,
c.titlu_curs as titlu_curs,n.valoare as valoare from studenti s join note n on s.id=n.id_student join cursuri c on c.id=n.id_curs order by s.id;
--la delete am folosit modelul de pe site si am modificat afisarea si variabilele de la old fiindca difera datorita acelui view
CREATE OR REPLACE TRIGGER delete_student_and_note
  INSTEAD OF delete ON catalog
BEGIN
  dbms_output.put_line('Stergem studentul cu numele:' || :OLD.nume_student ||' '||:Old.prenume_student||' '||:Old.titlu_curs||' '||:Old.valoare);
  delete from note where id_student=:OLD.student_id; --il stergem din note
  delete from prieteni where id_student1=:OLD.student_id; --apoi din prieteni 1
  delete from prieteni where id_student2=:OLD.student_id; --apoi din prieteni 2
  delete from studenti where id=:OLD.student_id; --apoi din studenti
END;
---------------------------Final primul exercitiu(Stergerea unui student si totodata a notelor sale (fara a folosi cascade constraints);)
CREATE OR REPLACE FORCE VIEW catalog1 AS 
select s.id as student_id,s.nume as nume_student,s.prenume as prenume_student,n.id_curs as id_curs,
c.titlu_curs as titlu_curs,n.valoare as valoare from studenti s join note n on s.id=n.id_student join cursuri c on c.id=n.id_curs order by s.id;

CREATE OR REPLACE TRIGGER insert_note_with_student 
INSTEAD OF insert ON catalog1
DECLARE
v_grupa varchar2(2); --aici vom avea o grupa random
v_matr VARCHAR2(6); --aici vom avea un numar matricol random
v_bursa int; --o bursa random
v_an int; --un an random
v_id int; --
v_temp int;
v_id_student INT; --vom retine numarul de studenti daca vrem sa facem random,dar am folosit numarul primit ca parametru
BEGIN  
 LOOP
         v_matr := FLOOR(DBMS_RANDOM.VALUE(100,999)) || CHR(FLOOR(DBMS_RANDOM.VALUE(65,91))) || CHR(FLOOR(DBMS_RANDOM.VALUE(65,91))) || FLOOR(DBMS_RANDOM.VALUE(0,9));
         select count(*) into v_temp from studenti where nr_matricol = v_matr;
         exit when v_temp=0;
 END LOOP;  --verificam sa nu existe 2 nr matricole la fel
 LOOP      
        v_an := TRUNC(DBMS_RANDOM.VALUE(0,3))+1;
        v_grupa := chr(TRUNC(DBMS_RANDOM.VALUE(0,2))+65) || chr(TRUNC(DBMS_RANDOM.VALUE(0,6))+49);
        select count(*) into v_temp from studenti where an=v_an and grupa=v_grupa;
        exit when v_temp < 30;
END LOOP; --verificam sa nu fie mai mult de 30 dde studenti intr-o grupa
 v_bursa := TRUNC(DBMS_RANDOM.VALUE(0,10))*100 + 500;--cele 3 sunt luate din scriptul pentru populare de pe site
 dbms_output.put_line('Inseram studentul cu numele si prenumele:' ||v_matr|| ' '||:New.student_id|| :New.nume_student ||' '|| :New.prenume_student ||' '|| :New.titlu_curs ||' '|| :New.valoare);
 select max(id)into v_id from note; --aflam id-ul maxim din note ca sa puteam adauga la pozitia respectiva
 select count(*)into v_id_student from studenti; --aflam numarul total de studenti pentru a putea adauga un nou student
 
 insert into Studenti (id,nume,prenume,NR_MATRICOL,an,grupa,bursa) values (v_id_student+1,:New.nume_student,:New.prenume_student,v_matr,v_an,v_grupa,v_bursa); 
 --inseram studentul cu valori random
 insert into note(id,id_student,id_curs,valoare) values(v_id+1,v_id_student+1,:New.id_curs,:New.valoare);
 --inseram nota la o pozitie noua consecutiva,
 dbms_output.put_line('Gata!');
END;

---------------------------Final al doilea exercitiu(Inserarea unei note la un curs pentru un student inexistent cu adaugarea studentului;)
 CREATE OR REPLACE FORCE VIEW catalog2 AS 
select s.id as student_id,s.nume as nume_student,s.prenume as prenume_student,n.id_curs as id_curs,
c.titlu_curs as titlu_curs,n.valoare as valoare from studenti s join note n on s.id=n.id_student join cursuri c on c.id=n.id_curs order by s.id;

CREATE OR REPLACE TRIGGER insert_note_with_curs2
INSTEAD OF insert ON catalog2
DECLARE
v_id_nr int;
v_id3 int;
v_credite int;
v_semestru int;
v_an_curs int;
BEGIN  
v_credite:=DBMS_RANDOM.VALUE(1,6);
v_an_curs:=DBMS_RANDOM.VALUE(1,3);
v_semestru:=DBMS_RANDOM.VALUE(1,2);
 dbms_output.put_line('Inseram cursul cu numele :'  ||:New.titlu_curs ||' '||' valoarea: '|| :New.valoare);
 select max(id)into v_id_nr from note; --selectam id-ul maxim
 select count(id)into v_id3 from cursuri;  --select numarul maxim de cursuri
 insert into cursuri(id,titlu_curs,an,semestru,credite) values (v_id3+1, :New.titlu_curs,v_an_curs,v_semestru,v_credite);
 --inseram un curs nou si titlul lui si datele random
 insert into note(id,id_student,id_curs,valoare) values(v_id_nr+1,:New.student_id,v_id3+1,:New.valoare);
 --inseram nota la cursul nou la studentul primit ca parametru 
 dbms_output.put_line('Gata!');
END;

---------------------------Final al treilea exercitiu(Inserarea unei note la un curs pentru un curs inexistent - cu adaugarea cursului;)
CREATE OR REPLACE FORCE VIEW catalog3 AS 
select s.id as student_id,s.nume as nume_student,s.prenume as prenume_student,n.id_curs as id_curs,
c.titlu_curs as titlu_curs,n.valoare as valoare from studenti s join note n on s.id=n.id_student join cursuri c on c.id=n.id_curs order by s.id;

 CREATE OR REPLACE TRIGGER insert_note_with_both
INSTEAD OF insert ON catalog3
DECLARE
v_grupa VARCHAR2(2); --aici vom avea o grupa random
v_matr VARCHAR2(6); --aici vom avea un numar matricol random
v_bursa int; --o bursa random
v_an int; --un an random
v_credite int;
v_semestru int;
v_an_curs int;
v_id_student int;
v_temp int;
v_id_nr int;
v_id3 int;
BEGIN
v_credite:=DBMS_RANDOM.VALUE(1,6);
v_an_curs:=DBMS_RANDOM.VALUE(1,3);
v_semestru:=DBMS_RANDOM.VALUE(1,2);
select max(id)into v_id_nr from note; --selectam id-ul maxim
select count(*)into v_id_student from studenti; --aflam numarul total de studenti pentru a putea adauga un nou student
select count(id)into v_id3 from cursuri;  --select numarul maxim de cursuri
LOOP
         v_matr := FLOOR(DBMS_RANDOM.VALUE(100,999)) || CHR(FLOOR(DBMS_RANDOM.VALUE(65,91))) || CHR(FLOOR(DBMS_RANDOM.VALUE(65,91))) || FLOOR(DBMS_RANDOM.VALUE(0,9));
         select count(*) into v_temp from studenti where nr_matricol = v_matr;
         exit when v_temp=0;
 END LOOP;  --verificam sa nu existe 2 nr matricole la fel

LOOP      
        v_an := TRUNC(DBMS_RANDOM.VALUE(0,3))+1;
       v_grupa := chr(TRUNC(DBMS_RANDOM.VALUE(0,2))+65) || chr(TRUNC(DBMS_RANDOM.VALUE(0,6))+49);
       select count(*) into v_temp from studenti where an=v_an and grupa=v_grupa;
       exit when v_temp < 30;
END LOOP; --verificam sa nu fie mai mult de 30 dde studenti intr-o grupa
v_bursa := 450;--cele 3 sunt luate din scriptul pentru populare de pe site

insert into cursuri(id,titlu_curs,an,semestru,credite) values (v_id3+1, :New.titlu_curs,v_an_curs,v_semestru,v_credite);
 --inseram un curs nou si titlul lui si datele random--
 dbms_output.put_line('Am inserat cursul:' || :New.titlu_curs);
 
insert into Studenti (id,nume,prenume,NR_MATRICOL,an,grupa,bursa) values (v_id_student+1,:New.nume_student,:New.prenume_student,v_matr,v_an,v_grupa,v_bursa); 
 --inseram studentul cu valori random--
dbms_output.put_line('Am inserat studentul cu:' ||v_matr|| ' '|| :New.nume_student ||' '|| :New.prenume_student);

 insert into note(id,id_student,id_curs,valoare) values(v_id_nr+1,v_id_student+1,v_id3+1,:New.valoare);
 --inseram nota la cursul nou la studentul primit ca parametru --
 dbms_output.put_line('Am inserat nota:'|| :New.valoare);
END;
 --------------------------Final al patrulea exercitiu(Inserarea unei note cand nu exista nici studentul si nici cursul.)
 CREATE OR REPLACE VIEW catalog4 AS 
select s.id as student_id,s.nume as nume_student,s.prenume as prenume_student,n.id_curs as id_curs,
c.titlu_curs as titlu_curs,n.valoare as valoare from studenti s join note n on s.id=n.id_student join cursuri c on c.id=n.id_curs order by s.id;
 
 CREATE OR REPLACE TRIGGER update_note
 INSTEAD OF update ON catalog4
 DECLARE
 v_nota int;--va retine nota pe care o are studentul la materia respectiva
BEGIN
select valoare into v_nota from note where id_student=:New.student_id  and id_curs=:New.id_curs;--salvam nota la materia respectiva
IF(v_nota<:New.valoare)
--avem conditia de a face update doar daca avem o valoare mai mare,daca nu,nu se schimba
THEN UPDATE note set valoare=:New.valoare,updated_at=sysdate where id_student=:New.student_id and id_curs=:New.id_curs;
--apoi facem update la valoare si la updated_at cu data de astazi  doar daca avem studentul respectiv si cursul respectiv
END IF;
END;
---------------------------Final al cincilea exercitiu(Update la valoarea notei pentru un student - se va modifica valoarea campului updated_at. De asemenea, valoarea nu poate fi modificata cu una mai mica (la mariri se considera nota mai mare).)
 
 delete from catalog where student_id=6;
 --stergem un student din view dar trebuie ca studentul sa existe
 insert into catalog1 values (127,'SGBD','SGBD',25,'NaveSpatiale',8); --inseram la studentul cu id-ul 126 cu nume,prenume la cursul cu id-ul respectiv si numele respectiv cu nota respectiva
 --daca nu exista studentul il creaza dar trebuie ca cursul sa existe 
 insert into catalog2 values (126,'SGBD','SGBD',27,'NaveSpatiale',8); --inseram la studentul cu id-ul 126 cu nume,prenume la cursul cu id-ul respectiv si numele respectiv cu nota respectiva
 --daca nu exista cursul il creaza dar trebuie ca studentul sa existe
 insert into catalog3 values (126,'SGBD','SGBD',27,'NaveSpatiale',8);
 --insereaza nota cu student si curs daca nu exista
 update catalog4 set valoare=10 where id_curs=5 and student_id=123;
 --face update daca gaseste cursul si studentul
 select * from note where id_curs=5 and id_student=123;
 
 
 --am creat la fiecare un view ca sa se vada functionalitatea
 --daca le puneam pe toate cand rulam un insert nu se vedea diferenta dintre a crea un student sau un curs si a le crea pe amandoua
 
 
 
 
 