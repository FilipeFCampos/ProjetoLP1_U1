CXX = g++
override CXXFLAGS += -g -Wall -pedantic

SRCS = ./classes/astronauta.o ./classes/voo.o ./classes/gerenciador.o functions.o main.o
HEADERS = ./libraries/classes.hpp ./libraries/functions.hpp

astronauta.o: $(HEADERS) ./classes/astronauta.cpp
	$(CXX) $(CXXFLAGS) astronauta.cpp -c

voo.o: $(HEADERS) ./classes/voo.cpp
	$(CXX) $(CXXFLAGS) voo.cpp -c

gerenciador.o: $(HEADERS) ./classes/gerenciador.cpp
	$(CXX) $(CXXFLAGS) gerenciador.cpp -c

functions.o: $(HEADERS) functions.cpp
	$(CXX) $(CXXFLAGS) functions.cpp -c

main.o: $(HEADERS) main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -c

projeto: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"

clean:
	rm -f projeto *.o ./classes/*.o

clean-projeto:
	rm -f projeto

clean-obj:
	rm -f *.o ./classes/*.o