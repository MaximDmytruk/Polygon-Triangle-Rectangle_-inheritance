/* 1. Створити абстрактний клас “Багатокутник”. Клас повинен містити методи для обчислення периметра, знаходження площі і ін. 
Побудувати похідний клас “Трикутник” і прямокутник, що містить також методи для знаходження довжин медіан, висот трикутника
*/
#include <iostream>
#include <math.h>
using namespace std;
class Polygon {         //абстрактний Базовий клас багатокутник 
public:
    virtual void Perimeter() = 0;      // віртуальні функції
    virtual void Area() = 0;
};

class Triangle :public Polygon      //Дічорній клас трикутник 
{
private:
    double ab, bc, ca;      //сторони трикутника 
public:
    Triangle (double ab,double bc,double ca)
    {
        this->ab = ab;
        this->bc = bc;
        this->ca = ca;
    }
    void Perimeter()override { cout << "Perimetr of triangle = " << ab + bc + ca << endl; } //Метод для розрахунку периметра трикутника 
    void Area()override {                               //метод для ррзрахунку площі трикутника 
        double p = (ab + bc + ca)/2;
        cout << "Area of triangle = " << sqrt(p * (p - ab) * (p - bc) * (p - ca)) << endl;
    }
    void Mediana()          //Розрахунок медіан сторін 
    {
        cout << "The lenght of mediana triangle A = " << 0.5 * sqrt(2 * bc * bc + 2 * ca * ca - ab * ab) << endl;
        cout << "The lenght of mediana triangle B = " << 0.5 * sqrt(2 * ab * ab + 2 * ca * ca - bc *bc) << endl;
        cout << "The lenght of mediana triangle C = " << 0.5 * sqrt(2 * ab * ab + 2 * bc * bc - ca * ca) << endl;
    }
    void HighTri() {            //Метод для розрахунку висот 
        double p = (ab + bc + ca) / 2;
        double s = sqrt(p * (p - ab) * (p - bc) * (p - ca));
        cout << "The lenght of high A = " << 2 * s / ab << endl;
        cout << "The lenght of high B = " << 2 * s / bc << endl;
        cout << "The lenght of high C = " << 2 * s / ca << endl;
    }
    ~Triangle() {}
    
};

class Rectangle:public Polygon      //дочірній клас прямокутник 
{
private:
    double a, b;        //сторони прямокутника 
public: 
    Rectangle(double a, double b)   //приймаємо дані про сторони 
    {
        this->a = a;
        this->b = b;
    }
    void Perimeter()override { cout << "Perimetr of a Rectangle = " << 2 * (a + b) << endl; }   //метод для розрахунку периметра 
    void Area()override { cout << "Area of a Rectangle = " << a * b << endl; }      //метод для розрахунку площі прямокутника 
    ~Rectangle() {}
};

int main()
{
    double a, b;   //сторони прямокутника 
    double ab, bc, ca; //сторони трикутника 
    cout << "Enter the length of the sides a Triangle " << endl;
    cin >> ab >> bc >>ca;
    cout << "Enter the length of the sides a Rectangle " << endl;       //Просимо ввсти дані про сторони 
    cin >> a >> b;

    Triangle triangle(ab, bc, ca);  //створюємо об'єкт класу трикутник  
    Rectangle rectangle(a, b);      //створюємо об'єкт класу прямокутник 
    cout << "\t-Triangle-" << endl;
    triangle.Perimeter();
    triangle.Area();            //викликаємо методи для розрахунку
    triangle.Mediana();
    triangle.HighTri();
    cout << endl;
    
    cout << "\t-Rectangle-" << endl;
    rectangle.Perimeter();      //викликаємо методи для розрахунку
    rectangle.Area();
}

