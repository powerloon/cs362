
#include "sched.h"

int mfqs(){
    int queues = -1;
    int q = -1;
    int maxage = -1;

    cout << "\n\nSelected MFQS";
    cout << "\nEnter number of queues(1-5): ";
    cin >> queues;
    cout << "\n";
    
    cout << "\nEnter size of the Time Quantum: ";
    cin >> q;
    cout << "\n";
    
    cout << "\nEnter the Maximum Age Time: ";
    cin >> q;
    cout << "\n";

    if(queues < 1 && queues > 5){
        cout << "\nError: Invalid Number of Queues Input";
        exit(1);
    }

    if(q < 1){
        cout << "\nError: Invaild Time Quantum Input";
        exit(1);
    }
    
    if(maxage < 1){
        cout << "\nError: Invaild Maximum Age Input";
        exit(1);
	}

	//getProcesses();
	int numLines;
	
    Process* processes(getProcesses(&numLines));
	
	cout << "numLines: " << numLines << endl;
	
	print_in_file(processes, &numLines);

    for (int i = 0; i < numlines; i++){
        if(processes[i].get_burst > 0){

            for(int j = 0; j < q; j++) { processes[i].set_burst(processes[i].get_burst() - 1) };
            
            if(processes[i].get_burst > 0){
                if(processes[i].get_level < (queues * q)){
                    processes[i].set_level(processes[i].get_level() + 1)
                }else{
                    if(processes.get_age()){
                        processes[i].set_level(processes[i].get_level() - 1);
                    }
                } 
            }
        }
    }
    	
    
}
