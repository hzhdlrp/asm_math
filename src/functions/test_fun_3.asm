extern printf
section .data
frm: db "%lf", 0xA, 0

section .bss
x: resq 1
temp: resq 1


section .text
    global test3

test3: ; ln(x) + 4, x > 0
    enter 0, 0

    mov eax, dword[ebp + 8]
    mov dword[x], eax
    mov eax, dword[ebp + 12]
    mov dword[x + 4], eax

    finit
    fld1
    fld qword[x]
    fyl2x
    ; st0 - log2(x)
    fldl2e
    ; st0 - log2(e)
    ; st1 - log2(x)
    fdivp
    mov dword[temp], 4
    fiadd dword[temp]
    leave
    ret