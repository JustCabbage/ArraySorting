#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>

#define WIDTH 1920
#define HEIGHT 720
sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Array Sorting | Press Space to Populate New Array");

int mainArray[WIDTH];
float barWidth = 1;

void PopulateArray() {
    // POPULATE RANDOM VALUES
    srand(time(NULL));
    for (int i = 0; i < WIDTH / barWidth; i++) {
        mainArray[i] = rand() % HEIGHT;
    }
}


int main()
{
    if (barWidth <= 0) barWidth = 1;
    PopulateArray();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            PopulateArray();

        // RENDER UNSORTED ARRAY INITIALLY, UPDATE EACH TIME SORTED
        for (int i = 0; i < WIDTH / barWidth; i++) {
            sf::RectangleShape rectangle(sf::Vector2f(barWidth, mainArray[i]));
            rectangle.setFillColor(sf::Color::White);
            rectangle.setPosition(i * barWidth, 0);
            window.draw(rectangle);

        }

        // SORT ARRAY IN SEPARATE LOOP
        for (int j = 0; j < (WIDTH / barWidth) - 1; j++) {
            if (mainArray[j] > mainArray[j + 1]) {
                int temp = mainArray[j];
                mainArray[j] = mainArray[j + 1];
                mainArray[j + 1] = temp;
            }
        }

        window.display();

        
    }
    return 0;
}