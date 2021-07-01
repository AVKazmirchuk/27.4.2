#include <utility>

#include "../include/header.h"

//-------Class Figure--------

Figure::Figure(std::string& inName, std::pair<double, double>& inCenter, Color inColor, std::pair<double, double>& inParameters) :
        name{ inName }, center{ inCenter }, color{ inColor }, parameters{ inParameters } {}

Figure::~Figure() = default;

std::string Figure::getName() const { return name; }

std::pair<double, double> Figure::getCenter() const { return center; }

std::string Figure::getColor() const
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

std::pair<double, double> Figure::getParameters() const { return parameters; }

double Figure::getPI() const { return PI; }

//Левая нижняя и правая верхняя координаты описывающего параллелепипеда

std::tuple<double, double, double, double> Figure::getParallelepiped(std::pair<double, double> offset) const
{
    return { center.first - offset.first, center.second - offset.second,
             center.first + offset.first, center.second + offset.second };
}

std::ostream& operator<<(std::ostream& out, const Figure* figure)
{
    std::tuple<double, double, double, double> parallelepiped = figure->preparingParallelepiped();

    out << '\n' << figure->getName() << ", center (" << figure->getCenter().first << ", " << figure->getCenter().second <<
              "), color(" << figure->getColor() << "), area (" << figure->getArea() << "), parallelepiped (" <<
              std::get<0>(parallelepiped) << ", " << std::get<1>(parallelepiped) <<
              ", " << std::get<2>(parallelepiped) << ", " << std::get<3>(parallelepiped) << ")\n";

    return out;
}

//-------Class Circle--------

Circle::Circle(std::string inName, std::pair<double, double> inCenter, Color inColor, std::pair<double, double> inParameters) :
        Figure(inName, inCenter, inColor, inParameters) {}

Circle::~Circle() = default;

double Circle::getArea() const { return getPI() * pow(getParameters().first, 2); }

std::tuple<double, double, double, double> Circle::preparingParallelepiped() const
{
    return getParallelepiped({ getParameters().first, getParameters().first });
}

//-------Class Square--------

Square::Square(std::string inName, std::pair<double, double> inCenter, Color inColor, std::pair<double, double> inParameters) :
        Figure(inName, inCenter, inColor, inParameters) {}

Square::~Square() = default;

double Square::getArea() const { return pow(getParameters().first, 2); }

std::tuple<double, double, double, double> Square::preparingParallelepiped() const
{
    return getParallelepiped({ getParameters().first / 2, getParameters().first / 2 });
}

//-------Class Triangle------

Triangle::Triangle(std::string inName, std::pair<double, double> inCenter, Color inColor, std::pair<double, double> inParameters) :
        Figure(inName, inCenter, inColor, inParameters) {}

Triangle::~Triangle() = default;

double Triangle::getArea() const { return pow(getParameters().first, 2) / 2 * sin(60 * getPI() / 180); }

std::tuple<double, double, double, double> Triangle::preparingParallelepiped() const
{
    return getParallelepiped({ getParameters().first / 2,
                                       sqrt(pow(getParameters().first, 2) - pow(getParameters().first, 2) / 4) / 2 });
}

//-------Class Rectangle-----

Rectangle::Rectangle(std::string inName, std::pair<double, double> inCenter, Color inColor, std::pair<double, double> inParameters) :
        Figure(inName, inCenter, inColor, inParameters) {}

Rectangle::~Rectangle() = default;

double Rectangle::getArea() const { return getParameters().first * getParameters().second; }

std::tuple<double, double, double, double> Rectangle::preparingParallelepiped() const
{
    return getParallelepiped({ getParameters().first / 2, getParameters().second / 2 });
}