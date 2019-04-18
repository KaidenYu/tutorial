
#### P3 - P6
EDC -> error detection and correction

- volatile memory:lose information if powered off
  - RAM(random access memory)
    - SRAM(static RAM): Cache
    - DRAM(dynamic RAM): main memories, frame buffers
      - SDRAM(synchronous DRAM)
      - DDR SDRAM(double data-rate synchronous DRAM)
        -DDR(2bits), DDR2(4bits), DDR3(8 bits), DDR4
- nonvolatile memory
  - ROM
  - PROM
  - EPROM
  - EEPROM
  - Flash memory
    - NAND Flash
    - NOR Flash
    - EE-NOR Flash

---

#### P7

I/O bridge: a colletion of chips, Intel call it "chipset"

---

#### P18

in old day: each track has same number of sectors --> track is more far from the center has bigger gap --> waste

the data size of a sector is always a power of two, and is almost always 512 bytes. 

---

#### P32

seek time -> mechanical limits

---

#### P35

logical disk block
“formatted capacity” and “maximum capacity”. some of those cylinders are reserved for failure

---

#### P36
PCI bus:boradcast bus, only a single set of wire.Any device change the value of the wire, every device on that bus can see this value
PCI express:modern system.point to point

----

#### P40
flash translation layer:firmware(like the disk controller on hard disk)

---

#### P45
- cpu cycle time:
  - before 2003: make cpu faster by double the clock frequency. decrease the feature size of the chip they are making ,put things closer
  - after 2003: 
      - processor design hit the power wall: power consumption is proportional to frequency (the higer the frequency, the more power you comsume)
      - 2003 the processor that intel is ready to ship was going to burn 800W power with gigantic heat sink about 4 square inches
      - put more processor cores onto the chips
