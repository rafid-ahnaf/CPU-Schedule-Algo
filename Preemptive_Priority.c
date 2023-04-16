//Task 3

#include<stdio.h>
#include<stdlib.h>

struct Process {
    char pid[10];
    int priority, AT, BT, CT, TT, WT, RT;  //RT=remaining time
};

void ascending_sort(struct Process p[], int n){
    struct Process temp;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(p[i].AT > p[j].AT){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}


int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for(int i=0; i<n; i++){
        printf("\nEnter pid for process %d: ", i+1);
        scanf("%s", &p[i].pid);

        printf("Enter arrival time for process %d: ", i+1);
        scanf("%d", &p[i].AT);

        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &p[i].BT);
        p[i].RT = p[i].BT;

        printf("Enter priority for process %d: ", i+1);
        scanf("%d", &p[i].priority);
    }

    ascending_sort(p, n);


    int cur_time = 0, completed = 0;
    while(completed!=n){
        int minPriority = 9999, index = -1;

        for(int i=0; i<n; i++){
            if(p[i].AT<=cur_time && p[i].RT>0){
                if(p[i].priority<minPriority){
                    minPriority = p[i].priority;
                    index = i;
                }
            }
        }

        if(index == -1){
            cur_time++;
        }else{
            cur_time++;
            p[index].RT--;

            if(p[index].RT == 0){
                p[index].CT = cur_time;
                p[index].TT = p[index].CT-p[index].AT;
                p[index].WT = p[index].TT - p[index].BT;
                completed++;
            }
        }

    }

    printf("\nProcess\tAT\tBT\tCT\tTT\tWT\tPriority\n");
    for(int i=0; i<n; i++){
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].AT, p[i].BT, p[i].CT, p[i].TT, p[i].WT, p[i].priority);
    }

    return 0;

}

