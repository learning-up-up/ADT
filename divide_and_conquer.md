# 分治策略
对于集合A的一个问题Q，将集合A划分为若干个子集，解决在子集上的问题Q，再将每个子集的结果拼接成A的结果称之为分治策略。我们往往可以进行重复分治直到问题在子集上足以简便解决。
## 控制抽象
```cpp
Type DAndC(P)
{
    if(Small(P))//Small(P)用来判断P是否足够小可以简便解决
        return S(P);//S(P)是解决结果
    else
    {
        //将P划分为更小的实例P1，P2，……Pk
        //再在每个子集上执行DAndC
        return combine(DAndC(P1),~);
    }
}
```
## 复杂度
$$
    T(n) = 
    \begin{cases}
        T(1) & n = 1\\
        aT(n/b) + f(n) & n > 1
    \end{cases}
$$
解这个递归式可以得到
$$
    T(n) = n^{\log^a_b}[T(1) + u(n)]
$$
其中，$u(n) = \sum^k_{k = 1}h(b^k)$