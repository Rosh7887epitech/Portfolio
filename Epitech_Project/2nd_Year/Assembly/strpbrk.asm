BITS 64
SECTION .text
GLOBAL strpbrk

strpbrk:
    ;;rdi = string
    ;;rsi = string of character

    xor rcx, rcx  ; counter = 0

loop:
    xor rdx, rdx  ; counter = 0
    mov al, byte [rdi + rcx]  ; al = character
    cmp al, 0  ; compare with '\0'
    je end_error ; if '\0' then end
    inc rcx  ; add 1 to counter
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
    mov rax, rdi  ; return value = pointer to character
    dec rcx  ; decrement pointer
    add rax, rcx  ; add counter to pointer
    ret  ; return

end_error:
    xor rax, rax  ; return 0
    ret  ; return
