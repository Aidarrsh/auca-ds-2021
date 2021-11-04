src = $(wildcard *.cpp)

CXXFLAGS = -g -std=c++11 -Wall -Wextra -Wshadow -pedantic -D_GLIBCXX_DEBUG -fsanitize=address -fsanitize=undefined
CXXRLSFLAGS = -O2 -std=c++11 -Wall -Wextra -Wshadow -pedantic

main: $(src)
	$(CXX) -o $@ $(CXXFLAGS) $^

.PHONY: release
release:
	$(CXX) -o main $(CXXRLSFLAGS) $(src)

.PHONY: clean
clean:
	rm -f main
