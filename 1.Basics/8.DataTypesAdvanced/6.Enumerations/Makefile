

cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst %.cpp,%.o,$(cpp_srcs))
cpp_objs := $(subst src/,objs/,$(cpp_objs))


compile_I :=

link_l    :=
link_L    := 



link_l := $(foreach item,$(link_l),-l$(item))
link_L := $(foreach item,$(link_L),-L$(item))

link_rpaths := $(foreach item,$(link_L),-Wl,-rpath=$(item))



compile_flags := -g -m64 -w -O3 -fpic
link_flags    := $(link_l) $(link_L) $(link_rpaths)



objs/%.o : src/%.cpp
	@echo Compile Source to Objects
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@ $(compile_flags)

workspace/exec : $(cpp_objs)
	@echo Link Objects to Executable
	@mkdir -p $(dir $@)
	@g++ $^ -o $@ $(link_flags)

run : workspace/exec
	@./$<

clean :
	@rm -rf objs workspace/exec

test : 

debug :
	@echo $(cpp_srcs)
	@echo $(cpp_objs)

.PHONY : run clean 

