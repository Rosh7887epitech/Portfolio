BITS 64
SECTION .text
GLOBAL memmove

memmove:
    cmp rdx, 0  ; compare the size (rdx) to 0
    je end  ; if the size is 0, jump to the end

    mov rax, rdi  ; save the initial destination in rax
    cmp rdi, rsi  ; compare the destination and source addresses
    ja overlap_copy  ; if destination > source, copy backwards

normal_copy:
    xor rcx, rcx  ; initialize the counter (rcx) to 0

normal_loop:
    mov al, byte [rsi + rcx]  ; load a byte from the source into al
    mov byte [rdi + rcx], al  ; copy the byte from al to the destination
    inc rcx  ; increment the counter
    cmp rcx, rdx  ; compare the counter to the size
    jl normal_loop  ; if counter < size, repeat the loop
    jmp end  ; jump to the end

; Defense : "lea" permet de calculer une adresse mémoire et de la stocker directement dans un registre

overlap_copy:
    lea rsi, [rsi + rdx - 1]  ; adjust the source pointer to the end
    lea rdi, [rdi + rdx - 1]  ; adjust the destination pointer to the end

overlap_loop:
    mov al, byte [rsi]  ; load a byte from the source into al
    mov byte [rdi], al  ; copy the byte from al to the destination
    dec rsi  ; decrement the source pointer
    dec rdi  ; decrement the destination pointer
    dec rdx  ; decrement the size
    jnz overlap_loop  ; if size != 0, repeat the loop

end:
    mov rax, rdi  ; load the final destination address into rax
    ret  ; return
