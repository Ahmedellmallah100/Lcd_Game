# ---------- Configuration ----------
MCU     = atmega32
CC      = avr-gcc
OBJCOPY = avr-objcopy
F_CPU   = 8000000UL
CFLAGS  = -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU) -std=c99

TARGET  = program
SRC_DIR = ../program
OUT_DIR = ../build
BIN_DIR = $(OUT_DIR)/bin

# ---------- Create Output Directory ----------
$(shell mkdir -p $(BIN_DIR))

# ---------- Find All .c Files Recursively ----------
define rwildcard
  $(wildcard $(1)/*.c) $(foreach d,$(wildcard $(1)/*),$(call rwildcard,$(d)))
endef

SRC := $(call rwildcard,$(SRC_DIR))
REL_SRC := $(patsubst $(SRC_DIR)/%,%,$(SRC))
OBJ := $(addprefix $(OUT_DIR)/Debug/, $(REL_SRC:.c=.o))

# ---------- Build All ----------
all: $(OUT_DIR)/$(TARGET).hex
	@mv -f $(OUT_DIR)/*.elf $(BIN_DIR)/ 2>/dev/null || true
	@mv -f $(OUT_DIR)/*.hex $(BIN_DIR)/ 2>/dev/null || true
	@echo
	@echo "----------------------------------------------------------"
	@echo "---------- HEX File was Generated [Successful] -----------"
	@echo "----------------------------------------------------------"
	@echo "------------ Developed by Eng - Ahmed Bahaa  -------------"
	@echo "--------- Automotive Embedded SW Engineer [ADAS] ---------"
	@echo "----------------------------------------------------------"
	@echo

# ---------- Compile .c to .o ----------
$(OUT_DIR)/Debug/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# ---------- Show Source Files ----------
src: $(SRC)
	@echo
	@echo "***************************************************"
	@echo "****** [Compiling the following '.c' files] *******"
	@echo "***************************************************"
	@for f in $(SRC); do echo $$f; done
	@echo "***************************************************"
	@echo

# ---------- Build Objects ----------
build: src $(OBJ)
	@echo
	@echo "******************************************************"
	@echo "****** [The following '.o' files were generated] *****"
	@echo "******************************************************"
	@for f in $(OBJ); do echo $$f; done
	@echo "******************************************************"
	@echo

# ---------- Link ELF ----------
$(OUT_DIR)/$(TARGET).elf: build
	@echo
	@echo "----------------------------------------------------"
	@echo "------------   [Generating ELF file]   -------------"
	@echo "----------------------------------------------------"
	$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "----------------------------------------------------"
	@echo

# ---------- Generate HEX ----------
$(OUT_DIR)/$(TARGET).hex: $(OUT_DIR)/$(TARGET).elf
	@echo
	@echo "----------------------------------------------------"
	@echo "------------   [Generating HEX file]   -------------"
	@echo "----------------------------------------------------"
	$(OBJCOPY) -O ihex -R .eeprom $< $@
	@echo "----------------------------------------------------"
	@echo

# ---------- Clean ----------
clean:
	@rm -rf $(OUT_DIR)
	@echo
	@echo "----------------------------------------------------"
	@echo "-------- [Output directory was cleaned now] --------"
	@echo "----------------------------------------------------"
	@echo
