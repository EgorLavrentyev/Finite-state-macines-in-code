#include <iostream>
#include <stack>
#pragma warning (disable: 26812)
using namespace std;
/* ������������� ����� ������ */
struct Node {
	int data; // ������ � ����
	Node* l; // ����� ���������
	Node* r; // ������ ���������
	Node* p; // ��������� �� ��������
};
const int SHOW_LEFT = 1;
const int SHOW_RIGHT = 2;
const int SHOW_PARENT = 4;
/* ��������� �������� */
enum State { START, LEFT, RIGHT, PARENT };

/*
* ����� ��������� ������ ��� ������������� �����
*
* �������� show ���������� ������������� ������:
* ������ (show == SHOW_LEFT),
* �������������� (show == SHOW_RIGHT),
* �������� (show == SHOW_PARENT)
*/
void traverseWithoutStack(Node const* node, int show) {
	State state = START;
	do {
		switch (state) {
		case START:
			state = LEFT;
			break;
		case LEFT:
			if (show == SHOW_LEFT) cout << node->data << " ";
			if (node->l) {
				node = node->l;
				state = LEFT;
			}
			else {
				state = RIGHT;
			}
			break;
		case RIGHT:
			if (show == SHOW_RIGHT) cout << node->data << " ";
			if (node->r) {
				node = node->r;
				state = LEFT;
			}
			else {
				state = PARENT;
			}
			break;
		case PARENT:
			if (show == SHOW_PARENT) cout << node->data << " ";
			if (node->p) {
				if (node->p->l == node) {
					node = node->p;
					state = RIGHT;
				}
				else {
					node = node->p;
					state = PARENT;
				}
			}
			else {
				state = START;
			}
			break;
		}
	} while (state != START);
}
	/*
* ����� ��������� ������ � �������������� �����
*
* �������� show ���������� ������������� ������:
* ������ (show == SHOW_LEFT),
* �������������� (show == SHOW_RIGHT),
* �������� (show == SHOW_PARENT)
*/
	void traverseWithStack(Node const* node, int show) {
		std::stack<Node const*> stack;

		State state = START;
		do {
			switch (state) {
			case START:
				state = LEFT;
				break;
			case LEFT:
				if (show == SHOW_LEFT) cout << node->data << " ";
				if (node->l) {
					stack.push(node);
					node = node->l;
					state = LEFT;
				}
				else {
					state = RIGHT;
				}
				break;
			case RIGHT:
				if (show == SHOW_RIGHT) cout << node->data << " ";
				if (node->r) {
					stack.push(node);
					node = node->r;
					state = LEFT;
				}
				else {
					state = PARENT;
				}
				break;
			case PARENT:
				if (show == SHOW_PARENT) cout << node->data << " ";
				if (stack.empty()) {
					state = START;
				}
				else if (stack.top()->l == node) {
					node = stack.top(); stack.pop();
					state = RIGHT;
				}
				else if (stack.top()->r == node) {
					node = stack.top(); stack.pop();
					state = PARENT;
				}
				break;
			}
		} while (state != START);
	}
	int cNodes; // ���������� �����
	Node* nodes; // ����
	/*
	* ������ ������� ������
	*/
	void readInput() {
		cin >> cNodes;
		nodes = new Node[cNodes];
		for (int i = 0; i < cNodes; i++) {
			nodes[i].data = i;
			nodes[i].p = NULL;
			nodes[i].l = NULL;
			nodes[i].r = NULL;
		}
		for (int i = 0; i < cNodes; i++) {
			int l, r;
			cin >> l >> r;
			if (l != -1) {
				nodes[i].l = nodes + l;
				nodes[l].p = nodes + i;
			}
			if (r != -1) {
				nodes[i].r = nodes + r;
				nodes[r].p = nodes + i;
			}
		}
	}
	int main() {
		readInput();
		cout << "Preorder Without Stack" << endl;
		traverseWithoutStack(nodes, SHOW_LEFT);
		cout << endl;

		cout << "Preorder With Stack" << endl;
		traverseWithStack(nodes, SHOW_LEFT);
		cout << endl;
		cout << "Inorder Without Stack" << endl;
		traverseWithoutStack(nodes, SHOW_RIGHT);
		cout << endl;

		cout << "Inorder With Stack" << endl;
		traverseWithStack(nodes, SHOW_RIGHT);
		cout << endl;

		cout << "Postorder Without Stack" << endl;
		traverseWithoutStack(nodes, SHOW_PARENT);
		cout << endl;

		cout << "Postorder With Stack" << endl;
		traverseWithStack(nodes, SHOW_PARENT);
		cout << endl;
		delete[] nodes;

		return 0;
	}