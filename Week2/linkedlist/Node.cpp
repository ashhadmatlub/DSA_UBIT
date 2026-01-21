#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Node{
    int data;
    Node * next;
}

Node * list == NULL ;

void insert(int value){
    
    Node * temp ;
    temp = (Node *) malloc(sizeof(Node));
    temp -> data = value ;
    temp -> next = NULL ;

    if(list == NULL){
        list == temp 
    }else{
        Node * curr = list ;
    }

    while(curr -> next != NULL){
        curr = curr -> next;
    }

    curr -> next = temp ;
}
