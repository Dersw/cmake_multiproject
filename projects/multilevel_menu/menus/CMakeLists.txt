target_sources(multilevel_menu
    PRIVATE
        menu.hpp
        menu_functions.hpp
        menu_functions.cpp
        menu_items.hpp
        menu_items.cpp
)

target_include_directories(multilevel_menu PRIVATE
    "${PROJECT_SOURCE_DIR}/menus"
)
