//
// Created by drew on 11/22/17.
//

#ifndef SPLITTY_SPLITUTILS_H
#define SPLITTY_SPLITUTILS_H

#include <pangomm/fontdescription.h>

namespace SpUtils {

    Pango::FontDescription getFont(const std::string &desc, double size, Pango::Stretch stretch, Pango::Weight weight);
}

#endif //SPLITTY_SPLITUTILS_H
