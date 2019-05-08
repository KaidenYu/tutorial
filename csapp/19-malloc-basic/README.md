

#### P3
- brk ptr: top of heap

---



#### P4

- allocator
  - expicit allocator:application allocates and frees sapce
    - malloc and free in C
  - implicit allocator:application allocates space and system take care of freeing space
    - garbage collection in java, ML, and Lisp
    
---

#### P5
- malloc package
  - header: stdlib.h
  - void *malloc(size_t size)
    - successful:return pointer to memory block of least size bytes.if size==0, returns NULL
      - **16-byte** allignment on x86-64, **8-byte** allignment on x86
    - unsucessful: returns NULL(0) and sets errno
  - void free(void *p)
    - p must come form a previous call to malloc or realloc
  - other functions
    - calloc: zero initilizatoin version of malloc
    - realloc: change the size of previously allocated block
    - sbrk: used internally by allocators to grow or shrink the heap
    
---

#### P10-P11
- throughput
  - example: 5000 malloc calls and 5000 free calls in 10 seconds, throughput is 1000 operations/second
- Peak Memory Utilization
  - Pk: aggregate payload
  - Hk: current heap size(assume heap only grows when allocator uses sbrk)
  - Uk: peak memory utilization = (max i<=k Pi) / Hk
  
---

#### P12-P14
- Fragmentation
  - internal
    - occurs if payload is smaller than block size
    - cause:
      - overhead of maintaining heap data structures
      - padding for alignment purposes
      - explicit policy decisions(e.g. to return a big block to satisfy a small request)
    - depends only on the pattern of previous requests-> easy to measure
    
  - external
    - occurs when there is enough aggregate heap memory, but no single free block is large enough
    - depends on the pattern of future request-> difficult to measure
    
---

#### P16-P17
- how much to free
  - header(header field) : keep the length of block in the word preceding the block
  - an extra word required
- keeping trace of free blocks
  1. **Implicit list** using length—links all blocks
  2. **Explicit list** among the free blocks using pointers
  3. **Segregated free list**: Different free lists for different size classes
  4. **Blocks sorted by size**: Can use a balanced tree (e.g. Red-Black tree) with pointers within each free block, and the length used as a key
  
---

#### P20
- implicit free list
  - trick: When blocks are aligned, some low-order address bits are always 0, use one(some) of them as allocated/free flag(s)
    - e.g. 16-byte alignment indicates that size is multiple of 16(16,32,46...), so the low-order 4 bits are all zero

---

#### P36
- Boundary tag needed only for free blocks
- use another lower 0 bit as previous block allocated/free flag



