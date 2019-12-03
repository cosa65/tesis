	.file	"ping-pong.cpp"
	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.type	_ZStL13allocator_arg, @object
	.size	_ZStL13allocator_arg, 1
_ZStL13allocator_arg:
	.zero	1
	.type	_ZStL6ignore, @object
	.size	_ZStL6ignore, 1
_ZStL6ignore:
	.zero	1
	.section	.text._ZNSt9_Any_data9_M_accessEv,"axG",@progbits,_ZNSt9_Any_data9_M_accessEv,comdat
	.align 2
	.weak	_ZNSt9_Any_data9_M_accessEv
	.type	_ZNSt9_Any_data9_M_accessEv, @function
_ZNSt9_Any_data9_M_accessEv:
.LFB1185:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1185:
	.size	_ZNSt9_Any_data9_M_accessEv, .-_ZNSt9_Any_data9_M_accessEv
	.section	.text._ZNKSt9_Any_data9_M_accessEv,"axG",@progbits,_ZNKSt9_Any_data9_M_accessEv,comdat
	.align 2
	.weak	_ZNKSt9_Any_data9_M_accessEv
	.type	_ZNKSt9_Any_data9_M_accessEv, @function
_ZNKSt9_Any_data9_M_accessEv:
.LFB1186:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1186:
	.size	_ZNKSt9_Any_data9_M_accessEv, .-_ZNKSt9_Any_data9_M_accessEv
	.section	.text._ZNSt14_Function_baseC2Ev,"axG",@progbits,_ZNSt14_Function_baseC5Ev,comdat
	.align 2
	.weak	_ZNSt14_Function_baseC2Ev
	.type	_ZNSt14_Function_baseC2Ev, @function
