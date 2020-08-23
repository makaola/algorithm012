学习笔记
Trie是以字母为单位的树，每个节点不会直接记录单词，而是记录一个字母以及是否是结尾。相对来说更加合理，每次查找的时候从root出发到逐个匹配字母。具体模板如下：
class Trie {
    struct TrieNode {
        map<char, TrieNode*>child_table;
        int end;
        TrieNode(): end(0) {}
    };
        
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->child_table.count(word[i]) == 0)
                curr->child_table[word[i]] = new TrieNode();
                
            curr = curr->child_table[word[i]];                
        }
        curr->end = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return find(word, 1);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix, 0);
    }
private:
    TrieNode* root;
    bool find(string s, int exact_match) {
        TrieNode *curr = root;
        for (int i = 0; i < s.size(); i++) {
            if (curr->child_table.count(s[i]) == 0)
                return false;
            else
                curr = curr->child_table[s[i]];
        }
        
        if (exact_match)
            return (curr->end) ? true : false;
        else
            return true;
    }
};
不但可以查询完整单词，还可以查找前缀，如果记录优先级的话还一定程度上可以做推理。

并查集
并查集的关键点在于parent和union，主要针对的问题类型就是将满足某一条件的归属到同一个类别里。

不重复、剪枝、双向BFS、启发式搜素（优先队列）。

AVL树和红黑树
AVL树是高度平衡的，左右子树高度差在1以内，会记录下来。相比于红黑树来说维护起来更加复杂，但是由此带来的就是查询相对较快。
红黑树是维护成本没有那么高，左右子树高度最多差2倍，插入和删除时相对维护成本低一些，比一般树还是平衡许多。不会退化为类似链表的形式。

