IDIR =../include
CXX=clang++
CXXFLAGS=-Wall -O2 -std=c++17 -I$(IDIR)

ODIR=obj
LDIR =../lib
LDFLAGS=-L/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib/
# LIBS=-lm

_DEPS = BoardFlip.h
DEPS = $(patsubst %, $(IDIR)/%,$(_DEPS))

_OBJ = main.o BoardFlip.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

BoardFlip: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS) # $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
