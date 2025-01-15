--JOINS

--MOVIE + DIRECTOR

SELECT MVTITLE, YRMDE, MOVIE.DIRNUMB, DIRECTOR.DIRNUMB, DIRECTOR.DIRNAME, DIRECTOR.DIRBORN
FROM MOVIE
JOIN DIRECTOR
ON MOVIE.DIRNUMB = DIRECTOR.DIRNUMB;


SELECT MVTITLE AS "Title", DIRECTOR.DIRNAME AS "Directed by"
FROM MOVIE
INNER JOIN DIRECTOR
ON MOVIE.DIRNUMB = DIRECTOR.DIRNUMB;


SELECT DIRNAME, MOVIE.MVTITLE
FROM DIRECTOR
JOIN MOVIE
ON MOVIE.DIRNUMB = DIRECTOR.DIRNUMB;


SELECT DIRECTOR.DIRNAME, MOVIE.MVTITLE
FROM DIRECTOR
NATURAL JOIN MOVIE;


--Renaming column names
SELECT d.DIRNAME, mov.MVTITLE
FROM DIRECTOR d
NATURAL JOIN MOVIE mov;


SELECT MOVIE.MVTITLE, MOVSTAR.STARNUMB
FROM 
    MOVSTAR
    JOIN MOVIE
    ON MOVSTAR.MVNUMB = MOVIE.MVNUMB
;


SELECT STAR.STARNAME, MOVIE.MVTITLE, STAR.STARBORN, MOVIE.YRMDE, (MOVIE.YRMDE - STAR.STARBORN) AS "Star Age"
FROM 
    (MOVSTAR
    JOIN MOVIE
    ON MOVSTAR.MVNUMB = MOVIE.MVNUMB)
JOIN STAR
ON MOVSTAR.STARNUMB = STAR.STARNUMB
--WHERE MOVIE.MVTITLE LIKE "annie%"
;


SELECT * FROM MOVIE
NATURAL JOIN DIRECTOR
;


SELECT * FROM Food
RIGHT JOIN City
ON Food.CityCode = City.Code;


SELECT * FROM Food
FULL JOIN City
ON Food.CityCode = City.Code;


SELECT * FROM Food
UNION
SELECT * FROM City;







