#!/usr/bin/env bash

set -e

XDG_DATA_HOME=${XDG_DATA_HOME:-"$HOME/.local/share"}
APPLICATION_PREFIX="$XDG_DATA_HOME/ChatBot"
APPLICATION_DATABASE="$APPLICATION_PREFIX/chat-database.sqlite3"

echo "Removing old database: $APPLICATION_DATABASE"; rm "$APPLICATION_DATABASE"

for sql in $(find db-bootstrap-data/ -name *.sql | sort); do
    echo "Applying next SQL: $sql"
    sqlite3 "$APPLICATION_DATABASE" < "$sql"
done

echo "Copying bootstrapped database: $APPLICATION_DATABASE"; cp "$APPLICATION_DATABASE" .

exit $?

