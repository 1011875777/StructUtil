/*hash桶的普通结点*/
typedef struct stHASH_NODE
{  
    struct stHASH_NODE *pstNext;
    struct stHASH_NODE **ppstPrev;
}HASH_NODE_S;  


typedef struct stHASH_BUCKET
{
    struct stHASH_NODE *pstFirst;
}HASH_BUCKET_S;


