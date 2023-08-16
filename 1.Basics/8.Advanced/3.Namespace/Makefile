
MAIN   := Examples/mono.cc
MAIN.o := objs/mono.o

cc_srcs := $(shell find src -name "*.cc")
cc_objs := $(patsubst src/%.cc,objs/%.o,$(cc_srcs))


include_dirs := ./include
linking_libs := orb
library_dirs := ./lib

I_options := $(include_dirs:%=-I%)
l_options := $(linking_libs:%=-l%)
L_options := $(library_dirs:%=-L%)
r_options := $(library_dirs:%=-Wl,-rpath=%)

dynamic_options := -fPIC
compile_options := -g -O3 -w -std=c++14 $(I_options)
linking_options := $(l_options) $(L_options) $(r_options)

$(MAIN.o) : $(MAIN)
	@echo [INFO]: Compile $< to $@
	@mkdir -p $(dir $@)
	@g++ -c $< -o $@ $(compile_options) 

objs/%.o : src/%.cc
	@echo [INFO]: Compile $^ to $@
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@ $(compile_options) $(dynamic_options)

lib/liborb.so : $(cc_objs)
	@echo [INFO]: Generate $@, including: $^
	@mkdir -p $(dir $@)
	@g++ -shared $^ -o $@


dynamic : lib/liborb.so


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