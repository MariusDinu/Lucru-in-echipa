--Nassar Mahmoud ,Grupa A5


--acici am creat viewul
SET SERVEROUTPUT ON;

CREATE OR REPLACE view catalog as
select s.id as nrId,s.nume as nume_student,s.prenume as prenume_student,n.id_curs as id_curs,
c.titlu_curs as titlu_curs,n.valoare as valoare from studenti s join note n on s.id=n.id_student join cursuri c on c.id=n.id_curs order by s.id;

--aici am facut triggerul pt delete
CREATE OR REPLACE TRIGGER Sterge_student_si_note
 INSTEAD of delete ON catalog
 BEGIN
  dbms_output.put_line('am sters studentul cu numele:'||:OLD.nume_student);
  delete from note where id_student=:OLD.nrId;
  delete from prieteni where id_student1=:OLD.nrId;
  delete from prieteni where id_student2=:OLD.nrId;
  delete from studenti where id=:OLD.nrId;

 END;
 
--aici am facut triggerul pt Inserarea unei note la un curs pentru un student inexistent 
CREATE OR REPLACE TRIGGER insert_student_inexistent 
INSTEAD OF insert ON catalog
DECLARE
valoare_grupa varchar2(2);
valoare_nr_matricol VARCHAR2(6);
valoare_bursa int;
valoare_an int;
valoare_id_note int;
valoare_temp int;
valoare_id_student INT;
BEGIN  
 LOOP
         valoare_nr_matricol := FLOOR(DBMS_RANDOM.VALUE(100,999)) || CHR(FLOOR(DBMS_RANDOM.VALUE(65,91))) || CHR(FLOOR(DBMS_RANDOM.VALUE(65,91))) || FLOOR(DBMS_RANDOM.VALUE(0,9));
         select count(*) into valoare_temp from studenti where nr_matricol = valoare_nr_matricol;
         exit when valoare_temp=0;
 END LOOP;  
 LOOP      
        valoare_an := TRUNC(DBMS_RANDOM.VALUE(0,3))+1;
        valoare_grupa := chr(TRUNC(DBMS_RANDOM.VALUE(0,2))+65) || chr(TRUNC(DBMS_RANDOM.VALUE(0,6))+49);
        select count(*) into valoare_temp from studenti where an=valoare_an and grupa=valoare_grupa;
        exit when valoare_temp < 30;
END LOOP;
        valoare_bursa := TRUNC(DBMS_RANDOM.VALUE(0,10))*100 + 500;
 dbms_output.put_line('Inseram studentul cu numele si prenumele:' || :New.nume_student ||' '|| :New.prenume_student );
 select max(id)into valoare_id_note from note;
 select count(*)into valoare_id_student from studenti;
 
 insert into Studenti (id,nume,prenume,NR_MATRICOL,an,grupa,bursa) values ( :New.nrId,:New.nume_student,:New.prenume_student,valoare_nr_matricol,valoare_an,valoare_grupa,valoare_bursa); 
 insert into note(id,id_student,id_curs,valoare) values(valoare_id_note+1,:New.nrId,:New.id_curs,:New.valoare);

END;

--aici am facut triggerul pt Inserarea unei note la un curs pentru un curs inexistent
CREATE OR REPLACE TRIGGER insert_adaugarea_cursului
INSTEAD OF insert ON catalog
DECLARE
TYPE varr IS VARRAY(1000) OF varchar2(255);
valoare_id_notee int;
valoare_id_cursuri int;
valoare_curs INT;
BEGIN  
 dbms_output.put_line('Inseram cursul cu numele :' ||:New.titlu_curs);
 select max(id)into valoare_id_notee from note;
 select count(id)into valoare_id_cursuri from cursuri; 
 valoare_curs:=DBMS_RANDOM.VALUE(0,5);
  insert into cursuri(id,titlu_curs) values (valoare_id_cursuri+1, :New.titlu_curs);
  insert into note(id,id_student,id_curs,valoare) values(valoare_id_notee+1,:New.nrId,valoare_id_cursuri+1,:New.valoare);

