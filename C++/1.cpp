#include <bits/stdc++.h>
using namespace std;
//=============================MACROS=============================================
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)                        //for loop from 0 to n
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)   //for loop to itearte from k,n both forward and backward
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
//============================CONSTANTS===========================================
const int mod = 1000000007;
//const int mod = 1'000'000'007;
const int bign = 3e5, M = bign;
//=============================SOME FUNCTIONS TO PRINT============================

void print_vec_int(vector<ll int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
//=============================SOME BASIC THINGS==================================
struct Node{
    int data;
    struct Node* next;
    Node (int data){
        this->data =data;
        next=NULL;
    }
};

struct BTnode{
    int data;
    struct BTnode* left;
    struct BTnode* right;
    BTnode (int data){
        this->data =data;
        left=NULL;
        right=NULL;
    }
};
struct LinkedList{
    Node* head;
    LinkedList() {
        head=NULL;
    }

    Node* reverse(Node* head){
        
        if(head==NULL || head->next ==NULL){
            return head;
        }
        Node* rest=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return rest;

    }

    void print(){
        struct Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

    void push(int data){
        Node* temp=new Node(data);
        temp->next =head;
        head =temp;
    }
};

struct bintree{
    BTnode* root;
    bintree() {
        root=NULL;
    }

    BTnode* push(BTnode* root,int data){
        BTnode* temp= new BTnode(data);

        if(root==NULL){
            root=temp;
            return root;
        }
        
        stack<BTnode*> s;
        s.push(root);
        while(! s.empty()){
            BTnode* store =s.top();
            s.pop();
            if(store->left !=NULL){
                s.push(store->left);
            }
            else{
                store->left=temp;
                return root;
            }
            if(store->right !=NULL){
                s.push(store->right);
            }
            else{
                store->right =temp;
                return root;
            }
        }
        return root;

    }
    void pre(BTnode* root){
        if(root ==NULL)
        return;
        cout<<root->data<<" ";
        pre(root->left);
        pre(root->right);
    }

    void in(BTnode* root){
        if(root ==NULL)
        return;
        
        in(root->left);
        cout<<root->data<<" ";
        in(root->right);
    }

    void post (BTnode* root){
        if(root ==NULL)
        return;
        
        post(root->left);
        post(root->right);
        cout<<root->data<<" ";
    }
    vector<int> preorder(BTnode* root){
        vector<int> ans;
        if(root==NULL)
        return ans;
        stack<BTnode*> s;
        s.push(root);
        while(! s.empty()){
            BTnode* n=s.top();
            s.pop();
            ans.push_back(n->data);
            if(n->right !=NULL){
                s.push(n->right);
            }
            if(n->left !=NULL){
                s.push(n->left);
            }
        }
        return ans;
    }

    vector<int> inorder(BTnode* root){
        vector<int> ans;
        BTnode* node =root;
        stack<BTnode*> s;
        while( node!=NULL || ! s.empty()){
            while(node!=NULL){
                s.push(node);
                node=node->left;
            }
            
                node= s.top();
                s.pop();
                ans.pb(node->data);
                node=node->right;

            
        }
        return ans;
    }

    vector<int> postorder(BTnode* root){
        vector<int> ans;
        BTnode* node =root;
        stack<BTnode*> s;
        stack<BTnode*> t;
        s.push(node);
        while(!s.empty()){
            node=s.top();
            s.pop();
            t.push(node);
            if(node->left !=NULL){
                s.push(node->left);
            }
            if(node->right !=NULL){
                s.push(node->right);
            }
        }
        BTnode* n;
        while(!t.empty()){
            n=t.top();
            t.pop();
            ans.pb(n->data);
        }
        return ans;
    }
};
class graph{
public:
    long long int size;
    vector<long long int> *adj;
    vector<vector<long long int>> *adj2;
    graph(long long int v){
        
        this->size =v;
        adj =new vector<long long int>[size];
        adj2=new vector<vector<long long int>>[size];
    }
    void add_edge(long long int src,long long int dest,bool bidr=false){
        adj[src].push_back(dest);
        if(bidr){
            adj[dest].push_back(src);
        }

    }
    void add_edge_with_weights(long long int src,long long int dest,long long int weight,bool bidr=false){
        vector<long long int> temp={dest,weight};
        
        adj2[src].push_back(temp);
        if(bidr){
            vector<long long int> temp2={src,weight};
            adj2[dest].push_back(temp2);
        }
        //cout<<"done edge"<<endl;
    }

    void print_graph(){
        for(int i=0;i<size;i++){
            cout<<i<<" -> ";
            for(auto x:adj[i]){
                cout<<x<<" ";
            }
            cout<<"\n";
        }
    }

    void bfs_helper(queue<long long int> q,bool vis[], long long int src,vector<long long int>& traverse){
        q.push(src);
        vis[src]=true;
        while(!q.empty()){
            long long int curr=q.front();
            q.pop();
            traverse.push_back(curr);
            for(auto x:adj[curr]){
                if(!vis[x]){
                    vis[x]=true;
                    q.push(x);
                }
            }
            
        }
    }

    vector<long long int> bfs(long long int src){
        queue<long long int> q;
        vector<long long int> traverse;
        bool vis[size]={false};
        bfs_helper(q,vis,src,traverse);
        return traverse;
    }    

    void dfs_helper(stack<long long int> st,bool vis[],long long int src,vector<long long int> & traverse){
        st.push(src);
        vis[src]=true;
        while(!st.empty()){
            long long int curr=st.top();
            st.pop();
            traverse.push_back(curr);
            for(auto x:adj[curr]){
                if(!vis[x]){
                    vis[x]=true;
                    st.push(x);
                }
            }
        }
    }

    vector<long long int> dfs(long long int src){
        stack<long long int> st;
        vector<long long int> traverse;
        bool vis[size]={false};
        dfs_helper(st,vis,src,traverse);
        return traverse;
    }

    long long int select_min_for_prims (vector<long long int> value,vector<bool> set_mst){
        long long int min=INT_MAX,minind;
        long long int v=value.size();
        
        for(int i=0;i<v;i++){
            if(value[i]<min and set_mst[i]!=true){
                minind=i;
                min=value[i];
            }
        }
        return minind;
    }
    void find_mst_by_prims(int *parents){ 
        //taking input of graph with nodes stored as pairs of node number and weight
        long long int v=this->size;
        vector<long long int> value (v,INT_MAX);
        vector<bool> set_mst (v,false);
        parents[0]=-1;
        value[0]=0;
        for(int i=0;i<v-1;i++){
            long long int u= select_min_for_prims(value,set_mst);
            
            set_mst[u]=true;
            for(auto j:adj2[u]){
                long long int ver=j[0];
                long long int wt=j[1];
                if(set_mst[ver]==false and wt<=value[ver]){
                    value[ver]=wt;
                    parents[ver]=u;
                }
                 
            }
        }
    }

    long long int select_min_for_djk(vector<long long int> &dist,vector<bool> &visited){
        long long int min=INT_MAX,minind;
        long long int v=visited.size();
        for(int i=0;i<v;i++){
            if(dist[i]<min and visited[i]!=true){
                minind=i;
                min=dist[i];
            
            }
        }
        return minind;
    
    }
    // give inout a src and a vector of long long int, with distances of every node==infinte, and you will get the updated distances in result.

    void dijk (long long int src,vector<long long int> &dist)
    {
        long long int v=this->size;
        
        vector<bool> visited(v,false);
        vector<long long int> parent(v,-1);
        parent[src]=-1;
        dist[src]=0;

        for(int i=0;i<v-1;i++){
            long long int u=select_min_for_djk(dist,visited);
            
            visited[u]=true;
            for(auto j:this->adj2[u]){
                long long int ver =j[0];
                long long int wt=j[1];
                
                if(visited[ver]==false  and (dist[u]+wt <dist[ver])){
                    dist[ver]=dist[u]+wt;
                    parent[ver]=u;
                }
            }
        }
        
    }
//this is the helper function for applying bfs in tarzan scc search algo.
    void dfs_tarzan_scc(long long int &u,vector<long long int>&disc,vector<long long int>&low,stack<long long int> & my_stack,vector<bool> &instack,vector<vector<long long  int>> &ans){
        static long long int time=0;
        disc[u]=low[u]=time;
        time++;
        my_stack.push(u);
        instack[u]=true;

        for(auto v:adj[u]){
            if(disc[v]==-1){
                dfs_tarzan_scc(v,disc,low,my_stack,instack,ans);
                low[u]=min(low[u],low[v]);

            }
            else if(instack[v]==true){
                low[u]=min(low[u],disc[v]);

            }
            
        }
        if(low[u]==disc[u]){
                vector<long long int> temp;
                while(my_stack.top()!=u){
                    temp.push_back(my_stack.top());
                    instack[my_stack.top()]=false;
                    my_stack.pop();
                }
                temp.push_back(my_stack.top());
                instack[my_stack.top()]=false;
                my_stack.pop();
                
                ans.push_back(temp);

            }

    }
// this function req. a vector<vector<ll int>> to store scc in them, each vector<ll int> is an scc. 
    void scc_by_tarzan(vector<vector<long long  int>> &ans){
        long long int v=this->size;
        vector<long long int> disc(v,-1),low(v,-1);
        vector<bool> instack(v,false);
        stack<long long int> my_stack;
        for(long long int i=0;i<v;i++){
            if(disc[i]==-1)
                dfs_tarzan_scc(i,disc,low,my_stack,instack,ans);
        }
        
    }
//it is the helper function of tarzan for articulation point.
    void dfs_tarzan_ap(long long int &u,vector<long long int> &disc,vector<long long int> &low,vector<long long int>&parent,vector<bool> &ap,vector<long long int>&child_count){
        static long long int time=0;
        disc[u]=low[u]=time;
        time++;
        long long child=0;
        for(auto v:adj[u]){
            if(disc[v]==-1){
                child_count[u]++;
                parent[v]=u;
                dfs_tarzan_ap(v,disc,low,parent,ap,child_count);
                low[u]=min(low[u],low[v]);
                if(parent[u]==-1 and child_count[u]>1){
                    ap[u]=true;
                }
                if(parent[u]!=-1 and low[v]>=disc[u] )
                    ap[u]=true;
                

            }
            else if(v !=parent[u]){
                low[u]=min(low[u],disc[v]);
            }
        }
    }
// it is used to fill boolean vector of all the, vertex... by tarzan algo..
    void articulation_point_by_tarzan(vector<bool> &ap){
        long long int v=this->size;
        vector<long long int> disc(v,-1),low(v,-1),parent(v,-1),child_count(v,0);
        
        for(long long int i=0;i<v;i++){
            if(disc[i]==-1)
            dfs_tarzan_ap(i,disc,low,parent,ap,child_count);
        }
    }

 
// this cluster of programs is for finding scc's by kosaraju algo, just give it vector<vector<long long int>> ans to it, and it will render it

    void reverse_kosaraju(vector<long long int> *adj,vector<long long int> *rev){
        long long int v=this->size;
        for(long long int i=0;i<v;i++){
            for(long long int j:adj[i]){
                rev[j].push_back(i);
            }
        }
    }
    void dfs_1_kosaraju(long long int &i,vector<bool> &visited,stack<long long int> &my_stack){
        visited[i]=true;
        for(long long int j: adj[i]){
            if(visited[j]==false){
                dfs_1_kosaraju(j,visited,my_stack);
            }
        }
        my_stack.push(i);
    }
    void dfs_2_kosaraju (long long int &i,vector<bool> &visited,vector<long long int> *rev,vector<long long int> &temp){
        temp.push_back(i);
        visited[i]=true;
        for(long long int j:rev[i]){
            if(visited[j]==false)
                dfs_2_kosaraju(j,visited,rev,temp);
        }
    }
    void scc_by_kosaraju (vector<vector<long long int>> &ans){
        long long int v=this->size;
        vector<bool> visited(v,false);
        stack<long long int> my_stack;
        for(long long int i=0;i<v;i++){
            if(!visited[i]){
                dfs_1_kosaraju(i,visited,my_stack);
            }
        }
        vector<long long int> rev[v];
        reverse_kosaraju(adj,rev);
        for(long long int i=0;i<v;i++){
            visited[i]=false;
        }
        while(!my_stack.empty()){
            
            long long int curr=my_stack.top();
            
            my_stack.pop();
            if(visited[curr]==false){

                vector<long long int> temp;
                dfs_2_kosaraju(curr,visited,rev,temp);
                
                ans.push_back(temp);
            }
        }

    }
// this cluster is for toposorting just provide it empty vector<long long int> to it, and it will render it

    void dfs_for_toposort(long long int i,vector<bool> &vis,stack<long long int> &ans){
	    
	    for(long long int j=0;j<adj[i].size();j++){
	        if(!vis[adj[i][j]]){
	            vis[adj[i][j]]=true;
	            dfs_for_toposort(adj[i][j],vis,ans);
	            
	        }
	        else{
	            continue;
	        }
	    }
	    
	    ans.push(i);
	}
	
	void topoSort(vector<long long int> &ans ) {
	    
        long long int v=this->size;

	    stack<long long int> ans_st;
	    vector<bool> vis(v,false);
	    for(long long int i=0;i<v;i++){
	        if(!vis[i]){
	            vis[i]=true;
	            
	            dfs_for_toposort(i,vis,ans_st);
	            
	        }
	        
	    }
	    
	    while(!ans_st.empty()){
	        long long int curr=ans_st.top();
	        ans_st.pop();
	        ans.push_back(curr);
	    }
	}
// a function for applying bellman forde algo on graph, just give it an empty vector for storing parent of all vertexes, and an vector storing infintes indicating distances for every node from source, and a src, and a bool which will tell us that wether we have neg. cycles in graph or not

    void bellman(vector<long long int> &parent,vector<long long int> &cost_parent,long long int src,bool &isneg){
        long long int v=this->size;
        vector<long long int> value(v,INT_MAX);
        parent[src]=-1;
        value[src]=0;
        bool updated;
        for(long long int i=0;i<v-1;i++){
            for(int ii=0;ii<v;ii++){
                for(auto x:adj2[ii]){
                    long long u=ii;
                    long long v=x[0];
                    long long wt=x[1];
                    if(value[u]!=INT_MAX && value[u]+wt<value[v]){
                        value[v]=value[u]+wt;
                        parent[v]=u;
                        cost_parent[v]=value[v];
                        updated=true;
                    }
                }
            }
            if(!updated){
                break;
            }
        }
        for(int ii=0;ii<v;ii++){
            for(auto x:adj2[ii]){
                long long u=ii;
                long long v=x[0];
                long long wt=x[1];
                if(value[u]!=INT_MAX && value[u]+wt<value[v]){
                    isneg=true;
                    return;
                }
            }
        }
    }
// just give it an empty 2 dimensional vectors to store the distance of every pair, and a boolean which will tell us, is there any neg, edge weight cycles in this.
    void flloyd (vector<vector<long long int>> &dist,bool &isneg){
        long long int v= this->size;

        //initialising the distance matrix with int max, and doiagonals to be 0
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(i==j){
                    dist[i][j]=0;
                }
                else
                dist[i][j]=INT_MAX;
            }
        }
        // filling the distance matrix with the edge weights as given
        for(long long int i=0;i<v;i++){
            for(auto x:adj2[i]){
                long long int u=i;
                long long int v=x[0];
                long long int wt=x[1];
                dist[u][v]=wt;
            }
        }
        // the v^3 steps, whch will find the all pair shortest paths
        for(long long int k=0;k<v;k++){
            for(long long int i=0;i<v;i++){
                for(long long int j=0;j<v;j++){
                    if(dist[i][k] == INT_MAX || dist[k][j]==INT_MAX){
                        continue;
                    }
                    else if(dist[i][k]+dist[k][j]<dist[i][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        // checking for any neg. edge weights cycles
        isneg=false;
        for(long long int i=0;i<v;i++){
            if(dist[i][i]<0){
                isneg=true;
                return;
            }
        }
    }
// ths cluster of functions has two major fnctions for m coloring problems,
// first function (m_color_decision) will take input no. of colurs m,a colour array initialised with 0,and a long long int i, which tells us the current taregted node
//it will return us a boolean value, which will tell us, if the graph can be coloured using that much number of colours, or not.
//the second function (m_color_permutation) will take all the values as above, instead, it also takes a empty vector<vector<long long int>> ans, to store all permutation possible to colour graph using m given colours., it will render this ans matrix, and donot return anythinsg else

    bool isvalid_m_color(long long int &c,vector<long long int> &color,long long int &u){
        // cout<<"printing color \n";
        // for(int i=0;i<color.size();i++){
        //     cout<<color[i]<<endl;
        // }
        for(auto v:adj[u]){
            if(color[v]!=0 and color[v]==c){
                return false;
            }
        }
        return true;
    }

    bool m_color_decision(long long int &m,vector<long long int> &color,long long int &i){
        long long int v=this->size;
        if(i==v)
            return true;
        for(long long int c=1;c<=m;c++){
            if(isvalid_m_color(c,color,i)){
                color[i]=c;
                long long int temp=i+1;
                if(m_color_decision(m,color,temp)){
                    return true;
                }
                color[i]=0;
            }
        }
        return false;
    }

    void m_color_permutation(long long int &m,vector<long long int> &color,long long int &i,vector<vector<long long int>> &ans){
        long long int v=this->size;
        if(i==v){
            ans.push_back(color);
            return;
        }
        for(long long int c=1;c<=m;c++){
            if(isvalid_m_color(c,color,i)){
                color[i]=c;
                long long int temp=i+1;
                m_color_permutation(m,color,temp,ans);
                color[i]=0;
            }
        }
    }

//it is simply checking if, a graph can be colured with 2 colours, if yes, then we can say it is bipartite, it will return a boolean value

    bool is_bipartite(){
        long long int v=this->size;
        vector<long long int> color(v,0);
        long long int m=2,i=0;
        return m_color_decision(m,color,i);
    }

    void dfs_tarzan_bridges(long long int u,vector<long long int> &disc,vector<long long int>&low,vector<long long int>&parent,vector<vector<long long int>> &bridges){
        static int timer=0;
        low[u]=disc[u]=timer;
        timer++;
        for(auto v:adj[u]){
            if(disc[v]==-1){
                parent[v]=u;
                dfs_tarzan_bridges(v,disc,low,parent,bridges);
                low[u]=min(low[u],low[v]);
                if(low[v]>disc[u]){
                    vector<long long int> temp;
                    temp.push_back(u);
                    temp.push_back(v);
                    bridges.push_back(temp);
                }
            }
            else if(v!=parent[u]){
                low[u]=min(low[u],disc[v]);
            }
        }
    }
    void bridges_by_tarzan(vector<vector<long long int>> &bridges){
        long long int v=this->size;
        vector<long long int> disc(v,-1),low(v,-1),parent(v,-1);
        for(long long int i=0;i<v;i++){
            if(disc[i]==-1){
                dfs_tarzan_bridges(i,disc,low,parent,bridges);
            }
        }
    }

};

//=============================FUNCTIONS INITIALISATION===========================
int check_prime(int n);
int mpow(int base, int exp); 
int rev(int n);
int max_sum_of_subarray(int arr[],int len);
int times_appear(vector<int> arr,int x);
pair<int,int> is_exists(vi arr,int x);
bool has_subarray_with_sum_k(vi v,int k);
pair <vi,int> partitioned(vi v, int k);
vector<vector<int>> transpose(vector<vector<int>> v);
int larget_rectangle_in_histogram (vi h);
bool is_palindrome(string s);
vector<ll int> rabin_karp(string txt,string pat); 
ll int modInverse(ll int a,ll int m);
ll int ncr(ll int n,ll int r);
vi prime_factors(int n);
vector<ll int>  printDivisors(ll int n);
//=============================SOLVE FUNCTION=====================================

//=============================SOLVE FUNCTION=====================================
//vector<ll int > ans;
//ll int dp[100005]={0};
//ll int dp2[100005]={0};
ll int ve[1000][1000];
void generatePrintBinary(ll int n,vector<string> &ret)
{
	// Create an empty queue of strings

	queue<string> q;

	// Enqueue the first binary number
	q.push("1");

	// This loops is like BFS of a tree with 1 as root
	// 0 as left child and 1 as right child and so on
	while (n--) {
		// print the front of queue
		string s1 = q.front();
		q.pop();
		ret.push_back(s1);

		string s2 = s1; // Store s1 before changing it

		// Append "0" to s1 and enqueue it
		q.push(s1.append("0"));

		// Append "1" to s2 and enqueue it. Note that s2
		// contains the previous front
		q.push(s2.append("1"));
	}
}



void printTheArray(int arr[], int n,vector<vector<int>> &ans){   vector<int> temp;
    for (int i = 0; i < n; i++) {
        temp.pb(arr[i]);
    }
    ans.pb(temp);
}
// used to get all binary string of length n

void generateAllBinaryStrings(int n, int arr[], int i,vector<vector<int>>&ans){
    if (i == n) {
        printTheArray(arr, n,ans);
        return;
    }
  
    // First assign "0" at ith position
    // and try for all other permutations
    // for remaining positions
    arr[i] = 0;
    generateAllBinaryStrings(n, arr, i + 1,ans);
  
    // And then assign "1" at ith position
    // and try for all other permutations
    // for remaining positions
    arr[i] = 1;
    generateAllBinaryStrings(n, arr, i + 1,ans);
}

void solve(int TN){
    string arr,arrt,arr1,arr1t,arr2,arr2t;
    char ch;
    ll int summ=0,temp=0,temp2=0;
    
    cout<<" hello "<<TN<<endl;
    
     
    
    

}

//==============================MAIN FUNCTION======================================

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
    #endif*/
    int t=1;
    cin>>t;
    int i=0;
    while(i<t){
    solve(i);
    i++;
    }
    return 0;
}
//===============================FUNCTIONS==========================================


//1.to check wether a no. is prime or not in O(sqrt(n))
int check_prime(int n){
    for (int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;

}
//2.a function to get (a^b)%MOD in O(logn) time
int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
//3. to reverse an integer in order of its length time
int rev(int n){
    int ans=0;
    while(n>0){
        ans*=10;
        ans+=(n%10);
        n/=10;
    }
    return ans;
}

//4. to get the sum of subarray with maximum sum in O(n) time
int max_sum_of_subarray(int arr[],int len){
    int best=0,sum=0,k;
    for(k=0;k< len ;k++){
        sum= max(arr[k],sum+arr[k]);
        best =max(best,sum);

    }
    return best;
}

//5. to count no. of apperance of element in an sorted array
int times_appear(vector<int> arr,int x){
    auto r=equal_range(arr.begin(),arr.end(),x);
    return(r.second-r.first);
}

//6. to check, if an element exist in an sorted array or not
// it return a pair of bool(int) and int
pair<int,int> is_exists(vi arr,int x){
    auto k =lower_bound(arr.begin(),arr.end(),x)-arr.begin();
    if(k<(arr.size()) && arr[k]==x){
        return (mp(1,k));
    }
    else{
        return(mp(0,0));
    }

}

//7. to check wether an array has a subarray with sum equals to k
//in O(n)

bool has_subarray_with_sum_k(vi v,int k){
    int sum=0,i;
    set<int>s;
    bool found=false;
    fo(i,v.size()){
        s.insert(sum);
        sum+=v[i];
        if(s.find(sum-k) !=s.end()){
        found=true;
        break;
        }
    }
    return found;
}

//8. to return an array /vector after applyiing partition algo.
//with pivot as k.....it also return the pivot position.
//will return the last index of element less pivot (-1,-3,-6,8,9,45,67)  ..pivot =0.....
//it will give 2,as last index ofneg element is 2.

pair <vi,int> partitioned(vi v, int k){
    int i,p=-1;
    
    fo(i,v.size()){
        if(v[i]<k){
            p++;
            swap(v[p],v[i]);

        }
        else{
            continue;
        }
    }
    return (mp(v,p));

}

//9. to return transpose of a matrix
//it return a 2-D vecor 

vector<vector<int>> transpose(vector<vector<int>> v){
    vector<vector<int>> ans;
    for(int i=0;i<v[0].size();i++){
        vector<int> temp;
        for(int j=0;j<v.size();j++){
            temp.pb(v[j][i]);
        }
        ans.push_back(temp);
    }
    return ans;
}

//10. to return the maximum area rectangle in an array of given heights.
// it has time complexity of O(n)

int larget_rectangle_in_histogram (vi h){
    int i,n=h.size();
    vi left(n),right(n);
    stack<int> st;
    fo(i,n){
        if(st.empty()){
            left[i]=0;
            st.push(i);
        }
        else{
            while(! st.empty()  && h[st.top()]>=h[i])
                st.pop();
            left[i]=st.empty() ?0 :st.top()+1;
            st.push(i);

        }
    }

    while(! st.empty())
        st.pop();
    
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            right[i]=n-1;
            st.push(i);
        }
        else{
            while(!st.empty() && h[st.top()]>=h[i])
                st.pop();
            right[i]=st.empty() ?n-1:st.top()-1;
            st.push(i);
        }
    }
    int maxarea=0;
    for(int i=0;i<n;++i){
        maxarea =max(maxarea,h[i]*(right[i]-left[i]+1));
    
    }
    return maxarea;
}

//11. to check wether a string is palindrome or not, in O(n) time

bool is_palindrome(string s){
    bool flag=true;
    int start=0;
    int last=s.size()-1;
    while(start<last){
        if(s[start]!=s[last]){
            flag=false;
            break;
        }
        start++;
        last--;
    }
    return flag;
}

//12. rabin karp algo
//it return a vector of long long int,which has indices, from which our search pattern is starting.
//entered string can have spaces too, there is no issue in it.
vector<ll int> rabin_karp(string txt,string pat){

    ll int d=256;
    vector<ll int> v;
    ll int q=1000000007;
    ll int M = pat.size();  
    ll int N = txt.size();  
    ll int i, j;  
    ll int p = 0; // hash value for pattern  
    ll int t = 0; // hash value for txt  
    ll int h = 1;  
  
    // The value of h would be "pow(d, M-1)%q"  
    for (i = 0; i < M - 1; i++)  
        h = (h * d) % q;  
  
    // Calculate the hash value of pattern and first  
    // window of text  
    for (i = 0; i < M; i++)  
    {  
        p = (d * p + pat[i]) % q;  
        t = (d * t + txt[i]) % q;  
    }  
    
    // Slide the pattern over text one by one  
    for (i = 0; i <= N - M; i++)  
    {  
  
        // Check the hash values of current window of text  
        // and pattern. If the hash values match then only  
        // check for characters on by one  
        if ( p == t )  
        {  
            /* Check for characters one by one */
            for (j = 0; j < M; j++)  
            {  
                if (txt[i+j] != pat[j]) { 
                    
                    break;  
                }
            }  
  
            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]  
            if (j == M)  
            v.pb(i);
        }  
  
        // Calculate hash value for next window of text: Remove  
        // leading digit, add trailing digit  
        if ( i < N-M )  
        {  
            t = (d*(t - txt[i]*h) + txt[i+M])%q;  
  
            // We might get negative value of t, converting it  
            // to positive  
            if (t < 0)  
            t = (t + q);  
            
        }  
    }
    return v;  
}  

//13. fuction to find the mod inverse of a number
// it return the ll int 

ll int modInverse(ll int a,ll int m) 
{ 
	ll int m0 = m; 
	ll int y = 0, x = 1; 

	if (m == 1) 
		return 0; 

	while (a > 1) { 
		// q is quotient 
		ll int q = a / m; 
		ll int t = m; 

		// m is remainder now, process same as 
		// Euclid's algo 
		m = a % m, a = t; 
		t = y; 

		// Update y and x 
		y = x - q * y; 
		x = t; 
	} 

	// Make x positive 
	if (x < 0) 
		x += m0; 

	return x; 
} 

//14. the function to find ncr 
// it return the ll int
ll int ncr(ll int n,ll int r)
{

	// p holds the value of n*(n-1)*(n-2)...,
	// k holds the value of r*(r-1)...
	long long int p = 1, k = 1;

	// C(n, r) == C(n, n-r),
	// choosing the smaller value
	if (n - r < r)
		r = n - r;

	if (r != 0) {
		while (r) {
			p *= n;
			k *= r;

			// gcd of p, k
			long long int m = __gcd(p, k);

			// dividing by gcd, to simplify
			// product division by their gcd 
			// saves from the overflow
			p /= m;
			k /= m;

			n--;
			r--;
		}

		// k should be simplified to 1
		// as C(n, r) is a natural number
		// (denominator should be 1 ) .
	}

	else
		p = 1;

	// if our approach is correct p = ans and k =1
	return p;
}


//15. function to return the prime factors of a number
// it gives us the vector of integers

vi prime_factors(int n) 
{   vi v;
    bool flag=false;

	// Print the number of 2s that divide n 
	while (n % 2 == 0) 
	{ 
        flag=true;
		n = n/2; 
	} 
    if(flag)
v.pb(2);
	// n must be odd at this point. So we can skip 
	// one element (Note i = i +2) 
	for (int i = 3; i <= sqrt(n); i = i + 2) 
	{ 
		// While i divides n, print i and divide n 
		while (n % i == 0) 
		{ 
			v.pb(i);
			n = n/i; 
		} 
	} 

	// This condition is to handle the case when n 
	// is a prime number greater than 2 
	if (n > 2) 
		v.pb(n);

    return v;
} 


//16. the function to give all the divisors of a number n in O(n^(0.5)) 
// it return the vector of long long integer, with each entry denoting the divisor

vector<ll int>  printDivisors(ll int n)
{   vector<ll int> toreturn;
    // Note that this loop runs till square root
    for (ll int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                toreturn.pb(i);
 
            else // Otherwise print both
                toreturn.pb(i);
                toreturn.pb(n/i);
        }
    }
    return toreturn;
}

    