#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int KeyType;

//定义数据元素类型
typedef struct 
{
    KeyType key;
    int hi;
}DataType;

//定义散列表类型定义
typedef struct 
{
    DataType *data;
    int tableSize;
    int curSize;
}HashTable;

void CreateHashTable(HashTable *H , int m , int p , int hash[] , int n);
int SearchHash(HashTable H , KeyType k);
void DisplayHash(HashTable H , int m);
void HashASL(HashTable H , int m);

int main(){
    int hash[] = {23,35,12,56,123,39,342,90};
    int m = 11, p = 11 , n = 8, pos ;
    KeyType k=123;
    HashTable H;
    CreateHashTable(&H , m , p , hash , n );
    DisplayHash(H , m);
    pos = SearchHash(H , k);
    printf("关键字%d在散列表中的位置为：%d\n", k, pos);
    HashASL(H,m);
    return 0;
}

//构造空的散列表并处理冲突
void CreateHashTable(HashTable *H , int m , int p , int hash[] , int n){
    int i , sum ,addr , di ,k=1 ;
    //散列表初始化
    H->data = (DataType*)malloc(m*sizeof(DataType));
    if(!H->data)exit(-1);
    for(i=0;i<m;i++){
        H->data[i].key = -1;
        H->data[i].hi = 0;
    }
    //求散列函数并处理冲突
    for(i=0;i<n;i++){
        sum = 0;
    //求散列函数
        addr = hash[i]%p;                /*除留余数法求地址，p为设置的取余参数，p≤m*/
        di = addr;
        if(H->data[addr].key == -1)H->data[addr].key = hash[i], H->data[di].hi = 1; 
    //处理冲突
        else{
            do
            {
              di = (di+k)%m;           /*线性探测法解决冲突，m为散列表长*/
              sum+=1;
            } while (H->data[di].key != -1);
            H->data[di].key = hash[i];
            H->data[di].hi = sum+1;      /*第一次查找没有算在解决冲突中，需要加1*/
        }
    }
    H->curSize = n ;        /*散列表中的关键字个数*/
    H->tableSize = m ;      /*散列表的长度*/
}

//显示散列表
void DisplayHash(HashTable H , int m){
    int i;
    printf("散列地址：");
    //关键字
    for(i=0;i<m;i++)printf("%-5d" , H.data[i].key);
    printf("\n");
    //冲突次数
    printf("冲突次数：");
    for(i=0;i<m;i++)printf("%-5d" , H.data[i].hi);
    printf("\n");
}

//搜索值
int SearchHash(HashTable H , KeyType k){
    int d,dl,m;
    m = H.tableSize;
    d=dl=k%m;
    while(H.data[d].key != -1){
        if (H.data[d].key == k)
            return d;
        else d=(d+1)%m;
        if(d==dl)return 0;
    }
    return 0;
}

void HashASL(HashTable H , int m){
    float average = 0 ;
    int i;
    for(i=0;i<m;i++)average=average+H.data[i].hi;
    average = average/H.curSize;
    printf("平均查找长度ASL = %.2f" ,average);
    printf("\n");
}