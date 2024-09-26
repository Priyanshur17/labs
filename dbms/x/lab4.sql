create database db1;
use db1;

Create table loan (

loanNo varchar(10),
branch_name varchar(20),
amount int(5),

constraint loan_pk primary key (loanNo)
);

Create table borrower (

customer_name varchar(20),
loanNo varchar(10),
constraint borrower_pk primary key (loanNo)

);

Create table depositor (

customer_name varchar(20),
account_number varchar(20),
constraint depositor_pk primary key (customer_name)
);

insert into loan value ("L-170","Downtown", 3000);
insert into loan value ("L-230","Redwood", 4000);
insert into loan value ("L-260","Perryridge ",1700);
insert into loan value ("L-155","Washigton", 4500);



insert into borrower value ("Jones","L-170");
 insert into borrower value ("Smith","L-230");
 insert into borrower value ("Hayes","L-155");
 

insert into depositor value ("Jones","HDBC2044");
insert into depositor value ("Smith","HDBC2055");

insert into depositor value ("Hayes","HDBC2066");

insert into depositor value ("Chris","HDBC2077");
insert into depositor value ("Adam","HDBC2088");

//inner join
Select * from (loan l inner join borrower b on l.loanno =b.loanno);

//left outer  join

Select * from ( loan l left outer join borrower b on l.loanno = b.loanno );

//natural join 
select * from (loan natural inner join borrower);

//right outer join
select * from ( loan l right outer join borrower b on l.loanno =b.loanno);

//full
SELECT * from ( loan l full outer join borrower b on l.loanno=b.loanno);

exercise:




To do Exercise:
i. Determine the names of sailors who are older than the
oldest sailor with a rating of10?

ans::

SELECT sname
FROM SAILORS
WHERE age > (SELECT MAX(age) FROM SAILORS WHERE rating = 10);

ii. Determine the names of sailors who have reserved all boats?

ans::
SELECT S.sname
FROM SAILORS S
WHERE NOT EXISTS (
    SELECT B.bid
    FROM BOATS B
    WHERE NOT EXISTS (
        SELECT R.bid
        FROM RESERVES R
        WHERE R.sid = S.sid AND R.bid = B.bid
    )
);


iii. Determine the average age of sailors with a rating of 10?
ans::
select AVG(age) FROM SAILORS S where S.rating=10;


iv. Determine the name and the age of the oldest sailor?
ans::
select s.sname,s.age from SAILORS s WHERE age=(select max(age) from SAILORS);


v. Count the number of sailors?
ans::
select count(sid) from SAILORS;

vi. For each red boat, find the number of reservations for
this boat?
ans::

SELECT COUNT(R.bid) from RESERVES R,BOATS B WHERE  R.bid=B.bid and B.color="red";


