# Write your MySQL query statement below

# because , the null value does not have any values to be checked with the operator ( #= , !=) ,. So when we use referee_id = 2 , it will not check in the null places #beacuse there is no values. So we have to combine both the statement--

select name from Customer where referee_id != 2 or referee_id is NULL