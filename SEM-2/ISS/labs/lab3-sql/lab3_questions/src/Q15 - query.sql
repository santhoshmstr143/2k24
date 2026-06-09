USE DB;
SELECT 
D.Dname, 
E.Fname 
AS 
Manager_Fname, 
E.Lname 
AS 
Manager_Lname
FROM DEPARTMENT D
JOIN EMPLOYEE E ON D.Mgr_ssn = E.Ssn;
