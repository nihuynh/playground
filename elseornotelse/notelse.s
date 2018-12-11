	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14
	.globl	_foo                    ## -- Begin function foo
	.p2align	4, 0x90
_foo:                                   ## @foo
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	-8(%rbp), %edx
	cmpl	-16(%rbp), %edx
	jle	LBB0_2
## %bb.1:
	movl	-16(%rbp), %eax
	movl	%eax, -4(%rbp)
	jmp	LBB0_6
LBB0_2:
	movl	-8(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jge	LBB0_4
## %bb.3:
	movl	-12(%rbp), %eax
	movl	%eax, -4(%rbp)
	jmp	LBB0_6
LBB0_4:
	jmp	LBB0_5
LBB0_5:
	movl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
LBB0_6:
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
