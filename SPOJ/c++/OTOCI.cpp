#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int MAXN = 30000 + 10;

class LCT {
public:
	struct Node {
		static Node *null;
		Node *childrens[2], *father;
		int rev, val, sum;
		Node(){
			childrens[0]=childrens[1]=father=NULL;
			rev = val = sum = 0;
		}

		bool isRoot(){
			return father->childrens[0] != this  && father->childrens[1] != this;
		}

		void pushdown(){
			if(rev) {
				childrens[0]->rev^=1, childrens[1]->rev^=1;
				swap(childrens[0], childrens[1]);
				rev ^=1;
			}
		}

		void pushup() {
			if (this == null)	return ;
			sum = this->val;
			if (childrens[0] != null) {
				sum = sum + childrens[0]->sum;
			}
			if (childrens[1] != null) {
				sum = sum + childrens[1]->sum;
			}
		}


	}_mem[MAXN];

	int index;

	LCT(){
		Node::null = &_mem[0];
		Node::null->father= Node::null;
		Node::null->childrens[0] = Node::null->childrens[1]= Node::null;
		index = 1;
	}

	void init(){
		index = 1;
	}

	Node* newNode(){
		Node *u = &_mem[index++];
		*u = Node();
		u->father = u->childrens[0] = u->childrens[1] = Node::null;
		return u;
	}

	void rotate(Node* x){
		Node *y;
		y = x->father;
		int dir = y->childrens[1] == x ? 1 : 0;
		x->childrens[dir^1]->father = y, y->childrens[dir] = x->childrens[dir^1];
		x->childrens[dir^1] = y;
		if(!y->isRoot())
			y->father->childrens[y->father->childrens[1] == y] = x;
		x->father = y->father, y->father = x;
		y->pushup(); x->pushup();
	}

	void propagate(Node *x){
		if(!x->isRoot()) propagate(x->father);
		x->pushdown();
	}

	void splay(Node *x){
		Node *y, *z;
		propagate(x);
		while(!x->isRoot()){
			y = x->father, z = y->father;
			if(!y->isRoot()){
				if((y->childrens[0] == x) != (z->childrens[0] == y))
					rotate(x);
				else{
					rotate(y);
				}
			}
			rotate(x);
		}
		x->pushup();
	}

	Node* access(Node *u) {
		Node *v = Node::null;
		for (; u != Node::null; u = u->father) {
			splay(u);
			u->childrens[1] = v;
			v = u;
			v->pushup();
		}
		return v;
	}

	void mk_root(Node *u) {
		access(u)->rev ^= 1, splay(u);
	}

	void link(Node *x, Node *y) {
		mk_root(x);
		x->father = y;
	}

	Node* find(Node *x) {
		for (x = access(x); x->pushdown(), x->childrens[0] != Node::null; x = x->childrens[0]);
		return x;
	}

	void cut(Node *x){
		Node *v, *rt = find(x);
		mk_root(rt);
		access(x), splay(x);
		for (v = x->childrens[0]; v->childrens[1] != Node::null; v = v->childrens[1]);
		x->childrens[0]->father = x->father;
		x->father = x->childrens[0] = Node::null;
	}

	void cut(Node *x, Node *y) {
		mk_root(x);
		access(y), splay(y);
		y->childrens[0] = x->father = Node::null;
	}

	Node* lca(Node *x, Node *y){
		Node *u, *v =Node::null, *lca = Node::null;
		access(y), splay(y);
		for(u=x; u!=Node::null; u=u->father){
			splay(u);
			if(u->father == Node::null){
				lca = u;
			}
			u->childrens[1] = v;
			v = u;
		}

		return lca;
	}

	int sumOnPath(Node *x, Node *y) {
		if(conected(x,y)){
			mk_root(x);
			access(y), splay(y);
			return y->sum;
		}else{
			return -1;
		}
	}
	//
	void updateNode(Node *x, int c) {
		mk_root(x);
		x->val = c;
	}

	bool conected(Node* u, Node*v){
		return find(u) == find(v);
	}

	inline int label(Node *x) {
		return x - _mem;
	}

} tree;

LCT::Node *LCT::Node::null;
LCT::Node *G[MAXN], *node;
int u, v, Q,N;
string op;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	tree.init();
	for(int i=1;i<=N;i++){
		cin>>u;
		G[i] = tree.newNode();
		G[i]->val = u;
	}
	cin>>Q;
	while(Q--){
		cin>>op>>u>>v;
		if(op == "bridge"){
			if(!tree.conected(G[u], G[v])){
				tree.link(G[u], G[v]);
				cout<<"yes"<<endl;
			}else{
				cout<<"no"<<endl;
			}
		}
		else if(op == "excursion"){
			int sum = tree.sumOnPath(G[u], G[v]);
			if(sum == -1)
				cout<<"impossible"<<endl;
			else
				cout<<sum<<endl;
		}else{
			tree.updateNode(G[u], v);
		}
	}
	return 0;
}

