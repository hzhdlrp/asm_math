section .bss
x: resq 1
temp: resq 1


section .text
    global test1

test1: ; x^3
    enter 0, 0

    mov eax, dword[ebp + 8]
    mov dword[x], eax
    mov eax, dword[ebp + 12]
    mov dword[x + 4], eax

    finit
    fld qword[x]
    fld st0
    fld st0
    fmulp
    fmulp

    leave
    ret