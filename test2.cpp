#include <iostream>
#include <string>
using namespace std;

struct Commnu
{
    string name;
    string tel;
    Commnu *next;
};

int main()
{
    Commnu *head = new Commnu;
    cin >> head->name;
    cin >> head->tel;
    head->next = NULL;
    cout << head->name << endl;
    cout << head->tel << endl;
    delete head;
    system("pause");
    return 0;
}
