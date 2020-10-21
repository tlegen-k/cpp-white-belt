## C++ White Belt Course Project
This repository contains my course project for [C++ course](https://www.coursera.org/learn/c-plus-plus-yellow/home/welcome)

### Task
It is necessary to write a program in C ++ that implements work with a simple database (abbreviated as "DB"). The program will communicate with the user via standard input and output (stdin and stdout streams).

We will store pairs of the following type in our database: date, event. Let's define the date as a string of the Year-Month-Day type, where Year, Month and Day are integers.

The event is defined as a string of arbitrary printable characters without delimiters inside (spaces, tabs, etc.). The event cannot be an empty string. Many different events can occur on the same date, the database must be able to save them all. It is not necessary to save identical events that occurred on the same day: it is enough to save only one of them.

Our database needs to understand certain commands in order to interact with it:
```cpp
- Add event:                            Add Date Event
- Delete event:                         Del Date Event
- Delete all events in date:            Del Date
- Find events in date:                  Find Date
- Print all events:                     Print
```
All commands, dates and events are separated by spaces as you type. Commands are read from standard input. There can be exactly one command on one line, but you can enter multiple commands on multiple lines. Blank lines can also come in - ignore them and continue processing new commands on subsequent lines.
### Add event (Add Date Event)

When adding an event, the database must remember it and then show it when searching (using the Find command) or printing (using the Print command). If the specified event already exists for the given date, re-adding it should be ignored. If the input is correct (see the section "Handling Input Errors"), the program should not display anything on the screen.
### Delete event (Del Date Event)

The command must remove the previously added event with the specified name on the specified date, if it exists. If the event is found and deleted, the program should print the string "Deleted successfully" (without quotes). If the event is not found on the specified date, the program should display the string "Event not found" (without quotes).
### Delete multiple events (Del Date)

The command removes all previously added events for the specified date. The program should always output a line like "Deleted N events", where N is the number of all found and deleted events. N can be zero if there were no events on the specified date.
### Event Search (Find Date)

Find and print previously added events on a specified date. The program should only print the events themselves, one per line. Events must be sorted in ascending order in the order of comparison between strings (string type).
### Print all events (Print)

Using this command, you can show the complete contents of our database. The program should print all Date Event pairs, one per line. All pairs must be sorted by date, and events within the same date must be sorted in ascending order in the order of string comparison among themselves (string type). Dates must be formatted in a special way: YYYY-MM-DD, where G, M, D are the numbers of the numbers of the year, month and day, respectively. If some number has fewer digits, then it must be padded with zeros, for example, 0001-01-01 - January 1st of the first year. You don't need to output a date with a negative year value.
### Handling Input Errors

The input in this task is not always correct: your program must handle some input errors correctly.
What input errors need to be handled

If the user entered an unknown command, then the program should report this by displaying the line "Unknown command: COMMAND", where COMMAND is the command entered by the user. The command is the first word in the line (up to a space).

If the date does not correspond to the Year-Month-Day format, where Year, Month and Day are arbitrary integers, then the program should print "Wrong date format: DATE", where DATE is what the user entered instead of the date (before a space). Please note that the parts of the date are separated by exactly one hyphen, and the date itself should not contain extra characters either before the year or after the day. Date parts cannot be empty, but they can be zero or even negative.

If the date format is correct, you need to check the validity of the month and day.

- If the month number is not a number from 1 to 12, print "Month value is invalid: MONTH", where MONTH is an invalid month number, for example, 13 or -1.
- If the month is correct and the day does not lie in the range from 1 to 31, print "Day value is invalid: DAY", where DAY is an invalid day number in the month, for example, 39 or 0.

Note that:

- You do not need to check the year value separately.
- There is no need to check the calendar correctness of the date: the number of days in each month is considered equal to 31, leap years need not be taken into account.
- If both the month and the day are wrong, then you need to display one error message per month.

Examples:

- 1-1-1 is a valid date;
- -1-1-1 - correct date (year -1, month 1, day 1);
- 1-1-1 - date in the correct format, but with an incorrect month -1;
- 1 --- 1-1 - date in the wrong format: the month cannot start with two hyphens.
- 1- + 1- + 1 is a valid date, since +1 is an integer

After processing any of the described errors of entering and printing a message, the program should terminate its execution.

Which input errors don't need to be handled

We do not aim to break your program in every possible way, therefore, with the exception of the one described in the previous paragraph, you can rely on correct input. In particular, we guarantee that:

- Each command occupies exactly one line entirely, although there may be blank lines in the input (they must be ignored).
- Events always contain the specified number of arguments: the Add command is always followed by the date and the event, the Find command is always followed by the date, the Del command is always followed by the date and possibly the event, and the Print command does not contain additional information.
- All commands, dates, and events are non-empty strings and do not contain spaces or other whitespace characters. (In particular, our tests do not contain the Add 2018-02-12 command, because it does not contain the event name after the date.) On the other hand, the Del command may not contain events after the date: in this case, you need to delete all events for the specified date (see the section "Deleting several events").
- Despite the fact that a date with a negative year value is considered correct, the tests are designed in such a way that it does not need to be printed in the Print command.
