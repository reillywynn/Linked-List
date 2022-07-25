
/*==== Construction / Destruction ====*/
Linkedlist();
LinkedList(const LinkedList<T>& list);
~LinkedList();

/*==== Insertion ====*/
void AddHead(const T& data);
void AddTail(const T& data);
void AddNodesHead(const T* data, unsigned int count);
void AddNodesTail(const T* data, unsigned int count);

/*==== Behaviors ====*/
void PrintForward() const;
void PrintReverse() const;

/*==== Accessors ====*/
unsigned int NodeCount() const;
};

template <typename T>
LinkedList<T>::LinkedList() {

}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {

}

template <typename T>
LinkedList<T>::~LinkedList() {

}

template <typename T>
void LinkedList<T>::AddHead(const T& data) {

}

template <typename T>
void LinkedList<T>::AddTail(const T& data) {

}

template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count) {

}

template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count) {

}

template <typename T>
void LinkedList<T>::PrintForward() const {

}

template <typename T>
void LinkedList<T>::PrintReverse() const {

}

template <typename T>
unsigned int LinkedList<T>::NodeCount() const {

}




template <typename T>
LinkedList<T>::LinkedList() {
	count = 0;
	head -> nullptr;
	tail -> nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {

}

template <typename T>
LinkedList<T>::~LinkedList() {

}

template <typename T>
void typename LinkedList<T>::Node LinkedList<T>::AddHead(const T* data) {

}

template <typename T>
void typename LinkedList<T>::Node LinkedList<T>::Addtail(const T* data) {

}




class LinkedList {
	struct Node {
		T* data;
		Node* next;
		Node* previous;
	};
public:

	/*==== Construction / Destruction ====*/
	Linkedlist(T* data, Node* next = nullptr, Node* previous = nullptr);
	~LinkedList();

	/*==== Insertion ====*/
	void AddHead(const T& data);
	void AddTail(const T& data);
	void AddNodesHead(const T* data, unsigned int count);
	void AddNodesTail(const T* data, unsigned int count);

	/*==== Behaviors ====*/
	void PrintForward() const;
	void PrintReverse() const;

private:
	Node* head;
	Node* tail;
	unisgned int count;

};

template <typename T>
LinkedList<T>::Linkedlist() {

}