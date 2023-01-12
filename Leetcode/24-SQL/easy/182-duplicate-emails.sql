-- SOLUTION DISCUSS
SELECT Email
FROM Person
GROUP BY Email
HAVING COUNT(Email) > 1;

-- SOLUTION MINE
SELECT p.email 
FROM (
    SELECT email, COUNT(*) as count
    FROM Person
    GROUP BY email) AS p
WHERE p.count > 1;


-- SOLUTION DEV
SELECT DISTINCT p1.Email
FROM Person p1, Person p2
WHERE p1.Email = p2.Email and p1.id != p2.id;