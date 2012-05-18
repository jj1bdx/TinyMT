# TinyMT - Tiny Mersenne Twister

A 2^127-1 period PRNG

## Notes

* TinyMT-src and TinyMT-Jump (1.1) both pieces of codes are merged.

* This git repository includes mods for FreeBSD 8. For compilation on FreeBSD 8,
  gcc 4.5 or later is required.
  The following example shows a configuration for gcc 4.6 (port lang/gcc46) for
  <code>/etc/libmap.conf</code>:

        ## for gcc46
        libstdc++.so.6                  gcc46/libstdc++.so.6

* The stock gcc of FreeBSD 8 (4.2.1) causes the following problems:
    * floating point handling error when testing <code>tinymt/</code> generated sequences
    * does not compile the C++ code under <code>dc/</code> 

## What is Tiny Mersenne Twister

(as described in <http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/TINYMT/index.html>)

TinyMT is a new small-sized variant of Mersenne Twister (MT) introduced by
Mutsuo Saito and Makoto Matsumoto in 2011. There are two types of TinyMT,
tinymt32 and tinymt64. tinymt32 outputs 32-bit unsigned integers and single
precision floating point numbers. On the other hand, tinymt64 outputs 64-bit
unsigned integers and double precision floating point numbers.

The purpose of TinyMT is not to replace Mersenne Twister. TinyMT has far
shorter period than Mersenne Twister. The merit of TinyMT is in its small size
of the internal state of 127 bits, far smaller than 19937 of Mersenne Twister.
The purpose of TinyMT may be used in a situation where large state generators
such as Mersenne Twister are difficult to use. According to statistical test
(BigCrush), the quality of the outputs of TinyMT seems pretty good, taking the
small size of the internal state into consideration.

## TinyMT features

* The periods of generated sequences are 2^127-1
* The size of internal state space is 127 bits
* The state transition function is F2-linear
* The output function is not F2-linear
* TinyMTDC generates distinct parameter sets for TinyMT
* TinyMTDC can generate a large number of parameter sets (over 232 x 216)
* Parameter generation of TinyMTDC is fast
