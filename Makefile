CC = g++
TARGET = test
OPT = -std=c++17 \
      -DSONG_INPUT \
      -DSONG_TEST \

$(TARGET) : test.o
	$(CC) $(OPT) -o  $(TARGET) test.o

test.o : test.cpp
	$(CC) $(OPT) -o test.o -c test.cpp
clean :
	rm -f *.o $(TARGET)
