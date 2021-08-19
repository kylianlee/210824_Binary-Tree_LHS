//
// Created by Kylian Lee on 2021/08/19.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int level;
  cin >> level;
  vector<vector<int>> tree;
  tree.resize(2);
  int size = (int)pow((double)2, (double)level + 1);
  tree[0].resize(size, 0);
  tree[1].resize(size);
  for (int i = 2; i < size; ++i) {
    cin >> tree[1][i];
  }
  for (int i = size - 1; i >= 3; i -= 2) {
    int a = tree[0][i] + tree[1][i];
    int b = tree[0][i - 1] + tree[1][i - 1];
    if(a > b){
      tree[0][i / 2] = a;
      tree[1][i - 1] += a - b;
    }
    else{
      tree[0][i / 2] = b;
      tree[1][i] += b - a;
    }
  }
  int sum = 0;
  for (int i = 2; i < size; ++i) {
    sum += tree[1][i];
  }
  cout << sum << endl;
  return 0;
}