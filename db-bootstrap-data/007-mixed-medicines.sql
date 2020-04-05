--- Medicines ---

CREATE TABLE IF NOT EXISTS 'Medicines' (
    'id' INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    'popc' INTEGER NOT NULL,
    'medicine_id' INTEGER NOT NULL,
    'medicineprovider_id' INTEGER NOT NULL,
    FOREIGN KEY ('medicine_id') REFERENCES 'MedicinesItems' ('id'),
    FOREIGN KEY ('medicineprovider_id') REFERENCES 'MedicinesProviders' ('id')
);

INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(1,1,36);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(1,2,67);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(1,3,63);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(1,4,67);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(1,5,57);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(2,1,23);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(2,2,59);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(2,3,17);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(2,4,35);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(2,5,19);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(3,1,58);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(3,2,37);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(3,3,37);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(3,4,59);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(3,5,58);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(4,1,38);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(4,2,50);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(4,3,38);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(4,4,48);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(4,5,28);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(5,1,58);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(5,2,30);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(5,3,50);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(5,4,23);
INSERT INTO 'Medicines' ('medicineprovider_id', 'medicine_id', 'popc')
    VALUES(5,5,25);

