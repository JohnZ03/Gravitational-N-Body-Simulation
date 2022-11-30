#include "main.cpp"

int step;
long double steps, endtime;

int main(){
    
    double start_time, end_time;
    
    System sys;
    sys.SetStartTime(18000);
    sys.timestep = 10; //1
    sys.LoadFile("results/solar_system.start");
    sys.SetOutToFile("results/output_solar_system.csv",1);
    endtime = 190000000000;
    steps = endtime/sys.timestep;
    
    for(step=0;step<steps;step++){
        sys.Output();
        sys.Step();
    }
    
//end_time = getElapsedTime();
    printf("Code took %lf seconds \n", end_time - start_time);
    
}
