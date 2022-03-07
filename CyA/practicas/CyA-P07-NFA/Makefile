SOURCES  := $(wildcard *.cc)
OBJS     := $(subst .cc,.o,$(SOURCES))

p07_nfa_simulator: $(OBJS)
	g++ -o $@ $^

%.o: %.cc
	g++ -c $^

clean:
	rm -rf *.o p07_nfa_simulator