#pragma once
#include <string>
#include <cmath>

class Color {
public:
    Color() : Color(0, 0, 0, 0) { }

    Color(const uint8_t& r, const uint8_t& g, const uint8_t& b, const uint8_t& a = 255) {
        m_color[0] = b;
        m_color[1] = g;
        m_color[2] = r;
        m_color[3] = a;
    }
    Color(const uint32_t& col) {
        m_color[0] = (col >> 24) & 0xFF;
        m_color[1] = (col >> 16) & 0xFF;
        m_color[2] = (col >> 8) & 0xFF;
        m_color[3] = (col) & 0xFF;
    }
    ~Color() = default;

    static Color FromInt(uint32_t value) {
        return { static_cast<uint8_t>((value >> 8) & 255), static_cast<uint8_t>((value >> 16) & 255), static_cast<uint8_t>((value >> 24) & 255), static_cast<uint8_t>((value >> 0) & 255) };
    }
    uint32_t GetInt() const {
        return static_cast<uint32_t>(m_color[3]) | static_cast<uint32_t>(m_color[2]) << 8 | static_cast<uint32_t>(m_color[1]) << 16 | static_cast<uint32_t>(m_color[0]) << 24;
    }

    void SetRed(const uint8_t& col) { m_color[2] = col; }
    [[nodiscard]] uint8_t GetRed() const { return m_color[2]; }
    void SetGreen(const uint8_t& col) { m_color[1] = col; }
    [[nodiscard]] uint8_t GetGreen() const { return m_color[1]; }
    void SetBlue(const uint8_t& col) { m_color[0] = col; }
    [[nodiscard]] uint8_t GetBlue() const { return m_color[0]; }
    void SetAlpha(const uint8_t& col) { m_color[3] = col; }
    [[nodiscard]] uint8_t GetAlpha() const { return m_color[3]; }

    void operator+=(Color other) {
        *this = operator+(other);
    }

    bool operator==(const Color& other) const {
        return GetRed() == other.GetRed() && GetGreen() == other.GetGreen() && GetBlue() == other.GetBlue() && GetAlpha() == other.GetAlpha();
    }

    bool operator!=(const Color& other) const {
        return !(operator==(other));
    }

    Color operator+(const Color& other) const {
        if (*this == Color{})
            return other;

        return {
            (uint8_t)std::round((float)(GetRed() + other.GetRed()) / 2),
            (uint8_t)std::round((float)(GetGreen() + other.GetGreen()) / 2),
            (uint8_t)std::round((float)(GetBlue() + other.GetBlue()) / 2),
            (uint8_t)std::round((float)(GetAlpha() + other.GetAlpha()) / 2),
        };
    }

private:
    uint8_t m_color[4] = { 0xFF, 0xFF, 0xFF, 0xFF };
};