#include <unistd.h>
#include <pthread.h>
#include <locale.h>
#define filozofSay 5


int cubuk[filozofSay];

void *fillEylem(void *id)
{
    int fill_no= *((int*)id);

    while(1)
    {
        //düþünme
        printf("PID : (%ld) Dusunur %d dusunuyor \n",pthread_self(),fill_no+1);
        sleep(1);

        //yemek isteme
        printf("PID : (%ld) Dusunur %d yemek istiyor\n",pthread_self(),fill_no+1);

        while(1)
        {
            if(cubuk[fill_no]==1)
                continue;
            if(cubuk[(fill_no+1)%filozofSay]==1)
                continue;

            cubuk[fill_no]=1;
            cubuk[(fill_no+1)%filozofSay]=1;

            printf("PID : (%ld) Dusunur %d  #%d ve #%d cubuklarini aldi\n",pthread_self(),fill_no+1,fill_no+1,((fill_no+1)%filozofSay));

            printf("PID : (%ld) Dusunur %d yemek yiyor\n",pthread_self(),fill_no+1);
            sleep(1);


            cubuk[fill_no]=0;
            cubuk[(fill_no+1)%filozofSay]=0;

            printf("PID : (%ld) Dusunur %d  #%d ve #%d cubuklarini birakti\n",pthread_self(),fill_no+1,fill_no+1,((fill_no+1)%filozofSay));
            break;
        }

    }
}

void *filTekrar(void* id)
{
    int fill_no = *((int*)id);

    while(1)
    {
        //düþünme
        printf("PID : (%ld) Dusunur %d dusunuyor \n",pthread_self(),fill_no+1);
        sleep(1);

        //yemek isteme
        printf("PID : (%ld) Dusunur %d yemek istiyor\n",pthread_self(),fill_no+1);

        while(1)
        {
            if(cubuk[fill_no]==1)
                continue;
            if(cubuk[(fill_no+1)%filozofSay]==1)
                continue;

            cubuk[fill_no]=1;
            cubuk[(fill_no+1)%filozofSay]=1;

            printf("PID : (%ld) Dusunur %d  #%d ve #%d cubuklarini aldi\n",pthread_self(),fill_no+1,fill_no+1,((fill_no+1)%filozofSay));

            printf("PID : (%ld) Dusunur %d yemek yiyor\n",pthread_self(),fill_no+1);
            sleep(1);


            cubuk[fill_no]=0;
            cubuk[(fill_no+1)%filozofSay]=0;

            printf("PID : (%ld) Dusunur %d  #%d ve #%d cubuklarini birakti\n",pthread_self(),fill_no+1,fill_no+1,((fill_no+1)%filozofSay));
            break;
        }

    }
}
int main(int argc,char const *argv[])
{
    pthread_t thread_ids[filozofSay];
    int philosopher_numbers[filozofSay];
    for(int i=0;i<filozofSay;i++)
    {
        philosopher_numbers[i]=i;
        cubuk[i]=0;
    }
    for(int i=0;i<filozofSay;i++)
    {
        pthread_create(&thread_ids[i],NULL,fillEylem,(void*)&philosopher_numbers[i]);
    }

    pthread_create(&thread_ids[filozofSay-1],NULL,filTekrar,(void*)&philosopher_numbers[filozofSay-1]);

    for(int i =0;i<filozofSay;i++)
    {
        pthread_join(thread_ids[i],NULL);
    }
    exit(0);
}
