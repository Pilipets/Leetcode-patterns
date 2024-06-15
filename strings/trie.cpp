// Trie data structure
//
// https://en.wikipedia.org/wiki/Trie
// https://leetcode.com/problems/implement-trie-prefix-tree/
//
// Complexity:
// - Seach O(n) time, O(1) space
// - Build O(n * m) time/space


class Trie
{
    struct TrieNode
    {
        bool is_word = false;
        array<TrieNode*, 26> child = {nullptr};
    };

    TrieNode* find(const string &word)
    {
        TrieNode* cur = root;
        for(char ch: word){
            if(cur->child[ch - 'a'] == nullptr)
                return nullptr;

            cur = cur->child[ch-'a'];            
        }

        return cur;
    }

    void free(TrieNode* cur)
    {
        for (TrieNode* node : cur->child)
            if (node)
                free(node);
        delete cur;
    }

public:
    /** Initialize your data structure here. */
    Trie() { root = new TrieNode(); }
    ~Trie()
    {
        free(root);
        root = nullptr;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode* cur = root;
        for(char ch: word){
            if(!cur->child[ch-'a'])
                cur->child[ch-'a'] = new TrieNode();
            cur = cur->child[ch-'a'];            
        }
        cur->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode* cur = find(word);
        return cur && cur->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode* cur = find(prefix);
        return cur;
    }

private:
    TrieNode* root;
};


// Build Trie
// note: using a class is only necessary if you want to store data at each node.
// otherwise, you can implement a trie using only hash maps.
//
struct TrieNode {
    int data;
    unordered_map<char, TrieNode*> children;
    TrieNode() : data(0), children(unordered_map<char, TrieNode*>()) {}
};

TrieNode* buildTrie(vector<string> words) {
    TrieNode* root = new TrieNode();
    for (string word: words) {
        TrieNode* curr = root;
        for (char c: word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        // at this point, you have a full word at curr
        // you can perform more logic here to give curr an attribute if you want
    }

    return root;
}