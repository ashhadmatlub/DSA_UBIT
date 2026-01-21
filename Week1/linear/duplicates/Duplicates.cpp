#include <iostream>
#include <stdio.h>

using namespace std;

// linear which takes more time but it doesn't have the limitation of sorted data . single 

int main(){
    int input[10] = { 3, 4 ,53, 12,456 ,456,8 , 12,5 , 12};
    int toSearch ;
    int count = 0 ;
    cout<<"Enter the number you want to find ";
    cin >> toSearch ;

    bool valid = true;

    for ( int i = 0 ; i < 10 ; i++){
        if(toSearch == input[i] ){
            count++ ;
            valid = false ; 
        }
    }
    if( valid){
        cout<<"Not found " <<toSearch ;
    }else {
        
        cout<< toSearch  <<" Found " << count << " Times";
    }
}