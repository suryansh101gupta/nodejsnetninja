#include <iostream>

using namespace std;



class Node

{

	//Data Members

    int data;

    Node* left;

    Node* right;

    //Threads

    bool lthread,rthread;



public:

    //Default constrcutor

    Node()

    {

        left = right = NULL;

        lthread = rthread = false;

    }



    //Paremetrized Constructor

    Node(int a)

    {

        data = a;

        left = right = NULL;

        lthread = rthread = false;

    }

    friend class TBTree;

};



// THREADED Binary Tree



class TBTree

{

    Node *root;



public:

    TBTree(){

        root==NULL;

    }



    Node *insert(Node *, int);

    Node *inorderSuccessor(Node *);

    Node *getSuccessor(Node *);

    void inorder(Node *);

    void preorder(Node *);

    Node *del(Node *, int);

};



Node *TBTree::insert(Node *root, int key)

{

    Node *p = root;

    Node *q = NULL;



    while (p != NULL)

    {

        if (key == p->data)

        {

            cout << "Duplicate key" << endl;

            return p;

        }



        q = p;

        if (key < p->data)

        {

            if (p->lthread == false)

                p = p->left;

            else

                break;

        }

        else

        {

            if (p->rthread == false)

                p = p->right;

            else

                break;

        }

    }

   Node* temp=new Node(key);



   temp->lthread=true;

   temp->rthread=true;



    if (p == NULL)

    {

        root = temp;

        temp->left = NULL;

        temp->right = NULL;

        cout << "Inserted " << key << endl;

    }



    else if (key < (p->data))

    {

        temp->left = p->left;

        temp->right = p;

        p->lthread = false;

        p->left = temp;

        cout << "Inserted " << key << endl;

    }



    else

    {

        temp->left = p;

        temp->right = p->right;

        p->rthread = false;

        p->right = temp;

        cout << "Inserted " << key << endl;

    }

    return root;

}



Node *TBTree::inorderSuccessor(Node *p)

{

    if (p->rthread){

    	 return p->right;

    }

    p = p->right;

    while (!p->lthread)

        p = p->left;

    return p;

}



void TBTree::inorder(Node *root)

{

    if (root == NULL)

    {

        cout << "Empty Tree" << endl;

        return;

    }

    Node *p = root;

    while (p->lthread == false)

        p = p->left;

    while (p != NULL)

    {

        cout << p->data << " ";

        p = inorderSuccessor(p);

    }

    cout << endl;

}



void TBTree::preorder(Node *root)

{

	if(root==NULL)

	{

		cout<<"Empty Tree"<<endl;

		return;

	}

	Node* p=root;

	while(p!=NULL)

	{

		cout<<p->data<<" ";

		if(p->lthread==false)

		{

			p=p->left;

		}

		else if(p->rthread==false)

		{

			p=p->right;

		}

		else

		{

			while(p!=NULL && p->rthread==true)

			{

				p=p->right;

			}

			if(p!=NULL)

			{

				p=p->right;

			}

		}

	}

	cout<<endl;

}



Node *TBTree::del(Node *root, int key)

{

    Node *par=NULL;

    Node *cur = root;

    bool found=false;



    // Search for the node to be deleted

    while (cur != NULL)

    {

        if (key == cur->data)

        {

            found = true;

            break;

        }

        par = cur;

        if (key < cur->data)

        {

            if (!cur->lthread)

                cur = cur->left;

            else

                break;

        }

        else

        {

            if (!cur->rthread)

                cur = cur->right;

            else

                break;

        }

    }



    if (!found)

    {

        cout << "Node not found." << endl;

        return root;

    }



    // Case 1: Node to be deleted is a leaf node

    if (cur->lthread && cur->rthread)

    {

        if (par == NULL)

        {

            root = NULL;

        }

        else if (cur == par->left)

        {

            par->lthread = true;

            par->left = cur->left;

        }

        else

        {

            par->rthread = true;

            par->right = cur->right;

        }

        delete cur;

    }

    // Case 2: Node to be deleted has only one child

    else if (cur->lthread || cur->rthread)

    {

        Node *child = (cur->lthread) ? cur->left : cur->right;

        if (par == NULL)

        {

            root = child;

        }

        else if (cur == par->left)

        {

            par->left = child;

        }

        else

        {

            par->right = child;

        }

        Node *succ =inorderSuccessor(par);

        Node *pred = inorderSuccessor(cur);

        if (cur->left == succ)

            succ->left = child;

        else

            pred->right = child;

        delete cur;

    }

    // Case 3: Node to be deleted has two children

    else

    {

        Node *succ =inorderSuccessor(cur);

        int temp = succ->data;

        del(root, succ->data);

        cur->data = temp;

    }



    return root;

}



int main()

{

    cout << "!!!Hello World!!!" << endl;

    Node *root =NULL;

    TBTree t;

    int choice;

    do

    {

        cout << "-----MENU-----" << endl;

        cout<<"1.Insert"<<endl;

        cout<<"2.Inorder"<<endl;

        cout<<"3.Preorder"<<endl;

        cout<<"4.Delete"<<endl;

        cout<<"5.Exit"<<endl;



        cout<<"Enter Choice: ";

        cin>>choice;



        switch (choice)

        {

        case 1:

            int a;

            cout << "Enter Data: ";

            cin >> a;

            root = t.insert(root, a);

            break;

        case 2:

            t.inorder(root);

            break;

        case 3:

            t.preorder(root);

            break;

        case 4:

            int val;

            cout<<"Enter Data to delete: "                                                       ;

            cin>>val;

            t.del(root,val);

            break;

        case 5:

        	exit(0);

        	cout<<"Exited"<<endl;

        	break;

        default:

        	cout<<"Invalid Choice"<<endl;

        	break;

        }

    }while(choice!=5);



    return 0;

}