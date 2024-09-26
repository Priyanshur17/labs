CREATE TABLE SAILORS (
sid integer(3),
sname VARCHAR(20) NOT NULL,
rating integer(2) NOT NULL,
age float(3,1),
CONSTRAINT pk_sailors PRIMARY KEY(sid)
);

CREATE TABLE BOATS (
bid integer(3),
bname VARCHAR(12) NOT NULL,
color VARCHAR(8) NOT NULL,
CONSTRAINT pk_boats PRIMARY KEY(bid)
);

CREATE TABLE RESERVES
( sid integer(3),
bid integer(3),
day DATE,
CONSTRAINT pk_reserves PRIMARY KEY(sid,bid) ,
CONSTRAINT fk_sailors FOREIGN KEY(sid) REFERENCES SAILORS(sid),
CONSTRAINT fk_boats FOREIGN KEY(bid) REFERENCES BOATS(bid)
);

insert into SAILORS VALUES (22,"Dustin",7,45.0);

insert into SAILORS VALUES (29,"Brutus",1,33.0);

insert into SAILORS VALUES (31,"Lubber",8,55.5);

insert into SAILORS VALUES (32,"Andy",8,25.5);

insert into SAILORS VALUES (58,"Rusty",10,35.0);

insert into SAILORS VALUES (64,"Horatio",7,35.0);

insert into SAILORS VALUES (71,"Zorba",10,16.0);

insert into SAILORS VALUES (74,"Horatio",9,35.0);

insert into SAILORS VALUES (85,"Art",3,25.5);

insert into SAILORS VALUES (95,"Bob",3,63.5);

insert into BOATS VALUES (101,"Interlake","blue");

insert into BOATS VALUES (102,"Interlake","red");

insert into BOATS VALUES (103,"Clipper","green");

insert into BOATS VALUES (104,"Marine","red");

insert into RESERVES VALUES (22,101,"1998-10-10");

insert into RESERVES VALUES (22,102, "1998-10-10");

insert into RESERVES VALUES (22,103, "1998-08-10");

insert into RESERVES VALUES (22,104, "1998-07-10");

insert into RESERVES VALUES (31,102, "1998-10-11");

insert into RESERVES VALUES (31,103, "1998-06-11");

insert into RESERVES VALUES (31,104, "1998-12-11");

insert into RESERVES VALUES (64,101, "1998-05-09");

insert into RESERVES VALUES (64,102, "1998-08-09");

insert into RESERVES VALUES (74,103, "1998-08-09");

CREATE TABLE SAILORS ( 
sid integer(3), 
sname VARCHAR(20) NOT NULL, 
rating integer(2) NOT NULL, 
age float(3,1), 
CONSTRAINT pk_sailors PRIMARY KEY(sid) 
);

CREATE TABLE BOATS ( 
bid integer(3), 
bname VARCHAR(12) NOT NULL, 
color VARCHAR(8) NOT NULL, 
CONSTRAINT pk_boats PRIMARY KEY(bid) 
);

CREATE TABLE RESERVES 
( sid integer(3), 
bid integer(3), 
day DATE, 
CONSTRAINT pk_reserves PRIMARY KEY(sid,bid) , 
CONSTRAINT fk_sailors FOREIGN KEY(sid) REFERENCES SAILORS(sid), 
CONSTRAINT fk_boats FOREIGN KEY(bid) REFERENCES BOATS(bid) 
);

insert into SAILORS VALUES (22,"Dustin",7,45.0);

insert into SAILORS VALUES (29,"Brutus",1,33.0);

insert into SAILORS VALUES (31,"Lubber",8,55.5);

insert into SAILORS VALUES (32,"Andy",8,25.5);

insert into SAILORS VALUES (58,"Rusty",10,35.0);

insert into SAILORS VALUES (64,"Horatio",7,35.0);

insert into SAILORS VALUES (71,"Zorba",10,16.0);

