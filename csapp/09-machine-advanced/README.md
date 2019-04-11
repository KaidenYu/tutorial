#### P3
- x86-64 Linux Memory Layout
  - stack
    - 8MB limit (use command "ulimit -s" to check the maximum of stack size)
    - E.g. local variables
  - Heap
    - Dynamically allocated as needed
    - malloc(), calloc(), new()
  - Data
    - Statitically allocated data
    - global vars, static vars, string constants
  - Text / Shared Libraries
    - Executable machine instructions
    - Read-only
    
  ![](https://i.imgur.com/2d3INQq.png)
  
  - 48 bits for virtual address (0~7FFFFFFFFFFF)
  - [reference](https://stackoverflow.com/questions/55358289/may-windows-64-bit-allocate-virtual-memory-over-7fffffffffff)

---
  
#### P4 -P6

![](https://i.imgur.com/3CF15zU.png)

![](https://i.imgur.com/mOL47yX.png)

![](https://i.imgur.com/NlQjzxA.png)

- Memory Allocation Example [ex01](https://github.com/KaidenYu/tutorial/tree/master/csapp/09-machine-advanced/ex01)
- Runaway Stack Example [ex02](https://github.com/KaidenYu/tutorial/tree/master/csapp/09-machine-advanced/ex02)

---

#### P8
- Memory Referencing Bug [ex03](https://github.com/KaidenYu/tutorial/tree/master/csapp/09-machine-advanced/ex03)

---

#### P10
- buffer overflow
  - exceeding the memory size allocated for an array
  - number one technical cause of security vulnerabilities
  - most common form
    - unchecked lengths on string inputs, particularly for bounded character arrays on the stack (stack smashing)
    
---

#### P11
- String Library Code which is unsecure
  - gets
    - No way to specify limit on number of characters to read
  - strcpy, strcat: copy strings of arbitrary length
  - scanf, fscanf, sscanf, when given %s conversion specification

- Buffer Overflow Stack Example [ex04](https://github.com/KaidenYu/tutorial/tree/master/csapp/09-machine-advanced/ex04)

  ![](https://i.imgur.com/m9oJf4t.png)

  ![](https://i.imgur.com/gITMsBs.png)

  ![](https://i.imgur.com/ghIvj3g.png)


