

cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst %.cpp,%.o,$(cpp_srcs))
cpp_objs := $(subst src/,objs/,$(cpp_objs))

compile_I := 
link_L    :=
link_l    := 
link_r    :=


objs/%.o : src/%.cpp
	@echo Compile Source to Objects
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@

workspace/exec : $(cpp_objs)
	@echo Link Objects to Executable
	@mkdir -p $(dir $@)
	@g++ $^ -o $@


run :workspace/exec
	@./$<


clean :
	@rm -rf objs workspace/exec

.PHONY : run clean