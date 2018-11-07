
CC      = clang 
CXX     = clang
OBJCOPY = objcopy
SIZE    = size
LINK    = ld


CFLAGS    = -target thumbv7-none-eabi -fshort-enums -Wno-unknown-attributes -march=armv7-a -mfpu=neon -mfloat-abi=softfp -v -Os -Werror=return-type -Wall -ansi -std=gnu99 -DVexV5
CXX_FLAGS = -target thumbv7-none-eabi -fshort-enums -Wno-unknown-attributes -march=armv7-a -mfpu=neon -mfloat-abi=softfp -v -Os -Werror=return-type -Wall -D_LIBCPP_HAS_NO_EXCEPTIONS -D_LIBCPP_HAS_NO_THREADS -std=c++1y -nostdinc++ -fno-rtti -fno-threadsafe-statics -fno-exceptions  -std=gnu++11 -ffunction-sections -fdata-sections -DVexV5
LNK_FLAGS = -v -nostdlib -T Build/lscript.ld -R Build/stdlib_0.lib  --gc-sections -LBuild/vexv5 -LBuild/vexv5/gcc/libs

LIBS =  --start-group -lv5rt -lc -lm -lgcc -lc++ --end-group

INC = -I. -IBuild/vexv5/include
cxx_bin: cxx.bin
main.bin: onefile.bin

cxx.o: cxx_entry.cpp
	$(CXX) $(CXX_FLAGS) $(INC) -c cxx_entry.cpp -o cxx.o
	
cxx.bin: cxx.elf
	$(OBJCOPY) -O binary cxx.elf cxx.bin

cxx.elf: cxx.o
	$(LINK) $(LNK_FLAGS) cxx.o $(LIBS) -o cxx.elf

	cxx_bin: cxx.bin

main.o: onefile.cpp
	$(CXX) $(CXX_FLAGS) $(INC) -c ../Competition/Drew/Cpp/Concept-InProgress/onefile.cpp -o onefile.o
	
main.bin: onefile.elf
	$(OBJCOPY) -O binary ../Competition/Drew/Cpp/onefile.elf ../Competition/Drew/Cpp/onefile.bin

main.elf: onefile.o
	$(LINK) $(LNK_FLAGS) ../Competition/Drew/Cpp/onefile.o $(LIBS) -o ../Competition/Drew/Cpp/onefile.elf

	main.bin: onefile.bin

clean:
	rm *.o
	rm *.elf
	rm *.bin

