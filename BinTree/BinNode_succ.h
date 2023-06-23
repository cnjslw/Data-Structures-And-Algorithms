#if !defined(__BINNODE_SUCC__)
#define __BINNODE_SUCC__

template <typename T>
BinNodePosi<T> BinNode<T>::succ()
{
    BinNodePosi<T> s = this;
    if (rc) {
        s = rc;
        while (HasLChild(*s))
            s = s->lc;
    } else {
        while (IsRChild(*s))
            s = s->parent;
        s = s->parent;
    }
    return s;
}

#endif // __BINNODE_SUCC__
