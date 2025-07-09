BITS 64
SECTION .text
GLOBAL strrchr

strrchr:
    ;;rdi = string
    ;;rsi = character

    test rdi, rdi  ; if string is null
    je end_error ; return 0
    xor r9, r9  ; r9 = 0

loop:
    mov al, byte [rdi]  ; al = character
    cmp al, 0  ; compare with '\0'
    je check_end ; if '\0' then check_end
    cmp al, sil  ; compare with character
    jne continue
    mov r9, rdi

continue:
    inc rdi  ; add 1 to counter
    jmp loop

check_end:
    cmp sil, 0  ; compare character with '\0'
    jne end_chr ; if character != '\0' then end_chr
    mov r9, rdi  ; else r9 = rdi

end_chr:
    mov rax, r9 ; return value = pointer to good character
    ret  ; return

end_error:  ; return null
    xor rax, rax
    ret