END;


--aici am facut triggerul pt Inserarea unei note cand nu exista nici studentul si nici cursul.
 CREATE OR REPLACE TRIGGER ultimul_insert
INSTEAD OF insert ON catalog
DECLARE
valoare_grupa VARCHAR2(2);
valoare_nr_matricol VARCHAR2(6);
valoare_bursa int;
valoare_an int; 
valoare_credite int;
valoare_semestru int;
valoare_an_curs int;
valoare_id_student int;
valoare_temp int;
valoare_id_notee int;
valoare_curs int;
BEGIN
valoare_credite:=DBMS_RANDOM.VALUE(1,6);
valoare_an_curs:=DBMS_RANDOM.VALUE(1,3);
valoare_semestru:=DBMS_RANDOM.VALUE(1,2);
select max(id)into valoare_id_notee from note; 
select count(*)into valoare_id_student from studenti; 
select count(id)into valoare_curs from cursuri; 
LOOP
         valoare_nr_matricol := FLOOR(DBMS_RANDOM.VALUE(100,999)) || CHR(FLOOR(DBMS_RANDOM.VALUE(65,91))) || CHR(FLOOR(DBMS_RANDOM.VALUE(65,91))) || FLOOR(DBMS_RANDOM.VALUE(0,9));
         select count(*) into valoare_temp from studenti where nr_matricol = valoare_nr_matricol;
         exit when valoare_temp=0;
 END LOOP;  

LOOP      
        valoare_an := TRUNC(DBMS_RANDOM.VALUE(0,3))+1;
       valoare_grupa := chr(TRUNC(DBMS_RANDOM.VALUE(0,2))+65) || chr(TRUNC(DBMS_RANDOM.VALUE(0,6))+49);
       select count(*) into valoare_temp from studenti where an=valoare_an and grupa=valoare_grupa;
       exit when valoare_temp < 30;
END LOOP; 
valoare_bursa := 600;

insert into cursuri(id,titlu_curs,an,semestru,credite) values (valoare_curs+1, :New.titlu_curs,valoare_an_curs,valoare_semestru,valoare_credite);
 dbms_output.put_line('Am inserat:' || :New.titlu_curs);
 
insert into Studenti (id,nume,prenume,NR_MATRICOL,an,grupa,bursa) values (valoare_id_student+1,:New.nume_student,:New.prenume_student,valoare_nr_matricol,valoare_an,valoare_grupa,valoare_bursa); 
dbms_output.put_line('Am inserat studentul cu numele:'  || :New.nume_student);

 insert into note(id,id_student,id_curs,valoare) values(valoare_id_notee+1,valoare_id_student+1,valoare_curs+1,:New.valoare);
 dbms_output.put_line('Am inserat nota cu val:'|| :New.valoare);
END;

--aici am facut update
CREATE OR REPLACE TRIGGER update_note
 INSTEAD OF update ON catalog
 DECLARE
 valoare_nota int;
BEGIN
select valoare into valoare_nota from note where id_student=:New.nrId  and id_curs=:New.id_curs;
IF(valoare_nota<:New.valoare)THEN UPDATE note set valoare=:New.valoare,updated_at=sysdate where id_student=:New.nrId and id_curs=:New.id_curs;
END IF;
END;


--comanda delete
 delete from catalog where nrId=1;
 --primul insert cu student
 insert into catalog values (127,'Nassar','mahmoud',25,'logica',9); 
 --2 insert cu curs
 insert into catalog values (125,'Nassar','mahmoud',27,'psihologie',5); 
 --3 insert cu curs si student
 insert into catalog values (120,'rares','ravriu',27,'anotomi',6);
 --update
 update catalog set valoare=9 where id_curs=4 and student_id=1;



