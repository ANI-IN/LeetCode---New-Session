# Write your MySQL query statement below
select p.product_name,s.year,s.price
from Sales as s
join product as p
where s.product_id=p.product_id;