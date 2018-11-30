class SegTree
{
private:
    vector <int> segTree;
    int sizeOfArray;

public:
    SegTree(vector <int> &arr)
    {
        sizeOfArray = arr.size();
        segTree.resize(2*sizeOfArray);
        for(int i = 0; i < sizeOfArray; i++)
        {
            segTree[sizeOfArray + i] = arr[i];
        }
        for(int i = sizeOfArray - 1; i >= 1; i--)
        {
            int leftChild = 2*i;
            int rightChild = 2*i + 1;
            segTree[i] = min(segTree[leftChild], segTree[rightChild]);
        }
    }

    void update(int index, int value)
    {
        index += sizeOfArray;
        segTree[index] = value;
        while(index > 1)
        {
            index /= 2;
            int leftChild = 2*index;
            int rightChild = 2*index + 1;
            segTree[index] = min(segTree[leftChild], segTree[rightChild]);
        }
    }

    int rangeMinQuery(int leftIndex, int rightIndex)
    {
        leftIndex += sizeOfArray;
        rightIndex += sizeOfArray;

        int minval = 1e9;

        while(leftIndex <= rightIndex)
        {
            if(leftIndex % 2 == 1)
            {
                minval = min(minval, segTree[leftIndex]);
                leftIndex++;
            }
            if(rightIndex % 2 == 0)
            {
                minval = min(minval, segTree[rightIndex]);
                rightIndex--;
            }
            leftIndex /= 2;
            rightIndex /= 2;
        }
        return minval;
    }
};
