#include "..\include\basetype.h"
#include "..\include\heap.h"
#include <stdlib.h>
#include <stdio.h>

VOID HEAP_Print(HEAP_S *pstHeap)
{
    INT i = 0;
    for(i = 0; i < pstHeap->uiHeapLength; i++)
    {
        printf("%d ", pstHeap->pulHeap[i]);
    }
    printf("\r\n");
    return;
}
/*二叉堆初始化*/
ULONG HEAP_Init(HEAP_S *pstHeap, PF_COMPARE pfComp)
{
    if (NULL == pstHeap || NULL == pfComp)
    {
        return FAILED;
    }
    pstHeap->pulHeap = (ULONG*)malloc(HEAP_INIT_SIZE * sizeof(ULONG));
    if (NULL == pstHeap->pulHeap)
    {
        return FAILED;
    }
    (VOID)memset(pstHeap->pulHeap, 0, HEAP_INIT_SIZE * sizeof(ULONG));
    pstHeap->uiHeapLength = 0;
    pstHeap->uiHeapSize = HEAP_INIT_SIZE;
    pstHeap->pfComp = pfComp;
    return SUCCESS;
}
/*销毁二叉堆*/
VOID HEAP_Destroy(HEAP_S *pstHeap)
{
    if (NULL != pstHeap->pulHeap)
    {
        free(pstHeap->pulHeap);
    }
    (VOID)memset(pstHeap, 0, sizeof(HEAP_S));
    return;
}

/*自顶向下堆化*/
VOID HEAP_ShiftDown(HEAP_S *pstHeap)
{
    INT i = 0;
    ULONG ulTemp = 0;
    while(i < pstHeap->uiHeapLength)
    {
        if (SON_LEFT(i) < pstHeap->uiHeapLength)
        {
            if (SON_RIGHT(i) >= pstHeap->uiHeapLength)
            {
                if (pstHeap->pfComp(pstHeap->pulHeap[i], pstHeap->pulHeap[SON_LEFT(i)]) > 0)
                {
                    ulTemp =  pstHeap->pulHeap[i];
                    pstHeap->pulHeap[i] = pstHeap->pulHeap[SON_LEFT(i)];
                    pstHeap->pulHeap[SON_LEFT(i)] = ulTemp;                    
                    i = SON_LEFT(i);
                }
                else
                {
                    break;
                }
            }
            else if ((pstHeap->pfComp(pstHeap->pulHeap[i], pstHeap->pulHeap[SON_LEFT(i)]) <= 0) &&
                     (pstHeap->pfComp(pstHeap->pulHeap[i], pstHeap->pulHeap[SON_RIGHT(i)]) <= 0))
            {
                break;
            }
            else if (pstHeap->pfComp(pstHeap->pulHeap[SON_LEFT(i)], pstHeap->pulHeap[SON_RIGHT(i)]) <= 0)
            {
                ulTemp =  pstHeap->pulHeap[i];
                pstHeap->pulHeap[i] = pstHeap->pulHeap[SON_LEFT(i)];
                pstHeap->pulHeap[SON_LEFT(i)] = ulTemp;                
                i = SON_LEFT(i);
            }
            else
            {
                ulTemp =  pstHeap->pulHeap[i];
                pstHeap->pulHeap[i] = pstHeap->pulHeap[SON_RIGHT(i)];
                pstHeap->pulHeap[SON_RIGHT(i)] = ulTemp;               
                i = SON_RIGHT(i);                
            }
        }
        else
        {
            break;
        }
        
    }
    return;
}
/*自底向上堆化*/
VOID HEAP_ShiftUp(HEAP_S *pstHeap)
{
    INT i = pstHeap->uiHeapLength - 1;
    ULONG ulTemp = 0;
    while(i > 0)
    {
        if (pstHeap->pfComp(pstHeap->pulHeap[i], pstHeap->pulHeap[PARENT(i)]) < 0)
        {
            ulTemp = pstHeap->pulHeap[PARENT(i)];
            pstHeap->pulHeap[PARENT(i)] = pstHeap->pulHeap[i];
            pstHeap->pulHeap[i] = ulTemp;
            i = PARENT(i);
        }
        else
        {
            break;
        }
    }
    return;
}
/*弹出最小结点*/
ULONG HEAP_PopMin(HEAP_S *pstHeap)
{
    ULONG ulRet = NULL;
    if (0 != pstHeap->uiHeapSize)
    {
        ulRet = pstHeap->pulHeap[0];
        pstHeap->uiHeapLength--;
        pstHeap->pulHeap[0] = pstHeap->pulHeap[pstHeap->uiHeapLength];
        pstHeap->pulHeap[pstHeap->uiHeapLength] = NULL;
        HEAP_ShiftDown(pstHeap);
    }
    
    return ulRet;
}

/*二叉堆中增加元素*/
ULONG HEAP_Add(HEAP_S *pstHeap, ULONG ulValue)
{
    ULONG ulRet = SUCCESS;
    ULONG *pulTemp = NULL;
    if (pstHeap->uiHeapLength >= pstHeap->uiHeapSize)
    {
        pulTemp = (ULONG*)malloc((pstHeap->uiHeapSize + HEAP_STEP_SIZE) * sizeof(ULONG));
        if (NULL != pulTemp)
        {
            memcpy(pulTemp, pstHeap->pulHeap, pstHeap->uiHeapLength * sizeof(ULONG));
            free(pstHeap->pulHeap);
            pstHeap->pulHeap = pulTemp;
            pstHeap->uiHeapSize += HEAP_STEP_SIZE;
                      
        }
        else
        {
            ulRet = FAILED;
        }
    }
    if (SUCCESS == ulRet)
    {
        pstHeap->pulHeap[pstHeap->uiHeapLength] = ulValue;
        pstHeap->uiHeapLength++;
        HEAP_ShiftUp(pstHeap);  
    }
    return ulRet;
}

