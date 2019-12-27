#Makefile编译模板，根据实际需要修改
CC:=gcc

LIB= doublelinkedlist.so
CFLAG+=-I../include
LDCFLAG+=-fPIC
LIB_DIR:=../lib

all:$(LIB) install

src:=$(wildcard ./*.c)
obj=$(patsubst %.c,%.o,$(src))

$(obj):$(src)
	${CC} -c $< -o $@ ${CFLAG}
	
$(LIB):$(obj)
	${CC} -o $@ $^ ${LDCFLAG}

install:
	install -d ${LIB_DIR}
	install -m 755 ${LIB} ${LIB_DIR}
clean:
	rm -rf ./*.o $(LIB)

.PHONY : all clean
	