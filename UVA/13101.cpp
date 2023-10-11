#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int MAXN = 50000 + 10;

class LCT {
public:
	struct Node {
		static Node *null;
		Node *childrens[2], *father;
		int rev, val, gcd;
		Node(){
			childrens[0]=childrens[1]=father=NULL;
			rev = val = 0;
			gcd = 1;
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

		void pushup(){
			if(this == null) return;
			gcd = this->val;
			if(childrens[0] != null){
				gcd = __gcd(gcd, childrens[0]->gcd);
			}

			if(childrens[1] != null){
				gcd = __gcd(gcd, childrens[1]->gcd);
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

	int gcdOnPath(Node *x, Node *y) {
		mk_root(x);
		access(y), splay(y);
		return y->gcd;
	}
	void updateNode(Node *x, int c) {
		mk_root(x);
		x->val = c;
	}
} tree;

LCT::Node *LCT::Node::null;
LCT::Node *G[MAXN<<1];
int W[MAXN];
int u, v, op,Q,N;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>N){
		for(int i=0;i<N;i++){
			cin>>W[i];
		}

		tree.init();
		for(int i=0;i<N;i++){
			G[i] = tree.newNode();
			G[i]->val = W[i];
		}
		for(int i=1;i<N;i++){
			cin>>u>>v;
			tree.link(G[u], G[v]);
		}
		cin>>Q;
		while(Q--){
			cin>>op>>u>>v;
			if(op==1){
				cout<<tree.gcdOnPath(G[u], G[v])<<endl;
			}else{
				tree.updateNode(G[u], v);
			}
		}
	}
	return 0;
}

