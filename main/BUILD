cc_binary(
  name = "raytracer",
  srcs = glob(["*.cc", "*.h"]),
  deps = [
    "@boost//:program-options",
    "@png_pp//:png_pp",
    "//primitives:primitives",
    "//materials:materials",
    "//objects:objects",
    '//util:util',
  ],
  copts = ['-O2', '-fopenmp'],
  linkopts = [
    '-lpng16', #for png++ library
    '-fopenmp',
    '-ffast-math',
  ]
)