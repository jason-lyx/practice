/*
 * reverse_linklist.cpp
 *
 *  Created on: Jun 22, 2015
 *  Modified on: Jul 12, 2015
 *      Author: main
 */

#include <iostream>

struct linklist {
	int val;
	linklist* next;
};

linklist* linklist_create(int n) {
	linklist* head = NULL;
	linklist* current = head;

	for (int i = 0; i < n; i++) {
		linklist* node = new linklist;
		node->val = i;
		node->next = NULL;
		if (current == NULL) {
			head = node;
			current = head;
		}
		else {
			current->next = node;
			current = node;
		}
	}

	return head;
}

linklist* linklist_reverse(linklist* head) {
	linklist* prev = NULL;
	while (head != NULL) {
		linklist* next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	return prev;
}

void linklist_print(linklist* head) {
	while (head != NULL) {
		std::cout << head->val << " ";
		head = head->next;
	}
}

int main() {
	linklist* list = linklist_create(10);
	linklist_print(list);
	std::cout << std::endl;

	linklist* reversed_list = linklist_reverse(list);
	linklist_print(reversed_list);
	std::cout << std::endl;

	return 0;
}
