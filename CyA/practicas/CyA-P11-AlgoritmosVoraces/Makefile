SOURCES  := $(wildcard *.cc)
OBJS     := $(subst .cc,.o,$(SOURCES))

ProblemaMochila: $(OBJS)
	g++ -o $@ $^

%.o: %.cc
	g++ -c $^

delete:
	rm -rf *.o ProblemaMochila
