SOURCES = src/main.cpp src/graph.cpp src/helper.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    g++ -o $(EXECUTABLE) $(OBJECTS)

$(OBJECTS): $(SOURCES)
    g++ -c $(SOURCES) -I include