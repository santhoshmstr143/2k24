USE DB;
SELECT 
    D.Dname, 
    COUNT(E.Ssn) AS Employee_Count
FROM 
    DEPARTMENT D
    INNER JOIN EMPLOYEE E ON D.Dnumber = E.Dno
GROUP BY 
    D.Dname;


