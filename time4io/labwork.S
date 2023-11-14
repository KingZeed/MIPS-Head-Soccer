  # labwork.S
  # Written 2015-2017 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1.
  # The macros PUSH and POP are in the public domain.
  # Please add your own code at the end of the file.

  #
  # Please keep the two macros PUSH and POP unchanged
  #
.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
  #
  # Please add your own code below this line
  #
	
	.data
	.text
	.globl delay, time2string, hexasc

hexasc:
	addi 	$v0, $a0, 0x30	# add 0x30 to v0 to start from ascii-symbol '0'
	slti 	$t0, $a0, 10	# set $t0 to 1 if $a0 is less than 10, otherwise set $t0 to 0
	bne 	$t0, $0, end	# jump to end if $t0 is not equal to end
	nop			# delay slot filler (just in case)
	addi 	$v0, $v0, 0x07	# add 0x07 to $v0
	end:
	jr $ra			# jump back
	nop
		
time2string:

	PUSH $ra
	PUSH $s0
	
	add	$s0, $0, $a0	# s0 = a0
	addi	$t7, $0, 0x3a	# Hexacode for char ':'
	addi	$t6, $0, 0x00	# Hexacode for NULL
	
	sb	$t6, 5($s0)
	
	andi	$a0, $a1, 0xF	# This section handles the least significant nibble of $a1 (ex: for 00001653 this handles the 3)
	and	$t4, $0, $s0
	
	jal 	hexasc
	nop
	sb 	$v0, 4($s0)
	
	srl	$a1, $a1, 4	# This section handles the 5 in the example 0x00001653
	andi	$a0, $a1, 0xF
	jal 	hexasc
	nop
	sb 	$v0, 3($s0)
	
	sb	$t7, 2($s0)	# This handles the colon
	
	srl	$a1, $a1, 4	#This section handles the 6 in the example 0x00001653
	andi	$a0, $a1, 0xF
	jal 	hexasc
	nop
	sb 	$v0, 1($s0)
	
	srl	$a1, $a1, 4	#This section handles the 1 in the example 0x00001653
	andi	$a0, $a1, 0xF
	jal 	hexasc
	nop
	sb 	$v0, 0($s0)
	
	POP $s0
	POP $ra
	jr	$ra
	nop

delay:				# $a0 = ms
	PUSH $s0
	add	$s0, $0, $a0
delay_while:
	add 	$t0, $0, $0	# $t0 = int i = 0
	ble	$s0, $0, end_dw
	nop
	addi	$s0, $s0, -1
	addi	$t1, $0, 3800 #202
delay_for:
	ble	$t1, $t0, delay_while
	nop
	addi	$t0, $t0, 1
	j	delay_for
	nop
	
end_dw:
	POP $s0
	jr	$ra
	nop