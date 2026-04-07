# User Management System

A command-line user management system built in C, focused on dynamic memory allocation and binary file persistence.

## About

This project was built to practice low-level concepts in C — dynamic memory with malloc/realloc/free, binary file I/O with fwrite/fread, and modular code organization with header files.

## Features

- Add users with name, email and age
- List all users in a formatted table
- Persistent storage — data is saved and loaded automatically from a binary file
- Dynamic memory — list expands automatically using realloc when needed

## Concepts practiced

- Dynamic memory allocation (malloc, realloc, free)
- Binary file I/O (fwrite, fread)
- Structs and pointers
- Header files and modular architecture
- Makefile

## Technologies

- C
- GCC
- Make

## How to run
```
\bash
git clone https://github.com/Wellzx/user-management-c.git
cd user-management-c
make
./user_manager
```
## Usage
```
1. Add User
2. List Users
3. Exit
```
Data is automatically saved to `users.bin` on exit and loaded on startup.
