#include "Branches.hpp"
#include <ctime>
#include <stdexcept>

Branches::Branches(const std::string &texturePath, int numBranches)
    : m_numBranches{numBranches}, m_randomEngine{std::random_device{}()} {
    if (!m_texture.loadFromFile(texturePath)) {
        throw std::runtime_error("Failed to load branches texture: " + texturePath);
    }
    m_branches.resize(m_numBranches);
    m_branchPositions.resize(m_numBranches, Side::NONE);

    // Initialize sprites
    for (auto &branch : m_branches) {
        branch.setTexture(m_texture);
        branch.setPosition(-2000, -2000);
        branch.setOrigin(220, 20); // Set origin for rotation
    }
}

void Branches::updateBranches(int seed) {
    // Move all branches down one position
    for (int j = m_numBranches - 1; j > 0; j--) {
        m_branchPositions[j] = m_branchPositions[j - 1];
    }

    // Spawn new branch at position 0 using proper RNG
    m_randomEngine.seed(static_cast<unsigned int>(std::time(nullptr)) + seed);
    std::uniform_int_distribution<int> dist(0, 4);
    int r = dist(m_randomEngine);

    switch (r) {
    case 0:
        m_branchPositions[0] = Side::LEFT;
        break;
    case 1:
        m_branchPositions[0] = Side::RIGHT;
        break;
    default:
        m_branchPositions[0] = Side::NONE;
        break;
    }

    // Update sprite positions and rotations
    for (int i = 0; i < m_numBranches; i++) {
        float height = i * 150;

        if (m_branchPositions[i] == Side::LEFT) {
            m_branches[i].setPosition(610, height);
            m_branches[i].setOrigin(220, 40);
            m_branches[i].setRotation(180);
        } else if (m_branchPositions[i] == Side::RIGHT) {
            m_branches[i].setPosition(1330, height);
            m_branches[i].setOrigin(220, 40);
            m_branches[i].setRotation(0);
        } else {
            m_branches[i].setPosition(3000, height); // Hide branch
        }
    }
}

bool Branches::isPlayerSquished(Side playerSide) const {
    // Check if bottom branch is on the same side as player
    return m_branchPositions[m_numBranches - 1] == playerSide;
}

void Branches::reset() {
    for (int i = 0; i < m_numBranches; i++) {
        m_branchPositions[i] = Side::NONE;
        m_branches[i].setPosition(3000, i * 150); // Hide all branches
    }
}

void Branches::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (const auto &branch : m_branches) {
        target.draw(branch, states);
    }
}
