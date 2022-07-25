#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class LinkedList {
public:
	struct Node {
		T data;
		Node* next;
		Node* prev;
	};

	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList<T>& list);
	
	LinkedList<T>& operator=(const LinkedList<T>& rhs);

	void AddHead(const T& data);
	void AddTail(const T& data);
	void AddNodesHead(const T* data, unsigned int count);
	void AddNodesTail(const T* data, unsigned int count);
	void InsertAfter(Node* node, const T& data);
	void InsertBefore(Node* node, const T& data);
	void InsertAt(const T& data, unsigned int index);

	unsigned int NodeCount() const;

	void PrintForward() const;
	void PrintReverse() const;
	void PrintForwardRecursive(const Node* node) const;
	void PrintReverseRecursive(const Node* node) const;

	Node* Head();
	const Node* Head() const;
	Node* Tail();
	const Node* Tail() const;

	void FindAll(vector<Node*>& outData, const T& value) const;
	const Node* Find(const T& data) const;
	Node* Find(const T& data);
	const Node* GetNode(unsigned int index) const;
	Node* GetNode(unsigned int index);

	const T& operator[](unsigned int index) const;
	T& operator[](unsigned int index);
	//LinkedList<T>& operator=(const LinkedList<T>* rhs);
	bool operator==(const LinkedList<T>& rhs) const;

	bool RemoveHead();
	bool RemoveTail();
	unsigned int Remove(const T& data);
	bool RemoveAt(unsigned int index);
	void Clear();
	

	
private:
	Node* head;
	Node* tail;
	unsigned int count;
	void Set(const LinkedList& list);


};
template <typename T>
void LinkedList<T>::Set(const LinkedList& list) {
	Node* curr = list.head;
	if (curr == nullptr) {
		head = nullptr;
		tail = nullptr;
		return;
	}

	Node* copyVal = list.head;
	Node* twinNode = nullptr;

	while (copyVal != nullptr) {
		twinNode = new Node();
		twinNode->data = copyVal->data;

		if (head == nullptr) {
			head = twinNode;
			tail = twinNode;
		}
		else {
			tail->next = twinNode;
			tail = twinNode;
		}
		copyVal = copyVal->next;
	}
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {
	Set(list);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {
	Clear();
	Set(rhs);
	return *this;
}

template <typename T>
LinkedList<T>::LinkedList() {
	count = 0;
	head = nullptr;
	tail = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	Clear();
}

template <typename T>
void LinkedList<T>::AddHead(const T& data){
	Node* frontNode = new Node();
	frontNode->data = data;
	frontNode->prev = nullptr;

	if (head == nullptr) {
		frontNode->next = nullptr;
		head = frontNode;
		tail = frontNode;
	}
	else {
		frontNode->next = head;
		head->prev = frontNode;
		head = frontNode;
	}
	count++;
}

template <typename T>
void LinkedList<T>::AddTail(const T& data) {
	Node* frontNode = new Node();
	frontNode->data = data;
	frontNode->next = nullptr;

	if (tail == nullptr) {
		frontNode->prev = nullptr;
		head = frontNode;
		tail = frontNode;
	}
	else {
		frontNode->prev = tail;
		tail->next = frontNode;
		tail = frontNode;
	}
	count++;
}

template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count) {
	for (unsigned int i = count; i > 0; i--) {
		AddHead(data[i-1]);
	}
}

template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count) {
	for (unsigned int i = 0; i < count; i++) {
		AddTail(data[i]);
	}
}

template <typename T>
void LinkedList<T>::PrintForward() const {
	Node* curr = head;
	while (curr != nullptr) {
		cout << curr->data << endl;
		curr = curr->next;
	}
}

template <typename T>
void LinkedList<T>::PrintReverse() const {
	Node* curr = tail;
	while (curr != nullptr) {
		cout << curr->data << endl;
		curr = curr->prev;
	}
}

