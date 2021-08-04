## 线性表
#### 1.顺序表

顺序存储方式，元素逻辑、物理上都相邻，即连续存储

优点：随机存取，快速定位

缺点：插、删时需要移动大量元素

#### 2.链表
- 单链表

    链式存储，逻辑相邻，物理上不一定相邻
   
    优点：插、删方便
      
    缺点：难以定位

  ```C
  //利用C创建结构体
  typedef struct Londe{
    ElemType data;
    struct Lnode *next;
  }Lnode, *Linklist
  ```
- 双链表
