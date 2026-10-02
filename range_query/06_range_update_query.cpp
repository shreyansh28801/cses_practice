#include <bits/stdc++.h>
using namespace std;

class SegTree
{
    int size;
    vector<long long> data;

    /*
        Note - we are using 1 based indexing here.
        Children of node x are 2x and 2x+1.
        Parent of node x is x/2.
    */

public:
    SegTree(int n)
    {
        size = 1;

        while (size < n)
            size *= 2;

        data.resize(2 * size, 0);
    }

    // Build

    // 1. Build iterative
    void build_iterative(vector<long long> &v)
    {
        int n = v.size();

        for (int i = size; i < 2 * size; i++)
        {
            if (i - size < n)
                data[i] = v[i - size];
            else
                data[i] = 0;
        }

        for (int i = size - 1; i > 0; i--)
            data[i] = 0;
    }

    // 2. Build recursive

    /*
        v    -> Original input array.
        node -> Current node index in segment tree.
        lx   -> left index of the original array range represented by node.
        rx   -> right index of the original array range represented by node.
    */
    void build_recursive(vector<long long> &v, int node, int lx, int rx)
    {
        if (lx == rx)
        {
            if (lx < v.size())
                data[node] = v[lx];
            else
                data[node] = 0;

            return;
        }

        int mid = (lx + rx) / 2;

        build_recursive(v, 2 * node, lx, mid);
        build_recursive(v, 2 * node + 1, mid + 1, rx);

        data[node] = 0;
    }

    void build_recursive(vector<long long> &v)
    {
        build_recursive(v, 1, 0, size - 1);
    }

    // Update

    /*
        pos  -> index in the original array to update.
        val  -> new value.
        node -> current node in segment tree.
        lx   -> left index of the original array range represented by node.
        rx   -> right index of the original array range represented by node.
    */
    void update(int node, int lx, int rx, int pos, long long val)
    {
        if (lx == rx)
        {
            data[node] = val;
            return;
        }

        int mid = (lx + rx) / 2;

        if (pos <= mid)
            update(2 * node, lx, mid, pos, val);
        else
            update(2 * node + 1, mid + 1, rx, pos, val);

        data[node] = min(data[2 * node], data[2 * node + 1]);
    }

    void update(int pos, long long val)
    {
        update(1, 0, size - 1, pos, val);
    }

    // Query

    /*
        l    -> left index of query range in original array.
        r    -> right index of query range in original array.
        node -> current node in segment tree.
        lx   -> left index of original array range represented by node.
        rx   -> right index of original array range represented by node.
    */
    long long query(int node, int lx, int rx, int l, int r)
    {
        // No overlap
        if (rx < l || r < lx)
            return 0;

        // Complete overlap
        if (l <= lx && rx <= r)
            return data[node];

        int mid = (lx + rx) / 2;

        long long left = query(2 * node, lx, mid, l, r);
        long long right = query(2 * node + 1, mid + 1, rx, l, r);

        return min(left, right);
    }

    long long query(int l, int r)
    {
        return query(1, 0, size - 1, l, r);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
 
    SegTree st(n);

    st.build_recursive(a);

    while (q--)
    {
        int type;
        cin>> type;

        if(1 == type) {
            int a, b;
            cin>>a>>b;
            st.update(a-1, b);

        } else if(2 == type){
            int l, r;
            cin>>l>>r;
            cout<<st.query(l-1, r-1)<< " ";

        } else {
            cout<< "Operation not allowed !!";
        }
    }
    return 0;
}