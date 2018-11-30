class Trie
{
public:
    struct tnode
    {
        vector <tnode*> child;
        bool isword;
    };
    tnode *root;
    int vocabLength;

    Trie(int vocab = 26)
    {
        vocabLength = vocab;
        root = makeTnode();
    }

    tnode* makeTnode()
    {
        tnode *newTnode = new tnode;
        newTnode->child.resize(vocabLength);
        for(int i = 0; i<vocabLength; i++)
        {
            newTnode->child[i] = NULL;
        }
        newTnode->isword = false;
        return newTnode;
    }

    void insert(string str)
    {
        tnode *temp = root;
        for(int i = 0; i<str.size(); i++)
        {
            int key = str[i] - 'a';
            if(temp->child[key] == NULL)
            {
                temp->child[key] = makeTnode();
            }
            temp = temp->child[key];
        }
        temp->isword = true;
    }

    bool search(string str)
    {
        tnode *temp = root;
        for(int i = 0; i<str.size(); i++)
        {
            int key = str[i] - 'a';
            if(temp->child[key] == NULL)
            {
                return false;
            }
            temp = temp->child[key];
        }
        return temp->isword;
    }
};
