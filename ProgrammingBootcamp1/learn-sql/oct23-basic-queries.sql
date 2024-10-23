SELECT DISTINCT CountryCode FROM City;


SELECT Name, Continent FROM Country
WHERE Continent != 'Asia'; -- <>


SELECT Name, Continent FROM Country
WHERE NOT (Continent = 'Asia'); -- <>


SELECT Name, Continent FROM Country
WHERE Continent = 'North America' OR Continent = 'South America';


--IN
SELECT Name, Continent FROM Country
WHERE Continent IN ('North America', 'South America', 'Europe');


--BETWEEN
SELECT Name, LifeExpectancy FROM Country
--WHERE LifeExpectancy >= 70 AND LifeExpectancy <= 80;
WHERE LifeExpectancy BETWEEN 70 AND 80;


SELECT Name, LifeExpectancy FROM Country
WHERE NOT (LifeExpectancy BETWEEN 70 AND 80);


--WILDCARD & Pattern matching (ignores cases)
--% - bao nhieu chars cung dc
SELECT Name, Region FROM Country
WHERE Region LIKE '%mid%';

--_ - chi dung 1 char thoi
SELECT Name FROM Country
WHERE Name LIKE '__a%';


--0 != NULL
SELECT Name, IndepYear, GNP FROM Country
--WHERE GNP = 0;
WHERE IndepYear IS NOT NULL;


-- Aggregation functions
-- performs a calculation on a set of values, and returns a single value
-- ignores NULL values

SELECT AVG(LifeExpectancy) FROM Country
WHERE Region LIKE '%america';


SELECT Name, MIN(Population) AS [Least Population] 
FROM Country
WHERE Region LIKE '%asia';


SELECT Name, MAX(SurfaceArea) AS "Largest surface area" 
FROM Country;


SELECT SUM(Population) AS "World population" 
FROM Country;


SELECT SUM(Population) AS "Europe population" 
FROM Country
WHERE Region LIKE '%euro%';


--ALIASES
SELECT AllCountries.Name AS [Country Name]
FROM Country AS AllCountries;


--CONCAT FIELD OUTPUTS
--SELECT Name, Name + ' - ' + District AS [Name - District]
--SELECT concat(Name, ' ', District)
SELECT Name || ' - ' || District AS Address
FROM City;


--LIMIT top 12
SELECT Name, GNP
FROM Country
WHERE Continent = 'Asia'
ORDER BY GNP DESC
LIMIT 12;




