

set serveroutput on;
Declare
v_nume profesori.nume%type;
v_nr int ;
v_exists int;
v_curs cursuri.titlu_curs%type;
v_id_curs cursuri.id%type;
v_nr_profs_care_predau_cursul int;
v_nr_cursuri_predate2 int;
v_nr_stud_promovati int ;
Begin 
v_nume:= '&i_sir_car';

select  count(*) into v_exists from profesori where nume = v_nume; 
if(v_exists < 1 )
then 

select count(*) into v_nr from didactic where  id_profesor in (select id from profesori where nume = v_nume) ;
 DBMS_OUTPUT.PUT_LINE( v_nr ||': nr de cursuri predate de' ||v_nume );
 
 select titlu_curs, id into v_curs, v_id_curs from  
(select titlu_curs, id from cursuri where id in
(select id_curs from  didactic where  id_profesor in 
(select id from profesori where nume = 'Clim')
) order by titlu_curs 
) where rownum=1;
DBMS_OUTPUT.PUT_LINE( v_curs ||' : numele primului cursului predat de  '  ||v_nume ||' in ordine alf.' );

select count(*)into v_nr_profs_care_predau_cursul from didactic where id_curs= v_id_curs ;
DBMS_OUTPUT.PUT_LINE( v_nr_profs_care_predau_cursul ||' :numarul profilor care mai predau cursul  '  ||v_curs );

select count(*) into v_nr_cursuri_predate2 from didactic where id_profesor in(select id_profesor from didactic where id_curs=  v_id_curs);
DBMS_OUTPUT.PUT_LINE( v_nr_cursuri_predate2 ||' :numarul cursurilor predate de profesorii care predau si  '  ||v_curs );

select count(*) into v_nr_stud_promovati from note where id_curs=(select id from cursuri where titlu_curs= v_curs) and valoare <5;
DBMS_OUTPUT.PUT_LINE( v_nr_stud_promovati ||' :numarul studentilor promovatila materia   '  ||v_curs );

select count(*) into v_nr_stud_promovati from note where id_curs=(select id from cursuri where titlu_curs= v_curs) and valoare >=5;
DBMS_OUTPUT.PUT_LINE( v_nr_stud_promovati ||' :numarul studentilor nepromovatila materia   '  ||v_curs );

else DBMS_OUTPUT.PUT_LINE( 'nu exista profesorul cu numele   '||v_nume);
end if;

End;

SELECT * FROM PROFESORI ;

SELECT COUNT(*),GRUPA,AN FROM STUDENTI JOIN NOTE ON STUDENTI.ID = NOTE.ID_STUDENT GROUP BY GRUPA, AN, ID_CURS HAVING 
ID_CURS = (SELECT ID_CURS FROM CURSURI WHERE 
UPPER(TITLU_CURS)LIKE '%BAZE DE DATE%') ORDER BY AN;