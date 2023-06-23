#if !defined(__BINTREE_INSERT__)
#define __BINTREE_INSERT__

template <typename T>
BinNodePosi<T> BinTree<T>::insertAsRoot(T const& e)
{
    _size = 1;
    return _root = new BinNode<T>(e);
}

template <typename T>
BinNodePosi<T> BinTree<T>::insertAsLC(BinNodePosi(T) x, T const& e) // e作为x的左孩子
{
    _size++;
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lc;
}

BinNodePosi<T> BinTree<T>::insertAsRC(BinNodePosi(T) x, T const& e) // e作为x的右孩子
{
    _size++;
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rc;
}
#endif // __BINTREE_INSERT__
