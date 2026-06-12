; This is a basic template file for writing 48K Spectrum code.

AppFilename             equ "NewFile"                   ; What we're called (for file generation)

AppFirst                equ $8000                       ; First byte of code (uncontended memory)

                        zeusemulate "48K","ULA+"        ; Set the model and enable ULA+


; Start planting code here. (When generating a tape file we start saving from here)

                        org AppFirst                    ; Start of application

AppEntry                ld A, 0FFH                       ; Valor bajo de número 1
                        ld B, 1H                        ; Valor alto de número 1
                        ld C, 1H                        ; Valor bajo de número 2
                        ld D, 2H                        ; Valor alto de número 2

                        ; Suma los valores
                        add A, C                        ; Suma los valores bajos
                        ld E, A                         ; Guarda el resultado bajo en E
                        ld A,B                          ;
                        adc A,D                         ; Suma los valores altos y el carry
                        ld H, A                         ; Guarda el resultado alto en H

                        ; Deposita el resultado en LOC3
                        ld IX,LOC3                      ;
                        ld (IX), E                      ; Deposita el valor bajo en LOC3
                        ld (IX+1), H                    ; Deposita el valor alto en LOC3+1

                        ;



                        halt                            ; Replace these lines with your code
                        jp AppEntry                     ;

                        LOC1 equ 8400H                  ;
                        LOC2 equ 8401H                  ;
                        LOC3 equ 8402H                  ;



; Stop planting code after this. (When generating a tape file we save bytes below here)
AppLast                 equ *-1                         ; The last used byte's address

; Generate some useful debugging commands

                        profile AppFirst,AppLast-AppFirst+1 ; Enable profiling for all the code

; Setup the emulation registers, so Zeus can emulate this code correctly

Zeus_PC                 equ AppEntry                    ; Tell the emulator where to start
Zeus_SP                 equ $FF40                       ; Tell the emulator where to put the stack

; These generate some output files

                        ; Generate a SZX file
                        output_szx AppFilename+".szx",$0000,AppEntry ; The szx file

                        ; If we want a fancy loader we need to load a loading screen
;                        import_bin AppFilename+".scr",$4000            ; Load a loading screen

                        ; Now, also generate a tzx file using the loader
                        output_tzx AppFilename+".tzx",AppFilename,"",AppFirst,AppLast-AppFirst,1,AppEntry ; A tzx file using the loader


