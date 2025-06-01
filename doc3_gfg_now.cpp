#include <bits/stdc++.h>

using namespace std;



class person{
    
    private:
        int m_id;
        int m_age;
        
    public:
        person()=default;
        
        person(int id,int age):m_id(id),m_age(age){}
        
        person(const person& obj){
            
            m_id=obj.m_id;
            m_age=obj.m_age;
        }
        
        person& operator=(person& obj){
            
            m_id=obj.m_id;
            m_age=obj.m_age;
            
            return *this;
        }
        
        person(person&& obj){
            
            m_id=obj.m_id;
            m_age=obj.m_age;
            
            obj.m_id=0;
            obj.m_age=0;
        }
        
        person& operator=(person&& obj){
            
            m_id=obj.m_id;
            m_age=obj.m_age;
            
            obj.m_id=0;
            obj.m_age=0;
            
            return *this;
        }
        
        
        
        int getId() const {
            return m_id;
        }
        
        int getAge() const {
            return m_age;
        }
        
        friend ostream& operator<<(ostream& out, person& obj){
            
            out<<obj.m_id<<" "<<obj.m_age;
            
            return out;
        }
};






typedef int (*addfunction)(int,int);

int add(int a,int b){
    
    return a+b;
}




template<typename T>
class Node{
    
    public:
        T data;
        Node<T>* next;
        
        Node():next(nullptr){}
        
        Node(T _data):data(_data),next(nullptr){}
        
        T& getData(){
            return data;
        }
        
        Node<T>* getNext(){
            return next;
        }
        
        void setData(T _data){
            data=_data;
        }
        
        void setNext(Node<T>* _next){
            next=_next;
        }
};


template<typename T>
class Stack{
    public:
        Node<T>* root;
        
        Stack():root(nullptr){}
        
        
        void push(T _data){
            
            Node<T>* temp=new Node<T>(_data);
            temp->next=root;
            root=temp;
        }
        
        void print(){
            
            Node<T>* temp=root;
            
            while(temp!=nullptr){
                cout<<temp->getData()<<" ";
                temp=temp->getNext();
            }
        }
        
};





template<typename T>
class Smartptr{
    public:
        T* ptr;
        
        Smartptr(T* _ptr):ptr(_ptr){}
        
        T& operator*(){
            return *ptr;
        }
        
        T* operator->(){
            return ptr;
        }
        
        ~Smartptr(){
            delete ptr;
        }
        
};




template<int  n>
struct fact{
  enum { val=2*fact<n-1>::val };  
};

template<>
struct fact<0>{
  enum { val=1 };  
};



void print(){
    cout<<"last print"<<endl;
}

template<typename TYPE,typename... TYPES>
void print(TYPE var1,TYPES... var2){
    
    cout<<var1<<" ";
    
    print(var2...);
}



class mycompare{

    public:
        int operator()(const person &p1,const person &p2){
            return p1.getAge() > p2.getAge();
        }
};


class mycompareptr{

    public:
        int operator()(const person* p1,const person *p2){
            return p1->getAge() > p2->getAge();
        }
};


class Base{
  public:
  Base(){
      cout<<"base constructor"<<endl;
  }
//   virtual void funBase()=0;
  virtual ~Base();
};

Base::~Base(){
    cout<<"pure base destructor"<<endl;
}

class Derived:public Base{
  public:
  Derived(){
      cout<<"Derived constructor"<<endl;
  }
  
  ~Derived(){
      cout<<"Derived destructor"<<endl;
  }
  
};



class Int{
    public:
        int val;
        
        Int(int _val):val(_val){}
        
        Int& operator++(){
            val++;
            return *this;
        }
        
        Int operator++(int dummy){
            Int temp =*this;
            ++(*this);
            return temp;
        }
        
        void print(){
            cout<<val;
        }
};


template<typename T>
void addVal(vector<T>& inp){
    T res=0;
    
    for(T i:inp){
        res+=i;
    }
    
    cout<<res<<endl;
}

template<>
void addVal<string>(vector<string>& inp){
    
    int res=0;
    
    for(auto s:inp){
        for(int i=0;i<s.size();i++){
            res+=(s[i]-'a');
        }
    }
    
    cout<<res<<endl;
}

// #define my_sizeof(x) ((&x + 1) - &x)
// #define my_sizeof(x) ((char *)(&x + 1) - (char *)&x)

#define my_size(x) ((char*)(&x+1)-(char*)&x);


int main() {

   





    cout << "\nHello Geek!";
    return 0;
}







void practice1(){
    
    person p1(12,24);
    person p2(14,28);

    cout<<p1;
    cout<<p2;
}

void practice2(){
    
    addfunction addref =add;
    cout<<addref(1,2);
  
}

