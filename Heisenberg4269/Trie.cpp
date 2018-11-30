class Trie
{
private:
    struct tnode
    {
        vector <tnode*> child;
        bool isword;
    };
    tnode *root;
    int vocabLength;

public:

    Trie(int vocab = 26)
    {
        vocabLength = vocab;
        root = makeTnode();
    }

    tnode* makeTnode()
    {
        tnode *newTnode = new tnode;
        newTnode->child.resize(vocabLength);
        for(int i = 0; i < vocabLength; i++)
        {
            newTnode->child[i] = NULL;
        }
        newTnode->isword = false;
        return newTnode;
    }

    void insert(string &str)
    {
        tnode *current = root;
        for(int i = 0; i < str.size(); i++)
        {
            int key = str[i] - 'a';
            if(!current->child[key])
            {
                current->child[key] = makeTnode();
            }
            current = current->child[key];
        }
        current->isword = current;
    }

    bool search(string &str)
    {
        tnode *current = root;
        for(int i = 0; i < str.size(); i++)
        {
            int key = str[i] - 'a';
            if(!current->child[key])
            {
                return false;
            }
            current = current->child[key];
        }
        return current->isword;
    }
};
