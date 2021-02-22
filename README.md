# log2
BBP for log(2)

    This program implements the BBP/Spigot algorithm to generate a few binary digits of log(2), or in general log(n)-log(n-1),
    beginning immediately after a given position id.
    On a 2012 laptop, it takes about 10s for id = 1e7 and 1 min for id = 1e8.
    This is a simpler version of the same alogrithm for pi.
    For more details, please see the Wikipedia page below and the references within.
    https://en.wikipedia.org/wiki/Bailey-Borwein-Plouffe_formula
