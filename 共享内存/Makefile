.PHONY:all
all:server clinet
server:comm.c server.c
	gcc -o $@ $^
clinet: comm.c client.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -f clinet server

#cc=gcc
#cli=client
#ser=server
#cliSrc=comm.c client.c
#serSrc=comm.c server.c
# 
#.PHONY:all
#all:$(cli) $(ser)
#$(cli):$(cliSrc)
#	$(cc) -o $@ $^
#$(ser):$(serSrc)
#	$(cc) -o $@ $^
#.PHONY:clean
#clean:
#	rm -f $(cli) $(ser)
