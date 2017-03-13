CC=g++
CC_FLAGS=-Wall -Werror -ansi -pedantic

all: And Test Command Connector Pipe RedirectInput OutputRedirectA OutputRedirectO Or Always Shell main
	
Always:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/Always.cpp -o bin/Always.o

And:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/And.cpp -o bin/And.o

Test:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/Test.cpp -o bin/Test.o

Command:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/Command.cpp -o bin/Command.o

Connector:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/Connector.cpp -o bin/Connector.o

Pipe:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/Pipe.cpp -o bin/Pipe.o

RedirectInput:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/RedirectInput.cpp -o bin/RedirectInput.o

OutputRedirectO:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/OutputRedirectO.cpp -o bin/OutputRedirectO.o

OutputRedirectA:
	mkdir -p bin
	$(CC) -c $(CC_FLAGS) src/OutputRedirectA.cpp -o bin/OutputRedirectA.o

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
