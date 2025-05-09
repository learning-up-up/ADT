<script type="text/javascript" async
    src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML">
</script>

# 相关术语
## 树的定义
节点的集合，存在一个特殊的根节点，其余的节点可以被划分为n个不相交的集合，其中每个集合仍是一个树，称为根节点的子树。这是对树的递归定义

## 延伸概念
* 度： 一个节点的子树的个数
* 叶（终止节点）： 度为0的节点
* 孩子： 节点X的子树的根称为X的孩子
* 父节点： 节点X是他孩子节点的父节点
* 层次与深度： 根节点在第0层，根节点的孩子在第1层，依此类推。树的深度是树中节点的最大层次（节点有时也定义成第1层）
* 有序性：如果节点的每个孩子有顺序，不可交换，则称为有序树，否则称为无序树

# 二叉树

每个节点最多只有两个子节点，且是有序的可以分为左子树和右子树

## 特殊的二叉树
* 满二叉树：顾名思义，所有的节点都有两个子节点，且所有的叶都在同一层上。类似于一个完整的塔式结构
* 完全二叉树：除了最后一层外，其他层都是满的，最后一层的节点从左到右依次排列。类似于一个不完整的塔式结构

## 存储实现

### 顺序实现

直接用一个数组来存储二叉树的节点，根节点存储在数组的第一个元素中，假设节点的下标为i，其父节点的下标就是$`\lfloor (i+ 1)/2\rfloor`$，则其左子树和右子树的下标分别为$2i+1$和$2i+2$。


### 链式实现

对于每个节点，其实现如下

```cpp
struct Node
{
    int data;
    Node* lchild;
    Node* rchild;
    //Node* parent 父节点指针是可有可无的，包含父结点指针的定义方法称为三叉链表
};
```

树结构实现
```cpp
class Tree
{
private:
    Node* root;
public:
    Tree(){root = NULL;}
    ~Tree();
    void Insert(int x);
};
```
### 遍历实现
存在三种遍历方法：前序遍历，中序遍历，后序遍历

代表了当前节点相对其左右子树的访问顺序，但注意左子树总是优先于右子树访问

```cpp
//这是前序遍历的实现
void Tree::visit(*Node p = root)
{
    printf("%d\n",p);
    if (!p->lchild)
        visit(p->lchild);
    if (!p->rchild)
        visit(p->rchild);
}

//中序遍历
void Tree::visit(*Node p = root)
{
    if(!p->lchild)
        visit(p->lchild);
    printf("%d\n",p);
    if(!p->rchild)
        visit(p->rchild);
}
```

遍历的应用
编译器运算处理
对于一个计算表达式的二叉树结构，往往可以使用后续遍历来实现逆波兰式的生成，再进一步通过栈结构进行运算

