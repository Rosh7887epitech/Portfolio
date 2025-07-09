BITS 64
SECTION .text
GLOBAL strcasecmp

strcasecmp:
    ;; rdi = string1, rsi = string2

loop:
    mov al, byte [rdi] ; load byte rdi
    mov bl, byte [rsi]  ; load byte rsi
    cmp al, 'A'  ; compare bytes
    jl no_convert_al  ; if al < 'A'
    cmp al, 'Z'  ; if al > 'Z'
    jg no_convert_al  ; if al > 'Z'
    add al, 32  ; convert to lowercase

no_convert_al:
    cmp bl, 'A'  ; compare bytes
    jl no_convert_bl  ; if bl < 'A'
    cmp bl, 'Z'  ; if bl > 'Z'
    jg no_convert_bl  ; if bl > 'Z'
    add bl, 32  ; convert to lowercase

no_convert_bl:
    cmp al, bl  ; compare bytes
    jne end  ; return 0 if bytes are not equal
    test al, al  ; if byte is null
    je end  ; return 0 if byte is null
    inc rdi  ; increment string1 pointer
    inc rsi  ; increment string2 pointer
    jmp loop  ; continue

end:
    sub al, bl  ; subtract bytes
    movsx rax, al  ; return int
    ret  ; return
