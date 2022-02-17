TARGET          := libSceShaccCgExt
SOURCES         := src

CFILES   := $(foreach dir,$(SOURCES), $(wildcard $(dir)/*.c))
CPPFILES   := $(foreach dir,$(SOURCES), $(wildcard $(dir)/*.cpp))
ASMFILES := $(foreach dir,$(SOURCES), $(wildcard $(dir)/*.S))
OBJS     := $(CFILES:.c=.o) $(CPPFILES:.cpp=.o) $(ASMFILES:.S=.o)

PREFIX  = arm-vita-eabi
CC       = $(PREFIX)-gcc
CXX      = $(PREFIX)-g++
AR       = $(PREFIX)-gcc-ar
CFLAGS  = -g -Wl,-q -g -O3 -ffast-math -mtune=cortex-a9 -mfpu=neon -ftree-vectorize -Wall -Iinclude
CXXFLAGS  = -g -Wl,-q -O3 -ffast-math -ftree-vectorize -Wall -fno-exceptions -fno-rtti -std=gnu++11 -fpermissive -Iinclude
ASFLAGS = $(CFLAGS)

all: $(TARGET).a

$(TARGET).a: $(OBJS)
	$(AR) -rc $@ $^
	
clean:
	@rm -rf $(TARGET).a $(TARGET).elf $(OBJS)
	
install: $(TARGET).a
	@mkdir -p $(VITASDK)/$(PREFIX)/lib/
	cp $(TARGET).a $(VITASDK)/$(PREFIX)/lib/
	@mkdir -p $(VITASDK)/$(PREFIX)/include/
	cp include/shacccg_ext.h $(VITASDK)/$(PREFIX)/include/