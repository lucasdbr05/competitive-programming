class Trie {
    struct Trienode{
        char val;
        int count;
        int endsHere;
        Trienode *child[26];
    };

    Trienode *root;
    Trienode *getNode(int index){
        Trienode *newnode = new Trienode;
        newnode->val='a'-index;
        newnode->count = newnode->endsHere=0;
        for (int i=0; i<26; i++){
            newnode->child[i]=NULL;
        }
        return newnode;
    }

public:
    Trie() {
        ios::sync_with_stdio(false);cin.tie(NULL);
        root = getNode('/'-'a');
    }
    
    void insert(string word) {
        Trienode *curr = root;
        int index;
        for(int i=0;word[i]!='\0'; ++i){
            index = word[i]-'a';
            if(curr->child[index]==NULL){
                curr->child[index]= getNode(index);
            }
            curr->child[index]->count+= 1;
            curr= curr->child[index];
        }
        curr->endsHere+=1;
    }
    
    bool search(string word) {
        Trienode *curr = root;
        int index;
        for(int i=0;word[i]!='\0'; ++i){
            index = word[i]-'a';
            if(curr->child[index]==NULL){
                return false;
            }
            curr= curr->child[index];
        }
        return curr->endsHere > 0;
    }
    
    bool startsWith(string prefix) {
        Trienode *curr = root;
        int index;
        for(int i=0; prefix[i]!='\0'; ++i){
            index = prefix[i]-'a';
            if(curr->child[index]==NULL){
                return false;
            }
            curr= curr->child[index];
        }
        return( curr->count > 0);
    }
};