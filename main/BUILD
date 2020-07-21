cc_binary(
  name = "raytracer",
  srcs = glob(["*.cc", "*.h"]),
  deps = [
    "@boost//:program-options",
    "//primitives:primitives",
    "//materials:materials",
    "//objects:objects"
  ],
  copts = ['-O2'],
)