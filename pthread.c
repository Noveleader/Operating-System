#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
struct thread_marks
{
int cat1, cat2, sum;
char *name;
};
void *total_thread(void *marks)
{
struct thread_marks *args = (struct thread_marks*) marks;
args->sum=args->cat1+args->cat2;
pthread_exit(NULL);
}
int main()
{
struct thread_marks *args = malloc(sizeof(struct thread_marks));
args->cat1=45;
args->cat2=30;
args->name="Vedant";
pthread_t p1;
pthread_create(&p1, NULL, total_thread, args);
pthread_join(p1,NULL);
printf("Name: %s\n",args->name);
printf("Total marks: %d",args->sum);
free(args);
args=NULL;
return 0;
}