insert into SAILORS VALUES (74,"Horatio",9,35.0);

insert into SAILORS VALUES (85,"Art",3,25.5);

insert into SAILORS VALUES (95,"Bob",3,63.5);

insert into BOATS VALUES (101,"Interlake","blue");

insert into BOATS VALUES (102,"Interlake","red");

insert into BOATS VALUES (103,"Clipper","green");

insert into BOATS VALUES (104,"Marine","red");

insert into RESERVES VALUES (22,101,"1998-10-10");

insert into RESERVES VALUES (22,102, "1998-10-10");

insert into RESERVES VALUES (22,103, "1998-08-10");

insert into RESERVES VALUES (22,104, "1998-07-10");

insert into RESERVES VALUES (31,102, "1998-10-11");

insert into RESERVES VALUES (31,103, "1998-06-11");

insert into RESERVES VALUES (31,104, "1998-12-11");

insert into RESERVES VALUES (64,101, "1998-05-09");

insert into RESERVES VALUES (64,102, "1998-08-09");

insert into RESERVES VALUES (74,103, "1998-08-09");

CREATE TABLE SAILORS ( 
sid NUMBER(3), 
sname VARCHAR2(20) NOT NULL, 
rating NUMBER(2) NOT NULL, 
age NUMBER(3,1), 
CONSTRAINT pk_sailors PRIMARY KEY(sid) 
);

CREATE TABLE BOATS ( 
bid integer(3), 
bname VARCHAR(12) NOT NULL, 
color VARCHAR(8) NOT NULL, 
CONSTRAINT pk_boats PRIMARY KEY(bid) 
);

CREATE TABLE BOATS ( 
bid NUMBER(3), 
bname VARCHAR2(12) NOT NULL, 
color VARCHAR2(8) NOT NULL, 
CONSTRAINT pk_boats PRIMARY KEY(bid) 
);

CREATE TABLE RESERVES 
( sid NUMBER(3), 
bid NUMBER(3), 
day DATE, 
CONSTRAINT pk_reserves PRIMARY KEY(sid,bid) , 
CONSTRAINT fk_sailors FOREIGN KEY(sid) REFERENCES SAILORS(sid), 
CONSTRAINT fk_boats FOREIGN KEY(bid) REFERENCES BOATS(bid) 
);

CREATE TABLE RESERVES 
( sid NUMBER(3), 
bid NUMBER(3), 
day DATE, 
CONSTRAINT pk_reserves PRIMARY KEY(sid,bid) , 
CONSTRAINT fk_sailors FOREIGN KEY(sid) REFERENCES SAILORS(sid), 
CONSTRAINT fk_boats FOREIGN KEY(bid) REFERENCES BOATS(bid) 
);

CREATE TABLE RESERVES 
( sid NUMBER(3), 
bid NUMBER(3), 
day DATE, 
CONSTRAINT pk_reserves PRIMARY KEY(sid,bid) , 
CONSTRAINT fk_sailors FOREIGN KEY(sid) REFERENCES SAILORS(sid), 
CONSTRAINT fk_boats FOREIGN KEY(bid) REFERENCES BOATS(bid) 
);

CREATE TABLE RESERVES 
( sid NUMBER(3), 
bid NUMBER(3), 
day DATE, 
CONSTRAINT pk_reserves PRIMARY KEY(sid,bid) , 
CONSTRAINT fk_sailors FOREIGN KEY(sid) REFERENCES SAILORS(sid), 
CONSTRAINT fk_boats FOREIGN KEY(bid) REFERENCES BOATS(bid) 
);

insert into SAILORS VALUES (22,"Dustin",7,45.0);

select * from sailors;

select * from SAILORS;

drop tables 
 



insert into SAILORS VALUES (22,’Dustin’,7,45.0);

insert into SAILORS VALUES (29,’Brutus’,1,33.0);

insert into SAILORS VALUES (31,’Lubber’,8,55.5);

