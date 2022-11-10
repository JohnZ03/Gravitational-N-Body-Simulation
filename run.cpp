#include "main.cpp"
#include "hrtime.h"
int step;
long double steps, endtime;

int main(){
    
    double start_time, end_time;
    
    start_time = getElapsedTime();
    System sys;
    sys.SetStartTime(18000);
    sys.timestep = 1;
    sys.LoadFile("burn_test.start");
    sys.SetOutToFile("output.txt",1);
    endtime = 19000;
    steps = endtime/sys.timestep;
    for(step=0;step<steps;step++){
        sys.Output();
        sys.Step();
    }
    
    end_time = getElapsedTime();
    printf("Code took %lf seconds \n", end_time - start_time);
    
}
