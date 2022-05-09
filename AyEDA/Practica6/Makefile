SOURCES  := $(wildcard *.cc)
OBJS     := $(subst .cc,.o,$(SOURCES))

p06_binary_tree: $(OBJS)
	g++ -o $@ $^

%.o: %.cc
	g++ -c $^

clean:
	rm -rf *.o p06_binary_tree