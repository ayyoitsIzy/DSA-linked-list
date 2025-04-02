#include <iostream>
struct node
{
    int elem;
    int expo;
    node *prev;
    node *next;
};
class polycat{
private:
node *head;
node *tail;
node *fence;
int size;

public:
polycat() {
    std::cout << "polynomial initialized\n";
    head = NULL;
    tail = NULL;
    fence = NULL;
    size = 0;
}

~polycat() { 
    node *current = head;
    while (current != NULL) {
        node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void inserthead(){
node *newnode = new node;
std::cout << "Enter Coefficient: ";
std :: cin >> newnode->elem ;
std::cout << "Enter exponent: ";
std :: cin >> newnode->expo ;
if (head == NULL)
{
    head = newnode;
    tail = newnode;
    newnode->next=NULL;
    newnode->prev=NULL;
    size++;
    return;
}/*else{
    head->prev=newnode;
    newnode->next=head;
    head = newnode;
    newnode->prev=NULL;
    size++;
    return;
}*/
}
void showequation(){
    node *context = fence;
    fence = head;
    printf("%dx^%d",fence->elem,fence->expo);
        fence = fence->next;
    while (fence != NULL)
    {
       if (fence->elem > 0)
       {
        printf(" +%dx^%d",fence->elem,fence->expo);
            fence = fence->next;
       }else{
        printf(" %dx^%d",fence->elem,fence->expo);
        fence = fence->next;
       }
    }
    printf("\n");
    fence = context;
}
void insert(){

if (head == NULL){inserthead();return;}



node *newnode = new node;
printf("Input co-efficient : ");std::cin >> newnode->elem;
printf("Input Exponent : ");std::cin >> newnode->expo;

if (size == 1)
{
    if ( newnode->expo == head->expo ){
        head -> elem = head->elem + newnode->elem;
        delete newnode;
        return;
    }

    if ( newnode->expo > head->expo )
    {
        newnode -> next = head;
        newnode ->prev = NULL;
        head -> prev = newnode;
        head = newnode;
       size++;
       return;
    }
    if ( newnode->expo < head->expo )
    {
        newnode -> next = NULL;
        newnode ->prev = tail;
        tail -> next = newnode;
        tail = newnode;
       size++;
       return;
    }
}
fence = head;
if (head -> expo < newnode->expo )
{
    head->prev = newnode;
    newnode->prev = NULL;
    newnode->next = head;
    head = newnode;
    size++;
    fence = fence->next;
    return;
}
if (tail -> expo > newnode->expo )
{
    tail->next = newnode;
    newnode->prev = tail;
    newnode->next = NULL;
    tail = newnode;
    size++;
    fence = fence->next;
    return;
}
while (fence->next != NULL)
{
   
 if (fence -> expo > newnode->expo && fence ->next->expo < newnode->expo  )
 {
    newnode->prev = fence;
    newnode->next = fence->next;
    fence -> next ->prev = newnode;
    fence->next= newnode;             
    fence = newnode->next;
    size++;
    return;
 }
 if (newnode->expo == fence->expo){fence -> elem += newnode->elem;delete newnode;return;}
 fence = fence->next;
}
fence = head;
}
void insert2(node* newnode){
    
    if (head == NULL){inserthead();return;}
    fence = head;
    if (head -> expo < newnode->expo )
{
    node *greater = new node;
    head -> prev = greater;
    greater->next = head;
    greater -> prev = NULL;
    greater->elem = newnode->elem;
    greater -> expo = newnode -> expo;
    head = greater;
    size++;
    return;
}
if (tail -> expo > newnode->expo )
{
    node *lesser = new node;
    tail -> next = lesser;
    lesser->prev = tail;
    lesser -> next = NULL;
    lesser->elem = newnode->elem;
    lesser -> expo = newnode -> expo;
    tail = lesser;
    size++;

    return;
}
    while (fence != NULL)
    {
       
     if (fence -> expo > newnode->expo && fence ->next->expo < newnode->expo  )
     {
        node *greater = new node;

        greater->prev = fence;
    greater->next = fence->next;
    greater->elem = newnode->elem;
    greater->expo= newnode->expo;

    fence -> next ->prev = greater;
    fence->next= greater;             
    fence = greater->next;
    size++;
    return;
     }
     if (newnode->expo == fence->expo){fence->elem += newnode->elem;return;}
     fence = fence->next;
    }
    }
node* getfencenode(){return fence;}   
void fencetohead(){fence = head;}
void fencemove(){fence = fence->next;}
node* nextfence(){return fence->next;}
void multiply(node *a){
    fence = head;
    while (fence!=NULL)
    {
     fence-> expo += a->expo;
     fence->elem = fence->elem*a->elem;
     fence = fence->next;
    }
}
void test(){printf("\nexpo = %d coef = %d\n",fence->expo,fence->elem);}
int getsize(){return size;}
};

void addition(polycat a,polycat b){
    a.fencetohead();// o 1
    b.fencetohead();// o 1

while (b.getfencenode() != NULL)// o (n(b))
{
    b.test();
    a.insert2(b.getfencenode());// o (n(a))
    a.showequation();// o (n(a)) but not nessesary for calculation
    b.fencemove();
}

}//o(n(b)n(a))
void polymultiply(polycat a,polycat b){
a.fencetohead();
b.fencetohead();
while (b.getfencenode() != NULL)// o (n(b))
{
    b.test();
    a.multiply(b.getfencenode());// o (n(a))
    a.showequation();// o (n(a)) but not nessesary for calculation
    b.fencemove();
}

}//o(n(b)n(a))


int main(){
polycat equa1;
polycat equa2;
equa1.insert();
equa1.insert();
equa1.insert();
equa1.showequation();
equa2.insert();
equa2.insert();
equa2.insert();
equa2.showequation();


//addition(equa1,equa2);
polymultiply(equa1,equa2);
//equa1.showequation();

//equa1.inserthead();
//equa1.showequation();
/*
equa1.insert();
equa1.showequation();
printf("%d",equa1.getsize());
equa1.insert();
equa1.showequation();
printf("%d",equa1.getsize());
equa1.insert();
equa1.showequation();
equa1.insert();
equa1.showequation();
equa1.insert();
equa1.showequation();
equa1.insert();
equa1.showequation();*/

}