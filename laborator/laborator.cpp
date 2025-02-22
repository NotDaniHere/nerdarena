#include <bits/stdc++.h>
	
using namespace std;
	
 
	
int main(){
	
    ifstream fin("laborator.in");
	
    ofstream fout("laborator.out");
	
    long long n,a,b; 
	
    fin >> n >> a >> b;
	
    string sa, sb;
	
    if(a==0) sa="0"; 
	
    else {
	
        while(a>0){
	
            sa.push_back(char(a%2+'0'));
	
            a/=2;
	
        }
	
        reverse(sa.begin(),sa.end());
	
    }
	
    if(b==0) sb="0"; 
	
    else {
	
        while(b>0){
	
            sb.push_back(char(b%2+'0'));
	
            b/=2;
	
        }
	
        reverse(sb.begin(),sb.end());
	
    }
	
    if(sa.size()<n) sa=string(n-sa.size(),'0') + sa; 
	
    else if(sa.size()>n) sa=sa.substr(sa.size()-n,n);
	
    if(sb.size()<n) sb=string(n-sb.size(),'0') + sb; 
	
    else if(sb.size()>n) sb=sb.substr(sb.size()-n,n);
	
    int p=0,q=0,r=0,cerbusca=0;
	
    for(int i=0;i<n;i++){
	
        if(sa[i]=='1' && sb[i]=='0') p++;
	
        if(sa[i]=='0' && sb[i]=='1') q++;
	
        if(sa[i]=='1' && sb[i]=='1'){
	
            cerbusca++;
	
            if(cerbusca>r) r=cerbusca;
	
        } else cerbusca=0;
	
    }
	
    fout<<p<<" "<<q<<" "<<r<<"\n";
	
    return 0;
	
}