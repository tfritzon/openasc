# Copyright (C) 2009  Mikael Larsmark, SM3WMV
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARoot directoriesRTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# ========================================================================
#
# Hey Emacs, this is a -*- makefile -*-
#
# WinAVR Sample makefile written by Eric B. Weddington, J�rg Wunsch, et al.
# Released to the Public Domain
# Please read the make user manual!
#
# Additional material for this makefile was submitted by:
#  Tim Henigan
#  Peter Fleury
#  Reiner Patommel
#  Sander Pool
#  Frederik Rouleau
#  Markus Pfaff
#  Mikael Larsmark, SM2WMV
#  Tobias Blomberg, SM0SVX
#
# On command line:
#
# make all = Make software.
#
# make clean = Clean out built project files.
#
# make coff = Convert ELF to AVR COFF (for use with AVR Studio 3.x or VMLAB).
#
# make extcoff = Convert ELF to AVR Extended COFF (for use with AVR Studio
#                4.07 or greater).
#
# make program = Download the hex file to the device, using avrdude.  Please
#                customize the avrdude settings below first!
#
# make fuse = Set the fuse bytes in the mcu.
#
# make filename.s = Just compile filename.c into the assembler code only
#
# To rebuild project do "make clean" then "make all".
#

# MCU name
ifndef MCU
$(error Variable MCU must be defined)
endif

# Output format. (can be srec, ihex, binary)
ifndef FORMAT
FORMAT = ihex
endif

# Target file name (without extension).
ifndef TARGET
$(error Variable TARGET must be defined)
endif

# Path to project root
ifndef ROOT
$(error Variable ROOT must be defined)
endif

#The name of this device
ifndef DEVICE_TYPE
$(error Variable DEVICE_TYPE must be defined)
endif
ifndef BASE_ADDRESS
$(error Variable BASE_ADDRESS must be defined)
endif

#The size of the RX queue in buffers
ifndef BUS_RX_QUEUE_SIZE
BUS_RX_QUEUE_SIZE = 10
endif
#The size of the TX queue in buffers
ifndef BUS_TX_QUEUE_SIZE
BUS_TX_QUEUE_SIZE = 10
endif

# Optimization level, can be [0, 1, 2, 3, s]. 
# 0 = turn off optimization. s = optimize for size.
# (Note: 3 is not always the best optimization level. See avr-libc FAQ.)
ifndef OPT
OPT = s
endif

# Debugging format.
# Native formats for AVR-GCC's -g are stabs [default], or dwarf-2.
# AVR (extended) COFF requires stabs, plus an avr-objcopy run.
ifndef DEBUG
DEBUG = stabs
endif

# Compiler flag to set the C Standard level.
# c89   - "ANSI" C
# gnu89 - c89 plus GCC extensions
# c99   - ISO C99 standard (not yet fully implemented)
# gnu99 - c99 plus GCC extensions
ifndef CSTANDARD
CSTANDARD = -std=c99 -fgnu89-inline
endif

# Compiler flags.
#  -g*:          generate debugging information
#  -O*:          optimization level
#  -f...:        tuning, see GCC manual and avr-libc documentation
#  -Wall...:     warning level
#  -Wa,...:      tell GCC to pass this to the assembler.
#    -adhlns...: create assembler listing
CFLAGS = -g$(DEBUG)
CFLAGS += $(CDEFS) $(CINCS)
CFLAGS += -O$(OPT)
CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -Wall -Wstrict-prototypes
CFLAGS += -Wa,-adhlns=$(notdir $(<:.c=.lst))
CFLAGS += $(patsubst %,-I%,$(EXTRAINCDIRS))
CFLAGS += $(CSTANDARD)
CFLAGS += -D$(DEVICE_TYPE) -DBUS_BASE_ADDR=$(BASE_ADDRESS)
CFLAGS += -DBUS_RX_QUEUE_SIZE=$(BUS_RX_QUEUE_SIZE)
CFLAGS += -DBUS_TX_QUEUE_SIZE=$(BUS_TX_QUEUE_SIZE)
CFLAGS += -D__AVR_LIBC_DEPRECATED_ENABLE__
CFLAGS += -D__PROG_TYPES_COMPAT__

