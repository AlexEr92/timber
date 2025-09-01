#pragma once

#include "Side.hpp"

#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

// Rip class for handling the gravestone visualization
class Rip : public sf::Drawable {
public:
    Rip(const std::string &texturePath);

    // Show the gravestone at player's death position
    void show(float x, float y, Side side);

    // Hide the gravestone (move off-screen)
    void hide();

private:
    sf::Texture m_texture; // Rip texture
    sf::Sprite m_sprite;   // Rip sprite
    bool m_isVisible = false;

    // Position constants
    static constexpr float RIP_HIDDEN_Y = 2000.f;
    static constexpr float RIP_OFFSET_X = -55.f; // Offset from player position
    static constexpr float RIP_OFFSET_Y = 40.f;  // Offset from player position

    // SFML rendering callback
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
