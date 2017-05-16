# latoo

### The Latoocarfian Attractor
is defined corecursively as follows (with modifications by `john`):
```
xn = sin(b * yi) + c * sin(b * xi)
yn = sin(a * yi) + b * sin(a * xi)
zn = sin(a * xi) + d * sin(a * yi)

where
-3.0 < a < 3.0 && -3.0 < b < 3.0 && 0.5 < c < 1.5 && 0.5 < d < 1.5
```
This code allows for ways of modulating through this chaotic system. 

### Installation and Execution
Clone to apps folder in your OF directory. Builds on both linux and osx. 
``` bash
$ make -j4  # thread up
$ make run  # run release
```

### Dependencies
* openFrameworks 0.9.8
* ofxTF
* ofxSyphon (osx only)
