

.gadget:
    pop %rdi
    retq
    pop %rax
    pop %rbx
    pop %rcx
    pop %rdx
    pop %rbp
    callq *%rax
    callq *%rbx
    callq *%rcx
    callq *%rdx
    callq *%rbp