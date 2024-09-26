PROCEDURE findMin(x IN number, y IN number, z OUT number) 


IS 


BEGIN 
  IF x < y THEN 
   z:= x; 
  ELSE 
   z:= y; 
  END IF; 
END; 
 
 
DECLARE 
a number; 
b number; 
c number; 
BEGIN 
a:= 23; 
b:= 45; 
findMin(a, b, c); 
dbms_output.put_line(' Minimum of (23, 45) : ' || c); 
findMin(30,10, c); 
dbms_output.put_line(' Minimum of ('||a||',' ||b||') is : '||c); 
END; 

/

PROCEDURE findMin(x IN number, y IN number, z OUT number) 


IS 


BEGIN 
  IF x < y THEN 
    z := x; 
  ELSE 
    z := y; 
  END IF; 
END; 
 
DECLARE 
  a number; 
  b number; 
  c number; 
BEGIN 
  a := 23; 
  b := 45; 
  findMin(a, b, c); 
  dbms_output.put_line(' Minimum of (23, 45) : ' || c); 
  findMin(30, 10, c);  
  dbms_output.put_line(' Minimum of (30, 10) is : ' || c);  
END; 

/

CREATE OR REPLACE PROCEDURE findMin(x IN number, y IN number, z OUT number) 
IS 
BEGIN 
  IF x < y THEN 
    z := x; 
  ELSE 
    z := y; 
  END IF; 
END; 
/

DECLARE 
  a number; 
  b number; 
  c number; 
BEGIN 
  a := 23; 
  b := 45; 
  findMin(a, b, c); 
  dbms_output.put_line('Minimum of (23, 45) : ' || c); 
  findMin(30, 10, c); 
  dbms_output.put_line('Minimum of (30, 10) is : ' || c); 
END; 
/

CREATE OR REPLACE PROCEDURE proc_incr_rating (p_sno NUMBER,p_increment NUMBER) 
 
IS 
 
BEGIN 
   vrating NUMBER; 
   SELECT rating 
   INTO vrating 
   FROM sailors 
   WHEREsid=p_sno; 
   UPDATE sailors 
   SET rating=rating+p_increment 
   WHEREsid=p_sno; 
END proc_incr_rating; 
/

BEGIN 
  proc_incr_rating(p_sno => 123, p_increment => 5); -- Replace 123 with the actual Sailor ID and 5 with the increment value. 
END; 
/

CREATE OR REPLACE PROCEDURE proc_incr_rating (p_sno NUMBER,p_increment NUMBER) 
 
IS 
 
BEGIN 
   vrating NUMBER; 
   SELECT rating 
   INTO vrating 
   FROM sailors 
   WHEREsid=p_sno; 
   UPDATE sailors 
   SET rating=rating+p_increment 
   WHEREsid=p_sno; 
END proc_incr_rating; 
/

BEGIN 
  proc_incr_rating(123, 5); -- Replace 123 with the actual Sailor ID and 5 with the increment value. 
END; 
/

CREATE TABLE SAILORS ( 
sid integer(3), 
sname VARCHAR(20) NOT NULL, 
rating integer(2) NOT NULL, 
age float(3,1), 
CONSTRAINT pk_sailors PRIMARY KEY(sid) 
);

CREATE TABLE SAILORS ( 
sid integer(3), 
sname VARCHAR(20) NOT NULL, 
rating integer(2) NOT NULL, 
age float(3,1), 
CONSTRAINT pk_sailors PRIMARY KEY(sid) 
);

CREATE TABLE SAILORS ( 
sid number(3), 
sname VARCHAR(20) NOT NULL, 
rating number(2) NOT NULL, 
age float(3,1), 
CONSTRAINT pk_sailors PRIMARY KEY(sid) 
);

CREATE TABLE SAILORS ( 
  sid number(3), 
  sname VARCHAR(20) NOT NULL, 
  rating number(2) NOT NULL, 
  age float(3,1), 
  CONSTRAINT pk_sailors PRIMARY KEY(sid) 
) 
;

CREATE TABLE SAILORS ( 
  sid number(3), 
  sname VARCHAR(20) NOT NULL, 
  rating number(2) NOT NULL, 
  age double(3,1), 
  CONSTRAINT pk_sailors PRIMARY KEY(sid) 
) 
;

CREATE TABLE SAILORS ( 
  sid number(3), 
  sname VARCHAR(20) NOT NULL, 
  rating number(2) NOT NULL, 
  age float(3), 
  CONSTRAINT pk_sailors PRIMARY KEY(sid) 
) 
;

insert into SAILORS VALUES (22,'Dustin',7,45.0);

insert into SAILORS VALUES (29,'Brutus',1,33.0);

insert into SAILORS VALUES (31,'Lubber',8,55.5);

insert into SAILORS VALUES (32,'Andy',8,25.5);

insert into SAILORS VALUES (58,'Rusty',10,35.0);

insert into SAILORS VALUES (64,'Horatio',7,35.0);

insert into SAILORS VALUES (71,'Zorba',10,16.0);

insert into SAILORS VALUES (74'Horatio',9,35.0);

insert into SAILORS VALUES (85,'Art',3,25.5);

insert into SAILORS VALUES (95,'Bob',3,63.5);

insert into SAILORS VALUES (74,'Horatio',9,35.0);

