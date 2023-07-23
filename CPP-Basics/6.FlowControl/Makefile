

cpp_srcs := $(shell find -name "*.cpp")
cpp_objs := $(patsubst %.cpp,%.o,$(cpp_srcs))
cpp_objs := $(subst src/,objs/,$(cpp_objs))


objs/%.o : src/%.cpp
	@echo Compile Source to Object
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@

workspace/exec : $(cpp_objs)
	@echo Link Object to Executable
	@mkdir -p $(dir $@)
	@g++ $^ -o $@

run : workspace/exec
	@./$<


clean :
	@rm -f objs workspace/exec

.PHONY : run clean