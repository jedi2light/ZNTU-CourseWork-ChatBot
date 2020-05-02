# How to run

```
# Please ensure that you have installed Qt5 in your system
$ git clone https://github.com/jedi2light/ZNTU-CourseWork-ChatBot.git
# Go to the directory with cloned project
$ cd ZNTU-CourseWork-ChatBot
# Initialize Sqlite3 based database
$ bash db-bootstrap.sh
# Compile and run project executable
$ qmake && make && ./ChatBot
```

# Deployment on Microsoft Windows (7, 8, 10)
1. Just run `db-bootstrap.bat` in project directory, this script will copy `./chat-database.sqlite3` into `%APPDATA\Chatbot` by itself.
2. (OLD SOLUTION) Place pre bootstrapped DB located at `./chat-database.sqlite3` into `%APPDATA%\ChatBot`. If directory does not exist, you need to create it.

# Sample Usage
Take a look at [Sample Usage](SAMPLE_USAGE.md).

# Layout
* Documentation located at `Doc/` directory
* Presentation located at `Assets/Presentation/` directory

# Demo
Go through this link: https://youtu.be/R-HvUBbMWQ4

# TODO: fill with other improtant information ...