void practice3(){
    
      
    Node<int>* n1=new Node<int>(10);
    Node<int>* n2=new Node<int>(20);
    Node<int>* n3=new Node<int>(30);
    
    cout<<n1->getData();
    cout<<n2->getData();

    vector<Node<int>*> vec1;
    vec1.push_back(n1);
    vec1.push_back(n2);
    vec1.push_back(n3);
    
    cout<<endl;
   
    
    for(auto it:vec1){
        cout<<it->getData()<<" ";
    }
    
    cout<<endl;
    cout<<endl;


    Node<float>* fn1=new Node<float>(10.5);
    Node<float>* fn2=new Node<float>(20.5);
    Node<float>* fn3=new Node<float>(30.5);
 
    
    cout<<fn1->getData();
    cout<<fn2->getData();
    
   

    vector<Node<float>*> vec2;
    vec2.push_back(fn1);
    vec2.push_back(fn2);
    vec2.push_back(fn3);
    
    cout<<endl;
    
    for(auto it:vec2){
        cout<<it->getData()<<" ";
    }
    
}



void practice4(){

    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    
    s1.print();
    cout<<endl;
    
    Stack<person> s2;
    s2.push(person(100,1000));
    s2.push(person(200,2000));
    
    s2.print();
    
    Smartptr<int> sp(new int());
    *sp=20;
    cout<<"smart "<<*sp<<endl;
  
}


void practice5(){
    
    
    
    unique_ptr<person> up1=make_unique<person>(100,25);
    cout<<"unique pointer: id  "<<up1->getId()<<endl;
    cout<<"unique pointer: age "<<up1->getAge()<<endl<<endl;

    shared_ptr<person> sp1=make_shared<person>(200,26);
    cout<<"shared pointer: id  "<<sp1->getId()<<endl;
    cout<<"shared pointer: age "<<sp1->getAge()<<endl<<endl;
    
    weak_ptr<person> wp1=sp1;
    // wp1=sp1.lock();
    
    cout<<"weak pointer: id  "<<(wp1.lock())->getId()<<endl;
    cout<<"weak pointer: count  "<<sp1.use_count()<<endl;
    
    
   cout << fact<4>::val << endl;
   print(1,2,3.14,"qwerty");

    
}

void practice6(){
    


    //comparator function and copy constructor need to have const

    person p1(1,11);
    person p2(2,22);
    person p3(3,33);
    
    priority_queue<person,vector<person>,mycompare> pqmin;
    
    // pqmin.push(person(1,11));
    // pqmin.push(person(2,22));
    // pqmin.push(person(3,33));


    pqmin.push(p1);
    pqmin.push(p2);
    pqmin.push(p3);

    while(!pqmin.empty()){
        
        auto temp=pqmin.top();
        pqmin.pop();
        cout<<temp<<endl;
        
    }
    
    
    priority_queue<person*,vector<person*>,mycompareptr> pqminptr;
    
    person* p1ptr= new person(1,11);
    person* p2ptr= new person(2,22);
    person* p3ptr= new person(3,33);
    
    pqminptr.push(p1ptr);
    pqminptr.push(p2ptr);
    pqminptr.push(p3ptr);
       
   
    while(!pqminptr.empty()){
        
        auto temp=pqminptr.top();
        pqminptr.pop();
        
        cout<<temp->getAge()<<" "<<temp->getId()<<endl;
    }


    Base* b=new Derived();
    delete b;
   

    Int a(1);
    a++;
    a.print();
    
    vector<int> intVec({1,2,3});
    vector<string> strVec({"ab","ef","gh"});
    
    addVal<int>(intVec);
    addVal(strVec);
    
    
    int x=10;
    int s=my_size(x);
    cout<<s<<endl;
    
    
    const volatile int x=10;
    
    int* ptrx = (int*)&x;
    
    cout<<x<<" ";
    *ptrx=100;
    cout<<x<<" ";
  
    
}


#include <bits/stdc++.h>


using namespace std;


template<typename T>
class Node{
    public:
        T data;
        Node<T>* next;
        
        Node():next(nullptr){}
        
        Node(T _data):data(_data),next(nullptr){}
        
        T& getData(){
            return data;
        }
        
        Node<T>* getNext(){
            return next;
        }
        
        void setNext(Node<T>* node){
            this->next=node;
        }
        
        friend ostream& operator<<(ostream& out,Node node){
            out<<node.data;
            return out;
        }
        
        
};

template<typename T>
class List{
    public:
    Node<T>* head;
    
    List():head(nullptr){}
    
    Node<T>* push(T data){
        
        Node<T>* newnode = new Node<T>(data);
        newnode->setNext(head);
        head=newnode;
        
        return head;
    }
    
    Node<T>* getHead(){
        return head;
    }
    
};

template<typename T>
void print(List<T> l1){
    
    Node<T>* temp=l1.getHead();
    
    while(temp!=nullptr){
        cout<<temp->getData()<<" ";
        temp=temp->getNext();
    }
}






int main() {
    
    // Node<int> n1(10);
    // cout<<n1;
    
    List<int> l1;
    l1.push(100);
    l1.push(200);
    
    print<int>(l1);
    cout<<endl;
    
    List<float> l2;
    l2.push(100.4);
    l2.push(200.6);
    
    print<float>(l2);
    
    



    cout<<endl;
    cout << "Hello Geek!";
    return 0;
}











