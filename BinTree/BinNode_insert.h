#ifndef __BINNODE_INSERT__
#define __BINNODE_INSERT__

template <typename T>
BinNodePosi<T> BinNode<T>::insertAsLC(T const& e)
{
    return lc = new BinNode(e, this); // 当成左孩子插入当前节点
}

template <typename T>
BinNodePosi<T> BinNode<T>::insertAsRC(T const& e)
{
    return rc = new BinNode(e, this); // 当成右孩子插入当前节点
}
#endif