#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int data) { // ejercicio 1
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* insert(Node* root, int data){ // ejercicio 2 
	if(root == NULL){
		root = createNode(data);
	}
	else{
		if(root->data > data){
			root->left = insert(root->left, data);
		}
		else{
			root->right = insert(root->right, data);
		}
	}
	return root;
}

void printTree_in_order(Node* root){ 
	if (root == NULL) {
		return;
	}
	printTree_in_order(root->left);
	cout << root->data << " ";
	printTree_in_order(root->right);
}


void printTree_pre_order(Node* root){ 
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	printTree_pre_order(root->left);
	printTree_pre_order(root->right);
		
}

void printTree_post_order(Node* root){ 
	if (root == NULL) {
		return;
	}
	printTree_post_order(root->left);
	printTree_post_order(root->right);
	cout << root->data << " ";
}

void depthFirstSearch(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    depthFirstSearch(root->left);
    depthFirstSearch(root->right);
}

void breadthFirstSearch(Node* root) {
    if (root == NULL) {
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        
        cout << current->data << " ";
        
        if (current->left != NULL) {
            q.push(current->left);
        }
        
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}

int main(){
	Node* node1 = new Node;
	node1->data = 1;
	
	Node* node2 = new Node;
	node2->data = 2;
	
	Node* node3 = new Node;
	node3->data = 3;
	
	Node* node4 = new Node;
	node4->data = 4;
	
	Node* node5 = new Node;
	node5->data = 5;
	
	Node* node6 = new Node;
	node6->data = 6;
	
	Node* node7 = new Node;
	node7->data = 7;

	node1->left = node2;
	node1->right = node3;
	
	node2->left = node4;
	node2->right = node5;
	
	node3->left = node6;
	node3->right = node7;
	
	node4->left = node4->right = node5->left = node5->right = node6->left = node6->right = node7->left = node7->right = NULL; 
	
	cout << "in-Order: ";
	printTree_in_order(node1);
	cout << endl;
	cout << "pre-Order: ";
	printTree_pre_order(node1);
	cout << endl;
	cout << "post-Order: ";
	printTree_post_order(node1);
	cout << endl;
	
	//ejercicio 5
	
	Node* root = NULL;	
	int arreglo[10] ={21, 18, 6, 9, 10, 7, 19, 15, 12, 5};
	
	for (int i = 0; i < 10; i++) {
        root = insert(root, arreglo[i]);
    }
	
	cout << "ejercicio 5 ordenado: ";
    printTree_in_order(root);
    cout << endl;
    
    //ejercicio 6
	cout << "Depth First Search: ";
    depthFirstSearch(root);
    cout << endl;
    
    //ejercicio 7
    cout << "Breadth-First Search: ";
    breadthFirstSearch(root);
    cout << endl;

	
	
	
	return 0;
}
