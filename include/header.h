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

    std::string& getName();

    std::pair<double, double> getCenter();

    std::string getColor();

    std::pair<double, double> getParameters();

    double getPI() const;

    //Левая нижняя и правая верхняя координаты описывающего параллелепипеда

    std::tuple<double, double, double, double> getParallelepiped(std::pair<double, double> offset) const;
};

class Circle : public Figure
{
public:
    Circle(std::string inName, std::pair<double, double> inCenter, Color inColor, std::pair<double, double> inParameters);

    double getArea();

    std::tuple<double, double, double, double> getParallelepiped();
};

class Square : public Figure
{
public:
    Square(std::string inName, std::pair<double, double> inCenter, Color inColor, std::pair<double, double> inParameters);

    double getArea();

    std::tuple<double, double, double, double> getParallelepiped();
};

class Triangle : public Figure
{
public:
    Triangle(std::string inName, std::pair<double, double> inCenter, Color inColor, std::pair<double, double> inParameters);

    double getArea();

    std::tuple<double, double, double, double> getParallelepiped();
};

class Rectangle : public Figure
{
public:
    Rectangle(std::string inName, std::pair<double, double> inCenter, Color inColor, std::pair<double, double> inParameters);

    double getArea();

    std::tuple<double, double, double, double> getParallelepiped();
};

