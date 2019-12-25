#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{/*元素的结点结构*/
	int key;		/*记录的关键字,忽略记录的其他数据项*/
	struct BTNode *Lchild, *Rchild;	/*左指针,右指针*/
}BTNode, *BSTree;

BTNode * SearchBST(BSTree T,int key);
BSTree InsertBST_key(BSTree T, int key);
BSTree InsertBST(BSTree T, BTNode *s);
BSTree CreateBST();
BTNode * SearchBST_F(BSTree T, int key, BSTree *F);
BSTree SearchDeleteBST(BSTree T, int key);
BSTree deleteBST(BSTree T, BTNode *p, BTNode *f);
void Postorder(BSTree T);
void Inorder(BSTree T);
void Proorder(BSTree T);

BTNode * SearchBST(BSTree T,int key)
{/*T指向二叉排序树的根节点,key为待查关键字值*/
	if (T == NULL)
        return NULL;    /*查找失败*/
    if (key == T->key)
        return T;   /*查找成功*/
    if (key < T->key)
        return (SearchBST(T->Lchild, key));     /*继续查找左子树*/
    if (key > T->key)
        return (SearchBST(T->Rchild, key));     /*继续查找右子树*/
}

BSTree InsertBST_key(BSTree T, int key)
{/*在以T为根节点的二叉排序树上查找关键字为key的记录,若不存在,将其插入*/
    BTNode *s;
    s = SearchBST(T, key);      /*调用搜索函数*/
    if(s)
        printf("\n关键字%d已经存在！\n",s->key);
    else
    {
        printf("将该关键字插入二叉排序树\n");
        s = (BTNode *)malloc(sizeof(BTNode));   /*生成一个结点空间*/
        s->key = key;
        s->Lchild = NULL;
        s->Rchild = NULL;
        T = InsertBST(T, s);    /*调用二叉排序树插入一个结点的递归算法*/
    }
    return T;
}/*InsertBST_key*/

BSTree InsertBST(BSTree T, BTNode *s)
{/*在以T为根的二叉排序树上插入一个指针s所指向的结点,并返回根指针T*/
    if (T == NULL)
        T = s; /*若树为空,则新插入结点s为新的树根*/
    else
    {
        if (s->key < T->key)
            T->Lchild = InsertBST(T->Lchild, s);    /*递归插入到T的左子树中*/
        else if (s->key > T->key)
            T->Rchild = InsertBST(T->Rchild, s);    /*递归插入到T的右子树中*/
    }
    return T;
}/*InsertBST*/

BSTree CreateBST()
{/*由空树开始,插入关键字序列,建立一颗二叉排序树*/
    BSTree T,s;     /*T为树根结点,s为树结点*/
    int key;    /*关键字*/
    T = NULL;
    printf("创建二叉排序树\n");
    printf("输入关键字key,输入\"-1\"结束\n");
    while (1)
    {
        scanf("%d",&key);   /*输入key值*/
        if (key!=-1)
        {
            s = (BTNode *)malloc(sizeof(BTNode));
            s->key = key;
            s->Lchild = NULL;
            s->Rchild = NULL;
            T = InsertBST(T, s);    /*插入二叉排序树*/
        }
        else
            break;
    }
    return T;
}/*CreateBST*/

BTNode * SearchBST_F(BSTree T, int key, BSTree *F)
{/*T指向根结点,key为待查找的关键字,*F存储指向key的双亲的指针*/
    if (T == NULL)
        return NULL;    /*查找失败返回NULL*/
    if(key == T->key)
        return T;   /*查找成功,返回树根的指针*/
    else
    {
        *F = T;     /* *F指向T */
        if (key < T->key)
            return SearchBST_F(T->Lchild, key, F);      /*继续在左子树查找*/
        else if(key > T->key)
            return SearchBST_F(T->Rchild, key, F);      /*继续在右子树查找*/
    }
}/*SearchBST_F*/

BSTree SearchDeleteBST(BSTree T, int key)
{/*在二叉排序树T中删除关键字为key的记录*/
    BTNode *f, *p;/*p指向key,f为双亲指针*/
    f = NULL;
    p = SearchBST_F(T, key, &f);    /*查找key*/
    if(p)
        T = deleteBST(T, p, f);   /*删除T中的*p结点,双亲为*f结点*/
    else
        printf("关键字为 %d 的记录不存在！\n",key);
    return T;
}/*SearchDeleteBST*/

