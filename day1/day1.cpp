#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#define ll long long
#define v vector
using namespace std;

int main() {
    v<int> data;
    string line;
    ifstream myfile("C:\\Users\\Zain\\CLionProjects\\untitled4\\input");
    int sum = 0;
    while (getline(myfile, line)) {
        if (line != "") {
            sum += stoi(line);
        }
        else{
            data.push_back(sum);
            sum = 0;
        }
    }
    sum = 0;
    for(int i = 0; i < 3; i++){
        int greatest = 0;
        int position = 0;
        for(int j = 0; j < data.size(); j++){
            if(data.at(j) > greatest){
                greatest = data.at(j);
                position = j;
            }
        }
        if(i == 0){
            cout << "PART1: " <<  greatest << endl;
        }

        sum = sum + greatest;
        data.erase(data.begin() + position);

    }
    cout << "PART2: " << sum;




}