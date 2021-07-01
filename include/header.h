#pragma once
#include <iostream>

enum class Color
{
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    CYAN,
    BLUE,
    PURPLE
};

class Figure
{
private:
    std::string name;
    std::pair<double, double> center;
    Color color;
    std::pair<double, double> parameters;
    const double PI = 3.14;
public:
    Figure(std::string& inName, std::pair<double, double>& inCenter, Color inColor, std::pair<double, double>& inParameters);

    virtual ~Figure();

    std::string getName() const;

    std::pair<double, double> getCenter() const;

    std::string getColor() const;

    std::pair<double, double> getParameters() const;

    double getPI() const;

    virtual double getArea() const = 0;

    virtual std::tuple<double, double, double, double> preparingParallelepiped() const = 0;

    //Левая нижняя и правая верхняя координаты описывающего параллелепипеда

    std::tuple<double, double, double, double> getParallelepiped(std::pair<double, double> offset) const;

    friend std::ostream& operator<<(std::ostream& out, const Figure* figure);
};



class Circle : public Figure
{
public:
    Circle(std::string inName, std::pair<double, double> inCenter, Color inColor, std::pair<double, double> inParameters);

    virtual ~Circle();

    virtual double getArea() const override;

    virtual std::tuple<double, double, double, double> preparingParallelepiped() const override;
};



class Square : public Figure
{
public:
    Square(std::string inName, std::pair<double, double> inCenter, Color inColor, std::pair<double, double> inParameters);

    virtual ~Square();

    virtual double getArea() const override;

    virtual std::tuple<double, double, double, double> preparingParallelepiped() const override;
};



class Triangle : public Figure
{
public:
    Triangle(std::string inName, std::pair<double, double> inCenter, Color inColor, std::pair<double, double> inParameters);

    virtual ~Triangle();

    virtual double getArea() const override;

    virtual std::tuple<double, double, double, double> preparingParallelepiped() const override;
};



class Rectangle : public Figure
{
public:
    Rectangle(std::string inName, std::pair<double, double> inCenter, Color inColor, std::pair<double, double> inParameters);

    virtual ~Rectangle();

    virtual double getArea() const override;

    virtual std::tuple<double, double, double, double> preparingParallelepiped() const override;
};

