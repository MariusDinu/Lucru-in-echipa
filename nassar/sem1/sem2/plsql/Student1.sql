



CREATE OR REPLACE PROCEDURE cm (a_val IN NUMBER , b_val IN NUMBER ) AS
a NUMBER;
b NUMBER;
a1 NUMBER;
b1 NUMBER;
mdc NUMBER;
mmc NUMBER;
BEGIN
a:=a_val;
b:=b_val;
a1:=a_val;
b1:=b_val;
      while(a!=b)
      LOOP
        if(a>b)
            a:=a-b;
        else
            b:=b-a;
            END IF;
      END LOOP;
      mdc:=a;
      mmc:=(a1*b1)/mdc;
      DBMS_OUTPUT.PUT_LINE( mdc );
      DBMS_OUTPUT.PUT_LINE( mmc );
      
END ;

set serveroutput on;
BEGIN
   cm(24,32);
END;





























--fuctia medii student(avgStudent)care primeste nume si prenume
create or replace FUNCTION avgStudent (p_nume IN studenti.nume%type, p_prenume IN studenti.prenume%type)
RETURN VARCHAR2
AS
Md INTEGER; --va retine Md notelor
SLista INTEGER; --va retine de cate ori apare studentul in lista
mesaj_student VARCHAR(32767); --va retine mesajul in care se va afisa si Md
id_student_SLista INTEGER; --va retine id-ul studentului daca il gaseste in tabelul studenti
numar_note INTEGER; -- numarul de note al studentului 
student_inexistent EXCEPTION; -- daca studentul nu exista in tabel
PRAGMA EXCEPTION_INIT(student_inexistent, -20001);
student_fara_note EXCEPTION; -- daca studentul nu are note
PRAGMA EXCEPTION_INIT(student_fara_note, -20002);

BEGIN
select count(*)into SLista from studenti where nume=p_nume and prenume=p_prenume;--verificam daca studentul exista in tabel
IF SLista = 0 then 
   raise student_inexistent;
   else
   select id into id_student_SLista from studenti where nume=p_nume and prenume=p_prenume; --retinem in id_student_SLista id-ul studentului gasit in tabel
   select count(valoare) into numar_note from note  where id_student=id_student_SLista; -- numarul de note ale studentului
   IF numar_note = 0 then
   raise student_fara_note;
   END IF;
END IF;  

select avg(valoare)into Md from note where id_student=id_student_SLista; --calculam Md tuturor notelor ale studentului

mesaj_student := 'Studentul cu numele si prenumele ' || p_nume ||' '|| p_prenume || ' are Md ' || Md ;
RETURN mesaj_student;

EXCEPTION
WHEN student_inexistent THEN
  raise_application_error (-20001,'Studentul cu numele si prenumele ' || p_nume ||' '|| p_prenume || ' nu exista in baza de date.');
WHEN student_fara_note THEN
  raise_application_error (-20002,'Studentul cu numele si prenumele ' || p_nume ||' '|| p_prenume || ' nu are nici o nota.'); 
END avgStudent;




--blocul anonim

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
   --aici am aratat ca functia avgStudent functioneaza
    student_nameA := nameA('Ursu', 'Poenariu', 'Popescu');  --am initializat lista nameA
    student_lastNameA := lastNameA ('Ervin Rolland','Ana Elena','Theodora Ana');--am initializat lista lastNameA
   for i in student_nameA.first..student_nameA.last LOOP
      select avgStudent(student_nameA(i),student_lastNameA(i))into aratFunction from dual; --pentru fiecare nume-prenume de index i se va apela functia avgStudent
     DBMS_OUTPUT.PUT_LINE(aratFunction); --se vor afisa mediile dar exceptiile nu
   END LOOP;
   --aici am aratat cum am folosit exceptiile 
    student_nameF := nameF('Nassar', 'ionuti', 'amer');  --am initializat lista nameF
    student_lastNameF := lastNameF ('mahmoud','raveriu','achira'); --am initializat lista lastNameF
   for i in student_nameF.first..student_nameF.last LOOP
      select avgStudent(student_nameF(i),student_lastNameF(i))into aratFunction from dual; --pentru fiecare nume-prenume de index i se va apela functia avgStudent
       DBMS_OUTPUT.PUT_LINE(aratFunction); --se vor afisa mediile dar exceptiile nu
   END LOOP;
   
END;

select nume,prenume from STUDENTI;


















