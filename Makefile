CXX = g++
override CXXFLAGS += -g -Wall -pedantic

SRCS = classes.o functions.o main.o
HEADERS = classes.hpp functions.hpp

classes.o: $(HEADERS) classes.cpp
	$(CXX) $(CXXFLAGS) classes.cpp -c

functions.o: $(HEADERS) functions.cpp
	$(CXX) $(CXXFLAGS) functions.cpp -c

main.o: $(HEADERS) main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -c

projeto: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"

clean:
	rm -f projeto *.o

clean-projeto:
	rm -f projeto

clean-obj:
	rm -f *.o