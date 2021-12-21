#include <iostream>

using namespace std;

//clasa abstracta
class Figura{
    
    public:
    
    //functie virtuala specifica clase abstracte
       virtual double getArea() = 0;
       virtual double getPerimeter() = 0;
};


class Rectangle: public Figura{
    private:
        int* width;
        int height;

    public:

        //Sterge copy constructor-ul, nu exista.
        //Rectangle(const Rectangle& rect) = delete;

        // Sterge copy assignment
        //Rectangle& operator = (const Rectangle&) = delete;

        Rectangle(int width, int height) {
            this->width = new int;
            *this->width = width;
            this->height = height;
        }

//creem copy constructorul nostru
  Rectangle(const Rectangle& rect) {
            width = new int;
            *width = *(rect.width); //VALOAREA
            height = rect.height;
        }

        int getWidth() {
            return *width;
        }

        int getHeight() {
            return height;
        }
        void setWidth(int width) {
            *this->width = width;
        }

        void setHeight(int height) {
            this->height = height;
        }

        double getArea(){
            return getHeight() * getWidth();
        }

         double getPerimeter(){
            return 2 * (getHeight() + getWidth());
        }
        
};

class Circle: public Figura{
    private:
        int r;

    public:

        //Sterge copy constructor-ul, nu exista.
        Circle(const Circle& circle) = delete;

        // Sterge copy assignment
        Circle& operator = (const Circle&) = delete;

        Circle(int r) : r(r){}
         
        int getR() {
            return r;
        }
        void setR(int r) {
             this->r = r;
        }

        double getArea(){
            return 3.14 * getR() * getR();
        }

        double getPerimeter(){
            return 2 * 3,14 * getR();
        }
};

int main(){

    Rectangle r1(4,9);
    Rectangle r2 = r1;

    cout << "Rectangle1: H = " << r1.getHeight() << ", W = " << r1.getWidth() << endl;
    cout << "Perimenter: " << r1.getPerimeter() << endl << "Area = " << r1.getArea() << endl;
    cout << endl;
    cout << "Rectangle12 H = " << r2.getHeight() << ", W = " << r2.getWidth() << endl;
    cout << "Perimenter: " << r2.getPerimeter() << endl << "Area = " << r2.getArea() << endl;
    cout << endl;
    

    r2.setWidth(15);
    
    cout << "After wight change" << endl;
    cout << "Rectangle1: H = " << r1.getHeight() << ", W = " << r1.getWidth() << endl;
    cout << "Perimenter: " << r1.getPerimeter() << endl << "Area = " << r1.getArea() << endl;
    cout << endl;
    cout << "Rectangle12 H = " << r2.getHeight() << ", W = " << r2.getWidth() << endl;
    cout << "Perimenter: " << r2.getPerimeter() << endl << "Area = " << r2.getArea() << endl;
    cout << endl;

    Circle c(5);
    //Circle c2 = c;

    cout << "Circle: R = " << c.getR()  << endl;
    cout << "Perimenter: " << c.getPerimeter() << endl << "Area = " << c.getArea() << endl;
    //cout << "Circle: R2 = " << c2.getR()  << endl;
    //cout << "Perimenter: " << c2.getPerimeter() << endl << "Area = " << c2.getArea() << endl;
    //cout <<endl << endl;

    //c2.setR(7);

    //cout << "After r has been changed" << endl;
    //cout << "Circle: R = " << c.getR()  << endl;
    //cout << "Perimenter: " << c.getPerimeter() << endl << "Area = " << c.getArea() << endl;
    //cout << "Circle: R2 = " << c2.getR()  << endl;
    //cout << "Perimenter: " << c2.getPerimeter() << endl << "Area = " << c2.getArea() << endl;
    return 0;
}