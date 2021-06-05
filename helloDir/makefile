# := 恒等 = 赋值 $^ 所有依赖文件 $@ 所有目标文件 .PHONY 伪目标 $< 第一个依赖文件
# %.c 任意一个.c文件 *.c所有的.c文件

TAR = hello
cc := gcc
RMRF := rm -rf
OBJ = hello.o sub.o add.o 
FLAG := -c -g 

$(TAR):$(OBJ)
	$(cc) $^ -o $@
%.o:%.c  
	$(cc) $(FLAG) $^ -o $@

.PHONY:
clean:
	$(RMRF) $(TAR) $(OBJ)
