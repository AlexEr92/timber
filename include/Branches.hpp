#pragma once

#include "Side.hpp"

#include <random>
#include <string>
#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

// Manages branch sprites with random generation
class Branches : public sf::Drawable {
public:
    Branches(int numBranches = 6);

    // Load branch Texture
    bool loadFromFile(const std::string &texturePath);

    // Initialize brach sprites
    void initSprites();

    // Update branches positions
    void updateBranches(int seed);

    // Set branch position based on side
    void setBranchPosition(int index, Side side);

    // Check if player is squished by branch
    bool isPlayerSquished(Side playerSide) const;

    // Reset all branches to NONE
    void reset();

private:
    sf::Texture m_texture;               // Branch texture
    std::vector<sf::Sprite> m_branches;  // Branch sprites
    std::vector<Side> m_branchPositions; // Branch positions
    std::mt19937 m_randomEngine;         // RNG for branch generation
    int m_numBranches;

    // SFML rendering callback
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
