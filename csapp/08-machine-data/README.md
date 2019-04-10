#### P6
```c
#define ZLEN 5
typedef int zip_dig[ZLEN];
zip_dig cmu = { 1, 5, 2, 1, 3 };
zip_dig mit = { 0, 2, 1, 3, 9 };
zip_dig ucb = { 9, 4, 7, 2, 0 };
```

- Declaration “zip_dig cmu” equivalent to “int cmu[5]”

---

#### P11

![](https://i.imgur.com/lWgrmuY.png)

---

#### P14

![](https://i.imgur.com/3SAN2QP.png)

- int (*A3)[3]: A3 is a pointer to array[3] of int

---

### Additional info

[C Operator Precedence](https://en.cppreference.com/w/c/language/operator_precedence)
```
- char *x;         // x: a pointer to char
- char x[3];       // x: an array[3] of char
- char x();        // x: a function() returning char
- char *x[3];      // x: an array[3] of pointer to char
- char (*x)[3];    // x: a pointer to array[3] of char
- char **x;        // x: a pointer to pointer to char
- char *x();       // x: a function() returning pointer to char
- char *x()[3];    // x: a function() returning array[3] of pointer to char
- char (*x[])();   // x: an array[] of pointer to function() returning char
- char (*x())();   // x: a function() returning pointer to function() returning char
- char (*(*x)[])(int, int); // x: a pointer to array[] of pointer to function(int,int) returning char
```

---

#### P20

![](https://i.imgur.com/otBUXWL.png)

---

#### P21 - P23

![](https://i.imgur.com/b7H7EuD.png)

![](https://i.imgur.com/d7l6zsl.png)

![](https://i.imgur.com/DeG9dtj.png)

---

#### P24 - P26

![](https://i.imgur.com/UuxrxWa.png)

![](https://i.imgur.com/ISSDKIy.png)

![](https://i.imgur.com/o9DYQDA.png)

---

#### P31 - P32

![](https://i.imgur.com/rfX29jz.png)

![](https://i.imgur.com/xc3aqgQ.png)

---

####




