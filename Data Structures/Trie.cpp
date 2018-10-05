/*
Author: Sagar Gupta
E mail: sagar.june97p@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;

class Trie
{
    bool is_word;
    map<char, Trie> dict;

  public:
    Trie(void)
    {
        is_word = false;
    }
    void AddWord(string s)
    {
        if (s.size() == 0)
        {
            is_word = true;
        }
        else
        {
            if (dict.find(s[0]) == dict.end())
            {
                dict[s[0]] = Trie();
            }
            dict[s[0]].AddWord(s.substr(1));
        }
    }
    bool FindWord(string s)
    {
        if (s.size() == 0 && is_word == true)
        {
            return true;
        }
        else if (dict.find(s[0]) == dict.end())
        {
            return false;
        }
        else
        {
            return dict[s[0]].FindWord(s.substr(1));
        }
    }
    void PrintAll(string s = "")
    {
        if (is_word == true)
            cout << s << endl;
        for (auto it : dict)
        {
            it.second.PrintAll(s + it.first);
        }
    }
};
int main()
{
    Trie t;
    t.AddWord("sagar");
    t.AddWord("saga");
    t.AddWord("hola");
    cout << t.FindWord("sagar");
    cout << t.FindWord("saga");
    cout << t.FindWord("sag");
    cout << t.FindWord("hola");
    cout << endl;
    t.PrintAll();
    return 0;
}