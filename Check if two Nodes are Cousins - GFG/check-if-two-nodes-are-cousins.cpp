//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

bool isCousins(Node*root , int x , int y);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        int x , y;
        scanf("%d ",&x);
		scanf("%d ",&y);
        if(x==y)
        {
            cout<<"0\n";
            continue;
        }
        cout <<isCousins(root,x,y)<< endl;
    }
    return 1;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false
void func(int i,Node*root,int x,int &ans){
    if(ans!=-1){
        return;
    }
    if(!root){
        return;
    }
    if(root->data==x){
        ans=i;
        return ;
    }
    func(i+1,root->left,x,ans);
    if(ans!=-1){
        return ;
    }
    func(i+1,root->right,x,ans);
    return ;
}
void parent_func(Node*root,map<int,int>&mp){
    if(!root)return;
    queue<Node*>q;
    mp[root->data]=0;
    q.push(root);
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        if(x->left){
            mp[x->left->data]=x->data;
            q.push(x->left);
        }
        if(x->right){
            mp[x->right->data]=x->data;
            q.push(x->right);
        }
    }
    return ;
}
bool isCousins(Node *root, int a, int b)
{
   //add code here.
   int l1=-1;
   int l2=-1;
   func(0,root,a,l1);
   func(0,root,b,l2);
   map<int,int>mp;
   parent_func(root,mp);
   if(l1==l2 && mp[a]!=mp[b]){
       return true;
   }
   return false;
}