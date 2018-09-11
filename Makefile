CC = clang++
CFLAGS = -ldl -Wall -g -std=c++17

raytracer: raytracer.cpp
  $(CC) $^ $(CFLAGS) -o $@
test: test.cpp
	$(CC) $^ $(CFLAGS) -o $@
