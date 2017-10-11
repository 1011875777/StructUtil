#include "..\include\basetype.h"
#include "..\include\list.h"
#include "..\include\heap.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct stTest
{
    INT iA;
    DTQ_NODE_S stNode;
    SHORT sB;
}TEST_S;


INT compare(ULONG ulA, ULONG ulB)
{
    INT iA = (INT)ulA;
    INT iB = (INT)ulB;
    if (iA > iB)
    {
        return 1;
    }
    else if (iA < iB)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
VOID HEAP_Sort(INT *piArray, INT iLen)
{
    INT i = 0;
    INT iTemp = 0;
    HEAP_S stHeap;
    HEAP_Init(&stHeap, compare);
    for (i = 0; i < iLen; i++)
    {
        HEAP_Add(&stHeap, piArray[i]);
    }
    for (i = 0; i < iLen; i++)
    {
        iTemp = (INT)HEAP_PopMin(&stHeap);
        printf("%d ", iTemp);
    }
    printf("\r\n");
    HEAP_Destroy(&stHeap);
    return;
}

VOID main()
{
    #if 0
    INT iA = 0;
    DTQ_HEAD_S stList;
    TEST_S *pstNode = NULL;
    TEST_S *pstNodeNext = NULL;
    DTQ_Init(&stList);
    while(scanf("%d", &iA) && iA != 99)
    {
        pstNode = (TEST_S*)malloc(sizeof(TEST_S));
        if (NULL != pstNode)
        {
            DTQ_NodeInit(&(pstNode->stNode));
            pstNode->iA = iA;
            DTQ_AddHead(&stList, &(pstNode->stNode));
        }
    }
    DTQ_FOR_EACH_ENTRY(&stList, pstNode, TEST_S, stNode)
    {
        printf("%d ", pstNode->iA);
    }
    printf("\r\n");
    DTQ_FOR_EACH_ENTRY_R(&stList, pstNode, TEST_S, stNode)
    {
        printf("%d ", pstNode->iA);
    }
    printf("\r\n");
    DTQ_FOR_EACH_ENTRY_SAFE(&stList, pstNode, pstNodeNext, TEST_S, stNode)
    {
        DTQ_DelNode(&(pstNode->stNode));        
        free(pstNode);
    }
    #endif

    INT aiArray[] = {1,3,5,7,9,2,4,6,8,10,0,19};
    HEAP_Sort(aiArray, sizeof(aiArray)/sizeof(INT));
    
    return;
}

