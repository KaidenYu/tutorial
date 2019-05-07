

#### P13-P20

each process has its own page table

- phsycal memory: DRAM
- virtual memory: disk
- page table: DRAM(kernel data structure)


- Page hit(DRAM cache hit):in physical memory
- Page fault(DRAM cache miss)：not in physical memory, cause page fault(exception)
  - handling page fault: page fault handler selects a victim to be evicted, offending instruction is restarted(page hit)
  - demanding paging: waiting until the miss to copy the page to DRAM

---

#### P21
- Virtual memory works because of locality
- working set: at any point in time, programs tend to access a set of active virtual pages called the working set
  - working set size < main memory size : good performance for one process after compulsory misses
  - working set size > main memory size : Thrashing: bad performance due to pages swapping in and out 


---

#### P25
execve allocates virtual pages for .text and.data sections & creates PTES marked as "invalid" -> cause page fault when access, then copy the page on demand by the virtual memory

---

#### P28
virtual address 2^48. the higher order bit should be all zero(user code and data) or all one(kernel code and data)

SUP-> supervisor mode: can be access by user or kernel
EXEC->new in x86_64, doesn't exist in x86(32bit) system (protection mechanism mentioned in attack lab)

---

#### P35
CR3: control register 3

VPO is identical to PPO
