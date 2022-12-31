#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

#define ll long long
#define v vector
using namespace std;
using namespace std::chrono;


int main() {
    auto start = high_resolution_clock::now();
    string line;
    ifstream myfile("/Users/zainzaidi/Desktop/input");
    int sum1 = 0;
    int sum2 = 0;
    while (getline(myfile, line)) {
    	int x1 = stoi(line.substr(0, line.find("-")));
    	int x2 = stoi(line.substr(line.find("-") + 1, line.find(",") - line.find("-") - 1));
    	line = line.substr(line.find(",")+1);
    	int y1 = stoi(line.substr(0, line.find("-")));
    	int y2 = stoi(line.substr(line.find("-") + 1, line.find(",") - line.find("-") - 1));
    	if((x1 <= y2 && y1 <= x2)){
    	sum2++;
    	}
    	if((x1 >= y1 && y2 >= x2) || (x1 <= y1 && y2 <= x2)){
    	sum1++;
    	}

    }

    //time code
    cout << sum1 << " " << sum2 << endl; 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;


}