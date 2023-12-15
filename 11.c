#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
int sum;
void *runner(void *param);
int main(int argc,char *argv[]){
    pthread_t tid;
    if(argc!=2 || atoi(argv[1])<0){
        fprintf(stderr,"usage:a.out<integervalue>\n%d must be >= 0\n",atoi(argv[1]));
        return -1;
    }
    pthread_create(&tid,NULL,runner,argv[1]);
    pthread_join(tid,NULL);
    printf("SUM = %d\n",sum);
    return 0;
}
void *runner(void *param){
    int i,upper = atoi(param);
    sum = 0;
    for(i = 1;i <= upper; i++)
        sum+=i;
    pthread_exit(0);
}
