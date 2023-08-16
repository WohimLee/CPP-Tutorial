
MAIN   := Examples/main.cpp
MAIN.o := objs/main.o

cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs))


include_dirs := ./include
linking_libs := test
library_dirs := ./lib

I_options := $(include_dirs:%=-I%)
l_options := $(linking_libs:%=-l%)
L_options := $(library_dirs:%=-L%)
r_options := $(library_dirs:%=-Wl,-rpath=%)

dynamic_options := -fPIC
compile_options := -g -O3 -w -std=c++14 $(I_options)
linking_options := $(l_options) $(L_options) $(r_options)

# Compile main
$(MAIN.o) : $(MAIN)
	@echo [INFO]: Compile $< to $@
	@mkdir -p $(dir $@)
	@g++ -c $< -o $@ $(compile_options) 

# Compile all the source code
objs/%.o : src/%.cpp
	@echo [INFO]: Compile $^ to $@
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@ $(compile_options) $(dynamic_options)

# Make a .so lib
lib/libtest.so : $(cpp_objs)
	@echo [INFO]: Generate $@, including: $^
	@mkdir -p $(dir $@)
	@g++ -shared $^ -o $@


dynamic : lib/libtest.so

# Link to a executable
workspace/exec : $(MAIN.o) dynamic
	@echo [INFO]: Link $< to $@
	@mkdir -p $(dir $@)
	@g++ $< -o $@ $(linking_options)

run : workspace/exec
	@./$<


clean :
	@rm -rf objs lib workspace/exec


debug :
	@echo $(MAIN)
	@echo $(MAIN.o)


.PHONY : run clean debug dynamic