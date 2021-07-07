#include <vector>
#include <pybind11/pybind11.h>

namespace py = pybind11;

py::object test() {
    py::object pandas = py::module_::import("pandas");
    py::object read_csv = pandas.attr("read_csv");
    py::object df = read_csv("test01.csv");
    py::list cols;
    cols.append("a");
    cols.append("b");
    py::object col_a = df.attr("__getitem__")(cols);
    py::object ret = col_a.attr("__mul__")(2);

    return ret;
}

PYBIND11_MODULE(test01, m) {
    m.def("test", &test);
}
