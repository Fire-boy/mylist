PROCNAME=list
CC=gcc
CCFLAG=-g
INCLUDE=-I./
LIBDIR=-L./
LIBS=
OBJ=main.o list.o

$(PROCNAME):$(OBJ)
	$(CC) $(CCFLAG) $(OBJ) -o $(PROCNAME) 

.PHONY:clean
clean:
	rm *.o $(PROCNAME)
