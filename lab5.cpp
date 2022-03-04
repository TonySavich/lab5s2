#include <iostream>
#include <fstream>
const int One = 1;

struct Elem
{
    int data;       // 
    //    
    Elem* left;
    Elem* right;
    Elem* parent;
};

//  
Elem* MAKE(int data, Elem* p)
{
    Elem* q = new Elem;         //    
    q->data = data;
    q->left = nullptr;
    q->right = nullptr;
    q->parent = p;
    return q;
}

//  
void ADD(int data, Elem*& root)
{
    if (root == nullptr) {
        root = MAKE(data, nullptr);
        return;
    }
    Elem* v = root;
    while ((data < v->data && v->left != nullptr) || (data > v->data && v->right != nullptr))
        if (data < v->data)
            v = v->left;
        else
            v = v->right;
    if (data == v->data)
        return;
    Elem* u = MAKE(data, v);
    if (data < v->data)
        v->left = u;
    else
        v->right = u;
}

//  
void PASS(Elem* v)
{
    if (v == nullptr)
        return;
    // 

    PASS(v->left);
    // 
    std::cout << v->data << std::endl;

    PASS(v->right);

    // 
}

Elem* SEARCH(int data, Elem* v) // v - ,    
{
    if (v == nullptr)
        return v;
    if (v->data == data)
        return v;
    if (data < v->data)
        return SEARCH(data, v->left);
    else
        return SEARCH(data, v->right);
}


void DELETE(int data, Elem*& root)
{
    //   .  
    Elem* u = SEARCH(data, root);
    if (u == nullptr)
        return;

    //   ( )
    if (u->left == nullptr && u->right == nullptr && u == root)
    {
        root = nullptr;
        return;
    }

    //    
    if (u->left != nullptr && u->right != nullptr)
    {
        Elem* t = u->right;
        while (t->left != nullptr)
            t = t->left;
        u->data = t->data;
        u = t;
    }
    Elem* t;
    if (u->left == nullptr)
        t = u->right;
    else
        t = u->left;
    if (u->parent->left == u)
        u->parent->left = t;
    else
        u->parent->right = t;
    if (t != nullptr)
        t->parent = u->parent;
}

void SuperSearch(int data, Elem* v, int k) {
 

    if (v == nullptr) {
        std::cout << "N";
        return;
    }

    if (v->data == data) {
        std::cout << k;
        return;
    }
 
    if (data < v->data)
        SuperSearch(data, v->left, k + 1);
    else
        SuperSearch(data, v->right, k+1);


}



int main()
{
    Elem* root = nullptr;
    std::ifstream in("input.txt");
    char a;
    int qq;
    while (!in.eof()) {
        in >> a;
        if (a == '+') {
            in >> qq;
            ADD(qq, root);
        }
        if (a == '?') {
            in >> qq;
            SuperSearch(qq, root, One);
        }
        if (a == '-') {
            in >> qq;
            DELETE(qq, root);
        }

        if (a == 'E') {
            break;
        }

   }




    return 0;
}

