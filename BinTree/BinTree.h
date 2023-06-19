#ifndef __BinTree__
#define __BinTree__
#include "BinNode.h"
template <typename T>
class BinTree {
protected:
    int _size; // 规模
    BinNodePosi(T) _root; // 根节点
    virtual int updateHeight(BinNodePosi(T) x); // 更新节点x的高度
    void updateHeightAbove(BinNodePosi(T) x); // 更新节点x及其祖先的高度
public:
    BinTree()
        : _size(0)
        , _root(nullptr)
    {
    }
    ~BinTree()
    {
        if (0 < _size)
            remove(_root);
    }
    int size() const { return _size; } // 规模
    bool empty() const { return !_root; } // 判空
    BinNodePosi<T> root() const { return _root; } // 返回根节点
    
};

#endif
