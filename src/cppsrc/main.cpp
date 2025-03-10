#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "data/data_client.hpp"

int main()
{
    std::cout << "hello\n";
}

PYBIND11_MODULE(intern, m)
{
    pybind11::class_<intproj::DataClient>(m, "DataClient")
      .def(pybind11::init<>())
      .def("tick", &intproj::DataClient::tick);
}