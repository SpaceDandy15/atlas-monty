Task 0 wants me to implement the push and pall opcodes as described,
 we will create a simple program in c.
 This program will simulate a stack and perform the operations according to the specifications. 
 We’ll use the atoi function for converting string arguments to integers, as requested. 
 * push Opcode: The push operation is implemented in the push function. It takes the current stack, the top index of the stack, and the value to be pushed.
 It increments the top index and then stores the value at the incremented top index. 
Before pushing, it checks if the next argument after push is a valid integer using atoi. If atoi returns 0, it indicates a failure to convert the argument to an integer,
 and an error message is printed along with exiting the program.

* pall Opcode: The pall operation is implemented in the pall function. It iterates over the stack from the top to the bottom, printing each value. If the stack is empty, nothing is printed.

* Error Handling: The program checks for invalid usage of the push opcode by verifying that there is a valid integer argument following push. If the argument is not a valid integer,
 an error message is printed, and the program exits with a failure status.

* Line Number: The line number in the error message is obtained using the __LINE_ macro, which gives the current line number in the source file