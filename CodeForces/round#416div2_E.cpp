#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, Q, I, J;

struct Node {
    int number_of_components;
    int left[10];
    int right[10];

    Node () {
        number_of_components = 0;
    }

    void unite(int x, int y) {
        for (int i = 0; i < N; i++) {
            if (left[i] == x) {
                left[i] = y;
            }
            if (right[i] == x) {
                right[i] = y;
            }
        }
    }
};

int mat[10][100000];
Node segment_tree[4 * 100000];

void build(int l, int r, int p) {
    if (l == r) {
        segment_tree[p].number_of_components = N;
        for (int i = 0; i < N; i++) {
            segment_tree[p].left[i] = segment_tree[p].right[i] = l * N + i;
        }
        for (int i = 0; i < N - 1; i++) {
            if (mat[i][l] == mat[i + 1][l]) {
                segment_tree[p].unite(segment_tree[p].left[i+1], segment_tree[p].right[i]);
                segment_tree[p].number_of_components--;
            }
        }
        return;
    }
    int mid = (l + r) / 2;

    build(l, mid, 2 * p);
    build(mid + 1, r, 2 * p + 1);
    
    Node res;
    Node ll = segment_tree[2 * p];
    Node rr = segment_tree[2 * p + 1];
    res.number_of_components = ll.number_of_components + rr.number_of_components;
    for (int i = 0; i < N; i++) {
        res.left[i] = ll.left[i];
        res.right[i] = rr.right[i];
    }

    for (int i = 0; i < N; i++) {
        if (mat[i][mid] == mat[i][mid + 1]) {
            if (ll.right[i] != rr.left[i]) {
                res.unite(ll.right[i], rr.left[i]);
                ll.unite(ll.right[i], rr.left[i]);
                res.number_of_components--;
            }
        }
    }
    segment_tree[p] = res;
}

Node query(int l, int r, int p) {
    if (l >= I && r <= J) {
        return segment_tree[p];
    }
    int mid = (l + r) / 2;
    if (mid >= J) {
        return query(l, mid, 2 * p);
    }
    if (mid < I) {
        return query(mid + 1, r, 2 * p + 1);
    }
    else {
        Node res;
        Node ll = query(l, mid, 2 * p);
        Node rr = query(mid + 1, r, 2 * p + 1);
        res.number_of_components = ll.number_of_components + rr.number_of_components;
        for (int i = 0; i < N; i++) {
            res.left[i] = ll.left[i];
            res.right[i] = rr.right[i];
        }
    
        for (int i = 0; i < N; i++) {
            if (mat[i][mid] == mat[i][mid + 1]) {
                if (ll.right[i] != rr.left[i]) {
                    res.unite(ll.right[i], rr.left[i]);
                    ll.unite(ll.right[i], rr.left[i]);
                    res.number_of_components--;
                }
            }
        }
        return res;
    }
}
int main() {


    scanf("%d %d %d", &N, &M, &Q);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    build(0, M - 1, 1);



    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &I, &J);
        I--;
        J--;
        printf("%d\n", query(0, M-1, 1).number_of_components);
    }
    return 0;
}
