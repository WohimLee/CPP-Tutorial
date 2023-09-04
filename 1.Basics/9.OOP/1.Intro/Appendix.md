
&emsp;
# Appendix 附录
## 1 符号小结
|符号 | 读法 |
| :----: | :----|
|*x|读作：pointed by x|
|&x|读作：address of x|
|x.y|读作：member y of object x|
|(*x).y|读作：member y of (object pointed by x)|
|x->y|读作：member y of (object pointed by x)|
|x[0]|读作：first object pointed by x（由x指向的第一个对象）|
|x[1]|读作：second object pointed by x（由x指向的第二个对象）|
| x[n]| 读作：(n+1)th object pointed by x（由x指向的第n+1个对象）|

&emsp;
## 2 运行时/编译时
"Compile-time" and "run-time" are two distinct phases in the life cycle of a program, and they refer to different moments of action regarding your code.

### 2.1 Compile-Time
Compile-time is the phase where the source code written by a programmer is transformed into an executable form by a compiler. During this phase, the compiler can check for syntax errors, type checking, and other forms of static analysis. Various optimizations to the code are also performed at this time to enhance performance. Any errors or issues detected during this phase prevent the code from being compiled into an executable file.

Here are some key points about compile-time:
- Syntax Checking: The compiler checks for syntax errors in the code.
- Type Checking: The compiler verifies that operations are being performed on compatible types.
- Memory Allocation: Memory space for static and global variables is allocated.
- Optimization: The compiler may optimize the code for better performance.
- Translation: The source code is translated to machine or bytecode.

### 2.2 Run-Time
Run-time, on the other hand, is the phase where the compiled program (executable file) is executed by the computer's processor. During this phase, the program interacts dynamically with the input data and the system resources. The actions performed at run-time are determined by the logic within the program and the inputs it receives.

Here are some key points about run-time:
- Dynamic Memory Allocation: Memory is allocated dynamically (e.g., using new or malloc).
Execution of Instructions: The actual execution of the program's instructions occurs.
- User Interaction: The program can interact with the user, receiving inputs, and displaying outputs.
- Error Handling: Run-time errors, such as division by zero or accessing an invalid memory location, can occur and must be handled to prevent crashes.
- Resource Management: The program interacts with system resources, such as file systems, network resources, etc.

### 2.3 Summary
In essence, compile-time is about preparing and validating the program (checking errors, optimizing, translating to machine code), and run-time is about executing the program and interacting dynamically with the environment (allocating memory dynamically, user interaction, handling run-time errors).