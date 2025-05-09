# Mason Crim
# Jake Hoke

all: pong.hex

install: pong.hex
	avrdude -C "C:\\Program Files (x86)\\Arduino\\hardware\\tools\\avr\\etc\\avrdude.conf" -p atmega328p -c usbtiny -U flash:w:pong.hex:i
	
pong.hex: pong.elf
	avr-objcopy -j .text -j .data -O ihex pong.elf pong.hex

pong.elf: main.o timer.o led.o input.o buzzer.o sleep.o pong.o
	avr-gcc -mmcu=atmega328p -o pong.elf main.o timer.o led.o input.o buzzer.o sleep.o pong.o

main.o: main.c timer.h led.h input.h buzzer.h sleep.h
	avr-gcc -mmcu=atmega328p -c main.c

timer.o: timer.c timer.h led.h
	avr-gcc -mmcu=atmega328p -c timer.c

led.o: led.c led.h
	avr-gcc -mmcu=atmega328p -c led.c

input.o: input.c input.h
	avr-gcc -mmcu=atmega328p -c input.c

buzzer.o: buzzer.c buzzer.h
	avr-gcc -mmcu=atmega328p -c buzzer.c

sleep.o: sleep.c sleep.h
	avr-gcc -mmcu=atmega328p -c sleep.c

pong.o: pong.S
	avr-gcc -mmcu=atmega328p -c pong.S

clean:
	del *.o *.elf *.hex
