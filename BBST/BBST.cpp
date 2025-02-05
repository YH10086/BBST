#include"BBST.h"

void ShowNode(BBSTree p){ //先序遍历
if(p==NULL) return;
printf("%d ",p->data);
ShowNode(p->lchild);
ShowNode(p->rchild);
}

BBSTree Lrotate(BBSTree p){ //左旋
BBSTree temp=p->rchild;
p->rchild=temp->lchild;
temp->lchild=p;
p->bf=GetHeight(p->lchild)-GetHeight(p->rchild);
temp->bf=GetHeight(temp->lchild)-GetHeight(temp->rchild);
return temp;
}

BBSTree Rrotate(BBSTree p){  //右旋
BBSTree temp=p->lchild;
p->lchild=temp->rchild;
temp->rchild=p;
p->bf=GetHeight(p->lchild)-GetHeight(p->rchild);
temp->bf=GetHeight(temp->lchild)-GetHeight(temp->rchild);
return temp;
}

BBSTree LRrotate(BBSTree p){  //左右旋
p->lchild=Lrotate(p->lchild);
return Rrotate(p);
}

BBSTree RLrotate(BBSTree p){  //右左旋 
p->rchild=Rrotate(p->rchild);
return Lrotate(p);
}

BBSTree InitNode(int value){  //创建并初始化节点
BBSTree temp=(BBSTree)malloc(sizeof(BBSTNode));
temp->data=value;
temp->lchild=NULL;
temp->rchild=NULL;
temp->bf=0;
return temp;
}

int GetHeight(BBSTree p){  //得到该节点树高
if(p==NULL) return 0;
int h1=GetHeight(p->lchild)+1;
int h2=GetHeight(p->rchild)+1;
return h1>h2 ? h1 :h2;
}

BBSTree PushNode(BBSTree p,int value,int* taller){ //插入节点
if(p==NULL) {  //当树为空或递归至空时，创建新节点
p=InitNode(value);
*taller=1;
return p;
}

else if(p->data>value){  //值较小，放置在左子树
 p->lchild=PushNode(p->lchild,value,taller);

if(*taller){  //调整bf值

if(p->bf==1){
if(p->lchild->bf==1){  //右旋
p=Rrotate(p);
*taller=0;    
}
else if(p->lchild->bf==-1){  //左右旋
p=LRrotate(p);
*taller=0;    
}
}

else if(p->bf==0){
p->bf=1;
}
else if(p->bf==-1){
p->bf=0;
}
}
}

else{  //值较大，放置在右子树
p->rchild=PushNode(p->rchild,value,taller);

if(*taller){  //调整bf值并做出相应旋转操作
if(p->bf==0) p->bf=-1;

else if(p->bf==-1){
if(p->rchild->bf==-1){  //左旋
 p=Lrotate(p);
 *taller=0;
}
else if(p->rchild->bf==1){  //右左旋
 p=RLrotate(p);
 *taller=0;
}  
}

}

}
return p;
}

BBSTree DeleteNode(BBSTree p,int value,int* shorter){//删除数据
if(p==NULL) return NULL;  //若树为空，则返回空

else if(p->data>value){
    p->lchild=DeleteNode(p->lchild,value,shorter); //递归回左子树

    if(*shorter){ //进行调整平衡因子与旋转操作

     if(p->bf==0){ 
    p->bf=-1;
    *shorter=0;
  }
  
  else if(p->bf==-1){
    if(p->rchild->bf==-1){
      p=Lrotate(p);
      
    } 

    else if(p->rchild->bf==1){
      p=RLrotate(p);
      
    }
    }

    else if(p->bf==1){
      p->bf=0;
      *shorter=0;
    } 
  
    }
}

else if(p->data<value){  
  p->rchild=DeleteNode(p->rchild,value,shorter);  //递归回右子树

  if(*shorter){  //进行调整平衡因子与旋转操作

  if(p->bf==0){ 
    p->bf=1;
    *shorter=0;
  }

  else if(p->bf==1){
    if(p->lchild->bf==1){
      p=Rrotate(p);
    } 

    else if(p->lchild->bf==-1){
      p=LRrotate(p);
    }
  }

  else if(p->bf==-1){
    p->bf=0;
    *shorter=0;
  }
  }
}

else{
if(p->lchild==NULL||p->rchild==NULL) {  //如果当前节点只有一孩的删除节点
BBSTree temp= p->lchild ? p->lchild : p->rchild;
free(p);
*shorter=1;
return temp;
}

else{  //当前节点有二孩的删除节点
BBSTree temp=p->rchild;
while(temp->lchild!=NULL) temp=temp->lchild; //替换为右子树最小值，改为删除右子树的最小节点
p->data=temp->data;
p->rchild=DeleteNode(p->rchild,temp->data,shorter);

}

}

return p;
}


