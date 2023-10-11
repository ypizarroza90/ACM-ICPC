#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int MAXN = 100000 + 10;

class LCT {
public:
	struct Node {
		static Node *null;
		Node *childrens[2], *father;
		int rev, val;
		Node(){
			childrens[0]=childrens[1]=father=NULL;
			rev = val = 0;
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
	}

	Node* access(Node *u) {
		Node *v = Node::null;
		for (; u != Node::null; u = u->father) {
			splay(u);
			u->childrens[1] = v;
			v = u;
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
	cin>>N>>Q;
	tree.init();
	for(int i=1;i<=N;i++){
		G[i] = tree.newNode();
	}
	while(Q--){
		cin>>op>>u;
		if(op == "link"){
			cin>>v;
			tree.link(G[u], G[v]);
		}
		else if(op == "lca"){
			cin>>v;
			node = tree.lca(G[u], G[v]);
			cout<<tree.label(node)<<endl;
		}else{
			tree.cut(G[u]);
		}
	}
	return 0;
}

