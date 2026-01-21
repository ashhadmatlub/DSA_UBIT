#include <iostream>
#include <stdio.h>

using namespace std;

// Binary in which we need sorted data; binary single 

int main(){
    int input[10] = { 23 , 45, 67, 89, 99, 123, 124, 567,789 , 890} ;
    int find ;
    cout<<"Enter the number you wanna find ";
    cin>> find ;

    int l = 0 ; 
    int r = 9 ; 
    int mid ;
    bool valid = true ;

    while ( l <= r){
        mid = ( l + r ) / 2 ;
        if(find == input[mid] ){
            valid = false ;
            cout<< " Found " << find ;
            break;
        }
        if(find > input[mid]  ){
            l = mid + 1 ;
        }else {
            r = mid - 1 ;
        }
    }

    if (valid){
        cout<<" Not Found " << find ;
    }
}