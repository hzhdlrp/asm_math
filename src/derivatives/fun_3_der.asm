section .bss
x: resq 1


section .text
    global f3_d
    
f3_d: ; d(1/x)/dx = -1/x^2
    enter 0, 0

    mov eax, dword[ebp + 8]
    mov dword[x], eax
    mov eax, dword[ebp + 12]
    mov dword[x + 4], eax

    finit
    fld1
    fld qword[x]
    fld st0
    fmulp
    ; st0 - x^2
    ; st1 - 1
    fyl2x
    ;st0 - 1 * log2(x^2)
    fchs
    ; st0 - (-log2(x^2))

    fld st0
    frndint
    fsub st1, st0
    ; st0 - truc(-log2(x^2))
    ; st1 - frac(-log2(x^2))
    fxch
    f2xm1
    fld1
    faddp
    fscale
    ; st0 - 2^(-log2(x))= 1/x^2
    fchs 
    
    leave
    ret