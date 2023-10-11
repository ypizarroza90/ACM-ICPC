#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'
const int MAXN = 100001;

struct node
{
	int cnt,prio;
	char key;
	node *l, *r;
	//bool rev;
};

typedef node* pnode;

pnode root;
node treap[MAXN];
vector<int> rnd;
int t_cnt;

int cnt(pnode t){
	return t ? t->cnt : 0;
}

void update(pnode t){
	if(t)
		t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

void push(pnode &t){
    if(t){
        update(t);
    }
}

void split(pnode t, pnode &l, pnode &r, int pos){
	if(!t)
		return void(l = r = NULL);
	push(t);
	if(pos <= cnt(t->l))
		split(t->l, l, t->l, pos), r = t;
	else
		split(t->r, t->r, r, pos - cnt(t->l)-1), l = t;

	update(t);
}

void merge(pnode &t, pnode l, pnode r){
	push(l); push(r);
	if(!l || !r)
		t = l ? l: r;
	else if(l->prio > r->prio)
		merge(l->r,l->r,r), t = l;
	else
		merge(r->l, l, r->l), t = r;

	update(t);
}

void insert(pnode &t, pnode it, int pos){
	if(!t)
		t = it;
	else if(it->prio > t->prio)
		split(t,it->l,it->r, pos), t=it;
	else if(pos <= cnt(t->l))
		insert(t->l, it, pos);
	else
		insert(t->r,it, pos-cnt(t->l)-1);

	update(t);
}

char k_th(pnode &t, int pos){
	push(t);
	if(pos < cnt(t->l))
		return k_th(t->l, pos);
	else if(pos > cnt(t->l))
		return k_th(t->r, pos - cnt(t->l)-1);
	return t->key;
}

void erase(pnode &t, char key){
	if(t->key == key)
		merge(t, t->l, t->r);
	else
		erase(key < t->key ? t->l : t->r, key);
}

void output(pnode t){
	if(!t) return;
	push(t);
	output(t->l);
	cout<<t->key<<' ';
	output(t->r);
}

void insert(int pos,char val){
	pnode it = &treap[t_cnt];
	it->key = val;
	it->prio = rnd[t_cnt];
	++t_cnt;
	insert(root, it,pos);
}

void push_from(pnode &t, int l, int r){
	pnode l1, r1;
	split(t, l1, r1, l);
	pnode l2, r2;
	split(r1, l2, r2, r-l+1);
	merge(l2,l2,l1);
	merge(t,l2, r2);
}

void push_back(pnode &t, int l, int r){
	pnode l1, r1;
	split(t, l1, r1, l);
	pnode l2, r2;
	split(r1, l2, r2, r-l+1);
	merge(l1,l1,r2);
	merge(t,l1, l2);
}

int N ,M ,op;
int value, pos, y;
string cad;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();
	 for (int i = 0; i < MAXN; i++)
        rnd.push_back(i);
    random_shuffle(rnd.begin(), rnd.end());
	cin>>cad;
    for(int i = 0; i < cad.size(); i++){
    	insert(i,cad[i]);
    }
    cin>>M;
    while(M--){
		cin>>op>>pos;
		switch(op){
			case 1:
				cin>>y;
				push_from(root, pos, y);
				break;
			case 2:
				cin>>y;
				push_back(root, pos, y);
				break;
			default:
				cout<<k_th(root,pos)<<endl;
				break;
		}
    }
	return 0;
}