# Assembler flags.
#  -Wa,...:   tell GCC to pass this to the assembler.
#  -ahlms:    create listing
#  -gstabs:   have the assembler create line number information; note that
#             for use in COFF files, additional information about filenames
#             and function names needs to be present in the assembler source
#             files -- see avr-libc docs [FIXME: not yet described there]
ASFLAGS = -Wa,-adhlns=$(<:.S=.lst),-gstabs 



#Additional libraries.

# Minimalistic printf version
PRINTF_LIB_MIN = -Wl,-u,vfprintf -lprintf_min

# Floating point printf version (requires MATH_LIB = -lm below)
PRINTF_LIB_FLOAT = -Wl,-u,vfprintf -lprintf_flt

PRINTF_LIB = -Wl,-u,vfprintf -lprintf_flt

# Minimalistic scanf version
SCANF_LIB_MIN = -Wl,-u,vfscanf -lscanf_min

# Floating point + %[ scanf version (requires MATH_LIB = -lm below)
SCANF_LIB_FLOAT = -Wl,-u,vfscanf -lscanf_flt

SCANF_LIB = 

MATH_LIB = -lm

# External memory options

# 64 KB of external RAM, starting after internal RAM (ATmega128!),
# used for variables (.data/.bss) and heap (malloc()).
#EXTMEMOPTS = -Wl,-Tdata=0x801100,--defsym=__heap_end=0x80ffff

# 64 KB of external RAM, starting after internal RAM (ATmega128!),
# only used for heap (malloc()).
#EXTMEMOPTS = -Wl,--defsym=__heap_start=0x801100,--defsym=__heap_end=0x80ffff

#EXTMEMOPTS = -Wl,--defsym=__heap_start=0x801100,--defsym=__heap_end=0x80ffff
EXTMEMOPTS = 

# Linker flags.
#  -Wl,...:     tell GCC to pass this to linker.
#    -Map:      create map file
#    --cref:    add cross reference to  map file
LDFLAGS = -Wl,-Map=$(TARGET).map,--cref
LDFLAGS += $(EXTMEMOPTS)
LDFLAGS += $(PRINTF_LIB) $(SCANF_LIB) $(MATH_LIB)




# Programming support using avrdude. Settings and variables.
# Set programming hardware specific configuration using the
# AVRDUDE_PROGRAMMER_OPTS environment variable if needed or use the
# ~/.avrduderc configuration file.
# E.g: AVRDUDE_PROGRAMMER_OPTS="-P usb -c avrispmkII -B1.1 "

AVRDUDE_WRITE_FLASH = -U flash:w:$(TARGET).hex
AVRDUDE_WRITE_EEPROM = -U eeprom:w:$(TARGET).eep
AVRDUDE_WRITE_EFUSE = $(AVRDUDE_EFUSE:%=-U efuse:w:%:m)
AVRDUDE_WRITE_HFUSE = $(AVRDUDE_HFUSE:%=-U hfuse:w:%:m)
AVRDUDE_WRITE_LFUSE = $(AVRDUDE_LFUSE:%=-U lfuse:w:%:m)
AVRDUDE_WRITE_FUSE = $(AVRDUDE_WRITE_EFUSE) $(AVRDUDE_WRITE_HFUSE) $(AVRDUDE_WRITE_LFUSE)



# Uncomment the following if you want avrdude's erase cycle counter.
# Note that this counter needs to be initialized first using -Yn,
# see avrdude manual.
#AVRDUDE_ERASE_COUNTER = -y

# Uncomment the following if you do /not/ wish a verification to be
# performed after programming the device.
#AVRDUDE_NO_VERIFY = -V

# Increase verbosity level.  Please use this when submitting bug
# reports about avrdude. See <http://savannah.nongnu.org/projects/avrdude> 
# to submit bug reports.
#AVRDUDE_VERBOSE = -v -v

AVRDUDE_FLAGS = -p $(MCU) $(AVRDUDE_PROGRAMMER_OPTS)
AVRDUDE_FLAGS += $(AVRDUDE_NO_VERIFY)
AVRDUDE_FLAGS += $(AVRDUDE_VERBOSE)
AVRDUDE_FLAGS += $(AVRDUDE_ERASE_COUNTER)



