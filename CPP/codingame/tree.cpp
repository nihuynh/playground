#include <stdlib.h>
using namespace std;
#define MAXDEPTH 10000
class Node
{
public:
	int value;
	Node *left;
	Node *right;

	Node *find(int v)
	{
		Node *res;
		res = this->find_until(v, 0);
		while (res->value != v) {
			res = res->find_until(v, 0);
		}
		return res;
	}
	Node *find_until(int v, int depth)
	{
		if (value == v || depth >= MAXDEPTH) {
			return this;
		}
		else if (value > v) {
			return left->find_until(v, depth + 1);
		}
		else if (value < v) {
			return right->find_until(v, depth + 1);
		}
		return NULL;
	}
};
