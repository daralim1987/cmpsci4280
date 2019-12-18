CC = gcc
CFLAGS = -g -Wall
TARGET = comp
OBJ = main.o scanner.o parser.o codeCreator.o testTree.o staticSemanticStack.o

%.o: %.c
	$(CC) $(CFLAGS) -c $<

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c createNode.h parser.h testTree.h codeCreator.h
scanner.o: scanner.c alphab.h createToken.h testTree.h scanner.h
parser.o: parser.c createToken.h createNode.h scanner.h testTree.h parser.h
codeCreator.o: codeCreator.c createToken.h createNode.h staticSemanticStack.h testTree.h codeCreator.h
testTree.o: testTree.c createToken.h createNode.h testTree.h
staticSemanticStack.o: staticSemanticStack.c staticSemanticStack.h

clean:
	rm -f $(TARGET) $(OBJ)
