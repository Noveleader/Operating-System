//Child Process
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
 int pid, pid1, pid2, pid3;
 pid = fork();
 if (pid == 0) {
 sleep(3);
 printf("child[1] --> pid = %d and ppid = %d\n",
 getpid(), getppid());
 }
 else {
 pid1 = fork();
 if (pid1 == 0) {
 sleep(2);
 printf("child[2] --> pid = %d and ppid = %d\n",
 getpid(), getppid());
 }
 else {
 pid2 = fork();
 if (pid2 == 0) {
 printf("child[3] --> pid = %d and ppid = %d\n",
 getpid(), getppid());
 }
 else{
 pid3 = fork();
 if(pid3 == 0);
 printf("child[4] --> pid = %d and ppid = %d\n",
 getpid(), getppid());
 }
 }
 }
exit(0);
}


 //Zombie Process
#include <stdio.h>
#include <sys/wait.h> 
#include <stdlib.h> 
#include <unistd.h> 
 int main(void) 
 { 
 pid_t pids[10]; 
 int i; 
 for (i = 2; i >= 0; --i) { 
 pids[i] = fork(); 
 if (pids[i] == 0) { 
 printf("Child%d\n", i); 
 sleep(i+1); 
 _exit(0); 
 } 
 } 
 for (i = 2; i >= 0; --i) { 
 printf("parent%d\n", i); 
 waitpid(pids[i], NULL, 0); 
 } 
 return 0; 
 } 

//Orphan Process
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
 int pid = fork();
 if (pid > 0) {
 printf("Parent process\n");
 printf("ID : %d\n\n", getpid());
 }
 else if (pid == 0) {
 printf("Child process\n");
 printf("ID: %d\n", getpid());
 printf("Parent -ID: %d\n\n", getppid());
 sleep(10);
 printf("\nChild process \n");
 printf("ID: %d\n", getpid());
 printf("Parent -ID: %d\n", getppid());
 }
 else {
 printf("Failed to create child process");
 }
 return 0;
}
 
