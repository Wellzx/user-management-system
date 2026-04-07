CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = user_manager

all: $(TARGET)

$(TARGET): main.c users.c
	$(CC) $(CFLAGS) main.c users.c -o $(TARGET)

clean:
	rm -f $(TARGET)