# select if(count(salary)=1, null, (select distinct salary from Employee order by salary desc limit 1 offset 1)) SecondHighestSalary from Employee; 

SELECT 
  IFNULL(
    (SELECT DISTINCT salary 
     FROM Employee 
     ORDER BY salary DESC 
     LIMIT 1 OFFSET 1), 
    NULL
  ) AS SecondHighestSalary;
