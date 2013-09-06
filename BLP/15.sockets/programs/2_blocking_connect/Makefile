.SUFFIXES: .o .c
LIBS = -lpthread
CC = gcc

SERVER_OBJECTS = ${SERVER_SOURCE:.c=.o}
SERVER_SOURCE = server_socket.c 

CLIENT_OBJECTS = ${SERVER_SOURCE:.c=.o}
CLIENT_SOURCE = client_socket.c 

.DEFAULT_GOAL := all

.c .o:
	${CC} -O3 -g ${CFLAGS} $< -o $@ 
server: ${SERVER_OBJECTS}
	${CC} -o $@ ${SERVER_OBJECTS} ${LIBS}
client: ${CLIENT_OBJECTS}
	${CC} -o $@ ${CLIENT_OBJECTS} ${LIBS}

all: client server
clean:
	rm -f ${SERVER_OBJECTS} ${CLIENT_OBJECTS} server client server_socket_file 
