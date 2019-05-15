
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
