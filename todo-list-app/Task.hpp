#pragma once

#include <string>

struct Task {
    int id;
    std::string title;
    bool completed = true;

    // не кращий варіант.
    // краще використати перевантаження оператора << для виводу для Task
    std::string ToStrint() const
    {
        return std::to_string(id) + " " + title + " " + std::to_string(completed);
    }
};