USE DB;
SELECT E.Fname, E.Lname
FROM EMPLOYEE E
JOIN WORKS_ON W ON E.Ssn = W.Essn
JOIN PROJECT P ON W.Pno = P.Pnumber
WHERE P.Pname IN (
    SELECT Pname
    FROM PROJECT
    JOIN WORKS_ON W2 ON PROJECT.Pnumber = W2.Pno
    JOIN EMPLOYEE E1 ON W2.Essn = E1.Ssn
    WHERE E1.Fname = 'Franklin' AND E1.Lname = 'Wong'
);
