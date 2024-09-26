create database db2;
use db2;


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

DELETE FROM supplier WHERE id < 400;
SHOW CREATE TABLE supplier;
alter table supplier drop PRIMARY KEY;
ALTER TABLE supplier ADD COLUMN address VARCHAR(100);
ALTER TABLE supplier MODIFY COLUMN name VARCHAR(30);
Drop NOT NULL Constraint: To drop the NOT NULL constraint, you first need to find the column with the constraint. For example, if the column is product_name:
ALTER TABLE product MODIFY COLUMN product_name VARCHAR(100);
SHOW CREATE TABLE product;
Then, drop the foreign key constraint. For example, if the constraint name is fk_category:
ALTER TABLE product DROP FOREIGN KEY fk_category;

DROP TABLE product;
TRUNCATE TABLE product;


CREATE TABLE TableName1 (
    ColumnName1 DataType,
    ColumnName2 DataType,
    ColumnName3 DataType,
    CONSTRAINT pk_TableName1 PRIMARY KEY (ColumnName1)
);

CREATE TABLE TableName2 (
    ColumnName4 DataType,
    ColumnName5 DataType,
    ColumnName6 DataType,
    CONSTRAINT pk_TableName2 PRIMARY KEY (ColumnName4),
    CONSTRAINT fk_TableName1_ColumnName4 FOREIGN KEY (ColumnName4) REFERENCES TableName1 (ColumnName1)
    ON UPDATE CASCADE
);

ALTER TABLE TableName2 
ADD CONSTRAINT fk_TableName1_ColumnName4 
FOREIGN KEY (ColumnName4) 
REFERENCES TableName1 (ColumnName1) 
ON UPDATE CASCADE;



CREATE TABLE IF NOT EXISTS supplier (
    id INT PRIMARY KEY,
    name VARCHAR(30) NOT NULL UNIQUE,
    phone BIGINT
);
INSERT IGNORE INTO supplier (id, name) VALUES (220, 'Sundram');
INSERT IGNORE INTO supplier VALUES (5555, 'Sansar', 6767676767676);
INSERT IGNORE INTO supplier (id, name, phone) VALUES (434, 'Krish', 303030303030);
CREATE TABLE IF NOT EXISTS product (
    pid INT PRIMARY KEY,
    sid INT,
    Pname VARCHAR(50),
    CONSTRAINT fk_supplier FOREIGN KEY (sid) REFERENCES supplier (id)
        ON DELETE CASCADE
);
INSERT IGNORE INTO product (pid, sid, Pname) VALUES (2349, 220, 'Laptop');
INSERT IGNORE INTO product (pid, sid, Pname) VALUES (3449, 5555, 'Mobile');
INSERT IGNORE INTO product (pid, sid, Pname) VALUES (5489, 434, 'Mobile');

DELETE FROM supplier WHERE id = 5555;

-- Observe the effect by selecting from both tables
SELECT * FROM supplier;
SELECT * FROM product;

i) Insert into Specific Columns

INSERT INTO TableName (ColumnName1, ColumnName2, ColumnName3, ...)
SELECT ColumnName1, ColumnName2, ColumnName3, ...
FROM TableName2
WHERE Conditional-Expression;


ii) Insert into All Columns

INSERT INTO TableName
SELECT ColumnName1, ColumnName2, ColumnName3, ...
FROM TableName2
WHERE Conditional-Expression;






-- Find sids of sailors with rating of 10
SELECT S.sid
FROM SAILORS S
WHERE S.rating = 10

UNION

-- Find sids of sailors who have reserved boat 104
SELECT R.sid
FROM RESERVES R
WHERE R.bid = 104;









SELECT S.rating, MIN(S.age) AS MinAge
FROM SAILORS S
WHERE S.age >= 18
GROUP BY S.rating
HAVING COUNT(*) > 1 
AND MIN(S.age) <= 60;


exercise:lab3

1) Find the names of sailors who have reserved a green boat?
ans::
SELECT DISTINCT S.sname
FROM SAILORS S
JOIN RESERVES R ON S.sid = R.sid
JOIN BOATS B ON R.bid = B.bid
WHERE B.color = 'green';


2) Find the color of the boat reserved by ‘Lubber’?
ans::

SELECT DISTINCT B.color
FROM BOATS B
JOIN RESERVES R ON B.bid = R.bid
JOIN SAILORS S ON R.sid = S.sid
WHERE S.sname = 'Lubber';


3) Find the ages of sailors whose name begins and ends with B and has at least three
characters.
ans::

SELECT  distinct S.age  FROM SAILORS S,RESERVES R,BOATS B  where S.sname like "B%_%b";

SELECT S.age
FROM SAILORS S
WHERE S.sname LIKE 'B%B' AND LENGTH(S.sname) >= 3;



4) Find all sid’s of sailors who have a rating of 10 or reserved boat 104?

