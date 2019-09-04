#include <stdio.h>

void FCFS()
{
    int n,temp,i,j;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    int a[n],b[n],c[n],w[n],t[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the arrival time of the process %d:",i+1);
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time of the process %d:",i+1);
        scanf("%d",&b[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }
    c[0]=b[0]+a[0];
    for(i=1;i<n;i++)
    {
        c[i]=c[i-1]+b[i];
    }

    int tot_wait=0,tot_turn=0;
    printf("\nArrival\tBurst\tWaiting\tTurnaround\n");
    w[0]=0;
    t[0]=c[0]-a[0];
    for(i=0;i<n-1;i++)
    {
        tot_wait+=(c[i]-a[i+1]);
        tot_turn+=(c[i]-a[i]);
    }
    temp=0;
    for(i=1;i<n;i++)
    {
        temp+=b[i-1];
        w[i]=(temp-a[i]);
    }
    for(i=0;i<n;i++)
    {
        t[i]=c[i]-a[i];
        printf("%d\t%d\t%d\t%d\n",a[i],b[i],w[i],t[i]);
    }
    float avg=tot_wait;
    printf("Average waiting time:%.3f ms\n",avg/n);
    avg=tot_turn;
    printf("Average turnaround time:%.3f ms\n",avg/n);
}

void SJF()
{
    int n,temp,i,j,s,f;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    int a[n],b[n],c[n],w[n],t[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the arrival time of the process %d:",i+1);
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time of the process %d:",i+1);
        scanf("%d",&b[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }
    int co=a[0]+b[0],k;
    for(i=1;i<n;i++)
    {
        s=i;
        j=i;

        while(a[j]<=co)
        {
            f=j;
            j++;
        }

        for(k=s;k<f;k++)
        {


                if(b[k]>b[k+1])
                {
                    temp=a[k];
                    a[k]=a[k+1];
                    a[k+1]=temp;
                    temp=b[k];
                    b[k]=b[k+1];
                    b[k+1]=temp;
                }

        }
        co+=b[i];
    }
    c[0]=a[0]+b[0];
    for(i=1;i<n;i++)
    {
        c[i]=(c[i-1]+b[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",c[i]);
    }
    int tot_wait=0,tot_turn=0;
    printf("\nArrival\tBurst\tWaiting\tTurnaround\n");
    w[0]=0;
    t[0]=c[0]-a[0];
    for(i=0;i<n-1;i++)
    {
        tot_wait+=(c[i]-a[i+1]);
        tot_turn+=(c[i]-a[i]);
    }
    temp=b[0]+a[0];
    for(i=1;i<n;i++)
    {
        w[i]=(temp-a[i]);
        temp+=b[i-1];
    }
    for(i=0;i<n;i++)
    {
        t[i]=c[i]-a[i];
        printf("%d\t%d\t%d\t%d\n",a[i],b[i],w[i],t[i]);
    }
    float avg=tot_wait;
    printf("Average waiting time:%.3f ms\n",avg/n);
    avg=tot_turn;
    printf("Average turnaround time:%.3f ms\n",avg/n);
}

void SRTF()
{
    int a[10],b[10],c[10],timecomp,i,s;
    int comp=0,n,time,tot_waiting=0,tot_turn=0;
    printf("Enter no of Processes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter arrival time for Process P%d : ",i+1);
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("Enter burst time for Process P%d : ",i+1);
        scanf("%d",&b[i]);
        c[i]=b[i];
    }
    printf("Process\tTurnaround\tWaiting\n");
    c[9]=9999;
    for(time=0;comp!=n;time++)
    {
        s=9;
        for(i=0;i<n;i++)
        {
            if(a[i]<=time && c[i]<c[s] && c[i]>0)
            {
                s=i;
            }
        }
        c[s]--;
        if(c[s]==0)
        {
            comp++;
            timecomp=time+1;
            printf("\nP[%d]\t%d\t%d",s+1,timecomp-a[s],timecomp-b[s]-a[s]);
            tot_waiting+=timecomp-b[s]-a[s];
            tot_turn+=timecomp-a[s];
        }
    }
    printf("\n\nAverage waiting time = %.3f\n",tot_waiting*1.0/n);
    printf("Average Turnaround time = %.3f",tot_turn*1.0/5);
}

void Priority_Nonpre()
{
    int n,temp,i,j,k,s,f;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    int a[n],b[n],c[n],p[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the arrival time of the process %d:",i+1);
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time of the process %d:",i+1);
        scanf("%d",&b[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("Enter the Priority of process %d:",i+1);
        scanf("%d",&p[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    int co=a[0]+b[0];
    for(i=1;i<n;i++)
    {
        s=i;j=i;
        while(a[j]<=co)
        {
            f=j;
            j++;
        }
        for(k=s;k<f;k++)
        {
            if(p[k]>p[k+1])
            {
                temp=a[k];
                a[k]=a[k+1];
                a[k+1]=temp;
                temp=b[k];
                b[k]=b[k+1];
                b[k+1]=temp;
                temp=p[k];
                p[k]=p[k+1];
                p[k+1]=temp;
            }
        }
        co+=b[i];
    }
    c[0]=a[0]+b[0];
    for(i=1;i<n;i++)
    {
        c[i]=(c[i-1]+b[i]);
    }
    int tot_wait=0,tot_turn=0;
    printf("\nArrival\tBurst\tWaiting\tTurnaround\n");
    for(i=0;i<n-1;i++)
    {
        tot_wait+=(c[i]-a[i+1]);
        tot_turn+=(c[i]-a[i]);
        printf("%d\t%d\t%d\t%d\n",a[i],b[i],tot_wait,tot_turn);
    }
    float avg=tot_wait;
    printf("Average waiting time:%.3f ms\n",avg/n);
    avg=tot_turn;
    printf("Average turnaround time:%.3f ms\n",avg/n);
}

void Priority_pre()
{
struct process
{
     char pro_name;
     int a, b, ct, tot_wait, tot_turnaround, priority;
     int status;
};
     int i, time = 0, b = 0, largest,j,limit;
     char c;
     float wait_time = 0, tot_turnaround = 0, avg_wait,avg_turnaround;
     printf("\nEnter Total Number of Processes:");
     scanf("%d", &limit);
     struct process temp,pro[limit];
     for(i = 0, c = 'A'; i < limit; i++, c++)
     {
         pro[i].pro_name = c;
         printf("\nEnter Details For Process[%C]:\n", pro[i].pro_name);
         printf("Enter Arrival Time:\t");
         scanf("%d", &pro[i].a );
         printf("Enter Burst Time:\t");
         scanf("%d", &pro[i].b);
         printf("Enter Priority:\t");
         scanf("%d", &pro[i].priority);
         pro[i].status = 0;
         b = b + pro[i].b;
     }
     for(i = 0; i < limit - 1; i++)
     {
         for(j = i + 1; j < limit; j++)
         {
             if(pro[i].a > pro[j].a)
             {
                 temp = pro[i];
                 pro[i] = pro[j];
                 pro[j] = temp;
             }
         }
     }
     pro[9].priority = -9999;
     printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");
     for(time = pro[0].a; time < b;)
     {
     largest = 9;
     for(i = 0; i < limit; i++)
     {
         if(pro[i].a <= time && pro[i].status != 1 && pro[i].priority > pro[largest].priority)
         {
         largest = i;
         }
         }
         time = time + pro[largest].b;
         pro[largest].ct = time;
         pro[largest].tot_wait = pro[largest].ct - pro[largest].a - pro[largest].b;
         pro[largest].tot_turnaround = pro[largest].ct - pro[largest].a;
         pro[largest].status = 1;
         wait_time = wait_time + pro[largest].tot_wait;
         tot_turnaround = tot_turnaround + pro[largest].tot_turnaround;
         printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d", pro[largest].pro_name,pro[largest].a, pro[largest].b,pro[largest].priority, pro[largest].tot_wait);
     }
     avg_wait = wait_time / limit;
     avg_turnaround = tot_turnaround / limit;
     printf("\n\nAverage waiting time:\t%f\n", avg_wait);
     printf("Average Turnaround Time:\t%f\n", avg_turnaround);
}

void RR()
{
    int count,n,time,remain,flag=0,tq;
    int tot_wait=0,turnaround_time=0,a[10],b[10],r[10];
    printf("Enter Total Process:");
    scanf("%d",&n);
    remain=n;
    for(count=0;count<n;count++)
    {
        printf("Enter Arrival Time for Process %d :",count+1);
        scanf("%d",&a[count]);
    }
        for(count=0;count<n;count++)
    {
        printf("Enter Burst Time for Process %d :",count+1);
        scanf("%d",&b[count]);
        r[count]=b[count];
    }
    printf("Enter Time Quantum:");
    scanf("%d",&tq);
    printf("\n\nProcess\tTurnaround\tWaiting\n\n");
    for(time=0,count=0;remain!=0;)
    {
        if(r[count]<=tq && r[count]>0)
        {
            time+=r[count];
            r[count]=0;
            flag=1;
        }
        else if(r[count]>0)
        {
            r[count]-=tq;
            time+=tq;
        }
        if(r[count]==0 && flag==1)
        {
            remain--;
            printf("P[%d]\t%d\t%d\n",count+1,time-a[count],time-a[count]-b[count]);
            tot_wait+=time-a[count]-b[count];
            turnaround_time+=time-a[count];
            flag=0;
        }
        if(count==n-1)
            count=0;
        else if(a[count+1]<=time)
            count++;
        else
            count=0;
    }
    printf("\nAverage Waiting Time= %f\n",tot_wait*1.0/n);
    printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);
}

int main()
{
    int choice=1;
    char turn='Y';
    do{
    printf("\n1.First Come First Serve\n2.Shortest Job First\n3.Shortest Remaining time First\n4.Priority Non-Preemptive\n");
    printf("5.Priority Premptive\n6.Round Robin\n");
    printf("\nEnter your choice(number associated with the algorithm):");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("\n");
        FCFS();
        break;
    case 2:
        printf("\n");
        SJF();
        break;
    case 3:
        printf("\n");
        SRTF();
        break;
    case 4:
        printf("\n");
        Priority_Nonpre();
        break;
    case 5:
        printf("\n");
        Priority_pre();
        break;
    case 6:
        printf("\n");
        RR();
        break;
    default:
        printf("\n");
        printf("Invalid Choice.You can try again\n");
    }
    printf("\n\nDo You want to calculate again?(Y/N)\n");
    scanf(" %c",&turn);
    }while(turn=='Y' || turn=='y');
    return 0;
}
