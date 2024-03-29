#include <iostream>

class shapes
{
public:
    shapes()
    {
        num_sides = 0;
        shape_name = " Неизвестная фигура";
    }
    int get_num_sides() { return num_sides; }
    std::string get_shape_name() { return shape_name; }
    virtual void print_info1(shapes* shape) 
    {
        std::cout << shape_name << std::endl << std::endl;
    }
protected:
    int num_sides;
    std::string shape_name;
};

class triangles : public shapes
{
public:
    triangles(int a_, int b_, int c_, int A_, int B_, int C_)
    {
        shape_name = " Треугольник";
        a = a_; b = b_; c = c_; A = A_; B = B_; C = C_;
    }
    int get_tr_a() { return a; }
    int get_tr_b() { return b; }
    int get_tr_c() { return c; }
    int get_tr_A() { return A; }
    int get_tr_B() { return B; }
    int get_tr_C() { return C; }
protected:
    int a, b, c, A, B, C;
    void print_info1(shapes* shape) override
    {
        std::cout << shape_name << std::endl;
        std::cout << " Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << " Углы: A=" << A << " B=" << B << " C=" << C << std::endl << std::endl;
    }
};

class quadrangles :public shapes
{
public:
    quadrangles(int a_, int b_, int c_, int d_, int A_, int B_, int C_, int D_)
    {
        shape_name = " Четырехугольник";
        a = a_; b = b_; c = c_; d = d_; A = A_; B = B_; C = C_; D = D_;
    }
    int get_qdr_a() { return a; }
    int get_qdr_b() { return b; }
    int get_qdr_c() { return c; }
    int get_qdr_d() { return d; }
    int get_qdr_A() { return A; }
    int get_qdr_B() { return B; }
    int get_qdr_C() { return C; }
    int get_qdr_D() { return D; }
protected:
    int a, b, c, d, A, B, C, D;
    void print_info1(shapes* shape)
    {
        std::cout << shape_name << std::endl;
        std::cout << " Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << " Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl << std::endl;
    }
};

class rectangular_triangles :public triangles
{
public:
    rectangular_triangles(int a_, int b_, int c_, int A_, int B_) :triangles(a, b, c, A, B, C)
    {
        shape_name = " Прямоугольный треугольник";
        a = a_; b = b_; c = c_; A = A_; B = B_; C = 90;
    }
};

class isosceles_triangles :public triangles
{
public:
    isosceles_triangles(int a_, int b_, int A_, int B_) :triangles(a, b, c, A, B, C)
    {
        shape_name = " Равнобедренный треугольник";
        a = c = a_; b = b_; A = C = A_; B = B_;
    }
};

class equilateral_triangles :public isosceles_triangles
{
public:
    equilateral_triangles(int a_) :isosceles_triangles(a, b, A, B)
    {
        shape_name = " Правильный треугольник";
        a = b = c = a_; A = B = C = 60;
    }
};

class parallelograms :public quadrangles
{
public:
    parallelograms(int a_, int b_, int A_, int B_) :quadrangles(a, b, c, d, A, B, C, D)
    {
        shape_name = " Параллелограмм";
        a = c = a_; b = d = b_; A = C = A_; B = D = B_;
    }
};

class rectangles :public parallelograms
{
public:
    rectangles(int a_, int b_) :parallelograms(a, b, A, B)
    {
        shape_name = " Прямоугольник";
        a = c = a_; b = d = b_; A = B = C = D = 90;
    }
};

class rhombs :public parallelograms
{
public:
    rhombs(int a_, int A_, int B_) :parallelograms(a, b, A, B)
    {
        shape_name = " Ромб";
        a = b = c = d = a_;  A = C = A_; B = D = B_;
    }
};

class squares :public rectangles
{
public:
    squares(int a_) :rectangles(a, b)
    {
        shape_name = " Квадрат";
        a = b = c = d = a_; A = B = C = D = 90;
    }
};

void print_info(shapes *shape_)
{
    shape_->print_info1(shape_);
}
int main()
{
    shapes shape;
    triangles triangle(1, 2, 3, 30, 65, 85);
    quadrangles quadrangle(2, 3, 4, 5, 90, 110, 60, 100);
    rectangular_triangles rectangular_triangle(3, 4, 5, 30, 60);
    isosceles_triangles isosceles_triangle(4, 6, 50, 65);
    equilateral_triangles equilateral_triangle(8);
    parallelograms parallelogram(4, 10, 45, 135);
    rectangles rectangle(5, 9);
    rhombs rhomb(5, 35, 145);
    squares square(15);
    print_info(&shape);
    print_info(&triangle);
    print_info(&rectangular_triangle);
    print_info(&isosceles_triangle);
    print_info(&equilateral_triangle);
    print_info(&quadrangle);
    print_info(&parallelogram);
    print_info(&rhomb);
    print_info(&rectangle);
    print_info(&square);
    std::cout << " Угол A=" << isosceles_triangle.get_tr_A() << " Тип фиугры: " << std::endl;
    std::cout << isosceles_triangle.get_shape_name() << std::endl << std::endl;
    std::cout << " Сторона d=" << parallelogram.get_qdr_d() << " Тип фиугры: " << std::endl;
    std::cout << parallelogram.get_shape_name() << std::endl;
}