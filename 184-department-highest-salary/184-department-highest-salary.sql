# Write your MySQL query statement below
select d.Name as Department, e.Name as Employee, e.salary as salary from Employee e , Department d where e.DepartmentId = d.Id
and (e.DepartmentId, e.Salary) in(select e.DepartmentId, max(e.Salary) from Employee e group by e.DepartmentId);