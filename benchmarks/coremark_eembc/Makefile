NAME = coremark
SRCS = $(shell find src/ -name "*.c")
include $(AM_HOME)/Makefile
ITERATIONS=20
ifeq ($(PLATFORM), npc)
ITERATIONS:=100
endif
CFLAGS += -DCOMPILER_FLAGS=\"\" -I$(abspath ./src/) \
	-I$(abspath ./include/) \
	-DITERATIONS=$(ITERATIONS)
