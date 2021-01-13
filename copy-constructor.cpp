#include <iostream>

using namespace std;

class Line {
    private:
        int *ptr;

    public:
        // constructor
        Line(int len);

        // copy constructor, const reference since the address of the obj
        // never changes
        Line(const Line &obj);

        // destructor
        ~Line(void);

        int getLength(void);
};

//using Line::Line;
//using Line::~Line;
//using Line::getLength;
//using Line::display;

// define constructor
Line::Line(int len) {
    cout << "Normal constructor allocating ptr" << endl;
    ptr = new int;
    *ptr = len;
}

// define copy constructor
Line::Line(const Line &obj) {
    cout << "Copy constructor allocating ptr" << endl;
    ptr = new int; // this ptr is for the copy of obj
    *ptr = *(obj.ptr);
}

// define destructor
Line::~Line(void) {
    cout << "Destructor freeing ptr memory" << endl;
    delete ptr;
}

int Line::getLength(void) {
    return *ptr;
}

void display(Line &obj) {
    cout << "Length of line: " << obj.getLength() << endl;
}

int main() {
    Line line(10);
    display(line);
    cout << "After display, right before return" << endl;
}