insert into SAILORS VALUES (32,’Andy’,8,25.5);

insert into SAILORS VALUES (58,’Rusty’,10,35.0);

insert into SAILORS VALUES (64,’Horatio’,7,35.0);

insert into SAILORS VALUES (71,’Zorba’,10,16.0);

insert into SAILORS VALUES (74,’Horatio’,9,35.0);

insert into SAILORS VALUES (85,’Art’,3,25.5);

insert into SAILORS VALUES (95,’Bob’,3,63.5);

nsert into SAILORS VALUES (22,"Dustin",7,45.0); 


insert into SAILORS VALUES (29,"Brutus",1,33.0);

insert into SAILORS VALUES (31,"Lubber",8,55.5);

insert into SAILORS VALUES (32,"Andy",8,25.5);

insert into SAILORS VALUES (58,"Rusty",10,35.0);

insert into SAILORS VALUES (64,"Horatio",7,35.0);

insert into SAILORS VALUES (71,"Zorba",10,16.0);

insert into SAILORS VALUES (74,"Horatio",9,35.0);

insert into SAILORS VALUES (85,"Art",3,25.5);

insert into SAILORS VALUES (95,"Bob",3,63.5);

insert into SAILORS VALUES (22,'Dustin',7,45.0);

insert into SAILORS VALUES (29,'Brutus',1,33.0);

insert into SAILORS VALUES (31,'Lubber',8,55.5);

insert into SAILORS VALUES (32,'Andy',8,25.5);

insert into SAILORS VALUES (58,'Rusty',10,35.0);

insert into SAILORS VALUES (64,'Horatio',7,35.0);

insert into SAILORS VALUES (71,'Zorba',10,16.0);

insert into SAILORS VALUES (74,'Horatio',9,35.0);

insert into SAILORS VALUES (85,'Art',3,25.5);

insert into SAILORS VALUES (95,'Bob',3,63.5);

select * from SAILORS;

insert into RESERVES VALUES (22,101,'1998-10-10');

insert into RESERVES VALUES (22,102, '1998-10-10');

insert into RESERVES VALUES (22,103, '1998-08-10');

insert into RESERVES VALUES (22,104, '1998-07-10');

insert into RESERVES VALUES (31,102, '1998-10-11');

insert into RESERVES VALUES (31,103, '1998-06-11');

insert into RESERVES VALUES (31,104, '1998-12-11');

insert into RESERVES VALUES (64,101, '1998-05-09');

insert into RESERVES VALUES (64,102, '1998-08-09');

insert into RESERVES VALUES (74,103, '1998-08-09');

insert into RESERVES VALUES (22,101,'1998-10-10');

insert into RESERVES VALUES (22,102, '1998-10-10');

insert into RESERVES VALUES (22,103, '1998-08-10');

insert into RESERVES VALUES (22,104, '1998-07-10');

insert into RESERVES VALUES (31,102, '1998-10-11');

insert into RESERVES VALUES (31,103, '1998-06-11');

insert into RESERVES VALUES (31,104, '1998-12-11');

insert into RESERVES VALUES (64,101, '1998-05-09');

insert into RESERVES VALUES (64,102, '1998-08-09');

insert into RESERVES VALUES (74,103, '1998-08-09');

insert into RESERVES VALUES (22,101,'1998-10-10');

insert into RESERVES VALUES (22,102, '1998-10-10');

insert into RESERVES VALUES (22,103, '1998-08-10');

insert into RESERVES VALUES (22,104, '1998-07-10');

insert into RESERVES VALUES (31,102, '1998-10-11');

insert into RESERVES VALUES (31,103, '1998-06-11');

insert into RESERVES VALUES (31,104, '1998-12-11');

insert into RESERVES VALUES (64,101, '1998-05-09');

insert into RESERVES VALUES (64,102, '1998-08-09');

insert into RESERVES VALUES (74,103, '1998-08-09');

