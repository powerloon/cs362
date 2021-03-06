#ifndef SCHED_H
#define SCHED_H

#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <pthread.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <time.h>
    
 
using namespace std;

/* Process class */
class Process {
    private:
		int p_id;
		int burst;
		int burst_original;
		int arrival;
		int priority;
		int priority_original;
		int deadline;
		int start_time;
		int end_time;
		int io;
		int age;
		int level;
		int increment;
    public:
		Process();
        Process(int, int, int, int, int, int);
		void set_values(int,int,int,int,int,int);
		int get_p_id() {return p_id;}
		int get_burst() {return burst;}
		int get_burst_original() {return burst_original;}
		int get_arrival() {return arrival;}
		int get_priority() {return priority;}
		int get_priority_original() {return priority_original;}
		int get_deadline() {return deadline;}
		int get_io() {return io;}
		int get_level() {return level;}
		int get_age() {return age;}
		int get_start_time() {return start_time;}
		int get_end_time() {return end_time;}
		int get_increment() {return increment;}
		void set_p_id(int _p_id) {p_id = _p_id;}
		void set_burst(int _burst) {burst = _burst;}
		void set_priority(int _priority) {priority = _priority;}
		void set_age(int _age) {age = _age;}
		void set_level(int _level) {level = _level;}
		void set_start_time(int _start_time) {start_time = _start_time;}
		void set_end_time(int _end_time) {end_time = _end_time;}
		void set_io(int _io) {io = _io;}
		void set_increment(int _increment) {increment = _increment;}
		void to_string();
        bool is_done();
};

int mfqs();
int rts();
int hs();

/* Input */
Process* getProcesses(int*);
void print_in_file(Process*, int*);

/* Stats */
void print_stats(Process*, int*);
void print_stats_full(Process*, int*);

/* MFQS */
void quickSort(Process*, int, int);

/* RTS */
void runRTS(Process*, int*, bool);
void sort_mfqs(Process*, int*);

#endif
