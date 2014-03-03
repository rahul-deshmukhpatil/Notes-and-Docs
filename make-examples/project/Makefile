
objects = a.o b.o \
		c.o
build : $(objects) 
	gcc -o run $(objects)

build-debug: a.o b.o c.o
	gcc -g -o run-debug a.o b.o; \
	echo "compiled !!!"
	
a.o : a.h c.h a.c
	gcc -c a.c

c.o : c.h c.h c.c
	gcc -c c.c

b.o : b.h c.h b.c
	gcc -c b.c

clean :
	rm -rf a.o b.o c.o run run-debug