template <typename T>
unsigned int LinkedList<T>::NodeCount() const {
	return count;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head() {
	return head;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const {
	return head;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail() {
	return tail;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const {
	return tail;
}

template <typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const {
	Node* curr = head;
	while (curr != nullptr) {
		if (curr->data == value) {
			outData.push_back(curr);
		}
		curr = curr->next;
	}
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const {
	Node* curr = head;
	int index = 0;
	while (curr->data != data && curr->next != nullptr) {
		index++;
		curr = curr->next;
	}
	if (curr->data != data) {
		return nullptr;
	}
	return (curr);
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) {
	Node* curr = head;
	int index = 0;
	while (curr->data != data && curr->next != nullptr) {
		index++;
		curr = curr->next;
	}
	if (curr->data != data) {
		return nullptr;
	}
	return (curr);
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const {
	Node* curr = head;
	if (index < count) {
		for (unsigned int i = 0; i < index; i++) {
			curr = curr->next;
		}
	}
	else {
		throw out_of_range("Error");
	}
	return curr;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) {
	Node* curr = head;
	if (index < count) {
		for (unsigned int i = 0; i < index; i++) {
			curr = curr->next;
		}
	}
	else {
		throw out_of_range("Error");
	}
	return curr;
}

template <typename T>
const T& LinkedList<T>::operator[](unsigned int index) const {
	Node* curr = head;
	if (index > count) {
		throw out_of_range("Error");
	}
	for (unsigned int i = 0; i < index; i++) {
		curr = curr->next;
	}
	return curr->data;
}

template <typename T>
T& LinkedList<T>::operator[](unsigned int index) {
	Node* curr = head;
	if (index > count) {
		throw out_of_range("Error");
	}
	for (unsigned int i = 0; i < index; i++) {
		curr = curr->next;
	}
	return curr->data;
}

template <typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data) {
	Node* insertNode = new Node();
	insertNode->data = data;
	insertNode->next = node->next;
	insertNode->prev = node;
	node->next = insertNode;

}

template <typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data) {
	Node* insertNode = new Node();
	insertNode->data = data;
	insertNode->prev = node->prev;
	insertNode->next = node;
	if (insertNode->prev != nullptr) {
		insertNode->prev->next = insertNode;
	}
}

template <typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index) {
	Node* insertNode = new Node();
	insertNode->data = data;
	insertNode->next = nullptr;
	insertNode->prev = nullptr;
	if (index < 0) {
		throw out_of_range("Error");
	}
	else if (index == 0) {
		insertNode->next = head;
		head->prev = insertNode;
		head = insertNode;
		count++;
	}
	else {
		Node* curr = head;
		unsigned int position = 0;
		while (position < index-1) {
			if (curr != nullptr) {
				curr = curr->next;
			}
			position++;
		}
		if (curr != nullptr) {
			insertNode->next = curr->next;
			insertNode->prev = curr;
			curr->next = insertNode;
			if (insertNode->next != nullptr) {
				insertNode->next->prev = insertNode;
				count++;
			}
		}
		else {
			throw out_of_range("Error");
		}
	}
}


template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const {
	Node* listOne = head;
	Node* listTwo = rhs.head;

	if (count != rhs.count) {
		return false;
	}
	bool keepGoing = true;
	while (listOne != nullptr && listTwo != nullptr && keepGoing == true) {
		if (listOne->data == listTwo->data) {
			keepGoing = true;
		}
		else {
			return false;
		}
		listOne = listOne->next;
		listTwo = listTwo->next;
	}
	if (keepGoing == true) {
		return true;
	}
	else {
		return false;
	}

}

template <typename T>
void LinkedList<T>::PrintForwardRecursive(const Node* node) const {
	if (node == nullptr)
		return;
	else {
		cout << node->data << endl;
		node = node->next;
		PrintForwardRecursive(node);
	}
}

template <typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const {
	if (node == nullptr) {
		return;
	}
	else {
		cout << node->data << endl;
		node = node->prev;
		PrintReverseRecursive(node);
	}
}


template <typename T>
bool LinkedList<T>::RemoveHead() {
	Node* curr = head;
	if (head == nullptr) {
		return false;
	}
	if (head != nullptr) {
		head = head->next;
		head->prev = nullptr;
	}
	if (head->next == nullptr) {
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	delete curr;
	return true;
	count--;
}

template <typename T>
bool LinkedList<T>::RemoveTail() {
	Node* curr = tail;
	if (tail == nullptr)
		return false;

	if (tail->prev != nullptr) {
		tail = tail->prev;
		tail->next = nullptr;

	}
	else {
		head = nullptr;
		tail = nullptr;
		count = 0;
		return true;
	}
	delete curr;
	return true;
	count--;
}

template <typename T>
unsigned int LinkedList<T>::Remove(const T& data) {
	Node* curr = head;
	Node* nextCurr = nullptr;
	unsigned int numRemoved = 0;
	while (curr != nullptr) {
		if (curr->data == data) {
			numRemoved++;
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			nextCurr = curr->next;
			delete curr;
			curr = nextCurr;
		}
		curr = curr->next;
	}
	count--;
	return numRemoved;
}

template <typename T>
bool LinkedList<T>::RemoveAt(unsigned int index) {
	Node* deleteNode = head;

	if (index < 0) {
		throw out_of_range("Error");
		return false;
	}
	else if (index > count) {
		return false;
	}
	else if (index == 0) {
		deleteNode->next->prev = nullptr;
		head = deleteNode->next;
		count--;
		delete deleteNode;
		return true;
	}
	else {
		Node* curr = head;
		unsigned int runs = 0;
		while (curr->next != nullptr) {
			if (runs == index) {
				break;
			}
			else {
				runs++;
				curr = curr->next;
			}
		}
		curr->next->prev = curr->prev;
		curr->prev->next = curr->next;
		delete curr;
		return true;
	}

}

template <typename T>
void LinkedList<T>::Clear() {
	Node* curr = head;
	Node* nextNode = nullptr;

	while (curr != nullptr) {
		nextNode = curr->next;
		delete curr;
		curr = nextNode;
	}
	count = 0;
	head = nullptr;
	tail = nullptr;
}









