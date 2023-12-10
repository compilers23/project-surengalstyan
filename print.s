.globl _print
_print:
    push %rbp
    mov %rsp, %rbp

    # Setup args
    lea fmt(%rip), %rdi # Load string address
    mov %rsi, %rsi
    xor %rax, %rax

    call _printf

    pop %rbp
    ret

fmt:
    .asciz "%d\n"
