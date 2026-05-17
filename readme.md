# CORDIC

CORDIC is an algorithm that can be used to calculate sin and cos of an angle in radians with simple operations. It uses a precomputed table of values and a precomputed value of pi.

These values are bootstrapped using functions atan and sin; atan is computed with a reasonably converging series and sqrt is calculated by Newton's method. The needed values are generated into header files, CORDIC does not further epend on these (rather heavy) functions.

Implemented sin and cos are accurate to 12 decimal places.

## Example

See `example.c`. Compile with `make example`, then run `./example`.
