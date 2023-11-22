#include <iostream>
using namespace std;

class Points {
public:
    int x = 0;
    int y = 0;
   
    void print_points();
};


void Points::print_points() {
    cout << "(" << x << "," << y << ")" << endl;
}

class Shape {
  protected:
  
    int number_of_points;
    Points* points;
public:
  Shape();

  int get_area();
  void create_shape(Points* p);

};
void Shape:: create_shape(Points* p){
  this->points = p;
}
Shape::Shape() {
cout<<"shape is created "<<endl;
  points = NULL ;
}

class Rectangle: public Shape {
public:
    Rectangle(int i);
    void print_shape();
    int get_area();
};

Rectangle::Rectangle(int number_of_points) {
  this->number_of_points = number_of_points;
  
}
void Rectangle:: print_shape(){
  Points* temp = this->points;
  for(int i = 0; i < number_of_points; i++){
    temp->print_points();
    temp++;
  }

  
}

int main() {

Points p1,p2,p3;
  p1.x = p1.y = 0;
  p2.x = p2.y = 1;
  p3.x = p3.y = 2;
  
  
Points *points_of_triangle ;
  points_of_triangle  = new Points[3];
  points_of_triangle[0] = p1;
  points_of_triangle[1] = p2;
  points_of_triangle[2] = p3;

  Rectangle r  = Rectangle(3);
  r.create_shape(points_of_triangle);
  r.print_shape();

  return 0 ;
}