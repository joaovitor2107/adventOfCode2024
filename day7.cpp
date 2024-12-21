#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool valid(int tam, long long num, long long val, const vector<long long>& vec){
    if(tam == 0) return num == val;
    if(tam < 0) return false;
    if(valid(tam - 1, num + vec[vec.size() - tam], val, vec)) return true;
    if(valid(tam - 1, num * vec[vec.size() - tam], val, vec)) return true;
    return false;
}

int main(){
    long long result = 0;
    string lines;
    while (getline(cin, lines)) {
        if (lines.empty()) continue;
        
        string digits;
        vector<long long> nums;
        long long val;
        int i = 0;
        
        while (i < lines.size() && (isdigit(lines[i]) || lines[i] == '.')) {
            digits += lines[i++];
        }
        
        if (digits.empty() || i >= lines.size() || lines[i] != ':') {
            continue;
        }
        
        val = stoll(digits);  
        
        i++; 
        while (i < lines.size() && isspace(lines[i])) {
            i++;
        }
        
        while (i < lines.size()) {
            while (i < lines.size() && isspace(lines[i])) {
                i++;
            }
            
            string digits2;
            while (i < lines.size() && (isdigit(lines[i]) || lines[i] == '.')) {
                digits2 += lines[i++];
            }
            
            if (!digits2.empty()) {
                    nums.push_back(stoll(digits2));  // Using stoll instead of stod
            }
        }
        
        if (!nums.empty()) {
            if(valid(nums.size() - 1, nums[0], val, nums)) result += val;
        }
    }
    cout << result << "\n";
    return 0;
}
