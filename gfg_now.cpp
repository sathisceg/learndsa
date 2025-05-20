#include <bits/stdc++.h>


using namespace std;


class Product{
    public:
        int id;
        string name;
        
        Product(int _id,string _name):id(_id),name(_name){}
        
        virtual string getProductName()=0;
        virtual int getProductId()=0;
        
        virtual ~Product()=default;
};


class Mobile:public Product{
    
    public:
        
        Mobile(int _id,string _name):Product(_id,_name){}
        
        string getProductName(){
            return name;
        }
        
        int getProductId(){
            return id;
        }
};

class Laptop:public Product{
  
  public:
    
    Laptop(int _id,string _name):Product(_id,_name){}
    
    string getProductName(){
        return name;
    }
    
    int getProductId(){
        return id;
    }
    
    friend ostream& operator<<(ostream& out,Laptop& obj){
        out<<obj.getProductId()<<" "<<obj.getProductName();
        return out;
    }
};


template<typename T>
class Node{
    public:
        T data;
        Node<T>* next;
        
        Node(T _data):data(_data),next(nullptr){}
        
        T& getData(){
            return data;
        }
        
        Node<T>* getNext(){
            return next;
        }
};

template<typename T>
class List{
  public:
    Node<T> *head;
    
    List():head(nullptr){}
    
    Node<T>* push(T _data){
        Node<T>* temp=new Node<T>(_data);
        temp->next=head;
        head=temp;
        return head;
    }
    
    void print(){
        Node<T>* temp=head;
        
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->getNext();
        }
    }
    
};




int main() {

    int a=10,b=20,c=30;
    
    List<int> l1;
    l1.push(a);
    l1.push(b);
    l1.push(c);
    l1.print();
    
    cout<<endl;
    
    float fa=10.01,fb=20.02,fc=30.03;
    
    List<float> f1;
    f1.push(fa);
    f1.push(fb);
    f1.push(fc);
    f1.print();  
    
    cout<<endl;
    
    Laptop p1(100,"prod1");
    Laptop p2(200,"prod2");

    List<Laptop> prodlist;
    prodlist.push(p1);
    prodlist.push(p2);
    
    prodlist.print();
   
    
    
    
    
    
    
    
    
    
    
    
    
    
    
   





    cout<<endl;
    cout << "Hello Geek!";
    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////















typedef int (*addfunction)(int,int);

int add(int a,int b){
    return a+b;
}

void practice(){
    
    
    addfunction addptr=add;
    
    int res = addptr(10,20);
    
    cout<<res<<" ";
    
    Product *p1 =new Mobile(100,"moto");
    Product *p2 =new Laptop(200,"hp");
    

    cout<<p1->getProductName()<<" ";
    cout<<p2->getProductName()<<" ";
}
































