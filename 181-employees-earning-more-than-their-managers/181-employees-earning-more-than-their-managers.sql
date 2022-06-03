# Write your MySQL query statement below
SELECT v1.name as Employee FROM Employee v1, Employee v2
Where v1.salary > v2.salary and v1.managerId = v2.id;