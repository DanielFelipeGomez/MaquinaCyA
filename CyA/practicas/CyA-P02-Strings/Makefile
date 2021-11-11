SOURCES  := $(wildcard *.cc)
OBJS     := $(subst .cc,.o,$(SOURCES))

p02_strings: $(OBJS)
	g++ -o $@ $^

%.o: %.cc
	g++ -c $^

clean:
	rm *.o p02_strings