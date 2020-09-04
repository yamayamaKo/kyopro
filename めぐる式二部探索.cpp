#include <bits/stdc++.h>
using namespace std;

int ok=0; //解が存在する値
int ng=1000; //解が存在しない値
//上のモノの大小を逆にすれば、最小値も分かる
bool solve(int n){
    if(n>0) return true;
    else return false;
}
void MeguruBinarySearch(){
    while(abs(ok-ng)>1){
    int mid = (ok+ng)/2;
    if(solve(mid)){//solveは適当な条件
        ok=mid;
    }else{
        ng=mid;
    }
    }
}
