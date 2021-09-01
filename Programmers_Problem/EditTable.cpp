#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct NODE 
{
    int Data;
    NODE *Prev;
    NODE *Next;
    NODE(int D) {
        Data = D;
        Prev = NULL;
        Next = NULL;
    }
};

struct LinkedList
{
    NODE *Head;
    NODE *Tail;

    LinkedList() : Head(NULL), Tail(NULL) {}
    void Insert(int Data_);
    NODE *Erase(NODE *Node);
    void Restore(NODE *Node);
};

void LinkedList::Insert(int Data_)
{
    if (Head == NULL)
    {
        NODE *newNode = new NODE(Data_);
        Head = newNode;
        Tail = newNode;
    }
    else{
        NODE *newNode = new NODE(Data_);
        newNode->Prev = Tail;
        Tail->Next = newNode;
        Tail = Tail->Next;
    }
}

NODE* LinkedList::Erase(NODE *Node)
{
    if (Node == Head)
    {
        Head = Node->Next;
        Node->Next->Prev = NULL;
        return Node->Next;
    }
    else if (Node == Tail) {
        Tail = Node->Prev;
        Node->Prev->Next = NULL;
        return Node->Prev;
    }
    else {
        Node->Prev->Next = Node->Next;
        Node->Next->Prev = Node->Prev;
        return Node->Next;
    }
}
void LinkedList::Restore(NODE *Node)
{
    if (Node->Prev == NULL)
    {
        Head = Node;
        Node->Next->Prev = Node;
    }
    else if (Node->Next == NULL)
    {
        Tail = Node;
        Node->Prev->Next = Node;
    }
    else
    {
        Node->Prev->Next = Node;
        Node->Next->Prev = Node;
    }
}
 
stack<NODE*> Delete;

LinkedList *List;
 
void Make_LinkedList(int N)
{
    List = new LinkedList();
    for (int i = 0; i < N; i++) List->Insert(i);
}
 
string Solve(int N, int K, vector<string> Cmd)
{
    NODE *Iter = List->Head;
    for (int i = 0; i < K; i++) Iter = Iter->Next;
 
    for (int i = 0; i < Cmd.size(); i++)
    {
        string Str = Cmd[i];
        if (Str[0] == 'U')
        {
            string SX = Str.substr(2);
            int X = stoi(SX);
            for (int i = 0; i < X; i++) Iter = Iter->Prev;
        }
        else if (Str[0] == 'D')
        {
            string SX = Str.substr(2);
            int X = stoi(SX);
            for (int i = 0; i < X; i++) Iter = Iter->Next;
        }
        else if (Str[0] == 'C')
        {
            Delete.push(Iter);
            Iter = List->Erase(Iter);
        }
        else
        {
            NODE *Z = Delete.top();
            Delete.pop();
            List->Restore(Z);
        }
    }
    
    string Result = "";
    for (int i = 0; i < N; i++) Result += 'O';
    while (Delete.empty() == false)
    {
        NODE *Temp = Delete.top();
        Delete.pop();
 
        int Idx = Temp->Data;
        Result[Idx] = 'X';
    }
    return Result;
}
 
string solution(int n, int k, vector<string> cmd)
{
    string answer = "";
    Make_LinkedList(n);
    answer = Solve(n, k, cmd);
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << solution(8, 2, {"D 2","C","U 3","C","D 4","C","U 2","Z","Z"}) << "\n";
    cout << solution(8, 2, {"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"}) << "\n";
    return 0;
}

