--- Diaseases Symptoms ---

CREATE TABLE IF NOT EXISTS 'DiaseasesSymptoms' (
    'id' INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    'name' VARCHAR NOT NULL,
    'important' INTEGER NOT NULL
);

INSERT INTO 'DiaseasesSymptoms' ('name', 'important') VALUES('labored breathing', 1);
INSERT INTO 'DiaseasesSymptoms' ('name', 'important') VALUES('stomach ache', 1);
INSERT INTO 'DiaseasesSymptoms' ('name', 'important') VALUES('heartburn', 1);
INSERT INTO 'DiaseasesSymptoms' ('name', 'important') VALUES('burping', 1);
INSERT INTO 'DiaseasesSymptoms' ('name', 'important') VALUES('body rash', 1);
INSERT INTO 'DiaseasesSymptoms' ('name', 'important') VALUES('cough', 0);
INSERT INTO 'DiaseasesSymptoms' ('name', 'important') VALUES('sore throat', 0);
INSERT INTO 'DiaseasesSymptoms' ('name', 'important') VALUES('temperature', 0);
INSERT INTO 'DiaseasesSymptoms' ('name', 'important') VALUES('runny nose', 0);
INSERT INTO 'DiaseasesSymptoms' ('name', 'important') VALUES('algidity', 0);

