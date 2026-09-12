-- SELECT TOP (1000) [Id]
--       ,[Name]
--   FROM [s3969801].[dbo].[games]

SELECT * FROM games;


INSERT INTO games (Name)
VALUES ('Dota 2');


DELETE FROM games
WHERE Name = 'Dota 2';


INSERT INTO [dbo].[games] (Name)
VALUES 
    ('Genshin'),
    ('Dota 2'),
    ('Lol'),
    ('BMW');


-- Raw SQL
