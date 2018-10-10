
CC      = clang 
CXX     = clang
OBJCOPY = objcopy
SIZE    = size
LINK    = ld


CFLAGS    = -target thumbv7-none-eabi -fshort-enums -Wno-unknown-attributes -march=armv7-a -mfpu=neon -mfloat-abi=softfp -v -Os -Werror=return-type -Wall -ansi -std=gnu99 -DVexV5
CXX_FLAGS = -target thumbv7-none-eabi -fshort-enums -Wno-unknown-attributes -march=armv7-a -mfpu=neon -mfloat-abi=softfp -v -Os -Werror=return-type -Wall -D_LIBCPP_HAS_NO_EXCEPTIONS -D_LIBCPP_HAS_NO_THREADS -std=c++1y -nostdinc++ -fno-rtti -fno-threadsafe-statics -fno-exceptions  -std=gnu++11 -ffunction-sections -fdata-sections -DVexV5
LNK_FLAGS = -v -nostdlib -T Build/vexv5/lscript.ld -R Build/vexv5/stdlib_0.lib  --gc-sections -LBuild/vexv5 -L/gcc/libs

LIBS =  --start-group -lv5rt -lc -lm -lgcc --end-group

INC = -I. -I/clang-5.0.0/include -I/vexv5/include -Igcc/include -Igcc/include/c++/5.0.0/include
cxx_bin: cxx.bin

cxx.o: cxx_entry.cpp
	$(CXX) $(CXX_FLAGS) $(INC) -c cxx_entry.cpp -o cxx.o
	
cxx.bin: cxx.elf
	$(OBJCOPY) -O binary cxx.elf cxx.bin

cxx.elf: cxx.o
	$(LINK) $(LNK_FLAGS) cxx.o $(LIBS) -o cxx.elf


clean:
	rm *.o
	rm *.elf
	rm *.bin

