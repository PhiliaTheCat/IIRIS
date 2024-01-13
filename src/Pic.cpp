#include "../include/Pic"

namespace ptc
{
    Pic::Pic(const Pic &src) noexcept(false)
    : height(src.height), width(src.width)
    {
        mat = new uint8_t [256 * 256];
        if (mat == nullptr)
            throw "Allocation failed!";
        for (int i = 0; i < 256 * 256; i += 1)
            mat[i] = src.mat[i];
    }

    Pic &Pic::operator =(const Pic &rhs)
    {
        height = rhs.height;
        width = rhs.width;
        for (int i = 0; i < 256 * 256; i += 1)
            mat[i] = rhs.mat[i];
        return *this;
    }

    Pic &Pic::operator =(Pic &&rhs)
    {
        height = rhs.height;
        width = rhs.width;
        if (mat != nullptr)
            delete [] mat;
        mat = rhs.mat;
        rhs.mat = nullptr;
        return *this;
    }
}
