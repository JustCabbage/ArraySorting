#include "Visualizer.hpp"

void Visualizer::Create(const std::string& Title, const std::uint32_t& Width, const std::uint32_t& Height)
{
    Visualizer::Window = std::make_unique<sf::RenderWindow>(sf::VideoMode({Width, Height}), Title, sf::Style::Default);
    Visualizer::PopulateArray();
    
    while(Window->isOpen())
    {
        sf::Event Event;
        Visualizer::PollEvent(Event);

        Window->clear();

        for(std::size_t i = 0; i < Visualizer::Array.size(); i++)
        {
            sf::RectangleShape Bar(sf::Vector2f{1, (float)Visualizer::Array[i]});
            Bar.setFillColor(sf::Color::White);
            Bar.setPosition({(float)i, 0});
            Window->draw(Bar);
        }

        Visualizer::SortArray();
        Window->display();
    }
}

void Visualizer::PollEvent(sf::Event& Event)
{
    while(Window->pollEvent(Event))
    {
        switch(Event.type)
        {
        case sf::Event::Closed:
            Window->close();
            break;
        case sf::Event::KeyPressed:
            if(Event.key.code == sf::Keyboard::Space)
            {
                Visualizer::PopulateArray();
            }
            break;
        }
    }
}

void Visualizer::SortArray()
{
    for(std::size_t i = 0; i < Visualizer::Array.size() - 1; i++)
    {
        if(Visualizer::Array[i] > Visualizer::Array[i + 1])
        {
            std::uint32_t OldCurrent = Visualizer::Array[i];
            Visualizer::Array[i] = Visualizer::Array[i + 1];
            Visualizer::Array[i + 1] = OldCurrent;
        }
    }
}

void Visualizer::PopulateArray()
{
    const int Height = Window->getSize().y;
    const int Width = Window->getSize().x;
    Visualizer::Array.resize(Width);
    std::random_device Device;
    std::mt19937 RandomGenerator(Device());
    std::uniform_int_distribution<std::mt19937::result_type> Distribution(0, Height);
    for(std::size_t i = 0; i < Width; i++)
    {
        Visualizer::Array[i] = Distribution(RandomGenerator);
    }
}