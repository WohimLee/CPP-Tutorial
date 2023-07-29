


# target : prequisties
# [tab]@command

cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst src%cpp,objs%o,$(cpp_srcs))


objs/%.o : src/%.cpp
	@echo Compile source to objects
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@ -I/datav/MyLesson/2_Cpp/3_CC++_Programing_Basics/7_Functions/include

workspace/exec : $(cpp_objs)
	@echo Linking
	@mkdir -p $(dir $@)
	@g++ $^ -o $@

run : workspace/exec
	@./$<

clean :
	@rm -rf objs workspace/exec 

debug :
	@echo $(cpp_srcs)
	@echo $(cpp_objs)


.PHONY : run debug clean