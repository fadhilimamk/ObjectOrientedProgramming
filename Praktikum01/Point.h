class Point {
    // Constructor
    // Set titik mula-mula ke (0, 0)
    public: Point();
    // Getter
    int getAbsis();
    int getOrdinat();
    // Setter
    void setAbsis(int x);
    void setOrdinat(int y);
    void print(); // print absis, kemudian ordinat dengan memanfaatkan Printer
    private: int x, y; // abscissa and ordinate
};
