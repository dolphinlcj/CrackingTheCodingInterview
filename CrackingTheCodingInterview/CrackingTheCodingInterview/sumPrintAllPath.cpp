#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 100;
struct Node{
	int key;
	Node *left, *right, *parent;
};

Node node[maxn];
int cnt;

void init()
{
	cnt = 0;
	memset(node, '\0', sizeof(node));
}

void createBTree(Node * &head, Node *parent, int a[], int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) >> 1;
		node[cnt].key = a[mid];
		node[cnt].parent = parent;
		cnt += 1;
		head = &(node[cnt]);

		createBTree(head->left, head, a, start, mid - 1);
		createBTree(head->right, head, a, mid + 1, end);
	}

}
void print(Node* head, int level)
{
	vector<int> v;
	while(head)
	{
		v.push_back(head->key);
		head = head->parent;
	}
	while (!v.empty())
	{
		cout << v.back() << " ";
		v.pop_back();
	}
	cout << endl;
}
void findSum(Node *head, int sum)
{
	if (head == NULL)
	{
		return;
	}
	Node *no = head;
	int temp = 0;
	
	for (int i = 1; no != NULL; i++)
	{	
		temp += no->key;
		if (temp == sum){
			print(head, i);
		}
		no = no->parent;
	}

	findSum(head->left, sum);
	findSum(head->right, sum);
}
int main()
{
	init();
	
	Node *r = NULL;
	int a[] = {4, 3, 8, 5, 2, 1, 6};
	int sum;
	
	createBTree(r, NULL, a, 0, 6);
	//input sum
	cin >> sum;
	
	findSum(r, sum);
	return 0;
}