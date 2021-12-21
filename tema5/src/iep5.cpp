// path -> cd /mnt/c/Users/dumit/Desktop/CTI_anIV_2021-2022/semI/IEP/tema5
// cmake src/
// make
// ./recangle
#include <iostream>

using namespace std;

class Rectangle{
    private:
        int length;
        int width; 

    public:
        //constructor
        Rectangle(int length, int width){
            this->length = length;
            this->width = width;
        }
        // default copy constructor
        Rectangle(){}

        //copy assigment operator
       Rectangle& operator = (const Rectangle& r) {	
		//check self-assigment
		if(this == &r){
            //ne asiguram ca copiem toate partile obiectului 
            length = r.length;
            width = r.width;
		}		
            return *this;
        }

        int getLength() {
            return length;
        }

        int getWidth() {
            return width;
        }

        void setLength(int length) {
            this->length = length;
        }

        void setWidth(int width) {
            this->width = width;
        }

        int calculate(){
            return getLength()*getWidth(); 
        }
        
};

class Parallelepiped: public Rectangle{

    private:
        int height;

    public:
    //constructor
    Parallelepiped(int height, int length, int width): Rectangle(length, width){
        this->height = height;
    }

    //in copy constructor invocam copy constructorul clasei de basa
    Parallelepiped(const Parallelepiped& p):Rectangle(p), height(p.height){}

    //copy assigment operator
    Parallelepiped& operator = (const Parallelepiped& p){
	//check self-assigment
		if(this == &p){
        	//inform the base class to copy its data memebers
        	Rectangle::operator=(p);
        	height=p.height;
		}
        return *this;
    }
    
    int getHeight(){
        return height;
    }

    void setHeight(int height){
        this->height = height;
    }

    int calculate(){
        return getHeight() * getLength() * getWidth();
    }

};


int main(){

    Rectangle r1(4, 6);
    Rectangle r2;
    //copy assigment
    r2 = r1;

    Parallelepiped p1(5, 8, 2);
    //copy constructor
    Parallelepiped p2 = p1;

    cout << "R1 has area = " << r1.calculate() << " (" <<r1.getLength() << ", " << r1.getWidth() << ")" << endl;
    cout << "R2 has area = " << r2.calculate() << " (" <<r2.getLength() << ", " << r2.getWidth() << ")" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "P1 has area = " << p1.calculate() << " (" <<p1.getLength() << ", " << p1.getWidth() << ", " << p1.getHeight() << " )" << endl;
    cout << "P2 has area = " << p2.calculate() << " (" <<p2.getLength() << ", " << p2.getWidth() << ", " << p1.getHeight() << " )" << endl;
    cout << endl;

    r1.setLength(7);
    r2.setWidth(9);

    p1.setWidth(3);
    p2.setHeight(14);

    cout << "#############################################" << endl;
    cout << "R1 has area = " << r1.calculate() << " (" <<r1.getLength() << ", " << r1.getWidth() << ")" << endl;
    cout << "R2 has area = " << r2.calculate() << " (" <<r2.getLength() << ", " << r2.getWidth() << ")" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "P1 has area = " << p1.calculate() << " (" <<p1.getLength() << ", " << p1.getWidth() << ", " << p1.getHeight() << ")" << endl;
    cout << "P2 has area = " << p2.calculate() << " (" <<p2.getLength() << ", " << p2.getWidth() << ", " << p2.getHeight() << ")" << endl;
    cout << endl;

    return 0;
}