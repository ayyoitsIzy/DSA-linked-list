#include <iostream>
#include<string.h>
#define range 4
struct node {
    int elem;
    char name[50];
    node *next;
    node *prev;
};

class linkedlist {
private:
    node *head;
    node *tail;
    node *fence;
    int size;

public:
    linkedlist() {
        std::cout << "Linked list initialized\n";
        head = NULL;
        tail = NULL;
        fence = NULL;
        size = 0;
    }

    ~linkedlist() { // Destructor to free memory
        node *current = head;
        while (current != NULL) {
            node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void head_insert() {
        node *newnode = new node;  
        std::cout << "Enter data for new name: ";
        std::cin >> newnode->name;
        std::cout << "Enter data for new score: ";
        std::cin >> newnode->elem;
        
        newnode->next = head;
        newnode->prev = NULL;

        if (head != NULL) {
            head->prev = newnode;
        } else {
            tail = newnode;  
        }
        size ++;
        head = newnode;
    }

   

    void showall() {
        if (head == NULL) {
            std::cout << "List is empty\n";
            return;
        }
        
        fence = head;
        while (fence != NULL) {
            printf("%s %d\n",fence->name,fence->elem);
            fence = fence->next;
        }
        std::cout << "\n";
    }
    void showuntill(int x) {
        if (head == NULL) {
            std::cout << "List is empty\n";
            return;
        }
        
        fence = head;
        for (int i =0 ; i < x ;i++) {
            printf("%s %d\n",fence->name,fence->elem);
            fence = fence->next;
        }
        std::cout << "\n";
    }
    void showat(int count) {
        if (count == 1)
        {
            printf("%d\n",head->elem);
            return;
        }
       
        
        fence = head;
        for (int i = 0; i < count-1; i++)
        {
            fence = fence->next;
            if (fence == NULL){
                printf("out of range\n");
                return;
            }
            
        }
        printf("%d\n",fence->elem);
        
    }
    void removenode(int x){
        node *prev;
        node *next;
        node *context;
        context = fence;
        fence = head;
        if (x == 0)
        {

            head = head->next;
            delete head->prev;
            head->prev = NULL;
            return;
        }
        if (x = size)
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = NULL;
            return;
        }
        if (x > size || x < 0)
        {
            printf("Cant delete!");
            return;
        }
        for (int i = 0; i < x; i++)
        {
         fence = fence->next;
        }
        prev = fence->prev;
        next = fence->next;
        delete fence;
        prev->next = next;
        next->prev = prev;
        size = size-1;
        fence = context;
    }
    void removeptr(node *x) {
        if (x == NULL) {
            std::cout << "Cannot delete a NULL node!" << std::endl;
            return;
        }
    
        if (x == head) {
            head = head->next; 
            if (head!=NULL) head->prev = NULL;
            delete x;
            size--;
            if (size == 0) tail = NULL; 
            return;
        }
    
        if (x == tail) {
            tail = tail->prev;
            if (tail!=NULL) tail->next = NULL;  
            size--;
            return;
        }
                x->next->prev = x->prev;
            x->prev->next = x->next;
        delete x;
        
        size--;
    }


    int get_size(){
        return size;
    }
    void insertbyorder(){
        if (head == NULL)
        {
            head_insert();
            return;
        }
        fence = head;

        node *newnode = new node;  
        std::cout << "Enter data for new name: ";
        std::cin >> newnode->name;
        std::cout << "Enter data for new score: ";
        std::cin >> newnode->elem;
        if (size == 1)
        {
            if (newnode->elem > head->elem )
            {
                head->prev = newnode;
                newnode->prev = NULL;
               newnode->next = head;
               head = newnode;
               
            }else {
                newnode->next = NULL;
                tail->next = newnode;
                newnode->prev = tail;
                tail = newnode;
            }
            size++;
            return;
        }

        
        if (newnode->elem > head->elem)
        {
                 head->prev = newnode;
                newnode->prev = NULL;
               newnode->next = head;
               head = newnode;
               if (size >= range+1)
        {
            removenode(size);
            size--;
        }
              size++;
               return;
        }
        
        for (int i = 0; i < size-1; i++)
        {
            if (newnode->elem <= fence->elem && newnode->elem > fence->next->elem) 
            {
                newnode->prev = fence;
                newnode->next = fence->next;
                fence->next = newnode;
                size++;
                if (size >= range+1)
            {
                removenode(size);
                size--;
            }
                return;
            }

            fence = fence->next;
        }
        newnode->next = NULL;
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
        size++;
        if (size >= range+1)
        {
            removenode(size);
            size--;
        }
        
    }
    void insert(){
        if (head == NULL)
        {
            head_insert();
            return;
        }

        node *newnode = new node;  
        std::cout << "Enter data for new name: ";
        std::cin >> newnode->name;
        std::cout << "Enter data for new score: ";
        std::cin >> newnode->elem;
        if (size == 1)
        {
            if (strcmp(newnode->name,head->name)==0)
            {
                head -> elem = newnode->elem;
                return;
            }
            if (newnode->elem > head->elem )
            {
                head->prev = newnode;
                newnode->prev = NULL;
                newnode->next = head;
                head = newnode;
                size++;
                return;
            }
            if (newnode->elem < head->elem )
            {
                tail->next = newnode;
                newnode->prev = tail;
                newnode->next = NULL;
                tail = newnode;
                size++;
                return;
            }
        }
        fence = head;
        while (fence->next != NULL)
        {
            if (fence == head && newnode->elem > head->elem)
            {
                head->prev = newnode;
                newnode->next = head;
                newnode -> prev = NULL;
                head = newnode;
                size++;
           //     fence = fence->next;
             //   continue;
                

            }
            if (newnode->elem < tail->elem)
            {
              
                   newnode->next = NULL;
                   tail->next = newnode;
                   newnode->prev = tail;
                   tail = newnode;
                   size++;
                 //  fence = fence->next;
                 //  continue;
            }
            if (newnode->elem <= fence->elem && newnode->elem > fence->next->elem) 
            {
                newnode->prev = fence;
                newnode->next = fence->next;
                //fence->next->next->prev = newnode;
                fence -> next ->prev = newnode;

                fence->next= newnode;
                
                fence = newnode->next;
                if (strcmp(fence->name,newnode->name)==0)removeptr(fence);
                size++;
                continue;
            }
           if (strcmp(fence->name,newnode->name)==0)
            {
                removeptr(fence);
            }
            
            fence = fence->next;
           
         }
        if (size >= range+1)
          {
         removeptr(tail);
            }
    
    }

    
};

int main() {
    linkedlist list1;
    //list1.head_insert();
    /*list1.insertbyorder();
    list1.insertbyorder();
    list1.insertbyorder();
    list1.insertbyorder();
    list1.insertbyorder();
    list1.insertbyorder();*/
    list1.insert();
    list1.insert();
    list1.insert();
    list1.insert();
    list1.showall();
    list1.insert();
    list1.insert();
    list1.insert();
    list1.showall();

    //list1.showuntill(2);
    printf("%d",list1.get_size());


    return 0;
}
