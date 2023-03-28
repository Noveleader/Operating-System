//Printing Nothing
//Create a file boot.asm in your testing folder, where you will play with it.
//Create it with the following code:
[BITS 16] ;tell the assembler that its a 16 bit code
[ORG 0x7C00] ;Origin, tell the assembler that where the code will
;be in memory after it is been loaded
JMP $ ;infinite loop
TIMES 510 - ($ - $$) db 0 ;fill the rest of sector with 0
DW 0xAA55 ; add boot signature at the end of bootloader
//Compile our assembly file boot.asm via nasm, running the command:
//nasm boot.asm -f bin -o boot1.bin
//Run the compiled binary file via QEMU: qemu-system-i386 -fda boot1.bin


//Printing Character 'A"
//Create a file boot.asm in your testing folder, where you will play with it.
//Create it with the following code.
[BITS 16] ;Tells the assembler that its a 16 bit code
[ORG 0x7C00] ;Origin, tell the assembler that where the code will
 ;be in memory after it is been loaded
MOV AL, 65
CALL PrintCharacter
JMP $ ;Infinite loop, hang it here.
PrintCharacter: ;Procedure to print character on screen
 ;Assume that ASCII value is in register AL
MOV AH, 0x0E ;Tell BIOS that we need to print one character on screen.
MOV BH, 0x00 ;Page no.
MOV BL, 0x07 ;Text attribute 0x07 is light grey font on black background
INT 0x10 ;Call video interrupt
RET ;Return to calling procedure
TIMES 510 - ($ - $$) db 0 ;Fill the rest of sector with 0
DW 0xAA55 ;Add boot signature at the end of bootloade
//Compile our assembly file boot.asm via nasm, running the command:
//nasm boot.asm -f bin -o boot1.bin
//Run the compiled binary file via QEMU: qemu-system-i386 -fda boot1.bin


//Printing Something
//Create a file boot.asm in your testing folder, where you will play with it.
//Create it with the following code.
org 0x7C00 ; BIOS loads our programm at this address
bits 16 ; We're working at 16-bit mode here
start:
cli ; Disable the interrupts
mov si, msg ; SI now points to our message
mov ah, 0x0E ; Indicate BIOS we're going to print chars
.loop lodsb ; Loads SI into AL and increments SI [next char]
or al, al ; Checks if the end of the string
jz halt ; Jump to halt if the end
int 0x10 ; Otherwise, call interrupt for printing the char
jmp .loop ; Next iteration of the loop
halt: hlt ; CPU command to halt the execution
msg: db "Something", 0 ; Our actual message to print
;; Magic numbers
times 510 - ($ - $$) db 0
dw 0xAA55
//Compile our assembly file boot.asm via nasm, running the command:
//nasm boot.asm -f bin -o boot1.bin
//Run the compiled binary file via QEMU: qemu-system-i386 -fda boot1.bin


