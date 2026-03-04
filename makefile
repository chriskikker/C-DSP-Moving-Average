# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LIBS = -lm

# Target executable name
TARGET = dsp_filter

# Source files
SRCS = main.c dsp_filter.c
# Header files (to track changes)
DEPS = dsp_header.h

# Default rule
all: $(TARGET)

# Link the object files into the final executable
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LIBS)

# Clean rule to remove the executable and CSV
clean:
	rm -f $(TARGET) output.csv

# Run rule to execute and generate data
run: all
	./$(TARGET) > output.csv
