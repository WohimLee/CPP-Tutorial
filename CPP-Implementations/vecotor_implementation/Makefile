



cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst %.cpp,%.o,$(cpp_srcs))
cpp_objs := $(subst src/,objs/,$(cpp_objs))




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

debug :
	@echo $(cpp_srcs)
	@echo $(cpp_objs)
clean :
	@rm -rf objs workspace/exec

.PHONY : run clean