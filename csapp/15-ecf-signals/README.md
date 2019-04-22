#### P7

![](https://i.imgur.com/LSqWYpc.png)

- pstree

![](https://i.imgur.com/bGsDzov.png)

---

#### P8 - P20
- shell: an application program that runs programs on behalf of the user
  - sh: Original Unix shell (Stephen Bourne, AT&T Bell Labs, 1977)
  - csh/tcsh: BSD Unix C shell
  - bash: “Bourne-Again” Shell (default Linux shell)

- simple shell
  - basic loop: read and evaluate(parse)
  - evaluate:
    - builtin command:runs in shell program
    - program: fork/exec
      - foreground: wait until its done
      - background: print PID and continue
      
- problem with simple shell
  - background jobs
    1. become zombies when terminate
    2. never reaped cause simple shell won't terminate
    3. memory leak!!!
  - solution: exceptional control flow-> signal
  
---

#### P23 - P29
- signal: a small message that notifies a process that an event of some type has occurred in the system
  - from: kernel
    - kernel sends when:
      1. Kernel has detected a system event such as divide-by-zero (SIGFPE) or the termination of a child process (SIGCHLD)
      2. Another process has invoked the kill system call to explicitly request the kernel to send a signal to the destination process
  - to: process
    - process receive when:
      1. A destination process receives a signal when it is forced by the kernel to react in some way to the delivery of the signal
    - ways of process to react after receiving:
      1. ignore
      2. terminate
      3. catch: will execute a **user-level** function called signal handler(kinda like hardware exception handler in kernel space)
  - information: Only information in a signal is its ID and the fact that it arrived

- [reference](https://www.tutorialspoint.com/unix/unix-signals-traps.html)

- ![](https://i.imgur.com/jnyvzLj.png)

---

#### P30 - P45
- signal concepts:
  - pending: A signal is pending if sent but not yet received
    - at most one pending signal of any type
    - signals are not queued: If a process has a pending signal of type k, then subsequent signals of type k that are sent to that process are discarded
    - a pending signal is received at most once
  - blocked: A process can block the receipt of **certain** signals (not all!!!)
    - Blocked signals can be delivered, but will not be received until the signal is unblocked

  - pending and blocked bit vectors
    - Kernel maintains pending and blocked bit vectors in the context of **each** process
    - pending:
      - Kernel sets bit k in pending when a signal of type k is delivered
      - Kernel clears bit k in pending when a signal of type k is received
    - blocked::
      - Can be set and cleared by using the **sigprocmask** function
      - Also referred to as the signal mask
      
- sending signals:
  1. kill program (/bin/kill)
    - send arbitrary signal to a process or process group
      - e.g. /bin/kill –9 24818 -> send SIGKILL to process 24818 where -9 means ID 9 means SIGKILL
      - e.g. /bin/kill –9 –24817 -> send SIGKILL to process group 24817
    
  2. keyboard
    - ctrl-c: SIGNIT
      - default action is to terminate each process
    - ctrl-z: SIGTSTP
      - default action is to stop (suspend) each process
    
  3. kill function
    - e.g. kill(PID, SIGINT);
    
- receiving signals:
  - Suppose kernel is returning from an exception handler and is ready to pass control to process p (context switch)
    1. kernel computes pnb = pending & ~blocking
    2. if(pnb==0)
      - Pass control to next instruction in the logical flow for p
    3. if(pnb!=0)
      - Choose least nonzero bit k in pnb and force process p to receive signal k
      - The receipt of the signal triggers some action by p
      - Repeat for all nonzero k in pnb
      - Pass control to next instruction in logical flow for p
  - predefined default actions:
    1. The process terminates
    2. The process stops until restarted by a **SIGCONT** signal
    3. The process ignores the signal
  - installing signal handlers:
    - handler_t *signal(int signum, handler_t *handler)
      - Different values for handler
        1. SIG_IGN: ignore signals of type signum
        2. SIG_DFL: revert to the default action on receipt of signals of type signum
        3. address of a user-level signal handler:
          - Called when process receives signal of type signum
          - Referred to as “installing” the handler
          - Executing handler is called “catching” or “handling” the signal
          - When the handler executes its return statement, control passes back to instruction in the control flow of the process that was interrupted by receipt of the signal
    
    - ![](https://i.imgur.com/5TL6XnO.png)
    
      - nested signal handlers: Handlers can be interrupted by other handlers
    
  - Blocking and Unblocking Signals
    - implicit blocking mechanism
    - explicit blocking and unblocking mechanism
      - **sigprocmask** function
      - supporting functions
        - sigemptyset – Create empty set
        - sigfillset – Add every signal number to set
        - sigaddset – Add signal number to set
        - sigdelset – Delete signal number from set

---

#### P52

```
while ((pid = wait(NULL)) > 0)
```
- If any process has no child process then wait() returns immediately “-1”.
- [reference](https://www.geeksforgeeks.org/wait-system-call-c/)
  
