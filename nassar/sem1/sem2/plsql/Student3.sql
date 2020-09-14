--am creat functia medie studenti cu 2 parametrii de tip nume respectiv prenume
create or replace FUNCTION medie_studenti (p_nume IN studenti.nume%type, p_prenume IN studenti.prenume%type)
RETURN VARCHAR2
AS
medie INTEGER; --va retine media notelor
valid INTEGER; --va retine de cate ori apare studentul in lista
mesaj_student VARCHAR(32767); --va retine mesajul in care se va afisa si media
id_student_valid INTEGER; --va retine id-ul studentului daca il gaseste in tabelul studenti
numar_note INTEGER; --va retine numarul de note al studentului 
student_inexistent EXCEPTION; --exceptie daca studentul nu exista in tabel
PRAGMA EXCEPTION_INIT(student_inexistent, -20001);
student_fara_note EXCEPTION; --exceptie daca studentul nu are note
PRAGMA EXCEPTION_INIT(student_fara_note, -20002);

BEGIN
select count(*)into valid from studenti where nume=p_nume and prenume=p_prenume;--verificam daca studentul exista in tabel
IF valid = 0 then 
   raise student_inexistent;
   else
   select id into id_student_valid from studenti where nume=p_nume and prenume=p_prenume; --retinem in id_student_valid id-ul studentului gasit in tabel
   select count(valoare) into numar_note from note  where id_student=id_student_valid; --verificam numarul de note ale studentului
   IF numar_note = 0 then
   raise student_fara_note;
   END IF;
END IF;  

select avg(valoare)into medie from note where id_student=id_student_valid; --calculam media tuturor notelor ale studentului

mesaj_student := 'Studentul cu numele si prenumele ' || p_nume ||' '|| p_prenume || ' are media ' || medie ;
RETURN mesaj_student;

EXCEPTION
WHEN student_inexistent THEN
  raise_application_error (-20001,'Studentul cu numele si prenumele ' || p_nume ||' '|| p_prenume || ' nu exista in baza de date.');
WHEN student_fara_note THEN
  raise_application_error (-20002,'Studentul cu numele si prenumele ' || p_nume ||' '|| p_prenume || ' nu are nici o nota.'); 
END medie_studenti;






DECLARE
    TYPE nameA IS TABLE OF varchar2(15);
    student_nameA nameA; --am creat lista cu nameA
    TYPE lastNameA IS TABLE OF varchar2(30);
    student_lastNameA lastNameA;--am creat lista cu lastNameA
    TYPE nameF IS TABLE OF varchar2(15);
    student_nameF nameF;--am creat lista cu nameF
    TYPE lastNameF IS TABLE OF varchar2(30);
    student_lastNameF lastNameF;--am creat lista cu lastNameF
    aratFunction varchar2(32767);
BEGIN
   --aici am aratat ca functia medie_studenti functioneaza
    student_nameA := nameA('Dragoman', 'Dragoman', 'Stoian');  --am initializat lista nameA
    student_lastNameA := lastNameA ('Silviu','Roland','George Ciprian');--am initializat lista lastNameA
   for i in student_nameA.first..student_nameA.last LOOP
      select medie_studenti(student_nameA(i),student_lastNameA(i))into aratFunction from dual; --pentru fiecare nume-prenume de index i se va apela functia medie_studenti
     DBMS_OUTPUT.PUT_LINE(aratFunction); --se vor afisa mediile dar exceptiile nu
   END LOOP;
   --aici am aratat cum am folosit exceptiile 
    student_nameF := nameF('Dinu', 'ABC', 'Alex');  --am initializat lista nameF
    student_lastNameF := lastNameF ('Andrei','ABC','Marina'); --am initializat lista lastNameF
   for i in student_nameF.first..student_nameF.last LOOP
      select medie_studenti(student_nameF(i),student_lastNameF(i))into aratFunction from dual; --pentru fiecare nume-prenume de index i se va apela functia medie_studenti
       DBMS_OUTPUT.PUT_LINE(aratFunction); --se vor afisa mediile dar exceptiile nu
   END LOOP;
   
END;

select * from studenti where nume = 'Stoian';
insert into STUDENTI (id,nume,prenume,NR_MATRICOL) values (1026,'ABC', 'ABC',123124);--am adaugat in student un student abc
insert into NOTE (id,id_student,id_curs) values (17518,1026,1);--nu am adaugat in tabelul note studentului abc la coloana valoare nimic 
select count(valoare) from note where id_student=1026; --afiseaza cate note are studentul abc
select count(*) from note where valoare is null; --afiseaza cate inregistrari cu valoare null gaseste