insert into BOATS VALUES (101,'Interlake','blue');

insert into BOATS VALUES (102,'Interlake','red');

insert into BOATS VALUES (103,'Clipper','green');

insert into BOATS VALUES (104,'Marine','red');

insert into RESERVES VALUES (22,101,'1998-10-10');

insert into RESERVES VALUES (22,102, '1998-10-10');

insert into RESERVES VALUES (22,103, '1998-08-10');

insert into RESERVES VALUES (22,104, '1998-07-10');

insert into RESERVES VALUES (31,102, '1998-10-11');

insert into RESERVES VALUES (31,103, '1998-06-11');

insert into RESERVES VALUES (31,104, '1998-12-11');

insert into RESERVES VALUES (64,101, '1998-05-09');

insert into RESERVES VALUES (64,102, '1998-08-09');

insert into RESERVES VALUES (74,103, '1998-08-09');

insert into RESERVES VALUES (22,101,'1998-10-10');

insert into RESERVES VALUES (22,102, '1998-10-10');

insert into RESERVES VALUES (22,103, '1998-08-10');

insert into RESERVES VALUES (22,104, '1998-07-10');

insert into RESERVES VALUES (31,102, '1998-10-11');

insert into RESERVES VALUES (31,103, '1998-06-11');

insert into RESERVES VALUES (31,104, '1998-12-11');

insert into RESERVES VALUES (64,101, '1998-05-09');

insert into RESERVES VALUES (64,102, '1998-08-09');

insert into RESERVES VALUES (74,103, '1998-08-09');

select * from reserves;

DECLARE 
  var_rating number(4); tmpsid number(4) := 71; 
BEGIN 
   SELECT rating INTO var_rating FROM sailors WHERE sid = tmpsid; 
 
   dbms_output.put_line(var_rating); 
   dbms_output.put_line('The Sailor'||tmpsid||'has rating'||var_rating); 
END;
/

DECLARE 
salary_increase CONSTANT number(3); 
BEGIN 
salary_increase := 100; 
dbms_output.put_line (salary_increase); 
END; 
/

DECLARE 
salary_increase CONSTANT number(3); 
BEGIN 
salary_increase := 100; 
dbms_output.put_line (salary_increase); 
END; 
/

  var_rating number(4); tmpsid number(4) := 71


BEGIN 
   SELECT rating INTO var_rating FROM sailors WHERE sid = tmpsid; 
 
   dbms_output.put_line(var_rating); 
   dbms_output.put_line('The Sailor'||tmpsid||'has rating'||var_rating); 
END; 
 
DECLARE 
salary_increase CONSTANT number(3); 
BEGIN 
salary_increase := 100; 
dbms_output.put_line (salary_increase); 
END; 
/

  var_rating number(4); tmpsid number(4) := 71


BEGIN 
   SELECT rating INTO var_rating FROM sailors WHERE sid = tmpsid; 
 
   dbms_output.put_line(var_rating); 
   dbms_output.put_line('The Sailor'||tmpsid||'has rating'||var_rating); 
END; 
/

DECLARE 
salary_increase CONSTANT number(3); 
BEGIN 
salary_increase := 100; 
dbms_output.put_line (salary_increase); 
END; 
/

DECLARE 
  var_rating number(4); tmpsid number(4) := 71; 
BEGIN 
   SELECT rating INTO var_rating FROM sailors WHERE sid = tmpsid; 
 
   dbms_output.put_line(var_rating); 
   dbms_output.put_line('The Sailor'||tmpsid||'has rating'||var_rating); 
END; 
/

DECLARE 
salary_increase CONSTANT number(3); 
BEGIN 
salary_increase := 100; 
dbms_output.put_line (salary_increase); 
END; 
/

DECLARE 
salary_increase CONSTANT number(3); 
BEGIN 
salary_increase := 100; 
dbms_output.put_line (salary_increase); 
END; 
/

