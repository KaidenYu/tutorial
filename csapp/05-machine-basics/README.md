#### P4
- Complex instruction set computer (CISC) - x86
- Reduced Instruction Set Computers (RISC) - ARM
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
- Assembly charactor:data type
  - “Integer” data of 1, 2, 4, or 8 bytes (don't distinguish signed or unsigned)
    1. Data values
    2. Addresses (untyped pointers)
  - Floating point data of 4, 8, or 10 bytes
  - (SIMD vector data types of 8, 16, 32 or 64 bytes)
#### additional info
![](https://i.imgur.com/8NAC3Oz.png)
![](https://i.imgur.com/kdE4W9o.png)
