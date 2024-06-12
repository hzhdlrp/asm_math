section .bss
temp: resq 1


section .text
    global test2_d

test2_d: ; d((5-x)/2)/dx = -1/2
    enter 0, 0

    finit
    fld1
    mov dword[temp], 2
    fidiv dword[temp]
    fchs

    leave
    ret