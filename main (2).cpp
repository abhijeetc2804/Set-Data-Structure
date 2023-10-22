#include<iostream>
#include<vector>
#include<string>
using namespace std;


int finder(vector<int> v1,int n,int x){
    if(n==0){
        return -1;
    }
    int idx=-1;
    if(x>v1[n-1] ||x<v1[0]){
        return -1;
    }    
    else{
        for(int i=0;i<n;i++){
            if(v1[i]==x){
                idx=i;
                break;
            }
        }
    }
    return idx;
}



class SET{
    public:
    vector<int> v1;
    void Insert(int x){
        int n=v1.size();
        if(n==0){
            v1.push_back(x);
            cout<<1;
        }
        else{
            int c=finder(v1,n,x);
            if(c==-1){
                if(x>v1[n-1]){
                    v1.push_back(x);
                }
                else{
                int i=0;
                while(v1[i]<x){
                    i++;
                }
                v1.insert(v1.begin()+i,x);
            }
            }
            cout<<v1.size();
        }
    }

    void Delete(int x){
        int n=v1.size();
        int y=finder(v1,n,x);
        if(y!=-1){
            v1.erase(v1.begin()+y);
            cout<<n-1;
        }
        else{
            cout<<n;
        }
    }

    void Belongs_to(int x){
        int n=v1.size();
        if(n==0){
            cout<<0;
        }
        else{
        if(x<v1[0] || x>v1[n-1]){
            cout<<0;
        }
        else{
            if(x==v1[0] || x==v1[n-1]){
                cout<<1;
            }
            else{
                if(finder(v1,n,x)==-1){
                    cout<<0;
                }
                else{
                    cout<<1;
                }
            }
        }
        }
    }
    
    void Union(SET v2){
        int n=v1.size();
        int m=(v2.v1).size();
        int i=0,j=0;
        vector<int> v3;
        while(i<n && j<m){
            if(v1[i]<(v2.v1)[j]){
                v3.push_back(v1[i]);
                i++;
            }
            else if(v1[i]>(v2.v1)[j]){
                v3.push_back((v2.v1)[j]);
                j++;
            }
            else{
                v3.push_back(v1[i]);
                i++;
                j++;
            }
        }
        while(i<n){
            v3.push_back(v1[i]);
            i++;
        }
        while(j<m){
            v3.push_back(v2.v1[j]);
            j++;
        }
        v1=v3;
        cout<<v3.size();
    }

    void Intersection(SET v2){
        vector<int> v3;
        int i=0,j=0;
        while(i<v1.size() && j<(v2.v1).size()){
            if(v1[i]==(v2.v1)[j]){
                v3.push_back(v1[i]);
                i++;
                j++;
            }
            else if(v1[i]<(v2.v1)[j]){
                i++;
            }
            else{
                j++;
            }
        }
        v1=v3;
        cout<<v3.size();
    }
    void Size(){
        cout<<v1.size();
    }
    void Diff(SET v2){
        vector<int> v3;
        int n=v1.size();
        int m=(v2.v1).size();
        int i=0,j=0;
        while(i<n && j<m){
            if(v1[i]<v2.v1[j]){
                v3.push_back(v1[i]);
                i++;
            }
            else if(v1[i]>v2.v1[j]){
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        while(i<n){
            v3.push_back(v1[i]);
            i++;
        }
        v1=v3;
        cout<<v3.size();
    }
    
    void SymDiff(SET v2){
        int n=v1.size();
        int m=(v2.v1).size();
        vector<int> v3;
        int i=0,j=0;
        while(i<n && j<m){
            if(v1[i]<(v2.v1)[j]){
                v3.push_back(v1[i]);
                i++;
            }
            else if(v1[i]>(v2.v1)[j]){
                v3.push_back((v2.v1)[j]);
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        while(i<n){
            v3.push_back(v1[i]);
            i++;
        }
        while(j<m){
            v3.push_back((v2.v1)[j]);
            j++;
        }
        
        v1=v3;
        cout<<v3.size();
    }
    void Print(){
        int n=v1.size();
        if(n>0){
            for(int i=0;i<n-1;i++){
                cout<<v1[i]<<",";
            }
            cout<<v1[n-1];
        }
    }
};


int main(){
    vector<SET> v;
    int x;
    while(cin>>x){
        int a,b;
        if(x==6||x==9){
            cin>>a;
        }
        else{
            cin>>a>>b;
        }
        if(x==1){
            if(v.size()==a){
                SET y;
                v.push_back(y);
                v[a].Insert(b);
            }
            else{
                v[a].Insert(b);
            }
        }
        else if(x==2){
            if(v.size()<=a){
                cout<<-1;
            }
            else {
                v[a].Delete(b);
            }
        }
        else if(x==3){
            if(v.size()>a){
                v[a].Belongs_to(b);
            }
            else{
                cout<<-1;
            }
        }
        else if(x==4){
            int n=v.size();
            if(a<n && b<n){
                v[a].Union(v[b]);
            }
            else if(max(a,b)==n){
                SET s;
                v.push_back(s);
                v[a].Union(v[b]);
            }
            else if(max(a,b)==n+1){
                SET s1,s2;
                v.push_back(s1);
                v.push_back(s2);
            }
        }
        else if(x==5){
            int n=v.size();
            if(a<n && b<n){
                v[a].Intersection(v[b]);
            }
            else if(max(a,b)==n){
                SET s;
                v.push_back(s);
                v[a].Intersection(v[b]);
            }
            else if(max(a,b)==n+1){
                SET s1,s2;
                v.push_back(s1);
                v.push_back(s2);
            }
        }
        else if(x==6){
            if(a<v.size()){
                v[a].Size();
            }
            else{
                SET s;
                v.push_back(s);
                cout<<0;
            }
        }
        else if(x==7){
            int n=v.size();
            if(a<n && b<n){
                v[a].Diff(v[b]);
            }
            else if(max(a,b)==n){
                SET s;
                v.push_back(s);
                v[a].Diff(v[b]);
            }
            else if(max(a,b)==n+1){
                SET s1,s2;
                v.push_back(s1);
                v.push_back(s2);
            }
        }
        else if(x==8){
            int n=v.size();
            if(a<n && b<n){
                v[a].SymDiff(v[b]);
            }
            else if(max(a,b)==n){
                SET s;
                v.push_back(s);
                v[a].SymDiff(v[b]);
            }
            else if(max(a,b)==n+1){
                SET s1,s2;
                v.push_back(s1);
                v.push_back(s2);
            }
        }
        else if(x==9){
            if(a<v.size()){
                v[a].Print();
            }
        }
    cout<<"\n";
    }
}