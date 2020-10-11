#include <iostream>
#define R 4
#define C 5

using namespace std;

class value_list{
    public:
    int col_index;
    int value;
    value_list *next;
};

class row_list{
    public:
    int row_number;
    row_list *link_down;
    value_list *link_right;
};

void create_value_node(int data, int j, row_list **z)
{
    value_list *temp, *d;

    // Create a new column node and assign data to it
    temp = new value_list;
    temp->col_index = j + 1;
    temp->value = data;
    temp->next = NULL;

    // If the newly created node is the first node of the row, then directly link it otherwise traverse.
    if ((*z)->link_right == NULL) 
    {
        (*z)->link_right = temp;
    }
    else
    {
        d = (*z)->link_right;
        while(d->next != NULL)
            d = d->next;
        d->next = temp;
    }
}

void create_row_list(row_list **start, int row, int col, int sparse_matrix[R][C])
{
    for (int i = 0; i < row; i++)
    {
        row_list *z, *r;
        // Create a new row node and assign data to it
        z = new row_list;
        z->row_number = i + 1;
        z->link_right = NULL;
        z->link_down = NULL;

        // If the newly created row node is the first one, then mark it as the start otherwise traverse.
        if (i == 0)
        *start = z;
        
        else
        {
            r = *start;
            while(r->link_down != NULL)
                r = r->link_down;
            r->link_down = z;
        }
        
        // To find out the non-zero values in that particular row.
        for (int j = 0; j < col; j++)
        {
            if (sparse_matrix[i][j] != 0)
            {
                create_value_node(sparse_matrix[i][j], j, &z);
            }
        }
    }
}

void print_matrix(row_list *start)
{
    row_list *r;
    value_list *z;
    r = start;
    while (r != NULL)
    {
        if (r->link_right != NULL)
        {
            cout << "\nrow = " << r->row_number;
            z = r->link_right;
            while (z != NULL)
            {
                cout << "\n column = " << z->col_index << " value = " << z->value;
                z = z->next;
            }
        }
        r = r->link_down;

    }
}

int main()
{
    // R = number of rows and C = number of columns
    int sparse_matrix[R][C] = 
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }

    };
    
    row_list *start = NULL;
    create_row_list(&start, R, C, sparse_matrix);
    print_matrix(start);

    return 0;
}
