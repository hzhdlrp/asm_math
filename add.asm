section .text
    global add
add:
    enter 0, 0
    mov eax, [ebp + 8]
    add eax, [ebp + 12]
    leave
    ret