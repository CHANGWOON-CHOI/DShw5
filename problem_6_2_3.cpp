#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Node {
public:
	int data;
	Node* next=nullptr;
};

class LinkedList {
public:
	Node* head = new Node();
	void insert(int data);
	const void printData();
	int getData(int nodeIndex);
private:
	int cntSize = 0;
};
void LinkedList::insert(int data) {
	if (cntSize == 0) {
		head->data = data;
		head->next = nullptr;
	}
	else {
		Node* currentNode = new Node();
		currentNode->data = data;
		currentNode->next = nullptr;
		Node* tmpNode = head;
		while (tmpNode->next != nullptr) {
			tmpNode = tmpNode->next;
		}
		tmpNode->next = currentNode;
	}
	++cntSize;
}
const void LinkedList::printData() {
	Node* tempNode = head;
	for (int i = 0; i < cntSize; ++i) {
		std::cout << tempNode->data << std::endl;
		tempNode = tempNode->next;
	}
}

int main() {
	ifstream ifile;
	string line;
	string num_v_s;
	string num_e_s;

	int num_v;
	int num_e;

	//modify number later
	string* edges = new string[100];

	ifile.open("graph.txt");
	getline(ifile, num_v_s);
	num_v = stoi(num_v_s);
	getline(ifile, num_e_s);
	num_e = stoi(num_e_s);

	int it = 0;
	while (getline(ifile, edges[it])) { it++; }
	ifile.close();

	//create adjacency list
	LinkedList* adj_list = new LinkedList[num_v];


	//for problem 1 & 2, unless edge_weight==0, add to adjacency list.
	for (int i = 0; i < it; i++) {
		stringstream ss(edges[i]);
		int* tmp = new int[3];
		int j = 0;
		while (ss.good()) {
			string substr;
			getline(ss, substr, ',');
			tmp[j] = stoi(substr);
			j++;
		}
		if (tmp[0] != 0) {
			//add tmp[2] to adjacency list of tmp[1]
			adj_list[tmp[1]].insert(tmp[2]);
		}
	}



	return 0;
}
