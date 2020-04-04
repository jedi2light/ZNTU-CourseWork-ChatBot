--- Topics Schema ---

CREATE TABLE IF NOT EXISTS "Topics" (
    'id' INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    'name' VARCHAR NOT NULL,
    'icon_id' INTEGER NOT NULL,
    FOREIGN KEY ('icon_id') REFERENCES 'TopicIcon' ('id')
);

