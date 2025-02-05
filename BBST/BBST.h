#include<stdio.h>
#include<stdlib.h>

typedef struct BBSTNode{   //平衡二叉树存储结构
int data;
int bf;
struct BBSTNode *lchild,*rchild;

} BBSTNode,*BBSTree;

BBSTree Lrotate(BBSTree p);  //左旋
BBSTree Rrotate(BBSTree p);  //右旋
BBSTree LRrotate(BBSTree p); //左右旋
BBSTree RLrotate(BBSTree p); //右左旋

BBSTree InitNode(int value); //创建并初始化节点
int GetHeight(BBSTree p);  //得到当前节点的树高
BBSTree DeleteNode(BBSTree p,int value,int* shorter);//删除节点
BBSTree PushNode(BBSTree p,int value,int* taller);//添加节点
void ShowNode(BBSTree p); //中序遍历节点

