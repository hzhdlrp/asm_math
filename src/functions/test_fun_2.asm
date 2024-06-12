section .bss
x: resq 1
temp: resq 1


section .text
    global test2

test2: ; (5-x)/2
    enter 0, 0

    mov eax, dword[ebp + 8]
    mov dword[x], eax
    mov eax, dword[ebp + 12]
    mov dword[x + 4], eax

    finit
    fld qword[x]
    fchs
    mov dword[temp], 5
    fiadd dword[temp]
    mov dword[temp], 2
    fidiv dword[temp]

    leave
    ret