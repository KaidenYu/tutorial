#### P3 - P7
- Mechanisms in Procedures
  1. Passing control
    - To beginning of procedure code
    - Back to return point
    
    ![](https://i.imgur.com/xLfiQnd.png)
    
  2. Passing data
    - Procedure arguments
    - Return value
    
    ![](https://i.imgur.com/kTxfd08.png)
    
  3. Memory management
    - Allocate during procedure execution
    - Deallocate upon return
    
    ![](https://i.imgur.com/6W264Oy.png)

  - Mechanisms all implemented with machine instructions
    - Machine instructions implement the mechanisms, but the choices are Passing data determined by designers. These choices make up the Application Binary Interface (ABI).
    - ABI vs API(Application Programming Interface)
    
    ![](https://i.imgur.com/4ulsZ01.png)
    
    - [reference](https://en.wikipedia.org/wiki/Application_binary_interface)
    
  - x86-64 implementation of a procedure uses only those mechanisms required

---

#### P10

![](https://i.imgur.com/SKu7IvF.png)

- grows toward lower address
- %rsp contains lowest stack address

---

#### P12

1. Stack: Push
  - pushq Src
    - Fetch operand at Src
    - Decrement %rsp by 8
    - write operand at address given by %rsp


2. Stack: Pop
  - popq Dest
    - Read value at address given by %rsp
    - Increment %rsp by 8
    - Store value at Dest (usually a register)
    - memory doesn't change only the value of %rsp (the data that is pushed won't be removed when popped )
 
 ---
 
 #### P18 - P23
- Procedure Control Flow
  - Use stack to support procedure call and return
  1. Procedure call: **call label**
    - Push return address on stack
      - return address: address of the next instruction right aftetr call (return to where)
    - Jump to label
  2. Procedure return: **ret**
    - Pop address from stack
    - Jump to address
    
  ![](https://i.imgur.com/3HaG7Gm.png)

  ![](https://i.imgur.com/1Jcmy0r.png)

  ![](https://i.imgur.com/B1mLoMB.png)

  ![](https://i.imgur.com/X8nsNTf.png)

  ![](https://i.imgur.com/CY5iZhN.png)
  
---

#### P25 - P26
- Procedure Data Flow
  - arguments 
    - first 6: %rdi, %rsi, %rdx, %rcx, %r8, %r9
    - more than 6 arguments: stack
  - return value
    - %rax
  
  ![](https://i.imgur.com/RH954b4.png)

  ![](https://i.imgur.com/5AM0zWC.png)

---

#### P28
- Managing Local Data
  - stack discipline
    - state for given procedure needed for limited time (duration: from called to return)
    - Callee returns before caller does
  - stack frames
    - stack allocated in frames
    - state for single procedure instantiation
      - instantiation: In programming, instantiation is the creation of a real instance or particular realization of an       abstraction or template such as a class of objects or a computer process.
  - recursion
    - stack-based languages: languages that support recursion (e.g. C, Pascal, Java, ...)
    - Code must be "Reentrant"(折返)
    - Need place to store state of each instantiation
      1. Arguments
      2. Local variables
      3. Return pointer

---

#### P29
- Stack Frames
  - Contents
    1. Return information
    2. Local storage (if needed)
    3. Temporary space (if needed)
  - Management
    - Space allocated when enter procedure
      - "Set-up" code
      - Includes push by call instruction
    - Deallocated when return
      - "Finish" code
      - Includes pop by ret instruction
  
  ![](https://i.imgur.com/xQvRBAQ.png)
  
- Call Chain Example

![](https://i.imgur.com/ktM9GCQ.png)

![](https://i.imgur.com/8jZmJ6B.png)

![](https://i.imgur.com/VzxGfPz.png)

![](https://i.imgur.com/wqK5E2U.png)

![](https://i.imgur.com/ZbUaAnx.png)

![](https://i.imgur.com/nbChm65.png)

#### P42
- x86-64/Linux Stack Frame
  - Current(Callee) Stack Frame
    - "Argument build:" Parameters for fucntion about to call
    - Local variables if can't keep in registers
    - Saved register context
    - Old frame pointer (optional)
  - Caller Stack Frame
    - Return address : Pushed by call instruction
    - Arguments for this call (more than 6 arguments)

  ![](https://i.imgur.com/OJbQMdc.png)
  
  - if rbp is optional,how do we know the length of stack frame to deallocate when retq?
  - there are some cases that we need to use rbp
  
---

#### P49


- movl $3000, %esi
  - although esi is 32bits but but doing this the upper bits(rsi) will be set to zero
  - Why use movl instead of movq? 1 byte shorter

---

#### P57
- Register Saving Conventions
  - caller and callee
    - when procedure yoo calls who
      - caller: yoo
      - callee: who
  - Conventions
    1. Caller Saved:
      - Caller saves temporary values in its frame before the call
    2. Callee Saved:
      - Callee saves temporary values in its frame before using
      - Callee restores them before returning to caller

  ![](https://i.imgur.com/86a5EYk.png)

  ![](https://i.imgur.com/dpGV5gv.png)
  

---

#### additional info

- je=jump if equal
- jz=jump if zero
- basically je and jz are the same instruction ("74" or "0F 84")

- ret = retq same instruction (C3)






