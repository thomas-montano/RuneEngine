CXX = g++-5
CXXFLAGS = -std=c++17
EXE = PrivateEye.exe
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

ODIR = obj

SOURCES=$(wildcard *.cpp Engine/*.cpp)
_OBJECTS=$(SOURCES:.cpp=.o)
OBJECTS = $(patsubst %,$(ODIR)/%,$(_OBJECTS))

$(ODIR)/%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXE) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(ODIR)/*.o $(ODIR)/Engine/*.o -o $(EXE) $(LDLIBS)

clean:
	rm -f $(OBJECTS)