BSTree deleteBST(BSTree T, BTNode *p, BTNode *f)
{/*删除p指针指向的结点,f指向*p的双亲结点,T指向根结点的指针*/
    BTNode *par, *s;
    int kind;
    if ((p->Lchild == NULL)&& (p->Rchild == NULL))
        kind = 1;   /*情况1,*p为叶子结点*/
    else if(p->Rchild == NULL)
        kind = 2;   /*情况2,*p只有左子树*/
    else if(p->Lchild == NULL)
        kind = 3;   /*情况3,*p只有右子树*/
    else
        kind = 4;   /*情况4,*p有左右子树*/
    switch (kind)
    {
        case 1: /*情况1,*p为叶子结点*/
        if(!f)  /*f为null,*p为根结点,树中只有一个根结点*/
            T = NULL;
        else
        {
            if(f->Lchild == p)
                f->Lchild == NULL;
            else if (f->Rchild == p)
                f->Rchild == NULL;
            free(p);
        }
        break;

        case 2: /*情况2,*p只有左子树*/
        if(!f)  /*f为null,*p为根结点,且只有左子树*/
            T = p->Lchild;
        else
        {
            if(p == f->Lchild)
                f->Lchild = p->Lchild;  /* *p是*f左子树的情况 */
            else if(p == f->Rchild)
                f->Rchild = p->Lchild;  /* *p是*f右子树的情况 */
        }
        free(p);
        break;

        case 3: /*情况3,*p只有右子树*/
        if(!f)  /*f为null,*p为根结点,且只有右子树*/
            T = p->Rchild;
        else
        {
            if(p == f->Lchild)
                f->Lchild = p->Rchild;  /* *p是*f左子树的情况 */
            else if(p == f->Rchild)
                f->Rchild = p->Rchild;  /* *p是*f右子树的情况 */
        }
        free(p);
        break;

        case 4: /*情况4,*p有左右子树*/
        par = p;
        s = p->Lchild;
        while (s->Rchild != NULL)
        {
            par = s;    /*双亲结点*/
            s = s->Rchild;
        }
        p->key = s->key;    /*s结点的值赋给p结点*/
        if(par == p)    /*特殊情况,*p的左孩子为*s*/
            p->Lchild = s->Lchild;
        else            /*一般情况*/
            par->Rchild = s->Lchild;
        free(s);
        break;
    }
    return T;
}

void Proorder(BSTree T)
{/*采用二叉链表存储结构,先序遍历二叉树,对每个结点输出其值*/
   if(T != NULL)       /*二叉树bt不为空*/
   {
       printf("%d ",T->key);      /*输出根结点的值*/
       Proorder(T->Lchild);     /*遍历左子树*/
       Proorder(T->Rchild);     /*遍历右子树*/
   }
}/*Proorder*/

void Inorder(BSTree T)
{/*采用二叉链表存储结构,中序遍历二叉树,对每个结点输出其值*/
   if(T != NULL)       /*二叉树bt不为空*/
   {
       Inorder(T->Lchild);     /*遍历左子树*/
       printf("%d ",T->key);      /*输出根结点的值*/
       Inorder(T->Rchild);     /*遍历右子树*/
   }
}/*Inorder*/

void Postorder(BSTree T)
{/*采用二叉链表存储结构,后序遍历二叉树,对每个结点输出其值*/
   if(T != NULL)       /*二叉树bt不为空*/
   {
       Postorder(T->Lchild);     /*遍历左子树*/
       Postorder(T->Rchild);     /*遍历右子树*/
       printf("%d ",T->key);      /*输出根结点的值*/
   }
}/*Postorder*/

int main()
{
    int flag,key;
    BSTree T;
    while (1)
    {
        printf("----------------------\n");
        printf("1.创建二叉排序树\n");
        printf("2.二叉排序树查找、插入关键字\n");
        printf("3.二叉排序树删除关键字\n");
        printf("4.退出程序\n");
        printf("----------------------\n");
        printf("\n请输入一个数选择功能:");
        flag = 8;
        scanf("%d",&flag);
        getchar();

        if(flag == 4)
            break;
        switch (flag)
        {
            case 1:
            T = CreateBST();
            printf("\n二叉排序树建立完毕\n");
            printf("先序遍历:\n");
            Proorder(T);
            printf("\n中序遍历:\n");
            Inorder(T);
            printf("\n后序遍历:\n");
            Postorder(T);
            printf("\n");
            system("pause");
            system("cls");
            break;

            case 2:
            printf("请输入要查找的关键字key:");
            scanf("%d",&key);
            T = InsertBST_key(T,key);
            printf("先序遍历:\n");
            Proorder(T);
            printf("\n中序遍历:\n");
            Inorder(T);
            printf("\n后序遍历:\n");
            Postorder(T);
            printf("\n");
            system("pause");
            system("cls");
            break;

            case 3:
            printf("请输入要删除的关键字key:");
            scanf("%d",&key);
            T = SearchDeleteBST(T,key);
            printf("先序遍历:\n");
            Proorder(T);
            printf("\n中序遍历:\n");
            Inorder(T);
            printf("\n后序遍历:\n");
            Postorder(T);
            printf("\n");
            system("pause");
            system("cls");
            break;

            default:
            printf("输入命令有误,请重新输入!\n");
            system("pause");
            system("cls");
            break;
        }
    }
    return 0;
}
