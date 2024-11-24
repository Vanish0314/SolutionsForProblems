/*
 * @Author: Vanish
 * @Date: 2024-11-07 13:54:18
 * @LastEditTime: 2024-11-07 14:12:19
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Trie {
public:
    bool m_IsEnd;
    Trie* m_Next[26];
    string m_Word;

    Trie() {
        m_IsEnd = false;
        for (int i = 0; i < 26; i++) {
            m_Next[i] = nullptr;
        }
        m_Word = "";
    }

    void insert(string word)
    {
        
    }

    bool search(string word) {
        
    }
    
    bool startsWith(string prefix) {
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

