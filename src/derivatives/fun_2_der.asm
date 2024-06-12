section .bss
temp: resq 1

section .text
    global f2_d

f2_d: ; d(2x - 2)/dx = 2
    enter 0, 0

    finit
    mov dword[temp], 2
    fild dword[temp]

    leave
    ret