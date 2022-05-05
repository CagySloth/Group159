FLAGS = -pedantic-errors -std=c++11

data_struct.o: data_struct.cpp data_struct.h
	g++ $(FLAGS) -c $<

accessories.o: accessories.cpp accessories.h data_struct.h
	g++ $(FLAGS) -c $<

board.o: board.cpp board.h data_struct.h
	g++ $(FLAGS) -c $<

cards.o: cards.cpp cards.h data_struct.h
	g++ $(FLAGS) -c $<

equipment.o: equipment.cpp equipment.h data_struct.h
	g++ $(FLAGS) -c $<

combat.o: combat.cpp combat.h data_struct.h equipment.h accessories.h cards.h
	g++ $(FLAGS) -c $<

control.o: control.cpp control.h data_struct.h board.h
	g++ $(FLAGS) -c $<

saveandload.o: saveandload.cpp saveandload.h data_struct.h
	g++ $(FLAGS) -c $<

main.o: main.cpp data_struct.h board.h combat.h control.h
	g++ $(FLAGS) -c $<

main: main.o data_struct.o board.o combat.o control.o saveandload.o
	g++ $(FLAGS) $^ -o main

clean:
	rm -f main main.o data_struct.o accessories.o board.o cards.o equipment.o combat.o control.o main.tgz

tar:
	tar -czvf main.tgz *.cpp *.h

.PHONY: clean tar