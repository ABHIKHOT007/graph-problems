#include<bits/stdc++.h>
using namespace std;
//word ladder

int shortestpath(string start, string target, set<string> &d)
{
    if(d.find(target)==d.end()){
        return 0;
    }

    int level=0;
    int wordlength=start.size();

    queue<string> q;
    q.push(start);
    while(!q.empty()){
        string word=q.front();
        q.pop();
        for(int pos=0;pos<wordlength;pos++){
            char ori_char=word[pos];
            for(char c='a';c<='z';c++){
                word[pos]=c;
                if(word==target){
                    return level+1;
                }
                if(d.find(word)==d.end()){
                    continue;
                    d.erase(word);
                    q.push(word);
                }
            }
            word[pos];
        }
    }
    return 0;
}

int main()
{
    set<string> d;
    d.insert("poon");
    d.insert("plee");
    d.insert("same");
    d.insert("poie");
    d.insert("poin");
    d.insert("plea");
    string start="toon";
    string target="plea";
    cout<<"lenght of the shortest chain is:"<<shortestpath(start,target,d)<<endl;
    return 0;
}