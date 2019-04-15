#### P4
- Complex Instruction Set Computer (CISC) - x86
- Reduced Instruction Set Computer (RISC) - ARM
---
#### P5
-why called x86?
> 8086,386,486... all end with "86"
- 386(1985):First 32 bit Intel processor , referred to as IA32
- Pentium 4E(2004):First 64-bit Intel x86 processor, referred to as x86-64, can also run 32-bit code
> some 32-bit program can't run on a 64-bit?why?
- Core 2(2006):First multi-core Intel processor
---
#### P6
- Architecture: (also ISA: instruction set architecture) The parts of a processor design that one needs to understand for writing assembly/machine code.
  Examples: instruction set specification, registers

- Microarchitecture: Implementation of the architecture
  Examples: cache sizes and core frequency

- Code Forms:
  1. Machine Code: The byte-level programs that a processor executes
  2. Assembly Code: A text representation of machine code
- Example ISAs:
  1. Intel: x86, IA32, Itanium, x86-64
  2. ARM: Used in almost all mobile phones
  3. RISC V: New open-source ISA
---
#### P15
![](https://i.imgur.com/L4SjCV2.png)
- PC: Program counter
  - Address of next instruction
  - Called “RIP” (x86-64)
- Register(give them names,not address)
- Condition codes
- Memory
  - Byte addressable array
  -  Code and user data
  -  Stack to support procedures
---
####  additional info
![](https://i.imgur.com/SW0T2xi.png)
- optimiztion option 
  - nothing: no optimization, assembly hard to understand
  - -Og:**basic optimization**
  - -O1:optimized, also hard to understand
---
#### P16
- Assembly charactor : Data Types
  - “Integer” data of 1, 2, 4, or 8 bytes (don't distinguish signed or unsigned)
    1. Data values
    2. Addresses (untyped pointers)
  - Floating point data of 4, 8, or 10 bytes
  - (SIMD vector data types of 8, 16, 32 or 64 bytes)
---
#### additional info
![](https://i.imgur.com/8NAC3Oz.png)
![](https://i.imgur.com/kdE4W9o.png)

- in ancient days: registers have very specific purposes and the names reflect their purposes
- now: just legacy names. only 1 special register now -> %rsp. for the most part,other registers are usable for holding program data

---

#### P19
- Assembly Characteristics: Operations
  - Transfer data between memory and register
    - memory -> register
    - register -> memory
  - Perform arithmetic function on register or memory data
  - Transfer control
    - Unconditional jumps to/from procedures
    - Conditional branches
    - Indirect branches
---

#### P20
- movq : where "q" stands for quad
  - q : quad word = 8 bytes
  - l : long word = 4 bytes
  - w : word = 2 bytes
  - b : byte = 1 byte

- movq src dst
  - immediate
    - constant interger data
    - prefixed with ‘$’
    - Encoded with 1, 2, or 4 bytes
    > how about 8 bytes?
  - register
    - Example: %rax, %r13
    - %rsp reserved for special use
    - Others have special uses for particular instructions
  - memory :
    - Simplest example: (%rax)
    - Various other “addressing modes”
  
---
#### P21
![](https://i.imgur.com/Rvt4LMU.png)
- memory-memory transfer need two instructions
  - memory[address] to register
  - register to memry[address]
---

#### P31 P32
- Memory Addressing Modes
  - Normal: (R) = Mem[Reg[R]]
  - Displacement: D(R) = Mem[Reg[R]+D]
  - General Form: D(Rb,Ri,S) = Mem[Reg[Rb]+S*Reg[Ri]+ D]
    - D: “displacement” means offset
    - Rb: "base" any of 16 registers
    - Ri: "index" any, except %rsp
    - S: "Scale" 1,2,4 or 8
    # special case:
      - (Rb,Ri) = Mem[Reg[Rb]+Reg[Ri]]
      - D(Rb,Ri) = Mem[Reg[Rb]+Reg[Ri]+D]
      - (Rb,Ri,S) = Mem[Reg[Rb]+S*Reg[Ri]]
      - (,Ri,S) = Mem[S*Reg[Ri]]
      
![](https://i.imgur.com/wXb6I7X.png) 

---
#### P36
- leaq src dst
  - leaq = load effective address quad
  - dst has to be a register
  > just take it as a arithmatic operation

![](https://i.imgur.com/pSNiT4t.png)

---

#### P37 P39
- Two Operand Instructions
  - addq Src,Dest => Dest = Dest + Src
  - subq Src,Dest => Dest = Dest - Src
  - imulq Src,Dest => Dest = Dest * Src
  - salq Src,Dest => Dest = Dest << Src  (also called shlq)
  - sarq Src,Dest => Dest = Dest >> Src  (Arithmatic)
  - shrq Src,Dest => Dest = Dest >> Src  (Logical)
  - xorq Src,Dest => Dest = Dest ^ Src
  - andq Src,Dest => Dest = Dest & Src
  - orq Src,Dest => Dest = Dest | Src
  
- One Operand Instructions
  - incq Dest => Dest = Dest + 1
  - decq Dest => Dest = Dest - 1
  - negq Dest => Dest = -Dest
  - notq Dest => Dest = ~Dest
  
  ![](https://i.imgur.com/gQF8j5g.png)

  ![](https://i.imgur.com/0ULM5VO.png)
  
  [reference: artihmatic shift vs logical shift](https://open4tech.com/logical-vs-arithmetic-shift/)
  
  [reference:~ ! -](https://stackoverflow.com/questions/11572181/not-vs-negation)
  
---

#### P40
- Arithmetic Expression Example

```
long arith
(long x, long y, long z)
{
  long t1 = x+y;
  long t2 = z+t1;
  long t3 = x+4;
  long t4 = y * 48;
  long t5 = t3 + t4;
  long rval = t2 * t5;
  return rval;
}
```

```
arith:
  leaq (%rdi,%rsi), %rax     # t1
  addq %rdx, %rax            # t2
  leaq (%rsi,%rsi,2), %rdx   
  salq $4, %rdx              # t4
  leaq 4(%rdi,%rdx), %rcx    # t5
  imulq %rcx, %rax           # rval
  ret
```

---

#### P46

![](https://i.imgur.com/8Apgs32.png)


