// This is a generic implementation of the segment tree without lazy propagation
// This solves range sum query with updates
// For other problems the implementation of the util class should be changed accordingly.

#include <iostream>

// struct for the segment tree node
struct sTreeNode{
	int x;
};

typedef struct sTreeNode snode;

class util{
public:
	// This is the return value if the range is out of bounds
	snode outValue;

	util(){
		outValue.x = 0;
	}

    // function to return the value of leaf during build
	snode getLeaf(int a)
    {
		snode ans;
		ans.x = a;
		return ans;
	}

    // function to combine two segment tree nodes
	snode combine(const snode &a, const snode &b)
    {
		snode ans;
		ans.x = a.x + b.x;
		return ans;
	}

    // function to return during query if the segment falls in the range
	snode getVal(const snode &a)
    {
		snode ans;
		ans.x = a.x;
		return ans;
	}
};

// IMPORTANT:: Assumes array is 1 indexed.
class segtree{
public:
	const int SIZE;
	snode *seg;
	util u;

	// constructor
	segtree(int size):
	SIZE(size)
	{
		seg = new snode[4*size+1];
		for(int i = 0 ; i <= 4*size ; i++)
			seg[i].x = 0;
	}

	// function to build the tree. Lrange and Rrange give us the segment the current node covers
	void build(int arr[],  int Lrange , int Rrange , int node_index = 1)
	{
		if(Lrange == Rrange)
		{
			seg[node_index] = u.getLeaf(arr[Lrange]);
			return;
		}
		int M = (Lrange+Rrange)/2;
		build(arr, Lrange, M, node_index*2);
		build(arr, M+1, Rrange, node_index*2+1);
		seg[node_index] = u.combine(seg[node_index*2], seg[node_index*2+1]);
	}

	// function to query the tree. Lrange and Rrange give us the segment the current node covers
	snode query(int i, int j, int Lrange , int Rrange , int node_index = 1)
	{
		if(j<Lrange || i>Rrange)
			return u.outValue;
		if(i<=Lrange && Rrange<=j)
			return u.getVal(seg[node_index]);
		int M = (Lrange+Rrange)/2;
		snode left  = query(i, j, Lrange, M, node_index*2);
		snode right = query(i, j, M+1, Rrange, node_index*2 + 1);
		return u.combine(left, right);
	}

	// function to update the segment tree. Lrange and Rrange give us the segment the current node covers
	void update(int pos, int val, int Lrange , int Rrange , int node_index = 1)
	{
		if(Lrange == Rrange)
		{
			seg[node_index] = u.getLeaf(val);
			return;
		}
		int M = (Lrange+Rrange)/2;
		if(pos <= M)
			update(pos, val, Lrange, M, node_index*2);
		else
			update(pos, val, M+1, Rrange, node_index*2 + 1);
		seg[node_index] = u.combine(seg[node_index*2], seg[node_index*2 + 1]);
	}

	// getter to get size
	int getSize () const
    {
		return SIZE;
	}

	// destructor
	~segtree()
    {
		delete [] seg;
	}

};
