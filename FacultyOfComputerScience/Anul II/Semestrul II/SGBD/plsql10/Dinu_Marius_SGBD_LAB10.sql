--Dinu Marius, an II, grupa A5
create or replace procedure create_materie( cursuri_number INTEGER) as
   v_cursor_id INTEGER;
   cursor date_tabel is select s.id,s.nume,s.prenume,s.nr_matricol,n.valoare,n.data_notare from studenti s join note n on s.id=n.id_student where n.id_curs=cursuri_number order by s.nume;
   --avem un cursor care ne trimite la zona de memorie unde e salvat acest select care ne da lista studentilor cu detalii care au note la materia primita ca parametru 
   cursor info_note is select column_name, data_type,data_precision from   user_tab_columns where  table_name = 'NOTE' and column_name in ('VALOARE','DATA_NOTARE') ;
   --aici vom avea acces la tipul de date a campulurilor valoare si data_notare cu tip si precizie
   cursor info_studenti is select column_name, data_type,data_precision,data_length from   user_tab_columns where  table_name = 'STUDENTI' and column_name in ('ID','NUME','PRENUME','NR_MATRICOL');
   --aici vom avea acces la tipul de date a campurilor id,nume,prenume,nr_matricol cu tip si lungime
   cursor info_catalog is select titlu_curs from cursuri where id=cursuri_number;
   v_ok INTEGER;
   --in aceste varchar2 vom salva tipul de date,tipul precizie dupa caz, lungimea dupa caz si restul detaliilor legate de fiecare coloana pentru a face comanda create mai usoara
   info_id varchar2(30);
   info_nume varchar2(30);
   info_prenume varchar2(30);
   info_nr varchar2(30);
   info_nota varchar2(30);
   info_data varchar2(30);
   info_materie varchar2(52);--aici punem numele materiei cu spatii
   info_materie_regex_space varchar2(52); --aici vom folosi regex ca sa scapam de spatii
   info_materie_regex_virg varchar2(52); --aici vom folosi regex ca sa scapam de virgule
   info_materie_regex_lin varchar2(52); --aici vom folosi regex ca sa scapam de cratime
begin
--aici stabilim tipul coloanelor
begin
--acest loop va salva tipul de date a campului valoare si data_notare
FOR v_linie in info_note LOOP
IF v_linie.column_name = 'VALOARE' THEN 
info_nota:= v_linie.data_type||'('||v_linie.data_precision||')'; --salvam tipul si precizia
ELSE info_data:= v_linie.data_type; --iar aici salvam doar tipul
END IF;
END LOOP;

FOR v_linie in info_studenti LOOP
--pentru a face mai usoara comanda de create am zis sa pun si restul detaliilor 
IF v_linie.column_name = 'ID' THEN info_id:=v_linie.data_type||' '||'NOT NULL PRIMARY KEY' ;  DBMS_OUTPUT.PUT_LINE(info_id); 
-- am creat un varchar2 care sa contina toate detalii despre id
ELSE  
         IF v_linie.column_name = 'NUME' THEN info_nume:=v_linie.data_type||'('||v_linie.data_length||')'||' NOT NULL';  DBMS_OUTPUT.PUT_LINE(info_nume);
         --am creat un varchar2 care sa contina toate detalii despre nume (tipul + lungimea,nu avem nevoie de precizie aici)
               ELSE 
                     IF v_linie.column_name = 'PRENUME' THEN info_prenume:=v_linie.data_type||'('||v_linie.data_length||')'||' NOT NULL';  DBMS_OUTPUT.PUT_LINE(info_prenume);
                     --am creat un varchar care sa contina toate detalii despre prenume (tipul + lungimea,nu avem nevoie de precizie aici)
                          ELSE IF v_linie.column_name = 'NR_MATRICOL' THEN info_nr:=v_linie.data_type||'('||v_linie.data_length||')'||' NOT NULL';  DBMS_OUTPUT.PUT_LINE(info_nr);
                          --am creat un varchar care sa contina toate detalii despre numar matricol (tipul + lungimea,nu avem nevoie de precizie aici)