_ZNSt14_Function_baseC2Ev:
.LFB1204:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, 16(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1204:
	.size	_ZNSt14_Function_baseC2Ev, .-_ZNSt14_Function_baseC2Ev
	.weak	_ZNSt14_Function_baseC1Ev
	.set	_ZNSt14_Function_baseC1Ev,_ZNSt14_Function_baseC2Ev
	.section	.text._ZNSt14_Function_baseD2Ev,"axG",@progbits,_ZNSt14_Function_baseD5Ev,comdat
	.align 2
	.weak	_ZNSt14_Function_baseD2Ev
	.type	_ZNSt14_Function_baseD2Ev, @function
_ZNSt14_Function_baseD2Ev:
.LFB1207:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1207
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L8
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	-8(%rbp), %rsi
	movq	-8(%rbp), %rcx
	movl	$3, %edx
	movq	%rcx, %rdi
	call	*%rax
.L8:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1207:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._ZNSt14_Function_baseD2Ev,"aG",@progbits,_ZNSt14_Function_baseD5Ev,comdat
.LLSDA1207:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1207-.LLSDACSB1207
.LLSDACSB1207:
.LLSDACSE1207:
	.section	.text._ZNSt14_Function_baseD2Ev,"axG",@progbits,_ZNSt14_Function_baseD5Ev,comdat
	.size	_ZNSt14_Function_baseD2Ev, .-_ZNSt14_Function_baseD2Ev
	.weak	_ZNSt14_Function_baseD1Ev
	.set	_ZNSt14_Function_baseD1Ev,_ZNSt14_Function_baseD2Ev
	.section	.rodata
	.align 4
	.type	_ZN9__gnu_cxxL21__default_lock_policyE, @object
	.size	_ZN9__gnu_cxxL21__default_lock_policyE, 4
_ZN9__gnu_cxxL21__default_lock_policyE:
	.long	2
	.align 4
	.type	_ZL24SG_BARRIER_SERIAL_THREAD, @object
	.size	_ZL24SG_BARRIER_SERIAL_THREAD, 4
_ZL24SG_BARRIER_SERIAL_THREAD:
	.long	-1
	.type	_ZStL10defer_lock, @object
	.size	_ZStL10defer_lock, 1
_ZStL10defer_lock:
	.zero	1
	.type	_ZStL11try_to_lock, @object
	.size	_ZStL11try_to_lock, 1
_ZStL11try_to_lock:
	.zero	1
	.type	_ZStL10adopt_lock, @object
	.size	_ZStL10adopt_lock, 1
_ZStL10adopt_lock:
	.zero	1
	.align 8
	.type	_ZN5boost6detail15aligned_storageL22alignment_of_max_alignE, @object
	.size	_ZN5boost6detail15aligned_storageL22alignment_of_max_alignE, 8
_ZN5boost6detail15aligned_storageL22alignment_of_max_alignE:
	.quad	16
	.local	_ZN7simgrid5simixL12simix_timersE
	.comm	_ZN7simgrid5simixL12simix_timersE,40,32
	.section	.text._ZN5boost6none_tC2ENS0_8init_tagE,"axG",@progbits,_ZN5boost6none_tC5ENS0_8init_tagE,comdat
	.align 2
	.weak	_ZN5boost6none_tC2ENS0_8init_tagE
	.type	_ZN5boost6none_tC2ENS0_8init_tagE, @function
_ZN5boost6none_tC2ENS0_8init_tagE:
.LFB6287:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6287:
	.size	_ZN5boost6none_tC2ENS0_8init_tagE, .-_ZN5boost6none_tC2ENS0_8init_tagE
	.weak	_ZN5boost6none_tC1ENS0_8init_tagE
	.set	_ZN5boost6none_tC1ENS0_8init_tagE,_ZN5boost6none_tC2ENS0_8init_tagE
	.local	_ZN5boostL4noneE
	.comm	_ZN5boostL4noneE,1,1
	.section	.text._ZN5boost11optional_ns15in_place_init_tC2ENS1_8init_tagE,"axG",@progbits,_ZN5boost11optional_ns15in_place_init_tC5ENS1_8init_tagE,comdat
	.align 2
	.weak	_ZN5boost11optional_ns15in_place_init_tC2ENS1_8init_tagE
	.type	_ZN5boost11optional_ns15in_place_init_tC2ENS1_8init_tagE, @function
_ZN5boost11optional_ns15in_place_init_tC2ENS1_8init_tagE:
.LFB6301:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6301:
	.size	_ZN5boost11optional_ns15in_place_init_tC2ENS1_8init_tagE, .-_ZN5boost11optional_ns15in_place_init_tC2ENS1_8init_tagE
	.weak	_ZN5boost11optional_ns15in_place_init_tC1ENS1_8init_tagE
	.set	_ZN5boost11optional_ns15in_place_init_tC1ENS1_8init_tagE,_ZN5boost11optional_ns15in_place_init_tC2ENS1_8init_tagE
	.local	_ZN5boost11optional_nsL13in_place_initE
	.comm	_ZN5boost11optional_nsL13in_place_initE,1,1
	.section	.text._ZN5boost11optional_ns18in_place_init_if_tC2ENS1_8init_tagE,"axG",@progbits,_ZN5boost11optional_ns18in_place_init_if_tC5ENS1_8init_tagE,comdat
	.align 2
	.weak	_ZN5boost11optional_ns18in_place_init_if_tC2ENS1_8init_tagE
	.type	_ZN5boost11optional_ns18in_place_init_if_tC2ENS1_8init_tagE, @function
_ZN5boost11optional_ns18in_place_init_if_tC2ENS1_8init_tagE:
.LFB6304:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6304:
	.size	_ZN5boost11optional_ns18in_place_init_if_tC2ENS1_8init_tagE, .-_ZN5boost11optional_ns18in_place_init_if_tC2ENS1_8init_tagE
	.weak	_ZN5boost11optional_ns18in_place_init_if_tC1ENS1_8init_tagE
	.set	_ZN5boost11optional_ns18in_place_init_if_tC1ENS1_8init_tagE,_ZN5boost11optional_ns18in_place_init_if_tC2ENS1_8init_tagE
	.local	_ZN5boost11optional_nsL16in_place_init_ifE
	.comm	_ZN5boost11optional_nsL16in_place_init_ifE,1,1
	.section	.rodata
	.align 4
	.type	_ZL15NO_MAX_DURATION, @object
	.size	_ZL15NO_MAX_DURATION, 4
_ZL15NO_MAX_DURATION:
	.long	-1
	.text
	.globl	_simgrid_log_category__sample_simulator__constructor__
	.type	_simgrid_log_category__sample_simulator__constructor__, @function
_simgrid_log_category__sample_simulator__constructor__:
.LFB6559:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	40+_simgrid_log_category__sample_simulator(%rip), %eax
	testl	%eax, %eax
	jne	.L14
	movl	$-1, %esi
	leaq	_simgrid_log_category__sample_simulator(%rip), %rdi
	call	_xbt_log_cat_init@PLT
.L14:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6559:
	.size	_simgrid_log_category__sample_simulator__constructor__, .-_simgrid_log_category__sample_simulator__constructor__
	.section	.init_array.00600,"aw"
	.align 8
	.quad	_simgrid_log_category__sample_simulator__constructor__
	.globl	_simgrid_log_category__sample_simulator
	.section	.rodata
.LC0:
	.string	"sample_simulator"
	.align 8
.LC1:
	.string	"Messages specific for this simulator"
	.section	.data.rel,"aw",@progbits
	.align 32
	.type	_simgrid_log_category__sample_simulator, @object
	.size	_simgrid_log_category__sample_simulator, 80
_simgrid_log_category__sample_simulator:
	.quad	_simgrid_log_category__root
	.quad	0
	.quad	0
	.quad	.LC0
	.quad	.LC1
	.long	0
	.long	-1
	.long	1
	.zero	4
	.quad	0
	.quad	0
	.long	1
	.zero	4
	.section	.data.rel.local,"aw",@progbits
	.align 8
	.type	_ZL30_simgrid_log_category__default, @object
	.size	_ZL30_simgrid_log_category__default, 8
_ZL30_simgrid_log_category__default:
	.quad	_simgrid_log_category__sample_simulator
	.section	.rodata
	.align 8
.LC2:
	.string	"/home/martin/Documents/Tesis/Experimentacion/simgrid/simple_network/ping-pong.cpp"
	.align 8
.LC3:
	.string	"Ping from mailbox %s to mailbox %s"
	.align 8
.LC4:
	.string	"Task received : large communication (bandwidth bound)"
	.align 8
.LC5:
	.string	"Pong time (bandwidth bound): %.3f"
	.text
	.type	_ZL6pingerPN7simgrid3s4u7MailboxES2_, @function
_ZL6pingerPN7simgrid3s4u7MailboxES2_:
.LFB6560:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$168, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -152(%rbp)
	movq	%rsi, -160(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	40(%rax), %eax
	testl	%eax, %eax
	jne	.L16
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	$4, %esi
	movq	%rax, %rdi
	call	_xbt_log_cat_init@PLT
	testl	%eax, %eax
	je	.L17
.L16:
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	44(%rax), %eax
	cmpl	$4, %eax
	jg	.L17
	movl	$1, %eax
	jmp	.L18
.L17:
	movl	$0, %eax
.L18:
	testb	%al, %al
	je	.L19
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movq	%rax, -112(%rbp)
	movl	$4, -104(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, -96(%rbp)
	leaq	_ZZL6pingerPN7simgrid3s4u7MailboxES2_E8__func__(%rip), %rax
	movq	%rax, -88(%rbp)
	movl	$12, -80(%rbp)
	movq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7simgrid3s4u7Mailbox8get_nameB5cxx11Ev@PLT
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv@PLT
	movq	%rax, %rbx
	movq	-152(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7simgrid3s4u7Mailbox8get_nameB5cxx11Ev@PLT
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv@PLT
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rbx, %rcx
	leaq	.LC3(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	_xbt_log_event_log@PLT
.L19:
	call	_ZN7simgrid3s4u6Engine9get_clockEv@PLT
	movq	%xmm0, %rbx
	movl	$8, %edi
	call	_Znwm@PLT
	movq	%rbx, (%rax)
	movq	%rax, -136(%rbp)
	movq	-136(%rbp), %rcx
	movq	-160(%rbp), %rax
	movl	$1, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN7simgrid3s4u7Mailbox3putEPvm@PLT
	movq	-152(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7simgrid3s4u7Mailbox3getEv@PLT
	movq	%rax, -128(%rbp)
	call	_ZN7simgrid3s4u6Engine9get_clockEv@PLT
	movapd	%xmm0, %xmm1
	movq	-128(%rbp), %rax
	movsd	(%rax), %xmm0
	subsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	movsd	%xmm0, -120(%rbp)
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	40(%rax), %eax
	testl	%eax, %eax
	jne	.L20
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	$4, %esi
	movq	%rax, %rdi
	call	_xbt_log_cat_init@PLT
	testl	%eax, %eax
	je	.L21
.L20:
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	44(%rax), %eax
	cmpl	$4, %eax
	jg	.L21
	movl	$1, %eax
	jmp	.L22
.L21:
	movl	$0, %eax
.L22:
	testb	%al, %al
	je	.L23
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movq	%rax, -112(%rbp)
	movl	$4, -104(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, -96(%rbp)
	leaq	_ZZL6pingerPN7simgrid3s4u7MailboxES2_E8__func__(%rip), %rax
	movq	%rax, -88(%rbp)
	movl	$22, -80(%rbp)
	leaq	-112(%rbp), %rax
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	_xbt_log_event_log@PLT
.L23:
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	40(%rax), %eax
	testl	%eax, %eax
	jne	.L24
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	$4, %esi
	movq	%rax, %rdi
	call	_xbt_log_cat_init@PLT
	testl	%eax, %eax
	je	.L25
.L24:
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	44(%rax), %eax
	cmpl	$4, %eax
	jg	.L25
	movl	$1, %eax
	jmp	.L26
.L25:
	movl	$0, %eax
.L26:
	testb	%al, %al
	je	.L27
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movq	%rax, -112(%rbp)
	movl	$4, -104(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, -96(%rbp)
	leaq	_ZZL6pingerPN7simgrid3s4u7MailboxES2_E8__func__(%rip), %rax
	movq	%rax, -88(%rbp)
	movl	$23, -80(%rbp)
	movq	-120(%rbp), %rdx
	leaq	-112(%rbp), %rax
	movq	%rdx, -168(%rbp)
	movsd	-168(%rbp), %xmm0
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	movl	$1, %eax
	call	_xbt_log_event_log@PLT
.L27:
	movq	-128(%rbp), %rax
	movq	%rax, %rdi
	call	_ZdlPv@PLT
	nop
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L28
	call	__stack_chk_fail@PLT
.L28:
	addq	$168, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6560:
	.size	_ZL6pingerPN7simgrid3s4u7MailboxES2_, .-_ZL6pingerPN7simgrid3s4u7MailboxES2_
	.section	.rodata
	.align 8
.LC6:
	.string	"Pong from mailbox %s to mailbox %s"
	.align 8
.LC7:
	.string	"Task received : small communication (latency bound)"
.LC8:
	.string	" Ping time (latency bound) %f"
.LC10:
	.string	"task_bw->data = %.3f"
	.text
	.type	_ZL6pongerPN7simgrid3s4u7MailboxES2_, @function
_ZL6pongerPN7simgrid3s4u7MailboxES2_:
.LFB6561:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$168, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -152(%rbp)
	movq	%rsi, -160(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	40(%rax), %eax
	testl	%eax, %eax
	jne	.L30
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	$4, %esi
	movq	%rax, %rdi
	call	_xbt_log_cat_init@PLT
	testl	%eax, %eax
	je	.L31
.L30:
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	44(%rax), %eax
	cmpl	$4, %eax
	jg	.L31
	movl	$1, %eax
	jmp	.L32
.L31:
	movl	$0, %eax
.L32:
	testb	%al, %al
	je	.L33
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movq	%rax, -112(%rbp)
	movl	$4, -104(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, -96(%rbp)
	leaq	_ZZL6pongerPN7simgrid3s4u7MailboxES2_E8__func__(%rip), %rax
	movq	%rax, -88(%rbp)
	movl	$29, -80(%rbp)
	movq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7simgrid3s4u7Mailbox8get_nameB5cxx11Ev@PLT
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv@PLT
	movq	%rax, %rbx
	movq	-152(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7simgrid3s4u7Mailbox8get_nameB5cxx11Ev@PLT
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv@PLT
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rbx, %rcx
	leaq	.LC6(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	_xbt_log_event_log@PLT
.L33:
	movq	-152(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7simgrid3s4u7Mailbox3getEv@PLT
	movq	%rax, -136(%rbp)
	call	_ZN7simgrid3s4u6Engine9get_clockEv@PLT
	movapd	%xmm0, %xmm1
	movq	-136(%rbp), %rax
	movsd	(%rax), %xmm0
	subsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	movsd	%xmm0, -128(%rbp)
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	40(%rax), %eax
	testl	%eax, %eax
	jne	.L34
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	$4, %esi
	movq	%rax, %rdi
	call	_xbt_log_cat_init@PLT
	testl	%eax, %eax
	je	.L35
.L34:
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	44(%rax), %eax
	cmpl	$4, %eax
	jg	.L35
	movl	$1, %eax
	jmp	.L36
.L35:
	movl	$0, %eax
.L36:
	testb	%al, %al
	je	.L37
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movq	%rax, -112(%rbp)
	movl	$4, -104(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, -96(%rbp)
	leaq	_ZZL6pongerPN7simgrid3s4u7MailboxES2_E8__func__(%rip), %rax
	movq	%rax, -88(%rbp)
	movl	$34, -80(%rbp)
	leaq	-112(%rbp), %rax
	leaq	.LC7(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	_xbt_log_event_log@PLT
.L37:
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	40(%rax), %eax
	testl	%eax, %eax
	jne	.L38
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	$4, %esi
	movq	%rax, %rdi
	call	_xbt_log_cat_init@PLT
	testl	%eax, %eax
	je	.L39
.L38:
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	44(%rax), %eax
	cmpl	$4, %eax
	jg	.L39
	movl	$1, %eax
	jmp	.L40
.L39:
	movl	$0, %eax
.L40:
	testb	%al, %al
	je	.L41
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movq	%rax, -112(%rbp)
	movl	$4, -104(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, -96(%rbp)
	leaq	_ZZL6pongerPN7simgrid3s4u7MailboxES2_E8__func__(%rip), %rax
	movq	%rax, -88(%rbp)
	movl	$35, -80(%rbp)
	movq	-128(%rbp), %rdx
	leaq	-112(%rbp), %rax
	movq	%rdx, -168(%rbp)
	movsd	-168(%rbp), %xmm0
	leaq	.LC8(%rip), %rsi
	movq	%rax, %rdi
	movl	$1, %eax
	call	_xbt_log_event_log@PLT
.L41:
	movq	-136(%rbp), %rax
	movq	%rax, %rdi
	call	_ZdlPv@PLT
	movl	$8, %edi
	call	_Znwm@PLT
	pxor	%xmm0, %xmm0
	movsd	%xmm0, (%rax)
	movq	%rax, -120(%rbp)
	call	_ZN7simgrid3s4u6Engine9get_clockEv@PLT
	movq	%xmm0, %rdx
	movq	-120(%rbp), %rax
	movq	%rdx, (%rax)
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	40(%rax), %eax
	testl	%eax, %eax
	jne	.L42
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	$4, %esi
	movq	%rax, %rdi
	call	_xbt_log_cat_init@PLT
	testl	%eax, %eax
	je	.L43
.L42:
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	44(%rax), %eax
	cmpl	$4, %eax
	jg	.L43
	movl	$1, %eax
	jmp	.L44
.L43:
	movl	$0, %eax
.L44:
	testb	%al, %al
	je	.L45
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movq	%rax, -112(%rbp)
	movl	$4, -104(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, -96(%rbp)
	leaq	_ZZL6pongerPN7simgrid3s4u7MailboxES2_E8__func__(%rip), %rax
	movq	%rax, -88(%rbp)
	movl	$41, -80(%rbp)
	movq	-120(%rbp), %rax
	movq	(%rax), %rdx
	leaq	-112(%rbp), %rax
	movq	%rdx, -168(%rbp)
	movsd	-168(%rbp), %xmm0
	leaq	.LC10(%rip), %rsi
	movq	%rax, %rdi
	movl	$1, %eax
	call	_xbt_log_event_log@PLT
.L45:
	movq	-120(%rbp), %rcx
	movq	-160(%rbp), %rax
	movl	$1000000000, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN7simgrid3s4u7Mailbox3putEPvm@PLT
	nop
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L46
	call	__stack_chk_fail@PLT
.L46:
	addq	$168, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6561:
	.size	_ZL6pongerPN7simgrid3s4u7MailboxES2_, .-_ZL6pongerPN7simgrid3s4u7MailboxES2_
	.section	.rodata
.LC11:
	.string	"Usage: %s platform_file.xml"
.LC12:
	.string	"Mailbox 1"
.LC13:
	.string	"Mailbox 2"
.LC14:
	.string	"node-0.acme.org"
.LC15:
	.string	"pinger"
.LC16:
	.string	"node-1.acme.org"
.LC17:
	.string	"ponger"
.LC18:
	.string	"Total simulation time: %.3f"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6562:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA6562
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$200, %rsp
	.cfi_offset 3, -24
	movl	%edi, -196(%rbp)
	movq	%rsi, -208(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-208(%rbp), %rdx
	leaq	-196(%rbp), %rcx
	leaq	-184(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
.LEHB0:
	call	_ZN7simgrid3s4u6EngineC1EPiPPc@PLT
.LEHE0:
	movl	-196(%rbp), %eax
	cmpl	$2, %eax
	je	.L48
	movl	40+_simgrid_log_category__root(%rip), %eax
	testl	%eax, %eax
	jne	.L49
	movl	$7, %esi
	leaq	_simgrid_log_category__root(%rip), %rdi
.LEHB1:
	call	_xbt_log_cat_init@PLT
	testl	%eax, %eax
	je	.L50
.L49:
	movl	44+_simgrid_log_category__root(%rip), %eax
	cmpl	$7, %eax
	jg	.L50
	movl	$1, %eax
	jmp	.L51
.L50:
	movl	$0, %eax
.L51:
	testb	%al, %al
	je	.L52
	leaq	_simgrid_log_category__root(%rip), %rax
	movq	%rax, -112(%rbp)
	movl	$7, -104(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, -96(%rbp)
	leaq	_ZZ4mainE8__func__(%rip), %rax
	movq	%rax, -88(%rbp)
	movl	$50, -80(%rbp)
	movq	-208(%rbp), %rax
	movq	(%rax), %rdx
	leaq	-112(%rbp), %rax
	leaq	.LC11(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	_xbt_log_event_log@PLT
.L52:
	movl	xbt_log_no_loc(%rip), %eax
	testl	%eax, %eax
	jne	.L53
	call	xbt_backtrace_display_current@PLT
.LEHE1:
.L53:
	call	abort@PLT
.L48:
	leaq	-168(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	movq	-208(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rcx
	leaq	-168(%rbp), %rdx
	leaq	-112(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
.LEHB2:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@PLT
.LEHE2:
	leaq	-112(%rbp), %rdx
	leaq	-184(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB3:
	call	_ZN7simgrid3s4u6Engine13load_platformERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@PLT
.LEHE3:
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-168(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	leaq	-168(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	leaq	-168(%rbp), %rdx
	leaq	-112(%rbp), %rax
	leaq	.LC12(%rip), %rsi
	movq	%rax, %rdi
.LEHB4:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@PLT
.LEHE4:
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
.LEHB5:
	call	_ZN7simgrid3s4u7Mailbox7by_nameERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@PLT
.LEHE5:
	movq	%rax, -160(%rbp)
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-168(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	leaq	-168(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	leaq	-168(%rbp), %rdx
	leaq	-112(%rbp), %rax
	leaq	.LC13(%rip), %rsi
	movq	%rax, %rdi
.LEHB6:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@PLT
.LEHE6:
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
.LEHB7:
	call	_ZN7simgrid3s4u7Mailbox7by_nameERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@PLT
.LEHE7:
	movq	%rax, -152(%rbp)
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-168(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	leaq	-185(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	leaq	-185(%rbp), %rdx
	leaq	-144(%rbp), %rax
	leaq	.LC14(%rip), %rsi
	movq	%rax, %rdi
.LEHB8:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@PLT
.LEHE8:
	leaq	-144(%rbp), %rax
	movq	%rax, %rdi
.LEHB9:
	call	_ZN7simgrid3s4u4Host7by_nameERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@PLT
.LEHE9:
	movq	%rax, %rbx
	leaq	-168(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	leaq	-168(%rbp), %rdx
	leaq	-112(%rbp), %rax
	leaq	.LC15(%rip), %rsi
	movq	%rax, %rdi
.LEHB10:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@PLT
.LEHE10:
	leaq	-176(%rbp), %rax
	movq	-152(%rbp), %rcx
	movq	-160(%rbp), %rdx
	leaq	-112(%rbp), %rsi
	movq	%rcx, %r9
	movq	%rdx, %r8
	leaq	_ZL6pingerPN7simgrid3s4u7MailboxES2_(%rip), %rcx
	movq	%rbx, %rdx
	movq	%rax, %rdi
.LEHB11:
	call	_ZN7simgrid3s4u5Actor6createIPFvPNS0_7MailboxES4_EJS4_S4_EvEEN5boost13intrusive_ptrIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostET_DpT0_
.LEHE11:
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost13intrusive_ptrIN7simgrid3s4u5ActorEED1Ev
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-168(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	leaq	-144(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-185(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	leaq	-185(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	leaq	-185(%rbp), %rdx
	leaq	-144(%rbp), %rax
	leaq	.LC16(%rip), %rsi
	movq	%rax, %rdi
.LEHB12:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@PLT
.LEHE12:
	leaq	-144(%rbp), %rax
	movq	%rax, %rdi
.LEHB13:
	call	_ZN7simgrid3s4u4Host7by_nameERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@PLT
.LEHE13:
	movq	%rax, %rbx
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	leaq	-176(%rbp), %rdx
	leaq	-112(%rbp), %rax
	leaq	.LC17(%rip), %rsi
	movq	%rax, %rdi
.LEHB14:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@PLT
.LEHE14:
	leaq	-168(%rbp), %rax
	movq	-160(%rbp), %rcx
	movq	-152(%rbp), %rdx
	leaq	-112(%rbp), %rsi
	movq	%rcx, %r9
	movq	%rdx, %r8
	leaq	_ZL6pongerPN7simgrid3s4u7MailboxES2_(%rip), %rcx
	movq	%rbx, %rdx
	movq	%rax, %rdi
.LEHB15:
	call	_ZN7simgrid3s4u5Actor6createIPFvPNS0_7MailboxES4_EJS4_S4_EvEEN5boost13intrusive_ptrIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostET_DpT0_
.LEHE15:
	leaq	-168(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost13intrusive_ptrIN7simgrid3s4u5ActorEED1Ev
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	leaq	-144(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-185(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	leaq	-184(%rbp), %rax
	movq	%rax, %rdi
.LEHB16:
	call	_ZN7simgrid3s4u6Engine3runEv@PLT
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	40(%rax), %eax
	testl	%eax, %eax
	jne	.L54
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	$4, %esi
	movq	%rax, %rdi
	call	_xbt_log_cat_init@PLT
	testl	%eax, %eax
	je	.L55
.L54:
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movl	44(%rax), %eax
	cmpl	$4, %eax
	jg	.L55
	movl	$1, %eax
	jmp	.L56
.L55:
	movl	$0, %eax
.L56:
	testb	%al, %al
	je	.L57
	movq	_ZL30_simgrid_log_category__default(%rip), %rax
	movq	%rax, -112(%rbp)
	movl	$4, -104(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, -96(%rbp)
	leaq	_ZZ4mainE8__func__(%rip), %rax
	movq	%rax, -88(%rbp)
	movl	$61, -80(%rbp)
	call	_ZN7simgrid3s4u6Engine9get_clockEv@PLT
	leaq	-112(%rbp), %rax
	leaq	.LC18(%rip), %rsi
	movq	%rax, %rdi
	movl	$1, %eax
	call	_xbt_log_event_log@PLT
.LEHE16:
.L57:
	movl	$0, %ebx
	leaq	-184(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7simgrid3s4u6EngineD1Ev@PLT
	movl	%ebx, %eax
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L74
	jmp	.L90
.L77:
	movq	%rax, %rbx
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L60
.L76:
	movq	%rax, %rbx
.L60:
	leaq	-168(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	jmp	.L61
.L79:
	movq	%rax, %rbx
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L63
.L78:
	movq	%rax, %rbx
.L63:
	leaq	-168(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	jmp	.L61
.L81:
	movq	%rax, %rbx
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L65
.L80:
	movq	%rax, %rbx
.L65:
	leaq	-168(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	jmp	.L61
.L85:
	movq	%rax, %rbx
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L67
.L84:
	movq	%rax, %rbx
.L67:
	leaq	-168(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	jmp	.L68
.L83:
	movq	%rax, %rbx
.L68:
	leaq	-144(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L69
.L82:
	movq	%rax, %rbx
.L69:
	leaq	-185(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	jmp	.L61
.L89:
	movq	%rax, %rbx
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L71
.L88:
	movq	%rax, %rbx
.L71:
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	jmp	.L72
.L87:
	movq	%rax, %rbx
.L72:
	leaq	-144(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L73
.L86:
	movq	%rax, %rbx
.L73:
	leaq	-185(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	jmp	.L61
.L75:
	movq	%rax, %rbx
.L61:
	leaq	-184(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7simgrid3s4u6EngineD1Ev@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB17:
	call	_Unwind_Resume@PLT
.LEHE17:
.L90:
	call	__stack_chk_fail@PLT
.L74:
	addq	$200, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6562:
	.section	.gcc_except_table,"a",@progbits
.LLSDA6562:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE6562-.LLSDACSB6562
.LLSDACSB6562:
	.uleb128 .LEHB0-.LFB6562
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB6562
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L75-.LFB6562
	.uleb128 0
	.uleb128 .LEHB2-.LFB6562
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L76-.LFB6562
	.uleb128 0
	.uleb128 .LEHB3-.LFB6562
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L77-.LFB6562
	.uleb128 0
	.uleb128 .LEHB4-.LFB6562
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L78-.LFB6562
	.uleb128 0
	.uleb128 .LEHB5-.LFB6562
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L79-.LFB6562
	.uleb128 0
	.uleb128 .LEHB6-.LFB6562
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L80-.LFB6562
	.uleb128 0
	.uleb128 .LEHB7-.LFB6562
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L81-.LFB6562
	.uleb128 0
	.uleb128 .LEHB8-.LFB6562
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L82-.LFB6562
	.uleb128 0
	.uleb128 .LEHB9-.LFB6562
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L83-.LFB6562
	.uleb128 0
	.uleb128 .LEHB10-.LFB6562
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L84-.LFB6562
	.uleb128 0
	.uleb128 .LEHB11-.LFB6562
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L85-.LFB6562
	.uleb128 0
	.uleb128 .LEHB12-.LFB6562
	.uleb128 .LEHE12-.LEHB12
	.uleb128 .L86-.LFB6562
	.uleb128 0
	.uleb128 .LEHB13-.LFB6562
	.uleb128 .LEHE13-.LEHB13
	.uleb128 .L87-.LFB6562
	.uleb128 0
	.uleb128 .LEHB14-.LFB6562
	.uleb128 .LEHE14-.LEHB14
	.uleb128 .L88-.LFB6562
	.uleb128 0
	.uleb128 .LEHB15-.LFB6562
	.uleb128 .LEHE15-.LEHB15
	.uleb128 .L89-.LFB6562
	.uleb128 0
	.uleb128 .LEHB16-.LFB6562
	.uleb128 .LEHE16-.LEHB16
	.uleb128 .L75-.LFB6562
	.uleb128 0
	.uleb128 .LEHB17-.LFB6562
	.uleb128 .LEHE17-.LEHB17
	.uleb128 0
	.uleb128 0
.LLSDACSE6562:
	.text
	.size	main, .-main
	.section	.text._ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeD2Ev,"axG",@progbits,_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeD5Ev,comdat
	.align 2
	.weak	_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeD2Ev
	.type	_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeD2Ev, @function
_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeD2Ev:
.LFB7060:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7060:
	.size	_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeD2Ev, .-_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeD2Ev
	.weak	_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeD1Ev
	.set	_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeD1Ev,_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeD2Ev
	.section	.text._ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvED2Ev,"axG",@progbits,_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvED5Ev,comdat
	.align 2
	.weak	_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvED2Ev
	.type	_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvED2Ev, @function
_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvED2Ev:
.LFB7063:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvED2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7063:
	.size	_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvED2Ev, .-_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvED2Ev
	.weak	_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvED1Ev
	.set	_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvED1Ev,_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvED2Ev
	.section	.text._ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_EC2ERKSB_,"axG",@progbits,_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_EC5ERKSB_,comdat
	.align 2
	.weak	_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_EC2ERKSB_
	.type	_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_EC2ERKSB_, @function
_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_EC2ERKSB_:
.LFB7065:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7065
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB18:
	call	_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeC2ERKSF_
.LEHE18:
	movq	-24(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-24(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rdi
.LEHB19:
	call	_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvEC1Ev
.LEHE19:
	jmp	.L96
.L95:
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeD2Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB20:
	call	_Unwind_Resume@PLT
.LEHE20:
.L96:
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7065:
	.section	.gcc_except_table
.LLSDA7065:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7065-.LLSDACSB7065
.LLSDACSB7065:
	.uleb128 .LEHB18-.LFB7065
	.uleb128 .LEHE18-.LEHB18
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB19-.LFB7065
	.uleb128 .LEHE19-.LEHB19
	.uleb128 .L95-.LFB7065
	.uleb128 0
	.uleb128 .LEHB20-.LFB7065
	.uleb128 .LEHE20-.LEHB20
	.uleb128 0
	.uleb128 0
.LLSDACSE7065:
	.section	.text._ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_EC2ERKSB_,"axG",@progbits,_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_EC5ERKSB_,comdat
	.size	_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_EC2ERKSB_, .-_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_EC2ERKSB_
	.weak	_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_EC1ERKSB_
	.set	_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_EC1ERKSB_,_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_EC2ERKSB_
	.section	.text._ZSt4moveIRPFvPN7simgrid3s4u7MailboxES3_EEONSt16remove_referenceIT_E4typeEOS8_,"axG",@progbits,_ZSt4moveIRPFvPN7simgrid3s4u7MailboxES3_EEONSt16remove_referenceIT_E4typeEOS8_,comdat
	.weak	_ZSt4moveIRPFvPN7simgrid3s4u7MailboxES3_EEONSt16remove_referenceIT_E4typeEOS8_
	.type	_ZSt4moveIRPFvPN7simgrid3s4u7MailboxES3_EEONSt16remove_referenceIT_E4typeEOS8_, @function
_ZSt4moveIRPFvPN7simgrid3s4u7MailboxES3_EEONSt16remove_referenceIT_E4typeEOS8_:
.LFB7126:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7126:
	.size	_ZSt4moveIRPFvPN7simgrid3s4u7MailboxES3_EEONSt16remove_referenceIT_E4typeEOS8_, .-_ZSt4moveIRPFvPN7simgrid3s4u7MailboxES3_EEONSt16remove_referenceIT_E4typeEOS8_
	.section	.text._ZSt4moveIRPN7simgrid3s4u7MailboxEEONSt16remove_referenceIT_E4typeEOS6_,"axG",@progbits,_ZSt4moveIRPN7simgrid3s4u7MailboxEEONSt16remove_referenceIT_E4typeEOS6_,comdat
	.weak	_ZSt4moveIRPN7simgrid3s4u7MailboxEEONSt16remove_referenceIT_E4typeEOS6_
	.type	_ZSt4moveIRPN7simgrid3s4u7MailboxEEONSt16remove_referenceIT_E4typeEOS6_, @function
_ZSt4moveIRPN7simgrid3s4u7MailboxEEONSt16remove_referenceIT_E4typeEOS6_:
.LFB7127:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7127:
	.size	_ZSt4moveIRPN7simgrid3s4u7MailboxEEONSt16remove_referenceIT_E4typeEOS6_, .-_ZSt4moveIRPN7simgrid3s4u7MailboxEEONSt16remove_referenceIT_E4typeEOS6_
	.section	.text._ZN7simgrid3s4u5Actor6createIPFvPNS0_7MailboxES4_EJS4_S4_EvEEN5boost13intrusive_ptrIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostET_DpT0_,"axG",@progbits,_ZN7simgrid3s4u5Actor6createIPFvPNS0_7MailboxES4_EJS4_S4_EvEEN5boost13intrusive_ptrIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostET_DpT0_,comdat
	.weak	_ZN7simgrid3s4u5Actor6createIPFvPNS0_7MailboxES4_EJS4_S4_EvEEN5boost13intrusive_ptrIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostET_DpT0_
	.type	_ZN7simgrid3s4u5Actor6createIPFvPNS0_7MailboxES4_EJS4_S4_EvEEN5boost13intrusive_ptrIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostET_DpT0_, @function
_ZN7simgrid3s4u5Actor6createIPFvPNS0_7MailboxES4_EJS4_S4_EvEEN5boost13intrusive_ptrIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostET_DpT0_:
.LFB7125:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$80, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	%rcx, -80(%rbp)
	movq	%r8, -88(%rbp)
	movq	%r9, -96(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt4moveIRPN7simgrid3s4u7MailboxEEONSt16remove_referenceIT_E4typeEOS6_
	movq	%rax, %r12
	leaq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt4moveIRPN7simgrid3s4u7MailboxEEONSt16remove_referenceIT_E4typeEOS6_
	movq	%rax, %rbx
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt4moveIRPFvPN7simgrid3s4u7MailboxES3_EEONSt16remove_referenceIT_E4typeEOS8_
	movq	%rax, %rsi
	leaq	-48(%rbp), %rax
	movq	%r12, %rcx
	movq	%rbx, %rdx
	movq	%rax, %rdi
	call	_ZSt4bindIPFvPN7simgrid3s4u7MailboxES3_EJS3_S3_EENSt12_Bind_helperIXsrSt5__or_IJSt11is_integralINSt5decayIT_E4typeEESt7is_enumISC_EEE5valueESA_JDpT0_EE4typeEOSA_DpOSH_
	movq	-56(%rbp), %rax
	leaq	-48(%rbp), %rcx
	movq	-72(%rbp), %rdx
	movq	-64(%rbp), %rsi
	movq	%rax, %rdi
	call	_ZN7simgrid3s4u5Actor6createISt5_BindIFPFvPNS0_7MailboxES5_ES5_S5_EEEEN5boost13intrusive_ptrIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostET_
	movq	-56(%rbp), %rax
	movq	-24(%rbp), %rbx
	xorq	%fs:40, %rbx
	je	.L103
	call	__stack_chk_fail@PLT
.L103:
	addq	$80, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7125:
	.size	_ZN7simgrid3s4u5Actor6createIPFvPNS0_7MailboxES4_EJS4_S4_EvEEN5boost13intrusive_ptrIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostET_DpT0_, .-_ZN7simgrid3s4u5Actor6createIPFvPNS0_7MailboxES4_EJS4_S4_EvEEN5boost13intrusive_ptrIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostET_DpT0_
	.section	.text._ZN5boost13intrusive_ptrIN7simgrid3s4u5ActorEED2Ev,"axG",@progbits,_ZN5boost13intrusive_ptrIN7simgrid3s4u5ActorEED5Ev,comdat
	.align 2
	.weak	_ZN5boost13intrusive_ptrIN7simgrid3s4u5ActorEED2Ev
	.type	_ZN5boost13intrusive_ptrIN7simgrid3s4u5ActorEED2Ev, @function
_ZN5boost13intrusive_ptrIN7simgrid3s4u5ActorEED2Ev:
.LFB7131:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7131
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L106
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZN7simgrid3s4u21intrusive_ptr_releaseEPNS0_5ActorE@PLT
.L106:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7131:
	.section	.gcc_except_table
.LLSDA7131:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7131-.LLSDACSB7131
.LLSDACSB7131:
.LLSDACSE7131:
	.section	.text._ZN5boost13intrusive_ptrIN7simgrid3s4u5ActorEED2Ev,"axG",@progbits,_ZN5boost13intrusive_ptrIN7simgrid3s4u5ActorEED5Ev,comdat
	.size	_ZN5boost13intrusive_ptrIN7simgrid3s4u5ActorEED2Ev, .-_ZN5boost13intrusive_ptrIN7simgrid3s4u5ActorEED2Ev
	.weak	_ZN5boost13intrusive_ptrIN7simgrid3s4u5ActorEED1Ev
	.set	_ZN5boost13intrusive_ptrIN7simgrid3s4u5ActorEED1Ev,_ZN5boost13intrusive_ptrIN7simgrid3s4u5ActorEED2Ev
	.section	.text._ZNSt6vectorIPFvPvESaIS2_EEC2Ev,"axG",@progbits,_ZNSt6vectorIPFvPvESaIS2_EEC5Ev,comdat
	.align 2
	.weak	_ZNSt6vectorIPFvPvESaIS2_EEC2Ev
	.type	_ZNSt6vectorIPFvPvESaIS2_EEC2Ev, @function
_ZNSt6vectorIPFvPvESaIS2_EEC2Ev:
.LFB7180:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7180
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPFvPvESaIS2_EEC2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7180:
	.section	.gcc_except_table
.LLSDA7180:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7180-.LLSDACSB7180
.LLSDACSB7180:
.LLSDACSE7180:
	.section	.text._ZNSt6vectorIPFvPvESaIS2_EEC2Ev,"axG",@progbits,_ZNSt6vectorIPFvPvESaIS2_EEC5Ev,comdat
	.size	_ZNSt6vectorIPFvPvESaIS2_EEC2Ev, .-_ZNSt6vectorIPFvPvESaIS2_EEC2Ev
	.weak	_ZNSt6vectorIPFvPvESaIS2_EEC1Ev
	.set	_ZNSt6vectorIPFvPvESaIS2_EEC1Ev,_ZNSt6vectorIPFvPvESaIS2_EEC2Ev
	.section	.text._ZN5boost9intrusive14pointer_traitsIPNS0_9list_nodeIPvEEE10pointer_toERS4_,"axG",@progbits,_ZN5boost9intrusive14pointer_traitsIPNS0_9list_nodeIPvEEE10pointer_toERS4_,comdat
	.weak	_ZN5boost9intrusive14pointer_traitsIPNS0_9list_nodeIPvEEE10pointer_toERS4_
	.type	_ZN5boost9intrusive14pointer_traitsIPNS0_9list_nodeIPvEEE10pointer_toERS4_, @function
_ZN5boost9intrusive14pointer_traitsIPNS0_9list_nodeIPvEEE10pointer_toERS4_:
.LFB7369:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -56(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-56(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	$0, -16(%rbp)
	movq	-24(%rbp), %rax
	nop
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L113
	call	__stack_chk_fail@PLT
.L113:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7369:
	.size	_ZN5boost9intrusive14pointer_traitsIPNS0_9list_nodeIPvEEE10pointer_toERS4_, .-_ZN5boost9intrusive14pointer_traitsIPNS0_9list_nodeIPvEEE10pointer_toERS4_
	.section	.text._ZN5boost9intrusive14pointer_traitsIPKNS0_9list_nodeIPvEEE10pointer_toERS5_,"axG",@progbits,_ZN5boost9intrusive14pointer_traitsIPKNS0_9list_nodeIPvEEE10pointer_toERS5_,comdat
	.weak	_ZN5boost9intrusive14pointer_traitsIPKNS0_9list_nodeIPvEEE10pointer_toERS5_
	.type	_ZN5boost9intrusive14pointer_traitsIPKNS0_9list_nodeIPvEEE10pointer_toERS5_, @function
_ZN5boost9intrusive14pointer_traitsIPKNS0_9list_nodeIPvEEE10pointer_toERS5_:
.LFB7370:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -56(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-56(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	$0, -16(%rbp)
	movq	-24(%rbp), %rax
	nop
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L119
	call	__stack_chk_fail@PLT
.L119:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7370:
	.size	_ZN5boost9intrusive14pointer_traitsIPKNS0_9list_nodeIPvEEE10pointer_toERS5_, .-_ZN5boost9intrusive14pointer_traitsIPKNS0_9list_nodeIPvEEE10pointer_toERS5_
	.section	.text._ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeC2ERKSF_,"axG",@progbits,_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeC5ERKSF_,comdat
	.align 2
	.weak	_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeC2ERKSF_
	.type	_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeC2ERKSF_, @function
_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeC2ERKSF_:
.LFB7372:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost4heap6detail9heap_baseISt4pairIdPN7simgrid5simix5TimerEENS4_3xbt14HeapComparatorIS8_EELb1EmLb0EEC2ERKSB_
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7372:
	.size	_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeC2ERKSF_, .-_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeC2ERKSF_
	.weak	_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeC1ERKSF_
	.set	_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeC1ERKSF_,_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeC2ERKSF_
	.section	.text._ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED2Ev,"axG",@progbits,_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED5Ev,comdat
	.align 2
	.weak	_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED2Ev
	.type	_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED2Ev, @function
_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED2Ev:
.LFB7375:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7375:
	.size	_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED2Ev, .-_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED2Ev
	.weak	_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED1Ev
	.set	_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED1Ev,_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED2Ev
	.section	.text._ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvEC2Ev,"axG",@progbits,_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvEC5Ev,comdat
	.align 2
	.weak	_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvEC2Ev
	.type	_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvEC2Ev, @function
_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvEC2Ev:
.LFB7378:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvEC2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7378:
	.size	_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvEC2Ev, .-_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvEC2Ev
	.weak	_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvEC1Ev
	.set	_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvEC1Ev,_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvEC2Ev
	.section	.text._ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvED2Ev,"axG",@progbits,_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvED5Ev,comdat
	.align 2
	.weak	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvED2Ev
	.type	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvED2Ev, @function
_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvED2Ev:
.LFB7381:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7381
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE5clearEv
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE13get_root_nodeEv
	movq	%rax, -16(%rbp)
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE4initERKPNS0_9list_nodeIS3_EE
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L124
	call	__stack_chk_fail@PLT
.L124:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7381:
	.section	.gcc_except_table
.LLSDA7381:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7381-.LLSDACSB7381
.LLSDACSB7381:
.LLSDACSE7381:
	.section	.text._ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvED2Ev,"axG",@progbits,_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvED5Ev,comdat
	.size	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvED2Ev, .-_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvED2Ev
	.weak	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvED1Ev
	.set	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvED1Ev,_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvED2Ev
	.section	.text._ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE6uniqueERKPKNS0_9list_nodeIS3_EE,"axG",@progbits,_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE6uniqueERKPKNS0_9list_nodeIS3_EE,comdat
	.weak	_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE6uniqueERKPKNS0_9list_nodeIS3_EE
	.type	_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE6uniqueERKPKNS0_9list_nodeIS3_EE, @function
_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE6uniqueERKPKNS0_9list_nodeIS3_EE:
.LFB7422:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive16list_node_traitsIPvE8get_nextERKPKNS0_9list_nodeIS2_EE
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L126
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, -8(%rbp)
	jne	.L127
.L126:
	movl	$1, %eax
	jmp	.L128
.L127:
	movl	$0, %eax
.L128:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7422:
	.size	_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE6uniqueERKPKNS0_9list_nodeIS3_EE, .-_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE6uniqueERKPKNS0_9list_nodeIS3_EE
	.section	.text._ZSt7forwardIPFvPN7simgrid3s4u7MailboxES3_EEOT_RNSt16remove_referenceIS6_E4typeE,"axG",@progbits,_ZSt7forwardIPFvPN7simgrid3s4u7MailboxES3_EEOT_RNSt16remove_referenceIS6_E4typeE,comdat
	.weak	_ZSt7forwardIPFvPN7simgrid3s4u7MailboxES3_EEOT_RNSt16remove_referenceIS6_E4typeE
	.type	_ZSt7forwardIPFvPN7simgrid3s4u7MailboxES3_EEOT_RNSt16remove_referenceIS6_E4typeE, @function
_ZSt7forwardIPFvPN7simgrid3s4u7MailboxES3_EEOT_RNSt16remove_referenceIS6_E4typeE:
.LFB7433:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7433:
	.size	_ZSt7forwardIPFvPN7simgrid3s4u7MailboxES3_EEOT_RNSt16remove_referenceIS6_E4typeE, .-_ZSt7forwardIPFvPN7simgrid3s4u7MailboxES3_EEOT_RNSt16remove_referenceIS6_E4typeE
	.section	.text._ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE,"axG",@progbits,_ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE,comdat
	.weak	_ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE
	.type	_ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE, @function
_ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE:
.LFB7434:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7434:
	.size	_ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE, .-_ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE
	.section	.text._ZSt4bindIPFvPN7simgrid3s4u7MailboxES3_EJS3_S3_EENSt12_Bind_helperIXsrSt5__or_IJSt11is_integralINSt5decayIT_E4typeEESt7is_enumISC_EEE5valueESA_JDpT0_EE4typeEOSA_DpOSH_,"axG",@progbits,_ZSt4bindIPFvPN7simgrid3s4u7MailboxES3_EJS3_S3_EENSt12_Bind_helperIXsrSt5__or_IJSt11is_integralINSt5decayIT_E4typeEESt7is_enumISC_EEE5valueESA_JDpT0_EE4typeEOSA_DpOSH_,comdat
	.weak	_ZSt4bindIPFvPN7simgrid3s4u7MailboxES3_EJS3_S3_EENSt12_Bind_helperIXsrSt5__or_IJSt11is_integralINSt5decayIT_E4typeEESt7is_enumISC_EEE5valueESA_JDpT0_EE4typeEOSA_DpOSH_
	.type	_ZSt4bindIPFvPN7simgrid3s4u7MailboxES3_EJS3_S3_EENSt12_Bind_helperIXsrSt5__or_IJSt11is_integralINSt5decayIT_E4typeEESt7is_enumISC_EEE5valueESA_JDpT0_EE4typeEOSA_DpOSH_, @function
_ZSt4bindIPFvPN7simgrid3s4u7MailboxES3_EJS3_S3_EENSt12_Bind_helperIXsrSt5__or_IJSt11is_integralINSt5decayIT_E4typeEESt7is_enumISC_EEE5valueESA_JDpT0_EE4typeEOSA_DpOSH_:
.LFB7432:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE
	movq	%rax, %r12
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE
	movq	%rax, %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIPFvPN7simgrid3s4u7MailboxES3_EEOT_RNSt16remove_referenceIS6_E4typeE
	movq	%rax, %rsi
	movq	-24(%rbp), %rax
	movq	%r12, %rcx
	movq	%rbx, %rdx
	movq	%rax, %rdi
	call	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC1IJS3_S3_EEEOS5_DpOT_
	movq	-24(%rbp), %rax
	addq	$32, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7432:
	.size	_ZSt4bindIPFvPN7simgrid3s4u7MailboxES3_EJS3_S3_EENSt12_Bind_helperIXsrSt5__or_IJSt11is_integralINSt5decayIT_E4typeEESt7is_enumISC_EEE5valueESA_JDpT0_EE4typeEOSA_DpOSH_, .-_ZSt4bindIPFvPN7simgrid3s4u7MailboxES3_EJS3_S3_EENSt12_Bind_helperIXsrSt5__or_IJSt11is_integralINSt5decayIT_E4typeEESt7is_enumISC_EEE5valueESA_JDpT0_EE4typeEOSA_DpOSH_
	.section	.text._ZSt4moveIRSt5tupleIJPN7simgrid3s4u7MailboxES4_EEEONSt16remove_referenceIT_E4typeEOS8_,"axG",@progbits,_ZSt4moveIRSt5tupleIJPN7simgrid3s4u7MailboxES4_EEEONSt16remove_referenceIT_E4typeEOS8_,comdat
	.weak	_ZSt4moveIRSt5tupleIJPN7simgrid3s4u7MailboxES4_EEEONSt16remove_referenceIT_E4typeEOS8_
	.type	_ZSt4moveIRSt5tupleIJPN7simgrid3s4u7MailboxES4_EEEONSt16remove_referenceIT_E4typeEOS8_, @function
_ZSt4moveIRSt5tupleIJPN7simgrid3s4u7MailboxES4_EEEONSt16remove_referenceIT_E4typeEOS8_:
.LFB7438:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7438:
	.size	_ZSt4moveIRSt5tupleIJPN7simgrid3s4u7MailboxES4_EEEONSt16remove_referenceIT_E4typeEOS8_, .-_ZSt4moveIRSt5tupleIJPN7simgrid3s4u7MailboxES4_EEEONSt16remove_referenceIT_E4typeEOS8_
	.section	.text._ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEE7_M_headERS4_,"axG",@progbits,_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEE7_M_headERS4_,comdat
	.weak	_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEE7_M_headERS4_
	.type	_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEE7_M_headERS4_, @function
_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEE7_M_headERS4_:
.LFB7440:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EE7_M_headERS4_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7440:
	.size	_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEE7_M_headERS4_, .-_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEE7_M_headERS4_
	.section	.text._ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EE7_M_headERS4_,"axG",@progbits,_ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EE7_M_headERS4_,comdat
	.weak	_ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EE7_M_headERS4_
	.type	_ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EE7_M_headERS4_, @function
_ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EE7_M_headERS4_:
.LFB7441:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7441:
	.size	_ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EE7_M_headERS4_, .-_ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EE7_M_headERS4_
	.section	.text._ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC2EOS4_,"axG",@progbits,_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC5EOS4_,comdat
	.align 2
	.weak	_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC2EOS4_
	.type	_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC2EOS4_, @function
_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC2EOS4_:
.LFB7442:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEE7_M_headERS4_
	movq	%rax, %rdi
	call	_ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EEC2IS3_EEOT_
	nop
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7442:
	.size	_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC2EOS4_, .-_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC2EOS4_
	.weak	_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC1EOS4_
	.set	_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC1EOS4_,_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC2EOS4_
	.section	.text._ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC2EOS4_,"axG",@progbits,_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC5EOS4_,comdat
	.align 2
	.weak	_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC2EOS4_
	.type	_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC2EOS4_, @function
_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC2EOS4_:
.LFB7445:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC2EOS4_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7445:
	.size	_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC2EOS4_, .-_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC2EOS4_
	.weak	_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC1EOS4_
	.set	_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC1EOS4_,_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC2EOS4_
	.section	.text._ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC2EOS7_,"axG",@progbits,_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC5EOS7_,comdat
	.align 2
	.weak	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC2EOS7_
	.type	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC2EOS7_, @function
_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC2EOS7_:
.LFB7447:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt4moveIRPFvPN7simgrid3s4u7MailboxES3_EEONSt16remove_referenceIT_E4typeEOS8_
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rax
	leaq	8(%rax), %rbx
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	_ZSt4moveIRSt5tupleIJPN7simgrid3s4u7MailboxES4_EEEONSt16remove_referenceIT_E4typeEOS8_
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC1EOS4_
	nop
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7447:
	.size	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC2EOS7_, .-_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC2EOS7_
	.weak	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC1EOS7_
	.set	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC1EOS7_,_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC2EOS7_
	.section	.text._ZSt4moveIRSt5_BindIFPFvPN7simgrid3s4u7MailboxES4_ES4_S4_EEEONSt16remove_referenceIT_E4typeEOSB_,"axG",@progbits,_ZSt4moveIRSt5_BindIFPFvPN7simgrid3s4u7MailboxES4_ES4_S4_EEEONSt16remove_referenceIT_E4typeEOSB_,comdat
	.weak	_ZSt4moveIRSt5_BindIFPFvPN7simgrid3s4u7MailboxES4_ES4_S4_EEEONSt16remove_referenceIT_E4typeEOSB_
	.type	_ZSt4moveIRSt5_BindIFPFvPN7simgrid3s4u7MailboxES4_ES4_S4_EEEONSt16remove_referenceIT_E4typeEOSB_, @function
_ZSt4moveIRSt5_BindIFPFvPN7simgrid3s4u7MailboxES4_ES4_S4_EEEONSt16remove_referenceIT_E4typeEOSB_:
.LFB7450:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7450:
	.size	_ZSt4moveIRSt5_BindIFPFvPN7simgrid3s4u7MailboxES4_ES4_S4_EEEONSt16remove_referenceIT_E4typeEOSB_, .-_ZSt4moveIRSt5_BindIFPFvPN7simgrid3s4u7MailboxES4_ES4_S4_EEEONSt16remove_referenceIT_E4typeEOSB_
	.section	.text._ZNSt8functionIFvvEED2Ev,"axG",@progbits,_ZNSt8functionIFvvEED5Ev,comdat
	.align 2
	.weak	_ZNSt8functionIFvvEED2Ev
	.type	_ZNSt8functionIFvvEED2Ev, @function
_ZNSt8functionIFvvEED2Ev:
.LFB7452:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt14_Function_baseD2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7452:
	.size	_ZNSt8functionIFvvEED2Ev, .-_ZNSt8functionIFvvEED2Ev
	.weak	_ZNSt8functionIFvvEED1Ev
	.set	_ZNSt8functionIFvvEED1Ev,_ZNSt8functionIFvvEED2Ev
	.section	.text._ZN7simgrid3s4u5Actor6createISt5_BindIFPFvPNS0_7MailboxES5_ES5_S5_EEEEN5boost13intrusive_ptrIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostET_,"axG",@progbits,_ZN7simgrid3s4u5Actor6createISt5_BindIFPFvPNS0_7MailboxES5_ES5_S5_EEEEN5boost13intrusive_ptrIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostET_,comdat
	.weak	_ZN7simgrid3s4u5Actor6createISt5_BindIFPFvPNS0_7MailboxES5_ES5_S5_EEEEN5boost13intrusive_ptrIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostET_
	.type	_ZN7simgrid3s4u5Actor6createISt5_BindIFPFvPNS0_7MailboxES5_ES5_S5_EEEEN5boost13intrusive_ptrIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostET_, @function
_ZN7simgrid3s4u5Actor6createISt5_BindIFPFvPNS0_7MailboxES5_ES5_S5_EEEEN5boost13intrusive_ptrIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostET_:
.LFB7449:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7449
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$120, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -104(%rbp)
	movq	%rsi, -112(%rbp)
	movq	%rdx, -120(%rbp)
	movq	%rcx, -128(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-128(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt4moveIRSt5_BindIFPFvPN7simgrid3s4u7MailboxES4_ES4_S4_EEEONSt16remove_referenceIT_E4typeEOSB_
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC1EOS7_
	leaq	-96(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB21:
	call	_ZNSt8functionIFvvEEC1ISt5_BindIFPFvPN7simgrid3s4u7MailboxES7_ES7_S7_EEvvEET_
.LEHE21:
	movq	-104(%rbp), %rax
	leaq	-64(%rbp), %rcx
	movq	-120(%rbp), %rdx
	movq	-112(%rbp), %rsi
	movq	%rax, %rdi
.LEHB22:
	call	_ZN7simgrid3s4u5Actor6createERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostERKSt8functionIFvvEE@PLT
.LEHE22:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8functionIFvvEED1Ev
	movq	-104(%rbp), %rax
	movq	-24(%rbp), %rbx
	xorq	%fs:40, %rbx
	je	.L151
	jmp	.L153
.L152:
	movq	%rax, %rbx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8functionIFvvEED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB23:
	call	_Unwind_Resume@PLT
.LEHE23:
.L153:
	call	__stack_chk_fail@PLT
.L151:
	addq	$120, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7449:
	.section	.gcc_except_table
.LLSDA7449:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7449-.LLSDACSB7449
.LLSDACSB7449:
	.uleb128 .LEHB21-.LFB7449
	.uleb128 .LEHE21-.LEHB21
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB22-.LFB7449
	.uleb128 .LEHE22-.LEHB22
	.uleb128 .L152-.LFB7449
	.uleb128 0
	.uleb128 .LEHB23-.LFB7449
	.uleb128 .LEHE23-.LEHB23
	.uleb128 0
	.uleb128 0
.LLSDACSE7449:
	.section	.text._ZN7simgrid3s4u5Actor6createISt5_BindIFPFvPNS0_7MailboxES5_ES5_S5_EEEEN5boost13intrusive_ptrIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostET_,"axG",@progbits,_ZN7simgrid3s4u5Actor6createISt5_BindIFPFvPNS0_7MailboxES5_ES5_S5_EEEEN5boost13intrusive_ptrIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostET_,comdat
	.size	_ZN7simgrid3s4u5Actor6createISt5_BindIFPFvPNS0_7MailboxES5_ES5_S5_EEEEN5boost13intrusive_ptrIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostET_, .-_ZN7simgrid3s4u5Actor6createISt5_BindIFPFvPNS0_7MailboxES5_ES5_S5_EEEEN5boost13intrusive_ptrIS1_EERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS0_4HostET_
	.section	.text._ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implD2Ev,"axG",@progbits,_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implD5Ev,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implD2Ev
	.type	_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implD2Ev, @function
_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implD2Ev:
.LFB7477:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIPFvPvEED2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7477:
	.size	_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implD2Ev, .-_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implD2Ev
	.weak	_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implD1Ev
	.set	_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implD1Ev,_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implD2Ev
	.section	.text._ZNSt12_Vector_baseIPFvPvESaIS2_EEC2Ev,"axG",@progbits,_ZNSt12_Vector_baseIPFvPvESaIS2_EEC5Ev,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIPFvPvESaIS2_EEC2Ev
	.type	_ZNSt12_Vector_baseIPFvPvESaIS2_EEC2Ev, @function
_ZNSt12_Vector_baseIPFvPvESaIS2_EEC2Ev:
.LFB7479:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implC1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7479:
	.size	_ZNSt12_Vector_baseIPFvPvESaIS2_EEC2Ev, .-_ZNSt12_Vector_baseIPFvPvESaIS2_EEC2Ev
	.weak	_ZNSt12_Vector_baseIPFvPvESaIS2_EEC1Ev
	.set	_ZNSt12_Vector_baseIPFvPvESaIS2_EEC1Ev,_ZNSt12_Vector_baseIPFvPvESaIS2_EEC2Ev
	.section	.text._ZNSt12_Vector_baseIPFvPvESaIS2_EED2Ev,"axG",@progbits,_ZNSt12_Vector_baseIPFvPvESaIS2_EED5Ev,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIPFvPvESaIS2_EED2Ev
	.type	_ZNSt12_Vector_baseIPFvPvESaIS2_EED2Ev, @function
_ZNSt12_Vector_baseIPFvPvESaIS2_EED2Ev:
.LFB7482:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7482
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	sarq	$3, %rax
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	(%rax), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPFvPvESaIS2_EE13_M_deallocateEPS2_m
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implD1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7482:
	.section	.gcc_except_table
.LLSDA7482:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7482-.LLSDACSB7482
.LLSDACSB7482:
.LLSDACSE7482:
	.section	.text._ZNSt12_Vector_baseIPFvPvESaIS2_EED2Ev,"axG",@progbits,_ZNSt12_Vector_baseIPFvPvESaIS2_EED5Ev,comdat
	.size	_ZNSt12_Vector_baseIPFvPvESaIS2_EED2Ev, .-_ZNSt12_Vector_baseIPFvPvESaIS2_EED2Ev
	.weak	_ZNSt12_Vector_baseIPFvPvESaIS2_EED1Ev
	.set	_ZNSt12_Vector_baseIPFvPvESaIS2_EED1Ev,_ZNSt12_Vector_baseIPFvPvESaIS2_EED2Ev
	.section	.text._ZNSt9_Any_data9_M_accessIPKSt9type_infoEERT_v,"axG",@progbits,_ZNSt9_Any_data9_M_accessIPKSt9type_infoEERT_v,comdat
	.align 2
	.weak	_ZNSt9_Any_data9_M_accessIPKSt9type_infoEERT_v
	.type	_ZNSt9_Any_data9_M_accessIPKSt9type_infoEERT_v, @function
_ZNSt9_Any_data9_M_accessIPKSt9type_infoEERT_v:
.LFB7578:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt9_Any_data9_M_accessEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7578:
	.size	_ZNSt9_Any_data9_M_accessIPKSt9type_infoEERT_v, .-_ZNSt9_Any_data9_M_accessIPKSt9type_infoEERT_v
	.section	.text._ZN5boost4heap6detail9heap_baseISt4pairIdPN7simgrid5simix5TimerEENS4_3xbt14HeapComparatorIS8_EELb1EmLb0EEC2ERKSB_,"axG",@progbits,_ZN5boost4heap6detail9heap_baseISt4pairIdPN7simgrid5simix5TimerEENS4_3xbt14HeapComparatorIS8_EELb1EmLb0EEC5ERKSB_,comdat
	.align 2
	.weak	_ZN5boost4heap6detail9heap_baseISt4pairIdPN7simgrid5simix5TimerEENS4_3xbt14HeapComparatorIS8_EELb1EmLb0EEC2ERKSB_
	.type	_ZN5boost4heap6detail9heap_baseISt4pairIdPN7simgrid5simix5TimerEENS4_3xbt14HeapComparatorIS8_EELb1EmLb0EEC2ERKSB_, @function
_ZN5boost4heap6detail9heap_baseISt4pairIdPN7simgrid5simix5TimerEENS4_3xbt14HeapComparatorIS8_EELb1EmLb0EEC2ERKSB_:
.LFB7621:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost4heap6detail11size_holderILb1EmEC2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7621:
	.size	_ZN5boost4heap6detail9heap_baseISt4pairIdPN7simgrid5simix5TimerEENS4_3xbt14HeapComparatorIS8_EELb1EmLb0EEC2ERKSB_, .-_ZN5boost4heap6detail9heap_baseISt4pairIdPN7simgrid5simix5TimerEENS4_3xbt14HeapComparatorIS8_EELb1EmLb0EEC2ERKSB_
	.weak	_ZN5boost4heap6detail9heap_baseISt4pairIdPN7simgrid5simix5TimerEENS4_3xbt14HeapComparatorIS8_EELb1EmLb0EEC1ERKSB_
	.set	_ZN5boost4heap6detail9heap_baseISt4pairIdPN7simgrid5simix5TimerEENS4_3xbt14HeapComparatorIS8_EELb1EmLb0EEC1ERKSB_,_ZN5boost4heap6detail9heap_baseISt4pairIdPN7simgrid5simix5TimerEENS4_3xbt14HeapComparatorIS8_EELb1EmLb0EEC2ERKSB_
	.section	.text._ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC2Ev,"axG",@progbits,_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC5Ev,comdat
	.align 2
	.weak	_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC2Ev
	.type	_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC2Ev, @function
_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC2Ev:
.LFB7624:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7624:
	.size	_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC2Ev, .-_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC2Ev
	.weak	_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC1Ev
	.set	_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC1Ev,_ZNSaIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC2Ev
	.section	.text._ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED2Ev,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED5Ev,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED2Ev
	.type	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED2Ev, @function
_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED2Ev:
.LFB7627:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7627:
	.size	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED2Ev, .-_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED2Ev
	.weak	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED1Ev
	.set	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED1Ev,_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEED2Ev
	.section	.text._ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvEC2Ev,"axG",@progbits,_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvEC5Ev,comdat
	.align 2
	.weak	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvEC2Ev
	.type	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvEC2Ev, @function
_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvEC2Ev:
.LFB7630:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-24(%rbp), %rax
	leaq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE6data_tC1ERKSC_
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE16priv_size_traitsEv
	movl	$0, %esi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive6detail11size_holderILb1EmvE8set_sizeEm
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE13get_root_nodeEv
	movq	%rax, -16(%rbp)
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE11init_headerERKPNS0_9list_nodeIS3_EE
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L163
	call	__stack_chk_fail@PLT
.L163:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7630:
	.size	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvEC2Ev, .-_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvEC2Ev
	.weak	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvEC1Ev
	.set	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvEC1Ev,_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvEC2Ev
	.section	.text._ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE5clearEv,"axG",@progbits,_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE5clearEv,comdat
	.align 2
	.weak	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE5clearEv
	.type	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE5clearEv, @function
_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE5clearEv:
.LFB7632:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-24(%rbp), %rax
	subq	$8, %rsp
	pushq	%rdx
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS0_6detail13null_disposerEEEvT_
	addq	$16, %rsp
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L165
	call	__stack_chk_fail@PLT
.L165:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7632:
	.size	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE5clearEv, .-_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE5clearEv
	.section	.text._ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE4initERKPNS0_9list_nodeIS3_EE,"axG",@progbits,_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE4initERKPNS0_9list_nodeIS3_EE,comdat
	.weak	_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE4initERKPNS0_9list_nodeIS3_EE
	.type	_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE4initERKPNS0_9list_nodeIS3_EE, @function
_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE4initERKPNS0_9list_nodeIS3_EE:
.LFB7633:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	$0, -16(%rbp)
	leaq	-16(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive16list_node_traitsIPvE8set_nextERKPNS0_9list_nodeIS2_EES8_
	leaq	-16(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive16list_node_traitsIPvE12set_previousERKPNS0_9list_nodeIS2_EES8_
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L167
	call	__stack_chk_fail@PLT
.L167:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7633:
	.size	_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE4initERKPNS0_9list_nodeIS3_EE, .-_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE4initERKPNS0_9list_nodeIS3_EE
	.section	.text._ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE13get_root_nodeEv,"axG",@progbits,_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE13get_root_nodeEv,comdat
	.align 2
	.weak	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE13get_root_nodeEv
	.type	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE13get_root_nodeEv, @function
_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE13get_root_nodeEv:
.LFB7634:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive6detail21default_header_holderINS0_16list_node_traitsIPvEEE8get_nodeEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7634:
	.size	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE13get_root_nodeEv, .-_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE13get_root_nodeEv
	.section	.text._ZN5boost9intrusive16list_node_traitsIPvE8get_nextERKPKNS0_9list_nodeIS2_EE,"axG",@progbits,_ZN5boost9intrusive16list_node_traitsIPvE8get_nextERKPKNS0_9list_nodeIS2_EE,comdat
	.weak	_ZN5boost9intrusive16list_node_traitsIPvE8get_nextERKPKNS0_9list_nodeIS2_EE
	.type	_ZN5boost9intrusive16list_node_traitsIPvE8get_nextERKPKNS0_9list_nodeIS2_EE, @function
_ZN5boost9intrusive16list_node_traitsIPvE8get_nextERKPKNS0_9list_nodeIS2_EE:
.LFB7662:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7662:
	.size	_ZN5boost9intrusive16list_node_traitsIPvE8get_nextERKPKNS0_9list_nodeIS2_EE, .-_ZN5boost9intrusive16list_node_traitsIPvE8get_nextERKPKNS0_9list_nodeIS2_EE
	.section	.text._ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC2IJS3_S3_EEEOS5_DpOT_,"axG",@progbits,_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC5IJS3_S3_EEEOS5_DpOT_,comdat
	.align 2
	.weak	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC2IJS3_S3_EEEOS5_DpOT_
	.type	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC2IJS3_S3_EEEOS5_DpOT_, @function
_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC2IJS3_S3_EEEOS5_DpOT_:
.LFB7670:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt4moveIRPFvPN7simgrid3s4u7MailboxES3_EEONSt16remove_referenceIT_E4typeEOS8_
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rax
	leaq	8(%rax), %rbx
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE
	movq	%rax, %r12
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE
	movq	%r12, %rdx
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC1IS3_S3_Lb1EEEOT_OT0_
	nop
	addq	$32, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7670:
	.size	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC2IJS3_S3_EEEOS5_DpOT_, .-_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC2IJS3_S3_EEEOS5_DpOT_
	.weak	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC1IJS3_S3_EEEOS5_DpOT_
	.set	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC1IJS3_S3_EEEOS5_DpOT_,_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC2IJS3_S3_EEEOS5_DpOT_
	.section	.text._ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EEC2IS3_EEOT_,"axG",@progbits,_ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EEC5IS3_EEOT_,comdat
	.align 2
	.weak	_ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EEC2IS3_EEOT_
	.type	_ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EEC2IS3_EEOT_, @function
_ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EEC2IS3_EEOT_:
.LFB7673:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7673:
	.size	_ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EEC2IS3_EEOT_, .-_ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EEC2IS3_EEOT_
	.weak	_ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EEC1IS3_EEOT_
	.set	_ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EEC1IS3_EEOT_,_ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EEC2IS3_EEOT_
	.section	.text._ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EE7_M_tailERS4_,"axG",@progbits,_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EE7_M_tailERS4_,comdat
	.weak	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EE7_M_tailERS4_
	.type	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EE7_M_tailERS4_, @function
_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EE7_M_tailERS4_:
.LFB7676:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7676:
	.size	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EE7_M_tailERS4_, .-_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EE7_M_tailERS4_
	.section	.text._ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EE7_M_headERS4_,"axG",@progbits,_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EE7_M_headERS4_,comdat
	.weak	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EE7_M_headERS4_
	.type	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EE7_M_headERS4_, @function
_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EE7_M_headERS4_:
.LFB7677:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	_ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EE7_M_headERS4_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7677:
	.size	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EE7_M_headERS4_, .-_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EE7_M_headERS4_
	.section	.text._ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EE7_M_headERS4_,"axG",@progbits,_ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EE7_M_headERS4_,comdat
	.weak	_ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EE7_M_headERS4_
	.type	_ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EE7_M_headERS4_, @function
_ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EE7_M_headERS4_:
.LFB7678:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7678:
	.size	_ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EE7_M_headERS4_, .-_ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EE7_M_headERS4_
	.section	.text._ZSt4moveIRSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEEONSt16remove_referenceIT_E4typeEOS8_,"axG",@progbits,_ZSt4moveIRSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEEONSt16remove_referenceIT_E4typeEOS8_,comdat
	.weak	_ZSt4moveIRSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEEONSt16remove_referenceIT_E4typeEOS8_
	.type	_ZSt4moveIRSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEEONSt16remove_referenceIT_E4typeEOS8_, @function
_ZSt4moveIRSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEEONSt16remove_referenceIT_E4typeEOS8_:
.LFB7679:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7679:
	.size	_ZSt4moveIRSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEEONSt16remove_referenceIT_E4typeEOS8_, .-_ZSt4moveIRSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEEONSt16remove_referenceIT_E4typeEOS8_
	.section	.text._ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC2EOS4_,"axG",@progbits,_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC5EOS4_,comdat
	.align 2
	.weak	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC2EOS4_
	.type	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC2EOS4_, @function
_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC2EOS4_:
.LFB7680:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EE7_M_tailERS4_
	movq	%rax, %rdi
	call	_ZSt4moveIRSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEEONSt16remove_referenceIT_E4typeEOS8_
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC2EOS4_
	movq	-24(%rbp), %rax
	leaq	8(%rax), %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EE7_M_headERS4_
	movq	%rax, %rdi
	call	_ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EEC2IS3_EEOT_
	nop
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7680:
	.size	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC2EOS4_, .-_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC2EOS4_
	.weak	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC1EOS4_
	.set	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC1EOS4_,_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC2EOS4_
	.section	.text._ZNSt8functionIFvvEEC2ISt5_BindIFPFvPN7simgrid3s4u7MailboxES7_ES7_S7_EEvvEET_,"axG",@progbits,_ZNSt8functionIFvvEEC5ISt5_BindIFPFvPN7simgrid3s4u7MailboxES7_ES7_S7_EEvvEET_,comdat
	.align 2
	.weak	_ZNSt8functionIFvvEEC2ISt5_BindIFPFvPN7simgrid3s4u7MailboxES7_ES7_S7_EEvvEET_
	.type	_ZNSt8functionIFvvEEC2ISt5_BindIFPFvPN7simgrid3s4u7MailboxES7_ES7_S7_EEvvEET_, @function
_ZNSt8functionIFvvEEC2ISt5_BindIFPFvPN7simgrid3s4u7MailboxES7_ES7_S7_EEvvEET_:
.LFB7683:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7683
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt14_Function_baseC2Ev
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE21_M_not_empty_functionIS9_EEbRKT_
	testb	%al, %al
	je	.L187
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt4moveIRSt5_BindIFPFvPN7simgrid3s4u7MailboxES4_ES4_S4_EEEONSt16remove_referenceIT_E4typeEOSB_
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB24:
	call	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE15_M_init_functorERSt9_Any_dataOS9_
.LEHE24:
	movq	-24(%rbp), %rax
	leaq	_ZNSt17_Function_handlerIFvvESt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE9_M_invokeERKSt9_Any_data(%rip), %rdx
	movq	%rdx, 24(%rax)
	movq	-24(%rbp), %rax
	leaq	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE10_M_managerERSt9_Any_dataRKSB_St18_Manager_operation(%rip), %rdx
	movq	%rdx, 16(%rax)
	jmp	.L187
.L186:
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt14_Function_baseD2Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB25:
	call	_Unwind_Resume@PLT
.LEHE25:
.L187:
	nop
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7683:
	.section	.gcc_except_table
.LLSDA7683:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7683-.LLSDACSB7683
.LLSDACSB7683:
	.uleb128 .LEHB24-.LFB7683
	.uleb128 .LEHE24-.LEHB24
	.uleb128 .L186-.LFB7683
	.uleb128 0
	.uleb128 .LEHB25-.LFB7683
	.uleb128 .LEHE25-.LEHB25
	.uleb128 0
	.uleb128 0
.LLSDACSE7683:
	.section	.text._ZNSt8functionIFvvEEC2ISt5_BindIFPFvPN7simgrid3s4u7MailboxES7_ES7_S7_EEvvEET_,"axG",@progbits,_ZNSt8functionIFvvEEC5ISt5_BindIFPFvPN7simgrid3s4u7MailboxES7_ES7_S7_EEvvEET_,comdat
	.size	_ZNSt8functionIFvvEEC2ISt5_BindIFPFvPN7simgrid3s4u7MailboxES7_ES7_S7_EEvvEET_, .-_ZNSt8functionIFvvEEC2ISt5_BindIFPFvPN7simgrid3s4u7MailboxES7_ES7_S7_EEvvEET_
	.weak	_ZNSt8functionIFvvEEC1ISt5_BindIFPFvPN7simgrid3s4u7MailboxES7_ES7_S7_EEvvEET_
	.set	_ZNSt8functionIFvvEEC1ISt5_BindIFPFvPN7simgrid3s4u7MailboxES7_ES7_S7_EEvvEET_,_ZNSt8functionIFvvEEC2ISt5_BindIFPFvPN7simgrid3s4u7MailboxES7_ES7_S7_EEvvEET_
	.section	.text._ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implC2Ev,"axG",@progbits,_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implC5Ev,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implC2Ev
	.type	_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implC2Ev, @function
_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implC2Ev:
.LFB7695:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIPFvPvEEC2Ev
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 16(%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7695:
	.size	_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implC2Ev, .-_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implC2Ev
	.weak	_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implC1Ev
	.set	_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implC1Ev,_ZNSt12_Vector_baseIPFvPvESaIS2_EE12_Vector_implC2Ev
	.section	.text._ZNSaIPFvPvEED2Ev,"axG",@progbits,_ZNSaIPFvPvEED5Ev,comdat
	.align 2
	.weak	_ZNSaIPFvPvEED2Ev
	.type	_ZNSaIPFvPvEED2Ev, @function
_ZNSaIPFvPvEED2Ev:
.LFB7698:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorIPFvPvEED2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7698:
	.size	_ZNSaIPFvPvEED2Ev, .-_ZNSaIPFvPvEED2Ev
	.weak	_ZNSaIPFvPvEED1Ev
	.set	_ZNSaIPFvPvEED1Ev,_ZNSaIPFvPvEED2Ev
	.section	.text._ZNSt12_Vector_baseIPFvPvESaIS2_EE13_M_deallocateEPS2_m,"axG",@progbits,_ZNSt12_Vector_baseIPFvPvESaIS2_EE13_M_deallocateEPS2_m,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIPFvPvESaIS2_EE13_M_deallocateEPS2_m
	.type	_ZNSt12_Vector_baseIPFvPvESaIS2_EE13_M_deallocateEPS2_m, @function
_ZNSt12_Vector_baseIPFvPvESaIS2_EE13_M_deallocateEPS2_m:
.LFB7700:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.L192
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaIPFvPvEEE10deallocateERS3_PS2_m
.L192:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7700:
	.size	_ZNSt12_Vector_baseIPFvPvESaIS2_EE13_M_deallocateEPS2_m, .-_ZNSt12_Vector_baseIPFvPvESaIS2_EE13_M_deallocateEPS2_m
	.section	.text._ZN5boost4heap6detail11size_holderILb1EmEC2Ev,"axG",@progbits,_ZN5boost4heap6detail11size_holderILb1EmEC5Ev,comdat
	.align 2
	.weak	_ZN5boost4heap6detail11size_holderILb1EmEC2Ev
	.type	_ZN5boost4heap6detail11size_holderILb1EmEC2Ev, @function
_ZN5boost4heap6detail11size_holderILb1EmEC2Ev:
.LFB7800:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7800:
	.size	_ZN5boost4heap6detail11size_holderILb1EmEC2Ev, .-_ZN5boost4heap6detail11size_holderILb1EmEC2Ev
	.weak	_ZN5boost4heap6detail11size_holderILb1EmEC1Ev
	.set	_ZN5boost4heap6detail11size_holderILb1EmEC1Ev,_ZN5boost4heap6detail11size_holderILb1EmEC2Ev
	.section	.text._ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC2Ev,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC5Ev,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC2Ev
	.type	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC2Ev, @function
_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC2Ev:
.LFB7803:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7803:
	.size	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC2Ev, .-_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC2Ev
	.weak	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC1Ev
	.set	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC1Ev,_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEEC2Ev
	.section	.text._ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE14root_plus_sizeC2Ev,"axG",@progbits,_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE14root_plus_sizeC5Ev,comdat
	.align 2
	.weak	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE14root_plus_sizeC2Ev
	.type	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE14root_plus_sizeC2Ev, @function
_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE14root_plus_sizeC2Ev:
.LFB7807:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive6detail21default_header_holderINS0_16list_node_traitsIPvEEEC1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7807:
	.size	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE14root_plus_sizeC2Ev, .-_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE14root_plus_sizeC2Ev
	.weak	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE14root_plus_sizeC1Ev
	.set	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE14root_plus_sizeC1Ev,_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE14root_plus_sizeC2Ev
	.section	.text._ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE6data_tC2ERKSC_,"axG",@progbits,_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE6data_tC5ERKSC_,comdat
	.align 2
	.weak	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE6data_tC2ERKSC_
	.type	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE6data_tC2ERKSC_, @function
_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE6data_tC2ERKSC_:
.LFB7809:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE14root_plus_sizeC1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7809:
	.size	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE6data_tC2ERKSC_, .-_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE6data_tC2ERKSC_
	.weak	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE6data_tC1ERKSC_
	.set	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE6data_tC1ERKSC_,_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE6data_tC2ERKSC_
	.section	.text._ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE16priv_size_traitsEv,"axG",@progbits,_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE16priv_size_traitsEv,comdat
	.align 2
	.weak	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE16priv_size_traitsEv
	.type	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE16priv_size_traitsEv, @function
_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE16priv_size_traitsEv:
.LFB7811:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7811:
	.size	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE16priv_size_traitsEv, .-_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE16priv_size_traitsEv
	.section	.text._ZN5boost9intrusive6detail11size_holderILb1EmvE8set_sizeEm,"axG",@progbits,_ZN5boost9intrusive6detail11size_holderILb1EmvE8set_sizeEm,comdat
	.align 2
	.weak	_ZN5boost9intrusive6detail11size_holderILb1EmvE8set_sizeEm
	.type	_ZN5boost9intrusive6detail11size_holderILb1EmvE8set_sizeEm, @function
_ZN5boost9intrusive6detail11size_holderILb1EmvE8set_sizeEm:
.LFB7812:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7812:
	.size	_ZN5boost9intrusive6detail11size_holderILb1EmvE8set_sizeEm, .-_ZN5boost9intrusive6detail11size_holderILb1EmvE8set_sizeEm
	.section	.text._ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE11init_headerERKPNS0_9list_nodeIS3_EE,"axG",@progbits,_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE11init_headerERKPNS0_9list_nodeIS3_EE,comdat
	.weak	_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE11init_headerERKPNS0_9list_nodeIS3_EE
	.type	_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE11init_headerERKPNS0_9list_nodeIS3_EE, @function
_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE11init_headerERKPNS0_9list_nodeIS3_EE:
.LFB7813:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive16list_node_traitsIPvE8set_nextERKPNS0_9list_nodeIS2_EES8_
	movq	-8(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive16list_node_traitsIPvE12set_previousERKPNS0_9list_nodeIS2_EES8_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7813:
	.size	_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE11init_headerERKPNS0_9list_nodeIS3_EE, .-_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE11init_headerERKPNS0_9list_nodeIS3_EE
	.section	.text._ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS0_6detail13null_disposerEEEvT_,"axG",@progbits,_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS0_6detail13null_disposerEEEvT_,comdat
	.align 2
	.weak	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS0_6detail13null_disposerEEEvT_
	.type	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS0_6detail13null_disposerEEEvT_, @function
_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS0_6detail13null_disposerEEEvT_:
.LFB7814:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-16(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE5beginEv
	leaq	-16(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEC1ERKNS1_ISC_Lb0EEE
	leaq	-16(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE3endEv
	leaq	-16(%rbp), %rdx
	leaq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEC1ERKNS1_ISC_Lb0EEE
.L203:
	leaq	-24(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusiveneERKNS0_13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEESF_
	testb	%al, %al
	je	.L202
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EE12pointed_nodeEv
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEppEv
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE4initERKPNS0_9list_nodeIS3_EE
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17priv_value_traitsEv
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive13bhtraits_baseINS_4heap6detail14heap_node_baseILb0EEEPNS0_9list_nodeIPvEENS0_7dft_tagELj1EE12to_value_ptrERKS9_
	movq	%rax, %rsi
	leaq	16(%rbp), %rdi
	call	_ZN5boost9intrusive6detail13null_disposerclIPNS_4heap6detail14heap_node_baseILb0EEEEEvT_
	jmp	.L203
.L202:
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE13get_root_nodeEv
	movq	%rax, -16(%rbp)
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE11init_headerERKPNS0_9list_nodeIS3_EE
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE16priv_size_traitsEv
	movl	$0, %esi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive6detail11size_holderILb1EmvE8set_sizeEm
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L204
	call	__stack_chk_fail@PLT
.L204:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7814:
	.size	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS0_6detail13null_disposerEEEvT_, .-_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS0_6detail13null_disposerEEEvT_
	.section	.text._ZN5boost9intrusive16list_node_traitsIPvE8set_nextERKPNS0_9list_nodeIS2_EES8_,"axG",@progbits,_ZN5boost9intrusive16list_node_traitsIPvE8set_nextERKPNS0_9list_nodeIS2_EES8_,comdat
	.weak	_ZN5boost9intrusive16list_node_traitsIPvE8set_nextERKPNS0_9list_nodeIS2_EES8_
	.type	_ZN5boost9intrusive16list_node_traitsIPvE8set_nextERKPNS0_9list_nodeIS2_EES8_, @function
_ZN5boost9intrusive16list_node_traitsIPvE8set_nextERKPNS0_9list_nodeIS2_EES8_:
.LFB7815:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	-16(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7815:
	.size	_ZN5boost9intrusive16list_node_traitsIPvE8set_nextERKPNS0_9list_nodeIS2_EES8_, .-_ZN5boost9intrusive16list_node_traitsIPvE8set_nextERKPNS0_9list_nodeIS2_EES8_
	.section	.text._ZN5boost9intrusive16list_node_traitsIPvE12set_previousERKPNS0_9list_nodeIS2_EES8_,"axG",@progbits,_ZN5boost9intrusive16list_node_traitsIPvE12set_previousERKPNS0_9list_nodeIS2_EES8_,comdat
	.weak	_ZN5boost9intrusive16list_node_traitsIPvE12set_previousERKPNS0_9list_nodeIS2_EES8_
	.type	_ZN5boost9intrusive16list_node_traitsIPvE12set_previousERKPNS0_9list_nodeIS2_EES8_, @function
_ZN5boost9intrusive16list_node_traitsIPvE12set_previousERKPNS0_9list_nodeIS2_EES8_:
.LFB7816:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	-16(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7816:
	.size	_ZN5boost9intrusive16list_node_traitsIPvE12set_previousERKPNS0_9list_nodeIS2_EES8_, .-_ZN5boost9intrusive16list_node_traitsIPvE12set_previousERKPNS0_9list_nodeIS2_EES8_
	.section	.text._ZN5boost9intrusive6detail21default_header_holderINS0_16list_node_traitsIPvEEE8get_nodeEv,"axG",@progbits,_ZN5boost9intrusive6detail21default_header_holderINS0_16list_node_traitsIPvEEE8get_nodeEv,comdat
	.align 2
	.weak	_ZN5boost9intrusive6detail21default_header_holderINS0_16list_node_traitsIPvEEE8get_nodeEv
	.type	_ZN5boost9intrusive6detail21default_header_holderINS0_16list_node_traitsIPvEEE8get_nodeEv, @function
_ZN5boost9intrusive6detail21default_header_holderINS0_16list_node_traitsIPvEEE8get_nodeEv:
.LFB7817:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive14pointer_traitsIPNS0_9list_nodeIPvEEE10pointer_toERS4_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7817:
	.size	_ZN5boost9intrusive6detail21default_header_holderINS0_16list_node_traitsIPvEEE8get_nodeEv, .-_ZN5boost9intrusive6detail21default_header_holderINS0_16list_node_traitsIPvEEE8get_nodeEv
	.section	.text._ZSt16forward_as_tupleIJEESt5tupleIJDpOT_EES3_,"axG",@progbits,_ZSt16forward_as_tupleIJEESt5tupleIJDpOT_EES3_,comdat
	.weak	_ZSt16forward_as_tupleIJEESt5tupleIJDpOT_EES3_
	.type	_ZSt16forward_as_tupleIJEESt5tupleIJDpOT_EES3_, @function
_ZSt16forward_as_tupleIJEESt5tupleIJDpOT_EES3_:
.LFB7822:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7822:
	.size	_ZSt16forward_as_tupleIJEESt5tupleIJDpOT_EES3_, .-_ZSt16forward_as_tupleIJEESt5tupleIJDpOT_EES3_
	.section	.text._ZN5boost9intrusiveneERKNS0_13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEESF_,"axG",@progbits,_ZN5boost9intrusiveneERKNS0_13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEESF_,comdat
	.weak	_ZN5boost9intrusiveneERKNS0_13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEESF_
	.type	_ZN5boost9intrusiveneERKNS0_13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEESF_, @function
_ZN5boost9intrusiveneERKNS0_13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEESF_:
.LFB7825:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusiveeqERKNS0_13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEESF_
	xorl	$1, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7825:
	.size	_ZN5boost9intrusiveneERKNS0_13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEESF_, .-_ZN5boost9intrusiveneERKNS0_13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEESF_
	.section	.text._ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEppEv,"axG",@progbits,_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEppEv,comdat
	.align 2
	.weak	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEppEv
	.type	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEppEv, @function
_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEppEv:
.LFB7826:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive16list_node_traitsIPvE8get_nextERKPNS0_9list_nodeIS2_EE
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7826:
	.size	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEppEv, .-_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEppEv
	.section	.text._ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC2IS3_S3_Lb1EEEOT_OT0_,"axG",@progbits,_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC5IS3_S3_Lb1EEEOT_OT0_,comdat
	.align 2
	.weak	_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC2IS3_S3_Lb1EEEOT_OT0_
	.type	_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC2IS3_S3_Lb1EEEOT_OT0_, @function
_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC2IS3_S3_Lb1EEEOT_OT0_:
.LFB7839:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-24(%rbp), %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE
	movq	%rax, %r12
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE
	movq	%r12, %rdx
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC2IS3_JS3_EvEEOT_DpOT0_
	nop
	addq	$32, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7839:
	.size	_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC2IS3_S3_Lb1EEEOT_OT0_, .-_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC2IS3_S3_Lb1EEEOT_OT0_
	.weak	_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC1IS3_S3_Lb1EEEOT_OT0_
	.set	_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC1IS3_S3_Lb1EEEOT_OT0_,_ZNSt5tupleIJPN7simgrid3s4u7MailboxES3_EEC2IS3_S3_Lb1EEEOT_OT0_
	.section	.text._ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EEC2IS3_EEOT_,"axG",@progbits,_ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EEC5IS3_EEOT_,comdat
	.align 2
	.weak	_ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EEC2IS3_EEOT_
	.type	_ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EEC2IS3_EEOT_, @function
_ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EEC2IS3_EEOT_:
.LFB7842:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7842:
	.size	_ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EEC2IS3_EEOT_, .-_ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EEC2IS3_EEOT_
	.weak	_ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EEC1IS3_EEOT_
	.set	_ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EEC1IS3_EEOT_,_ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EEC2IS3_EEOT_
	.section	.text._ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE21_M_not_empty_functionIS9_EEbRKT_,"axG",@progbits,_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE21_M_not_empty_functionIS9_EEbRKT_,comdat
	.weak	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE21_M_not_empty_functionIS9_EEbRKT_
	.type	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE21_M_not_empty_functionIS9_EEbRKT_, @function
_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE21_M_not_empty_functionIS9_EEbRKT_:
.LFB7844:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	$1, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7844:
	.size	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE21_M_not_empty_functionIS9_EEbRKT_, .-_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE21_M_not_empty_functionIS9_EEbRKT_
	.section	.text._ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE15_M_init_functorERSt9_Any_dataOS9_,"axG",@progbits,_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE15_M_init_functorERSt9_Any_dataOS9_,comdat
	.weak	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE15_M_init_functorERSt9_Any_dataOS9_
	.type	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE15_M_init_functorERSt9_Any_dataOS9_, @function
_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE15_M_init_functorERSt9_Any_dataOS9_:
.LFB7845:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt4moveIRSt5_BindIFPFvPN7simgrid3s4u7MailboxES4_ES4_S4_EEEONSt16remove_referenceIT_E4typeEOSB_
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	subq	$8, %rsp
	pushq	%rbx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE15_M_init_functorERSt9_Any_dataOS9_St17integral_constantIbLb0EE
	addq	$16, %rsp
	nop
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L220
	call	__stack_chk_fail@PLT
.L220:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7845:
	.size	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE15_M_init_functorERSt9_Any_dataOS9_, .-_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE15_M_init_functorERSt9_Any_dataOS9_
	.section	.text._ZNSt17_Function_handlerIFvvESt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE9_M_invokeERKSt9_Any_data,"axG",@progbits,_ZNSt17_Function_handlerIFvvESt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE9_M_invokeERKSt9_Any_data,comdat
	.weak	_ZNSt17_Function_handlerIFvvESt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE9_M_invokeERKSt9_Any_data
	.type	_ZNSt17_Function_handlerIFvvESt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE9_M_invokeERKSt9_Any_data, @function
_ZNSt17_Function_handlerIFvvESt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE9_M_invokeERKSt9_Any_data:
.LFB7846:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE14_M_get_pointerERKSt9_Any_data
	movq	%rax, %rdi
	call	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEclIJEvEET0_DpOT_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7846:
	.size	_ZNSt17_Function_handlerIFvvESt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE9_M_invokeERKSt9_Any_data, .-_ZNSt17_Function_handlerIFvvESt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE9_M_invokeERKSt9_Any_data
	.section	.text._ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE10_M_managerERSt9_Any_dataRKSB_St18_Manager_operation,"axG",@progbits,_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE10_M_managerERSt9_Any_dataRKSB_St18_Manager_operation,comdat
	.weak	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE10_M_managerERSt9_Any_dataRKSB_St18_Manager_operation
	.type	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE10_M_managerERSt9_Any_dataRKSB_St18_Manager_operation, @function
_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE10_M_managerERSt9_Any_dataRKSB_St18_Manager_operation:
.LFB7847:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movl	%edx, -52(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movl	-52(%rbp), %eax
	cmpl	$1, %eax
	je	.L224
	cmpl	$1, %eax
	jg	.L225
	testl	%eax, %eax
	je	.L226
	jmp	.L223
.L225:
	cmpl	$2, %eax
	je	.L227
	cmpl	$3, %eax
	je	.L228
	jmp	.L223
.L226:
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt9_Any_data9_M_accessIPKSt9type_infoEERT_v
	movq	%rax, %rdx
	leaq	_ZTISt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE(%rip), %rax
	movq	%rax, (%rdx)
	jmp	.L223
.L224:
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERT_v
	movq	%rax, %rbx
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE14_M_get_pointerERKSt9_Any_data
	movq	%rax, (%rbx)
	jmp	.L223
.L227:
	movq	-48(%rbp), %rdx
	movq	-40(%rbp), %rax
	subq	$8, %rsp
	pushq	%r8
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE8_M_cloneERSt9_Any_dataRKSB_St17integral_constantIbLb0EE
	addq	$16, %rsp
	jmp	.L223
.L228:
	movq	-40(%rbp), %rax
	subq	$8, %rsp
	pushq	%rcx
	movq	%rax, %rdi
	call	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE
	addq	$16, %rsp
	nop
.L223:
	movl	$0, %eax
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L230
	call	__stack_chk_fail@PLT
.L230:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7847:
	.size	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE10_M_managerERSt9_Any_dataRKSB_St18_Manager_operation, .-_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE10_M_managerERSt9_Any_dataRKSB_St18_Manager_operation
	.section	.text._ZNSaIPFvPvEEC2Ev,"axG",@progbits,_ZNSaIPFvPvEEC5Ev,comdat
	.align 2
	.weak	_ZNSaIPFvPvEEC2Ev
	.type	_ZNSaIPFvPvEEC2Ev, @function
_ZNSaIPFvPvEEC2Ev:
.LFB7855:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorIPFvPvEEC2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7855:
	.size	_ZNSaIPFvPvEEC2Ev, .-_ZNSaIPFvPvEEC2Ev
	.weak	_ZNSaIPFvPvEEC1Ev
	.set	_ZNSaIPFvPvEEC1Ev,_ZNSaIPFvPvEEC2Ev
	.section	.text._ZN9__gnu_cxx13new_allocatorIPFvPvEED2Ev,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIPFvPvEED5Ev,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIPFvPvEED2Ev
	.type	_ZN9__gnu_cxx13new_allocatorIPFvPvEED2Ev, @function
_ZN9__gnu_cxx13new_allocatorIPFvPvEED2Ev:
.LFB7858:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7858:
	.size	_ZN9__gnu_cxx13new_allocatorIPFvPvEED2Ev, .-_ZN9__gnu_cxx13new_allocatorIPFvPvEED2Ev
	.weak	_ZN9__gnu_cxx13new_allocatorIPFvPvEED1Ev
	.set	_ZN9__gnu_cxx13new_allocatorIPFvPvEED1Ev,_ZN9__gnu_cxx13new_allocatorIPFvPvEED2Ev
	.section	.text._ZNSt16allocator_traitsISaIPFvPvEEE10deallocateERS3_PS2_m,"axG",@progbits,_ZNSt16allocator_traitsISaIPFvPvEEE10deallocateERS3_PS2_m,comdat
	.weak	_ZNSt16allocator_traitsISaIPFvPvEEE10deallocateERS3_PS2_m
	.type	_ZNSt16allocator_traitsISaIPFvPvEEE10deallocateERS3_PS2_m, @function
_ZNSt16allocator_traitsISaIPFvPvEEE10deallocateERS3_PS2_m:
.LFB7860:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorIPFvPvEE10deallocateEPS3_m
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7860:
	.size	_ZNSt16allocator_traitsISaIPFvPvEEE10deallocateERS3_PS2_m, .-_ZNSt16allocator_traitsISaIPFvPvEEE10deallocateERS3_PS2_m
	.section	.text._ZN5boost9intrusive6detail21default_header_holderINS0_16list_node_traitsIPvEEEC2Ev,"axG",@progbits,_ZN5boost9intrusive6detail21default_header_holderINS0_16list_node_traitsIPvEEEC5Ev,comdat
	.align 2
	.weak	_ZN5boost9intrusive6detail21default_header_holderINS0_16list_node_traitsIPvEEEC2Ev
	.type	_ZN5boost9intrusive6detail21default_header_holderINS0_16list_node_traitsIPvEEEC2Ev, @function
_ZN5boost9intrusive6detail21default_header_holderINS0_16list_node_traitsIPvEEEC2Ev:
.LFB7949:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7949:
	.size	_ZN5boost9intrusive6detail21default_header_holderINS0_16list_node_traitsIPvEEEC2Ev, .-_ZN5boost9intrusive6detail21default_header_holderINS0_16list_node_traitsIPvEEEC2Ev
	.weak	_ZN5boost9intrusive6detail21default_header_holderINS0_16list_node_traitsIPvEEEC1Ev
	.set	_ZN5boost9intrusive6detail21default_header_holderINS0_16list_node_traitsIPvEEEC1Ev,_ZN5boost9intrusive6detail21default_header_holderINS0_16list_node_traitsIPvEEEC2Ev
	.section	.text._ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE5beginEv,"axG",@progbits,_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE5beginEv,comdat
	.align 2
	.weak	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE5beginEv
	.type	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE5beginEv, @function
_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE5beginEv:
.LFB7951:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE21priv_value_traits_ptrEv
	movq	%rax, -16(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE13get_root_nodeEv
	movq	%rax, -32(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive16list_node_traitsIPvE8get_nextERKPNS0_9list_nodeIS2_EE
	movq	%rax, -24(%rbp)
	leaq	-16(%rbp), %rdx
	leaq	-24(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC1ERKPNS0_9list_nodeIS8_EERKPKSC_
	movq	-40(%rbp), %rax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L237
	call	__stack_chk_fail@PLT
.L237:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7951:
	.size	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE5beginEv, .-_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE5beginEv
	.section	.text._ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEC2ERKNS1_ISC_Lb0EEE,"axG",@progbits,_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEC5ERKNS1_ISC_Lb0EEE,comdat
	.align 2
	.weak	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEC2ERKNS1_ISC_Lb0EEE
	.type	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEC2ERKNS1_ISC_Lb0EEE, @function
_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEC2ERKNS1_ISC_Lb0EEE:
.LFB7953:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rbx
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE16get_value_traitsEv
	movq	%rax, -32(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE12pointed_nodeEv
	movq	%rax, %rcx
	leaq	-32(%rbp), %rax
	movq	%rax, %rdx
	movq	%rcx, %rsi
	movq	%rbx, %rdi
	call	_ZN5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC1ERKS5_RKSH_
	nop
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L239
	call	__stack_chk_fail@PLT
.L239:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7953:
	.size	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEC2ERKNS1_ISC_Lb0EEE, .-_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEC2ERKNS1_ISC_Lb0EEE
	.weak	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEC1ERKNS1_ISC_Lb0EEE
	.set	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEC1ERKNS1_ISC_Lb0EEE,_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEC2ERKNS1_ISC_Lb0EEE
	.section	.text._ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE3endEv,"axG",@progbits,_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE3endEv,comdat
	.align 2
	.weak	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE3endEv
	.type	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE3endEv, @function
_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE3endEv:
.LFB7955:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE21priv_value_traits_ptrEv
	movq	%rax, -16(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE13get_root_nodeEv
	movq	%rax, -24(%rbp)
	leaq	-16(%rbp), %rdx
	leaq	-24(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC1ERKPNS0_9list_nodeIS8_EERKPKSC_
	movq	-40(%rbp), %rax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L242
	call	__stack_chk_fail@PLT
.L242:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7955:
	.size	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE3endEv, .-_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE3endEv
	.section	.text._ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EE12pointed_nodeEv,"axG",@progbits,_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EE12pointed_nodeEv,comdat
	.align 2
	.weak	_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EE12pointed_nodeEv
	.type	_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EE12pointed_nodeEv, @function
_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EE12pointed_nodeEv:
.LFB7956:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7956:
	.size	_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EE12pointed_nodeEv, .-_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EE12pointed_nodeEv
	.section	.text._ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17priv_value_traitsEv,"axG",@progbits,_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17priv_value_traitsEv,comdat
	.align 2
	.weak	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17priv_value_traitsEv
	.type	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17priv_value_traitsEv, @function
_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17priv_value_traitsEv:
.LFB7957:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7957:
	.size	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17priv_value_traitsEv, .-_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17priv_value_traitsEv
	.section	.text._ZN5boost9intrusive13bhtraits_baseINS_4heap6detail14heap_node_baseILb0EEEPNS0_9list_nodeIPvEENS0_7dft_tagELj1EE12to_value_ptrERKS9_,"axG",@progbits,_ZN5boost9intrusive13bhtraits_baseINS_4heap6detail14heap_node_baseILb0EEEPNS0_9list_nodeIPvEENS0_7dft_tagELj1EE12to_value_ptrERKS9_,comdat
	.weak	_ZN5boost9intrusive13bhtraits_baseINS_4heap6detail14heap_node_baseILb0EEEPNS0_9list_nodeIPvEENS0_7dft_tagELj1EE12to_value_ptrERKS9_
	.type	_ZN5boost9intrusive13bhtraits_baseINS_4heap6detail14heap_node_baseILb0EEEPNS0_9list_nodeIPvEENS0_7dft_tagELj1EE12to_value_ptrERKS9_, @function
_ZN5boost9intrusive13bhtraits_baseINS_4heap6detail14heap_node_baseILb0EEEPNS0_9list_nodeIPvEENS0_7dft_tagELj1EE12to_value_ptrERKS9_:
.LFB7958:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive14pointer_traitsIPNS_4heap6detail14heap_node_baseILb0EEEE10pointer_toERS5_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7958:
	.size	_ZN5boost9intrusive13bhtraits_baseINS_4heap6detail14heap_node_baseILb0EEEPNS0_9list_nodeIPvEENS0_7dft_tagELj1EE12to_value_ptrERKS9_, .-_ZN5boost9intrusive13bhtraits_baseINS_4heap6detail14heap_node_baseILb0EEEPNS0_9list_nodeIPvEENS0_7dft_tagELj1EE12to_value_ptrERKS9_
	.section	.text._ZN5boost9intrusive6detail13null_disposerclIPNS_4heap6detail14heap_node_baseILb0EEEEEvT_,"axG",@progbits,_ZN5boost9intrusive6detail13null_disposerclIPNS_4heap6detail14heap_node_baseILb0EEEEEvT_,comdat
	.align 2
	.weak	_ZN5boost9intrusive6detail13null_disposerclIPNS_4heap6detail14heap_node_baseILb0EEEEEvT_
	.type	_ZN5boost9intrusive6detail13null_disposerclIPNS_4heap6detail14heap_node_baseILb0EEEEEvT_, @function
_ZN5boost9intrusive6detail13null_disposerclIPNS_4heap6detail14heap_node_baseILb0EEEEEvT_:
.LFB7959:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7959:
	.size	_ZN5boost9intrusive6detail13null_disposerclIPNS_4heap6detail14heap_node_baseILb0EEEEEvT_, .-_ZN5boost9intrusive6detail13null_disposerclIPNS_4heap6detail14heap_node_baseILb0EEEEEvT_
	.section	.text._ZN5boost9intrusiveeqERKNS0_13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEESF_,"axG",@progbits,_ZN5boost9intrusiveeqERKNS0_13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEESF_,comdat
	.weak	_ZN5boost9intrusiveeqERKNS0_13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEESF_
	.type	_ZN5boost9intrusiveeqERKNS0_13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEESF_, @function
_ZN5boost9intrusiveeqERKNS0_13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEESF_:
.LFB7967:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EE12pointed_nodeEv
	movq	(%rax), %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EE12pointed_nodeEv
	movq	(%rax), %rax
	cmpq	%rax, %rbx
	sete	%al
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7967:
	.size	_ZN5boost9intrusiveeqERKNS0_13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEESF_, .-_ZN5boost9intrusiveeqERKNS0_13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEESF_
	.section	.text._ZN5boost9intrusive16list_node_traitsIPvE8get_nextERKPNS0_9list_nodeIS2_EE,"axG",@progbits,_ZN5boost9intrusive16list_node_traitsIPvE8get_nextERKPNS0_9list_nodeIS2_EE,comdat
	.weak	_ZN5boost9intrusive16list_node_traitsIPvE8get_nextERKPNS0_9list_nodeIS2_EE
	.type	_ZN5boost9intrusive16list_node_traitsIPvE8get_nextERKPNS0_9list_nodeIS2_EE, @function
_ZN5boost9intrusive16list_node_traitsIPvE8get_nextERKPNS0_9list_nodeIS2_EE:
.LFB7968:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7968:
	.size	_ZN5boost9intrusive16list_node_traitsIPvE8get_nextERKPNS0_9list_nodeIS2_EE, .-_ZN5boost9intrusive16list_node_traitsIPvE8get_nextERKPNS0_9list_nodeIS2_EE
	.section	.text._ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC2IS3_JS3_EvEEOT_DpOT0_,"axG",@progbits,_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC5IS3_JS3_EvEEOT_DpOT0_,comdat
	.align 2
	.weak	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC2IS3_JS3_EvEEOT_DpOT0_
	.type	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC2IS3_JS3_EvEEOT_DpOT0_, @function
_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC2IS3_JS3_EvEEOT_DpOT0_:
.LFB7992:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-24(%rbp), %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC2IS3_EEOT_
	movq	-24(%rbp), %rax
	leaq	8(%rax), %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNSt10_Head_baseILm0EPN7simgrid3s4u7MailboxELb0EEC2IS3_EEOT_
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7992:
	.size	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC2IS3_JS3_EvEEOT_DpOT0_, .-_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC2IS3_JS3_EvEEOT_DpOT0_
	.weak	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC1IS3_JS3_EvEEOT_DpOT0_
	.set	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC1IS3_JS3_EvEEOT_DpOT0_,_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EEC2IS3_JS3_EvEEOT_DpOT0_
	.section	.text._ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE15_M_init_functorERSt9_Any_dataOS9_St17integral_constantIbLb0EE,"axG",@progbits,_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE15_M_init_functorERSt9_Any_dataOS9_St17integral_constantIbLb0EE,comdat
	.weak	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE15_M_init_functorERSt9_Any_dataOS9_St17integral_constantIbLb0EE
	.type	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE15_M_init_functorERSt9_Any_dataOS9_St17integral_constantIbLb0EE, @function
_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE15_M_init_functorERSt9_Any_dataOS9_St17integral_constantIbLb0EE:
.LFB7994:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$16, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt4moveIRSt5_BindIFPFvPN7simgrid3s4u7MailboxES4_ES4_S4_EEEONSt16remove_referenceIT_E4typeEOSB_
	movq	%rax, %r12
	movl	$24, %edi
	call	_Znwm@PLT
	movq	%rax, %rbx
	movq	%r12, %rsi
	movq	%rbx, %rdi
	call	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEC1EOS7_
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERT_v
	movq	%rbx, (%rax)
	nop
	addq	$16, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7994:
	.size	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE15_M_init_functorERSt9_Any_dataOS9_St17integral_constantIbLb0EE, .-_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE15_M_init_functorERSt9_Any_dataOS9_St17integral_constantIbLb0EE
	.section	.text._ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE14_M_get_pointerERKSt9_Any_data,"axG",@progbits,_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE14_M_get_pointerERKSt9_Any_data,comdat
	.weak	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE14_M_get_pointerERKSt9_Any_data
	.type	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE14_M_get_pointerERKSt9_Any_data, @function
_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE14_M_get_pointerERKSt9_Any_data:
.LFB7995:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERKT_v
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7995:
	.size	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE14_M_get_pointerERKSt9_Any_data, .-_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE14_M_get_pointerERKSt9_Any_data
	.section	.text._ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEclIJEvEET0_DpOT_,"axG",@progbits,_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEclIJEvEET0_DpOT_,comdat
	.align 2
	.weak	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEclIJEvEET0_DpOT_
	.type	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEclIJEvEET0_DpOT_, @function
_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEclIJEvEET0_DpOT_:
.LFB7996:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	call	_ZSt16forward_as_tupleIJEESt5tupleIJDpOT_EES3_
	leaq	-25(%rbp), %rdx
	movq	-40(%rbp), %rax
	subq	$8, %rsp
	pushq	%rbx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE6__callIvJEJLm0ELm1EEEET_OSt5tupleIJDpT0_EESt12_Index_tupleIJXspT1_EEE
	addq	$16, %rsp
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L260
	call	__stack_chk_fail@PLT
.L260:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7996:
	.size	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEclIJEvEET0_DpOT_, .-_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EEclIJEvEET0_DpOT_
	.section	.text._ZNSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERT_v,"axG",@progbits,_ZNSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERT_v,comdat
	.align 2
	.weak	_ZNSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERT_v
	.type	_ZNSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERT_v, @function
_ZNSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERT_v:
.LFB7997:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt9_Any_data9_M_accessEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7997:
	.size	_ZNSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERT_v, .-_ZNSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERT_v
	.section	.text._ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE8_M_cloneERSt9_Any_dataRKSB_St17integral_constantIbLb0EE,"axG",@progbits,_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE8_M_cloneERSt9_Any_dataRKSB_St17integral_constantIbLb0EE,comdat
	.weak	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE8_M_cloneERSt9_Any_dataRKSB_St17integral_constantIbLb0EE
	.type	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE8_M_cloneERSt9_Any_dataRKSB_St17integral_constantIbLb0EE, @function
_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE8_M_cloneERSt9_Any_dataRKSB_St17integral_constantIbLb0EE:
.LFB7998:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$16, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERKT_v
	movq	(%rax), %r12
	movl	$24, %edi
	call	_Znwm@PLT
	movq	%rax, %rbx
	movq	(%r12), %rax
	movq	8(%r12), %rdx
	movq	%rax, (%rbx)
	movq	%rdx, 8(%rbx)
	movq	16(%r12), %rax
	movq	%rax, 16(%rbx)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERT_v
	movq	%rbx, (%rax)
	nop
	addq	$16, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7998:
	.size	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE8_M_cloneERSt9_Any_dataRKSB_St17integral_constantIbLb0EE, .-_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE8_M_cloneERSt9_Any_dataRKSB_St17integral_constantIbLb0EE
	.section	.text._ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE,"axG",@progbits,_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE,comdat
	.weak	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE
	.type	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE, @function
_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE:
.LFB7999:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERT_v
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZdlPv@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7999:
	.size	_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE, .-_ZNSt14_Function_base13_Base_managerISt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEE10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE
	.section	.text._ZN9__gnu_cxx13new_allocatorIPFvPvEEC2Ev,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIPFvPvEEC5Ev,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIPFvPvEEC2Ev
	.type	_ZN9__gnu_cxx13new_allocatorIPFvPvEEC2Ev, @function
_ZN9__gnu_cxx13new_allocatorIPFvPvEEC2Ev:
.LFB8007:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8007:
	.size	_ZN9__gnu_cxx13new_allocatorIPFvPvEEC2Ev, .-_ZN9__gnu_cxx13new_allocatorIPFvPvEEC2Ev
	.weak	_ZN9__gnu_cxx13new_allocatorIPFvPvEEC1Ev
	.set	_ZN9__gnu_cxx13new_allocatorIPFvPvEEC1Ev,_ZN9__gnu_cxx13new_allocatorIPFvPvEEC2Ev
	.section	.text._ZN9__gnu_cxx13new_allocatorIPFvPvEE10deallocateEPS3_m,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIPFvPvEE10deallocateEPS3_m,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIPFvPvEE10deallocateEPS3_m
	.type	_ZN9__gnu_cxx13new_allocatorIPFvPvEE10deallocateEPS3_m, @function
_ZN9__gnu_cxx13new_allocatorIPFvPvEE10deallocateEPS3_m:
.LFB8009:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZdlPv@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8009:
	.size	_ZN9__gnu_cxx13new_allocatorIPFvPvEE10deallocateEPS3_m, .-_ZN9__gnu_cxx13new_allocatorIPFvPvEE10deallocateEPS3_m
	.section	.text._ZNK5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE21priv_value_traits_ptrEv,"axG",@progbits,_ZNK5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE21priv_value_traits_ptrEv,comdat
	.align 2
	.weak	_ZNK5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE21priv_value_traits_ptrEv
	.type	_ZNK5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE21priv_value_traits_ptrEv, @function
_ZNK5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE21priv_value_traits_ptrEv:
.LFB8105:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17priv_value_traitsEv
	movq	%rax, %rdi
	call	_ZN5boost9intrusive14pointer_traitsIPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEE10pointer_toERSD_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8105:
	.size	_ZNK5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE21priv_value_traits_ptrEv, .-_ZNK5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE21priv_value_traits_ptrEv
	.section	.text._ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC2ERKPNS0_9list_nodeIS8_EERKPKSC_,"axG",@progbits,_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC5ERKPNS0_9list_nodeIS8_EERKPKSC_,comdat
	.align 2
	.weak	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC2ERKPNS0_9list_nodeIS8_EERKPKSC_
	.type	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC2ERKPNS0_9list_nodeIS8_EERKPKSC_, @function
_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC2ERKPNS0_9list_nodeIS8_EERKPKSC_:
.LFB8107:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC1ERKS5_RKSH_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8107:
	.size	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC2ERKPNS0_9list_nodeIS8_EERKPKSC_, .-_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC2ERKPNS0_9list_nodeIS8_EERKPKSC_
	.weak	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC1ERKPNS0_9list_nodeIS8_EERKPKSC_
	.set	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC1ERKPNS0_9list_nodeIS8_EERKPKSC_,_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC2ERKPNS0_9list_nodeIS8_EERKPKSC_
	.section	.text._ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE12pointed_nodeEv,"axG",@progbits,_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE12pointed_nodeEv,comdat
	.align 2
	.weak	_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE12pointed_nodeEv
	.type	_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE12pointed_nodeEv, @function
_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE12pointed_nodeEv:
.LFB8112:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8112:
	.size	_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE12pointed_nodeEv, .-_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE12pointed_nodeEv
	.section	.text._ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE16get_value_traitsEv,"axG",@progbits,_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE16get_value_traitsEv,comdat
	.align 2
	.weak	_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE16get_value_traitsEv
	.type	_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE16get_value_traitsEv, @function
_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE16get_value_traitsEv:
.LFB8113:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE7get_ptrEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8113:
	.size	_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE16get_value_traitsEv, .-_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE16get_value_traitsEv
	.section	.text._ZN5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC2ERKS5_RKSH_,"axG",@progbits,_ZN5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC5ERKS5_RKSH_,comdat
	.align 2
	.weak	_ZN5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC2ERKS5_RKSH_
	.type	_ZN5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC2ERKS5_RKSH_, @function
_ZN5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC2ERKS5_RKSH_:
.LFB8115:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8115:
	.size	_ZN5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC2ERKS5_RKSH_, .-_ZN5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC2ERKS5_RKSH_
	.weak	_ZN5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC1ERKS5_RKSH_
	.set	_ZN5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC1ERKS5_RKSH_,_ZN5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EEC2ERKS5_RKSH_
	.section	.text._ZN5boost9intrusive14pointer_traitsIPNS_4heap6detail14heap_node_baseILb0EEEE10pointer_toERS5_,"axG",@progbits,_ZN5boost9intrusive14pointer_traitsIPNS_4heap6detail14heap_node_baseILb0EEEE10pointer_toERS5_,comdat
	.weak	_ZN5boost9intrusive14pointer_traitsIPNS_4heap6detail14heap_node_baseILb0EEEE10pointer_toERS5_
	.type	_ZN5boost9intrusive14pointer_traitsIPNS_4heap6detail14heap_node_baseILb0EEEE10pointer_toERS5_, @function
_ZN5boost9intrusive14pointer_traitsIPNS_4heap6detail14heap_node_baseILb0EEEE10pointer_toERS5_:
.LFB8117:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -56(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-56(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	$0, -16(%rbp)
	movq	-24(%rbp), %rax
	nop
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L280
	call	__stack_chk_fail@PLT
.L280:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8117:
	.size	_ZN5boost9intrusive14pointer_traitsIPNS_4heap6detail14heap_node_baseILb0EEEE10pointer_toERS5_, .-_ZN5boost9intrusive14pointer_traitsIPNS_4heap6detail14heap_node_baseILb0EEEE10pointer_toERS5_
	.text
	.type	_ZN5boost9intrusive6detailL6uncastIPKNS0_9list_nodeIPvEEEENS1_12uncast_typesIT_E17non_const_pointerERKS9_, @function
_ZN5boost9intrusive6detailL6uncastIPKNS0_9list_nodeIPvEEEENS1_12uncast_typesIT_E17non_const_pointerERKS9_:
.LFB8124:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive14pointer_traitsIPNS0_9list_nodeIPvEEE15const_cast_fromIKS4_EES5_PT_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8124:
	.size	_ZN5boost9intrusive6detailL6uncastIPKNS0_9list_nodeIPvEEEENS1_12uncast_typesIT_E17non_const_pointerERKS9_, .-_ZN5boost9intrusive6detailL6uncastIPKNS0_9list_nodeIPvEEEENS1_12uncast_typesIT_E17non_const_pointerERKS9_
	.section	.text._ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC2IS3_EEOT_,"axG",@progbits,_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC5IS3_EEOT_,comdat
	.align 2
	.weak	_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC2IS3_EEOT_
	.type	_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC2IS3_EEOT_, @function
_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC2IS3_EEOT_:
.LFB8149:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS4_E4typeE
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNSt10_Head_baseILm1EPN7simgrid3s4u7MailboxELb0EEC2IS3_EEOT_
	nop
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8149:
	.size	_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC2IS3_EEOT_, .-_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC2IS3_EEOT_
	.weak	_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC1IS3_EEOT_
	.set	_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC1IS3_EEOT_,_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEEC2IS3_EEOT_
	.section	.text._ZNKSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERKT_v,"axG",@progbits,_ZNKSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERKT_v,comdat
	.align 2
	.weak	_ZNKSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERKT_v
	.type	_ZNKSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERKT_v, @function
_ZNKSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERKT_v:
.LFB8153:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt9_Any_data9_M_accessEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8153:
	.size	_ZNKSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERKT_v, .-_ZNKSt9_Any_data9_M_accessIPSt5_BindIFPFvPN7simgrid3s4u7MailboxES5_ES5_S5_EEEERKT_v
	.section	.text._ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE6__callIvJEJLm0ELm1EEEET_OSt5tupleIJDpT0_EESt12_Index_tupleIJXspT1_EEE,"axG",@progbits,_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE6__callIvJEJLm0ELm1EEEET_OSt5tupleIJDpT0_EESt12_Index_tupleIJXspT1_EEE,comdat
	.align 2
	.weak	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE6__callIvJEJLm0ELm1EEEET_OSt5tupleIJDpT0_EESt12_Index_tupleIJXspT1_EEE
	.type	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE6__callIvJEJLm0ELm1EEEET_OSt5tupleIJDpT0_EESt12_Index_tupleIJXspT1_EEE, @function
_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE6__callIvJEJLm0ELm1EEEET_OSt5tupleIJDpT0_EESt12_Index_tupleIJXspT1_EEE:
.LFB8154:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	_ZSt3getILm1EJPN7simgrid3s4u7MailboxES3_EERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_
	movq	%rax, %rcx
	movq	-48(%rbp), %rdx
	leaq	-25(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNVKSt3_MuIPN7simgrid3s4u7MailboxELb0ELb0EEclIRS3_St5tupleIJEEEEOT_SA_RT0_
	movq	%rax, %rbx
	movq	-40(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	_ZSt3getILm0EJPN7simgrid3s4u7MailboxES3_EERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_
	movq	%rax, %rcx
	movq	-48(%rbp), %rdx
	leaq	-26(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNVKSt3_MuIPN7simgrid3s4u7MailboxELb0ELb0EEclIRS3_St5tupleIJEEEEOT_SA_RT0_
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	movq	%rbx, %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZSt8__invokeIRPFvPN7simgrid3s4u7MailboxES3_EJRS3_S7_EENSt15__invoke_resultIT_JDpT0_EE4typeEOS9_DpOSA_
	nop
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L288
	call	__stack_chk_fail@PLT
.L288:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8154:
	.size	_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE6__callIvJEJLm0ELm1EEEET_OSt5tupleIJDpT0_EESt12_Index_tupleIJXspT1_EEE, .-_ZNSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE6__callIvJEJLm0ELm1EEEET_OSt5tupleIJDpT0_EESt12_Index_tupleIJXspT1_EEE
	.section	.text._ZN5boost9intrusive14pointer_traitsIPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEE10pointer_toERSD_,"axG",@progbits,_ZN5boost9intrusive14pointer_traitsIPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEE10pointer_toERSD_,comdat
	.weak	_ZN5boost9intrusive14pointer_traitsIPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEE10pointer_toERSD_
	.type	_ZN5boost9intrusive14pointer_traitsIPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEE10pointer_toERSD_, @function
_ZN5boost9intrusive14pointer_traitsIPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEE10pointer_toERSD_:
.LFB8226:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -56(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-56(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	$0, -16(%rbp)
	movq	-24(%rbp), %rax
	nop
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L294
	call	__stack_chk_fail@PLT
.L294:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8226:
	.size	_ZN5boost9intrusive14pointer_traitsIPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEE10pointer_toERSD_, .-_ZN5boost9intrusive14pointer_traitsIPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEE10pointer_toERSD_
	.section	.text._ZNK5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17priv_value_traitsEv,"axG",@progbits,_ZNK5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17priv_value_traitsEv,comdat
	.align 2
	.weak	_ZNK5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17priv_value_traitsEv
	.type	_ZNK5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17priv_value_traitsEv, @function
_ZNK5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17priv_value_traitsEv:
.LFB8227:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8227:
	.size	_ZNK5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17priv_value_traitsEv, .-_ZNK5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17priv_value_traitsEv
	.section	.text._ZNK5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE7get_ptrEv,"axG",@progbits,_ZNK5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE7get_ptrEv,comdat
	.align 2
	.weak	_ZNK5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE7get_ptrEv
	.type	_ZNK5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE7get_ptrEv, @function
_ZNK5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE7get_ptrEv:
.LFB8228:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8228:
	.size	_ZNK5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE7get_ptrEv, .-_ZNK5boost9intrusive17iiterator_membersIPNS0_9list_nodeIPvEEPKNS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIS3_EELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb0EE7get_ptrEv
	.section	.text._ZN5boost9intrusive14pointer_traitsIPNS0_9list_nodeIPvEEE15const_cast_fromIKS4_EES5_PT_,"axG",@progbits,_ZN5boost9intrusive14pointer_traitsIPNS0_9list_nodeIPvEEE15const_cast_fromIKS4_EES5_PT_,comdat
	.weak	_ZN5boost9intrusive14pointer_traitsIPNS0_9list_nodeIPvEEE15const_cast_fromIKS4_EES5_PT_
	.type	_ZN5boost9intrusive14pointer_traitsIPNS0_9list_nodeIPvEEE15const_cast_fromIKS4_EES5_PT_, @function
_ZN5boost9intrusive14pointer_traitsIPNS0_9list_nodeIPvEEE15const_cast_fromIKS4_EES5_PT_:
.LFB8232:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8232:
	.size	_ZN5boost9intrusive14pointer_traitsIPNS0_9list_nodeIPvEEE15const_cast_fromIKS4_EES5_PT_, .-_ZN5boost9intrusive14pointer_traitsIPNS0_9list_nodeIPvEEE15const_cast_fromIKS4_EES5_PT_
	.section	.text._ZSt3getILm0EJPN7simgrid3s4u7MailboxES3_EERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_,"axG",@progbits,_ZSt3getILm0EJPN7simgrid3s4u7MailboxES3_EERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_,comdat
	.weak	_ZSt3getILm0EJPN7simgrid3s4u7MailboxES3_EERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_
	.type	_ZSt3getILm0EJPN7simgrid3s4u7MailboxES3_EERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_, @function
_ZSt3getILm0EJPN7simgrid3s4u7MailboxES3_EERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_:
.LFB8236:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__get_helperILm0EPN7simgrid3s4u7MailboxEJS3_EERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8236:
	.size	_ZSt3getILm0EJPN7simgrid3s4u7MailboxES3_EERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_, .-_ZSt3getILm0EJPN7simgrid3s4u7MailboxES3_EERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_
	.section	.text._ZNVKSt3_MuIPN7simgrid3s4u7MailboxELb0ELb0EEclIRS3_St5tupleIJEEEEOT_SA_RT0_,"axG",@progbits,_ZNVKSt3_MuIPN7simgrid3s4u7MailboxELb0ELb0EEclIRS3_St5tupleIJEEEEOT_SA_RT0_,comdat
	.align 2
	.weak	_ZNVKSt3_MuIPN7simgrid3s4u7MailboxELb0ELb0EEclIRS3_St5tupleIJEEEEOT_SA_RT0_
	.type	_ZNVKSt3_MuIPN7simgrid3s4u7MailboxELb0ELb0EEclIRS3_St5tupleIJEEEEOT_SA_RT0_, @function
_ZNVKSt3_MuIPN7simgrid3s4u7MailboxELb0ELb0EEclIRS3_St5tupleIJEEEEOT_SA_RT0_:
.LFB8237:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS5_E4typeE
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8237:
	.size	_ZNVKSt3_MuIPN7simgrid3s4u7MailboxELb0ELb0EEclIRS3_St5tupleIJEEEEOT_SA_RT0_, .-_ZNVKSt3_MuIPN7simgrid3s4u7MailboxELb0ELb0EEclIRS3_St5tupleIJEEEEOT_SA_RT0_
	.section	.text._ZSt3getILm1EJPN7simgrid3s4u7MailboxES3_EERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_,"axG",@progbits,_ZSt3getILm1EJPN7simgrid3s4u7MailboxES3_EERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_,comdat
	.weak	_ZSt3getILm1EJPN7simgrid3s4u7MailboxES3_EERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_
	.type	_ZSt3getILm1EJPN7simgrid3s4u7MailboxES3_EERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_, @function
_ZSt3getILm1EJPN7simgrid3s4u7MailboxES3_EERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_:
.LFB8238:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__get_helperILm1EPN7simgrid3s4u7MailboxEJEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8238:
	.size	_ZSt3getILm1EJPN7simgrid3s4u7MailboxES3_EERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_, .-_ZSt3getILm1EJPN7simgrid3s4u7MailboxES3_EERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_
	.section	.text._ZSt7forwardIRPFvPN7simgrid3s4u7MailboxES3_EEOT_RNSt16remove_referenceIS7_E4typeE,"axG",@progbits,_ZSt7forwardIRPFvPN7simgrid3s4u7MailboxES3_EEOT_RNSt16remove_referenceIS7_E4typeE,comdat
	.weak	_ZSt7forwardIRPFvPN7simgrid3s4u7MailboxES3_EEOT_RNSt16remove_referenceIS7_E4typeE
	.type	_ZSt7forwardIRPFvPN7simgrid3s4u7MailboxES3_EEOT_RNSt16remove_referenceIS7_E4typeE, @function
_ZSt7forwardIRPFvPN7simgrid3s4u7MailboxES3_EEOT_RNSt16remove_referenceIS7_E4typeE:
.LFB8240:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8240:
	.size	_ZSt7forwardIRPFvPN7simgrid3s4u7MailboxES3_EEOT_RNSt16remove_referenceIS7_E4typeE, .-_ZSt7forwardIRPFvPN7simgrid3s4u7MailboxES3_EEOT_RNSt16remove_referenceIS7_E4typeE
	.section	.text._ZSt7forwardIRPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS5_E4typeE,"axG",@progbits,_ZSt7forwardIRPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS5_E4typeE,comdat
	.weak	_ZSt7forwardIRPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS5_E4typeE
	.type	_ZSt7forwardIRPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS5_E4typeE, @function
_ZSt7forwardIRPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS5_E4typeE:
.LFB8241:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8241:
	.size	_ZSt7forwardIRPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS5_E4typeE, .-_ZSt7forwardIRPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS5_E4typeE
	.section	.text._ZSt8__invokeIRPFvPN7simgrid3s4u7MailboxES3_EJRS3_S7_EENSt15__invoke_resultIT_JDpT0_EE4typeEOS9_DpOSA_,"axG",@progbits,_ZSt8__invokeIRPFvPN7simgrid3s4u7MailboxES3_EJRS3_S7_EENSt15__invoke_resultIT_JDpT0_EE4typeEOS9_DpOSA_,comdat
	.weak	_ZSt8__invokeIRPFvPN7simgrid3s4u7MailboxES3_EJRS3_S7_EENSt15__invoke_resultIT_JDpT0_EE4typeEOS9_DpOSA_
	.type	_ZSt8__invokeIRPFvPN7simgrid3s4u7MailboxES3_EJRS3_S7_EENSt15__invoke_resultIT_JDpT0_EE4typeEOS9_DpOSA_, @function
_ZSt8__invokeIRPFvPN7simgrid3s4u7MailboxES3_EJRS3_S7_EENSt15__invoke_resultIT_JDpT0_EE4typeEOS9_DpOSA_:
.LFB8239:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 13, -24
	.cfi_offset 12, -32
	.cfi_offset 3, -40
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -40(%rbp)
	xorl	%eax, %eax
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS5_E4typeE
	movq	%rax, %r12
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS5_E4typeE
	movq	%rax, %rbx
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRPFvPN7simgrid3s4u7MailboxES3_EEOT_RNSt16remove_referenceIS7_E4typeE
	subq	$8, %rsp
	pushq	%r13
	movq	%r12, %rdx
	movq	%rbx, %rsi
	movq	%rax, %rdi
	call	_ZSt13__invoke_implIvRPFvPN7simgrid3s4u7MailboxES3_EJRS3_S7_EET_St14__invoke_otherOT0_DpOT1_
	addq	$16, %rsp
	nop
	movq	-40(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L313
	call	__stack_chk_fail@PLT
.L313:
	leaq	-24(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8239:
	.size	_ZSt8__invokeIRPFvPN7simgrid3s4u7MailboxES3_EJRS3_S7_EENSt15__invoke_resultIT_JDpT0_EE4typeEOS9_DpOSA_, .-_ZSt8__invokeIRPFvPN7simgrid3s4u7MailboxES3_EJRS3_S7_EENSt15__invoke_resultIT_JDpT0_EE4typeEOS9_DpOSA_
	.section	.text._ZSt12__get_helperILm0EPN7simgrid3s4u7MailboxEJS3_EERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE,"axG",@progbits,_ZSt12__get_helperILm0EPN7simgrid3s4u7MailboxEJS3_EERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE,comdat
	.weak	_ZSt12__get_helperILm0EPN7simgrid3s4u7MailboxEJS3_EERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE
	.type	_ZSt12__get_helperILm0EPN7simgrid3s4u7MailboxEJS3_EERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE, @function
_ZSt12__get_helperILm0EPN7simgrid3s4u7MailboxEJS3_EERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE:
.LFB8298:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt11_Tuple_implILm0EJPN7simgrid3s4u7MailboxES3_EE7_M_headERS4_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8298:
	.size	_ZSt12__get_helperILm0EPN7simgrid3s4u7MailboxEJS3_EERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE, .-_ZSt12__get_helperILm0EPN7simgrid3s4u7MailboxEJS3_EERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE
	.section	.text._ZSt12__get_helperILm1EPN7simgrid3s4u7MailboxEJEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE,"axG",@progbits,_ZSt12__get_helperILm1EPN7simgrid3s4u7MailboxEJEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE,comdat
	.weak	_ZSt12__get_helperILm1EPN7simgrid3s4u7MailboxEJEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE
	.type	_ZSt12__get_helperILm1EPN7simgrid3s4u7MailboxEJEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE, @function
_ZSt12__get_helperILm1EPN7simgrid3s4u7MailboxEJEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE:
.LFB8299:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt11_Tuple_implILm1EJPN7simgrid3s4u7MailboxEEE7_M_headERS4_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8299:
	.size	_ZSt12__get_helperILm1EPN7simgrid3s4u7MailboxEJEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE, .-_ZSt12__get_helperILm1EPN7simgrid3s4u7MailboxEJEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE
	.section	.text._ZSt13__invoke_implIvRPFvPN7simgrid3s4u7MailboxES3_EJRS3_S7_EET_St14__invoke_otherOT0_DpOT1_,"axG",@progbits,_ZSt13__invoke_implIvRPFvPN7simgrid3s4u7MailboxES3_EJRS3_S7_EET_St14__invoke_otherOT0_DpOT1_,comdat
	.weak	_ZSt13__invoke_implIvRPFvPN7simgrid3s4u7MailboxES3_EJRS3_S7_EET_St14__invoke_otherOT0_DpOT1_
	.type	_ZSt13__invoke_implIvRPFvPN7simgrid3s4u7MailboxES3_EJRS3_S7_EET_St14__invoke_otherOT0_DpOT1_, @function
_ZSt13__invoke_implIvRPFvPN7simgrid3s4u7MailboxES3_EJRS3_S7_EET_St14__invoke_otherOT0_DpOT1_:
.LFB8300:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRPFvPN7simgrid3s4u7MailboxES3_EEOT_RNSt16remove_referenceIS7_E4typeE
	movq	(%rax), %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS5_E4typeE
	movq	(%rax), %r12
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRPN7simgrid3s4u7MailboxEEOT_RNSt16remove_referenceIS5_E4typeE
	movq	(%rax), %rax
	movq	%r12, %rsi
	movq	%rax, %rdi
	call	*%rbx
	nop
	addq	$32, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8300:
	.size	_ZSt13__invoke_implIvRPFvPN7simgrid3s4u7MailboxES3_EJRS3_S7_EET_St14__invoke_otherOT0_DpOT1_, .-_ZSt13__invoke_implIvRPFvPN7simgrid3s4u7MailboxES3_EJRS3_S7_EET_St14__invoke_otherOT0_DpOT1_
	.weak	_ZTISt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE
	.section	.data.rel.ro._ZTISt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE,"awG",@progbits,_ZTISt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE,comdat
	.align 8
	.type	_ZTISt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE, @object
	.size	_ZTISt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE, 24
_ZTISt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTSSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE
	.quad	_ZTISt17_Weak_result_typeIPFvPN7simgrid3s4u7MailboxES3_EE
	.weak	_ZTSSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE
	.section	.rodata._ZTSSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE,"aG",@progbits,_ZTSSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE,comdat
	.align 32
	.type	_ZTSSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE, @object
	.size	_ZTSSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE, 49
_ZTSSt5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE:
	.string	"St5_BindIFPFvPN7simgrid3s4u7MailboxES3_ES3_S3_EE"
	.weak	_ZN7simgrid3xbt10ExtendableINS_3s4u5ActorEE9deleters_E
	.section	.bss._ZN7simgrid3xbt10ExtendableINS_3s4u5ActorEE9deleters_E,"awG",@nobits,_ZN7simgrid3xbt10ExtendableINS_3s4u5ActorEE9deleters_E,comdat
	.align 16
	.type	_ZN7simgrid3xbt10ExtendableINS_3s4u5ActorEE9deleters_E, @gnu_unique_object
	.size	_ZN7simgrid3xbt10ExtendableINS_3s4u5ActorEE9deleters_E, 24
_ZN7simgrid3xbt10ExtendableINS_3s4u5ActorEE9deleters_E:
	.zero	24
	.weak	_ZN7simgrid3xbt10ExtendableINS_3s4u4DiskEE9deleters_E
	.section	.bss._ZN7simgrid3xbt10ExtendableINS_3s4u4DiskEE9deleters_E,"awG",@nobits,_ZN7simgrid3xbt10ExtendableINS_3s4u4DiskEE9deleters_E,comdat
	.align 16
	.type	_ZN7simgrid3xbt10ExtendableINS_3s4u4DiskEE9deleters_E, @gnu_unique_object
	.size	_ZN7simgrid3xbt10ExtendableINS_3s4u4DiskEE9deleters_E, 24
_ZN7simgrid3xbt10ExtendableINS_3s4u4DiskEE9deleters_E:
	.zero	24
	.weak	_ZN7simgrid3xbt10ExtendableINS_3s4u4LinkEE9deleters_E
	.section	.bss._ZN7simgrid3xbt10ExtendableINS_3s4u4LinkEE9deleters_E,"awG",@nobits,_ZN7simgrid3xbt10ExtendableINS_3s4u4LinkEE9deleters_E,comdat
	.align 16
	.type	_ZN7simgrid3xbt10ExtendableINS_3s4u4LinkEE9deleters_E, @gnu_unique_object
	.size	_ZN7simgrid3xbt10ExtendableINS_3s4u4LinkEE9deleters_E, 24
_ZN7simgrid3xbt10ExtendableINS_3s4u4LinkEE9deleters_E:
	.zero	24
	.weak	_ZGVN7simgrid3xbt10ExtendableINS_3s4u5ActorEE9deleters_E
	.section	.bss._ZGVN7simgrid3xbt10ExtendableINS_3s4u5ActorEE9deleters_E,"awG",@nobits,_ZGVN7simgrid3xbt10ExtendableINS_3s4u5ActorEE9deleters_E,comdat
	.align 8
	.type	_ZGVN7simgrid3xbt10ExtendableINS_3s4u5ActorEE9deleters_E, @gnu_unique_object
	.size	_ZGVN7simgrid3xbt10ExtendableINS_3s4u5ActorEE9deleters_E, 8
_ZGVN7simgrid3xbt10ExtendableINS_3s4u5ActorEE9deleters_E:
	.zero	8
	.weak	_ZGVN7simgrid3xbt10ExtendableINS_3s4u4DiskEE9deleters_E
	.section	.bss._ZGVN7simgrid3xbt10ExtendableINS_3s4u4DiskEE9deleters_E,"awG",@nobits,_ZGVN7simgrid3xbt10ExtendableINS_3s4u4DiskEE9deleters_E,comdat
	.align 8
	.type	_ZGVN7simgrid3xbt10ExtendableINS_3s4u4DiskEE9deleters_E, @gnu_unique_object
	.size	_ZGVN7simgrid3xbt10ExtendableINS_3s4u4DiskEE9deleters_E, 8
_ZGVN7simgrid3xbt10ExtendableINS_3s4u4DiskEE9deleters_E:
	.zero	8
	.weak	_ZGVN7simgrid3xbt10ExtendableINS_3s4u4LinkEE9deleters_E
	.section	.bss._ZGVN7simgrid3xbt10ExtendableINS_3s4u4LinkEE9deleters_E,"awG",@nobits,_ZGVN7simgrid3xbt10ExtendableINS_3s4u4LinkEE9deleters_E,comdat
	.align 8
	.type	_ZGVN7simgrid3xbt10ExtendableINS_3s4u4LinkEE9deleters_E, @gnu_unique_object
	.size	_ZGVN7simgrid3xbt10ExtendableINS_3s4u4LinkEE9deleters_E, 8
_ZGVN7simgrid3xbt10ExtendableINS_3s4u4LinkEE9deleters_E:
	.zero	8
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB8459:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 13, -24
	.cfi_offset 12, -32
	.cfi_offset 3, -40
	movl	%edi, -52(%rbp)
	movl	%esi, -56(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -40(%rbp)
	xorl	%eax, %eax
	cmpl	$1, -52(%rbp)
	jne	.L325
	cmpl	$65535, -56(%rbp)
	jne	.L325
	leaq	-41(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZN7simgrid5simixL12simix_timersE(%rip), %rdi
	call	_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_EC1ERKSB_
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZN7simgrid5simixL12simix_timersE(%rip), %rsi
	leaq	_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_ED1Ev(%rip), %rdi
	call	__cxa_atexit@PLT
	subq	$8, %rsp
	pushq	%r13
	leaq	_ZN5boostL4noneE(%rip), %rdi
	call	_ZN5boost6none_tC1ENS0_8init_tagE
	addq	$16, %rsp
	subq	$8, %rsp
	pushq	%r12
	leaq	_ZN5boost11optional_nsL13in_place_initE(%rip), %rdi
	call	_ZN5boost11optional_ns15in_place_init_tC1ENS1_8init_tagE
	addq	$16, %rsp
	subq	$8, %rsp
	pushq	%rbx
	leaq	_ZN5boost11optional_nsL16in_place_init_ifE(%rip), %rdi
	call	_ZN5boost11optional_ns18in_place_init_if_tC1ENS1_8init_tagE
	addq	$16, %rsp
	leaq	_ZGVN7simgrid3xbt10ExtendableINS_3s4u5ActorEE9deleters_E(%rip), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L322
	leaq	_ZGVN7simgrid3xbt10ExtendableINS_3s4u5ActorEE9deleters_E(%rip), %rax
	movb	$1, (%rax)
	leaq	_ZN7simgrid3xbt10ExtendableINS_3s4u5ActorEE9deleters_E(%rip), %rdi
	call	_ZNSt6vectorIPFvPvESaIS2_EEC1Ev
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZN7simgrid3xbt10ExtendableINS_3s4u5ActorEE9deleters_E(%rip), %rsi
	leaq	_ZNSt6vectorIPFvPvESaIS2_EED1Ev(%rip), %rdi
	call	__cxa_atexit@PLT
.L322:
	leaq	_ZGVN7simgrid3xbt10ExtendableINS_3s4u4DiskEE9deleters_E(%rip), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L323
	leaq	_ZGVN7simgrid3xbt10ExtendableINS_3s4u4DiskEE9deleters_E(%rip), %rax
	movb	$1, (%rax)
	leaq	_ZN7simgrid3xbt10ExtendableINS_3s4u4DiskEE9deleters_E(%rip), %rdi
	call	_ZNSt6vectorIPFvPvESaIS2_EEC1Ev
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZN7simgrid3xbt10ExtendableINS_3s4u4DiskEE9deleters_E(%rip), %rsi
	leaq	_ZNSt6vectorIPFvPvESaIS2_EED1Ev(%rip), %rdi
	call	__cxa_atexit@PLT
.L323:
	leaq	_ZGVN7simgrid3xbt10ExtendableINS_3s4u4LinkEE9deleters_E(%rip), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L325
	leaq	_ZGVN7simgrid3xbt10ExtendableINS_3s4u4LinkEE9deleters_E(%rip), %rax
	movb	$1, (%rax)
	leaq	_ZN7simgrid3xbt10ExtendableINS_3s4u4LinkEE9deleters_E(%rip), %rdi
	call	_ZNSt6vectorIPFvPvESaIS2_EEC1Ev
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZN7simgrid3xbt10ExtendableINS_3s4u4LinkEE9deleters_E(%rip), %rsi
	leaq	_ZNSt6vectorIPFvPvESaIS2_EED1Ev(%rip), %rdi
	call	__cxa_atexit@PLT
.L325:
	nop
	movq	-40(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L324
	call	__stack_chk_fail@PLT
.L324:
	leaq	-24(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8459:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.section	.text._ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_ED2Ev,"axG",@progbits,_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_ED5Ev,comdat
	.align 2
	.weak	_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_ED2Ev
	.type	_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_ED2Ev, @function
_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_ED2Ev:
.LFB8479:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA8479
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_E5clearEv
	movq	-8(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEEvvvvED1Ev
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost4heap6detail24make_fibonacci_heap_baseISt4pairIdPN7simgrid5simix5TimerEENS_9parameter3aux8arg_listINS0_7compareINS4_3xbt14HeapComparatorIS8_EEEENSA_14empty_arg_listEEEE4typeD2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8479:
	.section	.gcc_except_table
.LLSDA8479:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8479-.LLSDACSB8479
.LLSDACSB8479:
.LLSDACSE8479:
	.section	.text._ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_ED2Ev,"axG",@progbits,_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_ED5Ev,comdat
	.size	_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_ED2Ev, .-_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_ED2Ev
	.weak	_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_ED1Ev
	.set	_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_ED1Ev,_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_ED2Ev
	.section	.text._ZNSt6vectorIPFvPvESaIS2_EED2Ev,"axG",@progbits,_ZNSt6vectorIPFvPvESaIS2_EED5Ev,comdat
	.align 2
	.weak	_ZNSt6vectorIPFvPvESaIS2_EED2Ev
	.type	_ZNSt6vectorIPFvPvESaIS2_EED2Ev, @function
_ZNSt6vectorIPFvPvESaIS2_EED2Ev:
.LFB8482:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA8482
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPFvPvESaIS2_EE19_M_get_Tp_allocatorEv
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	8(%rax), %rcx
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZSt8_DestroyIPPFvPvES2_EvT_S4_RSaIT0_E
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPFvPvESaIS2_EED2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8482:
	.section	.gcc_except_table
.LLSDA8482:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8482-.LLSDACSB8482
.LLSDACSB8482:
.LLSDACSE8482:
	.section	.text._ZNSt6vectorIPFvPvESaIS2_EED2Ev,"axG",@progbits,_ZNSt6vectorIPFvPvESaIS2_EED5Ev,comdat
	.size	_ZNSt6vectorIPFvPvESaIS2_EED2Ev, .-_ZNSt6vectorIPFvPvESaIS2_EED2Ev
	.weak	_ZNSt6vectorIPFvPvESaIS2_EED1Ev
	.set	_ZNSt6vectorIPFvPvESaIS2_EED1Ev,_ZNSt6vectorIPFvPvESaIS2_EED2Ev
	.section	.text._ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_E5clearEv,"axG",@progbits,_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_E5clearEv,comdat
	.align 2
	.weak	_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_E5clearEv
	.type	_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_E5clearEv, @function
_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_E5clearEv:
.LFB8494:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	leaq	16(%rax), %rbx
	movq	-40(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost4heap6detail13node_disposerINS1_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEENS1_14heap_node_baseILb0EEESaISA_EEC1ERSD_
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS4_13node_disposerINS4_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEES6_SaISN_EEEEEvT_
	movq	-40(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	_ZN5boost4heap6detail11size_holderILb1EmE8set_sizeEm
	movq	-40(%rbp), %rax
	movq	$0, 8(%rax)
	nop
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L329
	call	__stack_chk_fail@PLT
.L329:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8494:
	.size	_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_E5clearEv, .-_ZN5boost4heap14fibonacci_heapISt4pairIdPN7simgrid5simix5TimerEENS0_7compareINS3_3xbt14HeapComparatorIS7_EEEENS_9parameter5void_ESE_SE_SE_E5clearEv
	.section	.text._ZNSt12_Vector_baseIPFvPvESaIS2_EE19_M_get_Tp_allocatorEv,"axG",@progbits,_ZNSt12_Vector_baseIPFvPvESaIS2_EE19_M_get_Tp_allocatorEv,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIPFvPvESaIS2_EE19_M_get_Tp_allocatorEv
	.type	_ZNSt12_Vector_baseIPFvPvESaIS2_EE19_M_get_Tp_allocatorEv, @function
_ZNSt12_Vector_baseIPFvPvESaIS2_EE19_M_get_Tp_allocatorEv:
.LFB8495:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8495:
	.size	_ZNSt12_Vector_baseIPFvPvESaIS2_EE19_M_get_Tp_allocatorEv, .-_ZNSt12_Vector_baseIPFvPvESaIS2_EE19_M_get_Tp_allocatorEv
	.section	.text._ZSt8_DestroyIPPFvPvES2_EvT_S4_RSaIT0_E,"axG",@progbits,_ZSt8_DestroyIPPFvPvES2_EvT_S4_RSaIT0_E,comdat
	.weak	_ZSt8_DestroyIPPFvPvES2_EvT_S4_RSaIT0_E
	.type	_ZSt8_DestroyIPPFvPvES2_EvT_S4_RSaIT0_E, @function
_ZSt8_DestroyIPPFvPvES2_EvT_S4_RSaIT0_E:
.LFB8496:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt8_DestroyIPPFvPvEEvT_S4_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8496:
	.size	_ZSt8_DestroyIPPFvPvES2_EvT_S4_RSaIT0_E, .-_ZSt8_DestroyIPPFvPvES2_EvT_S4_RSaIT0_E
	.section	.text._ZN5boost4heap6detail13node_disposerINS1_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEENS1_14heap_node_baseILb0EEESaISA_EEC2ERSD_,"axG",@progbits,_ZN5boost4heap6detail13node_disposerINS1_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEENS1_14heap_node_baseILb0EEESaISA_EEC5ERSD_,comdat
	.align 2
	.weak	_ZN5boost4heap6detail13node_disposerINS1_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEENS1_14heap_node_baseILb0EEESaISA_EEC2ERSD_
	.type	_ZN5boost4heap6detail13node_disposerINS1_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEENS1_14heap_node_baseILb0EEESaISA_EEC2ERSD_, @function
_ZN5boost4heap6detail13node_disposerINS1_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEENS1_14heap_node_baseILb0EEESaISA_EEC2ERSD_:
.LFB8502:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8502:
	.size	_ZN5boost4heap6detail13node_disposerINS1_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEENS1_14heap_node_baseILb0EEESaISA_EEC2ERSD_, .-_ZN5boost4heap6detail13node_disposerINS1_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEENS1_14heap_node_baseILb0EEESaISA_EEC2ERSD_
	.weak	_ZN5boost4heap6detail13node_disposerINS1_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEENS1_14heap_node_baseILb0EEESaISA_EEC1ERSD_
	.set	_ZN5boost4heap6detail13node_disposerINS1_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEENS1_14heap_node_baseILb0EEESaISA_EEC1ERSD_,_ZN5boost4heap6detail13node_disposerINS1_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEENS1_14heap_node_baseILb0EEESaISA_EEC2ERSD_
	.section	.text._ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS4_13node_disposerINS4_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEES6_SaISN_EEEEEvT_,"axG",@progbits,_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS4_13node_disposerINS4_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEES6_SaISN_EEEEEvT_,comdat
	.align 2
	.weak	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS4_13node_disposerINS4_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEES6_SaISN_EEEEEvT_
	.type	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS4_13node_disposerINS4_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEES6_SaISN_EEEEEvT_, @function
_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS4_13node_disposerINS4_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEES6_SaISN_EEEEEvT_:
.LFB8504:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-16(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE5beginEv
	leaq	-16(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEC1ERKNS1_ISC_Lb0EEE
	leaq	-16(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE3endEv
	leaq	-16(%rbp), %rdx
	leaq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEC1ERKNS1_ISC_Lb0EEE
.L336:
	leaq	-24(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusiveneERKNS0_13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEESF_
	testb	%al, %al
	je	.L335
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EE12pointed_nodeEv
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEppEv
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE4initERKPNS0_9list_nodeIS3_EE
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17priv_value_traitsEv
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive13bhtraits_baseINS_4heap6detail14heap_node_baseILb0EEEPNS0_9list_nodeIPvEENS0_7dft_tagELj1EE12to_value_ptrERKS9_
	movq	%rax, %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost4heap6detail13node_disposerINS1_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEENS1_14heap_node_baseILb0EEESaISA_EEclEPSC_
	jmp	.L336
.L335:
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE13get_root_nodeEv
	movq	%rax, -16(%rbp)
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE11init_headerERKPNS0_9list_nodeIS3_EE
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE16priv_size_traitsEv
	movl	$0, %esi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive6detail11size_holderILb1EmvE8set_sizeEm
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L337
	call	__stack_chk_fail@PLT
.L337:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8504:
	.size	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS4_13node_disposerINS4_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEES6_SaISN_EEEEEvT_, .-_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS4_13node_disposerINS4_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEES6_SaISN_EEEEEvT_
	.section	.text._ZN5boost4heap6detail11size_holderILb1EmE8set_sizeEm,"axG",@progbits,_ZN5boost4heap6detail11size_holderILb1EmE8set_sizeEm,comdat
	.align 2
	.weak	_ZN5boost4heap6detail11size_holderILb1EmE8set_sizeEm
	.type	_ZN5boost4heap6detail11size_holderILb1EmE8set_sizeEm, @function
_ZN5boost4heap6detail11size_holderILb1EmE8set_sizeEm:
.LFB8505:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8505:
	.size	_ZN5boost4heap6detail11size_holderILb1EmE8set_sizeEm, .-_ZN5boost4heap6detail11size_holderILb1EmE8set_sizeEm
	.section	.text._ZSt8_DestroyIPPFvPvEEvT_S4_,"axG",@progbits,_ZSt8_DestroyIPPFvPvEEvT_S4_,comdat
	.weak	_ZSt8_DestroyIPPFvPvEEvT_S4_
	.type	_ZSt8_DestroyIPPFvPvEEvT_S4_, @function
_ZSt8_DestroyIPPFvPvEEvT_S4_:
.LFB8506:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Destroy_auxILb1EE9__destroyIPPFvPvEEEvT_S6_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8506:
	.size	_ZSt8_DestroyIPPFvPvEEvT_S4_, .-_ZSt8_DestroyIPPFvPvEEvT_S4_
	.section	.text._ZN5boost4heap6detail13node_disposerINS1_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEENS1_14heap_node_baseILb0EEESaISA_EEclEPSC_,"axG",@progbits,_ZN5boost4heap6detail13node_disposerINS1_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEENS1_14heap_node_baseILb0EEESaISA_EEclEPSC_,comdat
	.align 2
	.weak	_ZN5boost4heap6detail13node_disposerINS1_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEENS1_14heap_node_baseILb0EEESaISA_EEclEPSC_
	.type	_ZN5boost4heap6detail13node_disposerINS1_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEENS1_14heap_node_baseILb0EEESaISA_EEclEPSC_, @function
_ZN5boost4heap6detail13node_disposerINS1_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEENS1_14heap_node_baseILb0EEESaISA_EEclEPSC_:
.LFB8507:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EE13clear_subtreeISaINS1_16marked_heap_nodeIS8_EEEEEvRT_
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEE7destroyISB_EEvPT_
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	movl	$1, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEE10deallocateEPSB_m
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8507:
	.size	_ZN5boost4heap6detail13node_disposerINS1_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEENS1_14heap_node_baseILb0EEESaISA_EEclEPSC_, .-_ZN5boost4heap6detail13node_disposerINS1_16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEENS1_14heap_node_baseILb0EEESaISA_EEclEPSC_
	.section	.text._ZNSt12_Destroy_auxILb1EE9__destroyIPPFvPvEEEvT_S6_,"axG",@progbits,_ZNSt12_Destroy_auxILb1EE9__destroyIPPFvPvEEEvT_S6_,comdat
	.weak	_ZNSt12_Destroy_auxILb1EE9__destroyIPPFvPvEEEvT_S6_
	.type	_ZNSt12_Destroy_auxILb1EE9__destroyIPPFvPvEEEvT_S6_, @function
_ZNSt12_Destroy_auxILb1EE9__destroyIPPFvPvEEEvT_S6_:
.LFB8508:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8508:
	.size	_ZNSt12_Destroy_auxILb1EE9__destroyIPPFvPvEEEvT_S6_, .-_ZNSt12_Destroy_auxILb1EE9__destroyIPPFvPvEEEvT_S6_
	.section	.text._ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EE13clear_subtreeISaINS1_16marked_heap_nodeIS8_EEEEEvRT_,"axG",@progbits,_ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EE13clear_subtreeISaINS1_16marked_heap_nodeIS8_EEEEEvRT_,comdat
	.align 2
	.weak	_ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EE13clear_subtreeISaINS1_16marked_heap_nodeIS8_EEEEEvRT_
	.type	_ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EE13clear_subtreeISaINS1_16marked_heap_nodeIS8_EEEEEvRT_, @function
_ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EE13clear_subtreeISaINS1_16marked_heap_nodeIS8_EEEEEvRT_:
.LFB8509:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	leaq	32(%rax), %rbx
	movq	-48(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost4heap6detail13node_disposerINS1_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEENS1_14heap_node_baseILb0EEESaINS1_16marked_heap_nodeIS9_EEEEC1ERSF_
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS4_13node_disposerINS4_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEES6_SaINS4_16marked_heap_nodeISM_EEEEEEEvT_
	nop
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L343
	call	__stack_chk_fail@PLT
.L343:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8509:
	.size	_ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EE13clear_subtreeISaINS1_16marked_heap_nodeIS8_EEEEEvRT_, .-_ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EE13clear_subtreeISaINS1_16marked_heap_nodeIS8_EEEEEvRT_
	.section	.text._ZN5boost9intrusive14list_base_hookINS0_9link_modeILNS0_14link_mode_typeE1EEEvvED2Ev,"axG",@progbits,_ZN5boost9intrusive14list_base_hookINS0_9link_modeILNS0_14link_mode_typeE1EEEvvED5Ev,comdat
	.align 2
	.weak	_ZN5boost9intrusive14list_base_hookINS0_9link_modeILNS0_14link_mode_typeE1EEEvvED2Ev
	.type	_ZN5boost9intrusive14list_base_hookINS0_9link_modeILNS0_14link_mode_typeE1EEEvvED2Ev, @function
_ZN5boost9intrusive14list_base_hookINS0_9link_modeILNS0_14link_mode_typeE1EEEvvED2Ev:
.LFB8516:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EED2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8516:
	.size	_ZN5boost9intrusive14list_base_hookINS0_9link_modeILNS0_14link_mode_typeE1EEEvvED2Ev, .-_ZN5boost9intrusive14list_base_hookINS0_9link_modeILNS0_14link_mode_typeE1EEEvvED2Ev
	.weak	_ZN5boost9intrusive14list_base_hookINS0_9link_modeILNS0_14link_mode_typeE1EEEvvED1Ev
	.set	_ZN5boost9intrusive14list_base_hookINS0_9link_modeILNS0_14link_mode_typeE1EEEvvED1Ev,_ZN5boost9intrusive14list_base_hookINS0_9link_modeILNS0_14link_mode_typeE1EEEvvED2Ev
	.section	.text._ZN5boost4heap6detail14heap_node_baseILb0EED2Ev,"axG",@progbits,_ZN5boost4heap6detail14heap_node_baseILb0EED5Ev,comdat
	.align 2
	.weak	_ZN5boost4heap6detail14heap_node_baseILb0EED2Ev
	.type	_ZN5boost4heap6detail14heap_node_baseILb0EED2Ev, @function
_ZN5boost4heap6detail14heap_node_baseILb0EED2Ev:
.LFB8518:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive14list_base_hookINS0_9link_modeILNS0_14link_mode_typeE1EEEvvED2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8518:
	.size	_ZN5boost4heap6detail14heap_node_baseILb0EED2Ev, .-_ZN5boost4heap6detail14heap_node_baseILb0EED2Ev
	.weak	_ZN5boost4heap6detail14heap_node_baseILb0EED1Ev
	.set	_ZN5boost4heap6detail14heap_node_baseILb0EED1Ev,_ZN5boost4heap6detail14heap_node_baseILb0EED2Ev
	.section	.text._ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEENS0_18constant_time_sizeILb1EEEvvvED2Ev,"axG",@progbits,_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEENS0_18constant_time_sizeILb1EEEvvvED5Ev,comdat
	.align 2
	.weak	_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEENS0_18constant_time_sizeILb1EEEvvvED2Ev
	.type	_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEENS0_18constant_time_sizeILb1EEEvvvED2Ev, @function
_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEENS0_18constant_time_sizeILb1EEEvvvED2Ev:
.LFB8521:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvED2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8521:
	.size	_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEENS0_18constant_time_sizeILb1EEEvvvED2Ev, .-_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEENS0_18constant_time_sizeILb1EEEvvvED2Ev
	.weak	_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEENS0_18constant_time_sizeILb1EEEvvvED1Ev
	.set	_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEENS0_18constant_time_sizeILb1EEEvvvED1Ev,_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEENS0_18constant_time_sizeILb1EEEvvvED2Ev
	.section	.text._ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EED2Ev,"axG",@progbits,_ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EED5Ev,comdat
	.align 2
	.weak	_ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EED2Ev
	.type	_ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EED2Ev, @function
_ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EED2Ev:
.LFB8523:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$32, %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive4listINS_4heap6detail14heap_node_baseILb0EEENS0_18constant_time_sizeILb1EEEvvvED1Ev
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost4heap6detail14heap_node_baseILb0EED2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8523:
	.size	_ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EED2Ev, .-_ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EED2Ev
	.weak	_ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EED1Ev
	.set	_ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EED1Ev,_ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EED2Ev
	.section	.text._ZN5boost4heap6detail25parent_pointing_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED2Ev,"axG",@progbits,_ZN5boost4heap6detail25parent_pointing_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED5Ev,comdat
	.align 2
	.weak	_ZN5boost4heap6detail25parent_pointing_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED2Ev
	.type	_ZN5boost4heap6detail25parent_pointing_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED2Ev, @function
_ZN5boost4heap6detail25parent_pointing_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED2Ev:
.LFB8525:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EED2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8525:
	.size	_ZN5boost4heap6detail25parent_pointing_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED2Ev, .-_ZN5boost4heap6detail25parent_pointing_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED2Ev
	.weak	_ZN5boost4heap6detail25parent_pointing_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED1Ev
	.set	_ZN5boost4heap6detail25parent_pointing_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED1Ev,_ZN5boost4heap6detail25parent_pointing_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED2Ev
	.section	.text._ZN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED2Ev,"axG",@progbits,_ZN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED5Ev,comdat
	.align 2
	.weak	_ZN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED2Ev
	.type	_ZN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED2Ev, @function
_ZN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED2Ev:
.LFB8527:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost4heap6detail25parent_pointing_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8527:
	.size	_ZN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED2Ev, .-_ZN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED2Ev
	.weak	_ZN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED1Ev
	.set	_ZN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED1Ev,_ZN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED2Ev
	.section	.text._ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEE7destroyISB_EEvPT_,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEE7destroyISB_EEvPT_,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEE7destroyISB_EEvPT_
	.type	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEE7destroyISB_EEvPT_, @function
_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEE7destroyISB_EEvPT_:
.LFB8510:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEED1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8510:
	.size	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEE7destroyISB_EEvPT_, .-_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEE7destroyISB_EEvPT_
	.section	.text._ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEE10deallocateEPSB_m,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEE10deallocateEPSB_m,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEE10deallocateEPSB_m
	.type	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEE10deallocateEPSB_m, @function
_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEE10deallocateEPSB_m:
.LFB8529:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZdlPv@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8529:
	.size	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEE10deallocateEPSB_m, .-_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEE10deallocateEPSB_m
	.section	.text._ZN5boost4heap6detail13node_disposerINS1_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEENS1_14heap_node_baseILb0EEESaINS1_16marked_heap_nodeIS9_EEEEC2ERSF_,"axG",@progbits,_ZN5boost4heap6detail13node_disposerINS1_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEENS1_14heap_node_baseILb0EEESaINS1_16marked_heap_nodeIS9_EEEEC5ERSF_,comdat
	.align 2
	.weak	_ZN5boost4heap6detail13node_disposerINS1_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEENS1_14heap_node_baseILb0EEESaINS1_16marked_heap_nodeIS9_EEEEC2ERSF_
	.type	_ZN5boost4heap6detail13node_disposerINS1_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEENS1_14heap_node_baseILb0EEESaINS1_16marked_heap_nodeIS9_EEEEC2ERSF_, @function
_ZN5boost4heap6detail13node_disposerINS1_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEENS1_14heap_node_baseILb0EEESaINS1_16marked_heap_nodeIS9_EEEEC2ERSF_:
.LFB8531:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8531:
	.size	_ZN5boost4heap6detail13node_disposerINS1_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEENS1_14heap_node_baseILb0EEESaINS1_16marked_heap_nodeIS9_EEEEC2ERSF_, .-_ZN5boost4heap6detail13node_disposerINS1_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEENS1_14heap_node_baseILb0EEESaINS1_16marked_heap_nodeIS9_EEEEC2ERSF_
	.weak	_ZN5boost4heap6detail13node_disposerINS1_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEENS1_14heap_node_baseILb0EEESaINS1_16marked_heap_nodeIS9_EEEEC1ERSF_
	.set	_ZN5boost4heap6detail13node_disposerINS1_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEENS1_14heap_node_baseILb0EEESaINS1_16marked_heap_nodeIS9_EEEEC1ERSF_,_ZN5boost4heap6detail13node_disposerINS1_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEENS1_14heap_node_baseILb0EEESaINS1_16marked_heap_nodeIS9_EEEEC2ERSF_
	.section	.text._ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS4_13node_disposerINS4_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEES6_SaINS4_16marked_heap_nodeISM_EEEEEEEvT_,"axG",@progbits,_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS4_13node_disposerINS4_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEES6_SaINS4_16marked_heap_nodeISM_EEEEEEEvT_,comdat
	.align 2
	.weak	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS4_13node_disposerINS4_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEES6_SaINS4_16marked_heap_nodeISM_EEEEEEEvT_
	.type	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS4_13node_disposerINS4_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEES6_SaINS4_16marked_heap_nodeISM_EEEEEEEvT_, @function
_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS4_13node_disposerINS4_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEES6_SaINS4_16marked_heap_nodeISM_EEEEEEEvT_:
.LFB8533:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-16(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE5beginEv
	leaq	-16(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEC1ERKNS1_ISC_Lb0EEE
	leaq	-16(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE3endEv
	leaq	-16(%rbp), %rdx
	leaq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEC1ERKNS1_ISC_Lb0EEE
.L355:
	leaq	-24(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost9intrusiveneERKNS0_13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEESF_
	testb	%al, %al
	je	.L354
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EE12pointed_nodeEv
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive13list_iteratorINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEELb1EEppEv
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE4initERKPNS0_9list_nodeIS3_EE
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17priv_value_traitsEv
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive13bhtraits_baseINS_4heap6detail14heap_node_baseILb0EEEPNS0_9list_nodeIPvEENS0_7dft_tagELj1EE12to_value_ptrERKS9_
	movq	%rax, %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost4heap6detail13node_disposerINS1_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEENS1_14heap_node_baseILb0EEESaINS1_16marked_heap_nodeIS9_EEEEclEPSC_
	jmp	.L355
.L354:
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE13get_root_nodeEv
	movq	%rax, -16(%rbp)
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE11init_headerERKPNS0_9list_nodeIS3_EE
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE16priv_size_traitsEv
	movl	$0, %esi
	movq	%rax, %rdi
	call	_ZN5boost9intrusive6detail11size_holderILb1EmvE8set_sizeEm
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L356
	call	__stack_chk_fail@PLT
.L356:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8533:
	.size	_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS4_13node_disposerINS4_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEES6_SaINS4_16marked_heap_nodeISM_EEEEEEEvT_, .-_ZN5boost9intrusive9list_implINS0_8bhtraitsINS_4heap6detail14heap_node_baseILb0EEENS0_16list_node_traitsIPvEELNS0_14link_mode_typeE1ENS0_7dft_tagELj1EEEmLb1EvE17clear_and_disposeINS4_13node_disposerINS4_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEES6_SaINS4_16marked_heap_nodeISM_EEEEEEEvT_
	.section	.text._ZN5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EED2Ev,"axG",@progbits,_ZN5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EED5Ev,comdat
	.align 2
	.weak	_ZN5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EED2Ev
	.type	_ZN5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EED2Ev, @function
_ZN5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EED2Ev:
.LFB8535:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA8535
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-24(%rbp), %rax
	subq	$8, %rsp
	pushq	%rdx
	movq	%rax, %rdi
	call	_ZN5boost9intrusive6detail15destructor_implINS0_12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EEEEEvRT_NS1_13link_dispatchILS9_1EEE
	addq	$16, %rsp
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L358
	call	__stack_chk_fail@PLT
.L358:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8535:
	.section	.gcc_except_table
.LLSDA8535:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8535-.LLSDACSB8535
.LLSDACSB8535:
.LLSDACSE8535:
	.section	.text._ZN5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EED2Ev,"axG",@progbits,_ZN5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EED5Ev,comdat
	.size	_ZN5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EED2Ev, .-_ZN5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EED2Ev
	.weak	_ZN5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EED1Ev
	.set	_ZN5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EED1Ev,_ZN5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EED2Ev
	.section	.text._ZN5boost4heap6detail13node_disposerINS1_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEENS1_14heap_node_baseILb0EEESaINS1_16marked_heap_nodeIS9_EEEEclEPSC_,"axG",@progbits,_ZN5boost4heap6detail13node_disposerINS1_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEENS1_14heap_node_baseILb0EEESaINS1_16marked_heap_nodeIS9_EEEEclEPSC_,comdat
	.align 2
	.weak	_ZN5boost4heap6detail13node_disposerINS1_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEENS1_14heap_node_baseILb0EEESaINS1_16marked_heap_nodeIS9_EEEEclEPSC_
	.type	_ZN5boost4heap6detail13node_disposerINS1_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEENS1_14heap_node_baseILb0EEESaINS1_16marked_heap_nodeIS9_EEEEclEPSC_, @function
_ZN5boost4heap6detail13node_disposerINS1_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEENS1_14heap_node_baseILb0EEESaINS1_16marked_heap_nodeIS9_EEEEclEPSC_:
.LFB8537:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5boost4heap6detail9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EE13clear_subtreeISaINS1_16marked_heap_nodeIS8_EEEEEvRT_
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEE7destroyISB_EEvPT_
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	movl	$1, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorIN5boost4heap6detail16marked_heap_nodeISt4pairIdPN7simgrid5simix5TimerEEEEE10deallocateEPSB_m
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8537:
	.size	_ZN5boost4heap6detail13node_disposerINS1_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEENS1_14heap_node_baseILb0EEESaINS1_16marked_heap_nodeIS9_EEEEclEPSC_, .-_ZN5boost4heap6detail13node_disposerINS1_9heap_nodeISt4pairIdPN7simgrid5simix5TimerEELb1EEENS1_14heap_node_baseILb0EEESaINS1_16marked_heap_nodeIS9_EEEEclEPSC_
	.section	.rodata
	.align 8
.LC19:
	.string	"/usr/include/boost/intrusive/detail/generic_hook.hpp"
.LC20:
	.string	"!hook.is_linked()"
	.section	.text._ZN5boost9intrusive6detail15destructor_implINS0_12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EEEEEvRT_NS1_13link_dispatchILS9_1EEE,"axG",@progbits,_ZN5boost9intrusive6detail15destructor_implINS0_12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EEEEEvRT_NS1_13link_dispatchILS9_1EEE,comdat
	.weak	_ZN5boost9intrusive6detail15destructor_implINS0_12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EEEEEvRT_NS1_13link_dispatchILS9_1EEE
	.type	_ZN5boost9intrusive6detail15destructor_implINS0_12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EEEEEvRT_NS1_13link_dispatchILS9_1EEE, @function
_ZN5boost9intrusive6detail15destructor_implINS0_12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EEEEEvRT_NS1_13link_dispatchILS9_1EEE:
.LFB8538:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EE9is_linkedEv
	xorl	$1, %eax
	testb	%al, %al
	jne	.L362
	leaq	_ZZN5boost9intrusive6detail15destructor_implINS0_12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EEEEEvRT_NS1_13link_dispatchILS9_1EEEE19__PRETTY_FUNCTION__(%rip), %rcx
	movl	$48, %edx
	leaq	.LC19(%rip), %rsi
	leaq	.LC20(%rip), %rdi
	call	__assert_fail@PLT
.L362:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8538:
	.size	_ZN5boost9intrusive6detail15destructor_implINS0_12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EEEEEvRT_NS1_13link_dispatchILS9_1EEE, .-_ZN5boost9intrusive6detail15destructor_implINS0_12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EEEEEvRT_NS1_13link_dispatchILS9_1EEE
	.section	.text._ZNK5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EE9is_linkedEv,"axG",@progbits,_ZNK5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EE9is_linkedEv,comdat
	.align 2
	.weak	_ZNK5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EE9is_linkedEv
	.type	_ZNK5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EE9is_linkedEv, @function
_ZNK5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EE9is_linkedEv:
.LFB8539:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EE8this_ptrEv
	movq	%rax, -16(%rbp)
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive24circular_list_algorithmsINS0_16list_node_traitsIPvEEE6uniqueERKPKNS0_9list_nodeIS3_EE
	xorl	$1, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L365
	call	__stack_chk_fail@PLT
.L365:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8539:
	.size	_ZNK5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EE9is_linkedEv, .-_ZNK5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EE9is_linkedEv
	.section	.text._ZNK5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EE8this_ptrEv,"axG",@progbits,_ZNK5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EE8this_ptrEv,comdat
	.align 2
	.weak	_ZNK5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EE8this_ptrEv
	.type	_ZNK5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EE8this_ptrEv, @function
_ZNK5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EE8this_ptrEv:
.LFB8540:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5boost9intrusive14pointer_traitsIPKNS0_9list_nodeIPvEEE10pointer_toERS5_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8540:
	.size	_ZNK5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EE8this_ptrEv, .-_ZNK5boost9intrusive12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EE8this_ptrEv
	.weak	_ZTISt17_Weak_result_typeIPFvPN7simgrid3s4u7MailboxES3_EE
	.section	.data.rel.ro._ZTISt17_Weak_result_typeIPFvPN7simgrid3s4u7MailboxES3_EE,"awG",@progbits,_ZTISt17_Weak_result_typeIPFvPN7simgrid3s4u7MailboxES3_EE,comdat
	.align 8
	.type	_ZTISt17_Weak_result_typeIPFvPN7simgrid3s4u7MailboxES3_EE, @object
	.size	_ZTISt17_Weak_result_typeIPFvPN7simgrid3s4u7MailboxES3_EE, 24
_ZTISt17_Weak_result_typeIPFvPN7simgrid3s4u7MailboxES3_EE:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTSSt17_Weak_result_typeIPFvPN7simgrid3s4u7MailboxES3_EE
	.quad	_ZTISt22_Weak_result_type_implIPFvPN7simgrid3s4u7MailboxES3_EE
	.weak	_ZTSSt17_Weak_result_typeIPFvPN7simgrid3s4u7MailboxES3_EE
	.section	.rodata._ZTSSt17_Weak_result_typeIPFvPN7simgrid3s4u7MailboxES3_EE,"aG",@progbits,_ZTSSt17_Weak_result_typeIPFvPN7simgrid3s4u7MailboxES3_EE,comdat
	.align 32
	.type	_ZTSSt17_Weak_result_typeIPFvPN7simgrid3s4u7MailboxES3_EE, @object
	.size	_ZTSSt17_Weak_result_typeIPFvPN7simgrid3s4u7MailboxES3_EE, 54
_ZTSSt17_Weak_result_typeIPFvPN7simgrid3s4u7MailboxES3_EE:
	.string	"St17_Weak_result_typeIPFvPN7simgrid3s4u7MailboxES3_EE"
	.weak	_ZTISt22_Weak_result_type_implIPFvPN7simgrid3s4u7MailboxES3_EE
	.section	.data.rel.ro._ZTISt22_Weak_result_type_implIPFvPN7simgrid3s4u7MailboxES3_EE,"awG",@progbits,_ZTISt22_Weak_result_type_implIPFvPN7simgrid3s4u7MailboxES3_EE,comdat
	.align 8
	.type	_ZTISt22_Weak_result_type_implIPFvPN7simgrid3s4u7MailboxES3_EE, @object
	.size	_ZTISt22_Weak_result_type_implIPFvPN7simgrid3s4u7MailboxES3_EE, 16
_ZTISt22_Weak_result_type_implIPFvPN7simgrid3s4u7MailboxES3_EE:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTSSt22_Weak_result_type_implIPFvPN7simgrid3s4u7MailboxES3_EE
	.weak	_ZTSSt22_Weak_result_type_implIPFvPN7simgrid3s4u7MailboxES3_EE
	.section	.rodata._ZTSSt22_Weak_result_type_implIPFvPN7simgrid3s4u7MailboxES3_EE,"aG",@progbits,_ZTSSt22_Weak_result_type_implIPFvPN7simgrid3s4u7MailboxES3_EE,comdat
	.align 32
	.type	_ZTSSt22_Weak_result_type_implIPFvPN7simgrid3s4u7MailboxES3_EE, @object
	.size	_ZTSSt22_Weak_result_type_implIPFvPN7simgrid3s4u7MailboxES3_EE, 59
_ZTSSt22_Weak_result_type_implIPFvPN7simgrid3s4u7MailboxES3_EE:
	.string	"St22_Weak_result_type_implIPFvPN7simgrid3s4u7MailboxES3_EE"
	.text
	.type	_GLOBAL__sub_I__simgrid_log_category__sample_simulator__constructor__, @function
_GLOBAL__sub_I__simgrid_log_category__sample_simulator__constructor__:
.LFB8541:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8541:
	.size	_GLOBAL__sub_I__simgrid_log_category__sample_simulator__constructor__, .-_GLOBAL__sub_I__simgrid_log_category__sample_simulator__constructor__
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__simgrid_log_category__sample_simulator__constructor__
	.section	.rodata
	.type	_ZZL6pingerPN7simgrid3s4u7MailboxES2_E8__func__, @object
	.size	_ZZL6pingerPN7simgrid3s4u7MailboxES2_E8__func__, 7
_ZZL6pingerPN7simgrid3s4u7MailboxES2_E8__func__:
	.string	"pinger"
	.type	_ZZL6pongerPN7simgrid3s4u7MailboxES2_E8__func__, @object
	.size	_ZZL6pongerPN7simgrid3s4u7MailboxES2_E8__func__, 7
_ZZL6pongerPN7simgrid3s4u7MailboxES2_E8__func__:
	.string	"ponger"
	.type	_ZZ4mainE8__func__, @object
	.size	_ZZ4mainE8__func__, 5
_ZZ4mainE8__func__:
	.string	"main"
	.align 32
	.type	_ZZN5boost9intrusive6detail15destructor_implINS0_12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EEEEEvRT_NS1_13link_dispatchILS9_1EEEE19__PRETTY_FUNCTION__, @object
	.size	_ZZN5boost9intrusive6detail15destructor_implINS0_12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EEEEEvRT_NS1_13link_dispatchILS9_1EEEE19__PRETTY_FUNCTION__, 354
_ZZN5boost9intrusive6detail15destructor_implINS0_12generic_hookILNS0_10algo_typesE0ENS0_16list_node_traitsIPvEENS0_7dft_tagELNS0_14link_mode_typeE1ELNS0_14base_hook_typeE1EEEEEvRT_NS1_13link_dispatchILS9_1EEEE19__PRETTY_FUNCTION__:
	.ascii	"void boost::intrusive::detail::destructor_impl(Hook&, boost:"
	.ascii	":intrusive::detail::link_dispatch<(bo"
	.string	"ost::intrusive::link_mode_type)1>) [with Hook = boost::intrusive::generic_hook<(boost::intrusive::algo_types)0, boost::intrusive::list_node_traits<void*>, boost::intrusive::dft_tag, (boost::intrusive::link_mode_type)1, (boost::intrusive::base_hook_type)1>]"
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
