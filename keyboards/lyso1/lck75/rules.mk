# MCU name
MCU = atmega32a

# Processor frequency
F_CPU = 16000000

# Bootloader selection
BOOTLOADER = usbasploader

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite

# disabling these will give more space for the AVR to compile and hold more.
CONSOLE_ENABLE = no        	# Console for debug
COMMAND_ENABLE = no        	# Commands for debug and configuration
MOUSEKEY_ENABLE = no       	# Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control

# more space saving
SPACE_CADET_ENABLE = yes 	# cool stuff for open and close parentheses
GRAVE_ESC_ENABLE = no		# only really useful for smaller boards
MAGIC_ENABLE = no 			# magic keys swap lots of different keys
COMMAND_ENABLE = no			# make sure it does not conflict with space cadet

MUSIC_ENABLE = no			# remove music (NO_MUSIC_MODE in config.h)


NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output


UNICODE_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
ENCODER_ENABLE = yes
WPM_ENABLE = yes
LTO_ENABLE = yes			# saving space; disables Action Func & Macros
AUTO_SHIFT_ENABLE = no

SRC += lck75_oled.c			# adding in the oled control file
