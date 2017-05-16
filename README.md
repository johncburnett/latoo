# latoo
An openFrameworks and GLSL implementation of the Latoocarfian attractor. Transform feedback is used to corecursively calculate the position of each particle, entirely within the GPU. 

### The Latoocarfian Attractor
is defined by the following differential equation (with modifications by `john`):
```
xn = sin(b * yi) + c * sin(b * xi)
yn = sin(a * yi) + b * sin(a * xi)
zn = sin(a * xi) + d * sin(a * yi)

where
-3.0 < a < 3.0 && -3.0 < b < 3.0 && 0.5 < c < 1.5 && 0.5 < d < 1.5
```
This program grants several means of modulating through this chaotic system:
* Modulation of the coefficients
* Modulation of the differentials used to scale the coefficients
* Variations on the Latoocarfian equations

Eventually:
* Latoocarfian displacement of arbitrary point clouds

### Installation and Execution
Clone into the apps folder in your OF root directory. This project builds on both linux and osx (likely windows as well). 
``` bash
$ make -j4  # thread up
$ make run  # run release
```

### Dependencies
* openFrameworks 0.9.8
* ofxTF
* ofxSyphon
