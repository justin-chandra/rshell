CC=g++
CC_FLAGS=-Wall -ansi

all: main Always And Command Connector Or
	
Always:
	mkdir -p bin
	$(CC) $(C_FLAGS) src/main.cpp -o bin/Always

And:
	mkdir -p bin
	$(CC) $(C_FLAGS) src/And.cpp -o bin/And

Command:
	mkdir -p bin
	$(CC) $(C_FLAGS) src/Command.cpp -o bin/Command

Connector:
	mkdir -p bin
	$(CC) $(C_FLAGS) src/Connector.cpp -o bin/Connector

main: 
	mkdir -p bin
	$(CC) $(C_FLAGS) src/main.cpp -o bin/rshell

Or:
	mkdir -p bin
	$(CC) $(C_FLAGS) src/Or.cpp -o bin/Or

clean:
	rm -rf bin
