#pragma once

#include "menu.hpp"

namespace Dersw {
    const MenuItem* show_menu(const MenuItem* current);

    const MenuItem* exit(const MenuItem* current);

    const MenuItem* study_go_back(const MenuItem* current);

    const MenuItem* study_algebra_summ(const MenuItem* current);
    const MenuItem* study_algebra_substract(const MenuItem* current);
    const MenuItem* study_algebra_multiply(const MenuItem* current);
    const MenuItem* study_algebra_devide(const MenuItem* current);

    const MenuItem* study_calculus_diff(const MenuItem* current);
    const MenuItem* study_calculus_integral(const MenuItem* current);
}
