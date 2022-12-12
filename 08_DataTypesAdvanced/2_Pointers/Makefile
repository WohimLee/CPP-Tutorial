


cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst %.cpp,%.o,$(cpp_srcs))
cpp_objs := $(subst src/,objs/,$(cpp_objs))


compile_I := 
link_L := 
link_l :=  


compile_I := $(foreach item,$(compile_I),-I$(item))
link_r := $(foreach item,$(link_L),-Wl,-rpath=$(item))
link_L := $(foreach item,$(link_L),-L$(item))
link_l := $(foreach item,$(link_l),-l$(item))


compile_flags := -m64 -O3 -g -fpic -std=c++11 $(compile_I)
link_flags    := $(link_L) $(link_l) $(link_r)


debug :
	@echo $(compile_flags)


#-------------------- 统一编译成.o文件
objs/%.o : src/%.cpp
	@echo Compile Source to Objects
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@ $(compile_flags)


objects : $(cpp_objs)


#-------------------- 编静态库

lib/libmyfuncstatic.a : objs/func.o
	@echo Compile Objects to Static Lib
	@mkdir -p $(dir $@)
	@ar -r $@ $< 

static : lib/libmyfuncstatic.a

#-------------------- 编动态库
lib/libmyfuncshared.so : objs/func.o
	@echo Compile Objects to Shared Lib
	@mkdir -p $(dir $@)
	@g++ -shared $^ -o $@

shared : lib/libmyfuncshared.so

#-------------------- 链接成可执行文件

workspace/exec : objs/main.o 
	@echo Link Objects to Executable
	@mkdir -p $(dir $@)
	@g++ $^ -o $@ $(link_flags)



run : workspace/exec 
	@./$<



libclean :
	@rm -rf lib 

clean :
	@rm -rf objs workspace/exec lib

.PHONY : run clean debug