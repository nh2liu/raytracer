cc_library(
  name = "objects",
  hdrs = glob(["*.h"]),
  srcs = glob(["*.cc"]),
  copts = ['-O2'],
  deps = ['//primitives:primitives'],
  visibility = ["//main:__pkg__", "//materials:__pkg__"],
)