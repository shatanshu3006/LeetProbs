# Write your MySQL query statement below

#we use datediff function as the date diff saves from unintended date errors like
# last date of month is 31 and not 32 if we increment by 1
# previous date of 1 is 31 or 30 and not 0 if we decrement the date by 1 and so on
select w1.id
from Weather as w1 , Weather as w2
where datediff(w1.recordDate,w2.recordDate)=1 and w1.temperature>w2.temperature