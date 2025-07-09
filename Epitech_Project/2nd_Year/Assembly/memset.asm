BITS 64
SECTION .text
GLOBAL memset

memset:
    ;;rdi = string, rsi = character, rdx = length

    xor rax, rax  ; clear rax
    xor rcx, rcx  ; counter = 0

loop:
    cmp rdx, rcx  ; check if length is zero
    je end  ; if length == 0
    mov byte [rdi + rcx], sil  ; fill character (sil) at address rdi
    inc rcx  ; increment pointer
    jmp loop  ; repeat

end:
    mov rax, rdi  ; return value = pointer to string
    ret  ; return
