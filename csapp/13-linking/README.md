
#### P4
- gcc calls a series of translator cpp,cc1 and as
  - cpp: c preprocessor
  - cc1: c compiler
  - as: assebler
  
- .o file -> relocatable object file
  - relocatable: means they can be relocate and combine together
  
---

#### P6
- Why linker?
  1. Modularity(模組化)
    - many smaller source files instead of one monolithic mass
    - build libraries of common functions
  2. Efficiency
    - time: seperate compilation
      - change one source file, compile then relink
      - No need to recompile other sources
      - can compile multiple files concurrently
    - space: libraries
      - common function aggregate into a single file
      - Option 1: static linking
        - Executable files and running memory images contain only the library code they actually use
      - Option 2: Dynamic linking
        - Executable files contain no library code
        - During execution, single copy of library code can be shared across all executing processes

---

#### P7 - P9
- what do linkers do?
  1. Symbol resolution
    - program define and reference symbols(global variables and functions)
      ```
        void sum() {...} /* define symbol sum */
        sum();           /* reference symbol sum */
        int *xp = &x;    /* define symbol xp, reference x */
      ``
    - Symbol definitions are stored in object file (by assembler) in symbol table
      - Symbol table is an array of entries
      - Each entry includes name, size and location of symbol
    - During symbol resolution step, the linker associates each symbol reference with exactly one symbol definition
  2. Relocation
    - Merges separate code and data sections into single sections
    - Relocates symbols from their relative locations in the .o files to their final absolute memory locations in the executable
      - address in .o files are just **offset**
    - Updates all references to these symbols to reflect their new positions
    
---

#### P10 - P13
- Three kinds of Object Files(Modules)
  1. Relocatable object file (.o file)
    - generated by assembler
    - Each .o file is produced from exactly one source (.c) file
  2. Executable object file (a.out file)
    - generated by linker
  3. Shared object file (.so file)
    - Special type of relocatable object file that can be loaded into memory and linked dynamically, at either load time or run-time.
    - Called Dynamic Link Libraries (DLLs) by Windows
    
- Executable and Linkable Format(ELF)
  - Standard binary format for object files
  - One unified format for
    1. Relocatable object files (.o)
    2. Executable object files (a.out)
    3. Shared object files (.so)
  - Generic name: ELF binaries

- ELF Object File Format
  - Elf header
    - Word size, byte ordering, file type (.o, exec, .so), machine type, etc.
  - Segment header table
    - Page size, virtual addresses memory segments (sections), segment sizes.
  - .text section
    - Code
  - .rodata section
    - Read only data: jump tables, ...
  - .data section
    - Initialized global variables
  - .bss section
    - Uninitialized global variables
    - real name: “Block Started by Symbol”
    - how to memorize it: “Better Save Space”
    - Has section header but occupies no space
  - .symtab section
    - Symbol table
    - Procedure and static variable names
    - Section names and locations
  - .rel.text section
    - Relocation info for .text section
    - Addresses of instructions that will need to be modified in the executable
    - Instructions for modifying.
  - .rel.data section
    - Relocation info for .data section
    - Addresses of pointer data that will need to be modified in the merged executable
    - the note that assembler makes to the linker to say "hey you got to fix with this refrence cause... i don't know where this symbol is gonna store in memory when its loaded"
  - .debug section
    - Info for symbolic debugging (gcc -g)
  - Section header table
    - Offsets and sizes of each section

---

#### P14
-Linker Symbols
  1. Global symbols
    - Symbols defined by module m that can be referenced by other modules
    - E.g.: non-static C functions and non-static global variables
  2. External symbols
    - Global symbols that are referenced by module m but defined by some other module.
  3. Local symbols
    - Symbols that are defined and referenced exclusively by module m
    - E.g.: C functions and global variables defined with the static attribute
    - local non-static C variables: stored on the stack
    - local static C variables: stored in either .bss, or .data
    - **Local linker symbols are not local program variables**
    
  ![](https://i.imgur.com/3Sxu8Sc.png)
  
  ![](https://i.imgur.com/k8sMshV.png)

- Resolves Duplicate Symbol Definitions

  - Program symbols are either strong or weak
    - Strong: procedures and initialized globals
    - Weak: uninitialized globals
    
    ![](https://i.imgur.com/FMKpaoB.png)
    
  - Linker’s Symbol Rules
    - Rule 1: Multiple strong symbols are not allowed
      - Each item can be defined only once
      - Otherwise: Linker error
    - Rule 2: Given a strong symbol and multiple weak symbols, choose the strong symbol
      - References to the weak symbol resolve to the strong symbol
    - Rule 3: If there are multiple weak symbols, pick an arbitrary one
      - Can override this with gcc –fno-common (mutiple weak symbols will show linker error) 
      
    ![](https://i.imgur.com/S5WSty4.png)
    
      - in example three and four: if p2() write x it will consider it as doulbe so will write 8 bytes but the linker will link the address to the int x

    - avoid global variables if you can
    - otherwise
      - use static
      - initialize it
      - use extern if you reference an external global variable
      
    - Role of .h Files 
      - global.h
      ```c
      #ifdef INITIALIZE
        int g = 23;
        static int init = 1;
      #else
        extern int g;
        static int init = 0;
      ```
      - c1.c
      ```c
      #include "global.h"
      int f()
      {
        ...
      }
      ```
      - c2.c
      ```c
      #define INITIALIZE
      #include "global.h"

      int main(int argc,char** argc)
      {
        ...
      }
      ```
---

#### P21 - P25

![](https://i.imgur.com/pMgArPO.png)

- system code
  - startup code from libc
  - initial stuff
  - call main function
  - when main fucntion does a return , it return to this startup code and it does exit()
  
- Relocation Entries

  ![](https://i.imgur.com/YPXcomT.png)

  ![](https://i.imgur.com/p0JMEDB.png)
  
---

#### P26

![](https://i.imgur.com/wr1qkaa.png)

  - brk()/sbrk()
  
---

#### P28 - P41
- Functions Packaging
  - Option 1: put all functions into a single source file
    - Programmers link big object file into their programs
    - Space and time inefficient
  - Option 2: put each function in a seperate souce file
    - Programmers explicitly link appropriate binaries into their programs
    - More efficient, but burdensome on the programmer
    
- Static Libraries (.a archive files)
  - Old-fashioned way
  - Concatenate related relocatable object files into a single file with an index (called an archive).
  - Enhance linker so that it tries to resolve unresolved external references by looking for the symbols in one or more archives.
  - If an archive member file resolves reference, link it into the executable.

  ![](https://i.imgur.com/rOBB3gK.png)

  - commonly used libraries
    - libc.a(the C standard library)
    - libm.a(the c math library)
    - check what is in archive
      - ar –t libc.a | sort
      
- Linking with Static Libraries  

  ![](https://i.imgur.com/gFabKe6.png)
  
  - Linker’s algorithm for resolving external references:
    - Scan .o files and .a files in the command line order.
    - During the scan, keep a list of the current unresolved references.
    - As each new .o or .a file, obj, is encountered, try to resolve each unresolved reference in the list against the symbols defined in obj.
    - If any entries in the unresolved list at end of scan, then error.
    
  - Problem:
    - Command line order matters!
    - Moral: put libraries at the end of the command line.
    
    ![](https://i.imgur.com/OPLh2hV.png)

- disadvantage of static libraries
  - Duplication in the stored executables (every function needs libc)
  - Duplication in the running executables
  - Minor bug fixes of system libraries require each application to explicitly relink
      - Rebuild everything with glibc?
      - [issue](https://security.googleblog.com/2016/02/cve-2015-7547-glibc-getaddrinfo-stack.html)


- Shard Libraries (also called dynamic link libraries, .so or dll in windows system)
  - Modern solution
  - Object files that contain code and data that are loaded and linked into an application dynamically, at either load-time or run-time
  - load-time linking: linking occur when loaded and run
    - in Linux, handled automatically by the dynamic linker (ld-linux.so)
    - Standard C library usually dynamically linked (libc.so)
  - run-time linking: linking occur after program has begun
    - done by calls to the **dlopen()** interface
    - useful in: distributing software, high-performance web servers, runtime library interpositioning, ...
  - Shared library routines can be shared by multiple processes
  
- Linking with dynamic Libraries
  - requirement:
    - .interp section
      - Specifies the dynamic linker to use (i.e., ld-linux.so)
    - .dynamic section
      - Specifies the names, etc of the dynamic libraries to use
      - Follow an example of csim-ref from cachelab
      - E.g.: (NEEDED)    Shared library: [libm.so.6]
  - find where are the libraries: ldd
    
    ![](https://i.imgur.com/VcmuqT7.png)
    
   
  ![](https://i.imgur.com/J0zNw4E.png)

  ![](https://i.imgur.com/2FoULqS.png)
   
---

#### P42
- Linking summary
  - is a technique that allows programs to be constructed from multiple object files.
  - can happen at different times in a program’s lifetime
    1. Compile time (when a program is compiled)
    2. Load time (when a program is loaded into memory)
    3. Run time (while a program is executing)
    
---

#### P44 - 
- Library Interpositioning
