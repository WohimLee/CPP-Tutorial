
MAIN := Examples/example2.c
# MAIN := Examples/test.c

TARGET := $(notdir $(basename $(MAIN)))

cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs))


include_dirs := 
linking_libs := 
library_dirs := 


I_options := $(include_dirs:%=-I%)
l_options := $(linking_libs:%=-l%)
L_options := $(library_dirs:%=-L%)
r_options := $(library_dirs:%=-Wl,-rpath=%)

dynamic_options := -fPIC
compile_options := -g -O3 -w -std=c++14 $(I_options)
linking_options := $(l_options) $(L_options) $(r_options)


# Compile TARGET
objs/$(TARGET).o : $(MAIN) 
	@echo [INFO]: Compile $^ to $@
	@mkdir -p $(dir $@)
	@gcc -c $< -o $@ $(compile_options)


workspace/$(TARGET) : objs/$(TARGET).o 
	@echo [INFO]: Linking $^ to $@
	@mkdir -p $(dir $@)
	@gcc $^ -o $@ $(linking_options)

run : workspace/$(TARGET)
	@./$<


clean :
	@rm -rf objs workspace/$(TARGET)


debug :
	@echo $(cpp_objs)

.PHONY : run clean debug