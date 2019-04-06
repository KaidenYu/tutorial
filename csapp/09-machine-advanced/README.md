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
  
#### P4 -P5
- Memory Allocation Example
- 
