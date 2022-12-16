SELECT 
    d.name AS Department, 
    e.name AS Employee, 
    e.salary AS Salary
FROM 
    Employee AS e, Department AS d
WHERE
    e.departmentId = d.id 
    AND
    (d.id, e.salary) IN (
        SELECT departmentId, MAX(salary)
        FROM Employee
        GROUP BY departmentId
    )
;