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

#### P16 - P19
- Reading Condition Codes
  - Setx instructions
    - Set low-order byte of destination to 0 or 1 based on combinations of condition codes
    - Does not alter remaining 7 bytes

  ![](https://i.imgur.com/KY5ZHGc.png)
  
  ![](https://i.imgur.com/XBQyulO.png)
  
  - al,bl, ... where "l" means low


  ![](https://i.imgur.com/ajLADph.png)
  
  ![](https://i.imgur.com/6Wr8dCL.png)
  
  - movzbl: move with zero extention from byte to long (but automatically set the higher 32bits to zero as well...confusing)

---

#### P21
- jX Instructions
  - Jump to different part of code depending on condition codes
  
  ![](https://i.imgur.com/cdsV5Gv.png)
  
  - ja: jump above. refer to the "switch Statements"

---

#### P23 - P25
- Conditional Branch
- command line: gcc –Og -S –fno-if-conversion control.c
  - –fno-if-conversion: disable predication(not all), so we can see the branch in assembly code

```c
long absdiff(long x, long y)
{
  long result;
  if (x > y)
    result = x-y; //blue part of assembly code
  else
    result = y-x; //red part of assembly code
  return result;
}
```
![](https://i.imgur.com/JKmhIop.png)

- expressing with goto code
```c
long absdiff_j(long x, long y)
{
  long result;
  int ntest = x <= y;
  if (ntest) goto Else;
  result = x-y;
  goto Done;
Else:
  result = y-x;
Done:
  return result;
}
```

- General Conditional Expression Translation
  - Create separate code regions for then & else expressions
  - Execute appropriate one
  
```c
val = Test ? Then_Expr : Else_Expr;
```
```c
  ntest = !Test;
  if (ntest) goto Else;
  val = Then_Expr;
  goto Done;
Else:
  val = Else_Expr;
Done:
  ...
```
---

#### P26 - P28
- Conditional Moves
  - Instruction supports:
    - if(Test) Dest <- Src
    - Ex. cmovle %rdx %rax # if <=, then move
  - Supported in post-1995 x86 processors
  - GCC tries to use them if known to be safe
- Why Conditional Moves?
  - Branches are very disruptive to instruction flow through pipelines
  - Conditional moves do not require control transfer

```c
long absdiff(long x, long y)
{
  long result;
  if (x > y)
    result = x-y;
  else
    result = y-x;
  return result;
}
```
![](https://i.imgur.com/rfOQuRM.png)

![](https://i.imgur.com/kvefjkG.png)

```c
val = Test ? Then_Expr : Else_Expr;
```
```
  result = Then_Expr ;
  eval = Else_Expr;
  nt = !Test;
  if (nt) result = eval;
  return result;
```


- Bad Case for Conditional Move
  1. Expensive Computations (bad performance)
    - since both values get computed, only makes sense when computations are very simple 
    - Ex. val= Test(x) ? Hard1(x):Hard2(x)
  2. Risky Computations (unsafe)
    - may have undesirable effects 
    - Ex. val = p ? *p : 0
  3. Computations with side effects
    - Ex. val = x > 0 ? x*=7 : x+=3;


ja -> jump above , unsigned

---

#### P30 - P39
- Exercise

![](https://i.imgur.com/7WGCmDd.png)


---

#### P32 - P36
- Do-while Loop
  - Example:
    - C code
    ```c
    long pcount_do(unsigned long x) 
    {
      long result = 0;
      do {
        result += x & 0x1;
        x >>= 1;
      } while (x);
      return result;
    }
    ```
    - goto version
    ```c
    long pcount_goto(unsigned long x) 
    {
      long result = 0;
    loop:
      result += x & 0x1;
      x >>= 1;
      if(x) goto loop;
      return result;
    }
    ```
  - general translation
  
  ![](https://i.imgur.com/NSU82XT.png)

---

#### P37
- While Loop
  - Example:
    - C code
    ```c
    long pcount_while(unsigned long x)
    {
      long result = 0;
      while (x) {
       result += x & 0x1;
        x >>= 1;
      }
      return result;
    }
    ```
    - goto version
    ```
    long pcount_goto_jtm(unsigned long x)
    {
      long result = 0;
      goto test;
    loop:
      result += x & 0x1;
      x >>= 1;
    test:
      if(x) goto loop;
      return result;
    }
    ```
    - do-while goto version
    ```
    long pcount_goto_dw(unsigned long x)
    {
      long result = 0;
      if (!x) goto done;
    loop:
      result += x & 0x1;
      x >>= 1;
      if(x) goto loop;
    done:
      return result;
    }
    ```
  - general translation
  
  ![](https://i.imgur.com/8Etnm3E.png)
  
---

#### P40 - P44
- For Loop
  - Example:
    - C code
    ```c
    #define WSIZE 8*sizeof(int)
    long pcount_for(unsigned long x)
    {
      size_t i;
      long result = 0;
      for (i = 0; i < WSIZE; i++)
      {
        unsigned bit =
          (x >> i) & 0x1;
        result += bit;
      }
      return result;
    }
    ```
    - while goto version
    ```c
    long pcount_for_while(unsigned long x)
    {
      size_t i;
      long result = 0;
      i = 0;
      while (i < WSIZE)
      {
        unsigned bit =
          (x >> i) & 0x1;
        result += bit;
        i++;
      }
      return result;
    }
    ```
    - do-while goto version
    ```c
    long pcount_for_goto_dw(unsigned long x) 
    {
      size_t i;
      long result = 0;
      i = 0;
      if (!(i < WSIZE)) //this two lines of check and goto could be removed
        goto done;      //cause compiler knows that i=0 
    loop:
      unsigned bit =
        (x >> i) & 0x1; 
      result += bit;
      i++; 
      if (i < WSIZE)
        goto loop;
    done:
      return result;
    }
    ```
  - general translation
  
  ![](https://i.imgur.com/YGplXxW.png)


---

#### P45
- Switch Statement
  - Example:
  ```c
  long switch_eg
  (long x, long y, long z)
  {
    long w = 1;
    switch(x) {
      case 1:
        w = y*z;
        break;
      case 2:
        w = y/z;
        /* Fall Through */
      case 3:
        w += z;
        break;
      case 5:
      case 6:
        w -= z;
        break;
      default:
        w = 2;
    }
    return w;
  }
  ```
    - Multiple case labels: 5 & 6
    - Fall through cases: 2
    - Missing cases: 4
  
  ![](https://i.imgur.com/fj5N9a1.png)
  
  ![](https://i.imgur.com/ektHKXY.png)

  ![](https://i.imgur.com/ektHKXY.png)

    - Table Structure
      - Each target requires 8 bytes (64bit cpu)
      - Base address at .L4
    - Jumping
      1. Direct: ja .L8 (for x<0 & x>6) 
        - Jump target is denoted by label .L8
      2. Indirect: jmp *.L4(,%rdi,8)  (for 0 ≤ x ≤ 6)
        - Start of jump table: .L4
        - Must scale by factor of 8 (addresses are 8 bytes)
        - Fetch target from effective Address .L4 + x*8

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
