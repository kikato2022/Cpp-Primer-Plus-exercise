
class Plorg{

private:
    char name[20];
    int CI;

public:

    Plorg(const char * sname = "Plorga", int ci = 50);

    void setCI(int ci){
        CI = ci;
    }
    void show() const;
};