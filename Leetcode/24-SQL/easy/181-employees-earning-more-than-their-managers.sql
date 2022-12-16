SELECT
    employee.name as Employee
FROM
    Employee employee, Employee manager
WHERE 
    employee.managerId = manager.id
    AND 
    employee.salary > manager.salary;