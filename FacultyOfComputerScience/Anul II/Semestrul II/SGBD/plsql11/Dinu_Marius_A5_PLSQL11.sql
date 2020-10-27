--Dinu Marius, grupa A5

DECLARE
cursor info_table_cursor is SELECT * FROM USER_TABLES; -- selectam toate tabelele utilizatorului si le punem in cursor
info_constr INTEGER; --salvam numarul de constrangeri
info_constr_type VARCHAR2(1000); --salvam ca varchar2 lista de constrangeri
info_table_count INTEGER; --salvam numarul de tabele
info_index_type VARCHAR2(1000); --salvam ca varchar2 lista de tipuri
info_index INTEGER; --salvam numarul de indecsi

cursor info_view_cursor is SELECT * FROM USER_VIEWS;  -- selectam toate view-urile utilizatorului si le punem in cursor
info_view_count INTEGER; --salvam numarul de view-uri

cursor info_index_cursor is SELECT * FROM USER_INDEXES; -- selectam toate indecsurile utilizatorului si le punem in cursor
info_index_type_index VARCHAR2(1000); --salvam ca varchar2 lista de indecsi
info_index_count INTEGER; --salvam numarul de indecsi

cursor info_type_cursor is SELECT * FROM USER_TYPES;  -- selectam toate tipurile utilizatorului si le punem in cursor
info_type_count INTEGER; --salvam numarul de tipuri

cursor info_package_cursor is SELECT * FROM USER_OBJECTS where object_type='PACKAGE' ;  -- selectam toate package-urile utilizatorului si le punem in cursor
info_package_count INTEGER; --salvam numarul de package-uri

cursor info_procedure_cursor is SELECT * FROM USER_OBJECTS where object_type='PROCEDURE' ;  -- selectam toate procedurile utilizatorului si le punem in cursor
info_procedure_count INTEGER; --salvam numarul de proceduri
info_procedure_count_line INTEGER; --salvam numarul de linii a procedurii

cursor info_function_cursor is SELECT * FROM USER_OBJECTS where object_type='FUNCTION' ;  -- selectam toate functiile utilizatorului si le punem in cursor
info_function_count INTEGER; --salvam numarul de functii
info_function_count_line INTEGER; --salvam numarul de linii a functiei

BEGIN
--aici avem afisarea tabelelor cu detaliile lor 
BEGIN

SYS.DBMS_OUTPUT.PUT_LINE('1.Afisam tabelele cu ,numele tabelului,cate inregistrari are,  indecsi si care sunt acestia,daca are constrangeri, tipul de constrangere si coloanele implicate, daca este nested table');
SYS.DBMS_OUTPUT.new_line;
SELECT count(*) into info_table_count FROM USER_TABLES;
IF(info_table_count>0)then
FOR v_linie in info_table_cursor LOOP
Select COUNT(*) into info_constr from user_constraints where table_name=v_linie.table_name;
--salvam numarul de constrangeri ca sa stim daca are sau nu
Select listagg(constraint_type||' : '||numele_constrangerii,'')within group(order by constraint_type) into info_constr_type from 
(select unique constraint_type,listagg(column_name||',')  within GROUP (ORDER BY constraint_type)as numele_constrangerii from 
(select unique ac.CONSTRAINT_TYPE,acc.column_name from all_constraints ac join all_cons_columns acc on  acc.owner = ac.owner and acc.table_name = ac.table_name and acc.constraint_name = ac.constraint_name where ac.table_name=v_linie.table_name) group by constraint_type);
--in aceasta comanda stabilim ce tip constrangeri si pe ce coloane este constrangerea.
--in prima faza am facut un join intre toate constrangerile si toate coloanele care au constrangeri
--apoi am pus conditia ca sa fie pe tabelul la care avem nevoieoanele care sunt de acel tip
--Apoi am incercat sa le fac ca un varchar pe toate la un loc, sa-mi apar
--le-am grupat pe tipul constrangerii ca am linii cu fiecare tip de constrangere si coloana ei dar fara ca tipul sa fie unic
--Apoi am incercat sa le fac unice si imi afisa tipul unic si toate cola tipul apoi toate coloanele, apoi urmatorul tip si coloanele lui
--De specificat ca am cautat pe net o metoda prin care sa fac mai multe coloane sa fie de tip varchar si am dat de comanda listagg care imi face o singura linie din toti parametrii dati
Select COUNT(*) into info_index from USER_INDEXES where table_name=v_linie.table_name;
--salvam numarul de indecsi ca sa stim daca are sau nu
select listagg(index_type||' : '||column_name||' ,')within group(order by index_type)into info_index_type from 
(SELECT ui.index_type,uic.COLUMN_NAME FROM USER_INDEXES ui join user_ind_columns uic on ui.TABLE_NAME=uic.TABLE_NAME and ui.index_name=uic.index_name where ui.table_name=v_linie.table_name );
--salvam intr-un varchar2 lista indecsilor cu tot cu tip
--mai intai am facut un join intre user_indexes si user_ind_columns si am selectat tipul si coloanele cu conditia ca tabelul sa fie cel cerut de utilizator
--apoi am salvat in varchar2, aici nu a fost nevoie sa folosesc unique fiindca la toate tabelele exista doar un index sau deloc 

