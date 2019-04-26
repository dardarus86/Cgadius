delete from planets where planet = 'mercury';
insert into planets values('mercury', '2440', 'yes');




CREATE TABLE ages(ID int NOT NULL PRIMARY KEY, name varchar(50), age int);
CREATE TABLE ages(ID int IDENTITY(1, 1) PRIMARY KEY, name VARCHAR(50), age int);  Identity(1, 1)first number = starting number, second number = value to increment by.
ALTER TABLE table_name ADD PRIMARY KEY(column_name)

week 2
CREATE TABLE manufacturers(mid int IDENTITY(1, 1) PRIMARY KEY, manufacturer VARCHAR(50));
CREATE TABLE cars(vin CHAR(17) NOT NULL PRIMARY KEY, regno VARCHAR(10), colour VARCHAR(30), mid int FOREIGN KEY REFERENCES manufacturers(mid));
INSERT INTO cars VALUES(‘ 2G1FT1EW8A90057EX’, ‘ST05XMP’, ‘Yellow’, ‘1’);

SELECT cars.vin, cars.regno, cars.colour, manufacturers.manufacturer FROM cars INNER JOIN manufacturer ON cars.mid = manufacturer.mid
SELECT manufacturers.manufacturer, cars.vin FROM manufacturers LEFT OUTER JOIN cars ON manufacturers.mid = cars.mid

SELECT students.studentno, students.name, modules.moduletitle FROM students INNER JOIN modulereg ON students.studentno = modulereg.studentcode INNER JOIN modules ON modulereg.modulecode = modules.modulecode


week 3
SELECT *FROM salaries ORDER BY salary DESC;
SELECT * FROM salaries ORDER BY department ASC, salary DESC;
SELECT * FROM salaries WHERE department = ‘Finance’ ORDER BY salary DESC;
SELECT COUNT(*)	FROM salaries WHERE department = ‘Finance’;
SELECT MAX(salary) FROM salaries
SELECT MIN(salary) FROM salaries
SELECT AVG(salary) FROM salaries
SELECT SUM(salary) FROM salaries
SELECT department, SUM(salary) FROM salaries GROUP BY department ORDER BY SUM(salary)

BEGIN TRANSACTION;
UPDATE accounts SET balance = 100 WHERE accountid = ‘JEFFCURRENT’;
UPDATE accounts SET balance = 500 WHERE accountif = ‘JEFFSAVINGS’;
COMMIT;

BEGIN TRANSACTION;
UPDATE accounts SET balance = 100 WHERE accountid = ‘JEFFCURRENT’;
UPDATE accounts SET balance = 500 WHERE accountif = ‘JEFFSAVINGS’;
ROLLBACK;



Week 1 games
CREATE TABLE customers(Forename VARCHAR(20), Surname VARCHAR(20), Address VARCHAR(50), EmailVARCHAR(50), FavPlatform VARCHAR(4), Date DATE);


INSERT INTO customers VALUES('Alan', ‘Smith’, ‘123 Bell Street’, 'davidsmith@gmail.com', 'PC', '1986-12-23');


INSERT INTO customers VALUES('Bob', ‘Ross’, ‘23 Door Road’, 'bobross@gmail.com', 'PS4', '1986-12-23');


INSERT INTO customers VALUES('Carl', ‘Davis’, ‘5 Park Place’, 'carldavis@gmail.com', 'PS4', '1986-12-23');


INSERT INTO customers VALUES(‘David', ‘Dale’, ‘1 Oxford Street’, 'daviddale@gmail.com', 'XBOX', '1986 - 12 - 23');


	INSERT INTO customers VALUES(‘Euan’, ‘Alastiar’, ‘6 Dell Place’, 'euanalastair@gmail.com', 'PC', '1986-12-23');

INSERT INTO customers VALUES(‘Frank’, ‘Alan’, ‘24 Abertay Street’, 'frankalan@gmail.com', 'PC', '1986-12-23');


INSERT INTO customers VALUES(‘Graham’, ‘Stot’, ‘2 Garmon Road’, 'grahamstot@gmail.com', 'XBOX', '1986-12-23');


INSERT INTO customers VALUES(‘Harry’, ‘Peterson’, ‘9 Raiden Place’, 'harrypeterson@gmail.com', 'XBOX', '1986-12-23');


INSERT INTO customers VALUES(‘Igor’, ‘Thor’, ‘155 Poto Street’, 'igorthot@gmail.com', 'PC', '1986-12-23');


INSERT INTO customers VALUES(‘James’, ‘Tanner’, ‘68 Torp Road’, 'jamestanner@gmail.com', 'PS4', '1986-12-23');


CREATE TABLE games(name varchar(20), Platform VARCHAR(4), stock int, price DECIMAL(5, 2));

INSERT INTO games VALUES(‘Goldeneye’, ‘PC’, ‘13’, '14.99');

INSERT INTO games VALUES(‘Halo’, ‘PS4’, ‘3’, '14.99');

INSERT INTO games VALUES(‘Banjo’, ‘PC’, ‘4’, '14.99');

INSERT INTO games VALUES(‘Mario’, ‘XBOX’, ‘9’, '14.99');

INSERT INTO games VALUES(‘Mass Effect’, ‘PC’, ‘12’, '14.99');

INSERT INTO games VALUES(‘Zelda’, ‘PS4’, ‘20’, '14.99');

INSERT INTO games VALUES(‘James Pong’, ‘XBOX’, ‘7’, '14.99');

INSERT INTO games VALUES(‘Tetris 2019’, ‘PS4’, ‘4’, '14.99');

INSERT INTO games VALUES(‘Borderlands 2’, ‘PC’, ‘6’, '14.99');