DECLARE 
  salary_increase CONSTANT number(3); 
BEGIN 
  salary_increase := 100; 
  dbms_output.put_line (salary_increase); 
END; 
/

DECLARE 
  salary_increase CONSTANT number(3); 
BEGIN 
  salary_increase := 100; 
  dbms_output.put_line (salary_increase); 
END; 
/

DECLARE 
  salary_increase CONSTANT number(3); 
BEGIN 
  salary_increase := 100; 
  dbms_output.put_line (salary_increase); 
END; 
/

DECLARE 
  salary_increase CONSTANT number(3); 
BEGIN 
  salary_increase := 100; 
  dbms_output.put_line (salary_increase); 
END; 
/

DECLARE 
  salary_increase CONSTANT number(3); 
BEGIN 
  salary_increase := 100; 
  dbms_output.put_line(salary_increase); 
END; 
/

DECLARE 
  salary_increase CONSTANT number(3); 
BEGIN 
  salary_increase := 100; 
  dbms_output.put_line(salary_increase); 
END; 
/

DECLARE 
v_width INTEGER; 
v_height INTEGER := 2; 
v_area INTEGER := 6; 
BEGIN 
v_width := v_area / v_height; 
DBMS_OUTPUT.PUT_LINE('v_width =' || v_width); 
EXCEPTION 
WHEN ZERO_DIVIDE THEN 
DBMS_OUTPUT.PUT_LINE('Division by zero'); 
END; 
/

createtable Employee( 


empno number, 


sal number, 


comm. number 


); 


v_empno employee.empno%TYPE;


createtable Employee( 


empno number, 


sal number, 


comm. number 


); 


v_empno employee.empno%TYPE;


createtable Employee( 


empno number, 


sal number, 


comm. number 


); 


v_empno employee.empno%TYPE;


create table Employee( 
empno number, 
sal number, 
comm. number 
);

v_empno employee.empno%TYPE;


DECLARE 
v_message VARCHAR2(50); 
v_count INTEGER := 2; 
v_area INTEGER := 6; 
BEGIN 
IF v_count > 0THEN 
v_message := 'v_countis positive'; 
IF v_area > 0THEN 
v_message := 'v_count and v_area are positive'; 
END IF; 
ELSIF v_count = 0 THEN 
v_message := 'v_count iszero'; 
ELSE 
END IF; 
v_message := 'v_countis negative'; 
DBMS_OUTPUT.PUT_LINE('v_message = ' || v_message); 
END; 
/

DECLARE 
v_message VARCHAR2(50); 
v_count INTEGER := 2; 
v_area INTEGER := 6; 
BEGIN 
IF v_count > 0 THEN 
v_message := 'v_countis positive'; 
IF v_area > 0 THEN 
v_message := 'v_count and v_area are positive'; 
END IF; 
ELSIF v_count = 0 THEN 
v_message := 'v_count iszero'; 
ELSE 
END IF; 
v_message := 'v_countis negative'; 
DBMS_OUTPUT.PUT_LINE('v_message = ' || v_message); 
END; 
/

DECLARE 
v_message VARCHAR2(50); 
v_count INTEGER := 2; 
v_area INTEGER := 6; 
BEGIN 
IF v_count > 0 THEN 
v_message := 'v_countis positive'; 
IF v_area > 0 THEN 
  v_message := 'v_count and v_area are positive'; 
END IF; 
ELSIF v_count = 0 THEN 
  v_message := 'v_count iszero'; 
ELSE 
END IF; 
    v_message := 'v_countis negative'; 
   DBMS_OUTPUT.PUT_LINE('v_message = ' || v_message); 
END; 
/

DECLARE 
v_message VARCHAR2(50); 
v_count INTEGER := 2; 
v_area INTEGER := 6; 
BEGIN 
IF v_count > 0 THEN 
v_message := 'v_countis positive'; 
IF v_area > 0 THEN 
  v_message := 'v_count and v_area are positive'; 
