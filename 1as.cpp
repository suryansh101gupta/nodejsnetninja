#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node* llink;
    Node* rlink;
public:
    Node(int d){
        data = d;
        llink = NULL;
        rlink = NULL;
    }
    friend class BST;
};

class BST{

public:


    Node* insert_node(Node* &root,int data){
        if (root == NULL){
            Node* temp  = new Node(data);
            root = temp;
        }
        else if (root->data > data){
            insert_node(root->llink,data);
        }
        else{
            insert_node(root->rlink,data);
        }
        return root;
    }

    void construct(Node* &root){
        int data;
        cout<<"Enter data : ";
        while(1){
            cin >> data;
            if (data == -1)
                return;
            insert_node(root,data);
        }
    }

    void Inorder_display(Node* root){
        if (root == NULL)
                return;
        Inorder_display(root->llink);
        cout<<root->data<<" ";
        Inorder_display(root->rlink);
    }

    void min_node(Node* root){
        if (root == NULL)
            return;
        while(root->llink){
            root= root->llink;
        }
        cout<<"Minimum Node in BST: "<<root->data<<endl;
    }

    void max_node(Node* root){
        if (root == NULL)
            return;
        while(root->rlink){
            root= root->rlink;
        }
        cout<<"Maximum Node in BST: "<<root->data<<endl;
    }

    void swapp(Node* root){
        if (root == NULL)
            return;

        if (root->llink == NULL && root->rlink == NULL)
            return;
        
        swapp(root->llink);
        swapp(root->rlink);
        Node* temp = root->llink;
        root->llink = root->rlink;
        root->rlink = temp;
    }

    void search_node(Node* root,int d){
        if (root == NULL){
            cout<<"Not Found!!"<<endl;
            return;
        }

        if (root->data == d){
            cout<<"Found in BST!!"<<endl;
            return;
        }
        else if (root->data > d){
            search_node(root->llink,d);
        }
        else{
            search_node(root->rlink,d);
        }
    }

    pair<int,int> nodes_in_longest_path(Node * root){
        if (root == NULL){
            pair<int,int> p =make_pair(0,0);
            return p;
        }

        pair<int,int> left = nodes_in_longest_path(root->llink);
        pair<int,int> right = nodes_in_longest_path(root->rlink);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int,int> ans;
        ans.first = max(op1,max(op2,op3));
        ans.second = max(left.second,right.second) + 1;
        return ans;

    }
};





int main(){
    BST myTree;
    Node* root = NULL;
    int choice,data;
    int flag = 0;
    while(1){
        cout<<"\n----MENU----\n1.Construct a BST\n2.Insert a node\n3.Find no. of nodes in longest path\n4.Min Node in BST\n5.Max Node in BST\n6.Swap BST\n7.Search an element\n8.Inorder Display\n\nEnter Choice: ";
        cin>>choice;
        switch(choice){
            case 1 :
                myTree.construct(root);
                break;
            case 2 :
                cout<<"Enter Data of Node: ";
                cin>>data;
                myTree.insert_node(root,data);
                break;
            
            case 3 :
                cout<<"Nodes in Longest Path : "<<myTree.nodes_in_longest_path(root).first<<endl;
                break;
            case 4 :
                myTree.min_node(root);
                break;
            case 5 :
                myTree.max_node(root);
                break;
            case 6 :
                myTree.swapp(root);
                cout<<"Swapped BST"<<endl;
                break;
            case 7 :
                cout<<"Enter data to search: ";
                cin>>data;
                myTree.search_node(root,data);
                break;
            case 8 :
                cout<<"Inorder Traversal : ";
                myTree.Inorder_display(root);
                cout<<endl;
                break;
            default :
                flag = 1;
                break;
        }
        if (flag==1){
            break;
        }
    }


    return 0;
}