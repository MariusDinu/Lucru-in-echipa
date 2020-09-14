--NASSAR MAHMOUD GRUPA:A5
--Am creat o procedura care primeste ca parametru idul cursului
create or replace procedure creiez_materia( id_de_materia INTEGER) as
   v_cursor_id INTEGER;
   cursor datele_tabelului is select s.id,s.nume,s.prenume,s.nr_matricol,n.valoare,n.data_notare from studenti s join note n on s.id=n.id_student where n.id_curs=id_de_materia order by s.nume;
   cursor informatie_din_studenti is select column_name, data_type,data_precision,data_length from   user_tab_columns where  table_name = 'STUDENTI' and column_name in ('ID','NUME','PRENUME','NR_MATRICOL');--vreau sa mentin ca atunci cand am number trebuia sa folosesc data_precision si cand am varchar trebuia sa folosesc lungima
   cursor informatie_din_note is select column_name, data_type,data_precision from   user_tab_columns where  table_name = 'NOTE' and column_name in ('VALOARE','DATA_NOTARE') ;
   cursor informatie_din_cursuri is select titlu_curs from cursuri where id=id_de_materia;
   v_ok INTEGER;
   --aici am dec var unde salvezi info din tabele existenta
   var_id_student varchar2(30);
   var_nume_student varchar2(30);
   var_prenume_student varchar2(30);
   var_nr_matricol_student varchar2(30);
   var_valoare_nota varchar2(30);
   var_date_notare_nota varchar2(30);
   var_nume_materia varchar2(52);
   --aici am folosit regex ca la numele cursuli avem spatiu si ca sa putem sa inseram
   var_nume_materia_regex_space varchar2(52); 

begin
--in acest bloc begin am 3 foruri ca sa stabilesc tipul de coloane
begin
--acest for este pt info din tabelul student
FOR v_linie in informatie_din_studenti LOOP
IF v_linie.column_name = 'ID' THEN var_id_student:=v_linie.data_type||' '||'NOT NULL PRIMARY KEY' ;  DBMS_OUTPUT.PUT_LINE(var_id_student); 
ELSE  
         IF v_linie.column_name = 'NUME' THEN var_nume_student:=v_linie.data_type||'('||v_linie.data_length||')'||' NOT NULL';  DBMS_OUTPUT.PUT_LINE(var_nume_student);
               ELSE 
                     IF v_linie.column_name = 'PRENUME' THEN var_prenume_student:=v_linie.data_type||'('||v_linie.data_length||')'||' NOT NULL';  DBMS_OUTPUT.PUT_LINE(var_prenume_student);
                          ELSE IF v_linie.column_name = 'NR_MATRICOL' THEN var_nr_matricol_student:=v_linie.data_type||'('||v_linie.data_length||')'||' NOT NULL';  DBMS_OUTPUT.PUT_LINE(var_nr_matricol_student);
END IF;
END IF;
END IF;
END IF;
END LOOP;
--acest for este pt info din tabelul note
FOR v_linie in informatie_din_note LOOP IF v_linie.column_name = 'VALOARE' THEN var_valoare_nota:= v_linie.data_type||'('||v_linie.data_precision||')'; 
--dupa cum vedeti aici mai sus am folosit precizia pt ca e de tip number
ELSE var_date_notare_nota:= v_linie.data_type; 
END IF;
END LOOP;
--acest for este pt info din tabelul cursuri
FOR v_linie in informatie_din_cursuri LOOP
var_nume_materia:=v_linie.titlu_curs; 


END LOOP;
--aici am inlocuit spatiu cu _
var_nume_materia_regex_space :=REGEXP_REPLACE(var_nume_materia, '( ){1,}', '_');

END;
--aici am creat tabelul
begin
  v_cursor_id := DBMS_SQL.OPEN_CURSOR;
  DBMS_SQL.PARSE(v_cursor_id, 'CREATE TABLE '||var_nume_materia_regex_space||' (id '||var_id_student||',nume '||var_nume_student||',prenume '||var_prenume_student||', nr_matricol '||var_nr_matricol_student||', nota '||var_valoare_nota||',data_notare '||var_date_notare_nota||')', DBMS_SQL.NATIVE);
  v_ok := DBMS_SQL.EXECUTE(v_cursor_id);

    DBMS_SQL.CLOSE_CURSOR(v_cursor_id);
end;
--aici am inserat datele
begin
  v_cursor_id := DBMS_SQL.OPEN_CURSOR;
  DBMS_SQL.PARSE(v_cursor_id,'Insert into '||var_nume_materia_regex_space||' values(:id,:nume,:prenume,:nr_matricol,:nota,:data_notare)' , DBMS_SQL.NATIVE); 
  
  FOR a_linie IN datele_tabelului LOOP
  
  dbms_sql.bind_variable( v_cursor_id,':id', a_linie.id);
  dbms_sql.bind_variable( v_cursor_id, ':nume', a_linie.nume );
  dbms_sql.bind_variable( v_cursor_id, ':prenume', a_linie.prenume );
  dbms_sql.bind_variable( v_cursor_id, ':nr_matricol', a_linie.nr_matricol );
  dbms_sql.bind_variable( v_cursor_id, ':nota', a_linie.valoare );
  dbms_sql.bind_variable( v_cursor_id, ':data_notare', a_linie.data_notare );
  v_ok := DBMS_SQL.EXECUTE(v_cursor_id);
  END LOOP;
  
  DBMS_SQL.CLOSE_CURSOR(v_cursor_id);
end;

end creiez_materia;

--vreau sa mentionez ca nu merge pt cursurile cu mai mult de 30 caractere
begin
creiez_materia(1);
creiez_materia(2);
creiez_materia(3);

end;

--aici am testat daca sau inserat datele
select * from INTRODUCERE_ÎN_PROGRAMARE;
select * from LOGICÃ;
select * from MATEMATICÃ;

select * from CURSURI;

