// path -> cd /mnt/c/Users/dumit/Desktop/CTI_anIV_2021-2022/semI/IEP/tema5
// cmake src/
// make
// ./recangle


#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
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
       Rectangle& operator=(const Rectangle& r) {	
            	//ne asiguram ca copiem toate partile obiectului 
            	length = r.length;
            	width = r.width;	
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
    Parallelepiped& operator=(const Parallelepiped& p){
        	//inform the base class to copy its data memebers
        	Rectangle::operator=(p);
        	height=p.height;

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

std::mutex m;	//you can use std::lock_guard if you want to be exception safe
int i = 0;

void parameters(int lenght, int width, int height){
	m.lock();
	cout << "P" << i << " " << lenght << "(l), " << width << "(L), " << height << "(h)" << endl;
	i++;
	m.unlock();

}

int main(){

//unique_ptr
	unique_ptr<Rectangle> r1(new Rectangle(4,6));
	cout <<"-----------------unique_ptr---------------------" << endl;
    cout << "Adresa lui r1: " << r1.get() << endl;
    // transfers ownership to r2
    unique_ptr<Rectangle> r2 = move(r1);
    cout <<"Adresa lui r1 dupa transfer: " << r1.get() << endl;
    cout <<"Adresa lui r2: " << r2.get() << endl;
    //cout << "Aria: " << r1->calculate() << endl; --> daca o pun da segmentation fault --- r1 nu mai este il seteaza pe NULL
    cout << "Aria: " << r2->calculate() << endl;

//shared_ptr
    shared_ptr<Parallelepiped> p1(new Parallelepiped(5, 8, 1));
    cout << "------------------shared_ptr--------------------" << endl;
    cout << "Adresa lui p1: " << p1.get() << endl;
    cout << "VolumulP1: " << p1->calculate() << endl;
    //transfer ownership to p2
    shared_ptr<Parallelepiped> p2(p1);
    cout << "Adresa lui p1: " << p1.get() << endl;
    cout << "Adresa lui p2: " << p2.get() << endl;
    cout << "VolumulP2: " << p2->calculate() << endl;
    // Returns the number of shared_ptr objects
    // referring to the same managed object.
    cout << "P1_count - " << p1.use_count() << endl;
    cout << "P2_count - " << p2.use_count() << endl;
     /*
    // Relinquishes ownership of p1 on the object
    // and pointer becomes NULL
    cout << "---Relinquishes ownership of p1 on the object---" << endl;
    p1.reset();
    cout << "Adresa P1: " << p1.get() << endl;
    cout << "P1_count - " << p1.use_count() << endl;
    cout << "P2_count - " << p2.use_count() << endl;
    cout << "Adresa P2: " << p2.get() << endl;
    */
    cout << "------------------------------------------------" << endl;
    //transfer ownership to p3
    shared_ptr<Parallelepiped> p3(p2);    

    std::thread th1(parameters, p1->getLength(), p1->getWidth(), p1->getHeight());
    std::thread th2(parameters, p2->getLength(), p2->getWidth(), p2->getHeight());
    std::thread th3(parameters, p3->getLength(), p3->getWidth(), p3->getHeight());

    th1.join();
    th2.join();
    th3.join();

    return 0;
}
// g++ iep6.cpp -lpthread