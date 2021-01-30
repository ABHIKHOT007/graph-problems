#include <bits/stdc++.h>
using namespace std;

int shortestpath(string start, string target, set<string> &d)
{
    map<string, vector<string>> umap;

    for (int i = 0; i < start.size(); i++)
    {
        string str = start.substr(0, i) + "*" + start.substr(i + 1);
        umap[str].push_back(start);
    }
    for (auto it = d.begin(); it != d.end(); it++)
    {
        string word = *it;
        for (int j = 0; j < word.size(); j++)
        {
            string str = word.substr(0, j) + "*" + word.substr(j + 1);
            umap[str].push_back(word);
        }
    }

    queue<pair<string, int>> q;
    map<string, int> visited;
    q.push(make_pair(start, 1));
    visited[start] = 1;

    while (!q.empty())
    {
        pair<string, int> p = q.front();
        q.pop();
        string word = p.first;
        int dist = p.second;
        if (word == target)
        {
            return dist;
        }

        for (int i = 0; i < word.size(); i++)
        {
            string str = word.substr(0, i) + "*" + word.substr(i + 1);
            vector<string> vect = umap[str];
            for (int j = 0; j < vect.size(); j++)
            {
                if (visited[vect[j]] == 0)
                {
                    visited[vect[j]] = 1;
                    q.push(make_pair(vect[j], dist + 1));
                }
            }
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
    d.insert("plie");
    d.insert("plea");

    string start = "toon";
    string target = "plea";

    cout << "lenght of shortes chain is:" << shortestpath(start, target, d);
    return 0;
}