f = 
out = s
G =

all:
ifeq ($(G),)
	@gcc $(f) lib/queue.c lib/stack.c -o $(out)
else
	@gcc $(f) lib/queueGenerica.c lib/stack.c -o $(out)
endif
