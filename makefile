CC=g++
CCFLAGS=-g -std=c++11 -D_BSD_SOURCE -Wall

TARGETS=server_tcp client_tcp server_udp client_upd clean

all: $(TARGETS)

server_tcp: server_tcp.o common.o common.h
	$(CC) $(CCFLAGS) -o $@ $^

server_tcp.o: server_tcp.cpp common.h
	$(CC) $(CCFLAGS) -c $<

client_tcp: client_tcp.o common.o common.h
	$(CC) $(CCFLAGS) -o $@ $^

client_tcp.o: client_tcp.cpp common.h
	$(CC) $(CCFLAGS) -c $<

server_udp: server_udp.o common.o common.h
	$(CC) $(CCFLAGS) -o $@ $^

server_udp.o: server_udp.cpp common.h
	$(CC) $(CCFLAGS) -c $<

client_upd: client_upd.o common.o common.h
	$(CC) $(CCFLAGS) -o $@ $^

client_upd.o: client_upd.cpp common.h
	$(CC) $(CCFLAGS) -c $<

common.o: common.cpp common.h 
	$(CC) $(CCFLAGS) -c $<

clean:
	rm -rf *.o