--- Keywords ---

CREATE TABlE IF NOT EXISTS 'Keywords' (
    'id' INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    'name' VARCHAR NOT NULL
);

INSERT INTO 'Keywords' ('name') VALUES('hello');
INSERT INTO 'Keywords' ('name') VALUES('i want');
INSERT INTO 'Keywords' ('name') VALUES('if');
INSERT INTO 'Keywords' ('name') VALUES('no');
INSERT INTO 'Keywords' ('name') VALUES('i was');
INSERT INTO 'Keywords' ('name') VALUES('i feel');
INSERT INTO 'Keywords' ('name') VALUES('i felt');

