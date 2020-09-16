# Disclaimer

This library has the same problem as the original Matlab code: radii might not be in the correct order.

This is due to the algorithm relying on eigen values to compute them. These values are not guaranteed to be in any particular order by the algorithms computing them.

A new algorithm or a fix to this one needs to be found.