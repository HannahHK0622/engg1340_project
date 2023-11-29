FLAGS = -pedantic-errors -std=c++11

gamelogic.o: gamelogic.cpp gamelogic.h
	g++ $(FLAGS) -c gamelogic.cpp

supertiktaktoe.o: supertiktaktoe.cpp gamelogic.h gameobj.h
	g++ $(FLAGS) -c supertiktaktoe.cpp

supertiktaktoe: supertiktaktoe.o gamelogic.o
	g++ $(FLAGS) supertiktaktoe.o gamelogic.o -o supertiktaktoe

clean:
	rm -f supertiktaktoe supertiktaktoe.o gamelogic.o

.PHONY: clean