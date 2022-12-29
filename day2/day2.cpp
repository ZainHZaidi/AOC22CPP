#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

#define ll long long
#define v vector
using namespace std;
using namespace std::chrono;

// returns 1 for me 0 for you -1 for draw
int game(int you, int me) {
    if (you == 1) {
        if (me == 1) { return 0; }
        else if (me == 2) { return 1; }
        else if (me == 3) { return -1; }
    }
    if (you == 2) {
        if (me == 1) { return -1; }
        else if (me == 2) { return 0; }
        else if (me == 3) { return 1; }
    } else if (you == 3) {
        if (me == 1) { return 1; }
        else if (me == 2) { return -1; }
        else if (me == 3) { return 0; }
    }

}

void part1(v<int> me, v<int> you) {
    int myScore = 0;
    int youScore = 0;
    for (int i = 0; i < me.size(); i++) {
        if (game(you.at(i), me.at(i)) == 0) {
            myScore = myScore + me.at(i) + 3;
            youScore = youScore + you.at(i) + 3;
        } else if (game(you.at(i), me.at(i)) == 1) {
            myScore = myScore + me.at(i) + 6;
            youScore = youScore + you.at(i);
        } else if (game(you.at(i), me.at(i)) == -1) {
            myScore = myScore + me.at(i);
            youScore = youScore + you.at(i) + 6;
        }


    }
    cout << "PART1: " << myScore << endl;
}

void part2(v<int> moves, v<int> you) {
    int myScore = 0;
    int youScore = 0;
    for (int i = 0; i < you.size(); i++) {
        if (moves.at(i) == 1) {
            for (int j = 1; j <= 3; j++) {
                if (game(you.at(i), j) == -1) {
                    myScore = myScore + j;
                    youScore = youScore + you.at(i) + 6;
                }
            }
        } else if (moves.at(i) == 2) {
            for (int j = 1; j <= 3; j++) {
                if (game(you.at(i), j) == 0) {
                    myScore = myScore + j + 3;
                    youScore = youScore + you.at(i) + 3;
                }
            }

        } else if (moves.at(i) == 3) {
            for (int j = 1; j <= 3; j++) {
                if (game(you.at(i), j) == 1) {
                    myScore = myScore + j + 6;
                    youScore = youScore + you.at(i) + 0;
                }
            }

        }
    }
    cout << "PART2: " << myScore << endl;
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