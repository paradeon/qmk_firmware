LEADER_ENABLE = yes
TAP_DANCE_ENABLE = yes
# COMBO_ENABLE = yes
# AUTO_SHIFT_ENABLE = yes

BOOTMAGIC_ENABLE = no		# Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = yes		# Mouse keys(+4700)
EXTRAKEY_ENABLE = yes		# Audio control and System control(+450)
# CONSOLE_ENABLE = yes		# Console for debug(+400)
# COMMAND_ENABLE = yes		# Commands for debug and configuration
KEYBOARD_LOCK_ENABLE = no	# Allow locking of keyboard via magic key
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
# SLEEP_LED_ENABLE = yes	# Breathing sleep LED during USB suspend
NKRO_ENABLE = yes			# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
# BACKLIGHT_ENABLE = yes	# Enable keyboard backlight functionality
# MIDI_ENABLE = YES			# MIDI controls
# UNICODE_ENABLE = YES		# Unicode
# BLUETOOTH_ENABLE = yes	# Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no          # Enable RGB Underglow

ifndef QUANTUM_DIR
        include ../../../../Makefile
endif





