class Node {
public:
Node* left; // 0
Node* right; // 1
};
class Solution {
public:
Node* root;
Solution() {
root = new Node();
}
void insert(int n) {

Node* temp = root;

for (int i = 31; i >= 0; i--) {
int currentBit = (n >> i) & 1;

if (!currentBit) {
if (!temp->left) temp->left = new Node();
temp = temp->left;
}

else {
if (!temp->right) temp->right = new Node();
temp = temp->right;
}

}
}
  // O(1) loop
int helper(int val) {
int ans = 0;
Node* temp = root;

// 0 -> move right; else vice versa
for (int i = 31; i >= 0; i--) {
int currentBit = (val >> i) & 1;

if (!currentBit) {
if (temp->right) {
temp = temp->right;
ans += (1 << i);
}
else temp = temp->left;

}
else {
if (temp->left) {
temp = temp->left;
ans += (1 << i);
}
else temp = temp->right;

}

}

return ans;

}
// O(n)
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
int res = 0;
for (int i = 0; i < n; i++) {

int value = nums[i];
insert(value);

int curAns = helper(value);

res = max(curAns, res);
}

return res; 
    }
};