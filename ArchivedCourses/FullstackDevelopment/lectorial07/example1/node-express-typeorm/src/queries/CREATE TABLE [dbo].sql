CREATE TABLE [dbo].[games] (
    [Id] INT IDENTITY (1, 1) NOT NULL,
    Name VARCHAR(50),
    CONSTRAINT [PK_games] PRIMARY KEY CLUSTERED ([Id] ASC)
);

INSERT INTO [dbo].[games] (Id, Name)
VALUES (5, 'Genshin Impact');
