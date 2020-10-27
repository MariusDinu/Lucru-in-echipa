--Dinu Marius,grupa A5
--am creat un script pentru a exporta intr-un fisier de format csv
CREATE OR REPLACE PROCEDURE export_to_csv as
  v_fisier UTL_FILE.FILE_TYPE; --initializam fisierul
  cursor info is select * from note;
  table_to_string varchar(100); --un string pe care-l vom folosi pentru a adauga valorile in fisier pentru a se pune cate o linie
  linie Number(38,0); --va retine numarul de linii total
BEGIN
  linie:=0; --initializam linii
  v_fisier:=UTL_FILE.FOPEN('MYDIR','EXPORT_NOTE_SQL.csv','W'); --cream si deschidem fisierul pentru a scrie,de aceea folosim W
FOR v_linie IN info LOOP --pentru fiecare linie din tabelul note
  table_to_string:=v_linie.id||' '||v_linie.id_student||' '||v_linie.id_curs||' '||v_linie.valoare||' '||v_linie.data_notare||' '||v_linie.created_at||' '||v_linie.updated_at;
  --adaugam in string toate datele de pe o linie din tabel
  UTL_FILE.PUT_LINE(v_fisier,table_to_string);
  --adaugam stringul cu linia in fisierul csv
  linie:=linie+1; --incrementam linie
END LOOP;
  DBMS_OUTPUT.PUT_LINE('Am extras '||linie||' linii!');
  --afisam la final cate linii am extras in csv
  UTL_FILE.FCLOSE(v_fisier);
  --inchidem fisierul
END;
/

--am creat un script pentru a insera dintr-un fisier csv
CREATE OR REPLACE PROCEDURE insert_from_csv as
 v_fisier UTL_FILE.FILE_TYPE;
 v_sir VARCHAR2(100); -- va retine randul primit din fisier
 --am creat niste variabile compatibile cu cele din tabelul note
 ID NUMBER(38,0);
 ID_STUDENT NUMBER(38,0);
 ID_CURS NUMBER(38,0);
 VALOARE NUMBER(2,0);
 DATA_NOTARE DATE;
 CREATED_AT DATE;
 UPDATED_AT DATE;
 
 suma int;--va retine pozitiile de la care sa inceapa sa caute regexp
 linie NUMBER(38,0); -- va retine numarul de linii
BEGIN
 v_fisier:=UTL_FILE.FOPEN('MYDIR','EXPORT_NOTE_SQL.csv','R'); --deschidem fisierul 
 linie:=0; --initializam linie
LOOP
   UTL_FILE.GET_LINE(v_fisier,v_sir);--citim prima linie din fisier

   ID:=regexp_substr(v_sir,'[^ ]+' ,1); suma:=length(ID);
   --preluam tot ce este pana la ' ' si reprezinta id-ul, apoi suma devine lungimea id-ului plus spatiul la care s-a oprit
   ID_STUDENT:=regexp_substr(v_sir,'[^ ]+' ,suma+1); suma:=suma+1+length(ID_STUDENT);
   --preluam tot ce este pana la ' ' si reprezinta id-ul studentului, apoi suma devine lungimea id-ului studentului plus spatiul la care s-a oprit
   ID_CURS:=regexp_substr(v_sir,'[^ ]+' ,suma+1); suma:=suma+1+length(ID_CURS);
   --preluam tot ce este pana la ' ' si reprezinta id-ul cursului, apoi suma devine lungimea id-ului cursului plus spatiul la care s-a oprit
   VALOARE:=regexp_substr(v_sir,'[^ ]+' ,suma+1);suma:=suma+1+length(VALOARE);
   --preluam tot ce este pana la ' ' si reprezinta valoarea, apoi suma devine lungimea valorii plus spatiul la care s-a oprit
   DATA_NOTARE:=regexp_substr(v_sir,'[^ ]+' ,suma+1);suma:=suma+1+length(DATA_NOTARE);
   --preluam tot ce este pana la ' ' si reprezinta data notarii, apoi suma devine lungimea datei notarii plus spatiul la care s-a oprit
   CREATED_AT:=regexp_substr(v_sir,'[^ ]+' ,suma+1);suma:=suma+1+length(CREATED_AT);
   --preluam tot ce este pana la ' ' si reprezinta data crearii, apoi suma devine lungimea crearii plus spatiul la care s-a oprit
   UPDATED_AT:=regexp_substr(v_sir,'[^ ]+' ,suma+1);suma:=suma+1+length(UPDATED_AT);
   --preluam tot ce este pana la ' ' si reprezinta data updatelui, apoi suma devine lungimea updatelui plus spatiul la care s-a oprit
   linie:=linie+1;--incrementam linie ca sa stim numarul exact de linii introduse
   DBMS_OUTPUT.PUT_LINE(ID||' '||ID_STUDENT||' '||ID_CURS||' '||VALOARE||' '||DATA_NOTARE||' '||CREATED_AT||' '||UPDATED_AT);
   --afiseaza valorile pe care urmeaza sa le introduc
   insert into note values (ID,ID_STUDENT,ID_CURS,VALOARE,DATA_NOTARE,CREATED_AT,UPDATED_AT);
   --inseram valorile
 END LOOP; 
 EXCEPTION 
 WHEN NO_DATA_FOUND
 THEN --daca nu mai gaseste date inchide fisierul si afiseaza cate linii am inserat
 UTL_FILE.FCLOSE(v_fisier); DBMS_OUTPUT.PUT_LINE('Am adaugat '||linie||' linii!');
END;

exec export_to_csv; --rulam ca sa exportam in csv
exec insert_from_csv; -- rulam ca sa inseram din csv

select * from note; --afisam tot tabelul,daca avem ceva in el
delete from note; --stergem tot din note

select COUNT(*) from note;

