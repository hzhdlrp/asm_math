section .bss
x: resq 1
temp: resq 1


section .text
    global test2

test2: ; (1-x)/3
    enter 0, 0

    mov eax, dword[ebp + 8]
    mov dword[x], eax
    mov eax, dword[ebp + 12]
    mov dword[x + 4], eax

    finit
    fld qword[x]
    fchs
    fld1
    faddp
    mov dword[temp], 3
    fild dword[temp]
    fmulp

    leave
    ret