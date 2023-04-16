//Task 2

#include<stdio.h>
#include<stdlib.h>

struct Process {
    char pid[10];
    int BT, CT, TT, WT, RT;  //RT=remaining time
};


int main(){
    int n, q;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter time quantum: ");
    scanf("%d", &q);



    struct Process p[n];
    for(int i=0; i<n; i++){
        printf("\nEnter pid for process %d: ", i+1);
        scanf("%s", &p[i].pid);

        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &p[i].BT);
        p[i].RT = p[i].BT;
     }

     int cur_time = 0, completed = 0, cur_p = 0, i=0;

     while(completed<n){
        if(p[i].RT<=q && p[i].RT>0){
            cur_time += p[i].RT;
            p[i].RT -= p[i].RT;
            p[i].CT = cur_time;
            p[i].TT = cur_time;
            p[i].WT = p[i].TT - p[i].BT;
            completed++;
        }else if(p[i].RT>0){
            cur_time += q;
            p[i].RT -= q;
        }

        i = (i+1)%n;
     }

     printf("\nProcess\tBT\tCT\tTT\tWT\n");
     for(int i=0; i<n; i++){
        printf("%s\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].BT, p[i].CT, p[i].TT, p[i].WT);
     }

     return 0;

};

