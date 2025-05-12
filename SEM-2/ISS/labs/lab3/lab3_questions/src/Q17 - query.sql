USE DB;
SELECT E.Fname, 
       E.Lname
FROM EMPLOYEE E
WHERE E.Dno = 
      (SELECT Dno 
       FROM EMPLOYEE 
       WHERE Salary = 
             (SELECT MAX(Salary) 
              FROM EMPLOYEE));
