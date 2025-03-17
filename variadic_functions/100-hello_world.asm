section					.data
												; Define the str "Hello World\n"
	msg					db "Hello, World", 0x0A ; 0x0A is NewLine
	len					equ $ -msg				; Calculate the length of the str


section					.text
global					main

main:
	; System call: write(fd, buf, count)
	mov rax, 1				; syscall number for write (1)
	mov rdi, 1				; file descriptor (1 = stdout)
	mov rsi, msg			; pointer to the str
	mov rdx, len			; length of the str
	syscall					; invoke the system call

	; System call: exit(status)
	mov rax, 60				; syscall number for exit (60)
	xor rdi, rdi			; status = 0
	syscall					; invoke the system call
