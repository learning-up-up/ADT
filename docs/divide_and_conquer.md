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

对于分治算法，其重要的步骤是划分问题并进行递归，对于该问题，经典的遍历比较与分治算法的比较复杂度为 $ O(n) $，但分治算法在递归过程中进行入栈和出栈的过程是一个效率较低的过程，导致分治算法并没有明显的性能提升，反而在递归层数较多时性能有明显下降。

### 排序

#### 归并排序

基本思想：将一个序列分成两个序列，分别对两个序列进行排序之后，再对两个排序进行合并。合并的过程中，由于两个序列都是有序的，因此可以通过逐次由左到右比较两个序列的最小值，来实现合并。

```cpp
void Merge(int *a, int n)
{
    int *b = new int[n];//在这里开辟新数组来进行合并

    int i = 0, j = n / 2;

    while((i < n / 2) && (j < n))
    {
        if(a[i] < a[j])
            b[i + j++] = a[i++];
        else
            b[i + j++] = a[j++];
    }
    
    if(i >= n / 2)
    {
        while(j < n)
            b[i + j++] = a[j++];
    }
    if(j >= n)
    {
        while(i < n / 2)
            b[i + j++] = a[i++];
    }
    for(int k = 0; k < n; k++)
        a[k] = b[k];
    delete[] b;
}
void Sort(int *a, int n)
{
    // n = 1时，就不必再排序了
    if(n > 1)
    {
        //划分
        Sort(a, n / 2);
        Sort(a + n / 2, n - n / 2);
        //合并
        Merge(a, n);
    }
}
```

##### 时间复杂度
最坏的情况下，Merge操作需要进行$ n - 1 $次比较，考虑其时间复杂度
```math
T(n) = 
    \begin{cases}
        T(1) = a, n = 1\\
        2T(n / 2) + n - 1 & n \geq 2
    \end{cases}
```
解这个递归式,当$n = 2^k$时
```math
    \begin{equation*}
        \begin{split}
            T(n)& = T(2^k)\\
            & = 2T(2^{k - 1}) + 2^k - 1\\
            & =\dots\\
            & =2^kT(1) + k(2^{k} - 1) + 1\\
            & =an + (n-1)\log n + 1
        \end{split}
    \end{equation*}
```
因此时间复杂度为 $ O(n \log n) $

#### 快速排序

```cpp
template <class T>
void Sort(T* pa ,int n)
{
    if(n == 0 || n == 1)
        return;
    else
    {
        int l = -1, r = n;
        int flag = *pa;
        while(l < r)
        {
            do
                l++;
            while (*(pa + l) < flag);

            do
                r--;
            while (*(pa + r) > flag);

            if(l < r)
                swap(*(pa + l), *(pa + r));
            
        }
        swap(*pa, *(pa + r));
        Sort(pa, r + 1);
        Sort(pa + r + 1, n - r - 1);
        
    }
}
```

##### 时间复杂度

平均时间下，时间复杂度为$` O(n \log n) `$，最坏时间复杂度为$` O(n^2) `$

#### 排序的稳定性

稳定性是指在排序过程中，若两个元素相等，则它们在排序前后的相对位置不变。对于基于分治算法的两种排序，归并排序为稳定排序，而快速排序则不是稳定排序。

### 选择
