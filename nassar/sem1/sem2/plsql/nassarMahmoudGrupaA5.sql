--cu comanda asta am creat o coloana de tipul nested in tabelul studenti 
CREATE OR REPLACE TYPE lista_medii is TABLE of NUMBER;


      
alter table studenti add medii lista_medii nested table medii store as nume;
      

-- cu functia asta am inserat mediile in coloana creata
DECLARE
tabel lista_medii;
values_number Studenti.Medii%TYPE;
BEGIN
 
  for v_i IN 1..1025 LOOP
    select avg(n.valoare) BULK COLLECT INTO tabel
     from studenti s join note n on s.id = n.id_student join cursuri c on c.id=n.id_curs where s.id=v_i
       group by s.id,c.an,c.semestru order by s.id;
   
 update studenti set medii = tabel where id=v_i;
END LOOP;
END;

-- cu comanda asta am apelat un id de student dorit sa ii fie afisat medile 
select medii from studenti where id = 1;