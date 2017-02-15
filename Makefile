CC=g++
CC_FLAGS=-Wall -ansi

all: And Command Connector Or Always main
	
Always:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/main.cpp -o bin/Always.o

And:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/And.cpp -o bin/And.o

Command:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/Command.cpp -o bin/Command.o

Connector:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/Connector.cpp -o bin/Connector.o

main: 
	mkdir -p bin
	$(CC) src/*.o -o bin/rshell

Or:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/Or.cpp -o bin/Or.o

clean:
	rm -rf bin
