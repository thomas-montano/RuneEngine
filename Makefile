CXX = g++-5
CXXFLAGS = -std=c++17
EXE = PrivateEye.exe
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lglfw3 -lGLEW -lGLU -lGL -pthread -ldl -lGLEW -lrt -lXrandr -lXi -lXinerama -lX11

SRCDIR = ./
ODIR = obj

SOURCES := $(shell find $(SRCDIR) -name "*.cpp")
SOURCES := $(filter-out ./Engine/Renderer/main.cpp , $(SOURCES))

_OBJECTS=$(SOURCES:.cpp=.o)
OBJECTS = $(patsubst %,$(ODIR)/%,$(_OBJECTS))

$(ODIR)/%.o : %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@
$(EXE) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXE) $(LDLIBS)

clean:
	rm -f $(OBJECTS)
