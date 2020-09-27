// OS 피터슨 솔루션 다시 풀기

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define FALSE  0
#define TRUE  1
#define N 2 

int turn; //자신의 턴을 정하는 변수 

int flage[N]; //모든 변수0(false)로 초기화 


DWORD WINAPI thread_func_1(LPVOID lpParam);


volatile	int   shared_var = 0; 
volatile 	int   job_complete[2] = { 0, 0 };

//상대편의 연산 수행의 끝을 알 수 있는 배열
void leave_region(int process)

{

   flage[process] = FALSE;


}

void enter_region(int process)
/*
한 프로세스가 실행되고 나면 조건들을 비교하여,
연산 수행 중에 다른 프로세스
*/
{

   int other; 
   other = 1 - process; 
   flage[process] = TRUE;
   turn = process;
   __asm mfence;
   while ((turn == process) && (flage[other]))
   {

	}   

}


int main(void)
{
   int i,j;

   DWORD dwThreadId_1, dwThrdParam_1 = 1;
   HANDLE hThread_1;



   hThread_1 = CreateThread(
      NULL,                        
      0,                           
      thread_func_1,                  
      &dwThrdParam_1,                
      0,                                    
      &dwThreadId_1);               


   if (hThread_1 == NULL)
   {
      printf("Thread 1 creation error\n");
      exit(0);
   }
   else
   {
      CloseHandle(hThread_1);
   }
   /* I am main thread*/
   /* Now Main Thread and Thread 1 runs concurrently */

   for (i = 0; i < 10000; i++) {
      for ( j = 0; j < 100000; j++) {
         enter_region(0);;
         shared_var++;
         __asm mfence;
         leave_region(0);
      }
      printf("[%d] p0 스레드 연산 결과:  %d \n",i+1, shared_var);
   }
   while (flage[1] == 0 );
   _getch(); 
   ExitProcess(0); 


}

DWORD WINAPI thread_func_1(LPVOID lpParam)
{
   for (int i = 0; i < 10000; i++) {
      for (int j = 0; j < 100000; j++) {
         enter_region(1);
         shared_var++;
         __asm mfence;
         leave_region(1);
      }
   printf("스레드 번호: %d 연산 결과: %d \n", 1, shared_var);
   }

   ExitThread(0);
}