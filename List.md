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
节点模板
```
template<class T>
class Link
{
private:
    T data;
    T* next;//下一个节点的位置
}
```
链表模板：
```
template <class T>
class List
{
ptivate:
    Link<T>* header;//头节点
    Link<T>* tralier;//尾节点
public：
    Pred()//curr移动到前驱
    Next()//curr移动到后继
    //构造方法，遍历方法……
};
```
