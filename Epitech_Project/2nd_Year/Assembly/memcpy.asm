BITS 64
SECTION .text
GLOBAL memcpy

memcpy:
    ;;rdi = destination, rsi = source, rdx = length

    cmp rdx, 0  ; check if length is zero
    je end  ; if yes, return destination
    xor rax, rax  ; return value = 0
    xor rcx, rcx  ; counter = 0

loop:
    mov al, byte [rsi + rcx]  ; load byte from source
    mov byte [rdi + rcx], al  ; store byte to destination
    inc rcx  ; increment pointer
    dec rdx  ; decrement length
    cmp rdx, 0  ; check if length is zero
    jne loop  ; continue if length > 0

end:
    mov rax, rdi  ; return value = pointer to destination
    ret  ; return
