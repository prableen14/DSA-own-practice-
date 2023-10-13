bool checkB(vector<int> b){
    for(int i=0;i<b.size()-1;i++){
        if(b[i]>=b[i+1]) return false;
    }
    return true;
}
bool solution(vector<int> a) {
    int k=a.size()-1;
int j=0;
vector<int> b(a.size());
for(int i=0;i<a.size();i++){
    if(i%2==0){
       b[i]=a[j];
       j++ ;
    }
    else{
       b[i]=a[k]; 
       k--;
    }
}
return checkB(b);
}

