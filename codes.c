
 // code for fcfs algorithim
#include<stdio.h>
int main()
{
    int n;
    printf("enter the number of processes");
    scanf("%d",&n);
    int at[32], bt[20], ct[20],tat[20],wt[20];
    for(int i=0;i<n;i++)
    {
        printf("enter the arrval and burst time of the processes %d", i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }

    // sort on bases of arrival time
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(at[i]>at[j])
            {
                int t;
                t=at[i];
                at[i]=at[j];
                at[j]=t;

                t=bt[i];
                bt[i]=bt[j];
                bt[j]=t;
            }
        }
    }

    // values of ct, tat, wt
    int time=0;
    for(int i=0;i<n;i++)
    {
        if(time<at[i])
        {
            time=at[i];
        }
        ct[i]=time+bt[i];
        time=ct[i];

        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

    printf("\nprocess\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("p%d\t%d\t%d\t%d\t%d\t%d\n" , i+1,at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // calculating avgerages time
     float  avgtat=0,avgwt=0;
     for(int i=0;i<n;i++)
     {
        avgtat+=tat[i];
        avgwt+=wt[i];
     }
     avgtat/=n;
     avgwt/=n;

     printf("%f%f", avgtat, avgwt);
     return 0;
}

// code for sjf algorithim
#include<stdio.h>
#include<limits.h>
int main()
{
    int n;
    printf("enter the number of processes");
    scanf("%d",&n);
    int at[32], bt[20], ct[20],tat[20],wt[20], done[20];
    int time=0, completed=0;
    for(int i=0;i<n;i++)
    {
        printf("enter the arrval and burst time of the processes %d", i+1);
        scanf("%d%d",&at[i],&bt[i]);
        done[i]=0;
    }

    while(completed<n)
    {
        int idx=-1, minbt=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(!done[i] && at[i]<=time && bt[i]<minbt)
            {
                minbt=bt[i];
                idx=i;
            }
        }

        if(idx==-1)
        {
            time++;
        }else
        {
            ct[idx]=time+bt[idx];
            time=ct[idx];
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];
            done[idx]=1;
            completed++;
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("p%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i],wt[i]);
    }
    float a1=0, a2=0;
    for(int i=0;i<n;i++)
    {
        a1+=tat[i];
        a2+=wt[i];
    }
    a1/=n;
    a2/=n;
    printf("%f\n%f", a1,a2);
    return 0;
}

// priroty sheduling algorithim

#include<stdio.h>
#include<limits.h>
int main()
{
    int n;
    printf("enter the number of processes");
    scanf("%d",&n);
    int at[32], bt[20],pt[20], ct[20],tat[20],wt[20], done[20];
    int time=0, completed=0;
    for(int i=0;i<n;i++)
    {
        printf("enter the arrval and burst time and priority of the processes %d", i+1);
        scanf("%d%d%d",&at[i],&bt[i], &pt[i]);
        done[i]=0;
    }

    while(completed<n)
    {
        int idx=-1,minpt=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(!done[i] && at[i]<=time && pt[i]<minpt)
            {
                minpt=pt[i];
                idx=i;
            }
        }
        if(idx==-1) time++;
        else
        {
            ct[idx]=time+bt[idx];
            time=ct[idx];
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];
            done[idx]=1;
            completed++;
        }
    }

    printf("\nP\tAT\tBT\tPT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("\n%dp\t%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i],pt[i],ct[i],tat[i],wt[i]);
    }
    float a1=0, a2=0;
    for(int i=0;i<n;i++)
    {
        a1+=tat[i];
        a2+=wt[i];
    }
    a1/=n;
    a2/=n;
    printf("%f\n%f", a1,a2);
    return 0;
}

// round robin algorithim based on time quanta
#include<stdio.h>
#include<limits.h>
int main()
{
    int n;
    printf("enter the number of processes ::-");
    scanf("%d",&n);
    int at[32], bt[20],ct[20],tat[20],wt[20], rt[20];
    int time=0, completed=0;
    for(int i=0;i<n;i++)
    {
        printf("enter the arrval and burst time and priority of the processes %d::-> ", i+1);
        scanf("%d%d",&at[i],&bt[i]);
        
    }
     int tq;
     printf("enter the value of time quanta::-> ");
     scanf("%d",&tq);

    while(completed<n)
    {
        int d=0;
       for(int i=0;i<n;i++)
       {
        if(rt[i]>0 && at[i]<=time)
        {
            if(rt[i]>tq)
            {
                time+=tq;
                rt[i]-=tq;
            }
            else
            {
                time+=rt[i];
                rt[i]=0;
                ct[i]=time;
                tat[i]=ct[i]-at[i];
                wt[i]=tat[i]-bt[i];
                completed++;
            }
        }
       }
       if(!d) time++;
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("\n%dp\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i],ct[i],tat[i],wt[i]);
    }
    float a1=0, a2=0;
    for(int i=0;i<n;i++)
    {
        a1+=tat[i];
        a2+=wt[i];
    }
    a1/=n;
    a2/=n;
    printf("%f\n%f", a1,a2);
    return 0;
}
 // pipe system call 

 #include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char read_msg[100], write_msg[100];

    // Take input message from user
    printf("Enter a message: ");
    scanf("%s", write_msg);

    // Create pipe
    if (pipe(fd) == -1) {
        printf("Failed to create pipe\n");
        return 1;
    }

    if (fork() == 0) {
        // Child process -> read
        close(fd[1]);   // Close write end
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
        close(fd[0]);
    } else {
        // Parent process -> write
        close(fd[0]);   // Close read end
        write(fd[1], write_msg, strlen(write_msg) + 1);
        close(fd[1]);
    }

    return 0;
}

// fork system call

#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        // Child process
        for (char c = 'A'; c <= 'E'; c++) {
            printf("Child prints: %c\n", c);
        }
    }
    else if (pid > 0) {
        // Parent process
        for (int i = 1; i <= 5; i++) {
            printf("Parent prints: %d\n", i);
        }
    }
    else {
        printf("Fork failed!\n");
    }

    return 0;
}
 // srtf prremptiv 

 #include <stdio.h>
#include<limits.h>
int main() {
    int n;
    scanf("%d",&n);
    int at[20], bt[20],ct[20],tat[20],wt[20],rt[20];
    int completed=0, time=0;
    float avgtat=0, avgwt=0;
    for(int i=0;i<n;i++)
    {
        printf("enter the arrivala nd burst time of process %d--",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }
    
    while(completed!=n)
    {
        int idx=-1, minrt=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0 && rt[i]<minrt)
            {
                minrt=rt[i];
                idx=i;
            }
        }
        if(rt[idx]!=-1)
        {
              rt[idx]--;
        
          if(rt[idx]==0)
        {
            completed++;
            ct[idx]=time+1;
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];
            avgtat+=tat[idx];
            avgwt+=wt[idx];
        }
    }
    time++;
    }
    
    printf("\nP\tAT\tBT\tTAT\tCT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\n",i+1, at[i], bt[i],tat[i], ct[i], wt[i]);
    }
    
    printf("average turn arounftime and burst time is %f%f",avgtat/n,avgwt/n);
    return 0;
    
 
}
