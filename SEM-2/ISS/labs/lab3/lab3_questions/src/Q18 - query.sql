USE DB;
CREATE VIEW Department_Manager_Salary AS
SELECT D.Dname AS Department_Name,
       E.Fname AS Manager_First_Name,
       E.Lname AS Manager_Last_Name,
       E.Salary AS Manager_Salary
FROM DEPARTMENT D
JOIN EMPLOYEE E ON D.Mgr_ssn = E.Ssn;
