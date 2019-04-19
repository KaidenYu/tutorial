
#### P8
- types of cache miss
  1. cold(compulsory) miss
  2. conflict miss
  3. capacity miss

---

#### P13
- Cache organization
  - S(sets)
  - E(lines per sets)
  - B(bytes per block(line))

---

#### additional info
> how many bits does the "tag" contain?
> ![](https://i.imgur.com/9iuZAcB.png)
> ![](https://i.imgur.com/shI2SGm.png)

---

#### P23
- write
  - hit
    - Write-through (write immediately to memory)
    - Write-back (defer write to memory until replacement of line)
      - Need a dirty bit (line different from memory or not)
  - miss
    - Write-allocate (load into cache, update line in cache)
      - Good if more writes to the location follow
    - No-write-allocate (writes straight to memory, does not load into cache)
    
- typical
  - Write-through + No-write-allocate
  - **Write-back + Write-allocate**

---

#### P47 - P53

![](https://i.imgur.com/ADq4gz3.png)

![](https://i.imgur.com/qim1HB0.png)

![](https://i.imgur.com/dFI5KmC.png)

![](https://i.imgur.com/WqaY4Jl.png)

![](https://i.imgur.com/2LydBa8.png)

![](https://i.imgur.com/Is6oH2k.png)

![](https://i.imgur.com/rzEUwxW.png)
