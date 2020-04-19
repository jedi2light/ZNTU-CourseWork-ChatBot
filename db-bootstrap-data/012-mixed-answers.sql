--- Answers ---

CREATE TABLE IF NOT EXISTS 'Answers' (
    'id' INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    'phrase' TEXT NOT NULL,
    'keyword_id' INTEGER NOT NULL,
    FOREIGN KEY ('keyword_id') REFERENCES 'Keywords' ('id')
);

INSERT INTO 'Answers' ('phrase', 'keyword_id') VALUES('How do you do. Please state your problem.', 1);
INSERT INTO 'Answers' ('phrase', 'keyword_id') VALUES('What would it mean if you got %1"', 2);
INSERT INTO 'Answers' ('phrase', 'keyword_id') VALUES('Why do you want %1', 2);
INSERT INTO 'Answers' ('phrase', 'keyword_id') VALUES('Suppose you got %1 soon"', 2);
INSERT INTO 'Answers' ('phrase', 'keyword_id') VALUES('Do you really think its likely that %1', 3);
INSERT INTO 'Answers' ('phrase', 'keyword_id') VALUES('Do you wish that %1', 3);
INSERT INTO 'Answers' ('phrase', 'keyword_id') VALUES('What do you think about %1', 3);
INSERT INTO 'Answers' ('phrase', 'keyword_id') VALUES('Really-- if %1', 3);
INSERT INTO 'Answers' ('phrase', 'keyword_id') VALUES('Why not?', 4);
INSERT INTO 'Answers' ('phrase', 'keyword_id') VALUES('You are being a bit negative', 4);
INSERT INTO 'Answers' ('phrase', 'keyword_id') VALUES('Are you saying NO just to be negative?', 4);
INSERT INTO 'Answers' ('phrase', 'keyword_id') VALUES('Were you really?', 5);
INSERT INTO 'Answers' ('phrase', 'keyword_id') VALUES('Perhaps I already knew you were %1', 5);
INSERT INTO 'Answers' ('phrase', 'keyword_id') VALUES('Why do you tell me you were %1 now?', 5);
INSERT INTO 'Answers' ('phrase', 'keyword_id') VALUES('Do you often feel %1?', 6);
INSERT INTO 'Answers' ('phrase', 'keyword_id') VALUES('What other feelings do you have?', 7);

