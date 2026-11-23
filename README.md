# Quintana v1

Quintana v1 is a lightweight command-line chatbot written in C. It stores keywords in a binary search tree and selects a random response when a matching keyword is found in the user's input.

## Features

- Binary search tree implementation for keyword storage
- Keyword matching with case-insensitive input parsing
- Multiple responses for each keyword
- Randomized response selection
- Graceful memory cleanup when the program exits
- Interactive terminal conversation loop

## Supported Keywords

`hello`, `help`, `code`, `bug`, `error`, `work`, `tired`, `idea`, `learn`, `status`, `joke`, `time`, `why`, `thanks`, and `bye`

## Build

Compile the program with GCC:

```sh
gcc -Wall -Wextra -g quintana.c -o quintana
```

## Run

```sh
./quintana
```

Type a message and press Enter. Quintana checks the words in your message for a supported keyword. Type `bye` to exit.

## Example

```text
Quintana v1.0
Quintana Online: How can I help you?
You: hello
Quintana: Hey there. I'm really glad you're here—what's on your mind?
You: bye
Quintana: Okay, take care of yourself. I'll be right here whenever you want to talk again.
```

## Project Structure

- `quintana.c` — chatbot implementation
- `README.md` — project documentation
