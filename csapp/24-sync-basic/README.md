
#### additional info
1. joinable: fork and join model
2. https://computing.llnl.gov/tutorials/pthreads/#Compiling

---

#### P11
- i.m, msgs.m, tid.m: m means stack of main
- mypid.p0, mypid.p1: p0 means stack of peer thread 0, p1 means stack of peer thread 1

---

#### P18
- Pthread_create(&tid1, NULL,thread, &niters);
  - it's ok to pass address of niters which is a local variable of main, because it's not modified (only read)
  
---

