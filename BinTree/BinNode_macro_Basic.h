/*
 *后续的操作将频繁的判断节点的状态
 *例如计算树的高度要判断节点是否是叶子节点，
 *遍历二叉树要判断左右子树，
 *计算节点的高度要判断是有孩子
 *等等
 */

#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lc))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rc))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasRChild(x) || HasLChild(x))
#define HasBothChild(x) (HasRChild(x) && HasLChild(x))
#define IsLeaf(x) (!HasChild(x))

/*获取兄弟节点*/
#define sibling(p) \
    (IsLChild(*(p)) ? (p)->parent->rc : (p)->parent->lc)

/*叔叔节点*/
#define uncle(x) \
    (IsLChild(*(x)->parent)) ? (x)->parent->parent->rc : (x)->parent->parent->lc )

/*来自父亲的引用*/
#define FromParentTo(x) \
    (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lc : (x).parent->rc))