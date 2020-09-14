--NASSAR MAHMOUD GRUPA:A5

--am facut sa apara pe prima linia numele la fiecare colana
CREATE OR REPLACE PROCEDURE EXPORT_date_csv
is
v_file UTL_FILE.File_type;
v_string VARCHAR2 (4000);
CURSOR C IS
select id,id_student,id_curs,valoare,data_notare,CREATED_AT,UPDATED_AT from note;
BEGIN
v_file := UTL_FILE.FOPEN('MYDIR','EXTRACT.csv','w',1000);
v_string := 'id,id_student,id_curs,valoare,data_notare,CREATED_AT,UPDATED_AT';
UTL_FILE.put_line (v_file, v_string);
FOR cur IN C
LOOP
v_string := cur.id|| ','|| cur.id_student|| ','|| cur.id_curs|| ','|| cur.valoare|| ','||cur.data_notare|| ','||cur.CREATED_AT|| ','||cur.UPDATED_AT ;
UTL_FILE.put_line (v_file, v_string);
end loop;
UTL_FILE.FCLOSE(v_file);
EXCEPTION 
WHEN OTHERS THEN
IF UTL_FILE.IS_OPEN(v_file)
then
UTL_FILE.FCLOSE(v_file);
end if;
end;

-- sa executa procedura pt a exporta  din tabel
exec EXPORT_date_csv;


--pt a inseara in tabel dar inainte trebuia sa fie stearsa prima linia
DECLARE
      F UTL_FILE.FILE_TYPE;
      V_LINE VARCHAR2 (32676);
      V_ID NUMBER(38,0);
      V_ID_STUDENT NUMBER(38,0);
      V_ID_CURS NUMBER(38,0);
      V_VALOARE NUMBER(2,0);
      V_DATA_NOTARE DATE;
      V_CREATED_AT DATE;
      V_UPDATED_AT DATE;
    BEGIN
      F := UTL_FILE.FOPEN ('MYDIR','EXTRACT.csv', 'R');
    IF UTL_FILE.IS_OPEN(F) THEN
      LOOP
        BEGIN
          UTL_FILE.GET_LINE(F, V_LINE, 32676);
          IF V_LINE IS NULL THEN
            EXIT;
          END IF;
          V_ID := REGEXP_SUBSTR(V_LINE, '[^,]+', 1, 1);
          V_ID_STUDENT := REGEXP_SUBSTR(V_LINE, '[^,]+', 1, 2);
          V_ID_CURS := REGEXP_SUBSTR(V_LINE, '[^,]+', 1, 3);
          V_VALOARE := REGEXP_SUBSTR(V_LINE, '[^,]+', 1, 4);
          V_DATA_NOTARE := REGEXP_SUBSTR(V_LINE, '[^,]+', 1, 5);
          V_CREATED_AT := REGEXP_SUBSTR(V_LINE, '[^,]+', 1, 6);
          V_UPDATED_AT := REGEXP_SUBSTR(V_LINE, '[^,]+', 1, 7);

          INSERT INTO NOTE VALUES(V_id,V_id_student,V_id_curs,V_valoare,V_data_notare,V_CREATED_AT,V_UPDATED_AT);
          COMMIT;
        EXCEPTION
        WHEN NO_DATA_FOUND THEN
          EXIT;
        END;
      END LOOP;
    END IF;
    UTL_FILE.FCLOSE(F);
  END;
 
 

--cand faci insertul tabel trebie sa stergi mai intai
delete from note;
select *from note;

--ca sa nu repet o greseala pe care am facuto 
--am folosit informati din acest sait
--https://tipsfororacle.blogspot.com/2017/03/export-table-data-to-flat-files.html