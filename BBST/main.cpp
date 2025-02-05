#include<stdio.h>
#include"BBST.h"

int main(){
BBSTree p=NULL;
int taller=0;
int shorter=0;  //init
p=PushNode(p,24,&taller);
p=PushNode(p,18,&taller);
p=PushNode(p,14,&taller);  //Rrotate
p=PushNode(p,32,&taller);
p=PushNode(p,45,&taller);  //Lrotate
p=PushNode(p,12,&taller);
p=PushNode(p,13,&taller);   //LRrotate
p=PushNode(p,70,&taller);
p=PushNode(p,49,&taller);  //RLrotate
p=DeleteNode(p,32,&shorter); 
p=DeleteNode(p,24,&shorter);   //delete_Lrotate
p=PushNode(p,60,&taller);
p=DeleteNode(p,45,&shorter);  //delete_RLrotate
p=PushNode(p,36,&taller);
p=DeleteNode(p,70,&shorter); //delete_Rrotate
p=PushNode(p,38,&taller);
p=DeleteNode(p,60,&shorter);  //delete_LRrotate
/*

*/
ShowNode(p);

}