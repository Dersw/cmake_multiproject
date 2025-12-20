#include "menu_items.hpp"

#include <cstddef>

#include "menu_functions.hpp"

const Dersw::MenuItem Dersw::STUDY_ALGEBRA_SUMM = {
    "1 - Хочу научиться складывать!", Dersw::study_algebra_summ, &Dersw::STUDY_ALGEBRA
};
const Dersw::MenuItem Dersw::STUDY_ALGEBRA_SUBSTRACT = {
    "2 - Хочу научиться вычитать!", Dersw::study_algebra_substract, &Dersw::STUDY_ALGEBRA
};
const Dersw::MenuItem Dersw::STUDY_ALGEBRA_MULTIPLY = {
    "3 - Хочу научиться умножать!", Dersw::study_algebra_multiply, &Dersw::STUDY_ALGEBRA
};
const Dersw::MenuItem Dersw::STUDY_ALGEBRA_DEVIDE = {
    "4 - Хочу научиться делить!", Dersw::study_algebra_devide, &Dersw::STUDY_ALGEBRA
};
const Dersw::MenuItem Dersw::STUDY_ALGEBRA_GO_BACK = {
    "0 - Вернуться назад", Dersw::study_go_back, &Dersw::STUDY_ALGEBRA
};

namespace {
    const Dersw::MenuItem* study_algebra_children[] = {
        &Dersw::STUDY_ALGEBRA_GO_BACK,
        &Dersw::STUDY_ALGEBRA_SUMM,
        &Dersw::STUDY_ALGEBRA_SUBSTRACT,
        &Dersw::STUDY_ALGEBRA_MULTIPLY,
        &Dersw::STUDY_ALGEBRA_DEVIDE,
    };
    const int study_algebra_size = sizeof(study_algebra_children) / sizeof(study_algebra_children[0]);
}

const Dersw::MenuItem Dersw::STUDY_CALCULUS_DIFF = {
    "1 - Хочу изучить дифференциальное счисление!", Dersw::study_calculus_diff, &Dersw::STUDY_CALCULUS
};
const Dersw::MenuItem Dersw::STUDY_CALCULUS_INTEGRAL = {
    "2 - Хочу изучить интегральное счисление!", Dersw::study_calculus_integral, &Dersw::STUDY_CALCULUS
};
const Dersw::MenuItem Dersw::STUDY_CALCULUS_GO_BACK = {
    "0 - Вернуться назад", Dersw::study_go_back, &Dersw::STUDY_CALCULUS
};

namespace {
    const Dersw::MenuItem* study_calculus_children[] = {
        &Dersw::STUDY_CALCULUS_GO_BACK,
        &Dersw::STUDY_CALCULUS_DIFF,
        &Dersw::STUDY_CALCULUS_INTEGRAL,
    };
    const int study_calculus_size = sizeof(study_calculus_children) / sizeof(study_calculus_children[0]);
}

const Dersw::MenuItem Dersw::STUDY_ALGEBRA = {
    "1 - Хочу изучить алгебру!", Dersw::show_menu, &Dersw::STUDY, study_algebra_children, study_algebra_size
};
const Dersw::MenuItem Dersw::STUDY_CALCULUS = {
    "2 - Хочу изучить математический анализ!", Dersw::show_menu, &Dersw::STUDY, study_calculus_children, study_calculus_size
};
const Dersw::MenuItem Dersw::STUDY_GO_BACK = {
    "0 - Вернуться назад", Dersw::study_go_back, &Dersw::STUDY
};

namespace {
    const Dersw::MenuItem* study_children[] = {
        &Dersw::STUDY_GO_BACK,
        &Dersw::STUDY_ALGEBRA,
        &Dersw::STUDY_CALCULUS,
    };
    const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}

const Dersw::MenuItem Dersw::STUDY = {
    "1 - Хочу учиться математике!", Dersw::show_menu, &Dersw::MAIN, study_children, study_size
};
const Dersw::MenuItem Dersw::EXIT = {
    "0 - Я лучше пойду посплю...", Dersw::exit, &Dersw::MAIN
};

namespace {
    const Dersw::MenuItem* main_children[] = {
        &Dersw::EXIT,
        &Dersw::STUDY
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const Dersw::MenuItem Dersw::MAIN = {
    nullptr, Dersw::show_menu, nullptr, main_children, main_size
};
