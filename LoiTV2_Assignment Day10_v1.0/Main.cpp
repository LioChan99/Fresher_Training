#include<iostream>
using namespace std;
#include<vector>
#include<cmath>

class Shape
{
    public:
    Shape(){};
    virtual ostream& print(ostream& out) const =0;
    virtual double caculateArea()=0;
    friend ostream& operator <<(ostream& out, const Shape& p)
    {
        return p.print(out);
    }
    virtual ~Shape(){};
};

class Point
{
    private:
       int x;
       int y;
       int z;
    public:
    Point(){};
    int getX()
    {
        return x;
    }
    void setX(int &x)
    {
        this->x=x;
    }
    void setY(int &y)
    {
        this->y=y;
    }
     void setZ(int &z)
    {
        this->z=z;
    }
    int getY()
    {
        return y;
    }
    int getZ()
    {
        return z;
    }
    Point(const int &x,const int &y,const int &z)
    {
        this->x=x;
        this->y=y;
        this->z=z;
    }
    //set Poin Infor from keyboard
    void setPointInfor()
    {   int x;
        cout<<"Point.x: ";
        cin>>x;
        setX(x);
        int y;
        cout<<"Point.y: ";
        cin>>y;
        setY(y);
        int z;
        cout<<"Point.z: ";
        cin>>z;
        setZ(z);
    }
    friend ostream& operator<<(ostream& out, const Point& p)
    {
        return out << "Point("<< p.x<< ", "<<p.y<<", "<<p.z<<')';

    }
};

class Triangle: public Shape
{
   private:
      Point P1;
      Point P2;
      Point P3;
    public:
      Triangle(const Point &P1,const Point &P2,const Point &P3)
      {
        this->P1=P1;
        this->P2=P2;
        this->P3=P3;
      }
      ostream& print(ostream& out) const override
      {
        return out<<"Triangle("<<P1<<", "<<P2<<", "<<P3<<")"<<endl;
      }
      //calculate rectangleArea
      double caculateArea() override {
		double d1 = sqrt(pow(P1.getX() - P2.getX(), 2)
			+ pow(P1.getY() - P2.getY(),2)+pow(P1.getZ() - P2.getZ(), 2));
		double d2 = sqrt(pow(P1.getX() - P3.getX(), 2)
			+ pow(P1.getY() - P3.getY(),2)+pow(P1.getZ() - P3.getZ(), 2));
		double d3 = sqrt(pow(P2.getX() - P3.getX(), 2)
			+ pow(P2.getY() - P3.getY(),2)+pow(P2.getZ() - P3.getZ(), 2));
		double p=(d1+d2+d3)/2;
        return sqrt(p*(p-d1)*(p-d2)*(p-d3));
	}
};

class Circle: public Shape
{
   private:
      Point P1;
      int Radius;
    public:
      Circle(const Point& P1,const int& Radius)
      {
        this->P1=P1;
        this->Radius= Radius;
      }
      int getRadius()
      {
        return this->Radius;
      }
      ostream& print(ostream& out) const override
      {
        return out<<"Circle("<<P1<<", "<<"radius "<<Radius<<")"<<endl;
      }
      //calculate CircleArea
      double caculateArea() override
      {
        return 2.14* Radius*Radius;
      }
};

int getlargestRadius(vector<Shape*>v)
{   int max=0;
    for(int i=0;i<v.size();i++)
    {
      if(dynamic_cast<Circle*>(v[i]))
      { 
         if(dynamic_cast<Circle*>(v[i])->getRadius() >max)
         max=dynamic_cast<Circle*>(v[i])->getRadius();
      } 
    }
    return max;
}


int main()
{   Circle c(Point(1,2,3), 7);
    cout<< c<<endl;
    Triangle t(Point(1,2,3),Point(4,5,6),Point(7,8,9));
    cout<< t<<endl;
    vector<Shape*> v
    {
        new Circle(Point(1,2,3),7),
        new Triangle(Point(1,2,3),Point(4,5,6),Point(7,8,9)),
        new Circle(Point(4,5,6),3)
    };
    for(int i=0;i<v.size();i++)
    {
        cout<<*v[i]<<endl;
    }
    cout<<"The largest radius is: "<<getlargestRadius(v)<<endl;
    // free vector's memory
    for(int i=0;i<v.size();i++)
    {
        delete v[i];
    }
    
    while (true)
    {   int i;
        cout<<"Press 1 to Enter a Circle"<<endl;
        cout<<"Press 2 to Enter a Rectangle"<<endl;
        cin>>i;
        switch(i)
        {
            case 1:
            {
                cout<<"Enter circle's radius:"<<endl;
                int d;
                cin>>d;
                Shape*c= new Circle(Point(0,0,0),d);
                cout<<"Area: "<<c->caculateArea()<<endl;
                delete c;
                break;
            }
            case 2:
            {
                cout<<"Enter Point1:"<<endl;
                Point P1;
                P1.setPointInfor();

                cout<<"Enter Point1:"<<endl;
                Point P2;
                P2.setPointInfor();

                cout<<"Enter Point1:"<<endl;
                Point P3;
                P3.setPointInfor();
                Shape*T= new Triangle(P1,P2,P3);
                cout<<"Area: "<< T->caculateArea()<<endl;
                delete T;
                break;
            }
            default:
              break;
        }
    }
    return 0;
}