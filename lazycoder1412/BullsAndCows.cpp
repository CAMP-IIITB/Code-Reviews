class Solution {
public:
    string getHint( const string& secret, const string& guess) {
        vector<int> cnt(10, 0);
        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i])
                bulls++;
            else{
                int curr = secret[i] - '0';
                cnt[curr]++;
            }

        }
        for (int i = 0; i < guess.size(); i++) {
            if (secret[i] != guess[i] and cnt[guess[i] - '0'] > 0) {
                cows++;
                int curr = guess[i] - '0';
                cnt[curr]--;
            }
        }
        string ans = to_string(bulls) + 'A' + to_string(cows) + 'B';
        return ans;
    }
};
