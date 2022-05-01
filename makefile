#把所有的目录做成变量，方便修改和移植   
BIN = ./bin  
SRC = ./src  
INC = ./inc
OBJ = ./obj

#提前所有源文件(即：*.c文件)和所有中间文件(即：*.o)  
#SOURCE = $(wildcard ${SRC}/*.c)  
SOURCE = $(shell find . -name *.c)
OBJECT = $(patsubst %.c,${OBJ}/%.o,$(notdir ${SOURCE}))  

#设置最后目标文件  
TARGET = main  
BIN_TARGET = ${BIN}/${TARGET}  

CC = gcc   
CFLAGS = -g -Wall -I${INC}   

#用所有中间文件生成目的文件，规则中可以用 $^替换掉 ${OBJECT}  
${BIN_TARGET}:${OBJECT}  
	$(CC) -o $@ ${OBJECT}  

#生成各个中间文件  
${OBJ}/%.o:${SOURCE}
	$(CC) $(CFLAGS) -o $@ -c $<  

.PHONY:clean  
clean:  
	find $(OBJ) -name *.o -exec rm -rf {} \; #这个是find命令，不懂的可以查下资料  
	rm -rf $(BIN_TARGET)  
