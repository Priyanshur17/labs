Create table department (
dnumber int(1) PRIMARY KEY,
dname varchar(50) NOT NULL,
MGRssn int(10) NOT NULL,
MGRstartdate date NOT NULL
);

insert into department values(5,'research',333445555,'1988-05-22');
insert into department values(4,'administration',987654321,'1995-01-01');
insert into department values(1,'headquarters',888665555,'1981-06-19');

Create table dep_location(
dnumber int(1),
dloaction varchar(25) PRIMARY KEY,
FOREIGN KEY (dnumber) REFERENCES department(dnumber)
);

insert into dep_location values(1,'houston');
insert into dep_location values(4,'stafford');
insert into dep_location values(5,'bellaire');
insert into dep_location values(5,'sugarland');

Create table employee (
ssn int(10) PRIMARY KEY,
first_name varchar(25) NOT NULL,
last_name varchar(25) NOT NULL,
MINIT varchar(1) NOT NULL,
bdate date NOT NULL,
address varchar(255) NOT NULL,
sex varchar(1) NOT NULL,
salary int(5) NOT NULL,
super_ssn int(10),
dnumber int(1),
FOREIGN KEY (dnumber) REFERENCES department(dnumber)
);

insert into employee values(123456789,'john','smith','B','1965-01-09','731 Fondren,Houston,TX','M',30000,333445555,5);
insert into employee values(333445555,'franklin','wong','T','1955-12-08','638 Voss,Houston,TX','M',40000,888665555,5);
insert into employee values(999887777,'alicia','zelaya','J','1968-01-19','3321 Castle,spring,TX','F',25000,987654321,4);
insert into employee values(987654321,'jennifer','wallace','S','1941-06-20','291 Berry,bellaire,TX','F',43000,888665555,4);
insert into employee values(666884444,'ramesh','narayan','K','1962-09-15','975 Fire Oak,Humble,TX','M',38000,333445555,5);
insert into employee values(453453453,'joyce','english','A','1972-07-31','5631 Rice ,Houston,TX','F',25000,333445555,5);
insert into employee values(987987987,'ahmad','jabbar','V','1969-03-29','980 Dallas,Houston,TX','M',25000,987654321,4);
insert into employee values(888665555,'james','borg','E','1937-11-10','450 Stone,Houston,TX','M',55000,NULL,1);

Create table project (
pnumber int(2) PRIMARY KEY,
pname varchar(50) NOT NULL,
plocation varchar(50) NOT NULL,
dnumber int(1),
FOREIGN KEY (dnumber) REFERENCES department(dnumber)
);

insert into project values(1,'ProductX','Bellaire',5);
insert into project values(2,'ProductY','Sugarland',5);
insert into project values(3,'ProductZ','Houston',5);
insert into project values(10,'Computerization','Stafford',4);
insert into project values(20,'Reorganization','Houston',1);
insert into project values(30,'Newbenefits','Stafford',4);


Create table dependent(
ssn int(10),
dependent_name varchar(25) PRIMARY KEY,
sex varchar(1) NOT NULL,
bdate date NOT NULL,
relationship varchar(20) NOT NULL,
FOREIGN KEY (ssn) REFERENCES employee(ssn)
);


insert into dependent VALUES(333445555,'Alice','F','1986-04-05','Daughter');
insert into dependent VALUES(333445555,'Theodore','M','1983-10-25','Son');
insert into dependent VALUES(333445555,'Joy','F','1958-05-03','Spouse');
insert into dependent VALUES(987654321,'Abner','M','1942-02-28','Spouse');
insert into dependent VALUES(123456789,'Michael','M','1988-01-04','Son');
insert into dependent VALUES(123456789,'Elizabeth','F','1967-05-05','Spouse');


create table works_on(
ssn int(10),
pnumber int(2),
hours float(3,1),
FOREIGN KEY (ssn) REFERENCES employee(ssn),
FOREIGN KEY (pnumber) REFERENCES project(pnumber)
);

insert into works_on values(123456789,1,32.5);
insert into works_on values(123456789,2,7.5);
insert into works_on values(666884444,3,40.0);
insert into works_on values(453453453,1,20.0);
insert into works_on values(453453453,2,20.0);
insert into works_on values(333445555,2,10.0);
insert into works_on values(333445555,3,10.0);
insert into works_on values(333445555,10,10.0);
insert into works_on values(333445555,20,10.0);
insert into works_on values(999887777,30,30.0);
insert into works_on values(999887777,10,10.0);
insert into works_on values(987987987,10,35.0);
insert into works_on values(987987987,30,5.0);
insert into works_on values(987654321,30,20.0);
insert into works_on values(987654321,20,15.0);
insert into works_on values(888665555,20,NULL);









1. Retrieve the date of birth, gender and address of employee whose name is James.

SELECT bdate, sex, address
FROM employee
WHERE first_name = 'James';

2. Retrieve the name of each employee who has a dependent with the same first name and same sex as the employee.

