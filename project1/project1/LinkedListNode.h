#pragma once

class LinkedListNode {
public:
	LinkedListNode(int value, LinkedListNode* previous = nullptr, LinkedListNode* = nullptr);

	int data;
	LinkedListNode* previous;
	LinkedListNode* next;
};

LinkedListNode::LinkedListNode(int value, LinkedListNode* previous)