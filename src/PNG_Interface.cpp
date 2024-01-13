#include <cstring>

#include "../include/png.h"
#include "../include/PNG_Interface"

namespace ptc
{
    Pic Read_from_PNG(const char file_name[]) noexcept(false)
    {
        png_image pic;
        pic.version = PNG_IMAGE_VERSION;
        pic.opaque = nullptr;

        png_image_begin_read_from_file(&pic, file_name);

        if (pic.warning_or_error)
            throw pic.message;

        pic.format = PNG_FORMAT_GRAY;

        Pic res = Pic(pic.height, pic.width);

        png_image_finish_read(&pic, nullptr, res.get_mat(), 0, nullptr);

        if (pic.warning_or_error)
            throw pic.message;

        return res;
    }

    void Write_into_PNG(const Pic &src, const char file_name[]) noexcept(false)
    {
        png_image pic;
        std::memset(&pic, 0, sizeof(png_image));
        pic.version = PNG_IMAGE_VERSION;
        pic.opaque = nullptr;
        pic.height = src.get_height();
        pic.width = src.get_width();
        pic.format = PNG_FORMAT_GRAY;
        pic.flags = 0;
        pic.colormap_entries = 0;

        png_image_write_to_file(&pic, file_name, 0, src.get_mat(), 0, nullptr);

        if (pic.warning_or_error)
            throw pic.message;

        return;
    }

}
