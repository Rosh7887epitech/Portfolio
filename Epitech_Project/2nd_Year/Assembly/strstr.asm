BITS 64
SECTION .text
GLOBAL strstr

strstr:
    ;; rdi = haystack, rsi = needle
    ;; r9 = haystack pointer, r10 = needle pointer, r8 = current haystack position

    cmp byte [rsi], 0  ; if needle = '\0'
    jz end_haystack  ; if yes, return haystack
    mov r8, rdi  ; save haystack pointer

search_loop:
    cmp byte [r8], 0 ; if end of haystack
    jz end_error  ; if reached, return NULL
    mov r9, r8  ; start checking from current haystack position
    mov r10, rsi  ; start of needle

loop_check:
    mov al, [r9]  ; byte from haystack
    mov bl, [r10] ; byte from needle
    cmp bl, 0 ; if end of needle
    je end_found  ; full match found
    cmp al, 0 ; if end of haystack
    jz end_error  ; return NULL
    cmp al, bl  ; compare characters
    jne next_char_haystack   ; if different, move to next position
    inc r9  ; move to next character
    inc r10   ; move to next character in needle
    jmp loop_check ; continue comparing

next_char_haystack:
    inc r8  ; move to next character
    jmp search_loop  ; Restart search

end_found:
    mov rax, r8  ; return pointer to match
    ret

end_haystack:
    mov rax, rdi ; return haystack
    ret

end_error:
    xor rax, rax ; return NULL
    ret
