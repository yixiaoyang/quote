include ../../common.mk

SRC_DIRS:=.

SAMPLE_EXECUTALBE:=csv_string

SRCS:=$(wildcard $(addsuffix /*.cpp, $(SRC_DIRS)))
OBJS:=$(addsuffix .o, $(basename $(SRCS)))
DEPS:=$(addsuffix .d, $(basename $(SRCS)))

PROJECT_STATIC_LIB:=../../src/$(PROJECT_STATIC_LIB_NAME)

LDLIBS+=$(PROJECT_LDLIBS)

CXXFLAGS+=-I../../src

.PHONY: all clean

all: $(SAMPLE_EXECUTALBE)

$(SAMPLE_EXECUTALBE): $(OBJS) $(PROJECT_STATIC_LIB)
	$(CXX) $(OBJS) $(PROJECT_STATIC_LIB) $(LDFLAGS) $(LDLIBS) -o $@

clean:
	rm -f $(DEPS) $(OBJS) $(SAMPLE_EXECUTALBE)

%.d: %.cpp
	$(CXX) $(CXXFLAGS) -MP -MM -MF $@ -MT '$@ $(addsuffix .o, $(basename $<))' $<

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif
