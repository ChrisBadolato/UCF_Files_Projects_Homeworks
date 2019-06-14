# Christopher Badolato 2/11/2019
# multiplication with forloops
# $t0-t1 is our use entered values.
# $t2-t7 are used throughout the program to store values 
# results stored in t5-t7

.data
prompt1: .asciiz "Please enter a value for F and G in that order \n"
f: .asciiz "\nf_ten = "
g: .asciiz "\ng_ten = "
results1: .asciiz "\nh_quotient  = "
results2: .asciiz "\nh_remainder =  "
results3: .asciiz "\ni_quotient = "
results4: .asciiz "\ni_remainder =  "
results5: .asciiz "\nj_remainder =  "


.text #required directives

 	#ask for user input
li $v0, 4 #4 is code for strings (look at help button operations)
la $a0, prompt1 #load Address of string
syscall

li $t0, 0
li $t1, 0
li $t2, 0
li $t3, 0
	#Get Value f
li $v0, 5
syscall
move $t0, $v0
	#Get Value g
li $v0, 5
syscall
move $t1, $v0
			
li $t2, 0	#h_quotient
add $t3, $t3, $t0	#h_remainder we initialize to get into our first loop

	
Loop1:  blt $t3, $t1, EXIT1
	sub $t3, $t3, $t1
	addi $t2, $t2, 1
	j Loop1
EXIT1:

	#prints f and g
li $v0, 4 
la $a0, f 
syscall

li $v0, 1
move $a0, $t0
syscall 

li $v0, 4 
la $a0, g
syscall

li $v0, 1
move $a0, $t1
syscall 

	#prints results of h = (f/g)
li $v0, 4 
la $a0, results1 
syscall

li $v0, 1
move $a0, $t2
syscall 

li $v0, 4 
la $a0, results2
syscall

li $v0, 1
move $a0, $t3
syscall 

li $t4, 0	# stores result of f+g
li $t5, 0	# stores i_remainder
li $t6, 0	#t6 stores quotient
add $t4, $t0, $t1
addi $t5, $t4, 0

Loop2:  blt $t5, $t2, EXIT2
	sub $t5, $t5, $t2
	addi $t6, $t6, 1
	j Loop2
EXIT2:
	#print results of i = f+g/h_quotient
li $v0, 4 
la $a0, results3 
syscall

li $v0, 1
move $a0, $t6
syscall 

li $v0, 4 
la $a0, results4
syscall

li $v0, 1
move $a0, $t5
syscall 

	# get value of (f-g)
sub $t7, $t0, $t1

Loop3:  blt $t7, $t6, EXIT3
	sub $t7, $t7, $t6
	addi $t4, $t4, 1
	j Loop3
EXIT3:
	#print final results
li $v0, 4 
la $a0, results5 
syscall

li $v0, 1
move $a0, $t7
syscall

li $v0, 10
syscall
