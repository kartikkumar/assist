Assist
======

This repository catalogues miscellaneous C++ tools that I have authored to ASSIST my research (well if you can Boost your C++ code, why not assist it too?!).

I'm very open to suggestions and improvements, so feel free to teach me a thing or two.

Requirements
------

These tools are written off of the following open-source libraries:

- [`Eigen`](http://eigen.tuxfamily.org "Eigen's homepage")
- [`Boost`](http://www.boost.org "Boost's homepage")
- [`Tudat & Tudat Core`](http://tudat.tudelft.nl "Tudat project homepage")

`Assist` makes use of the cross-platform [`CMake`](http://www.cmake.org/ "CMake homepage") build system and has been tested with the 4.7 and 4.8 series of [GCC compilers](http://gcc.gnu.org "GCC homepage").

Installation
------

The easiest way to install the Assist library is to simply clone the repository and run CMake. This assumes that [`Eigen`](http://eigen.tuxfamily.org "Eigen's homepage"), [`Boost`](http://www.boost.org "Boost's homepage"), [`Tudat & Tudat Core`](http://tudat.tudelft.nl "Tudat project homepage") have been installed and can either be found through the system path or through relative paths (see CMake modules for the libraries included in the Assist project). 

In addition, you must have a C++ compiler and the [`CMake`](http://www.cmake.org/ "CMake homepage") tool needs to be installed on the system path. 

To clone the Assist library, simply execute the following from your terminal:

```
> git clone https://github.com/kartikkumar/assist.git
```

Move into the `assist` directory and create a `build` directory:

```
> mkdir build
> cd build
```

From within the `build` directory, run the following command:

```
build> cmake ../Assist
```

Once `CMake` has been run succesfully, run `make` from within the `build` directory to build the library. 

```
build> make
```

You can optionally also run the test suite at this stage to make sure that everything has been built correctly.

```
build> make test
```

This should not result in any failures.

The static libraries reside in `lib` directory in the project root.

Documentation
-------------

You can pass the `-DBUILD_DOCUMENTATION=on` option to `CMake` to build the (`Doxygen`)[http://www.doxygen.org "Doxygen homepage"] locally.

Contributing
------------

Once you've made your great commits:

1. [Fork][fk] Assist
2. Create a topic branch - `git checkout -b my_branch`
3. Push to your branch - `git push origin my_branch`
4. Create a [Pull Request](http://help.github.com/pull-requests/) from your
   branch
5. That's it!

You might want to checkout Resque's [Contributing][cb] wiki page for information
on coding standards, new features, etc.

License
------

See [COPYING](https://github.com/kartikkumar/assist/blob/master/COPYING).

Disclaimer
------

These tools are work-in-progress, and as such, I provide no assurances that they achieve the intended results in the manner conceived (in other words, don't blame me if you use any of these tools and they don't turn out to work as you expected).

Contact
------

You can reach me at [me@kartikkumar.com](me@kartikkumar.com).

