all: server.out client.out

server.out: ServerInit.o Classified.o Distances.o FileReader.o kNearestNeighbors.o Server.o Parser.o StringValidation.o
	g++ ServerInit.o Classified.o Distances.o FileReader.o kNearestNeighbors.o Parser.o Server.o StringValidation.o -o server.out -std=c++11


client.out: ClientInit.o Client.o StringValidation.o
	g++ ClientInit.o Client.o StringValidation.o -o client.out -std=c++11

Client.o: Client.cpp
	g++ -c Client.cpp -std=c++11

ClientInit.o: ClientInit.cpp ClientInit.h
	g++ -c ClientInit.cpp -std=c++11

Server.o: Server.cpp
	g++ -c Server.cpp -std=c++11

kNearestNeighbors.o: kNearestNeighbors.cpp kNearestNeighbors.h
	g++ -c kNearestNeighbors.cpp -std=c++11

Classified.o: Classified.cpp Classified.h
	g++ -c Classified.cpp -std=c++11

FileReader.o: FileReader.cpp FileReader.h
	g++ -c FileReader.cpp -std=c++11

ServerInit.o: ServerInit.cpp ServerInit.h
	g++ -c ServerInit.cpp -std=c++11

Distances.o: Distances.cpp Distances.h
	g++ -c Distances.cpp -std=c++11

Parser.o: Parser.cpp Parser.h
	g++ -c Parser.cpp -std=c++11

StringValidation.o: StringValidation.cpp StringValidation.h
	g++ -c StringValidation.cpp -std=c++11

clean:
	rm *.o a.out

