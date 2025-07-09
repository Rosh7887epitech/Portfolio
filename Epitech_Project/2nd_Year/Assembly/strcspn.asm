BITS 64
SECTION .text
GLOBAL strcspn


strcspn:
    ;;rdi = string
    ;;rsi = string of character

    xor rcx, rcx  ; counter = 0

loop:
    xor rdx, rdx  ; counter = 0
    mov al, byte [rdi + rcx]  ; al = character
    inc rcx  ; add 1 to counter
    cmp al, 0  ; compare with '\0'
    je end ; if '\0' then end
    jmp loop_compare  ; second loop

loop_compare:
    mov bl, byte [rsi + rdx]  ; bl = character
    cmp al, bl  ; compare with character
    je end  ; if character then end
    cmp bl, 0  ; compare with '\0'
    je loop  ; if '\0' then end
    inc rdx  ; add 1 to counter
    jmp loop_compare  ; one more time

end:
    cmp rcx, 0  ; compare with 0
    je end_zero  ; if 0
    dec rcx  ; decrement pointer
    movsx rax, cl  ; return value = counter
    ret  ; return

end_zero:
    movsx rax, cl  ; return value = counter
    ret  ; return
