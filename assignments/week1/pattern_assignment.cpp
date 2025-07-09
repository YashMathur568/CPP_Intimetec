#include <iostream>

using namespace std;

void makePattern(int n){
    for(int i=0;i<(n/2)+1;i++){
        for(int j=0;j<=i;j++){
            if(j%2==0){
                if(j==n/2){
                    continue;
                }
                cout<<1;
            }
            else{
                if(j==n/2){
                    continue;
                }
                cout<<0;
            }
        }
        for(int s=0;s<n-(2*i)-2;s++){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
            if(j%2==0){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
    cout<<endl;
    }

    for(int i=0;i<n/2;i++){
        for(int j=0;j<(n/2)-i;j++){
            if(j%2==0){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }

        for(int s=0;s<2*i+1;s++){
            cout<<" ";
        }

        
        for(int j=0;j<(n/2)-i;j++){
            if(j%2==0){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
    cout<<endl;
    }
}

int main(){
    cout<<"Enter the number of rows in pattern"<<endl;
    int n;
    cin>>n;
    if(n==0){
        cout<<"Please Enter Valid Number Of Rows"<<endl;
        exit(1);
    }
    n=2*n+1;
    makePattern(n);
    return 0;
}