CXX = clang++
override CXXFLAGS += -g -Wall -pedantic -fsanitize=address

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

projeto-debug: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -U_FORTIFY_SOURCE -O0 $(SRCS) -o "$@"

clean:
	rm -f projeto projeto-debug