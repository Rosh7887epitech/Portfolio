BITS 64
SECTION .text
GLOBAL strlen

strlen:
    XOR RCX, RCX ; counter = 0

loop:
    CMP BYTE [RDI + RCX], 0  ; compare with '\0'
    JE end  ; if '\0' then end
    INC RCX  ; add 1 to counter
    JMP loop  ; one more time

end:

    MOV RAX, RCX  ; return value = length of string
    RET  ; return
