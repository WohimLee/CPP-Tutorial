
cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs))

objs/%.o : src/%.cpp
	@echo Compile $^
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@

workspace/exec : $(cpp_objs)
	@echo Linking $@
	@mkdir -p $(dir $@)
	@g++ $^ -o $@

run : workspace/exec
	@./$<

debug :
	@echo $(cpp_srcs)
	@echo $(cpp_objs)