p04_regular_expressions: p04_regular_expressions.o comment.o variable.o statement.o funciones.o program.o modify.o
	g++ -o $@ $^

%.o: %.cc
	g++ -c $^

clean:
	rm *.o p04_regular_expressions
