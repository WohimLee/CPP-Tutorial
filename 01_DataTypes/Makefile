
# target : prequisties
# 	@command


cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs))

objs/%.o : src/%.cpp
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@ -w

objs : $(cpp_objs)

workspace/exec : $(cpp_objs)
	@g++ $^ -o $@

run : workspace/exec
	@./$<

clean :
	@rm -rf objs workspace/exec

debug :
	@echo $(cpp_srcs)
	@echo $(cpp_objs)


.PHONY : debug run clean