#ifndef __BINNODE_SIZE__
#define __BINNODE_SIZE__

template <typename T>
int BinNode<T>::size()
{
    int s = 1;
    if (lc)
        s += lc->size();
    if (rc)
        s += rc->size();
    return s;
}

#endif