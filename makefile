CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
LIBFLAGS= -lsfml-graphics -lsfml-window -lsfml-system
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
EXEC= main 


all: $(EXEC)


$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(LIBFLAGS)   

%.o: %.cc
	$(CC) -o $@ -c $<

.depend:
	g++ $(CCFLAGS) -MM $(SRC) > .depends
-include .depends

clean:
	rm -f $(OBJ) $(EXEC)	