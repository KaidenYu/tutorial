
#### P22
- rader thread: doesn't write(modify) the object, so no need to protect


#### additional info(old lecture)

- ![](https://i.imgur.com/IYeP7SX.png)

- worker thread do call the initilization function

  ```C
  ...
  static pthread_once_t once = PTHREAD_ONCE_INIT;
  Pthread_once(&once, init_echo_cnt);
  ...
  ```
---

#### P38
- picture form old lecture slides
  ![](https://i.imgur.com/MCV5iLr.png)
  - deref: dereference
  
---

#### P46
- deadlock
  - ![](https://i.imgur.com/6Q2uqMU.png)
  - ![](https://i.imgur.com/qhyO6Ua.png)
  - only to make sure the deadlock zone is filled, so doesn't need to change order of V() since P() already changed
  
  
  
