#include <utility>

#include "../include/header.h"

Figure::Figure(std::string& inName, std::pair<double, double>& inCenter, Color inColor, std::pair<double, double>& inParameters) :
        name{ inName }, center{ inCenter }, color{ inColor }, parameters{ inParameters } {}

std::string& Figure::getName() { return name; }

std::pair<double, double> Figure::getCenter() { return center; }

std::string Figure::getColor()
{
    switch (static_cast<int>(color))
    {
        case 0: return "red";
        case 1: return "orange";
        case 2: return "yellow";
        case 3: return "green";
        case 4: return "cyan";
        case 5: return "blue";
        case 6: return "purple";

        default: return "unknown";
    }
}

std::pair<double, double> Figure::getParameters() { return parameters; }

double Figure::getPI() const { return PI; }

//Левая нижняя и правая верхняя координаты описывающего параллелепипеда

std::tuple<double, double, double, double> Figure::getParallelepiped(std::pair<double, double> offset) const
{
    return { center.first - offset.first, center.second - offset.second,
             center.first + offset.first, center.second + offset.second };
}



Circle::Circle(std::string inName, std::pair<double, double> inCenter, Color inColor, std::pair<double, double> inParameters) :
        Figure(inName, inCenter, inColor, inParameters) {}

double Circle::getArea() { return getPI() * pow(getParameters().first, 2); }

std::tuple<double, double, double, double> Circle::getParallelepiped()
{
    return Figure::getParallelepiped({ getParameters().first, getParameters().first });
}



Square::Square(std::string inName, std::pair<double, double> inCenter, Color inColor, std::pair<double, double> inParameters) :
        Figure(inName, inCenter, inColor, inParameters) {}

double Square::getArea() { return pow(getParameters().first, 2); }

std::tuple<double, double, double, double> Square::getParallelepiped()
{
    return Figure::getParallelepiped({ getParameters().first / 2, getParameters().first / 2 });
}



Triangle::Triangle(std::string inName, std::pair<double, double> inCenter, Color inColor, std::pair<double, double> inParameters) :
        Figure(inName, inCenter, inColor, inParameters) {}

double Triangle::getArea() { return pow(getParameters().first, 2) / 2 * sin(60 * getPI() / 180); }

std::tuple<double, double, double, double> Triangle::getParallelepiped()
{
    return Figure::getParallelepiped({
                                             getParameters().first / 2, sqrt(pow(getParameters().first, 2) - pow(getParameters().first, 2) / 4) / 2 });
}



Rectangle::Rectangle(std::string inName, std::pair<double, double> inCenter, Color inColor, std::pair<double, double> inParameters) :
        Figure(inName, inCenter, inColor, inParameters) {}

double Rectangle::getArea() { return getParameters().first * getParameters().second; }

std::tuple<double, double, double, double> Rectangle::getParallelepiped()
{
    return Figure::getParallelepiped({ getParameters().first / 2, getParameters().second / 2 });
}