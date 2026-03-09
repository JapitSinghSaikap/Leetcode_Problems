# Write your MySQL query statement below
SELECT user_id,
CONCAT(
    UPPER(SUBSTRING(name,1,1)),#for the first character only
    LOWER(SUBSTRING(name,2))#for the rest of the string
) name
FROM Users
ORDER BY user_id;