#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <unordered_set>

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
            pair<int, int>aux = parseRule(line);
            rules[aux.first].insert(aux.second);
        } else {
            sequences.push_back(parseSequence(line));
        }
    }
    
    int sum = 0;
    for (const auto& seq : sequences) {
        if (isValidSequence(seq, rules)) {
            sum += seq[seq.size() / 2];
        }
    }
    
    cout << sum << "\n";
    return 0;
}
