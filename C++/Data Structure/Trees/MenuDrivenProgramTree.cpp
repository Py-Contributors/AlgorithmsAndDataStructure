#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	int data;
	node *left, *right;
};

class tree
{
public:
	void create(node*, node*);
	node* getnode();
	void search(node*, int val);
	void preorder(node*);
	void inorder(node*);
	void postorder(node*);
};

node* tree::getnode()
{
	node* new_node = new node;
	new_node->left = NULL;
	new_node->right = NULL;
	cout << "Enter value: \n";
	cin >> new_node->data;
	return new_node;
}

void tree::create(node* root, node* new_node)
{
	if (root->data > new_node->data)
	{
		if (root->left == NULL)
			root->left = new_node;
		else
			create(root->left, new_node);
	}
	else
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			create(root->right, new_node);
	}
}

void search(node *root,int val)
{
    int flag=0;
    node *temp;
    temp=root;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            flag=1;
            break;
        }
        else if(temp->data>val)
            temp=temp->left;
        else
            temp=temp->right;

    }
    if(flag==1)
        cout<<"\nfound"<<endl;
    else
        cout<<"\nnot found"<<endl;
}

void tree::preorder(node* temp)
{
	if (temp != NULL)
	{
		cout<< temp->data << endl;
		preorder(temp->left);
		preorder(temp->right);
	}
}

void tree::inorder(node* temp)
{
	if (temp != NULL)
	{
		inorder(temp->left);
		cout<< temp->data << endl;
		inorder(temp->right);
	}
}

void tree::postorder(node* temp)
{
	if (temp != NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<< temp->data << endl;
	}
}

int main()
{
	tree x;
	node *root = NULL, *new_node;
	int ch,val, n, i;
	while (1)
	{
		cout << " Enter your choice(1-6):\n1. Create\n2. Inorder\n3. Preorder\n4. Postorder\n5. Search\n6. Exit\n";
		cin >> ch;
		switch (ch)
		{
			case 1:
			{
				cout << "Enter total number of nodes you want to enter:\n";
				cin >> n;
				for (i = 0; i < n; i++)
				{
					new_node = x.getnode();
					if (root == NULL)
						root = new_node;
					else
						x.create(root, new_node);
				}
				break;
			}
			case 2:
			{
				if (root == NULL)
					cout << "Empty\n";
				else
					x.inorder(root);
				break;
			}
			case 3:
			{
				if (root == NULL)
					cout << "Empty\n";
				else
					x.preorder(root);
				break;
			}
			case 4:
			{
				if (root == NULL)
					cout << "Empty\n";
				else
					x.postorder(root);
				break;
			}
			case 5:
                cout<<"Enter the number you want to search :";
                cin>>val;
                search(root,val);

                break;
            default:
                exit(0);
		}
	}



		}

