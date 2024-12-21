#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<int> parseSequence(const string& line) {
    vector<int> result;
    stringstream ss(line);
    string num;
    while (getline(ss, num, ',')) {
        result.push_back(stoi(num));
    }
    return result;
}

pair<int, int> parseRule(const string& line) {
    size_t pos = line.find('|');
    int before = stoi(line.substr(0, pos));
    int after = stoi(line.substr(pos + 1));
    return {before, after};
}

bool isValidSequence(const vector<int>& seq, 
                    const unordered_map<int, unordered_set<int>>& rules) {
    for (size_t i = 0; i < seq.size(); i++) {
        int current = seq[i];
        for (size_t j = i + 1; j < seq.size(); j++) {
            int next = seq[j];
            if (rules.count(next) && rules.at(next).count(current)) {
                return false;
            }
        }
    }
    return true;
}

bool compareByRules(int a, int b, const unordered_map<int, unordered_set<int>>& rules) {
    if (rules.count(a) && rules.at(a).count(b)) return true;
    if (rules.count(b) && rules.at(b).count(a)) return false;
    return false;
}

vector<int> sortSequence(vector<int> seq, const unordered_map<int, unordered_set<int>>& rules) {
    sort(seq.begin(), seq.end(), [&rules](int a, int b) {
        return compareByRules(a, b, rules);
    });
    return seq;
}

int main() {
    string line;
    unordered_map<int, unordered_set<int>> rules;
    vector<vector<int>> sequences;
    bool parsingRules = true;
    
    while (getline(cin, line)) {
        if (line.empty()) {
            parsingRules = false;
            continue;
        }
        
        if (parsingRules) {
    		pair<int, int> aux= parseRule(line);
            rules[aux.first].insert(aux.second);
        } else {
            sequences.push_back(parseSequence(line));
        }
    }
    
    int sum = 0;
    for (auto seq : sequences) {
        // Only process sequences that are initially invalid
        if (!isValidSequence(seq, rules)) {
            vector<int> sortedSeq = sortSequence(seq, rules);
            // If sorting made it valid, add its middle element
            if (isValidSequence(sortedSeq, rules)) {
                sum += sortedSeq[sortedSeq.size() / 2];
            }
        }
    }
    
    cout << sum << "\n";
    return 0;
}
