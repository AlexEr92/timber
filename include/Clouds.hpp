#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <random>
#include <vector>

class Clouds : public sf::Drawable {
public:
    Clouds();

    bool loadTexture(const std::string &filePath);
    void spawnClouds(int count);
    void update(float dt);

private:
    struct Cloud {
        sf::Sprite sprite;
        float speed;
        bool isActive = false;
    };

    sf::Texture m_texture;
    std::vector<Cloud> m_clouds;
    std::mt19937 m_randomEngine;

    void resetCloud(Cloud &cloud);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
