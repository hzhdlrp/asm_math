section .bss
x: resq 1
temp: resq 1


section .text
    global f3
    
f3: ; 1/x
    enter 0, 0

    mov eax, dword[ebp + 8]
    mov dword[x], eax
    mov eax, dword[ebp + 12]
    mov dword[x + 4], eax

    finit
    mov dword[temp], 1
    fild qword[temp]
    fld qword[x]
    ; st0 - x
    ; st1 - 1
    fyl2x
    ;st0 - 1 * log2(x)
    fchs
    ; st0 - (-log2(x))
    f2xm1
    ; st0 - 2^(-log2(x)) - 1 = 1/x - 1
    fiadd dword[temp]

    leave
    ret