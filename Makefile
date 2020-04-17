CXX = g++-5
CXXFLAGS = -std=c++11
EXE = PrivateEye.exe
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SOURCES=$(wildcard *.cpp Engine/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXE) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) *.o Engine/*.o -o $(EXE) $(LDLIBS)

clean:
	rm -f $(OBJECTS)
