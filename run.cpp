#include "main.cpp"
#include <chrono>

int step;
long double steps, endtime;

int main(){
    //g++ -o run run.cpp
    double start_time, end_time;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    printf("Program is running .... \n");
    System sys;
    sys.SetStartTime(18000);
    sys.timestep = 10; //1
    sys.LoadFile("results/solar_system.start");
    sys.SetOutToFile("results/output_solar_system.csv",1);
    endtime = 190000;
    steps = endtime/sys.timestep;
    
    for(step=0;step<steps;step++){
        sys.Output();
        sys.Step();
    }
    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    
}
