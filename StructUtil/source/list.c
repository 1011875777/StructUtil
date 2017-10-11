#include "..\include\basetype.h"
#include "..\include\list.h"
/*链表初始化*/
VOID DTQ_Init(DTQ_HEAD_S *pstList)
{
    pstList->pstNext = pstList;
    pstList->pstPrev = pstList;

    return;
}

/*结点初始化*/
VOID DTQ_NodeInit(DTQ_NODE_S *pstNode)
{
    pstNode->pstNext = NULL;
    pstNode->pstPrev = NULL;

    return;
}

/*链表头部插入结点*/
VOID DTQ_AddHead(DTQ_HEAD_S *pstList, DTQ_NODE_S *pstNode)
{
    pstNode->pstNext = pstList->pstNext;
    pstNode->pstPrev = pstList;    
    pstList->pstNext->pstPrev = pstNode;
    pstList->pstNext = pstNode;
    
    return;
}

/*链表尾部插入结点*/
VOID DTQ_AddTail(DTQ_HEAD_S *pstList, DTQ_NODE_S *pstNode)
{
    pstNode->pstNext = pstList;
    pstNode->pstPrev = pstList->pstPrev;
    pstList->pstPrev->pstNext = pstNode;
    pstList->pstPrev = pstNode;
    
    return;
}

/*指定结点后插入结点*/
VOID DTQ_AddAfter(DTQ_NODE_S *pstNode1, DTQ_NODE_S *pstNode2)
{
    pstNode2->pstNext = pstNode1->pstNext;
    pstNode2->pstPrev = pstNode1;    
    pstNode1->pstNext->pstPrev = pstNode2;
    pstNode1->pstNext = pstNode2;
    
    return;
}

/*指定结点前插入结点*/
VOID DTQ_AddBefore(DTQ_NODE_S* pstNode1, DTQ_NODE_S *pstNode2)
{
    pstNode2->pstNext = pstNode1;
    pstNode2->pstPrev = pstNode1->pstPrev;
    pstNode1->pstPrev->pstNext = pstNode2;
    pstNode1->pstPrev = pstNode2;
    return;
}

/*摘除结点*/
VOID DTQ_DelNode(DTQ_NODE_S *pstNode)
{
    pstNode->pstPrev->pstNext = pstNode->pstNext;
    pstNode->pstNext->pstPrev = pstNode->pstPrev;

    DTQ_NodeInit(pstNode);
    return;
}
/*判断链表是否为空*/
BOOL DTQ_IsEmpty(DTQ_HEAD_S *pstList)
{
    BOOL bRet = FALSE;
    if (pstList->pstNext == pstList)
    {
        bRet = TRUE;
    }
    return bRet;
}
/*摘除头节点*/
VOID DTQ_DelHead(DTQ_HEAD_S *pstList)
{
    if (!DTQ_IsEmpty(pstList))
    {
        DTQ_DelNode(pstList->pstNext);
    }
    return;
}
/*摘除尾结点*/
VOID DTQ_DelTail(DTQ_HEAD_S *pstList)
{
    if (!DTQ_IsEmpty(pstList))
    {
        DTQ_DelNode(pstList->pstPrev);
    }
    return;
}
