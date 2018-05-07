#ifndef INCLUDE_SF_LINE_HPP_
#define INCLUDE_SF_LINE_HPP_

#include <SFML/Graphics.hpp>

class sfLine : public sf::Drawable {
 public:
    sfLine(const sf::Vector2f& point1, const sf::Vector2f& point2,
        sf::Color color, float thickness);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    sf::Color color;
 private:
    float thickness;
    sf::Vertex vertices[4];
};

#endif  // INCLUDE_SF_LINE_HPP_
