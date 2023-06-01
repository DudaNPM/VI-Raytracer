//
//  RGB.hpp
//  VI-RT
//
//  Created by Luis Paulo Santos on 30/01/2023.
//


#ifndef RGB_hpp
#define RGB_hpp

#include <iostream>


class RGB {
public:
    float R, G, B;
    RGB ():R(0.),G(0.),B(0.) {}
    RGB (float r, float g, float b):R(r),G(g),B(b) {}
    RGB (float *rgb):R(rgb[0]),G(rgb[1]),B(rgb[2]) {}
    ~RGB () {}
    RGB& operator+=(const RGB& rhs){
        this->R += rhs.R;
        this->G += rhs.G;
        this->B += rhs.B;
        return *this;
    }
    RGB operator+(RGB const& obj)
    {
        RGB res;
        res.R = R + obj.R;
        res.G = G + obj.G;
        res.B = B + obj.B;
        return res;
    }
    RGB operator+(float x)
    {
        RGB res;
        res.R = R + x;
        res.G = G + x;
        res.B = B + x;
        return res;
    }
    RGB operator*(RGB const& obj)
    {
        RGB res;
        res.R = R * obj.R;
        res.G = G * obj.G;
        res.B = B * obj.B;
        return res;
    }
    RGB operator*(float x)
    {
        RGB res;
        res.R = R * x;
        res.G = G * x;
        res.B = B * x;
        return res;
    }
    RGB operator/(RGB const& obj)
    {
        RGB res;
        res.R = R / obj.R;
        res.G = G / obj.G;
        res.B = B / obj.B;
        return res;
    }
    RGB operator/(float x)
    {
        RGB res;
        res.R = R / x;
        res.G = G / x;
        res.B = B / x;
        return res;
    }
    float Y() {
        return (R*(float)0.2126 + G*(float)0.7152 + B*(float)0.0722);
    }
    bool isZero () {
        return ((R==0.) && (G==0.) && (B==0.));
    }
    void Clamp() {
        R = std::max(0.0f, std::min(R, 1.0f));
        G = std::max(0.0f, std::min(G, 1.0f));
        B = std::max(0.0f, std::min(B, 1.0f));
    }
};

#endif /* RGB_hpp */
