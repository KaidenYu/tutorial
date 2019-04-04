#### P8
![](https://i.imgur.com/dtw7v3K.png)

- information about currently executing program Registers
  - Temporary data
    - %rax, ...
  - Location of runtime stack
    - %rsp ( = stack pointer)
    - current stack top
  - Location of current code control point
    - %rip ( = instruction pointer = program counter)
  - Status of recent tests
    - CF, ZF, SF, OF (only one bit)
    - there are more
---

#### P9
- condition codes
  - single bit registers
    - CF: carry flag(for unsigned)
    - ZF: zero flag
    - SF: sign flag(for singed)
    - OF: overflow flag(for signed)
  - Implicitly set (as side effect) of arithmetic operations
    - ex:addq Src,Dest <-> t= a+b
      - CF set if carry out from most significant bit (unsigned overflow)
      - ZF set if t == 0
      - SF set if t < 0 (as signed)
      - OF set if two’s-complement (signed) overflow 
        - (a>0 && b>0 && t<0) || (a<0 && b<0 && t>=0)
  - Not set by leaq instruction

---

#### P14 P15
1. Compare Instruction
  - cmpq Src2, Src1
  - cmpq b,a like computing a-b without setting destination
    - CF set if carry out from most significant bit (used for unsigned comparisons)
    - ZF set if a == b
    - SF set if (a-b) < 0 (as signed)
    - OF set if two’s-complement (signed) overflow
      - (a>0 && b<0 && (a-b)<0) || (a<0 && b>0 && (a-b)>0)
2. Test Instruction
  - testq Src2, Src1
  - testq b,a like computing a&b without setting destination
    - ZF set when a&b == 0
    - SF set when a&b < 0
  - Useful to have one of the operands be a mask
  - often usage: testq %rax,%rax (means test %rax)

---


#### P
---
#### P
---
#### P
---
#### P
---
#### P
---
#### P
---
#### P
---
#### P
---
#### P
---
#### P
---
#### P
---
#### P
---
#### P
---
#### P
---
#### P
---
#### P
---
#### P
---
