--- Stage Schema ---

CREATE TABLE IF NOT EXISTS 'Stage' (
    'id' INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    'stage' VARCHAR NOT NULL,
    'topic' VARCHAR NOT NULL
);
