typedef int Item;

class List{

private:
    static const int MAX = 20;
    Item list[MAX];
    int tail;
    
    

public:

    List();
    void add(const Item & item);
    bool isempty() const;
    bool isfull() const;

    // 
    void set(const Item & item);
    void add_op(const Item & item);
    void minus_op(const Item & item);
    
    void show() const;

    //
    void visit( void(*pf)(Item & ));
};