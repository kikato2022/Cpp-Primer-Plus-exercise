struct Customer{
    char fullname[35];
    double payment;
};

class Customer_Stack{

private:
    static const int MAX = 20;
    Customer stack[MAX];
    int top;
    double total;

public:

    Customer_Stack();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const Customer & customer);   // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Customer & customer);      // pop into item

};