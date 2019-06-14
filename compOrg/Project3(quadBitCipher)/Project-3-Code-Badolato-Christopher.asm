#Christopher Badolato
#EEL 3801-0011
#4/8/2019
#This program will first, call QuadMinMixer, comparing two 32 bit integer values 4 bits at a time. 
#We will store the minimum of these two four bit values, into a new value (z) eventaully creating a 32 bit number.
#We will then count the frequency of each 4 bit hex didget in the 32 bit output z.  

.data
#initilize the data array
count: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

newLine: .asciiz "\n" 
t1: .asciiz "\nt1: \n" 
t2: .asciiz "\nt2: \n" 
mask: .asciiz "\nmask: \n" 
returnValue: .asciiz "QuadMinMixer = "
quadBitCipher: .asciiz "QuadBitChipher = "
.text

	QuadBitCipher:
	
		#get value for x from user
	li $v0, 5
	syscall
	move $t0, $v0
		#get value for y from user
	li $v0, 5
	syscall
	move $t1, $v0
		#store the input values into $a1 and $a2 to be used as parameters in quadMinMixer
	addi $a1, $t0, 0
	addi $a2, $t1, 0
	jal QuadMinMixer	
		#after our function is finished running z is now stored in register $s0 and print it out in hex
	move $s0, $v0
	li $v0, 4 
	la $a0, returnValue
	syscall
	li, $v0, 34
	addi $a0, $s0, 0
	syscall
	li $v0, 4 
	la $a0, newLine
	syscall
		#now that we have our value 'z' we can count the frequency of each hex value that occurs ( each set of 4-bits in the 32-bit value.)
		#z is now stored in register $s0
		#We load base address of our frequency array to $s1.
	la $s1, count
	addi $t0, $zero, 0x000000f	#create Mask to grab value off z, we will shift the mask to get our hex values off.
	
	#First Hex Value
				#$t4 will store our array index value for each "iteration" of the cipher
	and $t1, $t0, $s0 	#create a mask of first 4-bit value (one single hex value).
	sll $t1, $t1, 2		#multiply this hex value by 4. This will be the index of our array!
	add $s1, $s1, $t1	#add to the value storing our base address, this will take us to the position of the array we want "index of the hex value". 
	
	lw $t2, 0($s1)		#now that we have our array index we can load the value from it
	add $t2, $t2, 1		#add one at the index to count the freqeuncy
	sw $t2, 0($s1)		#store the value back into the array at the index of the hex bit.
	sub $s1, $s1, $t1 	#we need to reset our array to the base adress now that we are finished at that spot.
	
	#Now we can do the same for every 4 bits afterwards
	#We only need to shift our mask left 4 bits
	#To make sure we store the frequency at the correct index we need to right shift our masked hex value based on its distance from the LSB.
	#Once this value is shifted right to the least significant bit we need to multiply it by 4 to get the proper array index offset.
		#Second Hex Value
	sll $t0, $t0, 4		#shift our mask to the next four bits
	and $t1, $t0, $s0	#create a mask of the value Z. (000000f0) && (z)
	srl $t1, $t1, 2 	#shift right 2 (First we want to shift our value all the way right. Then, multiply by 4 to get correct memory index offset)((value >> 4) <<2)
	add $s1, $s1, $t1	#We can do this in one step by shifting right 2.
	lw $t2, 0($s1)		#Next we proceed as above, using the index found and stored into $s1. 
	add $t2, $t2, 1
	sw $t2, 0($s1)
	sub $s1, $s1, $t1 
	
		#Third Hex Value
	sll $t0, $t0, 4
	and $t1, $t0, $s0	#create a mask of the value Z. (00000f00) && (z)
	srl $t1, $t1, 6		#shift by 6 to make sure our array index is at the correct value. ((value >> 8) << 2)
	add $s1, $s1, $t1
	lw $t2, 0($s1)
	add $t2, $t2, 1
	sw $t2, 0($s1)
	sub $s1, $s1, $t1 
	
		#Fourth Hex Value
	sll $t0, $t0, 4
	and $t1, $t0, $s0	#create a mask of the value Z. (0000f000) && (z)
	srl $t1, $t1, 10	#shift by 10 to make sure our array index is at the correct value. ((value >> 12) << 2)
	add $s1, $s1, $t1
	lw $t2, 0($s1)
	add $t2, $t2, 1
	sw $t2, 0($s1)
	sub $s1, $s1, $t1 
	
		#Fifth Hex Value
	sll $t0, $t0, 4
	and $t1, $t0, $s0	#create a mask of the value Z. (000f0000) && (z)
	srl $t1, $t1, 14	#shift by 14 to make sure our array index is at the correct value. ((value >> 16) << 2)
	add $s1, $s1, $t1
	lw $t2, 0($s1)
	add $t2, $t2, 1
	sw $t2, 0($s1)
	sub $s1, $s1, $t1 
	
		#Sixth Hex Value
	sll $t0, $t0, 4
	and $t1, $t0, $s0	#create a mask of the value Z. (00f00000) && (z)
	srl $t1, $t1, 18	#shift by 18 to make sure our array index is at the correct value. ((value >> 20) << 2)
	add $s1, $s1, $t1
	lw $t2, 0($s1)
	add $t2, $t2, 1
	sw $t2, 0($s1)
	sub $s1, $s1, $t1 
	
		#Seventh Hex Value
	sll $t0, $t0, 4
	and $t1, $t0, $s0	#create a mask of the value Z. (0f000000) && (z)
	srl $t1, $t1, 22	#shift by 22 to make sure our array index is at the correct value. ((value >> 26) << 2)
	add $s1, $s1, $t1
	lw $t2, 0($s1)
	add $t2, $t2, 1
	sw $t2, 0($s1)
	sub $s1, $s1, $t1 
	
		#Eighth Hex Value
	sll $t0, $t0, 4
	and $t1, $t0, $s0	#create a mask of the value Z. (f0000000) && (z)
	srl $t1, $t1, 26	#shift by 26 to make sure our array index is at the correct value. ((value >> 30) << 2)
	add $s1, $s1, $t1
	lw $t2, 0($s1)
	add $t2, $t2, 1
	sw $t2, 0($s1)
	sub $s1, $s1, $t1 
		#Finally we can print our entire array.
		#could unroll the loop to make the instruction count drop a bit more.
	li $v0, 4 
	la $a0, quadBitCipher
	syscall
	
	li $t3, 0	#initialize loop counter
	printLoop:	
	lw $t4, 60($s1)	#load the END of the array (we are printing f frequency first)
	li $v0, 1 
	move $a0, $t4	#print the frequency stored at the current location of the array.
	syscall
	sub $s1, $s1, 4	#move back the the next value index of the array.
	add $t3, $t3, 1	#loop through 16 for each index.
	bne $t3, 16, printLoop		
	li $v0, 10
	syscall
	
	
	
	QuadMinMixer:
			#a1 = x
			#a2 = y
			#$v0 = return value(We need to send 'z' back to the main function)
			#create a mask value we start with our first four LSB.
			#create space for potential recursive use.
		addi $sp $sp, -12
			#store the resturn address onto the stack for recursive use later.
		sw $ra, 8($sp) 
			#create space for the sent in parameters
		sw $s0, 4($sp)
		sw $s1, 0($sp)
			#create temp to store mask value. We will AND x and y with this Mask to create a 4 bit value!
			#e.g. 1010  && 1111 = 1010
		addi $t0, $zero, 0x0000000f
		li $t1, 0	
	
		and $s0, $t0, $a1		#Create masks of our first Least Significant bits.
		and $s1, $t0, $a2		
		bge $s0, $s1, xIsGreater1	#checks to see if our first four bits (Least Significant Bits) of the x input are greater than the first four bits of y.
		or $t1, $t1, $s0		#e.g. (0000 + 1010) = (1010) We can just || our value with our CURRENT z value. Z will grow as we go!  
		j yIsGreater1					
		xIsGreater1:			#if we take the branch the first hex value in x is larger so to y.
		or $t1, $t1, $s1		#otherwise we just take the x value and jump to the next mask shift.
		yIsGreater1:			#finally if Y is greater we want to make sure to skip adding x to the output with the jump.
			#second Hex Value	
		sll $t0, $t0, 4			#After our first iteration we need to shift the mask left four to mask the next 4 bits!
		and $s0, $t0, $a1		#Then we can proceed as above, checking which 4 bits of each input is the smaller value.
		and $s1, $t0, $a2				
		bge $s0, $s1, xIsGreater2
		or $t1, $t1, $s0
		j yIsGreater2
		xIsGreater2:
		or $t1, $t1, $s1
		yIsGreater2:
			#Third Hex Value
		sll $t0, $t0, 4			#Shift the mask
		and $s0, $t0, $a1		#grab 4 bit section of inputs
		and $s1, $t0, $a2				
		bge $s0, $s1, xIsGreater3	# branch if x is greater then store y otherwise store x.
		or $t1, $t1, $s0		#"add" our four bit y to the output z
		j yIsGreater3	
		xIsGreater3:
		or $t1, $t1, $s1		#"add" our four bit x to the output z
		yIsGreater3:
		
			#Fourth Hex Value
		sll $t0, $t0, 4			#Shift the mask
		and $s0, $t0, $a1		#grab 4 bit section of inputs
		and $s1, $t0, $a2				
		bge $s0, $s1, xIsGreater4	# branch if x is greater then store y otherwise store x.
		or $t1, $t1, $s0
		j yIsGreater4
		xIsGreater4:
		or $t1, $t1, $s1
		yIsGreater4:
		
			#Fifth Hex Value
		sll $t0, $t0, 4			#Shift the mask
		and $s0, $t0, $a1		#grab 4 bit section of inputs
		and $s1, $t0, $a2				
		bge $s0, $s1, xIsGreater5	# branch if x is greater then store y otherwise store x.
		or $t1, $t1, $s0
		j yIsGreater5
		xIsGreater5:
		or $t1, $t1, $s1
		yIsGreater5:
		
			#sixth Hex Value
		sll $t0, $t0, 4			#Shift the mask
		and $s0, $t0, $a1		#grab 4 bit section of inputs
		and $s1, $t0, $a2				
		bge $s0, $s1, xIsGreater6	# branch if x is greater then store y otherwise store x.
		or $t1, $t1, $s0
		j yIsGreater6
		xIsGreater6:
		or $t1, $t1, $s1
		yIsGreater6:
		
			#seventh Hex Value
		sll $t0, $t0, 4			#Shift the mask
		and $s0, $t0, $a1		#grab 4 bit section of inputs
		and $s1, $t0, $a2				
		bge $s0, $s1, xIsGreater7	# branch if x is greater then store y otherwise store x.
		or $t1, $t1, $s0
		j yIsGreater7
		xIsGreater7:
		or $t1, $t1, $s1
		yIsGreater7:
		
			#eighth Hex Value
		sll $t0, $t0, 4			#Shift the mask
		and $s0, $t0, $a1		#grab 4 bit section of inputs
		and $s1, $t0, $a2				
		bge $s0, $s1, xIsGreater8	# branch if x is greater then store y otherwise store x.
		or $t1, $t1, $s0
		j yIsGreater8
		xIsGreater8:
		or $t1, $t1, $s1
		yIsGreater8:
			#we have reached the end of our 32 bit value.
			#pop the values back off the stack
			#restore the space.
		lw $ra, 8($sp)	
		lw $s0, 4($sp)	
		lw $s1, 0($sp)	
		addi $sp, $sp, 12
			#save our output (z) into $v0 to be returned back to our main function.
		move $v0, $t1
		jr $ra
