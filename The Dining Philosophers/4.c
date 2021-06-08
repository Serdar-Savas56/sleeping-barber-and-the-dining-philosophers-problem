#include <stdio.h>
#define n 5

int compltedPhilo=0;
struct fork
{
    int taken;
}ForkAvil[n];
struct philosp
{
    int left;
    int right;
}Philostartus[n];

void yemekDurumu(int philID)
{
    if(Philostartus[philID].left==10 && Philostartus[philID].right==10)
        printf("Filozof %d yemegini bitirdi\n",philID+1);
    else if(Philostartus[philID].left==1 && Philostartus[philID].right==1)
    {
        printf("Filozof %d yemegini bitirdi\n",philID+1);
        Philostartus[philID].left=Philostartus[philID].right=10;

        int otherFork=philID-1;

        if(otherFork==-1)
            otherFork=(n-1);
        ForkAvil[philID].taken=ForkAvil[otherFork].taken=0;
        printf("Filozof %d %d ve %d cubugunu birakti\n",philID+1,philID+1,otherFork+1);
        compltedPhilo++;
    }
    else if(Philostartus[philID].left==1 && Philostartus[philID].right==0)
    {
        if(philID==(n-1))
        {
            if(ForkAvil[philID].taken==0)
            {
                ForkAvil[philID].taken=Philostartus[philID].right=1;
                printf("%d numarali cubuk %d numarali filozof tarafindan alindi\n",philID+1,philID+1);
            }
            else
            {
                printf("%d numarali filozof %d .cubuk icin bekliyor\n",philID+1,philID+1);
            }
        }
        else
        {
            int dupphilID=philID;
            philID-=1;
            if(philID==-1)
                philID=(n-1);
            if(ForkAvil[philID].taken==0)
            {
                ForkAvil[philID].taken=Philostartus[dupphilID].right=1;
                printf("%d numarali cubuk % numarali filozof tarafindan alindi\n",philID+1,dupphilID+1);
            }
            else
            {
                printf("%d numarali filozof %d numarali cubugu bekliyor\n",dupphilID+1,philID+1);
            }
        }
    }
    else if(Philostartus[philID].left==0)
    {
        if(philID==(n-1))
        {
            if(ForkAvil[philID-1].taken==0)
            {
                ForkAvil[philID-1].taken=Philostartus[philID].left=1;
                printf("%d  numarali cubuk %d numarali filozof tarafindan alindi\n",philID,philID+1);
            }
            else
            {
                printf("%d  numarali filozof %d numarali cubugu bekliyor\n",philID+1,philID);
            }
        }
        else
        {
            if(ForkAvil[philID].taken==0)
            {
                ForkAvil[philID].taken=Philostartus[philID].left=1;
                printf("%d numarali cubuk %d numarali filozof tarafindan alindi\n",philID+1,philID+1);
            }
            else
            {
                printf("%d  numarali filozof %d numarali cubugu bekliyor\n",philID+1,philID+1);
            }
        }
    }
    else{}
}
int main()
{
    for(int i=0;i<n;i++)
    {
        ForkAvil[i].taken=Philostartus[i].left=Philostartus[i].right=0;
    }
    while(compltedPhilo<n)
    {
        for(int i=0;i<n;i++)
        {
            yemekDurumu(i);
            printf("\nYemegi tamamlanan filozof sayisi= %d\n\n",compltedPhilo);
            sleep(1);
        }
    }
    return 0;
}
