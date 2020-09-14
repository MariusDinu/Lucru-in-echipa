
CREATE OR REPLACE TYPE lista_medii is TABLE of NUMBER;


      
alter table studenti add medii lista_medii nested table medii store as nume;
      


CREATE OR REPLACE FUNCTION recomandari(myid integer) return varchar2 as
cursor prieteni is
select id_student1, nume, prenume, mycount from (
select * from (
select id_student1, count(*) as mycount from (
select id_student1 from prieteni where id_student2 in 
	(select id_student1 from prieteni where id_student2 = myid
	union
	select id_student2 from prieteni where id_student1 = myid
	)
union all
select id_student2 from prieteni where id_student1 in 
	(
	select id_student1 from prieteni where id_student2 = myid
	union
	select id_student2 from prieteni where id_student1 = myid
	)
) where id_student1 <> myid
group by id_student1
having count(*) > 1 
) where rownum < 6
) join studenti on studenti.id = id_student1;
v_rezultat varchar2(5000) := '{' || CHR(10);
begin
  for v_index in prieteni loop 
    v_rezultat := v_rezultat || '{"id": ' || v_index.id_student1 || ', ';
    v_rezultat := v_rezultat ||'"nume": ' || v_index.nume || ', ';
    v_rezultat := v_rezultat || '"prenume": ' || v_index.prenume || ', ';
    v_rezultat := v_rezultat || '"Nr. de prietenii": ' || v_index.mycount || '}';
    v_rezultat := v_rezultat || CHR(10);
  end loop;
  v_rezultat := v_rezultat || '}';
  return v_rezultat;
end recomandari;

SELECT recomandari(3) FROM dual;