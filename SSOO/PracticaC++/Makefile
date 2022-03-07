OBJS_COMMON	:= socket.o tools.o file.o
OBJS_RECEIVE	:= viewnetreceive.o
OBJS_SEND	:= viewnetsend.o

programas: viewnetsend viewnetreceive

viewnetreceive: $(OBJS_RECEIVE) $(OBJS_COMMON)
	g++ -o $@ $^

viewnetsend: $(OBJS_SEND) $(OBJS_COMMON)
	g++ -o $@ $^

%.o: %.cc
	g++ -c $^

.PHONY: clean
clean:
	rm -rf viewnetreceive viewnetsend *.o