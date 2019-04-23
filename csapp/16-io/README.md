
#### P11

- ![](https://i.imgur.com/t3ME9b4.png)

- open files limit is 1024

---

#### P15

- strace ./program (or builtin command such as "ls")
  - trace the system call

- strace -e trace=write,read ./program
  - only trace write and read
  
