#pragma once

#include <math.h>

class Vector2D {
    public:
        Vector2D(float x, float y) : m_x(x), m_y(y) {}

        float getX() { return m_x; }
        float getY() { return m_y; }
        float length() { return sqrt(m_x * m_x + m_y * m_y); }

        void setX(float x) { m_x = x; }
        void setY(float y) { m_y = y; }
        void normalize() {
            float l = length();
            if (l > 0) // never divide by zero
                (*this) *= 1 / l;
        }

        Vector2D operator+(const Vector2D& v2) const {
            return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
        }

        Vector2D& operator+=(const Vector2D& v2) {
            m_x += v2.m_x;
            m_y += v2.m_y;
            return *this;
        }

        Vector2D operator*(const float& scalar) const {
            return Vector2D(m_x * scalar, m_y * scalar);
        }

        Vector2D& operator*=(const float& scalar) {
            m_x *= scalar;
            m_y *= scalar;
            return *this;
        }

        Vector2D operator-(const Vector2D& v2) const {
            return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
        }

        Vector2D& operator-=(const Vector2D& v2) {
            m_x -= v2.m_x;
            m_y -= v2.m_y;
            return *this;
        }

        Vector2D operator/(const float& scalar) const {
            return Vector2D(m_x / scalar, m_y / scalar);     
        }

        Vector2D& operator/=(const float& scalar) {
            m_x /= scalar;
            m_y /= scalar;
            return *this;
        }

    private:
        float m_x;
        float m_y;
};