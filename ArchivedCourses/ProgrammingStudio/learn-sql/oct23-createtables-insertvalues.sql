--no constraints
CREATE TABLE Food (
    Name     TEXT,
    Price    REAL -- double
);


--with constraints
CREATE TABLE Food (
    Name     TEXT,   -- PRIMARY KEY,
    Price    REAL    NOT NULL,
    PRIMARY KEY (Name)
);


DROP TABLE IF EXISTS Food;


INSERT INTO Food
VALUES ('Pho', 60000);


INSERT INTO Food (Price, Name)
VALUES ('Bun Bo', 45000);


DELETE FROM Food
WHERE Name = 45000;


INSERT INTO Food (Price, Name)
VALUES (45000, 'Bun Bo');


--multiple values
INSERT INTO Food
VALUES 
 ('Pho', 60000),
 ('Pho', 60000),
 ('Pho', 60000),
 ('Pho', 60000),
 ('Pho', 60000),
 ('Pho', 60000);
 

INSERT INTO Food
VALUES ('Com tam', NULL);


