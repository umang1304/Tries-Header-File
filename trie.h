#include<iostream>
#include<string>
using namespace std;
class trienode
{
    char data;
    public:
    trienode** children;
    bool isterminal;

    trienode(char data)
    {
        this->data= data;
        children= new trienode*[26];
        for(int i=0; i<26; i++)
        {
            children[i]= NULL;
        }
        isterminal= false;
    }
};

class trie
{
    trienode* root;
    public:

    trie()
    {
        root= new trienode('\0');
    }

    void insertwordhelper(trienode* root, string word)
    {
        if(word.size()==0)
        {
            root->isterminal=true;
            return;
        }
        int index= word[0]-'a';
        trienode* child;
        if(root->children[index]!= NULL)
        {
            child= root->children[index];
        }
        else
        {
            child= new trienode(word[0]);
            root->children[index]= child;
        }
        insertwordhelper(child, word.substr(1));
    }

    void insertword(string word)
    {
        insertwordhelper(root, word);
    }


    bool searchwordhelper(trienode* root, string word)
    {
        if(word.size()==0)
        {
            if(root->isterminal==true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        int index= word[0]-'a';
        trienode* child;
        if(root->children[index]!= NULL)
        {
            child= root->children[index];
        }
        else
        {
            return false;
        }
       return searchwordhelper(child, word.substr(1));
    }

    bool searchword(string word)
    {
        return searchwordhelper(root, word);
    }


    void removewordhelper(trienode* root, string word)
    {
        if(word.size()==0)
        {
            root->isterminal=false;
            return;
        }
        int index= word[0]-'a';
        trienode* child;
        if(root->children[index]!= NULL)
        {
            child= root->children[index];
        }
        else
        {
            return;
        }
        removewordhelper(child, word.substr(1));

        if(child->isterminal== false)
        {
            for(int i=0;i<26; i++)
            {
                if(child->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index]= NULL;
        }
        else
        {
            return;
        }
    }

    void removeword(string word)
    {
        removewordhelper(root, word);
    }
};

