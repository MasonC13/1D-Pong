; Mason Crim
; Jacob Hoke

.text
.global setLowAndTime

#define PB0 0
#define PB1 1
#define PORTB 0x05
#define PINB  0x03

setLowAndTime:
    clr r22             ; Initialize r22:r25 registers to zero
    clr r23
    clr r24
    clr r25
    ldi r20, 1          ; Load 1 into r20
    cbi PORTB, PB1      ; Clear PB1

loop1:
    in r21, PINB        ; PINB into r21
    andi r21, (1 << PB0)
    breq done1          ; If PB0 is low, done
    add r22, r20        ; Increment r22:r25
    adc r23, r1
    adc r24, r1
    adc r25, r1
    nop
    rjmp .              ; Delay cycles
    rjmp .
    rjmp .
    rjmp loop1

done1:
    sbi PORTB, PB1      ; Set PB1 HIGH again
    ret

