section .data
  input_msg db "what is you name?", 0xA    ; The message to display, followed by a newline
  input_msg_len equ $ - input_msg ; calculate the length of `msg`
  msg db "Hello "
  msg_len equ $ - msg ; calculate the length of `msg`

section .bss
    buffer resb 128          ; Reserve 128 bytes for the input buffer

section .text
    global _start

_start:
  ; Ask for input
  mov rax, 1              ; Syscall number for sys_write (1)
  mov rdi, 1              ; File descriptor (1 for stdout)
  lea rsi, [input_msg]
  mov rdx, input_msg_len
  syscall

  ; Read input from the terminal (stdin)
  mov rax, 0              ; Syscall number for sys_read (0)
  mov rdi, 0              ; File descriptor (0 for stdin)
  lea rsi, [buffer]       ; Address of buffer to store input
  mov rdx, 128            ; Number of bytes to read
  syscall                 ; Make syscall

  ; Write message
  mov rax, 1              ; Syscall number for sys_write (1)
  mov rdi, 1              ; File descriptor (1 for stdout)
  lea rsi, [msg]
  mov rdx, msg_len
  syscall

  ; Write the input back to the terminal (stdout)
  mov rax, 1              ; Syscall number for sys_write (1)
  mov rdi, 1              ; File descriptor (1 for stdout)
  lea rsi, [buffer]       ; Address of buffer with input to write
  mov rdx, 128
  syscall                 ; Make syscall

  ; Exit the program
  mov rax, 60             ; Syscall number for sys_exit (60)
  mov rdi, 0            ; Exit code 0
  syscall                 ; Make syscall

