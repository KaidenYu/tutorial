.section .data

.section .text
	
	.global swap
swap:
	movq (%rdi), %rax
	movq (%rsi), %rdx
	movq %rdx, (%rdi)
	movq %rax, (%rsi)
	ret
