CC=gcc
CFLAGS=-I.

DEPS = AgariChecker.h Calculator.h main.h BasicType.h majsa.h Trans.h YakuChecker.h

OBJS = AgariChecker.o Calculator.o main.o majsa.o Trans.o YakuChecker.o

EXEC = MyMajChecker

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	del $(OBJS) $(EXEC).exe

.PHONY: all clean
