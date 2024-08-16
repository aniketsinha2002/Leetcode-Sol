class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(),tokens.end()); 
        int score = 0;
        int maxScore  =0;
        
        int i=0, j=n-1;

        while(i<=j)
        {
            if(power>=tokens[i])
            {
                power -= tokens[i];
                score+=1;
                i++;
                maxScore = max(maxScore, score);
            }
            else 
            {
                if(score>=1)
                {
                    power += tokens[j];
                    score --;
                    j--;
                    maxScore = max(maxScore, score);
                }
                else
                    return maxScore;
            }            
        }
        return maxScore;
    }
};