CREATE OR REPLACE PROCEDURE proc_incr_rating (p_sno NUMBER, p_increment NUMBER) 
IS 
   vrating NUMBER; 
BEGIN 
   SELECT rating 
   INTO vrating 
   FROM sailors 
   WHERE sid = p_sno; 
    
   UPDATE sailors 
   SET rating = rating + p_increment 
   WHERE sid = p_sno; 
END proc_incr_rating; 
/

BEGIN 
  proc_incr_rating(22, 5); -- Replace 123 with the actual Sailor ID and 5 with the increment value. 
END; 
/

select rating from sailors where sid=22 ;

Create PROCEDURE proc_ incr_rating (p_sno number, p_increment number) IS 
BEGIN 
UPDATE sailors 
SET rating = rating + p_increment 
WHERE sid = p_sno; 
END proc_incr_rating; 
/

DECLARE 
var_sno sailors.sid%TYPE := &var_sno; 
var_increment sailors.rating%TYPE :=&var_increment; 
BEGIN 
    proc_incr_rating(var_sno, var_increment); 
END; 
/

CREATE OR REPLACE PROCEDURE proc_incr_rating (p_sno NUMBER, p_increment NUMBER)  
IS  
BEGIN  
  UPDATE sailors  
  SET rating = rating + p_increment  
  WHERE sid = p_sno;  
END proc_incr_rating;  
/

DECLARE 
  var_sno sailors.sid%TYPE := &var_sno; 
  var_increment sailors.rating%TYPE := &var_increment; 
BEGIN 
  proc_incr_rating(var_sno, var_increment); 
END; 
/

DECLARE  
  var_sno sailors.sid%TYPE := 22;  
  var_increment sailors.rating%TYPE := 5;  
BEGIN  
  proc_incr_rating(var_sno, var_increment);  
END; 
/

select rating from sailors where sid= 22;

CREATE TABLE Employee ( 
  empno NUMBER, 
  sal NUMBER, 
  comm NUMBER 
);

INSERT INTO Employee VALUES (1, 100, 10);

INSERT INTO Employee VALUES (2, 200, 20);

INSERT INTO Employee VALUES (3, 300, 30);

CREATEOR REPLACE FUNCTION func_revised_salary (p_empno NUMBER) 


RETURNNUMBER 


IS 


vincr employee.sal%TYPE; 


vnet employee.sal%TYPE; 


vempno employee.empno%TYPE; 


vsal employee.sal%TYPE; 


vcomm employee.comm%TYPE; 


BEGIN 
SELECT empno ,sal ,comm 
INTO vempno ,vsal ,vcomm 
FROMemployee 
WHERE empno=p_empno; 
vnet:=vsal+vcomm; 
IF vsal <=20000THEN 
vincr:=0.20*vnet; 
ELS IF vsal >20000 AND vsal <=30000 THEN 
vincr:=0.30*vnet; 
ELSE 
vincr:=0.40*vnet; 
END IF; 
END IF; 
RETURN (vincr+vsal); 
ENDfunc_revised_salary ; 
/

CREATEOR REPLACE FUNCTION func_revised_salary (p_empno NUMBER) 


RETURN NUMBER 


IS 


vincr employee.sal%TYPE; 


vnet employee.sal%TYPE; 


vempno employee.empno%TYPE; 


vsal employee.sal%TYPE; 


vcomm employee.comm%TYPE; 


BEGIN 
SELECT empno ,sal ,comm 
INTO vempno ,vsal ,vcomm 
FROM employee 
WHERE empno=p_empno; 
vnet:=vsal+vcomm; 
IF vsal <=20000 THEN 
vincr:=0.20*vnet; 
ELS IF vsal >20000 AND vsal <=30000 THEN 
vincr:=0.30*vnet; 
ELSE 
vincr:=0.40*vnet; 
END IF; 
END IF; 
RETURN (vincr+vsal); 
END func_revised_salary ; 
/

CREATE OR REPLACE FUNCTION func_revised_salary (p_empno NUMBER) 
RETURN NUMBER 
IS 
vincr employee.sal%TYPE; 
vnet employee.sal%TYPE; 
vempno employee.empno%TYPE; 
vsal employee.sal%TYPE; 
vcomm employee.comm%TYPE; 
BEGIN 
SELECT empno ,sal ,comm 
INTO vempno ,vsal ,vcomm 
FROM employee 
WHERE empno=p_empno; 
vnet:=vsal+vcomm; 
IF vsal <=20000 THEN 
vincr:=0.20*vnet; 
ELS IF vsal >20000 AND vsal <=30000 THEN 
vincr:=0.30*vnet; 
ELSE 
vincr:=0.40*vnet; 
END IF; 
END IF; 
RETURN (vincr+vsal); 
END func_revised_salary ; 
/

CREATE OR REPLACE FUNCTION func_revised_salary (p_empno NUMBER) 
RETURN NUMBER 
IS 
vincr employee.sal%TYPE; 
vnet employee.sal%TYPE; 
vempno employee.empno%TYPE; 
vsal employee.sal%TYPE; 
vcomm employee.comm%TYPE; 
BEGIN 
SELECT empno ,sal ,comm 
INTO vempno ,vsal ,vcomm 
FROM employee 
WHERE empno=p_empno; 
vnet:=vsal+vcomm; 
IF vsal <=20000 THEN 
vincr:=0.20*vnet; 
ELSE IF vsal >20000 AND vsal <=30000 THEN 
vincr:=0.30*vnet; 
ELSE 
vincr:=0.40*vnet; 
END IF; 
END IF; 
RETURN (vincr+vsal); 
END func_revised_salary ; 
/

