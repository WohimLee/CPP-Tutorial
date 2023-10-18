
ROOT := /usr

boost_INCLUDE := $(ROOT)/include
boost_LIB_DIR := /usr/lib/x86_64-linux-gnu
full_paths := $(shell find $(boost_LIB_DIR) -name "libboost_*")
boost_LIBS = $(filter %.a %.so, $(full_paths))
# boost_LIBS := $(wildcard $(boost_LIBS)*.a $(boost_LIBS)*.so)
boost_LIBS := $(basename $(notdir $(boost_LIBS)))
boost_LIBS := $(patsubst lib%,%,$(boost_LIBS))