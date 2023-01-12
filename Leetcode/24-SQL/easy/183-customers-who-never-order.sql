-- MY SOLUTION
SELECT c.name as Customers
FROM Customers as c
WHERE c.id NOT IN (
    SELECT cus.id
    FROM Customers as cus INNER JOIN Orders
    ON cus.id = Orders.customerId
); 

-- DISCUSS SOLUTION
SELECT Customers.name as Customers 
FROM Customers
WHERE Customers.id NOT IN (
    SELECT Orders.customerId FROM Orders
);