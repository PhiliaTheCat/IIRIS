#include "..\include\Pic"

namespace ptc
{
    Pic::Pic(const unsigned &__height, const unsigned &__width) noexcept(false)
    : height(__height), width(__width)
    {
        mat = new uint8_t [256 * 256] {};
        if (mat == nullptr)
            throw "Allocation failed!";
    }

    Pic::Pic(const Pic &src) noexcept(false)
    : height(src.height), width(src.width)
    {
        mat = new uint8_t [256 * 256];
        if (mat == nullptr)
            throw "Allocation failed!";
        for (int i = 0; i < 256 * 256; i += 1)
            mat[i] = src.mat[i];
    }

    Pic::Pic(Pic &&src)
    : height(src.height), width(src.width), mat(src.mat)
    {
        src.mat = nullptr;
    }

    Pic::~Pic()
    {
        if (mat != nullptr)
            delete [] mat;
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
        mat = rhs.mat;
        rhs.mat = nullptr;
        return *this;
    }

    uint32_t Pic::get_height() const
    {
        return height;
    }

    uint32_t Pic::get_width() const
    {
        return width;
    }

    uint8_t *Pic::get_mat() const
    {
        return mat;
    }

    uint8_t *Pic::operator [](const uint32_t &x) const noexcept(false)
    {
        if (x / width >= height)
            throw "Invalid row index!";
        return &mat[x - x % width];
    }
}
