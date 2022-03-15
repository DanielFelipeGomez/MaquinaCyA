SOURCES  := $(wildcard *.cc)
OBJS     := $(subst .cc,.o,$(SOURCES))

p01_game_of_life: $(OBJS)
	g++ -o $@ $^

%.o: %.cc
	g++ -c $^

clean:
	rm -rf *.o p01_game_of_life