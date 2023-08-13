

cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs))


include_dirs := 
linking_libs := 
library_dirs := 

I_options := $(include_dirs:%=-I%)
l_options := $(linking_libs:%=-l%)
L_options := $(library_dirs:%=-L%)
r_options := $(library_dirs:%=-Wl,rpath=%)

dynamic_options := -fPIC
compile_options := -g -O3 -w -std=c++14 $(I_options)
linking_options := $(l_options) $(L_options) $(r_options)


objs/%.o : src/%.cpp
	@echo [INFO]: Compile Source to Object
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@ $(compile_options)

workspace/exec : $(cpp_objs)
	@echo [INFO]: Link Object to Executable
	@mkdir -p $(dir $@)
	@g++ $^ -o $@ $(linking_options)

run : workspace/exec
	@./$<


clean :
	@rm -rf objs workspace/exec


debug :
	@echo $(cpp_objs)

.PHONY : run clean debug