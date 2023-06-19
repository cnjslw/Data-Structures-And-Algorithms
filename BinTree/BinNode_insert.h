#ifndef __BINNODE_INSERT__
#define __BINNODE_INSERT__

template <typename T>
BinNode<T> BinNode<T>::BinNodePosi<T> insertAsLC(T const& e)
{
    return lc = new BinNode(e, this); // 当成左孩子插入当前节点
}

template <typename T>
BinNode<T> BinNode<T>::BinNodePosi<T> insertAsRC(T const& e)
{
    return rc = new BinNode(e, this); // 当成右孩子插入当前节点
}
#endif