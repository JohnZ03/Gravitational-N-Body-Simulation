#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <cstring>

using namespace std;

string filename, body_id, out_name;
vector <string> load_results, ids;
map<string,vector<string > > bodies;
vector<string> tmp_vec;
int i,n;


int main(){
    string start_file = "results/solar_system.start";
    string output_file = "results/output_solar_system.csv";
    ifstream infile(start_file);
	if (infile.is_open()) {
        string line;
        
        //c++ solar_system.start
        //#Body,Earth,5.97219e24,9.257413659715463e10,1.162223446072777e11,-3.503818829730153e6,-2.365164523224623e4,1.861221602108803e4,-1.359714779090915e-3
        
        //#Body
        while (getline(infile, line)) {
            if(line.compare(0,1,"#")==0){
                if(line.compare(1, 4,"Body")==0){
                    load_results.clear();
                    stringstream s_stream(line);
                    while(s_stream.good()) {
                        string substr;
                        getline(s_stream, substr, ',');
                        load_results.push_back(substr); //load_results is in format of the values
                        
                        //printf("YO %s \n", substr.c_str());
                    }
                    ids.push_back(load_results.at(1)); //push back ids of body name
                    //printf("Hello %s \n", ids[0].c_str());
                    //printf("Bye %s \n", load_results.at(1).c_str());
                }
            }
        }
    }
    ifstream outfile(output_file);
    //outfile.open(output_file,fstream::out);
    
    if (outfile.is_open()) {
        //printf("Opened output_solar_system.csv\n");
        
        string line;
        while (getline(outfile, line)) {
            
            
            if(line.compare(0,8,"Timestep")!=0){ //if not timestep
                //printf("not a time step line\n");
                
                if(line.compare(0,1,"#")!=0){
                    //printf("New timestep\n");
                    
                    for (string body_id : ids){
                        //printf("# %s\n", body_id.c_str());
                        
                        if(line.compare(0,5,body_id.substr(0,5))==0){
                        
                            load_results.clear();
							stringstream s_stream(line);
							while(s_stream.good()) {
							    string substr;
							    getline(s_stream, substr, ',');
							    load_results.push_back(substr);
                                
                                //printf("load_results %s\n", load_results.c_str());
                                
							}
                            bodies[body_id].push_back(load_results.at(2)+","+load_results.at(3)+","+load_results.at(4));
                            
                            //printf("%s %s\n",body_id.c_str(), bodies[body_id][0].c_str());
                        }
                    }
                }
            }
        }
    }
    for (string body_id : ids){ 
        out_name = "results/" + body_id+"_output.csv";
        char out_name_c[out_name.size() + 1];
        out_name.copy(out_name_c, out_name.size() + 1);
        out_name_c[out_name.size()] = '\0';
        freopen(out_name_c,"w",stdout);
        for(i=0;i<bodies[body_id].size();i++){
            
            //printf("readingGGG %s\n", bodies[body_id][0].c_str());
            
            cout<<bodies[body_id].at(i);
            cout<<"\n";
        }
    }
}
