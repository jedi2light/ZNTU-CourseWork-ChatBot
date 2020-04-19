--- Diaseases Items ---

CREATE TABLE IF NOT EXISTS 'DiaseasesItems' (
    'id' INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    'name' VARCHAR NOT NULL
);

INSERT INTO 'DiaseasesItems' ('name') VALUES('Chickenpox');
INSERT INTO 'DiaseasesItems' ('name') VALUES('Gastritis');
INSERT INTO 'DiaseasesItems' ('name') VALUES('COVID-19');
INSERT INTO 'DiaseasesItems' ('name') VALUES('ARI');
INSERT INTO 'DiaseasesItems' ('name') VALUES('Cold');

