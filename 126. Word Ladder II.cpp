#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <map>
#include <string>
#include <queue>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > paths;
        vector<string> path;
        unordered_set<string> frontque;
        unordered_set<string> backque;
        unordered_map<string, vector<string> > next;
        bool findFlag = false;
        unordered_set<string> s;

        for (auto item : wordList)
        {
            s.insert(item);
        }

        //首先确定有没有目标字符串
        if(s.find(endWord) == s.end())
        {
            return paths;            
        }

        frontque.insert(beginWord);
        backque.insert(endWord);
        while(!frontque.empty() && !backque.empty())
        {
            if(frontque.size() <= backque.size())
            {
                findFlag = bfs_extend(frontque, backque, s, next, true);
            }
            else
            {
                findFlag = bfs_extend(backque, frontque, s, next, false);
            }

            if(true == findFlag)
            {
                //cout<<"already find!!!!!"<<endl;
                break;
            }
        }

        if(true == findFlag)
        {
            path.push_back(beginWord);
            createPaths(beginWord, endWord, path, paths, next);
        }

        return paths;
    }

    
    bool bfs_extend(unordered_set<string>& beginque, unordered_set<string>& endque, unordered_set<string>& wordList, 
                    unordered_map<string, vector<string> >& next, bool flag)
    {
        char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                            'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        unordered_set<string> nextqueue;
        bool findFlag = false;

        for(auto item : beginque)
        {
            wordList.erase(item);
        }

        for(auto item : endque)
        {
            wordList.erase(item);
        }

        while(!beginque.empty())
        {
            string keyWord = *(beginque.begin());
            beginque.erase(keyWord);
            for(int pos = 0; pos < keyWord.length(); pos++)
            {
                string tempWord = keyWord;
                for(int alphaPos = 0; alphaPos < 26; alphaPos++)
                {
                    tempWord[pos] = alpha[alphaPos];
                    if(endque.find(tempWord) != endque.end())
                    {
                        findFlag = true;
                        flag ? next[keyWord].push_back(tempWord) : next[tempWord].push_back(keyWord);
                        //createNext(tempWord, keyWord, next, flag);
                    }
                    else if(!findFlag && wordList.find(tempWord) != wordList.end())
                    {
                        flag ? next[keyWord].push_back(tempWord) : next[tempWord].push_back(keyWord);
                        //createNext(tempWord, keyWord, next, flag);
                        //auto iter = find(wordList.begin(), wordList.end(), tempWord);   
                        nextqueue.insert(tempWord);
                        //wordList.erase(iter);
                    }
                }
            }
        }

        beginque = nextqueue;

        return findFlag;    
    }

   
    void createPaths(string beginWord, string endWord, vector<string> &path, vector<vector<string> > &paths, 
                     unordered_map<string, vector<string> > &next)
    {
        if(beginWord == endWord)
        {
            paths.push_back(path);
        }
        else 
        {
            for(auto it = next[beginWord].begin(); it != next[beginWord].end(); it++)
            {
                path.push_back(*it);
                createPaths(*it, endWord, path, paths, next);
                path.pop_back();
            }
        }
    }
};