# ---------------------------------------------------------------------------

# Define directories, if needed.
DIRAVR = c:/winavr
DIRAVRBIN = $(DIRAVR)/bin
DIRAVRUTILS = $(DIRAVR)/utils/bin
DIRINC = .
DIRLIB = $(DIRAVR)/avr/lib


# Define programs and commands.
SHELL = sh
CC = avr-gcc
#CC = /usr/local/avr/bin/avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
SIZE = avr-size
NM = avr-nm
AVRDUDE = avrdude
REMOVE = remove() { echo $(MSG_REMOVING) $$@; $(RM) -f $$@; }; remove
RECURSIVE_REMOVE = remove() { echo $(MSG_REMOVING) $$@; $(RM) -rf $$@; }; remove
COPY = cp

ifeq ($(AVRMAKE_ENHANCED_PRINTOUTS),1)
BOLD = "\033[1m"
NBOLD = "\033[0m"
endif


# Define Messages
# English
MSG_ERRORS_NONE = Errors: none
MSG_BEGIN = -------- begin --------
MSG_END = --------  end  --------
MSG_SIZE_BEFORE = --- Size before: 
MSG_SIZE_AFTER = --- Size after:
MSG_COFF = --- Converting to AVR COFF:
MSG_EXTENDED_COFF = --- Converting to AVR Extended COFF:
MSG_FLASH = --- Creating load file for Flash:
MSG_EEPROM = --- Creating load file for EEPROM:
MSG_EXTENDED_LISTING = --- Creating Extended Listing:
MSG_SYMBOL_TABLE = --- Creating Symbol Table:
MSG_LINKING = --- Linking:
MSG_COMPILING = --- Compiling:
MSG_ASSEMBLING = --- Assembling:
MSG_CLEANING = --- Cleaning project
MSG_REMOVING = --- Removing:
MSG_FUSING = --- Setting fuse bytes




# Define all object files.
#OBJ = $(basename $(SRC:.c=.o)) $(basename $(ASRC:.S=.o))
OBJ = $(SRC:.c=.o) $(ASRC:.S=.o)

# Define all listing files.
LST = $(ASRC:.S=.lst) $(SRC:.c=.lst)


# Compiler flags to generate dependency files.
GENDEPFLAGS = -Wp,-M,-MP,-MT,$(*F).o,-MF,.dep/$(@F).d


# Combine all necessary flags and optional flags.
# Add target processor to flags.
ALL_CFLAGS = -mmcu=$(MCU) -I. $(CFLAGS) $(GENDEPFLAGS)
ALL_ASFLAGS = -mmcu=$(MCU) -I. -x assembler-with-cpp $(ASFLAGS)



# Default target.
all: begin gccversion sizebefore build sizeafter finished end

build: elf hex eep lss sym

elf: $(TARGET).elf
hex: $(TARGET).hex
eep: $(TARGET).eep
lss: $(TARGET).lss 
sym: $(TARGET).sym



# Eye candy.
# AVR Studio 3.x does not check make's exit code but relies on
# the following magic strings to be generated by the compile job.
begin:
	@echo
	@echo $(MSG_BEGIN)

finished:
	@echo $(MSG_ERRORS_NONE)

end:
	@echo $(MSG_END)
	@echo


# Display size of file.
HEXSIZE = $(SIZE) --target=$(FORMAT) $(TARGET).hex
ELFSIZE = $(SIZE) -A $(TARGET).elf
sizebefore:
	@if [ -f $(TARGET).elf ]; then echo; echo $(BOLD)$(MSG_SIZE_BEFORE)$(NBOLD); $(ELFSIZE); echo; fi

sizeafter:
	@if [ -f $(TARGET).elf ]; then echo; echo $(BOLD)$(MSG_SIZE_AFTER)$(NBOLD); $(ELFSIZE); echo; fi



# Display compiler version information.
gccversion : 
	@$(CC) --version



# Program the flash of the device
program: $(TARGET).hex $(TARGET).eep
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_FLASH)


# Program the eeprom of the device
eeprom: $(TARGET).hex $(TARGET).eep
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_EEPROM)




