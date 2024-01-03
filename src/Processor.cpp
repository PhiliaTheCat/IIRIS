#include <cmath>

#include "..\include\Processor"

namespace ptc
{
    Pic &Generate_Sealed_Image(const Pic &src, const std::bitset<1024> &msg, const double &s)
    {
        Pic &res = Pic(src.get_height(), src.get_width());

    }

    Pic &Compress(const Pic &src, const double &s)
    {
        uint32_t nh = round(src.get_height() * s);
        uint32_t nw = round(src.get_width() * s);
        if (nh % 2 == 1)
            nh += 1;
        if (nw % 2 == 1)
            nw += 1;
        Pic res = Pic(nh, nw);
        double unit = src.get_height() / nh;
        for (int i = 0; i < nh; i += 1)
        {
            for (int j = 0; j < nw; j += 1)
            {
                double tarx = i * unit + .5 * unit;
                double tary = j * unit + .5 * unit;
                uint32_t x = round(tarx);
                uint32_t y = round(tary);
                res[i][j] = Calculate(src[x - 1][y - 1], src[x - 1][y], src[x][y - 1], src[x][y], tarx - x + .5, tary - y + .5);
            }
        }
        return res;
    }

    unsigned char Calculate(const uint8_t &a, const uint8_t &b, const uint8_t &c, const uint8_t &d, const double &x, const double &y)
    {
        
    }
}