SYS.DBMS_OUTPUT.PUT_LINE('Tabelul '||v_linie.table_name||' are '||v_linie.num_rows||' inregistrari.');

IF(info_constr>0) then --daca are constrangeri afiseaza detaliile
SYS.DBMS_OUTPUT.PUT_LINE('Constrangeri: Da,are '||info_constr||' constrangeri. Tipul constragerilor sunt: '||info_constr_type);
else
SYS.DBMS_OUTPUT.PUT_LINE('Constrangeri: Nu are constrangeri.');
END IF;
SYS.DBMS_OUTPUT.PUT_LINE('Este nested: '||v_linie.nested);

IF(info_index>0) then
 SYS.DBMS_OUTPUT.PUT_LINE('Indecsi: '||info_index_type);
else 
 SYS.DBMS_OUTPUT.PUT_LINE('Indecsi: Nu are indecsi.');
END IF;

 SYS.DBMS_OUTPUT.new_line;
END LOOP;
else
SYS.DBMS_OUTPUT.PUT_LINE('Nu are tabele.');
SYS.DBMS_OUTPUT.new_line;
END IF;
END;

--aici avem afisarea view-urilor cu detaliile lor
BEGIN
SYS.DBMS_OUTPUT.PUT_LINE('2.Afisam view-urile utilizatorului.');
SYS.DBMS_OUTPUT.NEW_LINE;
SELECT count(*)into info_view_count FROM USER_VIEWS;
--verificam daca exista view-uri
IF (info_view_count>0) then
FOR v_linie in info_view_cursor LOOP
--afisam detaliile
SYS.DBMS_OUTPUT.PUT_LINE('Nume view: '||v_linie.view_name||' , Lungime: '||v_linie.text_length);
SYS.DBMS_OUTPUT.NEW_LINE;
END LOOP;
else
SYS.DBMS_OUTPUT.PUT_LINE('Nu are view-uri.');
SYS.DBMS_OUTPUT.NEW_LINE;
END IF;
END;

--aici avem afisare indecsilor cu detaliile lor
BEGIN
SYS.DBMS_OUTPUT.PUT_LINE('3.Afisam indecsii utilizatorului');
SYS.DBMS_OUTPUT.new_line;
SELECT count(*)into info_index_count FROM USER_INDEXES;
IF(  info_index_count>0 ) then
--verificam daca exista indecsi
FOR v_linie in info_index_cursor LOOP
--afisam detalii
select listagg(column_name||' ,')within group(order by index_type)into info_index_type_index from 
(SELECT ui.index_type,uic.COLUMN_NAME FROM USER_INDEXES ui join user_ind_columns uic on ui.TABLE_NAME=uic.TABLE_NAME and ui.index_name=uic.index_name where ui.table_name=v_linie.table_name);
--selectam tipul indecsilor si coloana utilizand un join intre cele 2 tabele in care precizam ca numele tabelului sa fie la fel cu numele primit din cursor,fiindca cursorul ne aduca toti indecsii utilizatorului
--si salvam coloanele, am salvat doar coloanele fiindca celelalte detalii pot fi luate din cursor
SYS.DBMS_OUTPUT.PUT_LINE('Nume index: '||v_linie.index_name||' , Tip:'||v_linie.index_type||' , Coloana:'||info_index_type_index||' Tabel: '||v_linie.table_name);
SYS.DBMS_OUTPUT.new_line;
END LOOP;
else 
SYS.DBMS_OUTPUT.PUT_LINE('Nu are indecsi.');
SYS.DBMS_OUTPUT.new_line;
END IF;

