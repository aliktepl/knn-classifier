CC := g++
CFLAGS := -std=c++11

SOURCES := $(wildcard *.cpp)
OBJECTS := $(patsubst %.cpp, %.o, $(SOURCES))

client_OBJS := $(filter-out Server.o, $(OBJECTS))
server_OBJS := $(filter-out Client.o, $(OBJECTS))

all: client.out server.out

client.out: $(client_OBJS)
	$(CC) $^ -o $@

server.out: $(server_OBJS)
	$(CC) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f client.out server.out $(OBJECTS)
