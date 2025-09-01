#pragma once

#include <random>
#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

// Game bee with random movement behavior
class Bee : public sf::Drawable {
public:
    Bee(const std::string &texturePath);

    // Set initial bee position
    void setPosition(float x, float y);

    // Update bee position and state
    void update(float dt);

private:
    sf::Texture m_texture;       // Bee texture
    sf::Sprite m_sprite;         // Bee sprite
    float m_speed;               // Current movement speed
    bool m_isActive = false;     // Whether bee is currently active
    std::mt19937 m_randomEngine; // RNG for movement parameters

    // SFML rendering callback
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
