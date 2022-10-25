#include<iostream>
using namespace std;

class TrieNode
{
    public:
    TrieNode* children [26];
    bool isTerminal;
    TrieNode(char ch)
    {
        char data=ch;
        for(int i=0;i<26;++i)
        {
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie
{
    public:
    TrieNode* root;

    Trie()
    {
        root =new TrieNode('\0');
    }
    
    //insertion
    void insert(TrieNode* root,string word)
    {
        //base case
        if(word.size()==0)
        {
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        insert(child,word.substr(1));
    }
    

    void insertWord(string word)
    {
        insert(root,word);
    }
    
//searching
    bool search(TrieNode* root,string word)
    {
        if(word.size()==0)
        {
            return root->isTerminal;
        }
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else{
            return false;
        }
        
        return search(child,word.substr(1));
    }
     

     bool searchWord(string word)
    {
        return search(root,word);
    }
   

    bool ispref(TrieNode* root,string word)
    {
         if(word.size()==0)
        {
            return true;
        }
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else{
            return false;
        }
        
        return ispref(child,word.substr(1));
    }
    bool pref(string word)
    {
       return ispref(root,word);
    }



    //for deleting 
    void del(TrieNode* root,string word)
    {
        if(word.size()==0)
        {
            root->isTerminal=false;
            return ;
        }
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else{
            return ;
        }
        
        return del(child,word.substr(1));
    }
    bool delet(string word)
    {
        del(root,word);
    }
};

int main()
{
   Trie *t=new Trie();
   t->insertWord("abcd");
   t->insertWord("deepak");
   t->insertWord("rahul");
   t->insertWord("pooja");
   t->insertWord("puja");
   t->insertWord("rohit");
   t->insertWord("lovely");
   t->insertWord("muskan");
   t->insertWord("musk");
   t->insertWord("das");
   t->insertWord("monkey");
   t->insertWord("radio");
   t->insertWord("apple");
   t->insertWord("ball");
   t->insertWord("physics");
   t->insertWord("math");
   t->insertWord("chemistry");
   t->insertWord("biology");
   t->insertWord("geography");
   t->insertWord("history");
   t->insertWord("hindi");
   t->insertWord("english");
   t->insertWord("bangali");
   t->insertWord("telugu");
   t->insertWord("tamil");
int x=4;
while(x)
{
    
   
   cout<<"for search word press 1 "<<endl;
   cout<<"for checking prefix press 2 "<<endl;
   cout<<"for delete any word press 3 "<<endl;
   cout<<"for terminate press 0 "<<endl;
   cin>>x;
   if(x==0)break;
   string word;
   cout<<"enter the word = ";
   cin>>word;
   bool f;
   switch(x)
   {
    case 1:
            cout<<word<<" present hai ya nahi = ";
            cout<<t->searchWord(word)<<endl<<endl<<endl;
            break;
    case 2:
            cout<<word<<" prefix ka word hai ki nahi = ";
            cout<<t->pref(word)<<endl<<endl<<endl; 
            break;
    case 3:
            
            if(t->searchWord(word))
            {
               t->delet(word);
               cout<<word<<" deleted !!!"<<endl<<endl<<endl; 
            }
            else 
            cout<<word<<" not persent !!!"<<endl<<endl<<endl;  
            break;
            
    default:
    cout<<"INVALID KEY"<<endl<<endl<<endl;
   }
}
   return 0;
}