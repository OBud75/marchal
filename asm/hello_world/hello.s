.global _start
.intel_syntax noprefix

_start:
  # Write console
  mov rax, 1
  mov rdi, 1
  lea rsi, [hello_ptr] # to access a pointer
  mov rdx, [hello_size]
  syscall

  # Read
  mov rax, 0
  syscall

  # Exit
  mov rax, 60
  mov rdi, 0
  syscall

hello_ptr:
  .asciz "Hello world\n"

hello_size:
  .int 13 

; Les commentaires ressembles à des noms de fonctions.
; Créer des fonctions (exit, read, write...) puis les appeler depuis _start rendra le code plus "humain"
; Les commentaires deviendront redondants et on peut donc les enlever ce qui est une bonne chose
; car moins de maintenance et erreurs possibles (le commentaire peut mentir).