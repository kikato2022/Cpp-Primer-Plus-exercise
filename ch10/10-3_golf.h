// golf.h

class Golf{
private:
    static const int Len = 40;
    char fullname[Len];
    int handicap;

public:
    Golf(){
        fullname[0] = '\0';
        handicap = 0;    
    }
    Golf(const char * name, int hc);
    void set_handicap(int hc);
    void show() const;
};


// interactive version:
//  function solicits name and handicap from user
//  and sets the members of g to the values entered
//  returns 1 if name is entered, 0 if name is empty string
int setgolf(Golf & g);