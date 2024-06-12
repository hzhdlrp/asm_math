section .bss
x: resq 1
temp: resq 1


section .text
    global test1_d

test1_d: ; d(x^3)/dx = 3x^2
    enter 0, 0

    mov eax, dword[ebp + 8]
    mov dword[x], eax
    mov eax, dword[ebp + 12]
    mov dword[x + 4], eax

    finit
    fld qword[x]
    fld st0
    fmulp
    ; st0 - x^2
    mov dword[temp], 3
    fild dword[temp]
    fmulp

    leave
    ret