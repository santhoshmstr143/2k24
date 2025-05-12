USE DB;
SELECT 
 E.Fname,
 E.Lname, 
 D.Dname, 
 P.Pname
FROM EMPLOYEE E
JOIN DEPARTMENT D ON E.Dno = D.Dnumber
JOIN WORKS_ON W ON E.Ssn = W.Essn
JOIN PROJECT P ON W.Pno = P.Pnumber;