END IF; 
ELSIF v_count = 0 THEN 
  v_message := 'v_count iszero'; 
ELSE 
END IF; 
    v_message := 'v_countis negative'; 
   DBMS_OUTPUT.PUT_LINE('v_message = ' || v_message); 
END; 
/

DECLARE 
v_message VARCHAR2(50); 
v_count INTEGER := 2; 
v_area INTEGER := 6; 
BEGIN 
IF v_count > 0 THEN 
v_message := 'v_countis positive'; 
IF v_area > 0 THEN 
  v_message := 'v_count and v_area are positive'; 
END IF; 
ELSIF v_count = 0 THEN 
  v_message := 'v_count iszero'; 
ELSE 
END IF; 
    v_message := 'v_countis negative'; 
   DBMS_OUTPUT.PUT_LINE('v_message = ' || v_message); 
END; 
/

DECLARE 
v_message VARCHAR2(50); 
v_count INTEGER := 2; 
v_area INTEGER := 6; 
BEGIN 
IF v_count > 0 THEN 
v_message := 'v_countis positive'; 
IF v_area > 0 THEN 
  v_message := 'v_count and v_area are positive'; 
END IF; 
ELSIF v_count = 0 THEN 
  v_message := 'v_count iszero'; 
ELSE 
END IF; 
    v_message := 'v_countis negative'; 
   DBMS_OUTPUT.PUT_LINE('v_message = ' || v_message); 
END; 
/

DECLARE 
v_message VARCHAR2(50); 
v_count INTEGER := 2; 
v_area INTEGER := 6; 
BEGIN 
IF v_count > 0 THEN 
v_message := 'v_countis positive'; 
IF v_area > 0 THEN 
  v_message := 'v_count and v_area are positive'; 
END IF; 
ELSIF v_count = 0 THEN 
  v_message := 'v_count iszero'; 
ELSE 
END IF 
    v_message := 'v_countis negative'; 
   DBMS_OUTPUT.PUT_LINE('v_message = ' || v_message); 
END; 
/

DECLARE 
v_message VARCHAR2(50); 
v_count INTEGER := 2; 
v_area INTEGER := 6; 
BEGIN 
IF v_count > 0 THEN 
v_message := 'v_countis positive'; 
IF v_area > 0 THEN 
  v_message := 'v_count and v_area are positive'; 
END IF; 
ELSIF v_count = 0 THEN 
  v_message := 'v_count iszero'; 
ELSE 
END IF; 
    v_message := 'v_countis negative'; 
   DBMS_OUTPUT.PUT_LINE('v_message = ' || v_message); 
END; 
/

DECLARE 
   v_message VARCHAR2(50); 
   v_count INTEGER := 2; 
   v_area INTEGER := 6; 
BEGIN 
IF v_count > 0 THEN 
   v_message := 'v_countis positive'; 
IF v_area > 0 THEN 
  v_message := 'v_count and v_area are positive'; 
END IF; 
ELSIF v_count = 0 THEN 
  v_message := 'v_count iszero'; 
END IF; 
    v_message := 'v_countis negative'; 
   DBMS_OUTPUT.PUT_LINE('v_message = ' || v_message); 
END; 
/

DECLARE 
  v_counter NUMBER := 0; 
BEGIN 
   LOOP 
      v_counter := v_counter + 1; 
      DBMS_OUTPUT.PUT_LINE('v_counter ='||v_counter); 
      EXIT WHEN v_counter =5; 
   END LOOP; 
END; 
/

DECLARE 
v_counter NUMBER := 0; 
BEGIN 
   WHILE v_counter < 6 LOOP 
      v_counter := v_counter + 1; 
     DBMS_OUTPUT.PUT_LINE('v_counter ='||v_counter); 
   END LOOP; 
END; 
/

create table numtab ( 
    a number(2), 
    b number(2) 
);

