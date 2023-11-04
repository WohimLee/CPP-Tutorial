
MAIN := Examples/example1.c
HEADERS := 
# MAIN := Examples/test.c

TARGET := $(notdir $(basename $(MAIN)))

c_srcs := $(shell find src -name "*.c")
c_objs := $(patsubst src/%.c,objs/%.o,$(c_srcs))

include_dirs := include
linking_libs := m

I_options := $(include_dirs:%=-I%)
l_options := $(linking_libs:%=-l%)

compile_options := -g $(I_options)
linking_options := $(l_options)


# Compile TARGET
objs/$(TARGET).o : $(MAIN) $(HEADERS)
	@echo [INFO]: Compile $^ to $@
	@mkdir -p $(dir $@)
	@gcc -c $< -o $@ $(compile_options)


workspace/$(TARGET) : objs/$(TARGET).o 
	@echo [INFO]: Linking $^ to $@
	@mkdir -p $(dir $@)
	@gcc $^ -o $@ $(linking_options)

run : workspace/$(TARGET)
	@./$<


debug :
	@echo $(TARGET)

clean :
	@rm -rf objs lib workspace/$(TARGET)

.PHONY : debug clean run