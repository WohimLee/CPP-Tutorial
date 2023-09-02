cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs))

include_paths := 
link_library  := 
library_path  := 


I_options := $(include_paths:%=-I%)
l_options := $(link_library:%=-l%)
L_options := $(library_path:%=-L%)
r_options := $(library_path:%=-Wl,-rpath=%)

compile_options := -O3 -g -std=c++11 $(I_options) #-fpic 
link_options    := $(l_options) $(L_options) #$(r_options)

objs/%.o : src/%.cpp
	@echo Compile $^
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@ $(compile_options)

workspace/exec : $(cpp_objs)
	@echo Link $@
	@mkdir -p $(dir $@)
	@g++ $^ -o $@ $(link_options)

run : workspace/exec
	@./$<

clean :
	@rm -rf objs workspace/exec

debug :
	@echo $(cpp_srcs)

.PHONY : debug run clean
