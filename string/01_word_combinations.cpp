#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Node
{
    Node *links[26];
    bool flag = false;

public:
    bool containskey(char ch)
    {
        return (this->links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        this->links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        this->flag = true;
    }
    bool isEnd()
    {
        return this->flag == true;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containskey(word[i]))
            {
                node->put(word[i], new Node());
            }
            // move to reference link
            node = node->get(word[i]);
        }
        node->setEnd();
    }
};

int M = 1e9 + 7;

vector<int> cache;
int mx_len = 0;

int fu(int idx, string &str, Trie &trie)
{
    int n = str.size();
    if (idx >= n)
        return 1;
    if (cache[idx] != -1)
        return cache[idx];
    string temp;
    int ans = 0;
    Node *node = trie.root;

    for (int i = idx; i < n; i++)
    {
        temp.push_back(str[i]);
        if (temp.size() > mx_len)
            break;

        if (node->containskey(str[i]))
        {
            node = node->get(str[i]);
            if (node->isEnd())
            {
                ans = (ans % M + fu(i + 1, str, trie) % M) % M;
            }
        }
        else
        {
            break;
        }
    }

    return cache[idx] = ans;
}

void solve()
{
    string str;
    cin >> str;
    int k;
    cin >> k;

    Trie trie;

    while (k--)
    {
        string x;
        cin >> x;
        trie.insert(x);
        mx_len = max(mx_len, (int)x.size());
    }
    cache.resize(str.size() + 1, -1);
    cout << fu(0, str, trie);
}

int main()
{
    solve();
    return 0;
}