cc_binary(
  name = "raytracer",
  srcs = glob(["*.cc", "*.h"]),
  deps = [
    "@boost//:program-options",
    "@png_pp//:png_pp",
    "//primitives:primitives",
    "//materials:materials",
    "//objects:objects"
  ],
  copts = ['-O2'],
  linkopts = [
    '-lpng16', #for png++ library
  ]
)