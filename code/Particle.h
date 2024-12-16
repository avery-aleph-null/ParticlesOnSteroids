#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>

class Particle : public sf::Drawable {
private:
    float m_ttl;      // Time to live (seconds)
    float m_x, m_y;   // Position
    float m_vx, m_vy; // Velocity in px/s
    sf::Color m_color;
    float m_radius;

    // sf::Drawable requires draw method to be overridden
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    Particle(float x, float y, float vx, float vy, float ttl, sf::Color color, float radius=2.0f);

    void update(float dt);
    bool isAlive() const { return m_ttl > 0; }
    void getPosition(float &x, float &y) const { x = m_x; y = m_y; }
    sf::Color getColor() const { return m_color; }
    float getRadius() const { return m_radius; }
    void setPosition(float x, float y) { m_x = x; m_y = y; }
};

#endif
