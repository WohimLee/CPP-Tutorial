

cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs))



compile_options := -g -w -O3
linking_options := 


objs/%.o : src/%.cpp
	@echo Compile $^ to $@
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@ $(compile_options)


workspace/exec : $(cpp_objs)
	@echo Link $^ to $@
	@mkdir -p $(dir $@)
	@g++ $^ -o $@ $(linking_options)


run : workspace/exec
	@./$<

clean :
	@rm -rf objs workspace/exec


debug :
	@echo $(cpp_srcs)
	@echo $(cpp_objs)
