操作方式可分为
* 静态 仅读取
* 动态 可改变

数据结构也可以这样分类
* 静态
* 动态

# 链表（List）
典型的动态存储方式
## 结构

### 元素（node）

### 指针域

各个节点之间通过指针或引用彼此连接，各相邻节点彼此互称为前驱和后继

列表通过节点连接，理论上也存在秩，但是循秩访问的效率相当低，应使用循位置访问

## 接口与实现
### 节点模板
```cpp
template<class T>
class Link
{
private:
    T data;
    Link* next;//下一个节点的位置
    Link* pree;//上一个节点
public:

}
```
### 链表模板：
```cpp
template <class T>
class List
{
ptivate:
    Link<T>* header;//头节点
    Link<T>* tralier;//尾节点
public：
    init();
    Pred()//curr移动到前驱
    Next()//curr移动到后继
    //构造方法，遍历方法……
};
```
###  初始化
```cpp
template <class T> 
void List<T>::init()
{
    header = new Listnode<T>;
    trailer = new LIstnode<T>;
    header->next = trailer;
    header_>pree = NULL;
    trailer->pree = header;
    trailer->next = NULL;
    -size = 0;
}
```
### 插入

```cpp
template <class T>
void List<T> InsertBefore(Listnode* p, T const& d)
{
    _size++;
    Listnode* x = new Listnode(d, pree, this);
    pree->next = x;
    pree = x;//建立连接
}
```

衍生算法有
#### 复制构造
```cpp
template <class T>
void Listnode::Copy(Listnode* p, int n)
{
    init();//initialize
    while(n--)
    {
        Insetbefore(trailer, p->data);
        p = p->next;
    }
}
```

### 删除
```cpp
template <class T>
void List::remove(Listnode* p)
{
    (p->pree)->next = p->next;
    (p->next)->pree = p->pree;
    delete p;
    _size--;
}
```

#### 析构
先将所有内部节点删除，在释放头节点和尾节点

### 查找
以某一结点为基准，在它的n个前驱中，寻找最近的一个符合条件的位置，返回位置或无

也可以直接遍历这个链表

#### 去重

```cpp
template <class T>
int List<T>::deduplicate()
{
    if(_size < 2)
    return 0;
    int oldsize = _size;
    Listnode* = header->pree;
    int r = 1;//秩
    while(trailer != (p = p->next))//依次遍历到末节点
    {
        Listnode * q = find(p->data, r, p);//在前趋中依次查找
        q ? remove(q) : r++;
    }
    return oldsize -size;
}
### 