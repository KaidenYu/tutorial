
#### P4
- Altering the Control Flow
    1. changes in program state
        - jumps and branches
        - call and return
    
    2. changes in system state
        - exceptional control flow (ECF)

---

#### P5
- ECF (4 types)
    - low level mechanisms
        1. exceptions: implemeted by hardware and OS software
    - higher level mechanisms
        2. process context switch: implemeted by hardware timer and OS software
        3. signals: implemeted by OS software
        4. nonlocal jumps: implemeted by C runtime library

---

#### P10
- Exceptions
    1. asynchronous exceptions (caused by events external to the processor)
        - interrupts
    2. synchronous exceptions (caused by events that occur as a result executing an instruction)
        - traps
        - faluts
        - abort

---

#### P13

![](https://i.imgur.com/Lfif6Ue.png)

- write a c code with open() and compile with "gcc -static" , then you can see the syscall part of the assembly 

[reference: how open() works](https://0xax.gitbooks.io/linux-insides/SysCall/linux-syscall-5.html)


#### P30

- Linux system-level functions:  a wrapper for the actual system call
    - https://linux-kernel-labs.github.io/master/lectures/syscalls.html


