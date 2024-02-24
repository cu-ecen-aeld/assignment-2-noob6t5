#Make file for Writer.C aarch64-linux-gnu


#$for Compiluer
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall  -O2 -Wmissing-declarations -Wmissing-prototypes

SRCS = writer.c      #filename
TARGET = writer

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

ifdef CROSS_COMPILE
CC := $(CROSS_COMPILE)gcc
endif
