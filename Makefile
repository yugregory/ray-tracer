CC = clang++
CFLAGS = -ldl -Wall -g -std=c++17

test: test.cpp
	$(CC) $^ $(CFLAGS) -o $@
