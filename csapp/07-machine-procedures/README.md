
ret = retq same instruction (C3)

if rbp is optional,how do we know the length of stack frame to deallocate when retq?
there are some cases that we need to use rbp


movl $3000, %esi
although esi is 32bits but but doing this the upper bits(rsi) will be set to zero

je=jump if equal
jz=jump if zero
basically je and jz are same instruction ("74" or "0F 84")
