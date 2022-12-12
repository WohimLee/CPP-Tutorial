


cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst %.cpp,%.o,$(cpp_srcs))
cpp_objs := $(subst src/,objs/,$(cpp_objs))





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

