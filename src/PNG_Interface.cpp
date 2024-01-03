#include <cstdint>

#include "..\include\png.h"
#include "..\include\PNG_Interface"

namespace ptc
{
    Pic &Read_from_PNG(const char file_name[]) noexcept(false)
    {
        png_image pic;

        pic.version = PNG_IMAGE_VERSION;
        pic.opaque = nullptr;

        png_image_begin_read_from_file(&pic, file_name);

        pic.format = PNG_FORMAT_GRAY;

        Pic res = Pic(pic.height, pic.width);

        png_image_finish_read(&pic, nullptr, res.get_mat(), 1, nullptr);

        return res;
    }
}
