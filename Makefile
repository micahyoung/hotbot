ARDUINODIR = /Applications/Arduino.app/Contents/Resources/Java/
LIBRARIES := DHT22
BOARD = nano328
SERIALDEV = /dev/tty.usbserial-A901C6HG

include ~/Box/Projects/Hardware/lib/arduino-mk/arduino.mk
