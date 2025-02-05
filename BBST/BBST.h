#include<stdio.h>
#include<stdlib.h>

typedef struct BBSTNode{   //ƽ��������洢�ṹ
int data;
int bf;
struct BBSTNode *lchild,*rchild;

} BBSTNode,*BBSTree;

BBSTree Lrotate(BBSTree p);  //����
BBSTree Rrotate(BBSTree p);  //����
BBSTree LRrotate(BBSTree p); //������
BBSTree RLrotate(BBSTree p); //������

BBSTree InitNode(int value); //��������ʼ���ڵ�
int GetHeight(BBSTree p);  //�õ���ǰ�ڵ������
BBSTree DeleteNode(BBSTree p,int value,int* shorter);//ɾ���ڵ�
BBSTree PushNode(BBSTree p,int value,int* taller);//��ӽڵ�
void ShowNode(BBSTree p); //��������ڵ�

