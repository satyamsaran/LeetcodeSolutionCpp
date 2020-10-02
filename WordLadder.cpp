class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //shortest path
        //put the word list in a hash map
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        //SP algo's queue
        queue<pair<string,int>> q;
        unordered_set<string> visited;
        pair<string,int> qElt;
        string currWord,tempWord;
        int currDist,i,j;
        
        //initialisation
        //push into queue and mark as visited
        q.push({beginWord,1});
        visited.insert(beginWord);
        
        while(!q.empty()){
            
            qElt=q.front();
            q.pop();
            
                currWord=qElt.first;
                currDist=qElt.second;
                if(currWord==endWord) return currDist;
                
                //process its negbrs
                //for every index of word, consider all possibilities
            tempWord=currWord;
            for(i=0;i<currWord.size();i++){
                for(j=0;j<26;j++){
                    tempWord[i]=(char)(j+'a');
                    //if in dict but not visited 
                    if(dict.find(tempWord) !=dict.end() && visited.find(tempWord)==visited.end()){
                        visited.insert(tempWord);
                        q.push({tempWord,currDist+1});
                    }
                }
                tempWord[i]=currWord[i];
            }
            
        }
        return 0;
    }
};