select empno,sal,func_revised_salary(empno), comm from employee;

DECLARE 
v_incr_sal NUMBER(7,2); 
BEGIN 
v_incr_sal := proc_revised_salary(2); 
DBMS_OUTPUT.PUT_LINE('incremented salary is:'||v_incr_sal); 
END; 
/

DECLARE 
v_incr_sal NUMBER(7,2); 
BEGIN 
v_incr_sal := func_revised_salary(2); 
DBMS_OUTPUT.PUT_LINE('incremented salary is:'||v_incr_sal); 
END; 
/

insertinto employee values(4,400,NULL); 


insertinto employee values(5,500,NULL);


insert into employee values(4,400,NULL);

insert into employee values(5,500,NULL);

CREATE FUNCTION func_retrn_comm(p_empno NUMBER) 
RETURN NUMBER 
IS 
vincr employee.sal%TYPE; 
vnet employee.sal%TYPE; 
vempno employee.empno%TYPE; 
vsal employee.sal%TYPE; 
vcomm employee.comm%TYPE; 
BEGIN 
SELECT empno , sal ,NVL(comm,0) 
INTO vempno ,vsal ,vcomm 
FROM employee 
WHERE empno=p_empno; 
RETURN(vcomm); 
END func_retrn_comm; 
/

select e.empno, e.sal,func_revised_salary(e.empno), e.comm 
from employee e 
where e.comm=func_retrn_comm(5);

drop procedure proc_incr_rating


DROP FUNCTION proc_revised_salary


DROP FUNCTION func_revised_salary


CURSOR v_sailor_cursor IS 


SELECT sid,sname,rating,age 
FROM sailors ORDER BY sid;

OPEN v_sailor_cursor;


FETCH v_sailor_cursor 


INTO v_sailor_id, v_name, v_rating,v_age;


CURSOR v_sailor_cursor IS 


SELECT sid,sname,rating,age 
FROM sailors ORDER BY sid;

CURSOR v_sailor_cursor IS 


   SELECT sid,sname,rating,age 
   FROM sailors ORDER BY sid;

CURSOR v_sailor_cursor IS SELECT sid,sname,rating,age FROM sailors ORDER BY sid;


CURSOR v_sailor_curso IS SELECT sid,sname,rating,age FROM sailors ORDER BY sid;


CURSOR v_sailor_curso IS SELECT sid,sname,rating,age FROM sailors ORDER BY sid; 


OPEN v_sailor_cursor;


CURSOR v_sailor_cursor IS 


  SELECT sid, sname, rating, age 
  FROM sailors 
  ORDER BY sid;

CURSOR v_sailor_cursor IS 


  SELECT sid, sname, rating, age 
  FROM sailors 
  ORDER BY sid;

OPEN v_sailor_cursor; 


CURSOR v_sailor_cursor IS 


  SELECT sid, sname, rating, age 
  FROM sailors 
  ORDER BY sid 
OPEN v_sailor_cursor;

DECLARE 
v_sailor_id sailors.sid%TYPE; 
v_name sailors.sname%TYPE; 
v_rating sailors.rating%TYPE; 
v_age sailors.age%TYPE; 
CURSOR v_sailor_cursor IS 
SELECT sid,sname,rating,age 
FROM sailors 
ORDER BY sid; 
 
BEGIN 
OPENv_sailor_cursor; 
LOOP 
FETCH v_sailor_cursor 
INTO v_sailor_id, v_name, v_rating,v_age; 
EXIT WHEN v_sailor_cursor%NOTFOUND; 
DBMS_OUTPUT.PUT_LINE( 'v_sailor_id = ' || v_sailor_id || ', v_name = ' || v_name || ', v_rating = ' || v_rating||', v_age = ' || v_age); 
 
END LOOP; 
CLOSEv_sailor_cursor; 
END; 
/

DECLARE 
v_sailor_id sailors.sid%TYPE; 
v_name sailors.sname%TYPE; 
v_rating sailors.rating%TYPE; 
v_age sailors.age%TYPE; 
CURSOR v_sailor_cursor IS 
SELECT sid,sname,rating,age 
FROM sailors 
ORDER BY sid; 
 
BEGIN 
OPEN v_sailor_cursor; 
LOOP 
FETCH v_sailor_cursor 
INTO v_sailor_id, v_name, v_rating,v_age; 
EXIT WHEN v_sailor_cursor%NOTFOUND; 
DBMS_OUTPUT.PUT_LINE( 'v_sailor_id = ' || v_sailor_id || ', v_name = ' || v_name || ', v_rating = ' || v_rating||', v_age = ' || v_age); 
 
END LOOP; 
CLOSEv_sailor_cursor; 
END; 
/

DECLARE 
v_sailor_id sailors.sid%TYPE; 
v_name sailors.sname%TYPE; 
v_rating sailors.rating%TYPE; 
v_age sailors.age%TYPE; 
CURSOR v_sailor_cursor IS 
SELECT sid,sname,rating,age 
FROM sailors 
ORDER BY sid; 
 
