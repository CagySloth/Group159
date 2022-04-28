FLAGS = -pedantic-errors -std=c++11

struct.o: struct.cpp struct.h
	g++ $(FLAGS) -c $<

accessories.o: accessories.cpp accessories.h struct.h
	g++ $(FLAGS) -c $<

board.o: board.cpp board.h
	g++ $(FLAGS) -c $<

cards.o: cards.cpp cards.h struct.h
	g++ $(FLAGS) -c $<

equipment.o: equipment.cpp equipment.h struct.h
	g++ $(FLAGS) -c $<

combat.o: combat.cpp combat.h struct.h equipment.h accessories.h cards.h
	g++ $(FLAGS) -c $<

control.o: control.cpp control.h struct.h board.h
	g++ $(FLAGS) -c $<

main.o: main.cpp struct.h board.h combat.h control.h
	g++ $(FLAGS) -c $<

clean:
	rm -f main main.o struct.o accessories.o board.o cards.o equipment.o combat.o control.o main.tgz

tar:
	tar -czvf main.tgz *.cpp *.h

.PHONY: clean tar