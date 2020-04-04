--- Conversations Schema ---

CREATE TABlE IF NOT EXISTS 'Conversations' (
    'id' INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    'author' VARCHAR NOT NULl,
    'recipient' VARCHAR NOT NULL,
    'timestamp' VARCHAR NOT NULL,
    'message' TEXT NOT NULL,
    'icon_id' INTEGER NOT NULL,
    FOREIGN KEY('author') REFERENCES 'Topics' ('name'),
    FOREIGN KEY('recipient') REFERENCES 'Topics' ('name'),
    FOREIGN KEY('icon_id') REFERENCES 'TopicIcon' ('id')
);