BEGIN 
OPEN v_sailor_cursor; 
LOOP 
FETCH v_sailor_cursor 
INTO v_sailor_id, v_name, v_rating,v_age; 
EXIT WHEN v_sailor_cursor%NOTFOUND; 
DBMS_OUTPUT.PUT_LINE( 'v_sailor_id = ' || v_sailor_id || ', v_name = ' || v_name || ', v_rating = ' || v_rating||', v_age = ' || v_age); 
 
END LOOP; 
CLOSE v_sailor_cursor; 
END; 
/

 CREATE TABLE TempInfo ( 
 name VARCHAR2(20), 
 rec_date DATE, 
 age NUMBER(3,1) 
);

 SET SERVEROUTPUT ON SIZE 1000000


 DECLARE 
 v_sailor_id sailors.sid%TYPE; 
 v_name sailors.sname%TYPE; 
 v_rating sailors.rating%TYPE; 
 v_age sailors.age%TYPE; 
 CURSOR v_sailor_cursor IS 
 SELECT sid, sname, rating, age FROM sailors ORDER BY sid DESC; 
 BEGIN 
 OPEN v_sailor_cursor; 
 IF v_sailor_cursor%ISOPEN THEN 
 LOOP 
 FETCH v_sailor_cursor INTO v_sailor_id, v_name, v_rating, v_age; 
 EXIT WHEN v_sailor_cursor%NOTFOUND; 
DBMS_OUTPUT.PUT_LINE('v_sailor_id = ' || v_sailor_id || ', v_name = ' || v_name ||', v_rating = ' || v_rating || ', v_age = ' || v_age); 
INSERT INTO TempInfo VALUES (v_name, SYSDATE, v_age); 
END LOOP; 
COMMIT; 
 CLOSE v_sailor_cursor; 
 ELSE 
DBMS_OUTPUT.PUT_LINE('Unable to open the cursor'); 
 END IF; 
 END; 
/

 CREATE TABLE TempInfo ( 
 name VARCHAR2(20), 
 rec_date DATE, 
 age NUMBER(3,1) 
);

 DECLARE 
 v_sailor_id sailors.sid%TYPE; 
 v_name sailors.sname%TYPE; 
 v_rating sailors.rating%TYPE; 
 v_age sailors.age%TYPE; 
 CURSOR v_sailor_cursor IS 
 SELECT sid, sname, rating, age FROM sailors ORDER BY sid DESC; 
 BEGIN 
 OPEN v_sailor_cursor; 
 IF v_sailor_cursor%ISOPEN THEN 
 LOOP 
 FETCH v_sailor_cursor INTO v_sailor_id, v_name, v_rating, v_age; 
 EXIT WHEN v_sailor_cursor%NOTFOUND; 
DBMS_OUTPUT.PUT_LINE('v_sailor_id = ' || v_sailor_id || ', v_name = ' || v_name ||', v_rating = ' || v_rating || ', v_age = ' || v_age); 
INSERT INTO TempInfo VALUES (v_name, SYSDATE, v_age); 
END LOOP; 
COMMIT; 
 CLOSE v_sailor_cursor; 
 ELSE 
DBMS_OUTPUT.PUT_LINE('Unable to open the cursor'); 
 END IF; 
 END; 
/

 CREATE TABLE TempInfo ( 
 name VARCHAR2(20), 
 rec_date DATE, 
 age NUMBER(3,1) 
);

 DECLARE 
 v_sailor_id sailors.sid%TYPE; 
 v_name sailors.sname%TYPE; 
 v_rating sailors.rating%TYPE; 
 v_age sailors.age%TYPE; 
 CURSOR v_sailor_curso IS 
 SELECT sid, sname, rating, age FROM sailors ORDER BY sid DESC; 
 BEGIN 
 OPEN v_sailor_curso; 
 IF v_sailor_curso%ISOPEN THEN 
 LOOP 
 FETCH v_sailor_curso INTO v_sailor_id, v_name, v_rating, v_age; 
 EXIT WHEN v_sailor_curso%NOTFOUND; 
DBMS_OUTPUT.PUT_LINE('v_sailor_id = ' || v_sailor_id || ', v_name = ' || v_name ||', v_rating = ' || v_rating || ', v_age = ' || v_age); 
INSERT INTO TempInfo VALUES (v_name, SYSDATE, v_age); 
END LOOP; 
COMMIT; 
 CLOSE v_sailor_curso; 
 ELSE 
DBMS_OUTPUT.PUT_LINE('Unable to open the cursor'); 
 END IF; 
 END; 
/

 CREATE TABLE TempInfo ( 
 name VARCHAR2(20), 
 rec_date DATE, 
 age NUMBER(3,1) 
);

 SET SERVEROUTPUT ON SIZE 1000000


 DECLARE 
 v_sailor_id sailors.sid%TYPE; 
 v_name sailors.sname%TYPE; 
 v_rating sailors.rating%TYPE; 
 v_age sailors.age%TYPE; 
 CURSOR v_sailor_cursor IS 
 SELECT sid, sname, rating, age FROM sailors ORDER BY sid DESC; 
 BEGIN 
 OPEN v_sailor_cursor; 
 IF v_sailor_cursor%ISOPEN THEN 
 LOOP 
 FETCH v_sailor_cursor INTO v_sailor_id, v_name, v_rating, v_age; 
 EXIT WHEN v_sailor_cursor%NOTFOUND; 
