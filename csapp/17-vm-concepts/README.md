

#### P13

each process has its own page table


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
