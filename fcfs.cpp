#include <iostream>
using namespace std;
typedef struct Process{
	int btime;
	int atime;
	int stime;
	int ftime;
};

void fcfs(Process process[], int n){
	int stime, ftime;
	stime=process[0].atime;
	ftime=process[0].btime+stime;
	cout<<"Process number: "<<1<<" Selection time:"<<stime<<" Finish time: "<<ftime<<endl;
	for(int i=1;i<n;i++){
		if(process[i].atime > process[i-1].ftime){
			process[i].stime=process[i].atime;
		}
		else{
			process[i].stime=process[i-1].ftime;
		}
		process[i].ftime=process[i].btime+process[i].stime;
		cout<<"Process number: "<<i+1<<" Selection time:"<<process[i].stime<<" Finish time: "<<process[i].ftime<<endl;
	}
}

int main(){
	Process process[4];
	cout<<"Enter number of processes: ";
	int n;
	cin>>n;
	cout<<"Enter the details in sorted order:\n";
	for(int i=0;i<n;i++){
		cout<<"Enter brust time:";
		cin>>process[i].btime;
		cout<<"Enter arrival time:";
		cin>>process[i].atime;
	}

	fcfs(process,n);
	return 0;
}