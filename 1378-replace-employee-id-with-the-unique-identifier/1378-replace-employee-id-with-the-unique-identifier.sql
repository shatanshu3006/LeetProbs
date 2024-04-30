# Write your MySQL query statement below

#What is SQL LEFT JOIN?
#SQL LEFT JOIN, also known as a LEFT OUTER JOIN, is a type of SQL JOIN operation that retrieves all records from the left table (table1) and the matching records from the right table (table2). If there are no matching records in the right table, NULL values are included for those columns.
select eu.unique_id as unique_id,e.name as name from Employees as e left join EmployeeUNI as eu on e.id=eu.id;