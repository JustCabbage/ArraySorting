#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <memory>
#include <array>

namespace Visualizer
{
    void Create(const std::string& Title, const std::uint32_t& Width, const std::uint32_t& Height);
    void PollEvent(sf::Event& Event);
    void PopulateArray();
    void SortArray();
    
    inline std::unique_ptr<sf::RenderWindow> Window;
    inline std::vector<std::uint32_t> Array = {}; 
}