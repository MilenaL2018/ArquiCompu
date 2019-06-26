Función retardo

retorno:
        str     fp, [sp, #-4]!
        add     fp, sp, #0
        sub     sp, sp, #12
        str     r0, [fp, #-8]
        b       .L2
.L3:
        ldr     r3, [fp, #-8]
        sub     r3, r3, #1
        str     r3, [fp, #-8]
.L2:
        ldr     r3, [fp, #-8]
        cmp     r3, #0
        bne     .L3
        nop
        mov     r0, r3
        add     sp, fp, #0
        ldr     fp, [sp], #4
        bx      lr

switch case:
        str     r0, [fp, #-8]
        ldr     r3, [fp, #-8]
        cmp     r3, #98
        beq     .L6
        ldr     r3, [fp, #-8]
        cmp     r3, #99
        beq     .L7
        ldr     r3, [fp, #-8]
        cmp     r3, #97
        b       .L5
.L6:
        nop
        b       .L5
.L7:
        nop
.L5:
        nop
        mov     r0, r3
        add     sp, fp, #0
        ldr     fp, [sp], #4
        bx      lr

TENIS POR TABLA

.text

.extern velocidad_estandar
.extern controles_secuencia
.extern output
.extern delayMillis
.global tenis

datosTenis:
        .byte   -127
        .byte   -63
        .byte   -95
        .byte   -111
        .byte   -119
        .byte   -123
        .byte   -125
        .byte   -125
        .byte   -123
        .byte   -119
        .byte   -111
        .byte   -95
        .byte   -63
tenis():
        sub     sp, sp, #16
        str     wzr, [sp, 12]
.L3:
        ldr     w0, [sp, 12]
        cmp     w0, 12
        bgt     .L2
        ldr     w0, [sp, 12]
        add     w0, w0, 1
        str     w0, [sp, 12]
        b       .L3
.L2:
        mov     w0, 64
        str     w0, [sp, 8]
.L5:
        ldr     w0, [sp, 8]
        lsr     w1, w0, 31
        add     w0, w1, w0
        asr     w0, w0, 1
        str     w0, [sp, 8]
        ldr     w0, [sp, 8]
        cmp     w0, 2
        ble     .L4
        b       .L5
.L4:
        ldr     w0, [sp, 8]
        lsl     w0, w0, 1
        str     w0, [sp, 8]
        ldr     w0, [sp, 8]
        cmp     w0, 64
        bgt     .L7
        b       .L4
.L7:
        nop
        add     sp, sp, 16
        ret


.data


.end

