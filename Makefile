CC=g++
CC_FLAGS=-Wall -Werror -ansi -pedantic

all: And Command Connector Or Always Shell main
	
Always:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/Always.cpp -o bin/Always.o

And:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/And.cpp -o bin/And.o

Command:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/Command.cpp -o bin/Command.o

Connector:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/Connector.cpp -o bin/Connector.o

Shell:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/Shell.cpp -o bin/Shell.o

main: 
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/main.cpp -o bin/main.o
	$(CC) bin/*.o -o bin/rshell

Or:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/Or.cpp -o bin/Or.o

clean:
	rm -rf bin
