//This is a generic implementation of the segment tree without lazy propagation
//This solves range sum query with updates
//For other problems the implementation of the util class should be changed accordingly.

#include <iostream>

struct sTreeNode{
	int x;
};

typedef struct sTreeNode snode;

class util{
public:
	//This is the return value if the range is out of bounds
	snode outValue;

	util(){
		outValue.x = 0;
	}
	snode getLeaf(int a){
		snode ans;
		ans.x = a;
		return ans;
	}
	snode combine(const snode &a,const snode &b){
		snode ans;
		ans.x = a.x+b.x;
		return ans;
	}
	snode getVal(const snode &a){
		snode ans;
		ans.x = a.x;
		return ans;
	}
};

//IMPORTANT:: Assumes array is 1 indexed.
class segtree{
public:
	int SIZE;
	snode *seg;
	util u;
	//constructor
	segtree(int size):
	SIZE(size)
	{
		seg = new snode[4*size+1];
		for(int i = 0 ; i <= 4*size ; i++)
			seg[i].x = 0;
	}

	//function to build the tree
	void build(int arr[],  int L , int R , int node = 1)
	{
		if(L==R)
		{
			seg[node]=u.getLeaf(arr[L]);
			return;
		}
		int M=(L+R)/2;
		build(arr, L, M, node*2);
		build(arr, M+1, R, node*2+1);
		seg[node]=u.combine(seg[node*2], seg[node*2+1]);
	}

	//function to query the tree
	snode query(int i, int j, int L , int R , int node = 1)
	{
		if(j<L || i>R)
			return u.outValue;
		if(i<=L && R<=j)
			return u.getVal(seg[node]);
		int M=(L+R)/2;
		snode left=query(i, j, L, M, node*2);
		snode right=query(i, j, M+1, R, node*2 + 1);
		return u.combine(left, right);
	}

	//function to update the segment tree
	void update(int pos, int val, int L , int R , int node = 1)
	{
		if(L==R)
		{
			seg[node]=u.getLeaf(val);
			return;
		}
		int M=(L+R)/2;
		if(pos<=M)
			update(pos, val, L, M, node*2);
		else
			update(pos, val, M+1, R, node*2 + 1);
		seg[node]=u.combine(seg[node*2], seg[node*2 + 1]);
	}

	//getter to get size
	int getSize () const{
		return SIZE;
	}

	//destructor
	~segtree(){
		delete [] seg;
	}

};
