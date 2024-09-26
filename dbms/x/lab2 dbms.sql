create database lab2;
show databases;
use lab2;

CREATE TABLE supplier (
id int(4) NOT NULL,
name varchar(20),
phone INT(12) DEFAULT 99999999
);

ALTER TABLE supplier MODIFY phone BIGINT(12);

INSERT INTO supplier VALUES ( 555,'Sangam',676767676);
INSERT INTO supplier(id,phone) VALUES (734, 303033030);
INSERT INTO supplier (id,name) VALUES ( 320, 'Sundraam');
show table;
SELECT * from supplier;

INSERT INTO supplier(id,phone) VALUES (340, 333303030);
INSERT INTO supplier(name,phone) VALUES("Hoffer",90072345667);
--will show error bcz we have set the id to not NULL

SELECT * from supplier;

desc supplier;

ALTER TABLE supplier ADD UNIQUE (id);
ALTER TABLE supplier ADD UNIQUE (name);


INSERT INTO supplier(id,phone) VALUES (340, 333303030);
INSERT INTO supplier(id,phone) VALUES (340, 33330303120);
-- id is set unique

INSERT INTO supplier(name,phone) VALUES("Hoffer",90072345667);
SELECT * from supplier;

ALTER TABLE supplier ADD CONSTRAINT UNIQUE (id);
ALTER TABLE supplier ADD CONSTRAINT PRIMARY KEY (id);
-- TRUNCATE TABLE supplier; USE TO TRUNCATE
-- DROP TABLE supplier; USE TO DELETE THE TABLE

DESC supplier;
INSERT INTO supplier VALUES( 576,'Jasmine',07653555544);
INSERT INTO supplier VALUES( 764,'Boston',45007653544);


CREATE TABLE product
( pid int(4) NOT NULL PRIMARY KEY,
sid int(4),
pname varchar(20),
FOREIGN KEY (sid) REFERENCES supplier(id)
);

-- CREATE TABLE product
-- ( pid int(4) NOT NULL PRIMARY KEY,
-- sid int(4) FOREIGN KEY REFERENCES supplier(id),
-- pname varchar(20),
-- FOREIGN KEY (sid)
-- );
-- WE CAN ALSO DO LIKE THIS
DESC product;

SET FOREIGN_KEY_CHECKS=0;
--before inserting make sure to run above command
INSERT INTO product VALUES (2349, 220, 'Laptop');
INSERT INTO product VALUES (3449,5555, 'Mobile');
INSERT INTO product VALUES (4490, 434, 'Pen Drive');
INSERT INTO product VALUES (9452, 7070, 'Pen drive');
Select * from product;

INSERT INTO supplier VALUES(7070,'Mukherjee',50000600068);
INSERT INTO product (pid,sid,Pname) VALUES (9452, 7070, 'Pen drive');
--after running above command it will show that duplicate entry '9452' for primary key (pid)


CREATE TABLE students (
id int(5),
name varchar(20),
address varchar (20),
dob date,
PRIMARY KEY(id)
);
INSERT INTO students VALUES (200,'ashish','4123-MALVIYA','1998-12-20');
-- dob YYMMDD
ALTER TABLE students DROP PRIMARY KEY;
-- ALTER TABLE students MODIFY id (PRIMARY KEY);it is wrong bcz primary key is not a datatype it is a constraint
ALTER TABLE students ADD PRIMARY KEY(id);


-- /************EXCERCISE TASK*****************/
CREATE TABLE sailors(
sid INT(3) PRIMARY KEY,
sname VARCHAR(20) NOT NULL,
rating INT(2) NOT NULL,
age DECIMAL(3,1)
);


CREATE TABLE boats(
bid INT(3) PRIMARY KEY,
bname VARCHAR(12) NOT NULL,
color VARCHAR(8) NOT NULL
);


CREATE TABLE reserves(
sid INT(3) PRIMARY KEY,
bid INT(3),
day DATE
);

INSERT INTO sailors VALUES(22,"Dustin",7,45.0);
INSERT INTO sailors VALUES(29,"Brutus",1,33.0);
INSERT INTO sailors VALUES(31,"Lubber",8,55.5);
INSERT INTO sailors VALUES(32,"Andy",8,25.5);
INSERT INTO sailors VALUES(58,"Rusty",10,35.0);
INSERT INTO sailors VALUES(64,"Horatio",7,35.0);
INSERT INTO sailors VALUES(71,"Zorba",10,16.0);
INSERT INTO sailors VALUES(74,"Horatio",9,35.0);
INSERT INTO sailors VALUES(85,"Art",3,25.5);
INSERT INTO sailors VALUES(95,"Bob",3,63.5);

INSERT INTO reserves VALUES(22,101,'1998-10-10');
INSERT INTO reserves VALUES(22,102,'1998-10-10');
INSERT INTO reserves VALUES(22,103,'1998-8-10');
INSERT INTO reserves VALUES(22,104,'1998-7-10');
INSERT INTO reserves VALUES(31,102,'1998-10-11');
INSERT INTO reserves VALUES(31,103,'1998-6-11');
INSERT INTO reserves VALUES(64,101,'1998-5-9');
INSERT INTO reserves VALUES(64,102,'1998-8-9');
INSERT INTO reserves VALUES(74,103,'1998-8-9');

INSERT INTO boats VALUES(101,'Interlake','blue');
INSERT INTO boats VALUES(102,'Interlake','red');
INSERT INTO boats VALUES(103,'Clipper','green');
INSERT INTO boats VALUES(104,'Marine','red');