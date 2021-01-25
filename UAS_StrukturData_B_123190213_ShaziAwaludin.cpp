#include <iostream>
#include <malloc.h>
#include <string.h>

using namespace std;
typedef struct node *typeptr;

struct node
{
    int angka;
    typeptr kiri, kanan;
};

typeptr root, p, b;

void buatPohon()
{
    typeptr ptb;
    ptb = NULL;
    root = ptb;
}

int ptbKosong()
{
    if (root == NULL)
        return (true);
    else
        return (false);
}

char *hapusDuplikasi(char str[], int len)
{
    int idx = 0;
    for (int i = 0; i < len; i++)
    {
        int j;
        for (j = 0; j < i; j++)
            if (str[i] == str[j])
                break;
        if (j == i)
            str[idx++] = str[i];
    }

    return str;
}

void sisipnode(std::string &nim)
{
    // parsing nim jadi satuan char
    // satu node satu digit.
    char ntemp[10];
    strcpy(ntemp, nim.c_str());
    nim = hapusDuplikasi(ntemp, (sizeof(ntemp) / sizeof(ntemp[0])));
    // buat node berdasar string yang telah diparsing
    for (int i = 0; i < nim.length(); i++)
    {
        typeptr node_baru;
        node_baru = (node *)malloc(sizeof(node));
        node_baru->angka = nim[i] - '0';
        node_baru->kiri = NULL;
        node_baru->kanan = NULL;
        if (ptbKosong())
            root = node_baru;
        else
        {
            b = root;
            p = root;
            //mencari tempat untuk menyisipkan node
            while (p != NULL && ((int)nim[i] - '0') != b->angka)
            {
                b = p;
                if (((int)nim[i] - '0') < p->angka)
                    p = b->kiri;
                else
                    p = b->kanan;
            }
            if (((int)nim[i] - '0') == b->angka)
                cout << "\n\nNode " << nim << " sudah ada !\n\n";
            else
            {
                if (((int)nim[i] - '0') < b->angka)
                    b->kiri = node_baru;
                else
                    b->kanan = node_baru;
            }
        }
    }
}

void preorder(typeptr root)
{
    if (root != NULL)
    {
        cout << " " << root->angka;
        preorder(root->kiri);
        preorder(root->kanan);
    }
}

void inorder(typeptr root)
{
    if (root != NULL)
    {
        inorder(root->kiri);
        cout << " " << root->angka;
        inorder(root->kanan);
    }
}
void postorder(typeptr root)
{
    if (root != NULL)
    {
        postorder(root->kiri);
        postorder(root->kanan);
        cout << " " << root->angka;
    }
}

void cetak()
{
    cout << "\nPre-order : ";
    preorder(root);
    cout << "\nIn-order : ";
    inorder(root);
    cout << "\nPost-order: ";
    postorder(root);
    return;
}

int main()
{
    string str = "123190123";
    sisipnode(str);

    cetak();
    return 0;
}