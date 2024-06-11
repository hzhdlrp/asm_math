section .bss
x: resq 1
temp: resq 1


section .text
    global f2

f2: ; 2x - 2
    enter 0, 0

    mov eax, dword[ebp + 8]
    mov dword[x], eax
    mov eax, dword[ebp + 12]
    mov dword[x + 4], eax

    finit
    fld qword[x]
    mov dword[temp], 2
    fimul dword[temp]
    fisub dword[temp]

    leave
    ret