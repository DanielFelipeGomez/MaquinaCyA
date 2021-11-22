SOURCES  := $(wildcard *.cc)
OBJS     := $(subst .cc,.o,$(SOURCES))

p08_grammar_arithmetic: $(OBJS)
	g++ -o $@ $^

%.o: %.cc
	g++ -c $^

clean:
	rm -rf *.o p08_grammar_arithmetic