insert into numtab values(3,2);

insert into numtab values(12,54);

DECLARE 
    x number; 
    y number; 
BEGIN 
   SELECT a, b INTO x , y FROM numtab WHERE a>3; 
 
  IF x=3 THEN 
      INSERT INTO numtab VALUES(y,x); 
  ELSE 
    INSERT INTO numtab VALUES( y+10,x+20); 
   dbms_output.put_line('inserted into table”); 
  ENDIF; 
END; 
/

DECLARE 
    x number; 
    y number; 
BEGIN 
   SELECT a, b INTO x , y FROM numtab WHERE a>3; 
 
  IF x=3 THEN 
      INSERT INTO numtab VALUES(y,x); 
  ELSE 
    INSERT INTO numtab VALUES( y+10,x+20); 
   dbms_output.put_line('inserted into table”); 
  ENDIF; 
END; 
/

DECLARE 
    x number; 
    y number; 
BEGIN 
   SELECT a, b INTO x , y FROM numtab WHERE a>3; 
 
  IF x=3 THEN 
      INSERT INTO numtab VALUES(y,x); 
  ELSE 
    INSERT INTO numtab VALUES( y+10,x+20); 
   dbms_output.put_line('inserted into table”); 
   ENDIF; 
END; 
/

INSERT INTO numtab (a, b) VALUES (1, 2);

INSERT INTO numtab (a, b) VALUES (3, 4);

INSERT INTO numtab (a, b) VALUES (5, 6);

DECLARE 
  x NUMBER; 
  y NUMBER; 
BEGIN 
  SELECT a, b INTO x, y 
  FROM numtab 
  WHERE a > 3; 
   
  IF x = 3 THEN 
    INSERT INTO numtab VALUES(y, x); 
  ELSE 
    INSERT INTO numtab VALUES(y + 10, x + 20); 
    dbms_output.put_line('Inserted into table.'); 
  END IF; 
END; 
/

DECLARE 
  x NUMBER; 
  y NUMBER; 
BEGIN 
  SELECT a, b INTO x, y 
  FROM numtab 
  WHERE a > 3; 
   
  IF x = 3 THEN 
    INSERT INTO numtab VALUES(y, x); 
  ELSE 
    INSERT INTO numtab VALUES(y + 10, x + 20); 
    dbms_output.put_line('Inserted into table.'); 
  END IF; 
END; 
/

DECLARE 
  x NUMBER; 
  y NUMBER; 
BEGIN 
  SELECT a, b INTO x, y 
  FROM numtab 
  WHERE a > 3; 
   
  IF x = 3 THEN 
    INSERT INTO numtab VALUES(y, x); 
  ELSE 
    INSERT INTO numtab VALUES(y + 10, x + 20); 
    dbms_output.put_line('Inserted into table.'); 
  END IF; 
END; 
/

DECLARE 
  x NUMBER; 
  y NUMBER; 
BEGIN 
  SELECT a, b INTO x, y 
  FROM numtab 
  WHERE a > 3; 
   
  IF x = 3 THEN 
    INSERT INTO numtab VALUES(y, x); 
  ELSE 
    INSERT INTO numtab VALUES(y + 10, x + 20); 
    dbms_output.put_line('Inserted into table.'); 
  END IF; 
END; 
/

DECLARE 
  x NUMBER; 
  y NUMBER; 
BEGIN 
  SELECT a, b INTO x, y FROM numtab WHERE a > 3; 
   
  IF x = 3 THEN 
    INSERT INTO numtab VALUES(y, x); 
  ELSE 
    INSERT INTO numtab VALUES(y + 10, x + 20); 
    dbms_output.put_line('Inserted into table.'); 
  END IF; 
END; 
/

DECLARE 
  x NUMBER; 
  y NUMBER; 
BEGIN 
  SELECT a, b INTO x, y FROM numtab WHERE a > 3; 
  IF x = 3 THEN 
    INSERT INTO numtab VALUES(y, x); 
  ELSE 
    INSERT INTO numtab VALUES(y + 10, x + 20); 
    dbms_output.put_line('Inserted into table.'); 
  END IF; 
END; 
/

DECLARE 
  x NUMBER; 
  y NUMBER; 
  CURSOR c_numtab IS 
    SELECT a, b  
    FROM numtab  
    WHERE a > 3; 
BEGIN 
  FOR rec IN c_numtab LOOP 
    x := rec.a; 
    y := rec.b; 
     
    IF x = 3 THEN 
      INSERT INTO numtab VALUES (y, x); 
    ELSE 
      INSERT INTO numtab VALUES (y + 10, x + 20); 
      dbms_output.put_line('Inserted into table.'); 
    END IF; 
  END LOOP; 
END; 
/

DECLARE 
v_counter NUMBER; 
BEGIN 
FOR v_counter IN 1..5 LOOP 
DBMS_OUTPUT.PUT_LINE( „v_counter :‟ ||v_counter); 
END LOOP; 
END; 
/

DECLARE 
v_counter NUMBER; 
BEGIN 
   FOR v_counter IN 1..5 LOOP 
     DBMS_OUTPUT.PUT_LINE( „v_counter :‟ ||v_counter); 
   END LOOP; 
END; 
/

DECLARE 
v_counter NUMBER; 
BEGIN 
   FOR v_counter IN 1..5 LOOP 
     DBMS_OUTPUT.PUT_LINE( 'v_counter :' ||v_counter); 
   END LOOP; 
END; 
/

DECLARE 
  v_counter NUMBER; 
BEGIN 
  FOR v_counter IN REVERSE 1..5 LOOP 
    DBMS_OUTPUT.PUT_LINE('v_counter: ' || v_counter); 
  END LOOP; 
END; 
/

DECLARE 
   inputNumber VARCHAR2(20) := '12345';  
   invertedNumber VARCHAR2(20) := '';  
   i NUMBER; 
 
BEGIN 
  
   FOR i IN REVERSE 1..LENGTH(inputNumber) LOOP 
      invertedNumber := invertedNumber || SUBSTR(inputNumber, i, 1); 
   END LOOP; 
 
   DBMS_OUTPUT.PUT_LINE('Inverted Number using FOR loop: ' || invertedNumber); 
 
    
   invertedNumber := ''; 
 
  
   i := LENGTH(inputNumber); 
   WHILE i >= 1 LOOP 
      invertedNumber := invertedNumber || SUBSTR(inputNumber, i, 1); 
      i := i - 1; 
   END LOOP; 
 
   DBMS_OUTPUT.PUT_LINE('Inverted Number using WHILE loop: ' || invertedNumber); 
 
END; 
/

DECLARE 
   radius NUMBER; 
   area NUMBER; 
BEGIN 
   
   EXECUTE IMMEDIATE 'CREATE TABLE AREAS (Radius NUMBER, Area NUMBER)'; 
 
   FOR radius IN 4..10 LOOP 
       
      area := 3.14159 * POWER(radius, 2);  
      INSERT INTO AREAS (Radius, Area) VALUES (radius, area); 
      DBMS_OUTPUT.PUT_LINE('Radius = ' || radius || ', Area = ' || area); 
   END LOOP; 
 
   COMMIT; 
END; 
/

CREATE TABLE AREAS ( 
   Radius NUMBER, 
   Area NUMBER 
);

DECLARE 
   radius NUMBER; 
   area NUMBER; 
BEGIN 
   FOR radius IN 4..10 LOOP 
       
      area := 3.14159 * POWER(radius, 2);  
      INSERT INTO AREAS (Radius, Area) VALUES (radius, area); 
      DBMS_OUTPUT.PUT_LINE('Radius = ' || radius || ', Area = ' || area); 
   END LOOP; 
 
   COMMIT; 
END; 
/

