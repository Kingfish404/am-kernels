NAME = dhrystone
SRCS = dry.c
include $(AM_HOME)/Makefile

# Per-platform run count. Hardware simulation (npc/ysyxsoc) is orders of
# magnitude slower than NEMU, so far fewer runs still yield a stable
# cycle-accurate DMIPS/MHz figure (computed from the PMU active-cycle count).
NUMBER_OF_RUNS=500000
ifeq ($(PLATFORM), npc)
NUMBER_OF_RUNS:=5000
else ifeq ($(PLATFORM), ysyxsoc)
NUMBER_OF_RUNS:=500
else ifeq ($(PLATFORM), nemu)
NUMBER_OF_RUNS:=100000
endif
# DHRYSTONE_OPTIM_CFLAGS: optional aggressive optimization flags injected by the
# top-level `dhrystone-npc32/64-optim` targets. Empty by default so the plain
# `dhrystone-*` targets keep the AM baseline (-O2) flags.
CFLAGS += $(DHRYSTONE_OPTIM_CFLAGS) -DNUMBER_OF_RUNS=$(NUMBER_OF_RUNS)
