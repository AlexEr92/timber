#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include <vector>

class Clouds {
public:
    Clouds();

    bool loadTexture(const std::string &filePath);
    void spawnClouds(int count);
    void update(float dt);
    void draw(sf::RenderWindow &window) const;

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
};
