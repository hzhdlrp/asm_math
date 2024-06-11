section .bss
x: resq 1
temp: resq 1


section .text
    global f1

f1: ; e^(-x) + 3
    enter 0, 0

    mov eax, dword[ebp + 8]
    mov dword[x], eax
    mov eax, dword[ebp + 12]
    mov dword[x + 4], eax

    finit
    fld qword[x]
    fchs
    fldl2e
    ; st0 - log2(e)
    ; st1 - (-x)
    fmulp
    ;st0 - log2(e)*(-x)
    f2xm1
    ;st0 - e^(-x) - 1
    mov dword[temp], 4
    fiadd dword[temp]

    leave
    ret
