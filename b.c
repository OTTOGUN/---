#include<stdio.h>
#include <synchapi.h>
#include<string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild , *rchild;
}BiTNode,*BiTree;

//访问二叉树结点的具体操作，具体干什么
Status visit(char c,int level){
    printf("%c 位于第 %d 层\n",c,level);
}

//创建一棵二叉树，按照前序遍历的方式输入数据
Status CreateBiTree_Front(BiTree* T){
    char c;
    scanf("%c",&c);
    if(c == ' '){
        *T = NULL;
    }else{
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T) -> data = c;
        CreateBiTree_Front(&(*T) -> lchild);
        CreateBiTree_Front(&(*T) -> rchild);
        return OK;
    }
}

//前序遍历二叉树
Status PreOrderTraverse(BiTree T,int level){
    if(T){
        visit(T -> data,level);
        PreOrderTraverse(T -> lchild,level + 1);
        PreOrderTraverse(T -> rchild,level + 1);
    }
}

//中序遍历二叉树
Status InOrderTraverse(BiTNode* T,int level){
    if(T){
        InOrderTraverse(T -> lchild,level + 1);
        visit(T -> data,level);
        InOrderTraverse(T -> rchild,level + 1);
    }
}

//后序遍历二叉树
Status PosterTraverse(BiTNode* T,int level){
    if(T){
        PosterTraverse(T -> lchild,level + 1);
        PosterTraverse(T -> rchild,level + 1);
        visit(T -> data,level);
    }
}

int main(){
    int level = 1;
    BiTree T1 = NULL;

    CreateBiTree_Front(&T1);
    PreOrderTraverse(T1,level);
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    InOrderTraverse(T1,1);
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    PosterTraverse(T1,1);

    return 0;
}