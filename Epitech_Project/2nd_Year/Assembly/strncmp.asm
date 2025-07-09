BITS 64
SECTION .text
GLOBAL strncmp

strncmp:
    ;;rdi = string1, rsi = string2, rdx = length

    cmp rdx , 0  ; check if length is zero
    je end_error  ; if yes, return 0
    mov rcx, rdx  ; save length
    xor rax, rax  ; clear rax

loop:
    mov al, byte [rdi]  ; load byte from string1
    mov bl, byte [rsi]  ; load byte from string2
    cmp al, bl  ; compare bytes
    jne end  ; return 0 if bytes are not equal
    test al, al  ; if byte is null
    je end  ; return 0 if byte is null
    inc rdi  ; increment string1 pointer
    inc rsi  ; increment string2 pointer
    dec rcx  ; decrement length
    jnz loop  ; continue

end:
    sub al, bl  ; subtract bytes
    movsx rax, al  ; return int
    ret  ; return

end_error:
    xor rax, rax  ; return 0
    ret  ; return
