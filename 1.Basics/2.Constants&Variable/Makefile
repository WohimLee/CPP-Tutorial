

cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs))


cpp_compile_flags := -m64 -g -O3 -fpic -std=c++11


objs/%.o : src/%.cpp
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@

workspace/exec : $(cpp_objs)
	@mkdir -p $(dir $@)
	@g++ $^ -o $@

run : workspace/exec
	@./$<


debug :
	
clean : 
	@rm -rf objs workspace/exec 

.PHONY : clean debug run

