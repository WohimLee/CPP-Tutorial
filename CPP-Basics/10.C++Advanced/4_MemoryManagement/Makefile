
cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst %.cpp,%.o,$(cpp_srcs))
cpp_objs := $(subst src/,objs/,$(cpp_objs))

include_paths := /datav/MyLesson/2_Cpp/3_CC++_Programing_Basics/9_C++Advanced/4_MemoryManagement/src
library_paths :=
link_library  := 

I_option := $(include_paths:%=-I%)
L_option := $(library_paths:%=-L%)
l_option := $(link_library:%=-l%)
# r_option := $(library_paths:%=-Wl,-rpath=%)

compile_options := -m64 -O3 -g -w -std=c++11 $(I_option)
link_options    := $(l_option) $(L_option)

debug :
	@echo $(I_option)


objs/%.o : src/%.cpp
	@echo Compile Source to Objects
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@ $(compile_options)

workspace/exec : $(cpp_objs)
	@echo Link Objects to Executable
	@mkdir -p $(dir $@)
	@g++ $^ -o $@ $(link_options)


run :workspace/exec
	@./$<


clean :
	@rm -rf objs workspace/exec

.PHONY : run clean