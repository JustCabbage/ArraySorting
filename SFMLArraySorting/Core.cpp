#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <array>
#include <random>

static constexpr int WIDTH = 1920;
static constexpr int HEIGHT = 720;
static float BarWidth = 1;
static std::array<int, WIDTH> SortingArray;

inline void PopulateArray()
{
	std::random_device RandomDevice;
	std::mt19937 RandomGenerator(RandomDevice());
	std::uniform_int_distribution<std::mt19937::result_type> Distribution(0, HEIGHT);
	for (int i = 0; i < (SortingArray.size() / BarWidth); i++)
	{
		SortingArray[i] = Distribution(RandomGenerator);
	}
}

int main()
{
	sf::RenderWindow Window(sf::VideoMode(WIDTH, HEIGHT), "Array Sorting | Press Space to Populate New Array");
	if (BarWidth <= 0)
		BarWidth = 1;
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

		Window.clear(sf::Color::White);

		for (int i = 0; i < (SortingArray.size() / BarWidth); i++)
		{
			sf::RectangleShape Bar(sf::Vector2f(BarWidth, SortingArray[i]));
			Bar.setFillColor(sf::Color::Black);
			Bar.setPosition(i * BarWidth, 0);
			Window.draw(Bar);
		}

		for (int i = 0; i < (SortingArray.size() / BarWidth) - 1; i++)
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