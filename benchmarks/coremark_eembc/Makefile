NAME = coremark
SRCS = $(shell find src/ -name "*.c")
include $(AM_HOME)/Makefile
ITERATIONS=500000
ifeq ($(PLATFORM), npc)
ITERATIONS:=10
else ifeq ($(PLATFORM), ysyxsoc)
ITERATIONS:=2
else ifeq ($(PLATFORM), nemu)
ITERATIONS:=100
endif
CFLAGS += -DCOMPILER_FLAGS=\"\" -I$(abspath ./src/) \
	-I$(abspath ./include/) \
	-DITERATIONS=$(ITERATIONS)
