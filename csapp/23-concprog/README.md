
#### P10
- Dealock: e.g. signal handler and main routine both execute printf()
  - main routine execute printf() which aquires a lock, and then got interrupted by signal handler that also execute printf(), and that printf() also aquires a lock that it won't be able to get it

---

#### P14
- iterative server: only process request from one client at a time
- Client 2:
  - connect: return immediatly, won't block
  - write: return immediatly, won't block
  - read: blocks

---

#### P16
- flow of iterative serers: might be block one client and won't be able to serve others

---

#### P25
- parent(listen new client): use listenfd, must close connfd
- child(serve client): use connfd, should close listenfd


---

#### P42
- context switch: less expensive for thread than for process, since thread has less context to associate with (lot of context are shared)
- Threads share all code and data (except local stacks)
  - but actually its the different portion of the same stack, and a thread can access a stack of any other thread(not a good thing to do though)
  
---

#### P49
- Must be careful to avoid unintended sharing
  - Pthread_create(&tid, NULL, thread, (void *)&connfd);
    - diffrent thread dereference the same address point to stack
    - can't assume that main thread and peer thread runs in a certain order
    - e.g. different thread might derefrence and get the same connfd value, then two thread will serve the same client
