BITS 64
SECTION .text
GLOBAL strcmp


strcmp:
    ;;rdi = string1, rsi = string2

loop:
    mov al, byte [rdi]  ; load byte rdi
    mov bl, byte [rsi]  ; load byte rsi
    cmp al, bl  ; compare bytes
    jne end  ; return 0 if bytes are not equal
    test al, al  ; if byte is null
    je end  ; return 0 if byte is null
    inc rdi  ; increment string1
    inc rsi  ; increment string2
    jmp loop  ; continue

; Defense : movsx permet de copier un byte signé dans un registre 64 bits alors que mov ne le permet pas

end:
    sub al, bl  ; subtract bytes
    movsx rax, al  ; return int
    ret  ; Return
