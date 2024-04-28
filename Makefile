all: main

CXX = clang++
override CXXFLAGS += -g -Wmost -Werror -Wall -fsanitize=address

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.o' -print | sed -e 's/ /\\ /g')
HEADERS = $(classes.hpp functions.hpp)

classes.o: $(HEADERS)
	$(CXX) $(CXXFLAGS) classes.cpp -c

functions.o: $(HEADERS)
	$(CXX) $(CXXFLAGS) functions.cpp -c

main.o: $(HEADERS)
	$(CXX) $(CXXFLAGS) main.cpp -c

main: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"
	rm *.o

main-debug: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -U_FORTIFY_SOURCE -O0 functions.cpp classes.cpp main.cpp -o "$@"

clean:
	rm -f main main-debug