DBMS_OUTPUT.PUT_LINE('v_sailor_id = ' || v_sailor_id || ', v_name = ' || v_name ||', v_rating = ' || v_rating || ', v_age = ' || v_age); 
INSERT INTO TempInfo VALUES (v_name, SYSDATE, v_age); 
END LOOP; 
COMMIT; 
 CLOSE v_sailor_cursor; 
 ELSE 
DBMS_OUTPUT.PUT_LINE('Unable to open the cursor'); 
 END IF; 
 END; 
/

SET SERVEROUTPUT ON SIZE 1000000


DECLARE 
  v_name sailors.sname%TYPE; 
  v_rec_date TempInfo.rec_date%TYPE; 
  v_age sailors.age%TYPE; 
   
  CURSOR v_sailor_cursor IS 
    SELECT sname, SYSDATE, age 
    FROM sailors 
    ORDER BY sid DESC; 
 
BEGIN 
  OPEN v_sailor_cursor; 
   
  IF v_sailor_cursor%ISOPEN THEN 
    LOOP 
      FETCH v_sailor_cursor INTO v_name, v_rec_date, v_age; 
      EXIT WHEN v_sailor_cursor%NOTFOUND; 
      DBMS_OUTPUT.PUT_LINE('v_name = ' || v_name ||', v_rec_date = ' || v_rec_date || ', v_age = ' || v_age); 
      INSERT INTO TempInfo VALUES (v_name, v_rec_date, v_age); 
    END LOOP; 
    COMMIT; 
    CLOSE v_sailor_cursor; 
  ELSE 
    DBMS_OUTPUT.PUT_LINE('Unable to open the cursor'); 
  END IF; 
END; 
/

select * from TempInfo;

drop table TempInfo


CREATE TABLE TempInfo ( 
name VARCHAR2(20), 
rec_date DATE, 
age NUMBER(3,1) 
);

SET SERVEROUTPUT ON SIZE 1000000


DECLARE 
  v_name sailors.sname%TYPE; 
  v_rec_date TempInfo.rec_date%TYPE; 
  v_age sailors.age%TYPE; 
   
  CURSOR v_sailor_cursor IS 
    SELECT sname, SYSDATE, age 
    FROM sailors 
    ORDER BY sid DESC; 
 
BEGIN 
  OPEN v_sailor_cursor; 
   
  IF v_sailor_cursor%ISOPEN THEN 
    LOOP 
      FETCH v_sailor_cursor INTO v_name, v_rec_date, v_age; 
      EXIT WHEN v_sailor_cursor%NOTFOUND; 
      DBMS_OUTPUT.PUT_LINE('v_name = ' || v_name ||', v_rec_date = ' || v_rec_date || ', v_age = ' || v_age); 
      INSERT INTO TempInfo VALUES (v_name, v_rec_date, v_age); 
    END LOOP; 
    COMMIT; 
    CLOSE v_sailor_cursor; 
  ELSE 
    DBMS_OUTPUT.PUT_LINE('Unable to open the cursor'); 
  END IF; 
END; 
/

select * from TempInfo;

DECLARE 
v_sailor_id sailors.sid%TYPE; 
v_rating sailors.rating%TYPE; 
CURSOR v_sailor_cursor IS SELECT sid, sname,rating,age FROM sailors; 
BEGIN 
 
OPEN v_sailor_cursor; 
DBMS_OUTPUT.PUT_LINE('SID Rating '); 
DBMS_OUTPUT.PUT_LINE('------ --------' ); 
LOOP 
FETCH v_sailor_cursor INTO v_sailor_id, v_rating; 
EXIT WHEN v_sailor_cursor %ROWCOUNT >4 OR v_sailor_cursor%NOTFOUND; 
DBMS_OUTPUT.PUT_LINE( v_sailor_id || ' ' || v_rating); 
END LOOP; 
CLOSEv_sailor_cursor; 
END; 
/

DECLARE 
v_sailor_id sailors.sid%TYPE; 
v_rating sailors.rating%TYPE; 
CURSOR v_sailor_cursor IS SELECT sid, sname,rating,age FROM sailors; 
BEGIN 
 
OPEN v_sailor_cursor; 
DBMS_OUTPUT.PUT_LINE('SID Rating '); 
DBMS_OUTPUT.PUT_LINE('------ --------' ); 
LOOP 
FETCH v_sailor_cursor INTO v_sailor_id, v_rating; 
EXIT WHEN v_sailor_cursor %ROWCOUNT >4 OR v_sailor_cursor%NOTFOUND; 
DBMS_OUTPUT.PUT_LINE( v_sailor_id || ' ' || v_rating); 
END LOOP; 
CLOSE v_sailor_cursor; 
END; 
/

 SET SERVEROUTPUT ON SIZE 1000000


 DECLARE 
 v_sailor_id sailors.sid%TYPE; 
 v_rating sailors.rating%TYPE; 
CURSOR v_sailor_cursor IS 
 SELECT sid, rating FROM sailors; 
 BEGIN 
 OPEN v_sailor_cursor; 
 DBMS_OUTPUT.PUT_LINE('SID Rating'); 
 DBMS_OUTPUT.PUT_LINE('----- ------'); 
