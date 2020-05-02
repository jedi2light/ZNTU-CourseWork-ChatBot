@echo off

rem Set environment
set APPLICATION_DATAPATH="%APPDATA%\ChatBot"
set APPLICATION_DATAVASE="chat-database.sqlite3"

rem Show environment
echo "Application Data Path is: %APPLICATION_DATAPATH%, Application Database is:  %APPLICATION_DATAVASE%"

rem Create application data path directory if not exist
if not exist "%APPLICATION_DATAPATH%" (
    md "%APPLICATION_DATAPATH%"
)

rem Copy databasae into application data path directory
copy "%APPLICATION_DATAVASE%" "%APPLICATION_DATAPATH%"

pause
