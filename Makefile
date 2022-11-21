CC=gcc
AR=ar
FLAGS= -Wall -c -g
OBJECTS_MAIN=main.o
OBJECTS_MAT=my_mat.o
LIB_S_MAT=libmymats.a

all: main.o $(OBJECTS_MAT) $(LIB_S_MAT)
main.o:
	$(CC) $(FLAGS) main.c -o $(OBJECTS_MAIN)

$(OBJECTS_MAT):
	$(CC) $(FLAGS) my_mat.c -o $(OBJECTS_MAT)

$(LIB_S_MAT):
	$(AR) rcs $(LIB_S_MAT) $(OBJECTS_MAIN) $(OBJECTS_MAT)

.PHONY: clean all
	
clean:
	rm -f *.o *.a "mains"
