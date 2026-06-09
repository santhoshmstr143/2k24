USE DB;
SELECT Dno AS Department_Number, SUM(Salary) AS Total_Salary  
FROM EMPLOYEE  
GROUP BY Dno;