# Convert ELF to COFF for use in debugging / simulating in AVR Studio or VMLAB.
COFFCONVERT=$(OBJCOPY) --debugging \
--change-section-address .data-0x800000 \
--change-section-address .bss-0x800000 \
--change-section-address .noinit-0x800000 \
--change-section-address .eeprom-0x810000 


coff: $(TARGET).elf
	@echo $(BOLD)$(MSG_COFF) $(TARGET).cof...$(NBOLD)
	$(COFFCONVERT) -O coff-avr $< $(TARGET).cof


extcoff: $(TARGET).elf
	@echo $(BOLD)$(MSG_EXTENDED_COFF) $(TARGET).cof...$(NBOLD)
	$(COFFCONVERT) -O coff-ext-avr $< $(TARGET).cof



# Create final output files (.hex, .eep) from ELF output file.
%.hex: %.elf
	@echo $(BOLD)$(MSG_FLASH) $@...$(NBOLD)
	$(OBJCOPY) -O $(FORMAT) -R .eeprom $< $@

%.eep: %.elf
	@echo $(BOLD)$(MSG_EEPROM) $@...$(NBOLD)
	-$(OBJCOPY) -j .eeprom --set-section-flags=.eeprom="alloc,load" \
		--change-section-lma .eeprom=0 -O $(FORMAT) $< $@

# Create extended listing file from ELF output file.
%.lss: %.elf
	@echo $(BOLD)$(MSG_EXTENDED_LISTING) $@...$(NBOLD)
	$(OBJDUMP) -h -S $< > $@

# Create a symbol table from ELF output file.
%.sym: %.elf
	@echo $(BOLD)$(MSG_SYMBOL_TABLE) $@...$(NBOLD)
	$(NM) -n $< > $@



# Link: create ELF output file from object files.
.SECONDARY : $(TARGET).elf
.PRECIOUS : $(OBJ)
%.elf: $(OBJ)
	@echo $(BOLD)$(MSG_LINKING) $@...$(NBOLD)
	$(CC) $(ALL_CFLAGS) $(OBJ) --output $@ $(LDFLAGS)


# Compile: create object files from C source files.
%.o : %.c
	@echo $(BOLD)$(MSG_COMPILING) $<...$(NBOLD)
	$(CC) -c $(ALL_CFLAGS) $< -o $@ 


# Compile: create assembler files from C source files.
%.s : %.c
	$(CC) -S $(ALL_CFLAGS) $< -o $@


# Assemble: create object files from assembler source files.
%.o : %.S
	@echo $(BOLD)$(MSG_ASSEMBLING) $<...$(NBOLD)
	$(CC) -c $(ALL_ASFLAGS) $< -o $@



# Target: clean project.
clean: begin clean_list finished end

clean_list :
	@echo $(BOLD)$(MSG_CLEANING)...$(NBOLD)
	$(REMOVE) $(TARGET).hex
	$(REMOVE) $(TARGET).eep
	$(REMOVE) $(TARGET).obj
	$(REMOVE) $(TARGET).cof
	$(REMOVE) $(TARGET).elf
	$(REMOVE) $(TARGET).map
	$(REMOVE) $(TARGET).obj
	$(REMOVE) $(TARGET).a90
	$(REMOVE) $(TARGET).sym
	$(REMOVE) $(TARGET).lnk
	$(REMOVE) $(TARGET).lss
	$(REMOVE) $(OBJ)
	$(REMOVE) $(LST)
	$(REMOVE) $(SRC:.c=.s)
	$(REMOVE) $(SRC:.c=.d)
	$(RECURSIVE_REMOVE) .dep


fuse:
	@echo $(BOLD)$(MSG_FUSING)...$(NBOLD)
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_FUSE)



# Listing of phony targets.
.PHONY : all begin finish end sizebefore sizeafter gccversion \
build elf hex eep lss sym coff extcoff \
clean clean_list program fuse eeprom

# Don't print each command line when executed
.SILENT:

# Look for C source code in the following directories
vpath %.c $(ROOT)/wmv_bus
vpath %.c $(ROOT)/qpn/source
vpath %.c $(ROOT)


# Include the dependency files.
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)

