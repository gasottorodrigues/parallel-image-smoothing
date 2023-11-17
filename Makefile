CC=gcc
CFLAGS= -Wall -g
TARGET= main
MAIN = main.c
SRCS = lib/screen/screen.c
INCLUDES=lib/screen/screen.h

$(TARGET):$(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -o $(TARGET) $(MAIN) $(SRCS)

clean:
	rm -f $(TARGET)