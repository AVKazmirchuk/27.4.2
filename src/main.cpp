#include <iostream>

#include "../include/header.h"

bool cinNoFail()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid data!\n";
        return false;
    }
    else
    {
        if (std::cin.peek() != '\n')
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid data!\n";
            return false;
        }
    }

    return true;
}



std::tuple<int, std::string, std::pair<double, double>, Color, std::pair<double, double>> input()
{
    int figureType;
    while (true)
    {
        std::cout << "\nCommand, (1 - circle, 2 - square, 3 - triangle, 4 - rectangle): ";

        std::cin >> figureType;

        if (!cinNoFail()) continue;

        if (figureType >= 1 && figureType <= 4) break;

        std::cout << "Invalid input!\n";
    }

    std::string figureName;
    switch (figureType)
    {
        case 1: figureName = "Circle"; break;
        case 2: figureName = "Square"; break;
        case 3: figureName = "Triangle"; break;
        case 4: figureName = "Rectangle"; break;
        default:
            break;
    }

    std::pair<double, double> center;

    while (true)
    {
        std::cout << "Center, (x, y): ";
        std::cin >> center.first >> center.second;

        if (cinNoFail()) break;
    }

    int inputColor;
    while (true)
    {
        std::cout << "Color, (1 - red, 2 - orange, 3 - yellow, 4 - green,\n";
        std::cout << "5 - cyan, 6 - blue, 7 - purple): ";

        std::cin >> inputColor;

        if (!cinNoFail()) continue;

        if (inputColor >= 1 && inputColor <= 7) break;

        std::cout << "Invalid input!\n";
    }

    Color color;

    switch (inputColor)
    {
        case 1: color = Color::RED; break;
        case 2: color = Color::ORANGE; break;
        case 3: color = Color::YELLOW; break;
        case 4: color = Color::GREEN; break;
        case 5: color = Color::CYAN; break;
        case 6: color = Color::BLUE; break;
        case 7: color = Color::PURPLE; break;
        default:
            break;
    }

    std::cout << "Parameter, (for a circle - radius, for a square and a triangle - edge, " <<
              "for a rectangle - length and width): ";

    std::pair<double, double> parameters;

    while (true)
    {
        std::cin >> parameters.first;
        if (figureName == "Rectangle") std::cin >> parameters.second;

        if (cinNoFail()) break;
    }

    return { figureType, figureName, center, color, parameters };
}



int main()
{
    std::tuple<int, std::string, std::pair<double, double>, Color, std::pair<double, double>> parameters = input();

    Figure* figure;

    switch (std::get<0>(parameters))
    {
        case 1:
            figure = new Circle(std::get<1>(parameters), std::get<2>(parameters),
                    std::get<3>(parameters), std::get<4>(parameters));

            break;
        case 2:
            figure = new Square(std::get<1>(parameters), std::get<2>(parameters),
                    std::get<3>(parameters), std::get<4>(parameters));

            break;
        case 3:
            figure = new Triangle(std::get<1>(parameters), std::get<2>(parameters),
                    std::get<3>(parameters), std::get<4>(parameters));

            break;
        case 4:
            figure = new Rectangle(std::get<1>(parameters), std::get<2>(parameters),
                    std::get<3>(parameters), std::get<4>(parameters));

            break;
    }

    std::cout << figure;

    delete figure;
}