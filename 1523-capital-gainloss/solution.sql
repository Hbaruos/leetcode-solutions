# Write your MySQL query statement below
SELECT STOCK_NAME,
SUM( CASE WHEN operation = 'Sell' THEN PRICE ELSE 0 END) - SUM( CASE WHEN operation = 'Buy' THEN PRICE ELSE 0 END)
AS 'capital_gain_loss'
FROM STOCKS
GROUP BY 1;
