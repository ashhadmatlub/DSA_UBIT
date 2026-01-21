#include <iostream>
#include <stdio.h>

using namespace std;

// linear which takes more time but it doesn't have the limitation of sorted data . single 

int main(){
    int input[10] = { 3, 4 ,53, 12,456 ,7,8 , 12,5 , 10};
    int toSearch ;
    cout<<"Enter the number you want to find ";
    cin >> toSearch ;

    bool valid = true;

    for ( int i = 0 ; i < 10 ; i++){
        if(toSearch == input[i] ){
            cout<< toSearch ;
            valid = false ;
            break;
        }
    }
    if( valid){
        cout<<"Not found " <<toSearch;
    }else {
        cout<<" Found";
    }
}