SELECT * FROM Country;


SELECT * FROM Country
WHERE Continent = 'Asia';


SELECT Name AS "Country Name", Continent
FROM Country
WHERE Continent = 'Africa';


SELECT Name, Continent, Population
FROM Country
WHERE Continent = 'Asia'
ORDER BY Population DESC;


SELECT Name, Continent, Population, GNP
FROM Country
WHERE Continent = 'Asia' AND Population > 100000000
ORDER BY GNP DESC;


SELECT CountryCode, Country.Name, Language, IsOfficial, Percentage
FROM CountryLanguage
JOIN Country
ON CountryLanguage.CountryCode = Country.Code
WHERE IsOfficial = 1 AND Percentage > 50.0
ORDER BY Percentage DESC
;


--Data aggregation

SELECT SUM(Population) AS "World Population"
FROM Country;


select sum(Population) as "Europe population"
from Country
where Continent = 'Europe';


SELECT Count() AS OceaniaCountries
FROM Country
WHERE Continent = 'Oceania';



