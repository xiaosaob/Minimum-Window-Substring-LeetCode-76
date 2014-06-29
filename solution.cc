// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".

// Note:
// If there is no such window in S that covers all characters in T, return the emtpy string "".

// If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

class Solution {
public:
    string minWindow(string S, string T) {
        vector<int> needed(256, 0);
        vector<int> found(256, 0);
        for(int i = 0; i < T.size(); ++i) 
            ++needed[T[i]];
        int start = 0, end = 0, count = 0;
        int bestStart = -1, minLen = INT_MAX;
        while(end < S.size()) {
            while(end < S.size() && count < T.size()) {
                if(++found[S[end]] <= needed[S[end]]) {
                    if(++count == T.size()) {
                        if(end-start+1 < minLen) {
                            minLen = end-start+1;
                            bestStart = start;
                        }
                    }
                }
                ++end;
            }
            if(count < T.size()) break;
            while(start < end && count == T.size()) {
                if(--found[S[start]] < needed[S[start]]) {
                    --count;
                } else {
                    if(end-start-1 < minLen) {
                        minLen = end-start-1;
                        bestStart = start+1;
                    }
                }
                ++start;
            }
        }
        return bestStart == -1 ? "" : S.substr(bestStart, minLen);
    }
};
