class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> cnt(10,0);
        int bulls=0,cows=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i])
                bulls++;
            else
                cnt[secret[i]-'0']++;
            
        }
        for(int i=0;i<guess.size();i++){
            if(secret[i]!=guess[i] and cnt[guess[i]-'0']>0){
                cows++;
                cnt[guess[i]-'0']--;
            }
        }
        string ans=to_string(bulls)+'A'+to_string(cows)+'B';
        return ans;
    }
};
