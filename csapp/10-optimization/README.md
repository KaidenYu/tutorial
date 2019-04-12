#### P6 - P7
- Code Motion
Reduce frequency with which computation performed
 - If it will always produce same result
 - Especially moving code out of loop

![](https://i.imgur.com/vtxRn9Q.png)

![](https://i.imgur.com/FI05H8v.png)

---

#### P8
- Reduction in Strength
  - Replace costly operation with simpler one
  - Shift, add instead of multiply or divide
    - 16*x --> x << 4
    - Utility is machine dependent
    - Depends on cost of multiply or divide instruction
      - On Intel Nehalem, integer multiply requires 3 CPU cycles
  - Recognize sequence of products
  
![](https://i.imgur.com/doRFk7G.png)

---

#### P9
- Share Common Subexpressions
  - Eeuse portions of expressions
  - GCC will do this with –O1
  
![](https://i.imgur.com/yBZTqeA.png)

---

#### P10 - P16
- Optimization Blocker #1: Procedure Calls

![](https://i.imgur.com/8VxmpXE.png)

![](https://i.imgur.com/KDbk90o.png)

![](https://i.imgur.com/xT1CTqe.png)

![](https://i.imgur.com/sDJkZUO.png)

![](https://i.imgur.com/LdVycKp.png)

![](https://i.imgur.com/lSPEZtw.png)


- Why couldn’t compiler move strlen out of inner loop?
  - Procedure may have side effects
    - Alters global state each time called
  - Function may not return same value for given arguments
    - Depends on other parts of global state
    - Procedure lower could interact with strlen
    
    ![](https://i.imgur.com/BkM9Jf3.png)

- Warning:
  - Compiler treats procedure call as a black box
  - Weak optimizations near them
- Remedies: 
  - Use of inline functions
    - GCC does this with –O1
      - Within single file
  - Do your own code motion

---

#### P17
- Memory
  
  ![](https://i.imgur.com/i84JeoU.png)

  ![](https://i.imgur.com/vnizVa7.png)

  ![](https://i.imgur.com/REDfieh.png)
  
  - access register instead of memory  
  
  **the example can't compiled**: double B[3] should be double* B or something?
  
  ![](https://i.imgur.com/rsg6imX.png)
  
  
  



register renaming & prediction
https://en.wikipedia.org/wiki/Register_renaming
