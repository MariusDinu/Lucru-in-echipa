
--Clasa
CREATE OR REPLACE TYPE profesor AS OBJECT
(nr_vechime NUMBER(6),--numarul reprezinta care prof este mai vechi cu cat proful este mai vchi cu cat numarul este mai mic
nume varchar2(10),
 prenume varchar2(10),
 grupa_la_care_preda varchar2(4),
 anul_la_care_preda number(1), 
 credete_materile_profesor number(1),
NOT FINAL member procedure afiseaza_date_despre_profesori,
 member procedure afiseaza_credete_profesor,
 MAP MEMBER FUNCTION vechime RETURN NUMBER,
 CONSTRUCTOR FUNCTION profesor(nr_vechime NUMBER ,nume varchar2, prenume varchar2)
 RETURN SELF AS RESULT
)NOT FINAL;

--metodele
CREATE OR REPLACE TYPE BODY profesor AS
   MEMBER PROCEDURE afiseaza_date_despre_profesori IS
   BEGIN
      -- DBMS_OUTPUT.PUT_LINE('Aceasta procedura calculeaza si afiseaza date dspre profesori');
       
       DBMS_OUTPUT.PUT_LINE( 'nume si prenume'|| ' : ' ||nume || ' '  || prenume);
    DBMS_OUTPUT.PUT_LINE('grupa la care preda' || ' '  ||  grupa_la_care_preda);
    DBMS_OUTPUT.PUT_LINE('anul la care preda' || ' '  || anul_la_care_preda);   
       
   END afiseaza_date_despre_profesori;
   
    MEMBER PROCEDURE afiseaza_credete_profesor IS
   BEGIN
      -- DBMS_OUTPUT.PUT_LINE('Aceasta procedura calculeaza si afiseaza credetele la materia profesorului ');
          DBMS_OUTPUT.PUT_LINE('credetele la materia profesorului' || ' '  ||  credete_materile_profesor);

   END afiseaza_credete_profesor;
   
   MAP MEMBER FUNCTION vechime RETURN NUMBER IS
  BEGIN
    RETURN nr_vechime;
  END;
   
     CONSTRUCTOR FUNCTION profesor(nr_vechime NUMBER ,nume varchar2, prenume varchar2)
 RETURN SELF AS RESULT
  AS
  BEGIN
    SELF.nr_vechime := nr_vechime ;
    SELF.nume := nume;
    SELF.prenume := prenume;
    SELF.anul_la_care_preda := 2;
    SELF.grupa_la_care_preda := 'A1';
    SELF.credete_materile_profesor := 4;
    RETURN;
  END;
END;




--bloc anonim
CREATE TABLE profesori_oop (idul_profesori VARCHAR2(4), obiect profesor);

set serveroutput on;
DECLARE
   v_profesor1 profesor;
   v_profesor2 profesor;
   v_profesor3 profesor;
BEGIN
   v_profesor1 := profesor(5,'Popescu', 'Ionut', 'A2', 1,5);
   v_profesor2 := profesor(1,'Vasilescu', 'George', 'A4', 3,6);
   v_profesor3 := profesor(2,'nassar', 'mahmoud');
   DBMS_OUTPUT.PUT_LINE('date despre profesori');
   v_profesor1.afiseaza_date_despre_profesori();
   v_profesor1.afiseaza_credete_profesor();
   v_profesor3.afiseaza_date_despre_profesori();
   v_profesor3.afiseaza_credete_profesor();
   insert into profesori_oop values ('100', v_profesor1);
   insert into profesori_oop values ('101', v_profesor2);
   --aici am comparat doi object prin MAP
     if (v_profesor1 < v_profesor3) 
      THEN DBMS_OUTPUT.PUT_LINE('profesorul '|| v_profesor1.nume || ' este mai vechi.');
      ELSE DBMS_OUTPUT.PUT_LINE('profesorul '|| v_profesor3.nume || ' este mai vechi.');
   END IF;
END;

--SUBCLASA CARE RESCRIE METODA afiseaza_date_despre_profesori
CREATE OR REPLACE TYPE profesori_bazat UNDER profesor
(    
   salariu NUMBER(6,2),
   OVERRIDING member procedure afiseaza_date_despre_profesori
)

CREATE OR REPLACE TYPE BODY profesori_bazat AS
    OVERRIDING MEMBER PROCEDURE afiseaza_date_despre_profesori IS
    BEGIN
       dbms_output.put_line('salriu prof'|| ' : ' || salariu);
    END afiseaza_date_despre_profesori;
END;

DECLARE
   v_profesori_bazat profesori_bazat;
BEGIN
    v_profesori_bazat := profesori_bazat(3,'calin', 'Mircea', 'A5', 2,4,1000);
    dbms_output.put_line(v_profesori_bazat.nume);
    v_profesori_bazat.afiseaza_date_despre_profesori();
END;

