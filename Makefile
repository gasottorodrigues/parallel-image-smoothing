CODE_DIR = src/lib/code
INC_DIR = src/lib
CC=gcc
CFLAGS= -Wall -g -fopenmp
MAIN = src/main.c
SRCS = $(CODE_DIR)/img_matrix.c $(CODE_DIR)/smoothing_filters.c
INCLUDES=$(INC_DIR)/pixel.h $(INC_DIR)/img_matrix.h $(INC_DIR)/smoothing_filters.h
TARGET=program

compile:$(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -o $(TARGET) $(MAIN) $(SRCS)

clean:
	rm -f $(TARGET)