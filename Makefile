# Makefile

SOURCE_PATH = sources
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.hpp)
OBJECTS = $(patsubst %.cpp,%.o,$(SOURCES))
	
all: run

run: build
	@./run

build: $(OBJECTS)
	@clang++ -o run $(OBJECTS)

%.o: %.cpp $(HEADERS)
	@clang++ -c -o $@ $<

clean:
	@echo "Cleaning up..."
	@rm -f *.o run