END IF;
END IF;
END IF;
END IF;
END LOOP;

FOR v_linie in info_catalog LOOP
info_materie:=v_linie.titlu_curs; 
END LOOP;
info_materie_regex_space :=REGEXP_REPLACE(info_materie,'( ){1,}', '_');--inlocuim spatiile din numele materiei pentru a putea folosi acest nume ca identifier
info_materie_regex_lin:=REGEXP_REPLACE(info_materie_regex_space,'-', '_');--inlocuim cratimele din numele materiei pentru a putea folosi acest nume ca identifier
info_materie_regex_virg:=REGEXP_REPLACE(info_materie_regex_lin,',', '_');--inlocuim virgulele din numele materiei pentru a putea folosi acest nume ca identifier

--pentru materiile cu id_curs 4 sau 7 nu pot folosi regex deoarece si cu regex ele depasesc 30 de caractere iar limita este de 30 de caractere pentru versiunea asta de oracle
END;
--aici cream tabelul
begin
  v_cursor_id := DBMS_SQL.OPEN_CURSOR;
  DBMS_SQL.PARSE(v_cursor_id, 'CREATE TABLE '||info_materie_regex_virg||' (id '||info_id||',nume '||info_nume||',prenume '||info_prenume||', nr_matricol '||info_nr||', nota '||info_nota||',data_notare '||info_data||')', DBMS_SQL.NATIVE);
  --aici avem comanda de create a unui tabel unde scriem doar denumirile coloanelor iar detaliile ne sunt date varcharulrile info
  v_ok := DBMS_SQL.EXECUTE(v_cursor_id);
  --executam comanda 
  --se creaza tabelul si acum mergem sa inseram
    DBMS_SQL.CLOSE_CURSOR(v_cursor_id);
end; 
--aici incepem sa inseram

begin
  v_cursor_id := DBMS_SQL.OPEN_CURSOR;
  --inseram in tabelul cu numele materiei
  DBMS_SQL.PARSE(v_cursor_id,'Insert into '||info_materie_regex_virg||' values(:id,:nume,:prenume,:nr_matricol,:nota,:data_notare)' , DBMS_SQL.NATIVE); 
  --avem comanda pentru insert unde am inlocuit values cu bind variables
  FOR a_linie IN date_tabel LOOP
  --pentru fiecare linie din date_tabel care contine datele din note si studenti 
  --legam fiecare coloana a linie de coloana din insert
  dbms_sql.bind_variable( v_cursor_id,':id', a_linie.id);
  dbms_sql.bind_variable( v_cursor_id, ':nume', a_linie.nume );
  dbms_sql.bind_variable( v_cursor_id, ':prenume', a_linie.prenume );
  dbms_sql.bind_variable( v_cursor_id, ':nr_matricol', a_linie.nr_matricol );
  dbms_sql.bind_variable( v_cursor_id, ':nota', a_linie.valoare );
  dbms_sql.bind_variable( v_cursor_id, ':data_notare', a_linie.data_notare );
  --inseram fiecare linie date_tabel in MATERIE atribuind valorile liniei de fiecare data
  v_ok := DBMS_SQL.EXECUTE(v_cursor_id);
  END LOOP;
  DBMS_SQL.CLOSE_CURSOR(v_cursor_id);
end;

end create_materie;

--ca parametru se foloseste id-ul cursului
begin
create_materie(1);
create_materie(2);
create_materie(3);
create_materie(5);
create_materie(9);
create_materie(10);
create_materie(12);
create_materie(16);
end;
--se pot incerca toate cursurile cu titlul mai mic de 30 de caractere
select * from SISTEME_DE_OPERARE;
select * from LOGICÃ;
select * from MATEMATICÃ;
select * from PRACTICÃ_SGBD;
--4,7,8,11,20 sunt cursurile cu titluri prea lungi 


