USE DB;
SET @avg_salary = (SELECT AVG(Salary) FROM EMPLOYEE);

SELECT Fname, Lname
FROM EMPLOYEE
WHERE Salary > @avg_salary;

