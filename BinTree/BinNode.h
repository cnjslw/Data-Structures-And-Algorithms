#ifndef __BinNode__
#define __BinNode__

template <typename T>
struct BinNode;
template <typename T>
using BinNodePosi = BinNode<T>*;

template <typename T>
struct BinNode {
    // members
    T data;
    BinNodePosi<T> parent, r, l;
    int height;
    // Constructor
    BinNode()
        : parent(nullptr)
        , lc(nullptr)
        , rc(nullptr)
        , height(0)
    {
    }

    BinNode(T e, BinNodePosi<T> p = nullptr, BinNodePosi<T> lc = nullptr, BinNodePosi<T> rc = nullptr, int h = 0)
        : data(e)
        , parent(p)
        , lc(lc)
        , rc(rc)
        , height(h)
    {
    }

    // interface
    int size();
    BinNodePosi<T> insertAsLC(T const&);
    BinNodePosi<T> insertAsRC(T const&);
    BinNodePosi<T> succ();
    template <typename VST>
    void travLevel(VST&); // 层序遍历
    template <typename VST>
    void travPre(VST&); // 先序遍历
    template <typename VST>
    void travIn(VST&); // 中序遍历
    template <typename VST>
    void travPost(VST&); // 后序遍历
    template <typename VST>
    /*DSA*/ void traverse(VST&); // 自定义遍历

    // 比较器
    bool operator<(BinNode const& bn) { return data < bn.data; }
    bool operator<(BinNode const& bn) { return data == bn.data; }

    /*DSA*/
    /*DSA*/ BinNodePosi<T> zig(); // 顺时针旋转
    /*DSA*/ BinNodePosi<T> zag(); // 逆时针旋转
    /*DSA*/ BinNodePosi<T> balance(); // 完全平衡化
    /*DSA*/ BinNodePosi<T> imitate(); // 逆时针旋转
};
#include "BinNode_implementation.h"
#endif