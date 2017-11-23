//
// Created by drew on 11/22/17.
//

#include <pangomm/fontdescription.h>
#include <pangomm/font.h>
#include "SplitUtils.h"

Pango::FontDescription SpUtils::getFont(
        const std::string &desc,
        double size = 15,
        Pango::Stretch stretch = Pango::STRETCH_NORMAL,
        Pango::Weight weight = Pango::WEIGHT_NORMAL) {

    Pango::FontDescription fontDescription(desc);
    fontDescription.set_stretch(stretch);
    fontDescription.set_weight(weight);
    fontDescription.set_size((int) (size * Pango::SCALE));

    return fontDescription;
}