ans::

select distinct S.sid FROM SAILORS S,RESERVES R,BOATS B WHERE S.rating=10 or (S.sid=R.sid AND R.bid=104);

SELECT S.sid
FROM SAILORS S
WHERE S.rating = 10
UNION
SELECT R.sid
FROM RESERVES R
WHERE R.bid = 104;



5) Find the name of the sailors who have reserved a ‘red’ boat?( using IN)
ans::
     SELECT DISTINCT S.sname
FROM SAILORS S
JOIN RESERVES R ON S.sid = R.sid
JOIN BOATS B ON R.bid = B.bid
WHERE B.color = 'red';


SELECT S.sname FROM SAILORS S WHERE S.sid IN (SELECT R.sid FROM RESERVES R WHERE R.bid IN (SELECT B.bid FROM BOATS B WHERE B.color='red') );

SELECT DISTINCT S.sname
FROM SAILORS S
WHERE S.sid IN (
    SELECT R.sid
    FROM RESERVES R
    JOIN BOATS B ON R.bid = B.bid
    WHERE B.color = 'red'
);


6) Find the names of sailors who have not reserved a ‘red’ boat?(using NOT IN)
ans::

SELECT DISTINCT sname
FROM SAILORS
WHERE sid NOT IN (
    SELECT DISTINCT S.sid
    FROM SAILORS S
    JOIN RESERVES R ON S.sid = R.sid
    JOIN BOATS B ON R.bid = B.bid
    WHERE B.color = 'red'
);

SELECT DISTINCT S.sname
FROM SAILORS S
WHERE S.sid NOT IN (
    SELECT R.sid
    FROM RESERVES R
    JOIN BOATS B ON R.bid = B.bid
    WHERE B.color = 'red'
);


SELECT S.sname FROM SAILORS S WHERE S.sid NOT IN (SELECT R.sid FROM RESERVES R WHERE R.bid IN (SELECT B.bid FROM BOATS B WHERE B.color='red') );


7) Find the names of sailors who have reserved both a ‘red’ and a ‘green’ boat?

SELECT S.sname
FROM SAILORS S
JOIN RESERVES R1 ON S.sid = R1.sid
JOIN RESERVES R2 ON S.sid = R2.sid
JOIN BOATS B1 ON R1.bid = B1.bid
JOIN BOATS B2 ON R2.bid = B2.bid
WHERE B1.color = 'red' AND B2.color = 'green';


SELECT S.sname FROM SAILORS S,RESERVES R, BOATS B WHERE S.sid=R.sid AND R.bid=B.bid AND B.color='red' INTERSECT SELECT S2.sname FROM SAILORS S2,RESERVES R2, BOATS B2 WHERE S2.sid=R2.sid AND R2.bid=B2.bid AND B2.color='green';


8) Find the increments for the ratings of sailor who have sailed two different
boats on the same day.

SELECT S.sname, R1.day, R1.bid, R1.rating - R2.rating AS rating_increment
FROM SAILORS S
JOIN RESERVES R1 ON S.sid = R1.sid
JOIN RESERVES R2 ON S.sid = R2.sid
WHERE R1.day = R2.day AND R1.bid <> R2.bid;

 SELECT S.sname, S.rating+1 AS rating
FROM SAILORS S, RESERVES R1,RESERVES R2
WHERE S.sid=R1.sid AND S.sid=R2.sid
AND R1.day =R2.day AND R1.bid<> R2.bid;


9) Find the name of sailors such that it have following relationship between their
ratings:
2 x rating( 1 st sailor) = rating (2 nd sailor) ‐ 1

SELECT S1.sname, S1.rating, S2.sname, S2.rating FROM SAILORS S1, SAILORS S2 where S1.rating * 2 = S2.rating - 1;

SELECT S1.sname
FROM SAILORS S1
JOIN SAILORS S2 ON 2 * S1.rating = S2.rating - 1
WHERE S1.sid != S2.sid;






exercise::





1. Find the sailor name and boat id of the reserved boat having the colour of blue and/or
green.

ans::
  SELECT S.sname,B.bid FROM SAILORS S,RESERVES R, BOATS B
WHERE S.sid=R.sid AND R.bid=B.bid AND (B.color="red" OR B.color="green");

SELECT S.sname, R.bid
FROM SAILORS S
JOIN RESERVES R ON S.sid = R.sid
JOIN BOATS B ON R.bid = B.bid
WHERE B.color IN ('blue', 'green');


2. Find the name of sailors if boat Number is 103.

ans:: 
SELECT S.sname FROM SAILORS S, RESERVES R
WHERE S.sid=R.sid AND R.bid=103;


3. Calculate the average age of all sailors.
ans:: 

select AVG(age)  AS AVG_SGE FROM SAILORS;


4. Count the number of different boats reserved.
ans::

