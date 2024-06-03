# Write your MySQL query statement below

# p table se product name uthaya, s se year aur price uthaya
select p.product_name, s.year, s.price      
from product as p
join sales as s
on p.product_id=s.product_id