LOOP 
 FETCH v_sailor_cursor INTO v_sailor_id, v_rating; 
EXIT WHEN v_sailor_cursor%ROWCOUNT > 4 OR v_sailor_cursor%NOTFOUND; 
DBMS_OUTPUT.PUT_LINE(v_sailor_id || ' ' || v_rating); 
 END LOOP; 
 CLOSE v_sailor_cursor; 
END; 
/

create table products( 
product_id INTEGER PRIMARY KEY, 
product_price number(5,2) 
);

create table product_price_audit( 
product_idINTEGERCONSTRAINTprice_audit_fk_productsREFERENCES 
products(product_id), 
old_priceNUMBER(5,2), 
new_price NUMBER(5,2) 
);

create table product_price_audit( 
product_id INTEGER CONSTRAINT price_audit_fk_products REFERENCES products(product_id), 
old_price NUMBER(5,2), 
new_price NUMBER(5,2) 
);

CREATE TRIGGER before_product_price_update 
BEFORE UPDATE OF product_price 
ON products 
FOR EACH ROW WHEN (new.product_price < old.product_price * 0.75) 
BEGIN 
dbms_output.put_line('product_id = ' ||:old.product_id); 
dbms_output.put_line('Old price = ' || :old.product_price); 
dbms_output.put_line('New price = ' || :new.product_price); 
dbms_output.put_line('The price reduction ismore than 25%'); 
INSERT INTO product_price_audit (product_id, old_price, new_price) VALUES(:old.product_id,:old.product_price,:new.product_price); 
END before_product_price_update; 
/

insert into products values(515.99);

insertintoproducts values(1049.99);


INSERT INTO products VALUES (1, 515.99);

INSERT INTO products VALUES (2, 1049.99);

INSERT INTO products VALUES (1, 515.99);

INSERT INTO products VALUES (2, 104.99);

UPDATE products_temp 
SET product_price = product_price * .7 
WHERE product_id IN (5, 10);

UPDATE products_temp 
SET product_price = product_price * .7 
WHERE product_id IN (1, 2);

select * from products;

UPDATE products 
 
SET product_price = product_price * .7 
WHERE product_id IN (5, 10);

UPDATE products 
 
SET product_price = product_price * .7 
WHERE product_id IN (1, 2);

DECLARE 
CURSOR emp_cur IS 
SELECT Ename,empid,salary FROM emp_tbl; 
 
emp_rec emp_cur%rowtype; 
BEGIN 
FOR emp_rec in emp_cur 
LOOP 
dbms_output.put_line(emp_cur.first_name||''||emp_cur.last_name||emp_cur.sal 
ary); 
END LOOP; 
END; 
/

CREATE TABLE EMP_TBL ( 
Ename VARCHAR2(50), 
 empid NUMBER, 
salary NUMBER(8, 2) 
);

 INSERT INTO EMP_TBL (Ename, empid, salary) VALUES ('John', 101, 50000.00);

INSERT INTO EMP_TBL (Ename, empid, salary) VALUES ('Jane', 102, 55000.00);

INSERT INTO EMP_TBL (Ename, empid, salary) VALUES ('Bob', 103, 60000.00);

 INSERT INTO EMP_TBL (Ename, empid, salary) VALUES ('Alice', 104, 52000.00);

 COMMIT;

 SET SERVEROUTPUT ON SIZE 1000000


 DECLARE 
 CURSOR emp_cur IS 
 SELECT Ename, empid, salary FROM EMP_TBL; 
 emp_rec emp_cur%ROWTYPE; 
 BEGIN 
 FOR emp_rec IN emp_cur 
 LOOP 
 DBMS_OUTPUT.PUT_LINE(emp_rec.Ename || ' ' || emp_rec.empid || ' ' || emp_rec.salary); 
 END LOOP; 
 END; 
/

 /


SET SERVEROUTPUT ON SIZE 1000000


DECLARE 
CURSOR sail_cur 
IS 
SELECT sname, rating 
FROM sailors WHERE age>30 
ORDER BY rating DESC; 
 
BEGIN 
FOR sail_rec IN sail_cur 
LOOP 
DBMS_OUTPUT.PUT_LINE 
('Sailor: ' || sail_rec.sname || ' have ratings ' || sail_rec.rating||'and age'||' sail_rec.age'); 
 
END LOOP; 
END; 
/

CREATE TABLE StoreFact ( 
NO NUMBER, 
fact NUMBER 
);

INSERT INTO StoreFact (NO) VALUES (5);

INSERT INTO StoreFact (NO) VALUES (7);

INSERT INTO StoreFact (NO) VALUES (3);

INSERT INTO StoreFact (NO) VALUES (10);

COMMIT;

BEGIN 
DBMS_OUTPUT.PUT_LINE('Data inserted into StoreFact table successfully.'); 
END; 
/

SET SERVEROUTPUT ON SIZE 1000000


