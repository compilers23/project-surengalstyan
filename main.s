.globl _main
_main:
  mov $42, %rsi
  call _print
exit:
  mov $60, %rax
  xor %rdi, %rdi
  syscall
