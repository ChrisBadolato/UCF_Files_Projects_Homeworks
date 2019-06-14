# Christopher Badolato 2/4/2019
# multiplication with forloops
# $t0-t3 is our use entered values.
# $t4 is our loop value
# results stored in t5-t7

.data
prompt1: .asciiz "Please enter a value for A, B. C and D in that order \n"
results1: .asciiz "\nf_ten =  "
results2: .asciiz "\nf_two =  "
results3: .asciiz "\ng_ten =  "
results4: .asciiz "\ng_two =  "

.text #required directives

 	#ask for user input
li $v0, 4 #4 is code for strings (look at help button operations)
la $a0, prompt1 #load Address of string
syscall

li $t0, 0
li $t1, 0
li $t2, 0
li $t3, 0
	#Get Value A
li $v0, 5
syscall
move $t0, $v0
	#Get Value B
li $v0, 5
syscall
move $t1, $v0
	#Get Value C
li $v0, 5
syscall
move $t2, $v0
	#Get Value D
li $v0, 5
syscall
move $t3, $v0

		#t4 our iteration
li $t4, 0	#stores a for our first loop
move $t5, $t0	#results
li $t6, 0
li $t7, 0

	#f =((A x A) + (B x D))
Loop: bge  $t4, $t0, EXIT   
add $t6, $t6, $t5
add $t4, $t4, 1 
j Loop   
EXIT:
	#now our result of (A x A) is stored in t6.
	#reset our iterator
li $t4, 0
	#loop through D
Loop2: bge  $t4, $t3, EXIT2  
add $t7, $t7, $t1 
add $t4, $t4, 1 
j Loop2   
EXIT2:
	#reusing $t5 for this results since we no longer need that register from above
sub $t5, $t6, $t7

move $s0, $t5

li $v0, 4 
la $a0, results1 
syscall
	#print results in decimal
li $v0, 1
move $a0, $s0
syscall 

li $v0, 4 
la $a0, results2 
syscall
	#print results in Binary
li $v0, 35
move $a0, $s0
syscall 


	#g =(A x D + 6 x C)
li $t4, 0
li $t5, 0
li $t6, 0
li $t7, 0

Loop3: bge  $t4, $t0, EXIT3   
add $t6, $t6, $t3
add $t4, $t4, 1 
j Loop3   
EXIT3:
	#now our result of (a x d) is stored in t6.
	#reset our iterator
li $t4, 0
	#loop through c add 6 each iteration
Loop4: bge  $t4, $t2, EXIT4 
add $t7, $t7, 6 
add $t4, $t4, 1 
j Loop4   
EXIT4:

	#reusing $t5 for this results since we no longer need that register from above
add $t5, $t6, $t7

move $s1, $t5

li $v0, 4 
la $a0, results3 
syscall
	#print results in decimal
li $v0, 1
move $a0, $s1
syscall 

li $v0, 4 
la $a0, results4
syscall
	#print results in binary
li $v0, 35
move $a0, $s1
syscall 

li $v0, 10
syscall
