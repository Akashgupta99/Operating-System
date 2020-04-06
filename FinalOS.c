#include<stdio.h>
#include<stdlib.h>


int main(){

    int i,j,k,t,t1,bt1[5]={0},at[5]={0,3,6,9,12},tat[5]={0},wt[5]={0},ct[5]={0},bt[5] = {0};

	int totalProcess,tBT=0,time=0, temp;

	float tTAT=0,tWT=0;
	FILE *fp,*fpp;
	
	
	fp = fopen("BURST_TIME.txt","w");
	
	if(fp == NULL){
		
		printf("Error!");
		exit(0);
		
	}
	
	for(i=0;i<5;i++){

		printf("\nEnter Burst Time for process %d : ",i+1);

		scanf("%d",&bt1[i]);
		
		fprintf(fp,"%d ",bt1[i]);

	}
	fclose(fp);
	
	fpp = fopen("BURST_TIME.txt","rw");
	
	fscanf(fpp,"%d %d %d %d %d",&bt[0],&bt[1],&bt[2],&bt[3],&bt[4]);
	
	fclose(fpp);



	//Swapping if user has not entered arrival time in ascending order

	for(i=0;i<5;i++){

        for(j=i+1; j<5; j++){

            if(at[i] > at[j]){

                t = at[i];

                t1 = bt[i];

                at[i] = at[j];

                bt[i] = bt[j];

                at[j] = t;

                bt[j] = t1;

            }

        }

    }



    k=1;

    //sort using burst time

    for(j=0;j<5;j++){

        time = time + bt[j];

        t = bt[k];

        for(i=k;i<5;i++){

            if(time>=at[i] && bt[i]<t){

                temp = at[k];

                at[k] = at[i];

                at[i] = temp;

                temp = bt[k];

                bt[k] = bt[i];

                bt[i] = temp;

            }

        }

        k++;

    }



    tBT = at[0];

    for( j=0;j<5;j++){

		tBT+=bt[j];

		ct[j]+=tBT;

	}



	//calculate turnaround time and waiting times

	for(k=0;k<5;k++){

		tat[k]=ct[k]-at[k];

		wt[k]=tat[k]-bt[k];

		tTAT+=tat[k];

        tWT+=wt[k];

	}



    //Printing Table

	printf("\n\n\t\t\t\t\tANSWER\n\n\tArrival Time\t\tBurst Time\t\tCompletion Time\t\tTurn Around Time\t\tWaiting Time\t\n\n");



	for(i=0;i<5;i++){

		printf("P%d\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);

	}

	printf("----------------------------------------------------------------------------------------------------------------");

	printf("\nTotal\t\t\t\t\t\t\t\t\t\t%.2f\t\t\t\t%.2f\n",tTAT,tWT);



	printf("\n\nAverage Turnaround Time = %f\n",tTAT/5);

	printf("Average WT = %f\n\n",tWT/5);
	


}
