#include <iostream>

using namespace std;





class Node{

public:

	string value;

	Node* lnext;



	Node(string v){

		this->value=v;

		this->lnext=NULL;

	}

};

class chainhash{

	Node* arr[26];

public:

	chainhash(){

		for(int i=0;i<26;i++){

			Node* temp=new Node("_");

			arr[i]=temp;

		}

	}

	char hash(string v){

		return v[0];

	}

    int charToRowIndex(char ch) {

        if ('a' <= ch && ch <= 'z') {

            return ch - 'a';

        } else {



            cerr << "Invalid character: " << ch << endl;

            return -1;

        }

    }

    void insert(string v){

    	char h = hash(v);

    	int index=charToRowIndex(h);

    	Node* newnode;

    	newnode=new Node(v);

    	Node* temp1= arr[index];

    	if(temp1->value=="_"){

    		arr[index]=newnode;

    	}

    	else{

    		Node* temp=arr[index];

    		temp->lnext=newnode;

    	}

    }

    void display(){

    	for(int i=0;i<26;i++){

    		Node* temp=arr[i];

    		string v=temp->value;

    		char ch=v[0];

    		cout<<ch<<" : "<<v;

    		while(temp->lnext){

    			temp=temp->lnext;

    			cout<<" -> "<<temp->value;

    		}

    		cout<<endl;

    	}

    }



    void search(string v){

    	char h = hash(v);

    	int flag=0;

    	int index=charToRowIndex(h);

    	Node* temp=arr[index];

//    	if(temp->value==v){

//    		cout<<"element found "<<endl;

//    		return;

//    	}

//    	while(temp->lnext && temp->lnext->value!=v){

//    		temp=temp->lnext;

//    	}

//    	if(temp->lnext->value==v){

//    		cout<<"Element found";

//    		return;

//    	}

//    	else if(temp->lnext->value!=v){

//    		cout<<"element not found";

//    		return;

//    	}

    	while(temp!=NULL)

    	{

    		if(temp->value == v)

    		{

    			flag=1;

    			break;

    		}

    		temp=temp->lnext;

    	}

    	if(flag == 1)

    	{

    		cout<<"Element found"<<endl;

    	}

    	else

    	{

    		cout<<"element not found"<<endl;

    	}

    }

    void Delete(string str)



	{

    	char ch=str[0];

    	int key=charToRowIndex(ch);

//    	int key =str[0]-'a';



    	if(arr[key]->value == "_")

    	{



    		cout<<"Element not found"<<endl;



    	}

    	else if(arr[key]-> value == str)

    	{



    		if(arr[key]->lnext != NULL)



    		{



    			arr[key]=arr[key]->lnext;



    		}



    		else



    		{



    			arr[key]->value = "_";



    		}



    	}

    	else



    	{



    		Node* temp=arr[key];



    		while(temp!= NULL)



    		{



    			if(temp->lnext!=NULL && temp->lnext->value==str)



    			{



    				temp->lnext=temp->lnext->lnext;



    				break;



    			}



    			temp=temp->lnext;



    		}



    	}



	}

};



int main() {

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	chainhash chh;

	chh.insert("hello");

	chh.insert("apple");

	chh.insert("android");

cout<<"\n Displaying Hash table : "<<endl;

	chh.display();

	cout<<"\nSearching apple in hash table : "<<endl;

	chh.search("apple");

	cout<<"\ndeleting apple from hash table : "<<endl;

	chh.Delete("apple");

	cout<<"\nDisplaying hash table after deleting "<<endl;

	chh.display();

	return 0;

}