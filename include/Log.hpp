#pragma once

#include "Side.hpp"

#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

// Log class for handling the flying log animation and physics
class Log : public sf::Drawable {
public:
    Log() = default;

    // Load log texture
    bool loadFromFile(const std::string &texturePath);

    // Launch the log in a specific direction based on Side enum
    void launch(Side direction);

    // Update log position based on elapsed time
    void update(float dt);

    // Reset log to initial position and state
    void reset();

private:
    sf::Texture m_texture; // Log texture
    sf::Sprite m_sprite;   // Log sprite
    bool m_isActive = false;

    // Movement properties
    float m_speedX = 0.f;
    float m_speedY = 0.f;

    // Physics constants
    static constexpr float LOG_SPEED_X = 5000.f;
    static constexpr float LOG_SPEED_Y = -1500.f;
    static constexpr float LOG_START_X = 810.f;
    static constexpr float LOG_START_Y = 720.f;

    // Boundary checks
    bool isOutOfBounds() const;

    // SFML rendering callback
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
