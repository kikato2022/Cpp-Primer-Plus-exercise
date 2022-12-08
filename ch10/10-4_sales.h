namespace SALES{
    const int QUARTERS = 4;
    class Sales{
    private:
        double sales[QUARTERS];
        double average;
        double max;
        double min;
        
    public:
        // copies the lesser of 4 or n items from the array ar
        // to the sales memeber of s and computes and store the
        // average, maximum, and minimum values of the entered items;
        // remaining elements of sales, if any, set to 0;
        Sales(const double ar[], int n);

        Sales();

        double * sale_arr() const{
            static double sale_arr[QUARTERS];
            for(int i=0; i<QUARTERS; i++){
                sale_arr[i] = sales[i];
            }
            return sale_arr;
        }

        void show() const;
    };

}