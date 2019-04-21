
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

---

#### P18
- Prcoess(instance of a running program): provides each program two key abstractions
    1. logical control flow
        - each program seems to have exclusive use of the CPU
        - provided by kernel mechanism called **context switching**
    2. private address space
        - each program seems to have exclusive use of main memory
        - provided by kernel mechanism called **virtual memory**
        
---

#### P20
- **top** command
[reference](https://www.cyberciti.biz/faq/linux-find-process-name/)

---



#### P28
- important: the kernel is not a seperate process, but rather runs as part of some existing process
> not quite sure what it means

---

#### P30 - P33
- system call error handling
    - linux system-level functions typically return -1 and set global variable errno to indicate cause
    
    ![](https://i.imgur.com/XtURydh.png)

- usage of error-reporting functions and error-handling wrappers(stevens-style error-handling wrappers)


- obtaining process IDs
    - pid_t getpid(void): returns PID of current process
    - pid_t getppid(void): returns PID of parent process


- Linux system-level functions:  a wrapper for the actual system call
    - [refernece}(https://linux-kernel-labs.github.io/master/lectures/syscalls.html)

---

#### P34-P36
- Three states of process (programmer's perspective)
    1. running: executing or scheduled by kernel to be executed eventually
    2. stopped: suspended and will not be scheduled until further notice (signals)
    3. terminated: stopped permaneatly

- terminating process
    - receiving a signal whose default actions is to terminate
    - return from main
    - void exit(int stauts): **called once but never returns**
    
- creating process
    - int fork(void): **called once but retunrs twice**

---

#### P50 - P57
- idea of reaping child process
    - when procees terminates, it still consumes system resources such as exit status, various OS tables, ...
    - called a zombie
- reaping
    - perform by parent ono terminate child using **wait** or **waitpid**
    - Parent is give exit status information
    - Kernel then deletes zombie child process
- if parent doesn't reap
    - will be reaped by init process(pid==1)
    - only need explicit reaping in long-running processes such as shells and servers
        - produce too many zombies, kinda like memory leak. so we need to explicitly reap before that happen
- [reference:init process](https://stackoverflow.com/questions/20744200/how-is-the-init-process-started-in-the-linux-kernel)

- Non-terminating child: not zombie, need to be terminate explicitly by **kill** command, then the init process will do the reaping(since the parent already terminated)


- int wait(int *child_status)
    - suspends current process untill **any one** of its children terminates
    - return pid of the child process
    - if child_status!=NULL, then can check the exit status using macors in **wait.h**
- pid_t waitpid(pid_t pid, int *status, int options)
    - Suspends current process until specific process terminates

---

#### P58
- int execve(char *filename, char *argv[], char *envp[])
    - loading and running programs in the current process
        - excutable file **filename**: can be object file or script beggining with #!interpreter
        - with argument list argv
        - with environment variable list envp
    - **overwrites code,data, and stack**
    - **called once and never retunrs** except if there is an error

![](https://i.imgur.com/DPPS5AA.png)

![](https://i.imgur.com/R3jWqWW.png)

-if you want the current process to keep running after **execve**, could(should?) use **fork**
