FLAGS = -pedantic-errors -std=c++11
TARGET = main

board.o: board.cpp board.h
	g++ $(FLAGS) -c $<

mobs.o: mobs.cpp mobs.h
	g++ $(FLAGS) -c $<

main.o: main.cpp board.h mobs.h
	g++ $(FLAGS) -c $<

$(TARGET): main.o board.o mobs.o
	g++ $(FLAGS) $^ -o $(TARGET)

clean:
	rm -f main main.o board.o mobs.o main.tgz

tar:
	tar -czvf main.tgz *.cpp *.h

.PHONY: clean tar