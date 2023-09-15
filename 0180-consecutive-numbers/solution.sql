SELECT DISTINCT num AS ConsecutiveNums FROM (
  SELECT id, num, LEAD(num, 1) OVER () AS LEAD1, LEAD(num, 2) OVER () AS LEAD2 FROM Logs 
) A
  WHERE num = LEAD1 && LEAD1 = LEAD2;
