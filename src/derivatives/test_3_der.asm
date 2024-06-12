section .bss
x: resq 1
temp: resq 1

section .text
    global test3_d
test3_d: ; d(ln(x))/dx = 1/x, x > 0
    enter 0, 0

    mov eax, dword[ebp + 8]
    mov dword[x], eax
    mov eax, dword[ebp + 12]
    mov dword[x + 4], eax

    finit
    fld1
    fld qword[x]
    ; st0 - x
    ; st1 - 1
    fyl2x
    ;st0 - 1 * log2(x)
    fchs
    ; st0 - (-log2(x))

    fld st0
    frndint
    fsub st1, st0
    ; st0 - truc(-log2(x))
    ; st1 - frac(-log2(x))
    fxch
    f2xm1
    fld1
    faddp
    fscale
    ; st0 - 2^(-log2(x))= 1/x

    leave
    ret