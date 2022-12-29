#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

#define ll long long
#define v vector
using namespace std;
using namespace std::chrono;


void part1() {
    int b;
    cout << "PART1: " << b << endl;
}

void part2() {
    int b;
    cout << "PART2: " << b << endl;
}


int main() {
    auto start = high_resolution_clock::now();
    v<int> you;
    v<int> me;
    string line;
    ifstream myfile("C:\\Users\\Zain\\CLionProjects\\untitled4\\input");
    int sum = 0;
    while (getline(myfile, line)) {
        me.push_back(line.at(2) - 87);
        you.push_back(line.at(0) - 64);
    }
    part1(me, you);
    part2(me, you);


    //time code
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;


}