--- Diaseases ---

CREATE TABLE IF NOT EXISTS 'Diaseases' (
    'id' INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    'diasease_item_id' INTEGER NOT NULL,
    'diasease_symptom_id' INTEGER NOT NULL,
    FOREIGN KEY ('diasease_item_id') REFERENCES 'DiaseasesItems' ('id'),
    FOREIGN KEY ('diasease_symptom_id') REFERENCES 'DiaseasesSymptoms' ('id')
);

--- Special Cases ---
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(1, 3);
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(2, 2);
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(3, 2);
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(4, 2);
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(5, 1);

--- Common Cases: Caugh ---
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(6, 3);
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(6, 4);
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(6, 5);

--- Common Cases: Sore Throat
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(7, 3);
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(7, 4);
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(7, 5);

--- Common Cases: Temperature
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(8, 1);
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(8, 2);
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(8, 3);
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(8, 4);
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(8, 5);

--- Common Cases: Runny Nose
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(9, 4);
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(9, 5);

--- Common Cases: Algidity
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(10, 1);
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(10, 2);
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(10, 3);
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(10, 4);
INSERT INTO 'Diaseases' ('diasease_symptom_id', 'diasease_item_id') VALUES(10, 5);

