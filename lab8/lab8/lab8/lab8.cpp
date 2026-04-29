#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<queue>
using namespace std;

ifstream fin("lab8.in");

void lowercase(string &cuv) {
    for (int i = 0; i < cuv.size(); i++) {
        if (cuv[i] >= 'A' && cuv[i] <= 'Z') {
            cuv[i] += ('a' - 'A');
        }
    }
}


map<string, int> frecv;
struct Compare {
    bool operator()(string a, string b) {
        if (frecv[a] != frecv[b]) {
            return frecv[a] < frecv[b];
        }
        return a > b;
    }
};
priority_queue<string, vector<string>, Compare> pq;

string sentence, cuv;
string separators = " ,.?!";
int main()
{
    getline(fin, sentence);
    auto start = sentence.find_first_not_of(separators);

    while (start != string::npos) {
        auto end = sentence.find_first_of(separators, start);
        cuv = sentence.substr(start, end - start);
        lowercase(cuv);
        frecv[cuv]++;
        start = sentence.find_first_not_of(separators, end);
    }
    
    for (auto it : frecv) {
        pq.push(it.first);
    }

    while (!pq.empty()) {
        cout << pq.top() << " => " << frecv[pq.top()] << '\n';
        pq.pop();
    }
    
    return 0;
}