DECLARE 
CURSOR f_cur IS SELECT NO FROM StoreFact; 
n_counter StoreFact.NO%TYPE; 
n_factorial NUMBER := 1; 
n_temp NUMBER; 
BEGIN 
OPEN f_cur; 
LOOP 
FETCH f_cur INTO n_counter; 
EXIT WHEN f_cur%NOTFOUND; 
DBMS_OUTPUT.PUT_LINE('No Fetched: ' || n_counter); 
n_temp := n_counter; 
n_factorial := 1; 
-- Calculate factorial 
WHILE n_counter > 0 LOOP 
n_factorial := n_factorial * n_counter; 
n_counter := n_counter - 1; 
END LOOP; 
IF n_factorial < 500 THEN 
DBMS_OUTPUT.PUT_LINE('Factorial of ' || n_temp || ' is ' || n_factorial); 
ELSE 
-- Update the fact column in StoreFact table 
UPDATE StoreFact SET fact = n_factorial WHERE NO = n_temp; 
DBMS_OUTPUT.PUT_LINE('Factorial inserted into table StoreFact for ' || n_temp); 
END IF; 
END LOOP; 
CLOSE f_cur; 
COMMIT; -- Commit the changes to the table 
END; 
/

SET SERVEROUTPUT ON SIZE 1000000


CREATE OR REPLACE FUNCTION CalculateFactorial(n IN NUMBER) RETURN NUMBER IS 
n_factorial NUMBER := 1; 
BEGIN 
FOR i IN 1..n LOOP 
n_factorial := n_factorial * i; 
END LOOP; 
RETURN n_factorial; 
END CalculateFactorial; 
/

DECLARE 
CURSOR f_cur IS SELECT NO FROM StoreFact; 
n_counter StoreFact.NO%TYPE; 
n_temp NUMBER; 
BEGIN 
OPEN f_cur; 
LOOP 
FETCH f_cur INTO n_counter; 
EXIT WHEN f_cur%NOTFOUND; 
DBMS_OUTPUT.PUT_LINE('No Fetched: ' || n_counter);      
n_temp := n_counter;      
-- Calculate factorial using the function 
DECLARE 
n_factorial NUMBER; 
BEGIN 
n_factorial := CalculateFactorial(n_temp);          
IF n_factorial < 500 THEN 
DBMS_OUTPUT.PUT_LINE('Factorial of ' || n_temp || ' is ' || n_factorial); 
ELSE 
-- Update the fact column in StoreFact table 
UPDATE StoreFact SET fact = n_factorial WHERE NO = n_temp; 
DBMS_OUTPUT.PUT_LINE('Factorial inserted into table StoreFact for ' || n_temp); 
END IF; 
END; 
END LOOP; 
CLOSE f_cur; 
COMMIT; -- Commit the changes to the table 
END; 
/

drop table sailors


CREATE TABLE SAILORS ( 
sid NUMBER(3), 
sname VARCHAR2(20) NOT NULL, 
rating NUMBER(2) NOT NULL, 
age NUMBER(3, 1), 
CONSTRAINT pk_sailors PRIMARY KEY (sid) 
);

INSERT INTO SAILORS VALUES (22, 'Dustin', 7, 45.0);

INSERT INTO SAILORS VALUES (29, 'Brutus', 1, 33.0);

INSERT INTO SAILORS VALUES (31, 'Lubber', 8, 55.5);

INSERT INTO SAILORS VALUES (32, 'Andy', 8, 25.5);

INSERT INTO SAILORS VALUES (58, 'Rusty', 10, 35.0);

INSERT INTO SAILORS VALUES (64, 'Horatio', 7, 35.0);

INSERT INTO SAILORS VALUES (71, 'Zorba', 10, 16.0);

INSERT INTO SAILORS VALUES (74, 'Horatio', 9, 35.0);

INSERT INTO SAILORS VALUES (85, 'Art', 3, 25.5);

INSERT INTO SAILORS VALUES (95, 'Bob', 3, 63.5);

COMMIT;

CREATE OR REPLACE TRIGGER CheckSailorRating 
BEFORE INSERT OR UPDATE OR DELETE ON SAILORS 
FOR EACH ROW 
BEGIN 
IF INSERTING THEN 
-- Allow insertion if the new rating is greater than 5 
IF :NEW.rating <= 5 THEN 
-- Raise an error message for violation 
RAISE_APPLICATION_ERROR(-20001, 'Sailor rating must be greater than 5 for insertion.'); 
END IF; 
ELSE 
-- Disallow updates and deletions 
RAISE_APPLICATION_ERROR(-20002, 'Updates and deletions are not allowed on the SAILORS table.'); 
END IF; 
END; 
/

INSERT INTO SAILORS VALUES (88, 'Art_DUP', 3,28.8);

INSERT INTO SAILORS VALUES (88, 'Art_DUP', 6,28.8);

CREATE OR REPLACE PROCEDURE findName(tsid IN NUMBER, name OUT VARCHAR2) IS 
BEGIN 
SELECT sname INTO name 
FROM SAILORS 
WHERE sid = tsid; 
EXCEPTION 
WHEN NO_DATA_FOUND THEN 
name := NULL; -- No matching sailor found 
END findName; 
/

DECLARE 
tm_sid NUMBER(3); 
tname VARCHAR2(12); 
BEGIN 
tm_sid := 22; 
findName(tm_sid, tname); 
DBMS_OUTPUT.PUT_LINE(tname); 
END; 
/

