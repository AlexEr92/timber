#pragma once

#include <random>
#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

// Manages cloud sprites with random movement
class Clouds : public sf::Drawable {
public:
    Clouds();

    // Load cloud texture
    bool loadTexture(const std::string &filePath);

    // Create cloud sprites
    void spawnClouds(int count);

    // Update cloud positions
    void update(float dt);

private:
    // Internal structure representing a single cloud instance
    struct Cloud {
        sf::Sprite sprite;
        float speed;
        bool isActive = false;
    };

    sf::Texture m_texture;       // Cloud texture
    std::vector<Cloud> m_clouds; // Cloud instances
    std::mt19937 m_randomEngine; // RNG for cloud properties

    // Reset cloud position/speed
    void resetCloud(Cloud &cloud);

    // SFML rendering callback
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
