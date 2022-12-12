

cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs))

objs/%.o : src/%.cpp
	@echo Compile $^
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@

workspace/exec : $(cpp_objs)
	@echo Link $@
	@mkdir -p $(dir $@)
	@g++ $^ -o $@


run : workspace/exec
	@./$<

clean : 
	@rm -rf objs workspace/exec

debug:
	@

.PHONY : run clean debug


