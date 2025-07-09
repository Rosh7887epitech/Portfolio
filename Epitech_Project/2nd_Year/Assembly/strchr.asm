BITS 64
SECTION .text
GLOBAL strchr

strchr:
    ;;rdi = string
    ;;rsi = character

loop:
    mov al, byte [rdi]  ; al = character
    cmp al, sil  ; compare with character
    je end  ; if character then end
    cmp al, 0  ; compare with '\0'
    je end_error ; if '\0' then end
    inc rdi  ; add 1 to counter
    jmp loop  ; one more time

end:
    mov rax, rdi  ; return value = pointer to character
    ret  ; return

end_error:
    xor rax, rax  ; return 0
    ret  ; return
