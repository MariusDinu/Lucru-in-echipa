--comanda pentru a crea o constrangere pe campul valoare pentru a avea doar o nota. Daca cursul este unic pe student atunci nu se vor putea adauga 2 note la acelasi curs.
ALTER TABLE note ADD CONSTRAINT adaugare_note   UNIQUE (id_student,id_curs);
--aici avem primul exercitiu in care verificam daca exista nota apoi adaugam 
DECLARE
student_nume varchar2(10):= 'Dinu'; --am ales numele si prenumele studentului
student_prenume varchar2(10):='Marius';
nota INTEGER:=8; --am ales nota studentului
id_student_valid INTEGER; --se va retine id-ul studentului
id_curs_Logica INTEGER; --se va retine id-ul cursului
count_id INTEGER; --se va retine numarul de studenti cu numele si prenumele dat 
numar_note INTEGER; -- se va retine numarul de note ale studentului de la materia aleasa
index_note INTEGER;
student_inexistent EXCEPTION; 
PRAGMA EXCEPTION_INIT(student_inexistent, -20001);
BEGIN
select Count(id) into count_id from studenti where nume=student_nume and prenume=student_prenume; 
IF count_id=0 then
   raise student_inexistent;        --verificam daca studentul exista in tabel 
   else
select id into id_student_valid from studenti where nume=student_nume and prenume=student_prenume; --retinem id-ul studentului 
select unique(c.id) into id_curs_Logica from note n join cursuri c on n.id_curs=c.id where c.titlu_curs= 'Logicã'; --retinem id-ul cursului
select count(*)into numar_note from note where id_student=id_student_valid and id_curs=id_curs_Logica; --retinem numarul de note
if numar_note=0 then 
dbms_output.put_line('Nu exista note:');  --verificam daca exista note 
select count(*)into index_note from note;
for i in 1..1000000 LOOP
BEGIN
     insert into note(id,id_student,id_curs,valoare) values(index_note+1150,id_student_valid,id_curs_Logica,nota); -- inseram nota ca ultima din tabel , note are aproixmativ 16000 dar indexul incepe de la 1150,deci adaugam de la suma lor
END; 
END LOOP;
END IF;
END IF;
    EXCEPTION
WHEN student_inexistent THEN
    raise_application_error (-20001,'Studentul cu ID-ul ' || id_student_valid || ' nu exista in baza de date.');
END;







select count(*) from studenti;
select count(*) from note; 
select * from note;

--aici avem a doua varianta in care nu verificam daca exista nota 

DECLARE
student_nume varchar2(10):= 'Dinu'; --am ales numele si prenumele studentului
student_prenume varchar2(10):='Marius';
nota INTEGER:=8; --am ales nota studentului
id_student_valid INTEGER; --se va retine id-ul studentului
id_curs_Logica INTEGER; --se va retine id-ul cursului
count_id INTEGER; --se va retine numarul de studenti cu numele si prenumele dat 
numar_note INTEGER; -- se va retine numarul de note ale studentului de la materia aleasa
index_note INTEGER;
student_inexistent EXCEPTION; 
PRAGMA EXCEPTION_INIT(student_inexistent, -20001);
BEGIN
select Count(id) into count_id from studenti where nume=student_nume and prenume=student_prenume;
IF count_id=0 then
   raise student_inexistent; --verificam data studentul exista 
   else
select id into id_student_valid from studenti where nume=student_nume and prenume=student_prenume;--retinem id-ul studentului
select unique(c.id) into id_curs_Logica from note n join cursuri c on n.id_curs=c.id where c.titlu_curs= 'Logicã';--retinem id-ul cursului
select count(*)into index_note from note;
END IF;

for i in 1..1000000 LOOP
BEGIN 
   insert into note(id,id_student,id_curs,valoare) values(index_note+1150,id_student_valid,id_curs_Logica,nota); --inseram nota fara sa verificam, daca exista deja vom prinde exceptia dup_val_on_index care se ocupa de duplicate
   DBMS_OUTPUT.PUT_LINE (SQLCODE);
   EXCEPTION
   WHEN dup_val_on_index then
    raise_application_error (-20003,'Studentul cu ID-ul,numele,prenumele ' || id_student_valid ||' '||student_nume||' '||student_prenume|| ' are deja nota.');
END; 
END LOOP;
 
    EXCEPTION
WHEN student_inexistent THEN
    raise_application_error (-20001,'Studentul cu ID-ul ' || id_student_valid || ' nu exista in baza de date.');
END;





    
