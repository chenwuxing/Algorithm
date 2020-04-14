#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node
{
    int key;
    string val;

    Node *left,*right;
    int N;
    Node(int key_para,string value,int num)
    {
        key = key_para;
        val = value;
        N = num;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
private:
    Node *root;

private:
    Node* min(Node *x)
    {
        if(x->left == NULL)
            return x;
        return min(x->left);
    }

    Node* floor(Node *x,int key)
    {
        if(x == nullptr)
            return nullptr;
        if(key < x->key)
            return floor(x->left,key);
        if(key == x->key)
            return x;
        Node *t = floor(x->right,key);
        if(t != nullptr)
            return t;
        else
            return x;
    }

    Node *select(Node *x,int k)
    {
        if(x == nullptrl)
            return nullptr;
        int t = size(x->left);
        if(t > k)
            return select(x->left,k);
        else if(t < k)
            return select(x->right,k-t-1);
        else
            return x;
    }

    int rank(int key,Node *x)
    {
        // 返回以x为根节点的子树中小于x->key的键的数量
        if(x == nullptr)
            return 0;
        if(key < x->key)
            return rank(key,x->left);
        else if(key > x->key)
            return 1 + size(x->left) + rank(key,x->right);
        else
            return size(x->left);
    }

    Node* deleteMin(Node* x)
    {
        if(x->left == nullptr)
            return x->right;
        x->left = deleteMin(x->left);
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }

    // 删除任意节点
    Node* delete(Node *x,int key)
    {
        if(x == nullptr)
            return nullptr;
        if(key < x->key)
            x->left = delete(x->left,key);
        else if(key > x->key)
            x->right = delete(x->right,key);
        else
        {
            if(x->right == nullptr)
                return x->right;
            if(x->left == nullptr)
                return x->right;
            Node *t = x;
            x = min(t->right);
            x->right = deleteMin(t->right);
            x->left = t->left;
        }
        x->N = size(x->left) + size(x->right);
        return x;
    }

    void keys(Node *x,queue<int> &que,int lo,string hi)
    {
        if(x == nullptr)
            return nullptr;
        if(x->key < lo)
            keys(x->left,que,lo,hi);
        if(x->key >= lo && x->key <= hi)
            que.push(x->key);
        if(x->key < hi)
            keys(x->right,que,lo,hi);
    }


public:

    BST(Node *head)
    {
        root = head;

    }

    //BST树节点总数
    int size()
    {
        return size(root);
    }

    int size(Node *x)
    {
        if(x == nullptr)
            return 0;
        else
            return x->N;
    }

    // 查找
    string get(int key)
    {
        return get(root,key);
    }

    string get(Node *x,int key)
    {
        if(x == nullptr)
            return NULL;
        if(key < x->key)
            return get(x->left,key);
        else if(key > x->key)
            return get(x->right,key);
        else
            return x->val;
    }

    // 插入
    void put(int key,string value)
    {
        root = put(root,key,value);
    }

    Node* put(Node *x,int key,string value)
    {
        if(x == nullptr)
        {
            Node *res = new Node(key,value,1);
            return res;

        }
        if(key < x->key)
            x->left = put(x->left,key,value);
        else if(key > x->key)
            x->right = put(x->right,key,value);
        else
            x->val = value;
        x->N  = size(x->left) + size(x->right) + 1;
        return x;
    }

    int min()
    {
        return min(root)->key;
    }

    int floor(int key)
    {
        Node *x = floor(root,key);
        if(x == nullptr)
            return NULL;
        return x->key;
    }

    //给出给定排名的键
    int select(int k)
    {
        return select(root,k)->key;
    }

    // 给出给定键的排名
    int rank(int key)
    {
        return rank(key,root);
    }

    // 删除最小节点
    void deleteMin()
    {
        root = deleteMin(root);
    }

    void delete()
    {
        root = delete(root,key);
    }

    //遍历范围
    queue<int> keys(int lo,int hi)
    {
        queue<int> que = new queue<int>;
        keys(root,que,lo,hi);
        return que;
    }
};


int main()
{
    Node *head = new Node(6,"root",1);
    BST root(head);
    root.put(1,"apple");
    root.put(9,"banana");
    string res = root.get(9);
    cout<<res<<endl;
    cout<<root.size()<<endl;



}