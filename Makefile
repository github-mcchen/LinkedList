#Makefile编译模板，根据实际需要修改
CC:=gcc

LIB= singlelinkedlist.so
LDCFLAG+=-fPIC

all:$(LIB)

src:=$(wildcard ./*.c)
obj=$(patsubst %.c,%.o,$(src))

$(obj):$(src)
	${CC} -c $< -o $@
	
$(LIB):$(obj)
	${CC} -o $@ $^ ${LDCFLAG}

clean:
	rm -rf ./*.o $(LIB)

.PHONY : all clean
	