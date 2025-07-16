MCU     = atmega32
CC      = avr-gcc
CFLAGS  = -Os -DF_CPU=8000000UL -mmcu=$(MCU)
TARGET  = program
SRC_DIR = ../program
OUT_DIR = ../build
BIN_DIR = $(OUT_DIR)/bin

# Recursive find for all .c files
define rwildcard
$(wildcard $(1)/*.c) $(foreach d,$(wildcard $(1)/*/),$(call rwildcard,$d))
endef

SRC := $(call rwildcard,$(SRC_DIR))
REL_SRC := $(patsubst $(SRC_DIR)/%,%,$(SRC))
OBJ := $(addprefix $(OUT_DIR)/Debug/, $(REL_SRC:.c=.o))

all: $(OUT_DIR)/$(TARGET).hex
	@mkdir -p $(BIN_DIR)
	@mv -f $(OUT_DIR)/*.elf $(BIN_DIR) 2>/dev/null || true
	@mv -f $(OUT_DIR)/*.hex $(BIN_DIR) 2>/dev/null || true
	@echo
	@echo ----------------------------------------------------------
	@echo ---------- HEX File was Generated [Successful] -----------
	@echo ----------------------------------------------------------
	@echo ------------ Developed by Eng - Ahmed Bahaa  -------------
	@echo --------- Automotive Embedded SW Engineer [ADAS] ---------
	@echo ----------------------------------------------------------
	@echo

$(OUT_DIR)/Debug/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

src: $(SRC)
	@echo
	@echo ***************************************************
	@echo ****** [Compiling the following '.c' files] *******
	@echo ***************************************************
	@for file in $(SRC); do echo $$file; done
	@echo ***************************************************
	@echo

build: src $(OBJ)
	@echo
	@echo ******************************************************
	@echo ****** [The following '.o' files were generated] ******
	@echo ******************************************************
	@for file in $(OBJ); do echo $$file; done
	@echo ******************************************************
	@echo

$(OUT_DIR)/$(TARGET).elf: build
	@echo
	@echo ----------------------------------------------------
	@echo ------------   [Generating ELF file]   -------------
	@echo ----------------------------------------------------
	$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo ----------------------------------------------------
	@echo

$(OUT_DIR)/$(TARGET).hex: $(OUT_DIR)/$(TARGET).elf
	@echo
	@echo ----------------------------------------------------
	@echo ------------   [Generating HEX file]   -------------
	@echo ----------------------------------------------------
	avr-objcopy -O ihex -R .eeprom $< $@
	@echo ----------------------------------------------------
	@echo

clean:
	@rm -rf $(OUT_DIR)
	@echo
	@echo ----------------------------------------------------
	@echo -------- [Output directory was cleaned now] --------
	@echo ----------------------------------------------------
	@echo

sync: copy_dirs
	@echo
	@echo ----------------------------------------------------
	@echo ------- [Source files ready for Compilation] -------
	@echo ----------------------------------------------------
	@echo

copy_dirs:
	@echo ----------------------------------------------------
	@echo ----- [Copying directory 'program' to 'output'] ----
	@echo ----------------------------------------------------
	@mkdir -p $(OUT_DIR)
	@cp -r $(SRC_DIR)/* $(OUT_DIR)/Debug
	@echo ----------------------------------------------------