CREATE OR REPLACE FUNCTION FindName2(tsid IN NUMBER) RETURN VARCHAR2 IS 
tname VARCHAR2(12); 
BEGIN 
SELECT sname INTO tname 
FROM SAILORS 
WHERE sid = tsid; 
 
RETURN tname; 
EXCEPTION 
WHEN NO_DATA_FOUND THEN 
RETURN NULL; -- No matching sailor found 
END FindName2; 
/

SET SERVEROUTPUT ON SIZE 1000000


DECLARE 
tm_sid NUMBER(3); 
tname VARCHAR2(12); 
BEGIN 
tm_sid := 22; 
tname := FindName2(tm_sid); -- Call the function and store the result in tname 
dbms_output.put_line(tname); 
END; 
/

CREATE OR REPLACE PROCEDURE DisplaySailorDetails(sailor_name IN VARCHAR2) IS 
BEGIN 
    FOR sailor_rec IN ( 
        SELECT * 
        FROM SAILORS 
        WHERE sname = sailor_name 
    ) LOOP 
        DBMS_OUTPUT.PUT_LINE('Sailor ID: ' || sailor_rec.sid); 
        DBMS_OUTPUT.PUT_LINE('Sailor Name: ' || sailor_rec.sname); 
        DBMS_OUTPUT.PUT_LINE('Sailor Rating: ' || sailor_rec.rating); 
        DBMS_OUTPUT.PUT_LINE('Sailor Age: ' || sailor_rec.age); 
        DBMS_OUTPUT.PUT_LINE('----------------------------------'); 
    END LOOP; 
EXCEPTION 
    WHEN NO_DATA_FOUND THEN 
        DBMS_OUTPUT.PUT_LINE('No sailor found with the name ' || sailor_name); 
END DisplaySailorDetails; 
/

SET SERVEROUTPUT ON SIZE 1000000


DECLARE 
sailor_name VARCHAR2(20) := 'Dustin'; -- Replace with the sailor's name you want to search for 
BEGIN 
DisplaySailorDetails(sailor_name); 
END; 
/

SELECT TO_CHAR(SYSDATE, 'Dy DD-Mon-YYYY HH24:MI:SS') AS "Current Time" FROM dual;

SELECT LEAST(DATE '2013-01-23', DATE '2006-12-24') FROM DUAL;

SELECT GREATEST(DATE '2013-01-23', DATE '2006-12-24') FROM DUAL;

SELECT MONTHS_BETWEEN(SYSDATE,TO_DATE('23-JAN-2006', 'DD-MON-YYYY')) FROM DUAL;

SELECT ADD_MONTHS(sysdate,3) FROM Dual;

SELECT LAST_DAY(SYSDATE)+1 FROM DUAL;

CREATE TABLE students ( 
    Idno CHAR(12), 
    Name VARCHAR2(15), 
    DoB DATE, 
    CGPA NUMBER(4, 2), 
    Age NUMBER(3) 
 );

INSERT INTO students (Idno, Name, DoB, CGPA, Age) 
VALUES ('2015H112151P', 'Sagun_Sinha', TO_DATE('1985-08-21', 'YYYY-MM-DD'), 8.5, 26);

create view vw_student as select * from students;

create view vw1_student as 
select Idno "identityno", Name "studentname" from students;

DESC vw1_student


DESC vw_student


select Idno,Name from vw_student;

INSERT INTO vw_student (Idno, Name, DoB, CGPA, Age) 
VALUES ('2004C6PS123', 'rohit', TO_DATE('05-04-1999', 'DD-MM-YYYY'), 8.00, 24);

update vw_student set name='mohit' where name='rohit';

DESC vw_student


select * from vw_student;

delete from vw_student where name='mohit';

select * from vw_student;

CREATE TABLE DEPT ( 
    deptname VARCHAR2(15), 
    deptno NUMBER(2) PRIMARY KEY, 
    addr VARCHAR2(20), 
    city VARCHAR2(15) 
);

CREATE TABLE EMP ( 
    eid VARCHAR2(10) PRIMARY KEY, 
    ename VARCHAR2(20), 
    salary NUMBER(5), 
    deptno NUMBER(2), 
    FOREIGN KEY (deptno) REFERENCES DEPT(deptno) 
);

create view vw_emp as select eid, ename,salary, emp.deptno, deptname, addr, city 
 
from EMP,DEPT 
 
where EMP.deptno=DEPT.deptno;

insert into vw_emp values('2008CH1234','ramesh',10000,10,'CSIS','BITS','PILANI');

update vw_emp set ename ='mohit' where deptno=10;

delete from vw_emp where deptno=10;

drop view vw1_student


insert into emp (eid,ename,salary) values(109,'Sami',3000);

savepoint a


insert into emp (eid,ename,salary) values(110,'Mounika',3001);

savepoint b


insert into emp (eid,ename,salary) values(111,'Kashyap', 3002);

rollback to a ;

RELEASE SAVEPOINT a; 


commit;

grant privileges on object to user


grant select, insert, update, delete on suppliers to smithj


grant all on suppliers to smithj


grant select on suppliers to public


revoke privileges on object from user


revoke delete on suppliers from anderson


revoke all on suppliers from anderson


revoke all on suppliers from public


grant execute on object to user


grant execute on Find_Value to smithj


grant execute on Find_Value to public


revoke execute on object from user


revoke execute on Find_Value from anderson


revoke execute on Find_Value from public


