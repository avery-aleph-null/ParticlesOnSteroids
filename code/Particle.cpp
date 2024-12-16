#include "Particle.h"
#include <cmath>

Particle::Particle(float x, float y, float vx, float vy, float ttl, sf::Color color, float radius)
    : m_x(x), m_y(y), m_vx(vx), m_vy(vy), m_ttl(ttl), m_color(color), m_radius(radius) {}

void Particle::update(float dt) {
    float gravity = 200.0f; // px/s^2 downward
    m_vy += gravity * dt;

    m_x += m_vx * dt;
    m_y += m_vy * dt;
    m_ttl -= dt;

    // Fade out as TTL decreases
    if (m_ttl < 1.0f) {
        float alphaFactor = (m_ttl < 0) ? 0.0f : m_ttl;
        sf::Uint8 alpha = static_cast<sf::Uint8>(255 * alphaFactor);
        m_color.a = alpha;
    }
}

void Particle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::CircleShape shape(m_radius);
    shape.setPosition(m_x, m_y);
    shape.setFillColor(m_color);
    target.draw(shape, states);
}
