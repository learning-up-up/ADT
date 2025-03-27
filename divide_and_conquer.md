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
```math
T(n) = 
    \begin{cases}
        T(1) & n = 1\\
        aT(n/b) + f(n) & n > 1
    \end{cases}
```
解这个递归式可以得到
```math
T(n) = n^{\log^a_b}[T(1) + u(n)]
```
其中，$`u(n) = \sum^k_{k = 1}h(b^k)`$

## 实际应用
### 残缺棋盘

### 二分搜索
前提：升序排好的序列。查找元素x，返回下标，若不存在返回-1（按习惯下标从0开始）

方法：先找最中间的元素$ q = n / 2 $，若等于x，直接返回下标；若不等于，再比较 $ *(a + q) > x $再递归查找 $ q + 1 < i < n $这一段。反之亦然。

#### 时间复杂度

n取值为$ [2^{k - 1}, 2^k) $时，最多做k此比较即可完成。时间复杂度为 $ O(\log n) $

#### 实现
```cpp
//数组降序排列
template <class T>
int BinSearch(T *a, int n, T x)
{
    int low = 1, high = n + 1;
    while (low < (high - 1))
    {
        int mid = (low + high) / 2;
        if(x < a[mid])
            high = mid;
        else
            low = mid;
    }
    if( x == a[low])
        return low;
    else 
        return 0;

}
```
减少了比较次数的优化版本

### max and min
