## 神奇的兔子
实际上是斐波那契数列

F(n)=F(n-1)+F(n-2)  (n>2)

F(n)=1  (n=1,2)

```c++
//指数复杂度
Fib(int n)
{
  if(n<1)
    return -1;
  else if(n=1||n=2)
    return 1;
       else
        return fib(n-1)+fib(n-2);
}
```
