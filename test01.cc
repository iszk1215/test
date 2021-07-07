#include <pybind11/pybind11.h>

namespace py = pybind11;

py::object test() {
    py::object pandas = py::module_::import("pandas");
    py::object read_csv = pandas.attr("read_csv");
    py::object df = read_csv("test01.csv");
    py::object getitem = df.attr("__getitem__");
    py::object col_a = getitem("a");
    py::object mul = col_a.attr("__mul__");
    py::object ret = mul(2);

    return ret;
}

PYBIND11_MODULE(test01, m) {
    m.def("test", &test);
}
