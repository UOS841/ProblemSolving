#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define MAX_CACHE_SIZE 8192

// 데이터 참조 스트림이 저장된 파일
#define TRACE_FILE_NAME "ref_stream.txt"

// 이중연결리스트의 노드 타입
struct buffer
{
    unsigned long blkno;
    struct buffer *next, *prev;
    struct buffer *hash_next, *hash_prev;
};

// 데이터를 저장할 공간을 한 번에 할당 받음
// 이후 추가적인 메모리 할당은 없음
// 할당 받은 노드들을 이용하여 LRU 리스트 또는 FIFO 리스트를 유지해야 함
struct buffer cache_buffer[MAX_CACHE_SIZE];

// LRU 시뮬레이터 인 경우 lrulist 아니면 fifolist를 유지하기 위한 헤드 노드 선언

struct buffer lrulist;

//hash table
#define HASH_SIZE (MAX_CACHE_SIZE / 3) //int형으로 바꿔줘야함
struct buffer hash_table[HASH_SIZE];

unsigned long curtime, hit, miss; //참조횟수 체크, 히트, 미스 체크용

//헤드 다음에 넣어야 함
void lruin(struct buffer *bp)
{
    struct buffer *dp = &lrulist;
    bp->next = dp->next;
    bp->prev = dp;
    (dp->next)->prev = bp;
    dp->next = bp;
}

struct buffer *lruout()
{
    struct buffer *bp;

    bp = lrulist.prev; //얘가 항상 가장 오래전에 참조된 애
    (bp->prev)->next = bp->next;
    (bp->next)->prev = bp->prev;

    return bp;
}

void reorder(struct buffer *bp)
{
    //현재 위치에서 빼서 lruin하기
    (bp->next)->prev = bp->prev;
    (bp->prev)->next = bp->next;
    lruin(bp);
}

//초기화(초기에 선언한거 연결시켜주기)
void init()
{
    int i;                                  //배열인덱스저장
    lrulist.next = lrulist.prev = &lrulist; //헤드 초기화

    for (i = 0; i < MAX_CACHE_SIZE; i++)
    {
        cache_buffer[i].blkno = ~0; //이게뭐다냐 블록 번호가 다 FF다..?
        cache_buffer[i].next = cache_buffer[i].prev = NULL;

        lruin(&cache_buffer[i]); //이케하면 0번노드가 맨 뒤, 8191번은 lrulist 헤드 그 다음 노드에 들어가있을 것(계속 헤드에 집어넣으니까)
    }
    return;
}

// void init_table(struct buffer ht[])
// {
//     int i;
//     for (i = 0; i < HASH_SIZE; i++)
//     {
//         printf("before\n");
//         printf("%d:%d\n", i, ht[i].blkno);
//         printf("%d:%d\n", i, ht[i].hash_prev);
//         printf("%d:%d\n", i, ht[i].hash_next);
//         ht[i].blkno = NULL;
//         ht[i].hash_prev = NULL;
//         ht[i].hash_next = NULL;
//         printf("after\n");
//         printf("%d:%d\n", i, ht[i].blkno);
//         printf("%d:%d\n", i, ht[i].hash_prev);
//         printf("%d:%d\n", i, ht[i].hash_next);
//     }
// }

int hash_function(unsigned long blkno)
{
    return blkno % HASH_SIZE;
}

void hash_chain_add(struct buffer* bp, struct buffer* ht)
{
    int hash_value = hash_function(bp->blkno);
    struct buffer* node_before = &ht[hash_value];\
    struct buffer* node_after = node_before->hash_next;
    printf("next %d\n", node_before->blkno);
    printf("next %d\n", node_before->hash_next);
    // printf("blkjno %d\n", node_after->blkno);
    if (node_before)
    {

        // node_after->hash_prev = bp;
        node_before->hash_next = bp;
        bp->hash_next = node_after;
        bp->hash_prev = node_before;
    }
    else
    {
        printf("2\n");
        // ht[hash_value] = bp;
    }
    printf("3\n");
}

//findblk 시간복잡도 O(n)
//hash table로 시간복잡도 완화 가능(메모리 더 사용하며)
struct buffer *findblk(unsigned long item, struct buffer *ht)
{

    struct buffer* node;

    int hash_value = hash_function(item);
    printf("hash_value : %d\n", hash_value);
    for (node = &ht[hash_value]; node != NULL; node = node->hash_next)
    {
        if (node->blkno == item)
        {
            fprintf(stderr, "yeahh\n", item);
            return node; //이래 둬도 되나..? node 가능..?
        }
        else
        {
            printf("%d\n", node->blkno);
        }
    }
    printf("Key Not found\n");
    return NULL;
}
void pgref(unsigned long blkno)
{
    struct buffer *bufp;
    struct buffer *ht = hash_table;
    bufp = findblk(blkno, ht);

    //search block number in lrulist
    if (bufp)
    {
        //hit
        printf("hit!\n");
        hit++;
        reorder(bufp);
    }
    else
    {
        printf("noo\n");
        miss++;

        bufp = lruout(); //이거로 lrulist를 가져옴??
        bufp->blkno = blkno;
        lruin(bufp);
        hash_chain_add(bufp, ht);
    }
}

int main(int argc, char *argv[])
{
    int ret;
    unsigned long blkno;
    FILE *fp = NULL;

    init();
    // init_table(hash_table);
    curtime = miss = hit = 0;


    if ((fp = fopen("C:/Users/Handal/github/ProblemSolving/handal95/CHICKEN/ref_stream.txt", "r")) == NULL)
    {
        printf("%s trace file open fail.\n", TRACE_FILE_NAME);

        return 0;
    }
    else
    {
        printf("start simulation!\n");
        printf("%d\n", sizeof(hash_table)/sizeof(hash_table[0]));
    }

    ////////////////////////////////////////////////
    // 시뮬레이션 시작 및 결과 출력을 위한 코드
    ////////////////////////////////////////////////
    while ((ret = fscanf(fp, "%lu\n", &blkno)) != EOF)
    {              //fp는 파일포인터
        curtime++; //이게 왜 필요한거지
        pgref(blkno);
        printf("%d\n", curtime);
    }
    fclose(fp);

    // printf("total access : %lu, hit : %lu, miss : %lu\n", curtime, hit, miss);
    // printf("hit ratio : %f, miss ratio : %f\n", (float)hit / (float)curtime, (float)miss / (float)curtime);
    // return 0;
}