END;

--aici avem afisarea tipurilor cu detaliile lor
BEGIN

SYS.DBMS_OUTPUT.PUT_LINE('4.Afisam tipurile utilizatorului.');
SYS.DBMS_OUTPUT.NEW_LINE;
Select COUNT(*) into info_type_count from USER_TYPES;
--verificam daca exista tipuri
IF(info_type_count>0)then
--afisam detaliile
FOR v_linie in info_type_cursor LOOP
SYS.DBMS_OUTPUT.PUT_LINE('Nume tip: '||v_linie.type_name||' , Tip: '||v_linie.typecode);
SYS.DBMS_OUTPUT.NEW_LINE;
END LOOP;
else 
SYS.DBMS_OUTPUT.PUT_LINE('Nu are type-uri');
END IF;
END;

--aici avem afisarea package urilor cu detaliile lor
BEGIN

SYS.DBMS_OUTPUT.PUT_LINE('5.Afisam tipurile utilizatorului.');
SYS.DBMS_OUTPUT.NEW_LINE;
Select COUNT(*) into info_package_count from USER_OBJECTS where object_type='PACKAGE' ;
--verificam daca exista package-uri
IF (info_package_count>0) then
--afisam detaliile
FOR v_linie in info_package_cursor LOOP
SYS.DBMS_OUTPUT.PUT_LINE('Nume pack: '||v_linie.object_name||' , Tip: '||v_linie.object_type||' , ID: '||v_linie.object_id);
SYS.DBMS_OUTPUT.NEW_LINE;
END LOOP;
else 
SYS.DBMS_OUTPUT.PUT_LINE('Nu are package-uri.');
SYS.DBMS_OUTPUT.NEW_LINE;
END IF;

END;

--aici avem afisarea procedurilor cu detaliile lor
BEGIN

SYS.DBMS_OUTPUT.PUT_LINE('6.Afisam procedurile utilizatorului.');
SYS.DBMS_OUTPUT.NEW_LINE;
Select COUNT(*) into info_procedure_count from USER_OBJECTS where object_type='PROCEDURE' ;
--verificam daca exista proceduri
IF (info_procedure_count>0) then
--afisam detaliile
FOR v_linie in info_procedure_cursor LOOP
select * into info_procedure_count_line from (select count(line) from user_source us join all_objects ao on us.name=ao.object_name and ao.owner='STUDENT' where type='PROCEDURE' and us.name=v_linie.object_name);
SYS.DBMS_OUTPUT.PUT_LINE('Nume procedura: '||v_linie.object_name||' , Tip: '||v_linie.object_type||' , ID: '||v_linie.object_id||' , Linii: '||info_procedure_count_line);
SYS.DBMS_OUTPUT.NEW_LINE;
END LOOP;
else 
SYS.DBMS_OUTPUT.PUT_LINE('Nu are proceduri.');
SYS.DBMS_OUTPUT.NEW_LINE;
END IF;

END;

--aici avem afisarea functiilor cu detaliile lor
BEGIN

SYS.DBMS_OUTPUT.PUT_LINE('7.Afisam functiile utilizatorului.');
SYS.DBMS_OUTPUT.NEW_LINE;
Select COUNT(*) into info_function_count from USER_OBJECTS where object_type='FUNCTION';
--verificam daca exista functii
IF (info_function_count>0) then
--afisam detaliile
FOR v_linie in info_function_cursor LOOP
select * into info_function_count_line from (select count(line) from user_source us join all_objects ao on us.name=ao.object_name and ao.owner='STUDENT' where type='FUNCTION' and us.name=v_linie.object_name);
SYS.DBMS_OUTPUT.PUT_LINE('Nume functie: '||v_linie.object_name||' , Tip: '||v_linie.object_type||' , ID: '||v_linie.object_id||' ,Linii: '||info_function_count_line);
SYS.DBMS_OUTPUT.NEW_LINE;
END LOOP;
else 
SYS.DBMS_OUTPUT.PUT_LINE('Nu are functii.');
SYS.DBMS_OUTPUT.NEW_LINE;
END IF;

END;

END;