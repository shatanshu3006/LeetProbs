# Write your MySQL query statement below

#here COALESCE is used to replace NULL values with zero before checking whether it is #equal to 2 or not.

select name from Customer where coalesce(referee_id,0)<>2;