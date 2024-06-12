section .bss
temp: resq 1


section .text
    global test2_d

test2_d: ; d((1-x)/3)/dx = -1/3
    enter 0, 0

    finit
    fld1
    mov dword[temp], 3
    fdivp
    fchs

    leave
    ret