SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary != (
    SELECT MAX(salary) 
    FROM Employee
); 

-- Official solution
SELECT
    (SELECT DISTINCT
            Salary
        FROM
            Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1) AS SecondHighestSalary
;