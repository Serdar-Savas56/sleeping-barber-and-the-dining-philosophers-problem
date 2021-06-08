#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <locale.h>
#define filozofSay 5

void *filozof(void *);
void dusun(int);
void cubukAl(int);
void yemekYe(int);
void cubukBirak(int);

pthread_mutex_t cubuklar[filozofSay];
pthread_t filozoflar[filozofSay];
pthread_attr_t durum[filozofSay];

int main()
{
    setlocale(LC_ALL,"Turkish");
    int i;
    srand(time(NULL));

    for(int i=0;i<filozofSay;i++)
    {
        pthread_mutex_init(&cubuklar[i],NULL);
    }
    for(int i=0;i<filozofSay;i++)
    {
        pthread_attr_init(&durum[i]);
    }
    for(int i=0;i<filozofSay;i++)
    {
        pthread_create(&filozoflar[i],&durum[i],filozof,(void *)(i));
    }
    for(int i=0;i<filozofSay;i++)
    {
     pthread_join(filozoflar[i],NULL);
    }
    return 0;
}
void *filozof(void *filoNo)
{
    while(1)
    {
        dusun(filoNo);
        cubukAl(filoNo);
        yemekYe(filoNo);
        cubukBirak(filoNo);
    }
}
void dusun(int filoNo)
{
    int sleepTime=rand()%3+1;
    printf("%d numarli filozof %d saniye dusunuyor \n",filoNo,sleepTime);
    sleep(sleepTime);
}
void cubukAl(int filoNo)
{
    int right = (filoNo+1) % filozofSay;
    int left =(filoNo+filozofSay)%filozofSay;
    if(filoNo & 1)
    {
        printf("%d numarali filozof % d cubugu almak icin bekliyor\n",filoNo,right);
        pthread_mutex_lock(&cubuklar[right]);
        printf("%d numarali filozof % d cubugu aldi\n",filoNo,right);
        printf("%d numarali filozof % d cubugu almak icin bekliyor\n",filoNo,left);
        pthread_mutex_lock(&cubuklar[left]);
        printf("%d numarali filozof % d cubugu aldi\n",filoNo,left);
    }
    else
    {
      printf("%d numarali filozof % d cubugu almak icin bekliyor\n",filoNo,left);
        pthread_mutex_lock(&cubuklar[left]);
        printf("%d numarali filozof % d cubugu aldi\n",filoNo,left);
        printf("%d numarali filozof % d cubugu almak icin bekliyor\n",filoNo,right);
        pthread_mutex_lock(&cubuklar[right]);
        printf("%d numarali filozof % d cubugu aldi\n",filoNo,right);
    }
}
void yemekYe(int filoNo)
{
    int eatTime=rand()%3+1;
    printf("%d numarali filozof % d saniyede yedi",filoNo,eatTime);
    sleep(eatTime);
}

void cubukBirak(int filoNo)
{
    printf("%d numarali filozof cubuklarini birakiyor\n",filoNo);
    pthread_mutex_unlock(&cubuklar[(filoNo+1)%filozofSay]);
    pthread_mutex_unlock(&cubuklar[(filoNo+filozofSay)%filozofSay]);
}
