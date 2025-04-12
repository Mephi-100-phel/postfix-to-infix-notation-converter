#INTERMEDIATE for static lib
.INTERMEDIATE: main.o process.o vector.o list.o static_list.a static_vector.a

#INTERMEDIATE for dynamic lib
.INTERMEDIATE: PIC_list.o PIC_process.o PIC_vector.o

LIB=static
STRUCT=vector

#IF CASES

all:
ifeq ($(LIB), static)
ifeq ($(STRUCT), vector)
	make static_vector
endif
ifeq ($(STRUCT), list)
	make static_list
endif
endif
ifeq ($(LIB), dynamic)
ifeq ($(STRUCT), vector)
	make dynamic_vector
endif
ifeq ($(STRUCT), list)
	make dynamic_list
endif
endif

#DYNAMIC

dynamic_vector: main.o dynamic_vector.so
	gcc -g -o lab2.out main.o dynamic_vector.so -Wl,-rpath,. 

dynamic_vector.so: PIC_process.o PIC_vector.o
	gcc -shared -o dynamic_vector.so PIC_process.o PIC_vector.o

dynamic_list: main.o dynamic_list.so
	gcc -g -o lab2.out main.o dynamic_list.so -Wl,-rpath,.

dynamic_list.so: PIC_process.o PIC_list.o
	gcc -shared -o dynamic_list.so PIC_process.o PIC_list.o

PIC_process.o:
	gcc -c -fPIC process.c -o PIC_process.o

PIC_vector.o:
	gcc -c -fPIC ./vector/vector_stack.c -o PIC_vector.o

PIC_list.o:
	gcc -c -fPIC ./list/list_stack.c -o PIC_list.o

#STATIC

static_vector: main.o static_vector.a
	gcc -g -o lab2.out main.o static_vector.a -I.

static_vector.a: vector.o process.o
	ar cr static_vector.a vector.o process.o

static_list: main.o static_list.a
	gcc -g -o lab2.out main.o static_list.a -I.

static_list.a: list.o process.o
	ar cr static_list.a list.o process.o

process.o:
	gcc -c process.c

vector.o:
	gcc -c ./vector/vector_stack.c -o vector.o

list.o:
	gcc -c ./list/list_stack.c -o list.o

#UNIVERSAL

main.o:
	gcc -c main.c

#CLEAN

clean:
	rm -f *.o *.so *.out *.a

