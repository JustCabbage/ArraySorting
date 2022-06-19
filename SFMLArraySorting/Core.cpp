#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <random>

#define WIDTH 1920
#define HEIGHT 720

int SortingArray[WIDTH];
float BarWidth = 1;

inline void PopulateArray() 
{
    // POPULATE RANDOM VALUES
    std::random_device RandomDevice;
    std::mt19937 RandomGenerator(RandomDevice());
    std::uniform_int_distribution<std::mt19937::result_type> Distribution(0, HEIGHT);
    for (int i = 0; i < WIDTH / BarWidth; i++) 
    {
        SortingArray[i] = Distribution(RandomGenerator);
    }
}


int main()
{
    sf::RenderWindow Window(sf::VideoMode(WIDTH, HEIGHT), "Array Sorting | Press Space to Populate New Array");
    if (BarWidth <= 0) BarWidth = 1;
    PopulateArray();
    while (Window.isOpen())
    {
        sf::Event event;
        while (Window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                Window.close();
                break;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            PopulateArray();

        Window.clear(sf::Color(191, 64, 191));

        // RENDER UNSORTED ARRAY INITIALLY, UPDATE EACH TIME SORTED
        for (int i = 0; i < WIDTH / BarWidth; i++) 
        {
            sf::RectangleShape Bar(sf::Vector2f(BarWidth, SortingArray[i]));
            Bar.setFillColor(sf::Color(0,0,0));
            Bar.setPosition(i * BarWidth, 0);
            Window.draw(Bar);
        }

        // SORT ARRAY IN SEPARATE LOOP
        for (int i = 0; i < (WIDTH / BarWidth) - 1; i++) 
        {
            if (SortingArray[i] > SortingArray[i + 1]) 
            {
                int Temp = SortingArray[i];
                SortingArray[i] = SortingArray[i + 1];
                SortingArray[i + 1] = Temp;
            }
        }

        Window.display();
    }
    return 0;
}