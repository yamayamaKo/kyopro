#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define all_acc(x) (x).begin(),(x).end(),0LL
#define int long long
#define absSort(v) sort(a.begin(), a.end(), [](int i, int j) -> bool {return abs(i) < abs(j);});
using namespace std;
using P=pair<int,int>;
using Graph=vector<vector<int>>;
using ll=long long;

//マージするよ
void merge(vector<int> &a,int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    vector<int> l(n1+1);
    vector<int> r(n2+1);
    for(int i=0;i<n1;i++) l[i]=a[left+i];
    for(int i=0;i<n2;i++) r[i]=a[mid+i];

    l[n1]=pow(10,10);
    r[n2]=pow(10,10);
    int i=0,j=0;

    for(int k=left;k<right;k++){
        //ここが比較しているところ
        //cnt++;
        if(l[i]<r[j]){
            a[k]=l[i];
            i++;
        }else{
            a[k]=r[j];
            j++;
        }
    }
}

//マージソートするよ   
void mergeSort(vector<int> &a,int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid,right);
        merge(a,left,mid,right);
    }
}

//分割統治法。rは-1して入れるのを忘れない。partition(a,0,n-1)のように
int partition(vector<int> &a,int p,int r){
    int x=a[r];
    int i=p-1;
    for(int j=p;j<(r);j++){
        if(a[j]<=x){
            i++;
            int key=a[i];
            a[i]=a[j];
            a[j]=key;
        }
    }
    int key=a[i+1];
    a[i+1]=a[r];
    a[r]=key;
    return i+1;
}

//クイックソートをする。rを-1するのは上と同様。
void quickSort(vector<int> &a,int p,int r){
    if(p<r){
        int q=partition(a,p,r);
        quickSort(a,p,q-1);
        quickSort(a,q+1,r);
    }
}

//計数ソートだよ。kは配列の最大値。
void countingSort(vector<int> a,vector<int> &b,int k){
    vector<int> c(k+1);
    int n=a.size();
    for(int i=0;i<=k;i++){
        c[i]=0;
    }

    //各値の出現数を記録する
    for(int i=0;i<n;i++){
        c[a[i]]++;
    }

    //ciにi以下の要素数を記録する
    for(int i=1;i<=k;i++){
        c[i]+=c[i-1];
    }

    //実際に配列に手を加えていく。
    for(int i=n-1;i>=0;i--){
        //c[a[i]]で、a[i]の値のうち、一番うしろのもののインデックスが分かる。
        //格納後に１減らすことで、いい感じにする。
        b[c[a[i]]-1]=a[i];
        c[a[i]]--;
    }
}