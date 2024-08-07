/*Given sequence k = k1<; k2<..... kn of n sorted keys, with a search probability
pi for each key ki . Build the Binary search tree that has the least search cost given
the access probability for each key. Test your program for following example
p1 = 3, p2 = 3, p3 = 1, p4 = 1
q0 = 2, q1 = 3, q2 = 1, q3= 1, q4 = 1


WEIGHT: 16
COST: 32
ROOT: 2
LEFT OF 2: 1
RIGHT OF 2: 3
RIGHT OF 3: 4

The weight of the binary search tree is 22, calculated as the sum of all success and failure probabilities (p and q).
The cost of the binary search tree is 16, which represents the total cost of searching for a key in the tree.
The root of the tree is key 2.
Key 1 is the left child of key 2, and keys 4 and 3 are its right children.
Key 1 has no children (leaf node).
Key 4 has key 3 as its left child and no right child.
Key 3 has no children (leaf node).
*/

#include<iostream>
#include <climits>
using namespace std;
const int N = 1e2;
int w[N][N];
int r[N][N];
int c[N][N];
int p[N];
int q[N];

int main() {
    cout << "ENTER NO. OF ELEMENTS: "; int n; cin >> n;
    cout << "ENTER SUCCESS PROB: \n"; 
    for(int i=1; i <= n; i++) {
        cin >> p[i];
    }
    cout  << "ENTER UNSUCCESS: \n";
    for(int i = 0; i <= n; i++) {
        cin >> q[i];
    }
    for(int i = 0; i <= n; i++) {
        w[i][i] = q[i];
        r[i][i] = 0;
        c[i][i] = 0;
    }
    for(int i = 0; i < n; i++) {
        w[i][i+1] = q[i] + q[i+1] + p[i+1];
        r[i][i+1] =  i+1;
        c[i][i+1] = q[i] + q[i+1] + p[i+1];
    }
    for(int d = 2; d <= n; d++) {
        for(int j = d; j <= n; j++) {
            int i = j - d;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            int mn = INT_MAX;
            int mnk;
            for(int k = i+1; k <= j; k++) {
                int x = c[i][k-1] + c[k][j];
                if(x < mn) {
                    mn = x;
                    mnk = k;
                }
            }
            c[i][j] = w[i][j] + mn;
            r[i][j] = mnk;
        }
    }
    cout << endl;
    cout << "WEIGHT: " << w[0][n] << endl;
    cout << "COST: " << c[0][n] << endl;
    cout << "ROOT: " << r[0][n] << endl;
    int que[100]; int front = 0, rear = -1;
    que[++rear] = 0;
    que[++rear] = n;
    que[++rear] = r[0][n];
    while(front <= rear) {
        int i = que[front++];
        int j = que[front++];
        int k = que[front++];
        if(r[i][k-1] != 0) {
            cout << "LEFT OF " << k << ": " << r[i][k-1] << endl;
            que[++rear] = i;
            que[++rear] = k-1;
            que[++rear] = r[i][k-1];
        }
        if(r[k][j] != 0) {
            cout << "RIGHT OF " << k << ": " << r[k][j]  << endl;
            que[++rear] = k;
            que[++rear] = j;
            que[++rear] = r[k][j];
        }
    }
}