SELECT COUNT(DISTINCT bid) AS num_reserved_boats
FROM RESERVES;



5. Find the names of sailors who have never reserved boat number 102.


ans::

SELECT sname
FROM SAILORS
WHERE sid NOT IN (SELECT sid FROM RESERVES WHERE bid = 102);





6. Find the average rating of sailors for each age level.
ans::
SELECT age, AVG(rating) AS avg_rating
FROM SAILORS
GROUP BY age;





7. Find all sailor id’s of sailors who have a rating of at least 8 or reserved boat 101.
ANS::
SELECT sid
FROM SAILORS
WHERE rating >= 8 OR sid IN (SELECT sid FROM RESERVES WHERE bid = 101);



8. Find the colour of boat reserve by Horataio.
ans::SELECT B.color
FROM SAILORS S,RESERVES R, BOATS B

WHERE S.sname = "Horatio" and S.sid=R.sid AND R.bid=B.bid ;




9. Find the names of sailors who have reserved both a red and a green boat.
ans::
 SELECT S.sname FROM SAILORS S,RESERVES R, BOATS B
WHERE S.sid=R.sid AND R.bid=B.bid AND (B.color="red" or B.color="green");


SELECT S.sname FROM SAILORS S,RESERVES R, BOATS B WHERE S.sid=R.sid AND R.bid=B.bid AND B.color='red' INTERSECT SELECT S2.sname FROM SAILORS S2,RESERVES R2, BOATS B2 WHERE S2.sid=R2.sid AND R2.bid=B2.bid AND B2.color='green';


10. Find the sailor id’s of sailors with age over 20 who have not reserved a boat whose
name includes the string “or”.
ans::

SELECT S.sid
FROM SAILORS S
LEFT JOIN RESERVES R ON S.sid = R.sid
WHERE S.age > 20 AND (R.bid IS NULL OR R.bid NOT IN (SELECT bid FROM BOATS WHERE bname LIKE '%or%'));

SELECT S.sid FROM SAILORS S ,RESERVES R where S.sid = R.sid AND S.age > 20 AND (R.bid IS NULL OR R.bid NOT IN (SELECT bid FROM BOATS WHERE bname LIKE '%or%'));         // ignore null values

11. For each rating, find the average age of sailors at that level of rating determine the
names and rating of sailors who have reserved at least two different boats.

ans::
SELECT S.sname, S.rating, AVG(S.age) AS avg_age
FROM SAILORS S
JOIN RESERVES R ON S.sid = R.sid
GROUP BY S.sname, S.rating
HAVING COUNT(DISTINCT R.bid) >= 2;

SELECT S.sname, S.rating, AVG(S.age) AS avg_age FROM SAILORS S, RESERVES R where S.sid = R.sid GROUP BY S.sname, S.rating HAVING COUNT(DISTINCT R.bid) >= 2;

-- First part: Sailors who reserved at least two different boats
WITH SailorsWithMultipleReservations AS (
    SELECT S.sid, S.sname, S.rating
    FROM SAILORS S
    JOIN RESERVES R ON S.sid = R.sid
    GROUP BY S.sid, S.sname, S.rating
    HAVING COUNT(DISTINCT R.bid) >= 2
)

-- Second part: Average age of sailors at each rating level
SELECT SW.rating, AVG(S.age) AS avg_age
FROM SailorsWithMultipleReservations SW
JOIN SAILORS S ON SW.sid = S.sid
GROUP BY SW.rating;




The WITH clause in SQL is used to define a Common Table Expression (CTE). A CTE is essentially a temporary result set that you can refer to within a SELECT, INSERT, UPDATE, or DELETE statement. It simplifies complex queries by breaking them into smaller, more manageable pieces and improving readability.

Benefits of Using CTEs
Improved Readability: CTEs make it easier to understand and maintain complex queries by breaking them down into logical steps.
Reusability: You can reference a CTE multiple times within the main query.
Modularity: CTEs help modularize your query logic, which can make debugging easier.
Syntax
The basic syntax for using a CTE is:



WITH CTEName AS (
    -- Query that defines the CTE
    SELECT ...
    FROM ...
    WHERE ...
)
-- Main query that uses the CTE
SELECT ...
FROM CTEName
WHERE ...



12. For each boat which was reserved by at least 5 distinct sailors, find the boat id and
the average age of sailors who reserved it.
ans::
SELECT R.bid, AVG(S.age) AS avg_age
FROM RESERVES R
JOIN SAILORS S ON R.sid = S.sid
GROUP BY R.bid
HAVING COUNT(DISTINCT R.sid) >= 5;


13. Find the sailor id’s of sailors whose rating is better than some sailor called Lubber.

ans::SELECT DISTINCT S1.sid
FROM SAILORS S1
WHERE S1.rating > (SELECT S2.rating FROM SAILORS S2 WHERE S2.sname = 'Lubber');