SELECT DISTINCT e.first_name, e.last_name
FROM employee e
INNER JOIN dependent d ON e.ssn = d.ssn
WHERE e.first_name = d.dependent_name AND e.sex = d.sex;

3. Find the name of all employee who work for administration department

SELECT e.first_name, e.last_name
FROM employee e
INNER JOIN department d ON e.dnumber = d.dnumber
WHERE d.dname = 'administration';

4. Retrieve all the attributes of employee who works in department no 4 or 1.

select * from employee e
    inner join department d on e.dnumber=d.dnumber
     where d.dnumber=4 or d.dnumber=1;

5. Retrieve the names of employees who have no dependents.

SELECT first_name, last_name
FROM employee
WHERE ssn NOT IN (SELECT DISTINCT ssn FROM dependent);


vi. Give all employees of department number 4 a 20% rise in their salary.

UPDATE employee
SET salary = salary * 1.20
WHERE dnumber = 4;

vii. Retrieve the total number of dependents.

SELECT COUNT(*) AS total_dependents
FROM dependent;

viii. Find out all employees in department no 4 whose salary is between 20000 and 35000
(inclusive) ordered by employees last name .

SELECT *
FROM employee
WHERE dnumber = 4 AND salary BETWEEN 20000 AND 35000
ORDER BY last_name;

ix. For each employee, retrieve the employee’s first and last name and the first and last name of
his or her immediate supervisor.

SELECT
    e.first_name AS employee_first_name,
    e.last_name AS employee_last_name,
    s.first_name AS supervisor_first_name,
    s.last_name AS supervisor_last_name
FROM
    employee e
LEFT JOIN
    employee s ON e.super_ssn = s.ssn;


x. For every project located in ‘Stafford’, list the project number, the controlling department
number, and the department manager’s last name, address, and birthdate.

SELECT
    p.pnumber AS project_number,
    p.dnumber AS controlling_department_number,
    d.MGRssn AS manager_ssn,
    e.last_name AS manager_last_name,
    e.address AS manager_address,
    e.bdate AS manager_birthdate
FROM
    project p
INNER JOIN
    department d ON p.dnumber = d.dnumber
INNER JOIN
    employee e ON d.MGRssn = e.ssn
WHERE
    p.plocation = 'Stafford';


xi. Find out the total no of employees in an organization.

SELECT COUNT(*) AS total_employees
FROM employee;

xii. For each project find out the project no, its name and no of employees who working on that
project.

SELECT
    p.pnumber AS project_number,
    p.pname AS project_name,
    COUNT(w.ssn) AS number_of_employees
FROM
    project p
LEFT JOIN
    works_on w ON p.pnumber = w.pnumber
GROUP BY
    p.pnumber, p.pname;

xiii. Display all distinct project location values.

SELECT DISTINCT plocation
FROM project;

xiv. Retrieve all employees in department 4 whose salary is between 2,000 and 3,000(inclusive)

SELECT *
FROM employee
WHERE dnumber = 4
  AND salary BETWEEN 2000 AND 3000;

xv. Find the names of all employees who do not have their supervisor.

SELECT first_name, last_name
FROM employee
WHERE super_ssn IS NULL;

xvi. For each department, retrieve the department number, the number of employees in the
department, and their average salary

SELECT
    d.dnumber AS department_number,
    COUNT(e.ssn) AS number_of_employees,
    AVG(e.salary) AS average_salary
FROM
    department d
LEFT JOIN
    employee e ON d.dnumber = e.dnumber
GROUP BY
    d.dnumber;

xvii. For each project on which more than two employees work, retrieve the project number, its
name, and the number of its employees.

SELECT
    p.pnumber AS project_number,
    p.pname AS project_name,
    COUNT(w.ssn) AS number_of_employees
FROM
    project p
INNER JOIN
    works_on w ON p.pnumber = w.pnumber
GROUP BY
    p.pnumber, p.pname
HAVING
    COUNT(w.ssn) > 2;

xviii. For every project located in ‘Houston’, list the project number, the controlling department
number and the department manager’s last name, address and birthdate.

SELECT
    p.pnumber AS project_number,
    p.dnumber AS controlling_department_number,
    d.MGRssn AS manager_ssn,
    e.last_name AS manager_last_name,
    e.address AS manager_address,
    e.bdate AS manager_birthdate
FROM
    project p
INNER JOIN
    department d ON p.dnumber = d.dnumber
INNER JOIN
    employee e ON d.MGRssn = e.ssn
WHERE
    p.plocation = 'Houston';

xix. Write query to change the location and controlling department of project number 10 to ‘Delhi’
and 1 respectively.

UPDATE project
SET plocation = 'Delhi', dnumber = 1
WHERE pnumber = 10;

xx. Delete all the dependent whose name starts with ‘A’ or ‘J’

DELETE FROM dependent
WHERE dependent_name LIKE 'A%' OR dependent_name LIKE 'J%';



