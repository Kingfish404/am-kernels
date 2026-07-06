NAME = coremark
SRCS = $(shell find src/ -name "*.c")
include $(AM_HOME)/Makefile
ITERATIONS=500000
ifeq ($(PLATFORM), npc)
ITERATIONS:=16
else ifeq ($(PLATFORM), ysyxsoc)
ITERATIONS:=2
else ifeq ($(PLATFORM), nemu)
ITERATIONS:=100
endif
# COREMARK_OPTIM_CFLAGS: optional aggressive optimization flags injected by the
# top-level `coremark-npc32/64-optim` targets. Empty by default so the plain
# `coremark-*` targets keep the AM baseline (-O2) flags.
CFLAGS += -DCOMPILER_FLAGS=\"\" -I$(abspath ./src/) \
	$(COREMARK_OPTIM_CFLAGS) \
	-I$(abspath ./include/) \
	-DITERATIONS=$(ITERATIONS)
